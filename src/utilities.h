// Copyright 2017 squimrel
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef SRC_UTILITIES_H_
#define SRC_UTILITIES_H_

#include <cstdio>  // FILE

#include <functional>  // std::function
#include <memory>      // std::unique_ptr
#include <sstream>     // std::ostringstream
#include <string>      // std::string

/**
 * This can for example output a double without trailing and leading zeros.
 */
template <class T>
std::string from_stream(const T value) {
  std::ostringstream out;
  out << value;
  const std::string s = out.str();
  // Strip leading zero.
  const auto n = s.find("0.");
  return n == 0 ? s.substr(1) : s;
}

/**
 * Open file using C for use with functions that need a FILE.
 */
using file_ptr = std::unique_ptr<FILE, std::function<void(FILE*)>>;
file_ptr make_file(const std::string& filename);

#endif  // SRC_UTILITIES_H_
