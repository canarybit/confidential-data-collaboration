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


struct buffer_and_size {
    char* data;
    size_t len;
};

void http_get
(
    CURL* curl,
    const char* url,
    struct buffer_and_size* header,
    struct buffer_and_size* body,
    struct curl_slist* request_headers,
    char* request_body
);
