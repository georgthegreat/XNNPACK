// Auto-generated file. Do not edit!
//   Template: src/qs8-igemm/MRx4c2-sse.c.in
//   Generator: tools/xngen
//
// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <emmintrin.h>

#include <xnnpack/igemm.h>
#include <xnnpack/math.h>


void xnn_qs8_igemm_minmax_ukernel_4x4c2__sse2_ld64(
    size_t mr,
    size_t nc,
    size_t kc,
    size_t ks,
    const int8_t** restrict a,
    const void* restrict w,
    int8_t* restrict c,
    size_t cm_stride,
    size_t cn_stride,
    size_t a_offset,
    const int8_t* zero,
    const union xnn_qs8_gemm_params params[restrict XNN_MIN_ELEMENTS(1)]) XNN_DISABLE_TSAN XNN_DISABLE_MSAN
{
  assert(mr != 0);
  assert(mr <= 4);
  assert(nc != 0);
  assert(kc != 0);
  assert(ks != 0);
  assert(ks % (4 * sizeof(void*)) == 0);
  assert(a_offset % sizeof(int8_t) == 0);
  assert(a != NULL);
  assert(w != NULL);
  assert(c != NULL);

  kc = round_up_po2(kc, 2);
  int8_t* c0 = c;
  int8_t* c1 = (int8_t*) ((uintptr_t) c0 + cm_stride);
  if XNN_UNPREDICTABLE(mr < 2) {
    c1 = c0;
  }
  int8_t* c2 = (int8_t*) ((uintptr_t) c1 + cm_stride);
  if XNN_UNPREDICTABLE(mr <= 2) {
    c2 = c1;
  }
  int8_t* c3 = (int8_t*) ((uintptr_t) c2 + cm_stride);
  if XNN_UNPREDICTABLE(mr != 4) {
    c3 = c2;
  }

  do {
    __m128i vacc0x0123 = _mm_loadu_si128((const __m128i*) w);
    __m128i vacc1x0123 = vacc0x0123;
    __m128i vacc2x0123 = vacc0x0123;
    __m128i vacc3x0123 = vacc0x0123;
    w = (const void*) ((uintptr_t) w + 4 * sizeof(int32_t));

    size_t p = ks;
    do {
      const int8_t* restrict a0 = a[0];
      if XNN_UNPREDICTABLE(a0 != zero) {
        a0 = (const int8_t*) ((uintptr_t) a0 + a_offset);
      }
      const int8_t* restrict a1 = a[1];
      if XNN_UNPREDICTABLE(a1 != zero) {
        a1 = (const int8_t*) ((uintptr_t) a1 + a_offset);
      }
      const int8_t* restrict a2 = a[2];
      if XNN_UNPREDICTABLE(a2 != zero) {
        a2 = (const int8_t*) ((uintptr_t) a2 + a_offset);
      }
      const int8_t* restrict a3 = a[3];
      if XNN_UNPREDICTABLE(a3 != zero) {
        a3 = (const int8_t*) ((uintptr_t) a3 + a_offset);
      }
      a += 4;

      size_t k = kc;
      while (k >= 8 * sizeof(int8_t)) {
        const __m128i va0 = _mm_loadl_epi64((const __m128i*) a0);
        const __m128i vxa0 = _mm_unpacklo_epi8(va0, _mm_cmpgt_epi8(_mm_setzero_si128(), va0));
        a0 += 8;
        const __m128i va1 = _mm_loadl_epi64((const __m128i*) a1);
        const __m128i vxa1 = _mm_unpacklo_epi8(va1, _mm_cmpgt_epi8(_mm_setzero_si128(), va1));
        a1 += 8;
        const __m128i va2 = _mm_loadl_epi64((const __m128i*) a2);
        const __m128i vxa2 = _mm_unpacklo_epi8(va2, _mm_cmpgt_epi8(_mm_setzero_si128(), va2));
        a2 += 8;
        const __m128i va3 = _mm_loadl_epi64((const __m128i*) a3);
        const __m128i vxa3 = _mm_unpacklo_epi8(va3, _mm_cmpgt_epi8(_mm_setzero_si128(), va3));
        a3 += 8;

        const __m128i vb0 = _mm_loadl_epi64((const __m128i*) w);
        const __m128i vxb0 = _mm_unpacklo_epi8(vb0, _mm_cmpgt_epi8(_mm_setzero_si128(), vb0));

        vacc0x0123 = _mm_add_epi32(vacc0x0123,
          _mm_madd_epi16(_mm_shuffle_epi32(vxa0, _MM_SHUFFLE(0, 0, 0, 0)), vxb0));
        vacc1x0123 = _mm_add_epi32(vacc1x0123,
          _mm_madd_epi16(_mm_shuffle_epi32(vxa1, _MM_SHUFFLE(0, 0, 0, 0)), vxb0));
        vacc2x0123 = _mm_add_epi32(vacc2x0123,
          _mm_madd_epi16(_mm_shuffle_epi32(vxa2, _MM_SHUFFLE(0, 0, 0, 0)), vxb0));
        vacc3x0123 = _mm_add_epi32(vacc3x0123,
          _mm_madd_epi16(_mm_shuffle_epi32(vxa3, _MM_SHUFFLE(0, 0, 0, 0)), vxb0));
        const __m128i vb1 = _mm_loadl_epi64((const __m128i*) ((uintptr_t) w + 8));
        const __m128i vxb1 = _mm_unpacklo_epi8(vb1, _mm_cmpgt_epi8(_mm_setzero_si128(), vb1));

        vacc0x0123 = _mm_add_epi32(vacc0x0123,
          _mm_madd_epi16(_mm_shuffle_epi32(vxa0, _MM_SHUFFLE(1, 1, 1, 1)), vxb1));
        vacc1x0123 = _mm_add_epi32(vacc1x0123,
          _mm_madd_epi16(_mm_shuffle_epi32(vxa1, _MM_SHUFFLE(1, 1, 1, 1)), vxb1));
        vacc2x0123 = _mm_add_epi32(vacc2x0123,
          _mm_madd_epi16(_mm_shuffle_epi32(vxa2, _MM_SHUFFLE(1, 1, 1, 1)), vxb1));
        vacc3x0123 = _mm_add_epi32(vacc3x0123,
          _mm_madd_epi16(_mm_shuffle_epi32(vxa3, _MM_SHUFFLE(1, 1, 1, 1)), vxb1));
        const __m128i vb2 = _mm_loadl_epi64((const __m128i*) ((uintptr_t) w + 16));
        const __m128i vxb2 = _mm_unpacklo_epi8(vb2, _mm_cmpgt_epi8(_mm_setzero_si128(), vb2));

        vacc0x0123 = _mm_add_epi32(vacc0x0123,
          _mm_madd_epi16(_mm_shuffle_epi32(vxa0, _MM_SHUFFLE(2, 2, 2, 2)), vxb2));
        vacc1x0123 = _mm_add_epi32(vacc1x0123,
          _mm_madd_epi16(_mm_shuffle_epi32(vxa1, _MM_SHUFFLE(2, 2, 2, 2)), vxb2));
        vacc2x0123 = _mm_add_epi32(vacc2x0123,
          _mm_madd_epi16(_mm_shuffle_epi32(vxa2, _MM_SHUFFLE(2, 2, 2, 2)), vxb2));
        vacc3x0123 = _mm_add_epi32(vacc3x0123,
          _mm_madd_epi16(_mm_shuffle_epi32(vxa3, _MM_SHUFFLE(2, 2, 2, 2)), vxb2));
        const __m128i vb3 = _mm_loadl_epi64((const __m128i*) ((uintptr_t) w + 24));
        const __m128i vxb3 = _mm_unpacklo_epi8(vb3, _mm_cmpgt_epi8(_mm_setzero_si128(), vb3));

        vacc0x0123 = _mm_add_epi32(vacc0x0123,
          _mm_madd_epi16(_mm_shuffle_epi32(vxa0, _MM_SHUFFLE(3, 3, 3, 3)), vxb3));
        vacc1x0123 = _mm_add_epi32(vacc1x0123,
          _mm_madd_epi16(_mm_shuffle_epi32(vxa1, _MM_SHUFFLE(3, 3, 3, 3)), vxb3));
        vacc2x0123 = _mm_add_epi32(vacc2x0123,
          _mm_madd_epi16(_mm_shuffle_epi32(vxa2, _MM_SHUFFLE(3, 3, 3, 3)), vxb3));
        vacc3x0123 = _mm_add_epi32(vacc3x0123,
          _mm_madd_epi16(_mm_shuffle_epi32(vxa3, _MM_SHUFFLE(3, 3, 3, 3)), vxb3));

        w = (const void*) ((uintptr_t) w + 32);
        k -= 8 * sizeof(int8_t);
      }
      if (k != 0) {
        const __m128i va0 = _mm_loadl_epi64((const __m128i*) a0);
        const __m128i vxa0 = _mm_unpacklo_epi8(va0, _mm_cmpgt_epi8(_mm_setzero_si128(), va0));
        a0 = (const int8_t*) ((uintptr_t) a0 + k);
        const __m128i va1 = _mm_loadl_epi64((const __m128i*) a1);
        const __m128i vxa1 = _mm_unpacklo_epi8(va1, _mm_cmpgt_epi8(_mm_setzero_si128(), va1));
        a1 = (const int8_t*) ((uintptr_t) a1 + k);
        const __m128i va2 = _mm_loadl_epi64((const __m128i*) a2);
        const __m128i vxa2 = _mm_unpacklo_epi8(va2, _mm_cmpgt_epi8(_mm_setzero_si128(), va2));
        a2 = (const int8_t*) ((uintptr_t) a2 + k);
        const __m128i va3 = _mm_loadl_epi64((const __m128i*) a3);
        const __m128i vxa3 = _mm_unpacklo_epi8(va3, _mm_cmpgt_epi8(_mm_setzero_si128(), va3));
        a3 = (const int8_t*) ((uintptr_t) a3 + k);

        const __m128i vb0 = _mm_loadl_epi64((const __m128i*) w);
        w = (const void*) ((uintptr_t) w + 8);
        const __m128i vxb0 = _mm_unpacklo_epi8(vb0, _mm_cmpgt_epi8(_mm_setzero_si128(), vb0));

        vacc0x0123 = _mm_add_epi32(vacc0x0123,
          _mm_madd_epi16(_mm_shuffle_epi32(vxa0, _MM_SHUFFLE(0, 0, 0, 0)), vxb0));
        vacc1x0123 = _mm_add_epi32(vacc1x0123,
          _mm_madd_epi16(_mm_shuffle_epi32(vxa1, _MM_SHUFFLE(0, 0, 0, 0)), vxb0));
        vacc2x0123 = _mm_add_epi32(vacc2x0123,
          _mm_madd_epi16(_mm_shuffle_epi32(vxa2, _MM_SHUFFLE(0, 0, 0, 0)), vxb0));
        vacc3x0123 = _mm_add_epi32(vacc3x0123,
          _mm_madd_epi16(_mm_shuffle_epi32(vxa3, _MM_SHUFFLE(0, 0, 0, 0)), vxb0));

        if (k > 2 * sizeof(int8_t)) {
          const __m128i vb1 = _mm_loadl_epi64((const __m128i*) w);
          w = (const void*) ((uintptr_t) w + 8);
          const __m128i vxb1 = _mm_unpacklo_epi8(vb1, _mm_cmpgt_epi8(_mm_setzero_si128(), vb1));

          vacc0x0123 = _mm_add_epi32(vacc0x0123,
            _mm_madd_epi16(_mm_shuffle_epi32(vxa0, _MM_SHUFFLE(1, 1, 1, 1)), vxb1));
          vacc1x0123 = _mm_add_epi32(vacc1x0123,
            _mm_madd_epi16(_mm_shuffle_epi32(vxa1, _MM_SHUFFLE(1, 1, 1, 1)), vxb1));
          vacc2x0123 = _mm_add_epi32(vacc2x0123,
            _mm_madd_epi16(_mm_shuffle_epi32(vxa2, _MM_SHUFFLE(1, 1, 1, 1)), vxb1));
          vacc3x0123 = _mm_add_epi32(vacc3x0123,
            _mm_madd_epi16(_mm_shuffle_epi32(vxa3, _MM_SHUFFLE(1, 1, 1, 1)), vxb1));

          if (k > 4 * sizeof(int8_t)) {
            const __m128i vb2 = _mm_loadl_epi64((const __m128i*) w);
            w = (const void*) ((uintptr_t) w + 8);
            const __m128i vxb2 = _mm_unpacklo_epi8(vb2, _mm_cmpgt_epi8(_mm_setzero_si128(), vb2));

            vacc0x0123 = _mm_add_epi32(vacc0x0123,
              _mm_madd_epi16(_mm_shuffle_epi32(vxa0, _MM_SHUFFLE(2, 2, 2, 2)), vxb2));
            vacc1x0123 = _mm_add_epi32(vacc1x0123,
              _mm_madd_epi16(_mm_shuffle_epi32(vxa1, _MM_SHUFFLE(2, 2, 2, 2)), vxb2));
            vacc2x0123 = _mm_add_epi32(vacc2x0123,
              _mm_madd_epi16(_mm_shuffle_epi32(vxa2, _MM_SHUFFLE(2, 2, 2, 2)), vxb2));
            vacc3x0123 = _mm_add_epi32(vacc3x0123,
              _mm_madd_epi16(_mm_shuffle_epi32(vxa3, _MM_SHUFFLE(2, 2, 2, 2)), vxb2));
          }
        }
      }
      p -= 4 * sizeof(void*);
    } while (p != 0);

    const __m128i vmultiplier = _mm_load_si128((const __m128i*) params->sse2.multiplier);
    const __m128i vrounding = _mm_load_si128((const __m128i*) params->sse2.rounding);

    const __m128i vnmask0x0123 = _mm_cmpgt_epi32(_mm_setzero_si128(), vacc0x0123);
    const __m128i vnmask1x0123 = _mm_cmpgt_epi32(_mm_setzero_si128(), vacc1x0123);
    const __m128i vnmask2x0123 = _mm_cmpgt_epi32(_mm_setzero_si128(), vacc2x0123);
    const __m128i vnmask3x0123 = _mm_cmpgt_epi32(_mm_setzero_si128(), vacc3x0123);

    const __m128i vabsacc0x0123 = _mm_sub_epi32(_mm_xor_si128(vacc0x0123, vnmask0x0123), vnmask0x0123);
    const __m128i vabsacc1x0123 = _mm_sub_epi32(_mm_xor_si128(vacc1x0123, vnmask1x0123), vnmask1x0123);
    const __m128i vabsacc2x0123 = _mm_sub_epi32(_mm_xor_si128(vacc2x0123, vnmask2x0123), vnmask2x0123);
    const __m128i vabsacc3x0123 = _mm_sub_epi32(_mm_xor_si128(vacc3x0123, vnmask3x0123), vnmask3x0123);

    const __m128i vabsacc0x1133 = _mm_shuffle_epi32(vabsacc0x0123, _MM_SHUFFLE(3, 3, 1, 1));
    const __m128i vabsacc1x1133 = _mm_shuffle_epi32(vabsacc1x0123, _MM_SHUFFLE(3, 3, 1, 1));
    const __m128i vabsacc2x1133 = _mm_shuffle_epi32(vabsacc2x0123, _MM_SHUFFLE(3, 3, 1, 1));
    const __m128i vabsacc3x1133 = _mm_shuffle_epi32(vabsacc3x0123, _MM_SHUFFLE(3, 3, 1, 1));

    const __m128i vabsprod0x02 = _mm_mul_epu32(vabsacc0x0123, vmultiplier);
    const __m128i vabsprod1x02 = _mm_mul_epu32(vabsacc1x0123, vmultiplier);
    const __m128i vabsprod2x02 = _mm_mul_epu32(vabsacc2x0123, vmultiplier);
    const __m128i vabsprod3x02 = _mm_mul_epu32(vabsacc3x0123, vmultiplier);

    const __m128i vnmask0x02 = _mm_shuffle_epi32(vnmask0x0123, _MM_SHUFFLE(2, 2, 0, 0));
    const __m128i vnmask1x02 = _mm_shuffle_epi32(vnmask1x0123, _MM_SHUFFLE(2, 2, 0, 0));
    const __m128i vnmask2x02 = _mm_shuffle_epi32(vnmask2x0123, _MM_SHUFFLE(2, 2, 0, 0));
    const __m128i vnmask3x02 = _mm_shuffle_epi32(vnmask3x0123, _MM_SHUFFLE(2, 2, 0, 0));

    const __m128i vprod0x02 = _mm_sub_epi64(_mm_xor_si128(vabsprod0x02, vnmask0x02), vnmask0x02);
    const __m128i vprod1x02 = _mm_sub_epi64(_mm_xor_si128(vabsprod1x02, vnmask1x02), vnmask1x02);
    const __m128i vprod2x02 = _mm_sub_epi64(_mm_xor_si128(vabsprod2x02, vnmask2x02), vnmask2x02);
    const __m128i vprod3x02 = _mm_sub_epi64(_mm_xor_si128(vabsprod3x02, vnmask3x02), vnmask3x02);

    const __m128i vq31prod0x02 = _mm_srli_epi64(_mm_add_epi64(vprod0x02, vrounding), 31);
    const __m128i vq31prod1x02 = _mm_srli_epi64(_mm_add_epi64(vprod1x02, vrounding), 31);
    const __m128i vq31prod2x02 = _mm_srli_epi64(_mm_add_epi64(vprod2x02, vrounding), 31);
    const __m128i vq31prod3x02 = _mm_srli_epi64(_mm_add_epi64(vprod3x02, vrounding), 31);

    const __m128i vabsprod0x13 = _mm_mul_epu32(vabsacc0x1133, vmultiplier);
    const __m128i vabsprod1x13 = _mm_mul_epu32(vabsacc1x1133, vmultiplier);
    const __m128i vabsprod2x13 = _mm_mul_epu32(vabsacc2x1133, vmultiplier);
    const __m128i vabsprod3x13 = _mm_mul_epu32(vabsacc3x1133, vmultiplier);

    const __m128i vnmask0x13 = _mm_shuffle_epi32(vnmask0x0123, _MM_SHUFFLE(3, 3, 1, 1));
    const __m128i vnmask1x13 = _mm_shuffle_epi32(vnmask1x0123, _MM_SHUFFLE(3, 3, 1, 1));
    const __m128i vnmask2x13 = _mm_shuffle_epi32(vnmask2x0123, _MM_SHUFFLE(3, 3, 1, 1));
    const __m128i vnmask3x13 = _mm_shuffle_epi32(vnmask3x0123, _MM_SHUFFLE(3, 3, 1, 1));

    const __m128i vprod0x13 = _mm_sub_epi64(_mm_xor_si128(vabsprod0x13, vnmask0x13), vnmask0x13);
    const __m128i vprod1x13 = _mm_sub_epi64(_mm_xor_si128(vabsprod1x13, vnmask1x13), vnmask1x13);
    const __m128i vprod2x13 = _mm_sub_epi64(_mm_xor_si128(vabsprod2x13, vnmask2x13), vnmask2x13);
    const __m128i vprod3x13 = _mm_sub_epi64(_mm_xor_si128(vabsprod3x13, vnmask3x13), vnmask3x13);

    const __m128i vq31prod0x13 = _mm_srli_epi64(_mm_add_epi64(vprod0x13, vrounding), 31);
    const __m128i vq31prod1x13 = _mm_srli_epi64(_mm_add_epi64(vprod1x13, vrounding), 31);
    const __m128i vq31prod2x13 = _mm_srli_epi64(_mm_add_epi64(vprod2x13, vrounding), 31);
    const __m128i vq31prod3x13 = _mm_srli_epi64(_mm_add_epi64(vprod3x13, vrounding), 31);

    const __m128i vq31prod0x0213 = _mm_castps_si128(_mm_shuffle_ps(
        _mm_castsi128_ps(vq31prod0x02), _mm_castsi128_ps(vq31prod0x13), _MM_SHUFFLE(2, 0, 2, 0)));
    const __m128i vq31prod1x0213 = _mm_castps_si128(_mm_shuffle_ps(
        _mm_castsi128_ps(vq31prod1x02), _mm_castsi128_ps(vq31prod1x13), _MM_SHUFFLE(2, 0, 2, 0)));
    const __m128i vq31prod2x0213 = _mm_castps_si128(_mm_shuffle_ps(
        _mm_castsi128_ps(vq31prod2x02), _mm_castsi128_ps(vq31prod2x13), _MM_SHUFFLE(2, 0, 2, 0)));
    const __m128i vq31prod3x0213 = _mm_castps_si128(_mm_shuffle_ps(
        _mm_castsi128_ps(vq31prod3x02), _mm_castsi128_ps(vq31prod3x13), _MM_SHUFFLE(2, 0, 2, 0)));

    const __m128i vq31prod0x0123 = _mm_shuffle_epi32(vq31prod0x0213, _MM_SHUFFLE(3, 1, 2, 0));
    const __m128i vq31prod1x0123 = _mm_shuffle_epi32(vq31prod1x0213, _MM_SHUFFLE(3, 1, 2, 0));
    const __m128i vq31prod2x0123 = _mm_shuffle_epi32(vq31prod2x0213, _MM_SHUFFLE(3, 1, 2, 0));
    const __m128i vq31prod3x0123 = _mm_shuffle_epi32(vq31prod3x0213, _MM_SHUFFLE(3, 1, 2, 0));

    const __m128i vremainder_mask = _mm_load_si128((const __m128i*) params->sse2.remainder_mask);
    const __m128i vrem0x0123 =
      _mm_add_epi32(_mm_and_si128(vq31prod0x0123, vremainder_mask), _mm_cmpgt_epi32(_mm_setzero_si128(), vq31prod0x0123));
    const __m128i vrem1x0123 =
      _mm_add_epi32(_mm_and_si128(vq31prod1x0123, vremainder_mask), _mm_cmpgt_epi32(_mm_setzero_si128(), vq31prod1x0123));
    const __m128i vrem2x0123 =
      _mm_add_epi32(_mm_and_si128(vq31prod2x0123, vremainder_mask), _mm_cmpgt_epi32(_mm_setzero_si128(), vq31prod2x0123));
    const __m128i vrem3x0123 =
      _mm_add_epi32(_mm_and_si128(vq31prod3x0123, vremainder_mask), _mm_cmpgt_epi32(_mm_setzero_si128(), vq31prod3x0123));

    const __m128i vremainder_threshold = _mm_load_si128((const __m128i*) params->sse2.remainder_threshold);
    const __m128i vshift = _mm_load_si128((const __m128i*) params->sse2.shift);
    vacc0x0123 =
      _mm_sub_epi32(_mm_sra_epi32(vq31prod0x0123, vshift), _mm_cmpgt_epi32(vrem0x0123, vremainder_threshold));
    vacc1x0123 =
      _mm_sub_epi32(_mm_sra_epi32(vq31prod1x0123, vshift), _mm_cmpgt_epi32(vrem1x0123, vremainder_threshold));
    vacc2x0123 =
      _mm_sub_epi32(_mm_sra_epi32(vq31prod2x0123, vshift), _mm_cmpgt_epi32(vrem2x0123, vremainder_threshold));
    vacc3x0123 =
      _mm_sub_epi32(_mm_sra_epi32(vq31prod3x0123, vshift), _mm_cmpgt_epi32(vrem3x0123, vremainder_threshold));

    const __m128i voutput_zero_point = _mm_load_si128((const __m128i*) params->sse2.output_zero_point);
    __m128i vacc01x0123 = _mm_adds_epi16(_mm_packs_epi32(vacc0x0123, vacc1x0123), voutput_zero_point);
    __m128i vacc23x0123 = _mm_adds_epi16(_mm_packs_epi32(vacc2x0123, vacc3x0123), voutput_zero_point);

    const __m128i voutput_min = _mm_load_si128((const __m128i*) params->sse2.output_min);
    const __m128i voutput_max = _mm_load_si128((const __m128i*) params->sse2.output_max);
    vacc01x0123 = _mm_min_epi16(_mm_max_epi16(vacc01x0123, voutput_min), voutput_max);
    vacc23x0123 = _mm_min_epi16(_mm_max_epi16(vacc23x0123, voutput_min), voutput_max);

    __m128i vout = _mm_packs_epi16(vacc01x0123, vacc23x0123);

    if (nc >= 4) {
      *((uint32_t*) c3) = (uint32_t) _mm_cvtsi128_si32(_mm_shuffle_epi32(vout, _MM_SHUFFLE(3, 3, 3, 3)));
      c3 = (int8_t*) ((uintptr_t) c3 + cn_stride);
      *((uint32_t*) c2) = (uint32_t) _mm_cvtsi128_si32(_mm_shuffle_epi32(vout, _MM_SHUFFLE(2, 2, 2, 2)));
      c2 = (int8_t*) ((uintptr_t) c2 + cn_stride);
      *((uint32_t*) c1) = (uint32_t) _mm_cvtsi128_si32(_mm_shuffle_epi32(vout, _MM_SHUFFLE(1, 1, 1, 1)));
      c1 = (int8_t*) ((uintptr_t) c1 + cn_stride);
      *((uint32_t*) c0) = (uint32_t) _mm_cvtsi128_si32(vout);
      c0 = (int8_t*) ((uintptr_t) c0 + cn_stride);

      a = (const int8_t**restrict) ((uintptr_t) a - ks);

      nc -= 4;
    } else {
      if (nc & 2) {
        *((uint16_t*) c3) = (uint16_t) _mm_extract_epi16(vout, 6);
        c3 += 2;
        *((uint16_t*) c2) = (uint16_t) _mm_extract_epi16(vout, 4);
        c2 += 2;
        *((uint16_t*) c1) = (uint16_t) _mm_extract_epi16(vout, 2);
        c1 += 2;
        *((uint16_t*) c0) = (uint16_t) _mm_extract_epi16(vout, 0);
        c0 += 2;
        vout = _mm_srli_epi32(vout, 16);
      }
      if (nc & 1) {
        *((int8_t*) c3) = (int8_t) _mm_extract_epi16(vout, 6);
        *((int8_t*) c2) = (int8_t) _mm_extract_epi16(vout, 4);
        *((int8_t*) c1) = (int8_t) _mm_extract_epi16(vout, 2);
        *((int8_t*) c0) = (int8_t) _mm_cvtsi128_si32(vout);
      }

      nc = 0;
    }
  } while (nc != 0);
}
