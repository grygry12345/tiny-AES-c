add_library (AES aes.h aes.c)

target_include_directories (AES PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})