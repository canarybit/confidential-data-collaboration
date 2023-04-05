/*  Copyright 2021 Canary Bit AB

*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*       http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
*/


#include <assert.h>
#include <stdint.h>

#include <wolfssl/options.h>
#include <wolfssl/wolfcrypt/asn_public.h>
#include <wolfssl/wolfcrypt/rsa.h>
#include "ra.h"
#include "wolfssl-ra.h"

void sha256_rsa_pubkey
(
    unsigned char hash[SHA256_DIGEST_SIZE],
    RsaKey* key
)
{
    // Expect a 3072 bit RSA key.
    assert(key->n.used == 48 /* == 3072 / 8 / 8 */);

    uint8_t buf[1024];
    /* SetRsaPublicKey() only exports n and e without wrapping them in
       additional ASN.1 (PKCS#1). */
    int pub_rsa_key_der_len = SetRsaPublicKey(buf, key, sizeof(buf), 0);
    assert(pub_rsa_key_der_len == rsa_pub_3072_raw_der_len);
    
    Sha256 sha;
    wc_InitSha256(&sha);
    wc_Sha256Update(&sha, buf, pub_rsa_key_der_len);
    wc_Sha256Final(&sha, hash);
}

/* This function only exists to make edger8r happy. There must be at
   least one trusted (ECALL) function. */
void dummy(void){
}


