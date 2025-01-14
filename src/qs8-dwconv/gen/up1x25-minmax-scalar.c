// Auto-generated file. Do not edit!
//   Template: src/qs8-dwconv/unipass-scalar.c.in
//   Generator: tools/xngen
//
// Copyright 2021 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <xnnpack/dwconv.h>
#include <xnnpack/math.h>
#include <xnnpack/scalar-utils.h>


void xnn_qs8_dwconv_minmax_ukernel_up1x25__scalar(
    size_t channels,
    size_t output_width,
    const int8_t** input,
    const void* weights,
    int8_t* output,
    size_t input_stride,
    size_t output_increment,
    size_t input_offset,
    const int8_t* zero,
    const union xnn_qs8_gemm_params params[restrict XNN_MIN_ELEMENTS(1)]) XNN_DISABLE_TSAN
{
  assert(channels != 0);
  assert(output_width != 0);

  const int32_t vmultiplier = params->scalar.multiplier;
  const int64_t vq31rounding = INT64_C(0x40000000);
  const int32_t vremainder_mask = params->scalar.remainder_mask;
  const uint32_t vshift = params->scalar.shift;
  const int32_t vremainder_threshold = params->scalar.remainder_threshold;
  const int32_t vout_min = params->scalar.output_min_less_zero_point;
  const int32_t vout_max = params->scalar.output_max_less_zero_point;
  const int32_t voutput_zero_point = params->scalar.output_zero_point;
  do {
    const int8_t* i0 = input[0];
    assert(i0 != NULL);
    if XNN_UNPREDICTABLE(i0 != zero) {
      i0 = (const int8_t*) ((uintptr_t) i0 + input_offset);
    }
    const int8_t* i1 = input[1];
    assert(i1 != NULL);
    if XNN_UNPREDICTABLE(i1 != zero) {
      i1 = (const int8_t*) ((uintptr_t) i1 + input_offset);
    }
    const int8_t* i2 = input[2];
    assert(i2 != NULL);
    if XNN_UNPREDICTABLE(i2 != zero) {
      i2 = (const int8_t*) ((uintptr_t) i2 + input_offset);
    }
    const int8_t* i3 = input[3];
    assert(i3 != NULL);
    if XNN_UNPREDICTABLE(i3 != zero) {
      i3 = (const int8_t*) ((uintptr_t) i3 + input_offset);
    }
    const int8_t* i4 = input[4];
    assert(i4 != NULL);
    if XNN_UNPREDICTABLE(i4 != zero) {
      i4 = (const int8_t*) ((uintptr_t) i4 + input_offset);
    }
    const int8_t* i5 = input[5];
    assert(i5 != NULL);
    if XNN_UNPREDICTABLE(i5 != zero) {
      i5 = (const int8_t*) ((uintptr_t) i5 + input_offset);
    }
    const int8_t* i6 = input[6];
    assert(i6 != NULL);
    if XNN_UNPREDICTABLE(i6 != zero) {
      i6 = (const int8_t*) ((uintptr_t) i6 + input_offset);
    }
    const int8_t* i7 = input[7];
    assert(i7 != NULL);
    if XNN_UNPREDICTABLE(i7 != zero) {
      i7 = (const int8_t*) ((uintptr_t) i7 + input_offset);
    }
    const int8_t* i8 = input[8];
    assert(i8 != NULL);
    if XNN_UNPREDICTABLE(i8 != zero) {
      i8 = (const int8_t*) ((uintptr_t) i8 + input_offset);
    }
    const int8_t* i9 = input[9];
    assert(i9 != NULL);
    if XNN_UNPREDICTABLE(i9 != zero) {
      i9 = (const int8_t*) ((uintptr_t) i9 + input_offset);
    }
    const int8_t* i10 = input[10];
    assert(i10 != NULL);
    if XNN_UNPREDICTABLE(i10 != zero) {
      i10 = (const int8_t*) ((uintptr_t) i10 + input_offset);
    }
    const int8_t* i11 = input[11];
    assert(i11 != NULL);
    if XNN_UNPREDICTABLE(i11 != zero) {
      i11 = (const int8_t*) ((uintptr_t) i11 + input_offset);
    }
    const int8_t* i12 = input[12];
    assert(i12 != NULL);
    if XNN_UNPREDICTABLE(i12 != zero) {
      i12 = (const int8_t*) ((uintptr_t) i12 + input_offset);
    }
    const int8_t* i13 = input[13];
    assert(i13 != NULL);
    if XNN_UNPREDICTABLE(i13 != zero) {
      i13 = (const int8_t*) ((uintptr_t) i13 + input_offset);
    }
    const int8_t* i14 = input[14];
    assert(i14 != NULL);
    if XNN_UNPREDICTABLE(i14 != zero) {
      i14 = (const int8_t*) ((uintptr_t) i14 + input_offset);
    }
    const int8_t* i15 = input[15];
    assert(i15 != NULL);
    if XNN_UNPREDICTABLE(i15 != zero) {
      i15 = (const int8_t*) ((uintptr_t) i15 + input_offset);
    }
    const int8_t* i16 = input[16];
    assert(i16 != NULL);
    if XNN_UNPREDICTABLE(i16 != zero) {
      i16 = (const int8_t*) ((uintptr_t) i16 + input_offset);
    }
    const int8_t* i17 = input[17];
    assert(i17 != NULL);
    if XNN_UNPREDICTABLE(i17 != zero) {
      i17 = (const int8_t*) ((uintptr_t) i17 + input_offset);
    }
    const int8_t* i18 = input[18];
    assert(i18 != NULL);
    if XNN_UNPREDICTABLE(i18 != zero) {
      i18 = (const int8_t*) ((uintptr_t) i18 + input_offset);
    }
    const int8_t* i19 = input[19];
    assert(i19 != NULL);
    if XNN_UNPREDICTABLE(i19 != zero) {
      i19 = (const int8_t*) ((uintptr_t) i19 + input_offset);
    }
    const int8_t* i20 = input[20];
    assert(i20 != NULL);
    if XNN_UNPREDICTABLE(i20 != zero) {
      i20 = (const int8_t*) ((uintptr_t) i20 + input_offset);
    }
    const int8_t* i21 = input[21];
    assert(i21 != NULL);
    if XNN_UNPREDICTABLE(i21 != zero) {
      i21 = (const int8_t*) ((uintptr_t) i21 + input_offset);
    }
    const int8_t* i22 = input[22];
    assert(i22 != NULL);
    if XNN_UNPREDICTABLE(i22 != zero) {
      i22 = (const int8_t*) ((uintptr_t) i22 + input_offset);
    }
    const int8_t* i23 = input[23];
    assert(i23 != NULL);
    if XNN_UNPREDICTABLE(i23 != zero) {
      i23 = (const int8_t*) ((uintptr_t) i23 + input_offset);
    }
    const int8_t* i24 = input[24];
    assert(i24 != NULL);
    if XNN_UNPREDICTABLE(i24 != zero) {
      i24 = (const int8_t*) ((uintptr_t) i24 + input_offset);
    }
    input = (const int8_t**) ((uintptr_t) input + input_stride);

    size_t c = channels;
    const void* w = weights;
    do {
      int32_t vacc = *((const int32_t*) w);

      const int32_t vi0 = *i0++;
      const int32_t vk0 = ((const int8_t*) ((uintptr_t) w + sizeof(int32_t)))[0];
      vacc += vi0 * vk0;
      const int32_t vi1 = *i1++;
      const int32_t vk1 = ((const int8_t*) ((uintptr_t) w + sizeof(int32_t)))[1];
      vacc += vi1 * vk1;
      const int32_t vi2 = *i2++;
      const int32_t vk2 = ((const int8_t*) ((uintptr_t) w + sizeof(int32_t)))[2];
      vacc += vi2 * vk2;
      const int32_t vi3 = *i3++;
      const int32_t vk3 = ((const int8_t*) ((uintptr_t) w + sizeof(int32_t)))[3];
      vacc += vi3 * vk3;
      const int32_t vi4 = *i4++;
      const int32_t vk4 = ((const int8_t*) ((uintptr_t) w + sizeof(int32_t)))[4];
      vacc += vi4 * vk4;
      const int32_t vi5 = *i5++;
      const int32_t vk5 = ((const int8_t*) ((uintptr_t) w + sizeof(int32_t)))[5];
      vacc += vi5 * vk5;
      const int32_t vi6 = *i6++;
      const int32_t vk6 = ((const int8_t*) ((uintptr_t) w + sizeof(int32_t)))[6];
      vacc += vi6 * vk6;
      const int32_t vi7 = *i7++;
      const int32_t vk7 = ((const int8_t*) ((uintptr_t) w + sizeof(int32_t)))[7];
      vacc += vi7 * vk7;
      const int32_t vi8 = *i8++;
      const int32_t vk8 = ((const int8_t*) ((uintptr_t) w + sizeof(int32_t)))[8];
      vacc += vi8 * vk8;
      const int32_t vi9 = *i9++;
      const int32_t vk9 = ((const int8_t*) ((uintptr_t) w + sizeof(int32_t)))[9];
      vacc += vi9 * vk9;
      const int32_t vi10 = *i10++;
      const int32_t vk10 = ((const int8_t*) ((uintptr_t) w + sizeof(int32_t)))[10];
      vacc += vi10 * vk10;
      const int32_t vi11 = *i11++;
      const int32_t vk11 = ((const int8_t*) ((uintptr_t) w + sizeof(int32_t)))[11];
      vacc += vi11 * vk11;
      const int32_t vi12 = *i12++;
      const int32_t vk12 = ((const int8_t*) ((uintptr_t) w + sizeof(int32_t)))[12];
      vacc += vi12 * vk12;
      const int32_t vi13 = *i13++;
      const int32_t vk13 = ((const int8_t*) ((uintptr_t) w + sizeof(int32_t)))[13];
      vacc += vi13 * vk13;
      const int32_t vi14 = *i14++;
      const int32_t vk14 = ((const int8_t*) ((uintptr_t) w + sizeof(int32_t)))[14];
      vacc += vi14 * vk14;
      const int32_t vi15 = *i15++;
      const int32_t vk15 = ((const int8_t*) ((uintptr_t) w + sizeof(int32_t)))[15];
      vacc += vi15 * vk15;
      const int32_t vi16 = *i16++;
      const int32_t vk16 = ((const int8_t*) ((uintptr_t) w + sizeof(int32_t)))[16];
      vacc += vi16 * vk16;
      const int32_t vi17 = *i17++;
      const int32_t vk17 = ((const int8_t*) ((uintptr_t) w + sizeof(int32_t)))[17];
      vacc += vi17 * vk17;
      const int32_t vi18 = *i18++;
      const int32_t vk18 = ((const int8_t*) ((uintptr_t) w + sizeof(int32_t)))[18];
      vacc += vi18 * vk18;
      const int32_t vi19 = *i19++;
      const int32_t vk19 = ((const int8_t*) ((uintptr_t) w + sizeof(int32_t)))[19];
      vacc += vi19 * vk19;
      const int32_t vi20 = *i20++;
      const int32_t vk20 = ((const int8_t*) ((uintptr_t) w + sizeof(int32_t)))[20];
      vacc += vi20 * vk20;
      const int32_t vi21 = *i21++;
      const int32_t vk21 = ((const int8_t*) ((uintptr_t) w + sizeof(int32_t)))[21];
      vacc += vi21 * vk21;
      const int32_t vi22 = *i22++;
      const int32_t vk22 = ((const int8_t*) ((uintptr_t) w + sizeof(int32_t)))[22];
      vacc += vi22 * vk22;
      const int32_t vi23 = *i23++;
      const int32_t vk23 = ((const int8_t*) ((uintptr_t) w + sizeof(int32_t)))[23];
      vacc += vi23 * vk23;
      const int32_t vi24 = *i24++;
      const int32_t vk24 = ((const int8_t*) ((uintptr_t) w + sizeof(int32_t)))[24];
      vacc += vi24 * vk24;

      w = (const void*) ((uintptr_t) w + sizeof(int32_t) + 25 * sizeof(int8_t));

      const int64_t vproduct = (int64_t) vacc * (int64_t) vmultiplier;
      const int32_t vq31product = (int32_t) (uint32_t) ((uint64_t) (vproduct + vq31rounding) >> 31);
      const int32_t vremainder = (vq31product & vremainder_mask) - (int32_t) (vq31product < 0);

      int32_t vout = asr_s32(vq31product, vshift) + (int32_t) (vremainder > vremainder_threshold);
      vout = math_max_s32(vout, vout_min);
      vout = math_min_s32(vout, vout_max);
      vout += voutput_zero_point;
      *output++ = (int8_t) vout;
    } while (--c != 0);

    output = (int8_t*) ((uintptr_t) output + output_increment);
  } while (--output_width != 0);
}
