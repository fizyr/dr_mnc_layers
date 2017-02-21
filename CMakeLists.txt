cmake_minimum_required(VERSION 3.1)
project(dr_mnc_layers)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

find_package(Caffe REQUIRED)
find_package(CUDA REQUIRED)
find_package(YamlCpp REQUIRED)

set(CUDA_HOST_COMPILER g++-5)
set(CUDA_PROPAGATE_HOST_FLAGS off)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)

include_directories(
	${Caffe_INCLUDE_DIRS}
	${CUDA_INCLUDE_DIRS}
	${YamlCpp_INCLUDE_DIRS}
)

cuda_add_library(mnc MODULE
	src/mask_pooling_layer.cpp
	src/mask_pooling_layer.cu
	src/mask_resize_layer.cpp
	src/mask_resize_layer.cu
	src/roi_pooling_layer.cpp
	src/roi_pooling_layer.cu
	src/roi_warping_layer.cpp
	src/roi_warping_layer.cu
	src/smooth_L1_loss_layer.cpp
	src/smooth_L1_loss_layer.cu
)

target_link_libraries(mnc
	${Caffe_LIBRARIES}
	${CUDA_LIBRARIES}
	${YamlCpp_LIBRARIES}
)
