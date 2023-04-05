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


/* Definitions common to attester and verifier. */

#include <stdint.h>
#include <stdlib.h>

#define OID(N) {0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF8, 0x4D, 0x8A, 0x39, (N)}

const uint8_t ias_response_body_oid[]    = OID(0x02);
const uint8_t ias_root_cert_oid[]        = OID(0x03);
const uint8_t ias_leaf_cert_oid[]        = OID(0x04);
const uint8_t ias_report_signature_oid[] = OID(0x05);

const uint8_t quote_oid[]          = OID(0x06);
const uint8_t pck_crt_oid[]        = OID(0x07);
const uint8_t pck_sign_chain_oid[] = OID(0x08);
const uint8_t tcb_info_oid[]       = OID(0x09);
const uint8_t tcb_sign_chain_oid[] = OID(0x0a);
const uint8_t qe_identity_oid[]    = OID(0x0b);
const uint8_t root_ca_crl_oid[]    = OID(0x0c);
const uint8_t pck_crl_oid[]        = OID(0x0d);
const uint8_t la_report_oid[]      = OID(0x0e);

const size_t ias_oid_len = sizeof(ias_response_body_oid);
