// Copyright 2015, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Injection point for custom user configurations. See README for details
//
// ** Custom implementation starts here **

#ifndef GTEST_INCLUDE_GTEST_INTERNAL_CUSTOM_GTEST_PORT_H_
#define GTEST_INCLUDE_GTEST_INTERNAL_CUSTOM_GTEST_PORT_H_

#ifdef arm

// Disable all features that do not work out of the box with embedded targets

#define GTEST_HAS_CLONE 0
#define GTEST_HAS_EXCEPTIONS 0
#define GTEST_HAS_POSIX_RE 0
#define GTEST_HAS_PTHREAD 0
#define GTEST_HAS_RTTI 0
#define GTEST_HAS_STREAM_REDIRECTION 0
#define GTEST_HAS_DEATH_TEST 0

// The folowing function are used by gtest, but are not available on embedded targets
// Having these dummy implementations is good enuogh for most cases

extern "C" inline FILE* fdopen(int fd __attribute__((unused)), const char* mode __attribute__((unused))) { return NULL; }
extern "C" inline char* getcwd(char *buf, size_t size __attribute__((unused))) { buf[0] = '.'; buf[1] = 0; return buf; }
extern "C" inline char* strdup(const char *str) { return strcpy((char*)malloc(strlen(str)+1), str); }
extern "C" inline int mkdir(const char *path __attribute__((unused)), mode_t mode __attribute__((unused))) { return -1; }
extern "C" inline int fileno(FILE *stream __attribute__((unused))) { return -1; }

#endif // arm 

#endif  // GTEST_INCLUDE_GTEST_INTERNAL_CUSTOM_GTEST_PORT_H_
