# Copyright (c) Open Enclave SDK contributors.
# Licensed under the MIT License.

set(EDL_FILE ../symcrypt_engine.edl)

# Invoke oeedger8r to generate edge routines (*_t.c, *_t.h, and *_args.h)
add_custom_command(
  OUTPUT symcrypt_engine_t.h symcrypt_engine_t.c
  DEPENDS ${EDL_FILE} edger8r
  COMMAND
    edger8r --trusted ${EDL_FILE} --search-path ${PROJECT_SOURCE_DIR}/include
    ${DEFINE_OE_SGX} --search-path ${CMAKE_CURRENT_SOURCE_DIR})

add_enclave(
  TARGET
  sgx_symcrypt_engine_enc
  CRYPTO_LIB
  OpenSSL
  SOURCES
  enc.c
  ${CMAKE_CURRENT_BINARY_DIR}/symcrypt_engine_t.c)

# Add include paths
enclave_include_directories(sgx_symcrypt_engine_enc PRIVATE
                            ${CMAKE_CURRENT_BINARY_DIR})
