/* Copyright 2020 The TensorFlow Authors. All Rights Reserved.
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
    http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

// Automatically created from a TensorFlow Lite flatbuffer using the command:
// xxd -i model.tflite > model.cc

// This is a standard TensorFlow Lite model file that has been converted into a
// C data array, so it can be easily compiled into a binary for devices that
// don't have a file system.

#include "modelHW.h"

// We need to keep the data array aligned on some architectures.
#ifdef __has_attribute
#define HAVE_ATTRIBUTE(x) __has_attribute(x)
#else
#define HAVE_ATTRIBUTE(x) 0
#endif
#if HAVE_ATTRIBUTE(aligned) || (defined(__GNUC__) && !defined(__clang__))
#define DATA_ALIGN_ATTRIBUTE __attribute__((aligned(4)))
#else
#define DATA_ALIGN_ATTRIBUTE
#endif

//const unsigned char g_model[] DATA_ALIGN_ATTRIBUTE = {
const unsigned char g_model[] __attribute__((aligned(16))) = {
    0x08, 0x00, 0x00, 0x00, 0x54, 0x46, 0x4c, 0x33, 0x32, 0xfa, 0xff, 0xff, 0x03,
    0x00, 0x00, 0x00, 0xc8, 0x09, 0x00, 0x00, 0xb8, 0x05, 0x00, 0x00, 0xa0, 0x05,
    0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x90, 0x05, 0x00,
    0x00, 0x88, 0x05, 0x00, 0x00, 0x38, 0x05, 0x00, 0x00, 0xe0, 0x04, 0x00, 0x00,
    0xcc, 0x04, 0x00, 0x00, 0x7c, 0x04, 0x00, 0x00, 0x6c, 0x00, 0x00, 0x00, 0x1c,
    0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x04, 0x00,
    0x00, 0x00, 0xa0, 0xf6, 0xff, 0xff, 0xa4, 0xf6, 0xff, 0xff, 0xa8, 0xf6, 0xff,
    0xff, 0xfe, 0xfa, 0xff, 0xff, 0x04, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00,
    0x3f, 0xcb, 0x61, 0x3f, 0x07, 0x1f, 0x0b, 0x3f, 0x9b, 0x73, 0xc3, 0xbe, 0x4c,
    0x8b, 0x2f, 0xbe, 0xa5, 0x13, 0x0b, 0xbf, 0xdd, 0x33, 0x54, 0x3f, 0x90, 0xd1,
    0xb6, 0x3f, 0x2a, 0x39, 0x73, 0xbf, 0x71, 0x8e, 0x47, 0x3e, 0x8a, 0xcd, 0x31,
    0xbe, 0xe0, 0x1a, 0x2b, 0x3c, 0x12, 0x24, 0x14, 0x3e, 0xa4, 0x33, 0x8a, 0x3f,
    0x19, 0x45, 0x33, 0xbf, 0x15, 0x0a, 0x02, 0xbf, 0xf7, 0xbb, 0x96, 0xbf, 0x4a,
    0xfb, 0xff, 0xff, 0x04, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x43, 0x62,
    0xbf, 0xbe, 0x48, 0x58, 0x12, 0xbf, 0x12, 0x3a, 0x2a, 0x3e, 0x32, 0x58, 0xd4,
    0xbf, 0xac, 0x8b, 0x61, 0xbe, 0x28, 0x24, 0x82, 0xbd, 0x54, 0x1e, 0x80, 0x3d,
    0x83, 0x8c, 0x4b, 0x3e, 0x00, 0x29, 0x9f, 0xbc, 0x43, 0x61, 0xb4, 0x3e, 0x29,
    0x8a, 0x0d, 0xbd, 0xc9, 0xda, 0x53, 0xbe, 0xc6, 0x1a, 0x95, 0xbe, 0xa8, 0xfe,
    0x1e, 0x3d, 0x53, 0xd6, 0xd4, 0x3e, 0xb6, 0x30, 0x3a, 0x3e, 0x80, 0xd7, 0xef,
    0x3b, 0xd0, 0x44, 0x5a, 0x3d, 0x17, 0x82, 0xa5, 0xbe, 0x09, 0x11, 0x79, 0xbe,
    0x7c, 0x60, 0xd7, 0x3d, 0x2f, 0xc0, 0x6d, 0xbe, 0xa2, 0x44, 0x3a, 0x3e, 0x20,
    0xe4, 0x88, 0xbe, 0xdc, 0xde, 0x80, 0x3d, 0x12, 0xe7, 0x82, 0xbe, 0x26, 0x77,
    0x84, 0x3e, 0x24, 0x9e, 0x95, 0xbe, 0x8f, 0x27, 0x90, 0x3e, 0x30, 0x7b, 0xa0,
    0x3c, 0xe6, 0xe4, 0x97, 0x3e, 0x43, 0x17, 0x8c, 0x3e, 0x81, 0x11, 0xc1, 0xbe,
    0xd6, 0xe3, 0x4c, 0x3a, 0x12, 0x33, 0x23, 0x3e, 0x9c, 0xee, 0x43, 0x3f, 0x64,
    0x44, 0xa3, 0xbd, 0xc0, 0x96, 0x90, 0x3b, 0xfc, 0xcd, 0xb4, 0xbe, 0xc2, 0x55,
    0x95, 0x3a, 0xbc, 0x1d, 0xb9, 0xbe, 0x17, 0xad, 0xd5, 0x3e, 0x0a, 0xcd, 0x82,
    0x3e, 0x09, 0x31, 0xb7, 0xbe, 0xe6, 0xf6, 0xa8, 0xbe, 0x73, 0xf0, 0xc1, 0x3e,
    0x01, 0x43, 0x4e, 0xbc, 0x0b, 0x29, 0xb0, 0x3e, 0xae, 0xad, 0xb0, 0xbe, 0xfa,
    0x33, 0x27, 0x3d, 0x95, 0xe4, 0xc6, 0x3e, 0x13, 0xcb, 0x5a, 0x3f, 0xbd, 0x5c,
    0xb9, 0xbe, 0x00, 0x52, 0x01, 0x3d, 0x00, 0xcb, 0x29, 0xbd, 0x6f, 0x87, 0x92,
    0x3e, 0x13, 0x0b, 0x94, 0x3e, 0x72, 0xb5, 0x15, 0x3e, 0x0f, 0xfe, 0xdb, 0x3d,
    0xdd, 0x8a, 0x71, 0xbe, 0x84, 0x96, 0xaa, 0xbd, 0xcc, 0x99, 0x9b, 0xbe, 0x26,
    0xe0, 0xd7, 0xbe, 0x16, 0xd7, 0xc2, 0xbe, 0xfa, 0x0a, 0x6b, 0x3e, 0x9f, 0xb5,
    0x8c, 0x3e, 0xba, 0x29, 0x37, 0xbe, 0x6d, 0x9f, 0x54, 0xbe, 0xdc, 0x29, 0xa4,
    0xbe, 0x04, 0x19, 0xe1, 0x3d, 0xce, 0xdb, 0xc7, 0xbe, 0xb6, 0x93, 0x9e, 0xbe,
    0x52, 0x83, 0x02, 0x3e, 0xa4, 0x9c, 0xba, 0xbe, 0x18, 0xe8, 0x44, 0x3d, 0xe0,
    0x80, 0x24, 0xbd, 0xf2, 0x31, 0x5c, 0x3e, 0x00, 0xe5, 0xd5, 0xba, 0xc7, 0xc6,
    0x54, 0xbe, 0x9e, 0xc6, 0x19, 0xbe, 0x84, 0xa2, 0x36, 0xbe, 0x08, 0x8b, 0x09,
    0xbf, 0xaa, 0x74, 0x3e, 0x3e, 0x9d, 0x70, 0x96, 0xbf, 0xb0, 0xa0, 0x3b, 0xbd,
    0xd0, 0xe7, 0x87, 0x3d, 0x0c, 0x07, 0x94, 0xbd, 0x79, 0xae, 0xcf, 0xbe, 0x9a,
    0x1c, 0xba, 0xbe, 0x90, 0x33, 0xd0, 0x3c, 0xa8, 0xeb, 0xc6, 0x3e, 0x46, 0x09,
    0x27, 0x3e, 0x40, 0xc8, 0x85, 0xbc, 0xd9, 0x0d, 0xbe, 0xbe, 0xf6, 0xa4, 0x4a,
    0xbc, 0xb6, 0x45, 0x93, 0xbe, 0x6f, 0x52, 0x99, 0x3e, 0xca, 0xa5, 0x1d, 0x3a,
    0xdc, 0xe1, 0xfa, 0x3d, 0x96, 0xc8, 0x75, 0x3f, 0x11, 0x2a, 0xc4, 0xbe, 0xe0,
    0x9a, 0x9d, 0xbd, 0x60, 0x6a, 0xc0, 0xbe, 0x63, 0xcb, 0xd3, 0x3e, 0xe0, 0xb4,
    0x17, 0xbc, 0x89, 0x99, 0xa7, 0x3e, 0x5f, 0x41, 0xf8, 0xbe, 0x27, 0x2f, 0xbc,
    0xbe, 0xe6, 0x3e, 0x6e, 0x3e, 0xa8, 0x31, 0x83, 0xbe, 0x1f, 0x0d, 0x76, 0xbd,
    0x4f, 0x9b, 0xc8, 0x3e, 0x55, 0x0f, 0x9e, 0x3e, 0x60, 0xc3, 0x3e, 0x3e, 0xbb,
    0x9d, 0x9f, 0x3e, 0xf7, 0x43, 0x1b, 0x3f, 0x74, 0x03, 0x2e, 0xbe, 0x82, 0xcb,
    0x90, 0xbe, 0x53, 0x56, 0xaf, 0x3e, 0x94, 0x93, 0x2f, 0xbd, 0xfa, 0x36, 0x28,
    0xbe, 0x18, 0xd8, 0xb7, 0xbd, 0xcc, 0xdb, 0x1e, 0xbe, 0x3d, 0xa5, 0xda, 0xbe,
    0x0e, 0x14, 0x08, 0x3e, 0x24, 0xd8, 0x99, 0xbe, 0x2f, 0x06, 0x47, 0xbf, 0x06,
    0x1d, 0x39, 0x3e, 0xdd, 0x27, 0x89, 0xbe, 0xda, 0x85, 0xa3, 0xbe, 0x00, 0x94,
    0x01, 0xba, 0x48, 0x2b, 0x5f, 0x3e, 0x7b, 0xd7, 0x82, 0x3e, 0x27, 0xa0, 0xd5,
    0x3e, 0x90, 0xba, 0xd2, 0xbe, 0x49, 0xa8, 0xe6, 0xbd, 0x9d, 0xce, 0x87, 0x3e,
    0xbb, 0xd5, 0x3f, 0xbe, 0xb2, 0x86, 0x71, 0xbe, 0x15, 0x99, 0x4c, 0xbe, 0x18,
    0xb2, 0xae, 0xbd, 0xc8, 0x10, 0x0f, 0xbe, 0xc6, 0xf2, 0xb6, 0xbe, 0xf4, 0xbc,
    0x44, 0xbe, 0x1c, 0x80, 0xfd, 0x3d, 0xa5, 0x46, 0x35, 0xbd, 0xfa, 0x13, 0x6e,
    0x3e, 0x9e, 0xd3, 0x8f, 0x3f, 0x7a, 0x26, 0x92, 0xbe, 0x68, 0xa1, 0x74, 0xbe,
    0x70, 0x24, 0x9b, 0xbe, 0xa8, 0x8e, 0xbe, 0x3e, 0xe8, 0xc6, 0x4d, 0x3d, 0x2e,
    0x31, 0x0f, 0x3e, 0x76, 0xad, 0xce, 0x3e, 0x89, 0xfa, 0xd4, 0x3e, 0x7c, 0xcd,
    0xdf, 0xbd, 0x60, 0x54, 0x01, 0x3d, 0xc3, 0xf5, 0x8e, 0xbe, 0x3c, 0x03, 0x9e,
    0xbe, 0x2c, 0x33, 0xd1, 0xbe, 0xce, 0xc1, 0x57, 0xbd, 0x82, 0x76, 0x36, 0x3e,
    0x9d, 0x1d, 0x9b, 0x3d, 0x82, 0xf4, 0xb1, 0xbe, 0xff, 0x34, 0xac, 0x3e, 0x1a,
    0xfe, 0xc6, 0xbe, 0x66, 0xe2, 0x5d, 0x3d, 0x7c, 0x87, 0x9a, 0xbe, 0xc0, 0xd3,
    0x8c, 0xbc, 0xb3, 0xec, 0x4d, 0x3e, 0x23, 0x33, 0xca, 0xbe, 0xe0, 0x53, 0xdd,
    0xbd, 0x14, 0x76, 0xe0, 0x3d, 0x80, 0x48, 0x2f, 0x3e, 0xce, 0x7b, 0xd8, 0xbe,
    0x60, 0xbe, 0x9a, 0x3c, 0xba, 0xf1, 0x09, 0x3e, 0x64, 0xe6, 0xc5, 0x3d, 0x22,
    0xb4, 0x19, 0xbe, 0xf8, 0xe8, 0xf0, 0xbd, 0xb0, 0x69, 0xbf, 0xbc, 0x79, 0xf3,
    0xad, 0x3e, 0x17, 0x4d, 0xf4, 0xbd, 0x08, 0xce, 0x16, 0xbe, 0xa8, 0x97, 0xad,
    0xbd, 0x2b, 0x63, 0x11, 0x3e, 0x8c, 0x44, 0x95, 0x3d, 0x63, 0x13, 0xc6, 0x3e,
    0x40, 0xf9, 0x19, 0x3d, 0xec, 0xf5, 0x82, 0x3e, 0xa2, 0xb4, 0x1a, 0x3e, 0x8c,
    0xfa, 0xbb, 0x3d, 0x88, 0xb3, 0x28, 0x3f, 0xe1, 0xd2, 0xd0, 0x3e, 0x87, 0xa4,
    0x61, 0x3f, 0xe6, 0x36, 0x7f, 0x3e, 0x84, 0x27, 0xe1, 0xbd, 0x68, 0x99, 0x73,
    0xbd, 0x98, 0x96, 0x0c, 0xbe, 0x60, 0x00, 0xe9, 0x3c, 0x58, 0x0d, 0x00, 0x3d,
    0x1f, 0x7e, 0xe9, 0xbe, 0x8a, 0x67, 0xaf, 0xbe, 0xf6, 0x7e, 0x59, 0x3e, 0x7e,
    0x15, 0x29, 0xbe, 0xf1, 0x37, 0xc7, 0xbd, 0xf7, 0x15, 0xc1, 0x3e, 0x32, 0x24,
    0xad, 0xbe, 0x98, 0xe5, 0x5b, 0x3e, 0xe9, 0xf8, 0xdb, 0xbe, 0x86, 0xa2, 0x1b,
    0x3f, 0xd5, 0x7b, 0x55, 0xbe, 0x50, 0x59, 0xca, 0xbd, 0xb9, 0xa2, 0xc3, 0xbe,
    0x20, 0x08, 0x10, 0xbe, 0x1e, 0xa9, 0x81, 0xbe, 0x89, 0x0d, 0xcb, 0xbe, 0x81,
    0x19, 0x2f, 0xbf, 0x9c, 0xc0, 0xb7, 0xbd, 0x52, 0x0a, 0x7d, 0x3e, 0x70, 0x39,
    0xa4, 0x3c, 0xae, 0xa1, 0xe5, 0xbd, 0xb8, 0xcf, 0x26, 0xbd, 0x2e, 0xcc, 0x5c,
    0x3e, 0xab, 0x74, 0x11, 0x3f, 0xc0, 0x2d, 0x4e, 0xbd, 0x10, 0x18, 0x59, 0x3f,
    0x7e, 0x47, 0xb6, 0xbe, 0x92, 0xd1, 0x3e, 0xbe, 0xaf, 0x09, 0xbf, 0xbe, 0xf5,
    0xfe, 0x7b, 0x3e, 0x09, 0xb3, 0x8c, 0x3e, 0x51, 0xa2, 0x95, 0x3e, 0x6e, 0x6e,
    0xb6, 0x3e, 0x64, 0xe0, 0x0b, 0xbe, 0x30, 0x5b, 0x51, 0x3d, 0xbc, 0xe6, 0xb3,
    0x3d, 0xb9, 0x03, 0xb4, 0xbe, 0xb0, 0x9c, 0x29, 0x3d, 0x08, 0x1f, 0x31, 0xbe,
    0x73, 0xdb, 0xda, 0x3d, 0x01, 0x5d, 0xc7, 0x3e, 0x64, 0x62, 0x25, 0x3f, 0x1b,
    0x76, 0x9e, 0x3e, 0x16, 0xc1, 0x07, 0xbe, 0x26, 0x4a, 0x02, 0x3e, 0xdd, 0x6c,
    0xe0, 0xbe, 0x74, 0x06, 0x86, 0xbe, 0xa6, 0x62, 0x0b, 0x3e, 0x08, 0x45, 0x99,
    0xbe, 0x8d, 0x47, 0xd9, 0x3e, 0x00, 0xbd, 0xa0, 0xbc, 0x3f, 0x08, 0xd0, 0xbe,
    0x06, 0x85, 0x63, 0xbf, 0x8a, 0xd5, 0xa2, 0xbe, 0x56, 0xff, 0xff, 0xff, 0x04,
    0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x85, 0xbe, 0xbe, 0x60, 0x61,
    0x6c, 0xbd, 0x79, 0x12, 0x11, 0xbf, 0xff, 0xa8, 0x1c, 0xbe, 0x7c, 0x33, 0xc9,
    0xbd, 0xb5, 0x91, 0xac, 0xbe, 0xb4, 0x46, 0xfb, 0xbe, 0xd8, 0x85, 0x4b, 0x3e,
    0x7c, 0xe1, 0xea, 0xbe, 0x00, 0x4e, 0x7d, 0xbb, 0xf9, 0x9f, 0x19, 0x3f, 0x6a,
    0xdd, 0x17, 0xbf, 0xc1, 0x46, 0x83, 0xbe, 0xc0, 0x91, 0x43, 0xbd, 0xc4, 0x75,
    0xb7, 0x3e, 0xaa, 0xcc, 0x5c, 0xbe, 0xa2, 0xff, 0xff, 0xff, 0x04, 0x00, 0x00,
    0x00, 0x04, 0x00, 0x00, 0x00, 0x38, 0xe3, 0x0b, 0xbe, 0xb2, 0xff, 0xff, 0xff,
    0x04, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0xf2, 0x1b, 0xc1, 0xbe, 0xfe,
    0x91, 0xfe, 0xbd, 0xb1, 0x1a, 0x08, 0x3e, 0xc3, 0x3f, 0xcd, 0x3d, 0x00, 0x00,
    0x00, 0x00, 0x35, 0x57, 0x25, 0xbe, 0x71, 0xb0, 0xf9, 0x3e, 0xdc, 0x82, 0xab,
    0x3e, 0x7c, 0x49, 0xe9, 0xbc, 0x85, 0x75, 0x11, 0x3e, 0x05, 0xf9, 0x28, 0xbd,
    0x4c, 0xe9, 0xd5, 0xbd, 0xb2, 0xb1, 0x1a, 0x3f, 0xfa, 0xfa, 0x74, 0x3e, 0xb1,
    0xa0, 0x1b, 0x3e, 0x44, 0xb6, 0x7e, 0x3e, 0x00, 0x00, 0x06, 0x00, 0x08, 0x00,
    0x04, 0x00, 0x06, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x98, 0x3e, 0x3f, 0x00, 0x00, 0x00, 0x00,
    0x41, 0x57, 0x76, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x85, 0xbe, 0xb9, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x6f, 0x75, 0xb4, 0xbe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xbb, 0x3d, 0xd4, 0xbc, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xfc, 0xff, 0xff, 0x04, 0xfc, 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00, 0x4d,
    0x4c, 0x49, 0x52, 0x20, 0x43, 0x6f, 0x6e, 0x76, 0x65, 0x72, 0x74, 0x65, 0x64,
    0x2e, 0x00, 0x01, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e,
    0x00, 0x18, 0x00, 0x04, 0x00, 0x08, 0x00, 0x0c, 0x00, 0x10, 0x00, 0x14, 0x00,
    0x0e, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0xf4, 0x00, 0x00, 0x00, 0xe8,
    0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00,
    0x00, 0x00, 0x6d, 0x61, 0x69, 0x6e, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00,
    0x00, 0x90, 0x00, 0x00, 0x00, 0x48, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
    0xce, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x08, 0x18, 0x00, 0x00, 0x00, 0x0c,
    0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x7c, 0xfc, 0xff, 0xff, 0x01, 0x00,
    0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00,
    0x00, 0x06, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00,
    0x14, 0x00, 0x00, 0x00, 0x08, 0x00, 0x0c, 0x00, 0x07, 0x00, 0x10, 0x00, 0x0e,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x1c, 0x00, 0x00, 0x00, 0x10, 0x00,
    0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xba, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00,
    0x01, 0x01, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
    0x07, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0e, 0x00, 0x16, 0x00, 0x00, 0x00, 0x08, 0x00, 0x0c, 0x00, 0x07, 0x00,
    0x10, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x24, 0x00, 0x00,
    0x00, 0x18, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00,
    0x08, 0x00, 0x07, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
    0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
    0x00, 0x09, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0a, 0x00, 0x00, 0x00, 0xb0, 0x02, 0x00, 0x00, 0x4c, 0x02, 0x00, 0x00, 0xf8,
    0x01, 0x00, 0x00, 0xa4, 0x01, 0x00, 0x00, 0x5c, 0x01, 0x00, 0x00, 0x14, 0x01,
    0x00, 0x00, 0xcc, 0x00, 0x00, 0x00, 0x84, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00,
    0x00, 0x04, 0x00, 0x00, 0x00, 0x86, 0xfd, 0xff, 0xff, 0x24, 0x00, 0x00, 0x00,
    0x0a, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x78,
    0xfd, 0xff, 0xff, 0x08, 0x00, 0x00, 0x00, 0x49, 0x64, 0x65, 0x6e, 0x74, 0x69,
    0x74, 0x79, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
    0x00, 0x01, 0x00, 0x00, 0x00, 0xba, 0xfd, 0xff, 0xff, 0x34, 0x00, 0x00, 0x00,
    0x09, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xac,
    0xfd, 0xff, 0xff, 0x19, 0x00, 0x00, 0x00, 0x73, 0x65, 0x71, 0x75, 0x65, 0x6e,
    0x74, 0x69, 0x61, 0x6c, 0x5f, 0x31, 0x2f, 0x64, 0x65, 0x6e, 0x73, 0x65, 0x5f,
    0x34, 0x2f, 0x52, 0x65, 0x6c, 0x75, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0xfe, 0xfd, 0xff, 0xff, 0x34,
    0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x04, 0x00,
    0x00, 0x00, 0xf0, 0xfd, 0xff, 0xff, 0x19, 0x00, 0x00, 0x00, 0x73, 0x65, 0x71,
    0x75, 0x65, 0x6e, 0x74, 0x69, 0x61, 0x6c, 0x5f, 0x31, 0x2f, 0x64, 0x65, 0x6e,
    0x73, 0x65, 0x5f, 0x33, 0x2f, 0x52, 0x65, 0x6c, 0x75, 0x00, 0x00, 0x00, 0x02,
    0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x42, 0xfe,
    0xff, 0xff, 0x34, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00,
    0x00, 0x04, 0x00, 0x00, 0x00, 0x34, 0xfe, 0xff, 0xff, 0x1b, 0x00, 0x00, 0x00,
    0x73, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x74, 0x69, 0x61, 0x6c, 0x5f, 0x31, 0x2f,
    0x64, 0x65, 0x6e, 0x73, 0x65, 0x5f, 0x35, 0x2f, 0x4d, 0x61, 0x74, 0x4d, 0x75,
    0x6c, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00,
    0x00, 0x86, 0xfe, 0xff, 0xff, 0x34, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x78, 0xfe, 0xff, 0xff, 0x1b,
    0x00, 0x00, 0x00, 0x73, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x74, 0x69, 0x61, 0x6c,
    0x5f, 0x31, 0x2f, 0x64, 0x65, 0x6e, 0x73, 0x65, 0x5f, 0x34, 0x2f, 0x4d, 0x61,
    0x74, 0x4d, 0x75, 0x6c, 0x00, 0x02, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
    0x10, 0x00, 0x00, 0x00, 0xca, 0xfe, 0xff, 0xff, 0x34, 0x00, 0x00, 0x00, 0x05,
    0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xbc, 0xfe,
    0xff, 0xff, 0x1b, 0x00, 0x00, 0x00, 0x73, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x74,
    0x69, 0x61, 0x6c, 0x5f, 0x31, 0x2f, 0x64, 0x65, 0x6e, 0x73, 0x65, 0x5f, 0x33,
    0x2f, 0x4d, 0x61, 0x74, 0x4d, 0x75, 0x6c, 0x00, 0x02, 0x00, 0x00, 0x00, 0x10,
    0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0e, 0xff, 0xff, 0xff, 0x44, 0x00,
    0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00,
    0x00, 0x00, 0xff, 0xff, 0xff, 0x2b, 0x00, 0x00, 0x00, 0x73, 0x65, 0x71, 0x75,
    0x65, 0x6e, 0x74, 0x69, 0x61, 0x6c, 0x5f, 0x31, 0x2f, 0x64, 0x65, 0x6e, 0x73,
    0x65, 0x5f, 0x35, 0x2f, 0x42, 0x69, 0x61, 0x73, 0x41, 0x64, 0x64, 0x2f, 0x52,
    0x65, 0x61, 0x64, 0x56, 0x61, 0x72, 0x69, 0x61, 0x62, 0x6c, 0x65, 0x4f, 0x70,
    0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x5e, 0xff, 0xff, 0xff,
    0x44, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x04,
    0x00, 0x00, 0x00, 0x50, 0xff, 0xff, 0xff, 0x2b, 0x00, 0x00, 0x00, 0x73, 0x65,
    0x71, 0x75, 0x65, 0x6e, 0x74, 0x69, 0x61, 0x6c, 0x5f, 0x31, 0x2f, 0x64, 0x65,
    0x6e, 0x73, 0x65, 0x5f, 0x34, 0x2f, 0x42, 0x69, 0x61, 0x73, 0x41, 0x64, 0x64,
    0x2f, 0x52, 0x65, 0x61, 0x64, 0x56, 0x61, 0x72, 0x69, 0x61, 0x62, 0x6c, 0x65,
    0x4f, 0x70, 0x00, 0x01, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0xae, 0xff,
    0xff, 0xff, 0x44, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00,
    0x00, 0x04, 0x00, 0x00, 0x00, 0xa0, 0xff, 0xff, 0xff, 0x2b, 0x00, 0x00, 0x00,
    0x73, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x74, 0x69, 0x61, 0x6c, 0x5f, 0x31, 0x2f,
    0x64, 0x65, 0x6e, 0x73, 0x65, 0x5f, 0x33, 0x2f, 0x42, 0x69, 0x61, 0x73, 0x41,
    0x64, 0x64, 0x2f, 0x52, 0x65, 0x61, 0x64, 0x56, 0x61, 0x72, 0x69, 0x61, 0x62,
    0x6c, 0x65, 0x4f, 0x70, 0x00, 0x01, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0e, 0x00, 0x14, 0x00, 0x04, 0x00, 0x00, 0x00, 0x08, 0x00, 0x0c,
    0x00, 0x10, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x2c, 0x00, 0x00, 0x00, 0x01, 0x00,
    0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x04, 0x00, 0x04,
    0x00, 0x04, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x64, 0x65, 0x6e, 0x73,
    0x65, 0x5f, 0x33, 0x5f, 0x69, 0x6e, 0x70, 0x75, 0x74, 0x00, 0x00, 0x00, 0x02,
    0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00,
    0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x0c, 0x00, 0x07,
    0x00, 0x00, 0x00, 0x08, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09,
    0x03, 0x00, 0x00, 0x00,
};
const int g_model_len = 2552;
