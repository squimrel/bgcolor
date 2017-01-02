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

#include "./src/png.h"

#include <stdexcept>  // std::runtime_error
#include <string>     // std::string
#include <tuple>      // std::make_tuple, std::tuple

extern "C" {
#include <png.h>
}

#include "./src/utilities.h"

PngData::PngData()
    : structure(png_create_read_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr,
                                       nullptr)),
      info(png_create_info_struct(structure)) {}

PngData::~PngData() { png_destroy_read_struct(&structure, &info, nullptr); }

Png::Png() {}

void Png::open(const std::string& filename) {
  using std::runtime_error;
  file_ = make_file(filename);
  if (file_.get() == nullptr) {
    throw runtime_error("Couldn't open file.");
  }
  constexpr std::size_t kSignatureSize = 8;
  {
    unsigned char signature[kSignatureSize];
    // Read potential png signature.
    fread(signature, 1, kSignatureSize, file_.get());
    if (png_sig_cmp(signature, 0, kSignatureSize)) {
      throw runtime_error("Invalid signature.");
    }
  }

  data = std::make_unique<PngData>();

  // Link png to file.
  png_init_io(data->structure, file_.get());

  // Tell libpng that the png header was already handled.
  png_set_sig_bytes(data->structure, kSignatureSize);

  /*
   * This seems a little overkill since this will parse the entire image and
   * only one pixel is needed for the application for which this class was
   * build.
   */
  png_read_png(
      data->structure, data->info,
      // Transforms are taken from butteraugli.
      PNG_TRANSFORM_PACKING | PNG_TRANSFORM_EXPAND | PNG_TRANSFORM_STRIP_16,
      nullptr);
  // Note that libpng errors won't be handled.
}

std::tuple<int, int, int, int> Png::color(const int x, const int y) const {
  enum Rgba : int { kRed = 0, kGreen, kBlue, kAlpha };

  const int channels = png_get_channels(data->structure, data->info);
  const png_bytep* const rows = png_get_rows(data->structure, data->info);

  auto value = [rows, channels, x, y](const int i) {
    return static_cast<int>(rows[y][channels * x + i]);
  };

  return std::make_tuple(value(kRed), value(kGreen), value(kBlue),
                         channels > kAlpha ? value(kAlpha) : 0xff);
}
