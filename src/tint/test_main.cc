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

#include "gmock/gmock.h"
#include "tint/tint.h"

namespace {

void TintInternalCompilerErrorReporter(const tint::InternalCompilerError& err) {
    FAIL() << err.Error();
}

struct Flags {
    bool spirv_reader_dump_converted = false;

    bool parse(int argc, char** argv) {
        bool errored = false;
        for (int i = 1; i < argc && !errored; i++) {
            auto match = [&](std::string name) { return name == argv[i]; };

            if (match("--dump-spirv")) {
                spirv_reader_dump_converted = true;
            } else {
                std::cout << "Unknown flag '" << argv[i] << "'" << std::endl;
                return false;
            }
        }
        return true;
    }
};

}  // namespace

// Entry point for tint unit tests
int main(int argc, char** argv) {
    testing::InitGoogleMock(&argc, argv);

    tint::Initialize();

    Flags flags;
    if (!flags.parse(argc, argv)) {
        return -1;
    }

    tint::SetInternalCompilerErrorReporter(&TintInternalCompilerErrorReporter);

    auto res = RUN_ALL_TESTS();

    tint::Shutdown();

    return res;
}
