// Copyright 2016 squimrel
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

#ifndef SRC_PNG_H_
#define SRC_PNG_H_

#include <memory>  // std::unique_ptr
#include <string>  // std::string
#include <tuple>   // std::tuple

extern "C" {
#include <png.h>
}

#include "./src/utilities.h"

/**
 * Extra class for RAII.
 */
class PngData {
 public:
  png_structp structure;
  png_infop info;

  PngData();
  ~PngData();
};

class Png {
 public:
  std::unique_ptr<PngData> data;

  Png();
  void open(const std::string& filename);
  std::tuple<int, int, int, int> color(const int x, const int y) const;

 private:
  file_ptr file_;
};

#endif  // SRC_PNG_H_
