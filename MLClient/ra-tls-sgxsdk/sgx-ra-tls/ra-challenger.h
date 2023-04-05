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



#ifndef _RA_CHALLENGER_H_
#define _RA_CHALLENGER_H_

#include <sgx_quote.h>
#ifdef RATLS_ECDSA
#include <sgx_quote_3.h>
#endif

extern int la_verify_sgx_cert_extensions(uint8_t* der_crt, uint32_t der_crt_len);
extern void la_get_report_from_cert(const uint8_t* der_crt, uint32_t der_crt_len,
		sgx_report_t* report);
/**
 * Extract an Intel SGX quote from an DCAP extension.
 */
#ifdef RATLS_ECDSA
void ecdsa_get_quote_from_extension
(
    const uint8_t* exts,
    size_t exts_len,
    sgx_quote3_t* q
);

void ecdsa_get_quote_from_dcap_cert
(
    const uint8_t* der_crt,
    uint32_t der_crt_len,
    sgx_quote3_t* q
);
#endif

/**
 * Extract an Intel SGX quote from an Intel Attestation Service (IAS) report.
 */
void get_quote_from_report
(
    const uint8_t* report /* in */,
    const int report_len  /* in */,
    sgx_quote_t* quote
);

/**
 * Extract an Intel SGX quote from a DER-encoded X.509 certificate.
 */
void get_quote_from_cert
(
    const uint8_t* der_crt,
    uint32_t der_crt_len,
    sgx_quote_t* q
);

/**
 * Verify SGX-related X.509 extensions.
 * @return 0 if verification succeeds, 1 otherwise.
 */
int verify_sgx_cert_extensions
(
    uint8_t* der_crt,
    uint32_t der_crt_len
);
#endif
