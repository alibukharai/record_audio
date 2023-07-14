// Copyright 2018-2019 Espressif Systems (Shanghai) PTE LTD
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

#ifndef _dsps_d_gen_H_
#define _dsps_d_gen_H_
#include "dsp_err.h"


#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief   delta function 
 * 
 * The function generate delta function.
 * output[i]=0, if i=[0..N)
 * output[i]=1, if i=pos, pos: [0..N-1)
 * The implementation use ANSI C and could be compiled and run on any platform
 *
 * @param output: output array.
 * @param len: length of the input signal
 * @param pos: delta function position
 *
 * @return
 *      - ESP_OK on success
 *      - One of the error codes from DSP library
 */
esp_err_t dsps_d_gen_f32(float *output, int len, int pos);

#ifdef __cplusplus
}
#endif

#endif // _dsps_d_gen_H_