// Auto-generated file. Do not edit!
//   Template: src/qs8-gemm/scalar.c.in
//   Generator: tools/xngen
//
// Copyright 2021 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <xnnpack/math.h>
#include <xnnpack/scalar-utils.h>
#include <xnnpack/gemm.h>


void xnn_qs8_gemm_minmax_ukernel_4x2__scalar(
    size_t mr,
    size_t nc,
    size_t kc,
    const int8_t* restrict a,
    size_t a_stride,
    const void* restrict w,
    int8_t* restrict c,
    size_t cm_stride,
    size_t cn_stride,
    const union xnn_qs8_gemm_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(mr != 0);
  assert(mr <= 4);
  assert(nc != 0);
  assert(kc != 0);

  const int8_t* a0 = a;
  int8_t* c0 = c;
  const int8_t* a1 = (const int8_t*) ((uintptr_t) a0 + a_stride);
  int8_t* c1 = (int8_t*) ((uintptr_t) c0 + cm_stride);
  if XNN_UNPREDICTABLE(mr < 2) {
    a1 = a0;
    c1 = c0;
  }
  const int8_t* a2 = (const int8_t*) ((uintptr_t) a1 + a_stride);
  int8_t* c2 = (int8_t*) ((uintptr_t) c1 + cm_stride);
  if XNN_UNPREDICTABLE(mr <= 2) {
    a2 = a1;
    c2 = c1;
  }
  const int8_t* a3 = (const int8_t*) ((uintptr_t) a2 + a_stride);
  int8_t* c3 = (int8_t*) ((uintptr_t) c2 + cm_stride);
  if XNN_UNPREDICTABLE(mr != 4) {
    a3 = a2;
    c3 = c2;
  }

  do {
    int32_t vacc0x0 = ((const int32_t*) w)[0];
    int32_t vacc0x1 = ((const int32_t*) w)[1];
    int32_t vacc1x0 = vacc0x0;
    int32_t vacc1x1 = vacc0x1;
    int32_t vacc2x0 = vacc0x0;
    int32_t vacc2x1 = vacc0x1;
    int32_t vacc3x0 = vacc0x0;
    int32_t vacc3x1 = vacc0x1;
    w = (const void*) ((uintptr_t) w + 2 * sizeof(int32_t));

    size_t k = kc;
    do {
      const int32_t va0 = (int32_t) *a0++;
      const int32_t va1 = (int32_t) *a1++;
      const int32_t va2 = (int32_t) *a2++;
      const int32_t va3 = (int32_t) *a3++;

      const int32_t vb0 = ((const int8_t*) w)[0];
      const int32_t vb1 = ((const int8_t*) w)[1];
      w = (const void*) ((uintptr_t) w + 2 * sizeof(int8_t));

      vacc0x0 += va0 * vb0;
      vacc0x1 += va0 * vb1;
      vacc1x0 += va1 * vb0;
      vacc1x1 += va1 * vb1;
      vacc2x0 += va2 * vb0;
      vacc2x1 += va2 * vb1;
      vacc3x0 += va3 * vb0;
      vacc3x1 += va3 * vb1;

      k -= sizeof(int8_t);
    } while (k != 0);

    const int32_t vmultiplier = params->scalar.multiplier;
    const int64_t vproduct0x0 = (int64_t) vacc0x0 * (int64_t) vmultiplier;
    const int64_t vproduct0x1 = (int64_t) vacc0x1 * (int64_t) vmultiplier;
    const int64_t vproduct1x0 = (int64_t) vacc1x0 * (int64_t) vmultiplier;
    const int64_t vproduct1x1 = (int64_t) vacc1x1 * (int64_t) vmultiplier;
    const int64_t vproduct2x0 = (int64_t) vacc2x0 * (int64_t) vmultiplier;
    const int64_t vproduct2x1 = (int64_t) vacc2x1 * (int64_t) vmultiplier;
    const int64_t vproduct3x0 = (int64_t) vacc3x0 * (int64_t) vmultiplier;
    const int64_t vproduct3x1 = (int64_t) vacc3x1 * (int64_t) vmultiplier;

    const int64_t vq31rounding = INT64_C(0x40000000);
    const int32_t vq31product0x0 = (int32_t) (uint32_t) ((uint64_t) (vproduct0x0 + vq31rounding) >> 31);
    const int32_t vq31product0x1 = (int32_t) (uint32_t) ((uint64_t) (vproduct0x1 + vq31rounding) >> 31);
    const int32_t vq31product1x0 = (int32_t) (uint32_t) ((uint64_t) (vproduct1x0 + vq31rounding) >> 31);
    const int32_t vq31product1x1 = (int32_t) (uint32_t) ((uint64_t) (vproduct1x1 + vq31rounding) >> 31);
    const int32_t vq31product2x0 = (int32_t) (uint32_t) ((uint64_t) (vproduct2x0 + vq31rounding) >> 31);
    const int32_t vq31product2x1 = (int32_t) (uint32_t) ((uint64_t) (vproduct2x1 + vq31rounding) >> 31);
    const int32_t vq31product3x0 = (int32_t) (uint32_t) ((uint64_t) (vproduct3x0 + vq31rounding) >> 31);
    const int32_t vq31product3x1 = (int32_t) (uint32_t) ((uint64_t) (vproduct3x1 + vq31rounding) >> 31);

    const int32_t vremainder_mask = params->scalar.remainder_mask;
    const int32_t vremainder0x0 = (vq31product0x0 & vremainder_mask) - (int32_t) (vq31product0x0 < 0);
    const int32_t vremainder0x1 = (vq31product0x1 & vremainder_mask) - (int32_t) (vq31product0x1 < 0);
    const int32_t vremainder1x0 = (vq31product1x0 & vremainder_mask) - (int32_t) (vq31product1x0 < 0);
    const int32_t vremainder1x1 = (vq31product1x1 & vremainder_mask) - (int32_t) (vq31product1x1 < 0);
    const int32_t vremainder2x0 = (vq31product2x0 & vremainder_mask) - (int32_t) (vq31product2x0 < 0);
    const int32_t vremainder2x1 = (vq31product2x1 & vremainder_mask) - (int32_t) (vq31product2x1 < 0);
    const int32_t vremainder3x0 = (vq31product3x0 & vremainder_mask) - (int32_t) (vq31product3x0 < 0);
    const int32_t vremainder3x1 = (vq31product3x1 & vremainder_mask) - (int32_t) (vq31product3x1 < 0);

    const uint32_t vshift = params->scalar.shift;
    const int32_t vremainder_threshold = params->scalar.remainder_threshold;
    int32_t vout0x0 = asr_s32(vq31product0x0, vshift) + (int32_t) (vremainder0x0 > vremainder_threshold);
    int32_t vout0x1 = asr_s32(vq31product0x1, vshift) + (int32_t) (vremainder0x1 > vremainder_threshold);
    int32_t vout1x0 = asr_s32(vq31product1x0, vshift) + (int32_t) (vremainder1x0 > vremainder_threshold);
    int32_t vout1x1 = asr_s32(vq31product1x1, vshift) + (int32_t) (vremainder1x1 > vremainder_threshold);
    int32_t vout2x0 = asr_s32(vq31product2x0, vshift) + (int32_t) (vremainder2x0 > vremainder_threshold);
    int32_t vout2x1 = asr_s32(vq31product2x1, vshift) + (int32_t) (vremainder2x1 > vremainder_threshold);
    int32_t vout3x0 = asr_s32(vq31product3x0, vshift) + (int32_t) (vremainder3x0 > vremainder_threshold);
    int32_t vout3x1 = asr_s32(vq31product3x1, vshift) + (int32_t) (vremainder3x1 > vremainder_threshold);

    const int32_t vout_min = params->scalar.output_min_less_zero_point;
    vout0x0 = math_max_s32(vout0x0, vout_min);
    vout0x1 = math_max_s32(vout0x1, vout_min);
    vout1x0 = math_max_s32(vout1x0, vout_min);
    vout1x1 = math_max_s32(vout1x1, vout_min);
    vout2x0 = math_max_s32(vout2x0, vout_min);
    vout2x1 = math_max_s32(vout2x1, vout_min);
    vout3x0 = math_max_s32(vout3x0, vout_min);
    vout3x1 = math_max_s32(vout3x1, vout_min);

    const int32_t vout_max = params->scalar.output_max_less_zero_point;
    vout0x0 = math_min_s32(vout0x0, vout_max);
    vout0x1 = math_min_s32(vout0x1, vout_max);
    vout1x0 = math_min_s32(vout1x0, vout_max);
    vout1x1 = math_min_s32(vout1x1, vout_max);
    vout2x0 = math_min_s32(vout2x0, vout_max);
    vout2x1 = math_min_s32(vout2x1, vout_max);
    vout3x0 = math_min_s32(vout3x0, vout_max);
    vout3x1 = math_min_s32(vout3x1, vout_max);

    const int32_t voutput_zero_point = params->scalar.output_zero_point;
    vout0x0 += voutput_zero_point;
    vout0x1 += voutput_zero_point;
    vout1x0 += voutput_zero_point;
    vout1x1 += voutput_zero_point;
    vout2x0 += voutput_zero_point;
    vout2x1 += voutput_zero_point;
    vout3x0 += voutput_zero_point;
    vout3x1 += voutput_zero_point;

    if XNN_LIKELY(nc >= 2) {
      c0[0] = (int8_t) vout0x0;
      c0[1] = (int8_t) vout0x1;
      c1[0] = (int8_t) vout1x0;
      c1[1] = (int8_t) vout1x1;
      c2[0] = (int8_t) vout2x0;
      c2[1] = (int8_t) vout2x1;
      c3[0] = (int8_t) vout3x0;
      c3[1] = (int8_t) vout3x1;

      a0 = (const int8_t*) ((uintptr_t) a0 - kc);
      a1 = (const int8_t*) ((uintptr_t) a1 - kc);
      a2 = (const int8_t*) ((uintptr_t) a2 - kc);
      a3 = (const int8_t*) ((uintptr_t) a3 - kc);

      c0 = (int8_t*) ((uintptr_t) c0 + cn_stride);
      c1 = (int8_t*) ((uintptr_t) c1 + cn_stride);
      c2 = (int8_t*) ((uintptr_t) c2 + cn_stride);
      c3 = (int8_t*) ((uintptr_t) c3 + cn_stride);

      nc -= 2;
    } else {
      if (nc & 1) {
        c0[0] = (int8_t) vout0x0;
        c1[0] = (int8_t) vout1x0;
        c2[0] = (int8_t) vout2x0;
        c3[0] = (int8_t) vout3x0;
      }

      nc = 0;
    }
  } while (nc != 0);
}
