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

#include "quote_generation.h"

uint32_t get_quote_size(int sgx_fd) {
    if (sgx_fd < 0) {
        printf("negative file descriptor\n");
        return -1;
    }

    uint32_t quote_size = 0;
    if (ioctl(sgx_fd, SGXIOC_GET_DCAP_QUOTE_SIZE, &quote_size) < 0) {
        printf("failed to ioctl get quote size\n");
        return -1;
    }

    return quote_size;
}

int generate_quote(int sgx_fd, sgxioc_gen_dcap_quote_arg_t *gen_quote_arg) {
    if (sgx_fd < 0) {
        printf("negative file descriptor\n");
        return -1;
    }

    if (gen_quote_arg == NULL) {
        printf("NULL gen_quote_arg\n");
        return -1;
    }

    if (ioctl(sgx_fd, SGXIOC_GEN_DCAP_QUOTE, gen_quote_arg) < 0) {
        printf("failed to ioctl get quote\n");
        return -1;
    }

    return 0;
}