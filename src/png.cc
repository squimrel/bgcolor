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

#include "./src/png.h"

#include <string>  // std::string
#include <tuple>   // std::make_tuple, std::tuple

Png::Png() {}

void Png::open(const std::string& filename) {
  throw std::runtime_error("Not yet implemented.");
}

std::tuple<int, int, int, int> Png::color(const int x, const int y) const {
  throw std::runtime_error("Not yet implemented.");
  return std::make_tuple(0, 0, 0, 0);
}
