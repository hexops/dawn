// Copyright 2021 The Tint Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "src/ast/interpolate_decoration.h"

#include "src/ast/test_helper.h"

namespace tint {
namespace ast {
namespace {

using InterpolateDecorationTest = TestHelper;

TEST_F(InterpolateDecorationTest, Creation) {
  auto* d = create<InterpolateDecoration>(InterpolationType::kLinear,
                                          InterpolationSampling::kCenter);
  EXPECT_EQ(InterpolationType::kLinear, d->type());
  EXPECT_EQ(InterpolationSampling::kCenter, d->sampling());
}

TEST_F(InterpolateDecorationTest, ToStr) {
  auto* d = create<InterpolateDecoration>(InterpolationType::kPerspective,
                                          InterpolationSampling::kSample);
  EXPECT_EQ(str(d), R"(InterpolateDecoration{perspective sample}
)");
}

}  // namespace
}  // namespace ast
}  // namespace tint
