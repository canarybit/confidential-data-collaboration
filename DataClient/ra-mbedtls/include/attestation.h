/* SPDX-License-Identifier: LGPL-3.0-or-later */
/* Copyright (C) 2018-2020 Invisible Things Lab
 *                         Rafal Wojdyla <omeg@invisiblethingslab.com>
 */

#ifndef ATTESTATION_H
#define ATTESTATION_H

#include <stdbool.h>
#include <stdint.h>
#include <sgx_report.h>

/*!
 *  \brief Display internal SGX quote structure.
 *
 *  \param[in] quote_data Buffer with quote data. This can be a full quote (sgx_quote_t)
 *                        or a quote from IAS attestation report (which is missing signature
 *                        fields).
 *  \param[in] quote_size Size of \a quote_data in bytes.
 */
void display_quote(const void* quote_data, size_t quote_size);

/*!
 *  \brief Display internal SGX report body structure (sgx_report_body_t).
 *
 *  \param[in] body Buffer with report body data.
 */
void display_report_body(const sgx_report_body_t* body);


/*!
 *  \brief Verify that the provided SGX quote contains expected values.
 *
 *  \param[in] quote_data      Quote to verify.
 *  \param[in] quote_size      Size of \a quote_data in bytes.
 *  \param[in] mr_signer       (Optional) Expected mr_signer quote field.
 *  \param[in] mr_enclave      (Optional) Expected mr_enclave quote field.
 *  \param[in] isv_prod_id     (Optional) Expected isv_prod_id quote field.
 *  \param[in] isv_svn         (Optional) Expected isv_svn quote field.
 *  \param[in] report_data     (Optional) Expected report_data quote field.
 *  \param[in] expected_as_str If true, then all expected SGX fields are treated as hex and
 *                             decimal strings. Otherwise, they are treated as raw bytes.
 *
 *  If \a expected_as_str is true, then \a mr_signer, \a mr_enclave and \a report_data are treated
 *  as hex strings, and \a isv_prod_id and a isv_svn are treated as decimal strings. This is
 *  convenient for command-line utilities.
 *
 *  \return 0 on successful verification, negative value on error.
 */
int verify_quote(const void* quote_data, size_t quote_size, const char* mr_signer,
                 const char* mr_enclave, const char* isv_prod_id, const char* isv_svn,
                 const char* report_data, bool expected_as_str);

#endif /* ATTESTATION_H */
