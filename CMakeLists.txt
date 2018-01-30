# CMake file of hold project

## Require cmake 3.3
cmake_minimum_required(VERSION 3.3)

project(quad-tree-test)

## quad-tree daat generating base library
OPTION(QTDG_BASE_GPU "Using gpu (for qtdg-base)" OFF)

set(QTDG_BASE_SRC ${PROJECT_SOURCE_DIR}/qtdg-base.cuda/source)
set(QTDG_BASE_INC ${PROJECT_SOURCE_DIR}/qtdg-base.cuda/include)

include_directories(${QTDG_BASE_INC})

if(QTDG_BASE_GPU)
  ## Require CUDA 8.0 or later
  find_package(CUDA 8.0 REQUIRED)
  set(QTDG_BASE_GPU_I 1)
  cuda_add_library(qtdg-base SHARED ${QTDG_BASE_SRC}/qtdg-base.cc ${QTDG_BASE_SRC}/computing.cu)
else(QTDG_BASE_GPU)
  set(QTDG_BASE_GPU_I 0)
  cuda_add_library(qtdg-base SHARED ${QTDG_BASE_SRC}/qtdg-base.cc ${QTDG_BASE_SRC}/computing.cu)
endif(QTDG_BASE_GPU)

configure_file(${QTDG_BASE_INC}/qtdg-base-config.h.in ${PROJECT_BINARY_DIR}/qtdg-base-config.h  @ONLY)
include_directories(${PROJECT_BINARY_DIR})

