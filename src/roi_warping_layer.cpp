// --------------------------------------------------------
// Multitask Network Cascade
// Written by Haozhi Qi
// Copyright (c) 2016, Haozhi Qi
// Licensed under The MIT License [see LICENSE for details]
// --------------------------------------------------------

#include "caffe/fast_rcnn_layers.hpp"

#include <yaml-cpp/yaml.h>

#include <cfloat>

using std::max;
using std::min;
using std::floor;
using std::ceil;

namespace caffe {

template <typename Dtype>
void ROIWarpingLayer<Dtype>::LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {
  // parse param string
  YAML::Node params = YAML::Load(this->layer_param_.module_param().param_str());

  // check existence of parameters
  CHECK(params["pooled_w"]) << "not found as parameter.";
  CHECK(params["pooled_h"]) << "not found as parameter.";
  CHECK(params["spatial_scale"]) << "not found as parameter.";

  // parse parameters
  pooled_width_  = params["pooled_w"].as<int>();
  pooled_height_ = params["pooled_h"].as<int>();
  spatial_scale_ = params["spatial_scale"].as<Dtype>();

  CHECK_GT(pooled_height_, 0)
      << "pooled_h must be > 0";
  CHECK_GT(pooled_width_, 0)
      << "pooled_w must be > 0";
}

template <typename Dtype>
void ROIWarpingLayer<Dtype>::Reshape(const vector<Blob<Dtype>*>& bottom, const vector<Blob<Dtype>*>& top) {
  channels_ = bottom[0]->channels();
  height_ = bottom[0]->height();
  width_ = bottom[0]->width();
  top[0]->Reshape(bottom[1]->num(), channels_, pooled_height_, pooled_width_);
  max_idx_w_.Reshape(bottom[1]->num(), channels_, pooled_height_, pooled_width_);
  max_idx_h_.Reshape(bottom[1]->num(), channels_, pooled_height_, pooled_width_);
  buffer_.Reshape(bottom[1]->num() * 5, channels_, pooled_height_, pooled_width_);
}

template <typename Dtype>
void ROIWarpingLayer<Dtype>::Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {
  NOT_IMPLEMENTED;
}

template <typename Dtype>
void ROIWarpingLayer<Dtype>::Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {
  NOT_IMPLEMENTED;
}

#ifdef CPU_ONLY
STUB_GPU(ROIWarpingLayer);
#endif

INSTANTIATE_CLASS(ROIWarpingLayer);
//REGISTER_LAYER_CLASS(ROIWarping);
EXPORT_LAYER_MODULE_CLASS(ROIWarping);

}  // namespace caffe
