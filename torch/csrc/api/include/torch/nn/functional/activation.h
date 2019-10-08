#pragma once

#include <torch/nn/options/activation.h>
#include <torch/types.h>

namespace torch {
namespace nn{
namespace functional {

inline Tensor elu(Tensor& input, const ELUOptions& options) {
  if (options.inplace()) {
    return torch::elu_(input, options.alpha());
  } else {
    return torch::elu(input, options.alpha());
  }
}

inline Tensor hardshrink(const Tensor& input,
                         const HardshrinkOptions& options) {
  return torch::hardshrink(input, options.lambda());
}

inline Tensor hardtanh(Tensor& input, const HardtanhOptions& options) {
  if (options.inplace()) {
    return torch::hardtanh_(input, options.min_val(), options.max_val());
  } else {
    return torch::hardtanh(input, options.min_val(), options.max_val());
  }
}

inline Tensor leaky_relu(Tensor& input, const LeakyReLUOptions& options) {
  if (options.inplace()) {
    return torch::leaky_relu_(input, options.negative_slope());
  } else {
    return torch::leaky_relu(input, options.negative_slope());
  }
}

inline Tensor logsigmoid(const Tensor& input) {
  return torch::log_sigmoid(input);
}

inline Tensor prelu(const Tensor& input, const Tensor& weight) {
  return torch::prelu(input, weight);
}

inline Tensor relu(Tensor& input, const ReLUOptions& options) {
  if (options.inplace()) {
    return torch::relu_(input);
  } else {
    return torch::relu(input);
  }
}

inline Tensor relu6(Tensor& input, const ReLU6Options& options) {
  return hardtanh(input,
    HardtanhOptions().min_val(0).max_val(6).inplace(options.inplace()));
}

inline Tensor rrelu(Tensor& input, const RReLUOptions& options, bool training=false) {
  if (options.inplace()) {
    return torch::rrelu_(input, options.lower(), options.upper(), training);
  } else {
    return torch::rrelu(input, options.lower(), options.upper(), training);
  }
}

inline Tensor celu(Tensor& input, const CELUOptions& options) {
  if (options.inplace()) {
    return torch::celu_(input, options.alpha());
  } else {
    return torch::celu(input, options.alpha());
  }
}

inline Tensor sigmoid(const Tensor& input) {
  return torch::sigmoid(input);
}

} // namespace functional
} // namespace nn
} // namespace torch
