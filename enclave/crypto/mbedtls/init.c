// Copyright (c) Open Enclave SDK contributors.
// Licensed under the MIT License.

#include <openenclave/bits/defs.h>
#include <openenclave/internal/crypto/init.h>

/* Forward declaration */
int SYMCRYPT_ENGINE_Initialize();

/* Add the implementation of the function (only available for OpenSSL)
 * to fulfill the linker requirement */
static int _SYMCRYPT_ENGINE_Initialize()
{
    return 0;
}
OE_WEAK_ALIAS(_SYMCRYPT_ENGINE_Initialize, SYMCRYPT_ENGINE_Initialize);

/* oe_crypto_initialize will be invoked during the enclave initialization.
 * Do nothing here given that Mbed TLS does not require initialization
 * (while OpenSSL does). */
void oe_crypto_initialize(void)
{
}

int oe_is_symcrypt_engine_available()
{
    return 0;
}
