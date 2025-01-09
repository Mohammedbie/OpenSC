#ifndef _OPENSC_WINCONFIG_H
#define _OPENSC_WINCONFIG_H

#include <stdio.h>
#include <sys/stat.h>
#include <sys/timeb.h>
#include <windows.h>
#include <winscard.h>

#ifdef _MSC_VER
// TODO fix data truncation instead of disabling them
// VC++ 2015 changes truncation warnings from 4244 to 4267.
#pragma warning(disable : 4267)
#pragma warning(disable : 4244)
#endif

#ifndef strcasecmp
#define strcasecmp stricmp
#endif

#ifndef strncasecmp
#define strncasecmp strnicmp
#endif

#ifndef vsnprintf
#define vsnprintf _vsnprintf
#endif

#ifndef snprintf
#define snprintf _snprintf
#endif

#ifndef R_OK
#define R_OK 4 /* test whether readable.  */
#define W_OK 2 /* test whether writable.  */
#define X_OK 1 /* test whether executable. */
#define F_OK 0 /* test whether exist.  */
#endif

#ifndef S_IRUSR
#define S_IRUSR S_IREAD
#endif

#ifndef S_IWUSR
#define S_IWUSR S_IWRITE
#endif

#define HAVE_STRNLEN
#define HAVE_IO_H
#define ENABLE_PCSC
#define HAVE_WINSCARD_H
#ifndef DEFAULT_PCSC_PROVIDER
#define DEFAULT_PCSC_PROVIDER "winscard.dll"
#endif

#define ENABLE_SHARED 1
#define ENABLE_NOTIFY 1

#define SC_PKCS15_PROFILE_DIRECTORY "C:\\Program Files\\OpenSC Project\\OpenSC\\profiles"

#define PATH_MAX FILENAME_MAX

#ifndef PACKAGE_VERSION
#define PACKAGE_VERSION "0.26.0"
#endif

#ifndef VERSION
#define VERSION PACKAGE_VERSION
#endif

#ifndef PACKAGE_NAME
#define PACKAGE_NAME "OpenSC master branch"
#endif

#ifndef OPENSC_FEATURES
#define OPENSC_FEATURES "N/A"
#endif

#ifndef OPENSC_VERSION_MAJOR
#define OPENSC_VERSION_MAJOR 0
#endif

#ifndef OPENSC_VERSION_MINOR
#define OPENSC_VERSION_MINOR 6
#endif

#ifndef OPENSC_VS_FF_COMPANY_NAME
#define OPENSC_VS_FF_COMPANY_NAME "Softlock"
#endif

#ifndef OPENSC_VS_FF_PRODUCT_NAME
#define OPENSC_VS_FF_PRODUCT_NAME "SLCOS"
#endif

#ifndef CVCDIR
#define CVCDIR "%PROGRAMFILES%\\OpenSC Project\\OpenSC\\cvc"
#endif

#ifndef DEFAULT_PKCS11_PROVIDER
#define DEFAULT_PKCS11_PROVIDER "%PROGRAMFILES%\\OpenSC Project\\OpenSC\\pkcs11\\opensc-pkcs11.dll"
#endif
#ifndef DEFAULT_ONEPIN_PKCS11_PROVIDER
#define DEFAULT_ONEPIN_PKCS11_PROVIDER "%PROGRAMFILES%\\OpenSC Project\\OpenSC\\pkcs11\\onepin-opensc-pkcs11.dll"
#endif

#define PKCS11_THREAD_LOCKING

#ifndef DEFAULT_SM_MODULE
#define DEFAULT_SM_MODULE "smm-local.dll"
#endif
#ifndef DEFAULT_SM_MODULE_PATH
#define DEFAULT_SM_MODULE_PATH "%PROGRAMFILES%\\OpenSC Project\\OpenSC\\tools"
#endif

#ifndef OPENSC_SCM_REVISION
#define OPENSC_SCM_REVISION "OpenSC version Git describe revision"
#endif

#endif
