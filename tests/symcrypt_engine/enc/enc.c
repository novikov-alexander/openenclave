// Copyright (c) Open Enclave SDK contributors.
// Licensed under the MIT License.

#include <openenclave/enclave.h>
#include <openenclave/internal/crypto/init.h>
#include <openenclave/internal/print.h>
#include <openenclave/internal/tests.h>
#include "symcrypt_engine_t.h"

/* We do not have the SymCrypt engine available yet, defining a mock initializer
 * with the same function prototype and returns 1, mimicking the expected
 * behavior. */
int SYMCRYPT_ENGINE_Initialize()
{
    return 1;
}

void ecall_test()
{
    OE_TEST(oe_is_symcrypt_engine_available() == 1);
}

OE_SET_ENCLAVE_SGX(
    1,    /* ProductID */
    1,    /* SecurityVersion */
    true, /* Debug */
    1024, /* NumHeapPages */
    1024, /* NumStackPages */
    1);   /* NumTCS */
