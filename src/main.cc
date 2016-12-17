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

#include <iomanip>   // std::setw, std::fill, std::hex
#include <iostream>  // std::cerr
#include <string>    // std::string
#include <tuple>     // std::tie

#include "./src/png.h"
#include "./src/utilities.h"

int main(int argc, const char* argv[]) {
  using std::cerr;
  using std::setw;
  if (argc < 2) {
    cerr << "Usage: " << argv[0] << " [image]\n";
    return 1;
  }
  const std::string filename = argv[1];
  Png png;
  try {
    png.open(filename);
    int red;
    int green;
    int blue;
    double alpha;
    std::tie(red, green, blue, alpha) = png.color(0, 0);
    alpha /= static_cast<double>(0xff);
    // Assume a white background color to generate a hex color.
    if (alpha != 1) {
      const int white = 0xff * (1 - alpha);
      red = red * alpha + white;
      green = green * alpha + white;
      blue = blue * alpha + white;
    }
    std::cout << "#" << std::setfill('0') << std::hex << setw(2) << red
              << setw(2) << blue << setw(2) << green << '\n';
  } catch (const std::runtime_error& err) {
    cerr << err.what();
    // I'm not sure if interupting the control flow here is actually allowed.
    return 1;
  }
}
