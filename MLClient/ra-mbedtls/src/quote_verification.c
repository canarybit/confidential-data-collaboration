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


#include <stdio.h>
#include <sys/ioctl.h>

#include "quote_verification.h"

uint32_t get_supplemental_data_size(int sgx_fd) {
    if (sgx_fd < 0) {
        printf("negative file descriptor\n");
        return -1;
    }

    uint32_t supplemental_size = 0;
    if (ioctl(sgx_fd, SGXIOC_GET_DCAP_SUPPLEMENTAL_SIZE, &supplemental_size) < 0) {
        printf("failed to ioctl get supplemental data size\n");
        return -1;
    }

    return supplemental_size;
}

int verify_dcap_quote(int sgx_fd, sgxioc_ver_dcap_quote_arg_t *ver_quote_arg) {
    if (sgx_fd < 0) {
        printf("negative file descriptor\n");
        return -1;
    }

    if (ver_quote_arg == NULL) {
        printf("NULL ver_quote_arg\n");
        return -1;
    }

    if (ioctl(sgx_fd, SGXIOC_VER_DCAP_QUOTE, ver_quote_arg) < 0) {
        printf("failed to ioctl verify quote\n");
        return -1;
    }

    return 0;
}
