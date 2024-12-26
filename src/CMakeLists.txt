cmake_minimum_required(VERSION 3.20)

include_directories(common libopensc minidriver pkcs11 pkcs15init scconf sm smm ui)

# add_subdirectory(test)
add_subdirectory(common)
add_subdirectory(libopensc)
add_subdirectory(minidriver)
add_subdirectory(pkcs11)
add_subdirectory(pkcs15init)
add_subdirectory(scconf)
add_subdirectory(sm)
add_subdirectory(ui)



