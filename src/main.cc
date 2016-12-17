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

#include <iostream>  // std::cerr
#include <string>    // std::string

int main(int argc, const char* argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " [image]\n";
    return 1;
  }
  const std::string filename = argv[1];
  // TODO(squimrel): Get the color of the pixel in the top left corner.
  std::cerr << "Not yet implemented.\n";
  return 1;
}
