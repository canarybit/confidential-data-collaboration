#  Copyright 2021 Canary Bit AB

#  Licensed under the Apache License, Version 2.0 (the "License");
#  you may not use this file except in compliance with the License.
#  You may obtain a copy of the License at
#
#       http://www.apache.org/licenses/LICENSE-2.0
#
#  Unless required by applicable law or agreed to in writing, software
#  distributed under the License is distributed on an "AS IS" BASIS,
#  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#  See the License for the specific language governing permissions and
#  limitations under the License.




#!/bin/bash
set -e

BLUE='\033[1;34m'
NC='\033[0m'
INSTANCE_DIR="ra_tls_instance"
occlum_glibc=/opt/occlum/glibc/lib

rm -rf ${INSTANCE_DIR} && occlum new ${INSTANCE_DIR}
cd ${INSTANCE_DIR}

# Copy mbedTLS library to $occlum_glibc
cp ../lib/libmbedcrypto.so.6 image/$occlum_glibc
cp ../lib/libmbedcrypto.so image/$occlum_glibc
cp ../lib/libmbedtls.so image/$occlum_glibc
cp ../lib/libmbedtls.so.13 image/$occlum_glibc
cp ../lib/libmbedx509.so image/$occlum_glibc
cp ../lib/libmbedx509.so.1 image/$occlum_glibc
cp ../lib/libtensorflowlite_c.so image/$occlum_glibc
cp ../lib/libra_tls_attest.so image/lib

# Copy ra-tls-server image to image/bin
cp ../bin/ra-tls-server image/bin
#cp ../../../demos/tensorflow_lite/tensorflow_src/tensorflow/lite/tools/make/gen/linux_x86_64/bin/label_image image/bin

# Copy network libraries to image/$occlum_glibc
cp $occlum_glibc/libnss_files.so.2 image/$occlum_glibc
cp $occlum_glibc/libnss_dns.so.2 image/$occlum_glibc
cp $occlum_glibc/libdl.so.2 image/$occlum_glibc
cp $occlum_glibc/librt.so.1 image/$occlum_glibc
cp /usr/local/occlum/x86_64-linux-musl/lib/libz.so.1 image/lib
cp /etc/nsswitch.conf image/etc
cp /etc/resolv.conf image/etc
cp /etc/host.conf image/etc
cp /etc/group image/etc
cp /etc/ssl/certs/ca-certificates.crt image/etc
cp /etc/hosts image/etc
cp /etc/passwd image/etc
cp /etc/gai.conf image/etc

mkdir -p image/opt/occlum/glibc/etc
cp /etc/ld.so.cache image/opt/occlum/glibc/etc

occlum build

echo -e "${BLUE}occlum run /bin/ra-tls-server${NC}"
occlum run /bin/ra-tls-server

cd ..
make clean
