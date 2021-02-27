add_library (AES aes.h aes_decrypt.c aes_encrypt.c)  

target_include_directories (AES PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})