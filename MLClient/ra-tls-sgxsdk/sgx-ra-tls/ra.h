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


#ifndef _RA_H_
#define _RA_H_

typedef struct {
    uint8_t ias_report[2*1024];
    uint32_t ias_report_len;
    uint8_t ias_sign_ca_cert[2*1024];
    uint32_t ias_sign_ca_cert_len;
    uint8_t ias_sign_cert[2*1024];
    uint32_t ias_sign_cert_len;
    uint8_t ias_report_signature[2*1024];
    uint32_t ias_report_signature_len;
} attestation_verification_report_t;

static const int rsa_3072_der_len = 1766;
static const int rsa_pub_3072_pcks_der_len = 422;
static const int rsa_pub_3072_pcks_header_len = 24;
static const int rsa_pub_3072_raw_der_len = 398; /* rsa_pub_3072_pcks_der_len - pcks_nr_1_header_len */

typedef struct {
    uint8_t quote[8192];
    uint32_t quote_len;
 } ecdsa_attestation_evidence_t;
#endif
