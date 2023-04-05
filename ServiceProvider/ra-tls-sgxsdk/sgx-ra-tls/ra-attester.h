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


#ifndef _RA_ATTESTER_H_
#define _RA_ATTESTER_H_

#include <sgx_quote.h>

#ifdef RATLS_ECDSA
struct ecdsa_ra_tls_options {
	char subscription_key[32];
};

void ecdsa_create_key_and_x509
(
    uint8_t* der_key,
    int* der_key_len,
    uint8_t* der_cert,
    int* der_cert_len
);
#else
struct ra_tls_options {
	sgx_spid_t spid;
	sgx_quote_sign_type_t quote_type;
	/* NULL-terminated string of domain name/IP, port and path prefix,
	   e.g., api.trustedservices.intel.com/sgx/dev for development and
	   api.trustedservices.intel.com/sgx for production. */
	const char ias_server[512];
	const char subscription_key[32];
};

void create_key_and_x509_pem
(
    uint8_t* pem_key,
    int* pem_key_len,
    uint8_t* pem_cert,
    int* pem_cert_len,
    const struct ra_tls_options* opts
);
#endif
#endif
