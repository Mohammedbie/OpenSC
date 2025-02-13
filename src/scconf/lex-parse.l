%{
/*
 * $Id$
 *
 * Copyright (C) 2002
 *  Antti Tapaninen <aet@cc.hut.fi>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <stdio.h>
#include "scconf.h"
#include "internal.h"

static scconf_parser *parser;

int yywrap() {
    return 1; // Signals EOF
}

%}

%option noyywrap
%option nounput

%%

"#"[^\r\n]*	scconf_parse_token(parser, TOKEN_TYPE_COMMENT, yytext);

\n		scconf_parse_token(parser, TOKEN_TYPE_NEWLINE, NULL);

[ \t\r]+	/* eat up whitespace */

[,{}=;]		scconf_parse_token(parser, TOKEN_TYPE_PUNCT, yytext);

\"([^\"\n\r]*\r*[\"\n]|$) {
    if (yytext[strlen(yytext) - 1] != '"') {
        fprintf(stderr, "Unclosed string: %s\n", yytext);
        exit(1);
    }
    scconf_parse_token(parser, TOKEN_TYPE_STRING, yytext);
}


[^;, \t\r\n]+  	scconf_parse_token(parser, TOKEN_TYPE_STRING, yytext);

%%

#ifndef YY_CURRENT_BUFFER_LVALUE
# define YY_CURRENT_BUFFER_LVALUE	yy_current_buffer
#endif

static void do_lex(scconf_parser *p)
{
	parser = p;

	yylex();

#if 1
	/* For non-reentrant C scanner only. */
	if (YY_CURRENT_BUFFER) {
		yy_delete_buffer(YY_CURRENT_BUFFER);
		YY_CURRENT_BUFFER_LVALUE = NULL;
		yy_init = 1;
		yy_start = 0;
	}
#endif
}

int scconf_lex_parse(scconf_parser *p, const char *filename)
{
	yyin = fopen(filename, "r");
	if (yyin == NULL)
		return 0;

	do_lex(p);

	fclose(yyin);
	yyin = NULL;
	return 1;
}

int scconf_lex_parse_string(scconf_parser *p, const char *conf_string)
{
	YY_BUFFER_STATE bs = yy_scan_string(conf_string);
	do_lex(p);
	yy_delete_buffer(bs);

	return 1;
}
