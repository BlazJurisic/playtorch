/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <jsi/jsi.h>

namespace torchlive {
namespace torch {

using namespace facebook;

class JSI_EXPORT TorchHostObject : public jsi::HostObject {
  jsi::Function add_;
  jsi::Function arange_;
  jsi::Function argmax_;
  jsi::Function empty_;
  jsi::Function rand_;
  jsi::Function randint_;

 public:
  TorchHostObject(jsi::Runtime& runtime);

 public:
  jsi::Value get(jsi::Runtime&, const jsi::PropNameID& name) override;
  std::vector<jsi::PropNameID> getPropertyNames(jsi::Runtime& rt) override;

 private:
  static jsi::Function createAdd(jsi::Runtime& runtime);
  static jsi::Function createArange(jsi::Runtime& runtime);
  static jsi::Function createArgmax(jsi::Runtime& runtime);
  static jsi::Function createEmpty(jsi::Runtime& runtime);
  static jsi::Function createRand(jsi::Runtime& runtime);
  static jsi::Function createRandint(jsi::Runtime& runtime);
};

} // namespace torch
} // namespace torchlive