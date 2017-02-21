// --------------------------------------------------------
// Multitask Network Cascade
// Written by Haozhi Qi
// Copyright (c) 2016, Haozhi Qi
// Licensed under The MIT License [see LICENSE for details]
// --------------------------------------------------------

#include "mask_resize_layer.hpp"

#include <yaml-cpp/yaml.h>

namespace caffe {

template <typename Dtype>
void MaskResizeLayer<Dtype>::LayerSetUp(const vector<Blob<Dtype>*>& bottom, const vector<Blob<Dtype>*>& top) {
  // parse param string
  YAML::Node params = YAML::Load(this->layer_param_.module_param().param_str());

  // check existence of parameters
  CHECK(params["output_height"]) << "not found as parameter.";
  CHECK(params["output_width"]) << "not found as parameter.";

  // parse parameters
  output_width_  = params["output_width"].as<int>();
  output_height_ = params["output_height"].as<int>();

  CHECK_GT(output_height_, 0) << "output_height must be > 0";
  CHECK_GT(output_width_, 0) << "output_width must be > 0";
}

template <typename Dtype>
void MaskResizeLayer<Dtype>::Reshape(const vector<Blob<Dtype>*>& bottom, const vector<Blob<Dtype>*>& top) {
  input_channels_ = bottom[0]->channels();
  output_channels_ = input_channels_;
  input_height_ = bottom[0]->height();
  input_width_ = bottom[0]->width();
  
  top[0]->Reshape(bottom[0]->num(), output_channels_, output_height_, output_width_);
}

template <typename Dtype>
void MaskResizeLayer<Dtype>::Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {
  NOT_IMPLEMENTED;
}

template <typename Dtype>
void MaskResizeLayer<Dtype>::Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {
  NOT_IMPLEMENTED;
}
  
#ifdef CPU_ONLY
STUB_GPU(MaskResizeLayer);
#endif

INSTANTIATE_CLASS(MaskResizeLayer);
//REGISTER_LAYER_CLASS(MaskResize);
EXPORT_LAYER_MODULE_CLASS(MaskResize);

}  // namespace caffe
