// Auto-generated file. Do not edit!
//   Template: src/qs8-igemm/4x16-aarch64-neon-mlal-lane-cortex-a53.S.in
//   Generator: tools/xngen
//
// Copyright 2021 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <xnnpack/assembly.h>

# void xnn_qs8_igemm_minmax_ukernel_4x16__aarch64_neon_mlal_lane_prfm_cortex_a53(
#     size_t mr,                 x0
#     size_t nc,                 x1
#     size_t kc,                 x2 / x0
#     size_t ks,                 x3 / x9
#     const int8_t**restrict a,  x4
#     const int8_t* restrict w,  x5
#     int8_t* restrict c,        x6
#     size_t cm_stride,          x7
#     size_t cn_stride,                  [sp] -> x10
#     size_t a_offset,                   [sp + 8] -> x11
#     const float* zero,                 [sp + 16] -> x12
#     const xnn_f32_minmax_params params [sp + 24] -> x8

# d8-d15, x19-x30 need to be preserved if used. x18 is reserved by the OS.

# Register usage
# A0  x20  v0
# A1  x15  v1
# A2  x13  v2
# A3  x21  v3
# B    x5  v4  v5  v6  v7
# C0   x6 v16 v20 v24 v28
# C1  x16 v17 v21 v25 v29
# C2  x17 v18 v22 v26 v30
# C3   x7 v19 v23 v27 v31
# unused v8 v9 v10 v11 v12 v13 v14 v15

BEGIN_FUNCTION xnn_qs8_igemm_minmax_ukernel_4x16__aarch64_neon_mlal_lane_prfm_cortex_a53

        # Clamp C pointers
        STP     d11, d10, [sp, #-64]!
        STP     d9, d8, [sp, #16]
        STP     x20, x19, [sp, #32]
        ADD     x8, x6, x7
        CMP     x0, #0x2
        CSEL    x8, x6, x8, cc
        LDP     x12, x11, [sp, #80]
        LDP     x14, x13, [sp, #64]
        CMP     x0, #0x3
        ADD     x9, x8, x7
        CSEL    x9, x8, x9, cc
        ADD     x10, x9, x7
        CMP     x0, #0x4
        CSEL    x10, x10, x9, eq
0:
        LDP     q0, q1, [x5]
        LDP     q2, q3, [x5, #32]
        ADD     x5, x5, #0x40
        MOV     x15, x3
        MOV     v6.16b, v1.16b
        MOV     v4.16b, v3.16b
        MOV     v5.16b, v2.16b
        MOV     v7.16b, v0.16b
        MOV     v16.16b, v3.16b
        MOV     v17.16b, v2.16b
        MOV     v18.16b, v1.16b
        MOV     v19.16b, v0.16b
        MOV     v20.16b, v3.16b
        MOV     v21.16b, v2.16b
        MOV     v22.16b, v1.16b
        MOV     v23.16b, v0.16b
1:
        LDP     x16, x17, [x4]
        LDP     x0, x20, [x4, #16]
        ADD     x7, x16, x13
        CMP     x16, x12
        CSEL    x19, x16, x7, eq
        ADD     x16, x17, x13
        CMP     x17, x12
        CSEL    x7, x17, x16, eq
        ADD     x16, x0, x13
        CMP     x0, x12
        CSEL    x0, x0, x16, eq
        ADD     x16, x20, x13
        CMP     x20, x12
        CSEL    x17, x20, x16, eq
        MOV     x16, x2
        CMP     x2, #0x8
        B.CC    3f
2:
        LDR     d24, [x19], #8
        LDR     d25, [x7], #8
        LDR     d26, [x0], #8
        LDR     d27, [x17], #8
        LDP     d28, d29, [x5]
        SXTL    v11.8h, v24.8b
        SXTL    v10.8h, v25.8b
        SXTL    v9.8h, v26.8b
        SXTL    v8.8h, v27.8b
        SXTL    v24.8h, v28.8b
        SMLAL   v23.4s, v24.4h, v11.h[0]
        SMLAL2  v22.4s, v24.8h, v11.h[0]
        SMLAL   v19.4s, v24.4h, v10.h[0]
        SMLAL2  v18.4s, v24.8h, v10.h[0]
        SMLAL   v7.4s, v24.4h, v9.h[0]
        SMLAL2  v6.4s, v24.8h, v9.h[0]
        SMLAL   v0.4s, v24.4h, v8.h[0]
        SMLAL2  v1.4s, v24.8h, v8.h[0]
        LDP     d25, d24, [x5, #16]
        SXTL    v26.8h, v29.8b
        SMLAL   v21.4s, v26.4h, v11.h[0]
        SMLAL2  v20.4s, v26.8h, v11.h[0]
        SXTL    v25.8h, v25.8b
        SMLAL   v17.4s, v26.4h, v10.h[0]
        SMLAL2  v16.4s, v26.8h, v10.h[0]
        SMLAL   v5.4s, v26.4h, v9.h[0]
        SMLAL2  v4.4s, v26.8h, v9.h[0]
        SMLAL   v2.4s, v26.4h, v8.h[0]
        SMLAL2  v3.4s, v26.8h, v8.h[0]
        SMLAL   v23.4s, v25.4h, v11.h[1]
        SMLAL2  v22.4s, v25.8h, v11.h[1]
        SMLAL   v19.4s, v25.4h, v10.h[1]
        SMLAL2  v18.4s, v25.8h, v10.h[1]
        SMLAL   v7.4s, v25.4h, v9.h[1]
        SMLAL2  v6.4s, v25.8h, v9.h[1]
        SMLAL   v0.4s, v25.4h, v8.h[1]
        SMLAL2  v1.4s, v25.8h, v8.h[1]
        LDP     d26, d25, [x5, #32]
        SXTL    v24.8h, v24.8b
        SMLAL   v21.4s, v24.4h, v11.h[1]
        SMLAL2  v20.4s, v24.8h, v11.h[1]
        SXTL    v26.8h, v26.8b
        SMLAL   v17.4s, v24.4h, v10.h[1]
        SMLAL2  v16.4s, v24.8h, v10.h[1]
        SMLAL   v5.4s, v24.4h, v9.h[1]
        SMLAL2  v4.4s, v24.8h, v9.h[1]
        SMLAL   v2.4s, v24.4h, v8.h[1]
        SMLAL2  v3.4s, v24.8h, v8.h[1]
        SMLAL   v23.4s, v26.4h, v11.h[2]
        SMLAL2  v22.4s, v26.8h, v11.h[2]
        SMLAL   v19.4s, v26.4h, v10.h[2]
        SMLAL2  v18.4s, v26.8h, v10.h[2]
        SMLAL   v7.4s, v26.4h, v9.h[2]
        SMLAL2  v6.4s, v26.8h, v9.h[2]
        SMLAL   v0.4s, v26.4h, v8.h[2]
        SMLAL2  v1.4s, v26.8h, v8.h[2]
        LDP     d24, d26, [x5, #48]
        SXTL    v25.8h, v25.8b
        PRFM    pldl1keep, [x5, #544]
        PRFM    pldl1keep, [x5, #608]
        SXTL    v24.8h, v24.8b
        SMLAL   v21.4s, v25.4h, v11.h[2]
        SMLAL2  v20.4s, v25.8h, v11.h[2]
        SMLAL   v17.4s, v25.4h, v10.h[2]
        SMLAL2  v16.4s, v25.8h, v10.h[2]
        SMLAL   v5.4s, v25.4h, v9.h[2]
        SMLAL2  v4.4s, v25.8h, v9.h[2]
        SMLAL   v2.4s, v25.4h, v8.h[2]
        SMLAL2  v3.4s, v25.8h, v8.h[2]
        SMLAL   v23.4s, v24.4h, v11.h[3]
        SMLAL2  v22.4s, v24.8h, v11.h[3]
        SMLAL   v19.4s, v24.4h, v10.h[3]
        SMLAL2  v18.4s, v24.8h, v10.h[3]
        SMLAL   v7.4s, v24.4h, v9.h[3]
        SMLAL2  v6.4s, v24.8h, v9.h[3]
        SMLAL   v0.4s, v24.4h, v8.h[3]
        SMLAL2  v1.4s, v24.8h, v8.h[3]
        LDP     d25, d24, [x5, #64]
        SXTL    v26.8h, v26.8b
        SMLAL   v21.4s, v26.4h, v11.h[3]
        SMLAL2  v20.4s, v26.8h, v11.h[3]
        SXTL    v25.8h, v25.8b
        SMLAL   v17.4s, v26.4h, v10.h[3]
        SMLAL2  v16.4s, v26.8h, v10.h[3]
        SMLAL   v5.4s, v26.4h, v9.h[3]
        SMLAL2  v4.4s, v26.8h, v9.h[3]
        SMLAL   v2.4s, v26.4h, v8.h[3]
        SMLAL2  v3.4s, v26.8h, v8.h[3]
        SMLAL   v23.4s, v25.4h, v11.h[4]
        SMLAL2  v22.4s, v25.8h, v11.h[4]
        SMLAL   v19.4s, v25.4h, v10.h[4]
        SMLAL2  v18.4s, v25.8h, v10.h[4]
        SMLAL   v7.4s, v25.4h, v9.h[4]
        SMLAL2  v6.4s, v25.8h, v9.h[4]
        SMLAL   v0.4s, v25.4h, v8.h[4]
        SMLAL2  v1.4s, v25.8h, v8.h[4]
        LDP     d26, d25, [x5, #80]
        SXTL    v24.8h, v24.8b
        SMLAL   v21.4s, v24.4h, v11.h[4]
        SMLAL2  v20.4s, v24.8h, v11.h[4]
        SXTL    v26.8h, v26.8b
        SMLAL   v17.4s, v24.4h, v10.h[4]
        SMLAL2  v16.4s, v24.8h, v10.h[4]
        SMLAL   v5.4s, v24.4h, v9.h[4]
        SMLAL2  v4.4s, v24.8h, v9.h[4]
        SMLAL   v2.4s, v24.4h, v8.h[4]
        SMLAL2  v3.4s, v24.8h, v8.h[4]
        SMLAL   v23.4s, v26.4h, v11.h[5]
        SMLAL2  v22.4s, v26.8h, v11.h[5]
        SMLAL   v19.4s, v26.4h, v10.h[5]
        SMLAL2  v18.4s, v26.8h, v10.h[5]
        SMLAL   v7.4s, v26.4h, v9.h[5]
        SMLAL2  v6.4s, v26.8h, v9.h[5]
        SMLAL   v0.4s, v26.4h, v8.h[5]
        SMLAL2  v1.4s, v26.8h, v8.h[5]
        LDP     d24, d26, [x5, #96]
        SXTL    v25.8h, v25.8b
        SMLAL   v21.4s, v25.4h, v11.h[5]
        SMLAL2  v20.4s, v25.8h, v11.h[5]
        SMLAL   v17.4s, v25.4h, v10.h[5]
        SMLAL2  v16.4s, v25.8h, v10.h[5]
        SMLAL   v5.4s, v25.4h, v9.h[5]
        SMLAL2  v4.4s, v25.8h, v9.h[5]
        SMLAL   v2.4s, v25.4h, v8.h[5]
        SMLAL2  v3.4s, v25.8h, v8.h[5]
        SXTL    v24.8h, v24.8b
        SXTL    v25.8h, v26.8b
        SMLAL   v23.4s, v24.4h, v11.h[6]
        SMLAL2  v22.4s, v24.8h, v11.h[6]
        SMLAL   v19.4s, v24.4h, v10.h[6]
        SMLAL2  v18.4s, v24.8h, v10.h[6]
        SMLAL   v7.4s, v24.4h, v9.h[6]
        SMLAL2  v6.4s, v24.8h, v9.h[6]
        SMLAL   v0.4s, v24.4h, v8.h[6]
        SMLAL2  v1.4s, v24.8h, v8.h[6]
        SMLAL   v21.4s, v25.4h, v11.h[6]
        SMLAL2  v20.4s, v25.8h, v11.h[6]
        SMLAL   v17.4s, v25.4h, v10.h[6]
        SMLAL2  v16.4s, v25.8h, v10.h[6]
        SMLAL   v5.4s, v25.4h, v9.h[6]
        SMLAL2  v4.4s, v25.8h, v9.h[6]
        SMLAL   v2.4s, v25.4h, v8.h[6]
        SMLAL2  v3.4s, v25.8h, v8.h[6]
        LDP     d24, d25, [x5, #112]
        SUB     x16, x16, #0x8
        ADD     x5, x5, #0x80
        CMP     x16, #0x7
        SXTL    v24.8h, v24.8b
        SMLAL   v23.4s, v24.4h, v11.h[7]
        SMLAL2  v22.4s, v24.8h, v11.h[7]
        SMLAL   v19.4s, v24.4h, v10.h[7]
        SMLAL2  v18.4s, v24.8h, v10.h[7]
        SMLAL   v7.4s, v24.4h, v9.h[7]
        SMLAL2  v6.4s, v24.8h, v9.h[7]
        SMLAL   v0.4s, v24.4h, v8.h[7]
        SMLAL2  v1.4s, v24.8h, v8.h[7]
        SXTL    v24.8h, v25.8b
        SMLAL   v21.4s, v24.4h, v11.h[7]
        SMLAL2  v20.4s, v24.8h, v11.h[7]
        SMLAL   v17.4s, v24.4h, v10.h[7]
        SMLAL2  v16.4s, v24.8h, v10.h[7]
        SMLAL   v5.4s, v24.4h, v9.h[7]
        SMLAL2  v4.4s, v24.8h, v9.h[7]
        SMLAL   v2.4s, v24.4h, v8.h[7]
        SMLAL2  v3.4s, v24.8h, v8.h[7]
        B.HI    2b
3:
        ADD     x4, x4, #0x20
        CBNZ    x16, 5f
4:
        SUBS    x15, x15, #0x20
        B.NE    1b
        B       12f
5:
        LDR     d24, [x19]
        LDR     d25, [x7]
        LDR     d26, [x0]
        LDR     d27, [x17]
        SXTL    v11.8h, v24.8b
        SXTL    v10.8h, v25.8b
        LDP     d24, d25, [x5]
        SXTL    v9.8h, v26.8b
        SXTL    v8.8h, v27.8b
        CMP     x16, #0x1
        SXTL    v24.8h, v24.8b
        SXTL    v25.8h, v25.8b
        SMLAL   v23.4s, v24.4h, v11.h[0]
        SMLAL2  v22.4s, v24.8h, v11.h[0]
        SMLAL   v21.4s, v25.4h, v11.h[0]
        SMLAL2  v20.4s, v25.8h, v11.h[0]
        SMLAL   v19.4s, v24.4h, v10.h[0]
        SMLAL2  v18.4s, v24.8h, v10.h[0]
        SMLAL   v17.4s, v25.4h, v10.h[0]
        SMLAL2  v16.4s, v25.8h, v10.h[0]
        SMLAL   v7.4s, v24.4h, v9.h[0]
        SMLAL2  v6.4s, v24.8h, v9.h[0]
        SMLAL   v5.4s, v25.4h, v9.h[0]
        SMLAL2  v4.4s, v25.8h, v9.h[0]
        SMLAL   v0.4s, v24.4h, v8.h[0]
        SMLAL2  v1.4s, v24.8h, v8.h[0]
        SMLAL   v2.4s, v25.4h, v8.h[0]
        SMLAL2  v3.4s, v25.8h, v8.h[0]
        B.NE    6f
        ADD     x5, x5, #0x10
        B       4b
6:
        LDP     d24, d25, [x5, #16]
        CMP     x16, #0x3
        SXTL    v24.8h, v24.8b
        SXTL    v25.8h, v25.8b
        SMLAL   v23.4s, v24.4h, v11.h[1]
        SMLAL2  v22.4s, v24.8h, v11.h[1]
        SMLAL   v21.4s, v25.4h, v11.h[1]
        SMLAL2  v20.4s, v25.8h, v11.h[1]
        SMLAL   v19.4s, v24.4h, v10.h[1]
        SMLAL2  v18.4s, v24.8h, v10.h[1]
        SMLAL   v17.4s, v25.4h, v10.h[1]
        SMLAL2  v16.4s, v25.8h, v10.h[1]
        SMLAL   v7.4s, v24.4h, v9.h[1]
        SMLAL2  v6.4s, v24.8h, v9.h[1]
        SMLAL   v5.4s, v25.4h, v9.h[1]
        SMLAL2  v4.4s, v25.8h, v9.h[1]
        SMLAL   v0.4s, v24.4h, v8.h[1]
        SMLAL2  v1.4s, v24.8h, v8.h[1]
        SMLAL   v2.4s, v25.4h, v8.h[1]
        SMLAL2  v3.4s, v25.8h, v8.h[1]
        B.CC    7f
        LDP     d24, d25, [x5, #32]
        CMP     x16, #0x3
        SXTL    v24.8h, v24.8b
        SXTL    v25.8h, v25.8b
        SMLAL   v23.4s, v24.4h, v11.h[2]
        SMLAL2  v22.4s, v24.8h, v11.h[2]
        SMLAL   v21.4s, v25.4h, v11.h[2]
        SMLAL2  v20.4s, v25.8h, v11.h[2]
        SMLAL   v19.4s, v24.4h, v10.h[2]
        SMLAL2  v18.4s, v24.8h, v10.h[2]
        SMLAL   v17.4s, v25.4h, v10.h[2]
        SMLAL2  v16.4s, v25.8h, v10.h[2]
        SMLAL   v7.4s, v24.4h, v9.h[2]
        SMLAL2  v6.4s, v24.8h, v9.h[2]
        SMLAL   v5.4s, v25.4h, v9.h[2]
        SMLAL2  v4.4s, v25.8h, v9.h[2]
        SMLAL   v0.4s, v24.4h, v8.h[2]
        SMLAL2  v1.4s, v24.8h, v8.h[2]
        SMLAL   v2.4s, v25.4h, v8.h[2]
        SMLAL2  v3.4s, v25.8h, v8.h[2]
        B.NE    8f
        ADD     x5, x5, #0x30
        B       4b
7:
        ADD     x5, x5, #0x20
        B       4b
8:
        LDP     d24, d25, [x5, #48]
        CMP     x16, #0x5
        SXTL    v24.8h, v24.8b
        SXTL    v25.8h, v25.8b
        SMLAL   v23.4s, v24.4h, v11.h[3]
        SMLAL2  v22.4s, v24.8h, v11.h[3]
        SMLAL   v21.4s, v25.4h, v11.h[3]
        SMLAL2  v20.4s, v25.8h, v11.h[3]
        SMLAL   v19.4s, v24.4h, v10.h[3]
        SMLAL2  v18.4s, v24.8h, v10.h[3]
        SMLAL   v17.4s, v25.4h, v10.h[3]
        SMLAL2  v16.4s, v25.8h, v10.h[3]
        SMLAL   v7.4s, v24.4h, v9.h[3]
        SMLAL2  v6.4s, v24.8h, v9.h[3]
        SMLAL   v5.4s, v25.4h, v9.h[3]
        SMLAL2  v4.4s, v25.8h, v9.h[3]
        SMLAL   v0.4s, v24.4h, v8.h[3]
        SMLAL2  v1.4s, v24.8h, v8.h[3]
        SMLAL   v2.4s, v25.4h, v8.h[3]
        SMLAL2  v3.4s, v25.8h, v8.h[3]
        B.CC    9f
        LDP     d24, d25, [x5, #64]
        CMP     x16, #0x5
        SXTL    v24.8h, v24.8b
        SXTL    v25.8h, v25.8b
        SMLAL   v23.4s, v24.4h, v11.h[4]
        SMLAL2  v22.4s, v24.8h, v11.h[4]
        SMLAL   v21.4s, v25.4h, v11.h[4]
        SMLAL2  v20.4s, v25.8h, v11.h[4]
        SMLAL   v19.4s, v24.4h, v10.h[4]
        SMLAL2  v18.4s, v24.8h, v10.h[4]
        SMLAL   v17.4s, v25.4h, v10.h[4]
        SMLAL2  v16.4s, v25.8h, v10.h[4]
        SMLAL   v7.4s, v24.4h, v9.h[4]
        SMLAL2  v6.4s, v24.8h, v9.h[4]
        SMLAL   v5.4s, v25.4h, v9.h[4]
        SMLAL2  v4.4s, v25.8h, v9.h[4]
        SMLAL   v0.4s, v24.4h, v8.h[4]
        SMLAL2  v1.4s, v24.8h, v8.h[4]
        SMLAL   v2.4s, v25.4h, v8.h[4]
        SMLAL2  v3.4s, v25.8h, v8.h[4]
        B.NE    10f
        ADD     x5, x5, #0x50
        B       4b
9:
        ADD     x5, x5, #0x40
        B       4b
10:
        LDP     d24, d25, [x5, #80]
        CMP     x16, #0x7
        SXTL    v24.8h, v24.8b
        SXTL    v25.8h, v25.8b
        SMLAL   v23.4s, v24.4h, v11.h[5]
        SMLAL2  v22.4s, v24.8h, v11.h[5]
        SMLAL   v21.4s, v25.4h, v11.h[5]
        SMLAL2  v20.4s, v25.8h, v11.h[5]
        SMLAL   v19.4s, v24.4h, v10.h[5]
        SMLAL2  v18.4s, v24.8h, v10.h[5]
        SMLAL   v17.4s, v25.4h, v10.h[5]
        SMLAL2  v16.4s, v25.8h, v10.h[5]
        SMLAL   v7.4s, v24.4h, v9.h[5]
        SMLAL2  v6.4s, v24.8h, v9.h[5]
        SMLAL   v5.4s, v25.4h, v9.h[5]
        SMLAL2  v4.4s, v25.8h, v9.h[5]
        SMLAL   v0.4s, v24.4h, v8.h[5]
        SMLAL2  v1.4s, v24.8h, v8.h[5]
        SMLAL   v2.4s, v25.4h, v8.h[5]
        SMLAL2  v3.4s, v25.8h, v8.h[5]
        B.CC    11f
        LDP     d24, d25, [x5, #96]
        ADD     x5, x5, #0x70
        SXTL    v24.8h, v24.8b
        SXTL    v25.8h, v25.8b
        SMLAL   v23.4s, v24.4h, v11.h[6]
        SMLAL2  v22.4s, v24.8h, v11.h[6]
        SMLAL   v21.4s, v25.4h, v11.h[6]
        SMLAL2  v20.4s, v25.8h, v11.h[6]
        SMLAL   v19.4s, v24.4h, v10.h[6]
        SMLAL2  v18.4s, v24.8h, v10.h[6]
        SMLAL   v17.4s, v25.4h, v10.h[6]
        SMLAL2  v16.4s, v25.8h, v10.h[6]
        SMLAL   v7.4s, v24.4h, v9.h[6]
        SMLAL2  v6.4s, v24.8h, v9.h[6]
        SMLAL   v5.4s, v25.4h, v9.h[6]
        SMLAL2  v4.4s, v25.8h, v9.h[6]
        SMLAL   v0.4s, v24.4h, v8.h[6]
        SMLAL2  v1.4s, v24.8h, v8.h[6]
        SMLAL   v2.4s, v25.4h, v8.h[6]
        SMLAL2  v3.4s, v25.8h, v8.h[6]
        B       4b
11:
        ADD     x5, x5, #0x60
        B       4b
12:
        MOV     x15, x11
        LD1R    {v25.4s}, [x15], #4
        CMP     x1, #0xf
        LD1R    {v24.4s}, [x15]
        SQRDMULH v23.4s, v23.4s, v25.4s
        SQRDMULH v22.4s, v22.4s, v25.4s
        SQRDMULH v21.4s, v21.4s, v25.4s
        SQRDMULH v20.4s, v20.4s, v25.4s
        SQRDMULH v19.4s, v19.4s, v25.4s
        SQRDMULH v18.4s, v18.4s, v25.4s
        SQRDMULH v17.4s, v17.4s, v25.4s
        SQRDMULH v16.4s, v16.4s, v25.4s
        SQRDMULH v7.4s, v7.4s, v25.4s
        SQRDMULH v6.4s, v6.4s, v25.4s
        SQRDMULH v5.4s, v5.4s, v25.4s
        SQRDMULH v4.4s, v4.4s, v25.4s
        SQRDMULH v0.4s, v0.4s, v25.4s
        SQRDMULH v1.4s, v1.4s, v25.4s
        SQRDMULH v2.4s, v2.4s, v25.4s
        SQRDMULH v3.4s, v3.4s, v25.4s
        CMEQ    v25.4s, v24.4s, #0
        MVN     v25.16b, v25.16b
        AND     v26.16b, v23.16b, v25.16b
        SSRA    v23.4s, v26.4s, #31
        AND     v26.16b, v22.16b, v25.16b
        SSRA    v22.4s, v26.4s, #31
        AND     v26.16b, v21.16b, v25.16b
        SSRA    v21.4s, v26.4s, #31
        AND     v26.16b, v20.16b, v25.16b
        SSRA    v20.4s, v26.4s, #31
        AND     v26.16b, v19.16b, v25.16b
        SSRA    v19.4s, v26.4s, #31
        AND     v26.16b, v18.16b, v25.16b
        SSRA    v18.4s, v26.4s, #31
        AND     v26.16b, v17.16b, v25.16b
        SSRA    v17.4s, v26.4s, #31
        AND     v26.16b, v16.16b, v25.16b
        SSRA    v16.4s, v26.4s, #31
        AND     v26.16b, v7.16b, v25.16b
        SSRA    v7.4s, v26.4s, #31
        AND     v26.16b, v6.16b, v25.16b
        SSRA    v6.4s, v26.4s, #31
        AND     v26.16b, v5.16b, v25.16b
        SSRA    v5.4s, v26.4s, #31
        AND     v26.16b, v4.16b, v25.16b
        SSRA    v4.4s, v26.4s, #31
        AND     v26.16b, v0.16b, v25.16b
        SSRA    v0.4s, v26.4s, #31
        AND     v26.16b, v1.16b, v25.16b
        ADD     x15, x11, #0x8
        SSRA    v1.4s, v26.4s, #31
        AND     v26.16b, v2.16b, v25.16b
        SSRA    v2.4s, v26.4s, #31
        LD1R    {v26.8h}, [x15]
        AND     v25.16b, v3.16b, v25.16b
        SRSHL   v23.4s, v23.4s, v24.4s
        SRSHL   v21.4s, v21.4s, v24.4s
        SRSHL   v19.4s, v19.4s, v24.4s
        SRSHL   v17.4s, v17.4s, v24.4s
        SRSHL   v7.4s, v7.4s, v24.4s
        SRSHL   v5.4s, v5.4s, v24.4s
        SRSHL   v0.4s, v0.4s, v24.4s
        SSRA    v3.4s, v25.4s, #31
        SRSHL   v22.4s, v22.4s, v24.4s
        SRSHL   v20.4s, v20.4s, v24.4s
        SRSHL   v18.4s, v18.4s, v24.4s
        SRSHL   v16.4s, v16.4s, v24.4s
        SRSHL   v6.4s, v6.4s, v24.4s
        SRSHL   v4.4s, v4.4s, v24.4s
        SRSHL   v1.4s, v1.4s, v24.4s
        SRSHL   v2.4s, v2.4s, v24.4s
        SQXTN   v23.4h, v23.4s
        SQXTN   v21.4h, v21.4s
        SQXTN   v19.4h, v19.4s
        SQXTN   v17.4h, v17.4s
        SQXTN   v7.4h, v7.4s
        SQXTN   v5.4h, v5.4s
        SQXTN   v0.4h, v0.4s
        SRSHL   v3.4s, v3.4s, v24.4s
        SQXTN   v2.4h, v2.4s
        SQXTN2  v23.8h, v22.4s
        SQXTN2  v21.8h, v20.4s
        SQXTN2  v19.8h, v18.4s
        SQXTN2  v17.8h, v16.4s
        SQXTN2  v7.8h, v6.4s
        SQXTN2  v5.8h, v4.4s
        SQXTN2  v0.8h, v1.4s
        SQXTN2  v2.8h, v3.4s
        SQADD   v1.8h, v23.8h, v26.8h
        SQADD   v4.8h, v19.8h, v26.8h
        SQADD   v7.8h, v7.8h, v26.8h
        SQADD   v0.8h, v0.8h, v26.8h
        ADD     x15, x11, #0xa
        SQADD   v3.8h, v21.8h, v26.8h
        SQADD   v6.8h, v17.8h, v26.8h
        SQADD   v5.8h, v5.8h, v26.8h
        SQADD   v2.8h, v2.8h, v26.8h
        SQXTN   v1.8b, v1.8h
        SQXTN   v4.8b, v4.8h
        SQXTN   v7.8b, v7.8h
        SQXTN   v0.8b, v0.8h
        SQXTN2  v1.16b, v3.8h
        SQXTN2  v4.16b, v6.8h
        SQXTN2  v7.16b, v5.8h
        SQXTN2  v0.16b, v2.8h
        LD1R    {v2.16b}, [x15]
        ADD     x15, x11, #0xb
        LD1R    {v5.16b}, [x15]
        SMAX    v0.16b, v0.16b, v2.16b
        SMAX    v6.16b, v7.16b, v2.16b
        SMAX    v4.16b, v4.16b, v2.16b
        SMAX    v7.16b, v1.16b, v2.16b
        SMIN    v3.16b, v0.16b, v5.16b
        SMIN    v1.16b, v6.16b, v5.16b
        SMIN    v2.16b, v4.16b, v5.16b
        SMIN    v0.16b, v7.16b, v5.16b
        B.LS    13f
        STR     q3, [x10]
        STR     q1, [x9]
        STR     q2, [x8]
        STR     q0, [x6]
        ADD     x10, x10, x14
        ADD     x9, x9, x14
        ADD     x8, x8, x14
        ADD     x6, x6, x14
        SUBS    x1, x1, #0x10
        SUB     x4, x4, x3
        B.NE    0b
        B       18f
13:
        TBNZ    w1, #3, 14f
        MOV     v0.d[1], v2.d[0]
        MOV     v1.d[1], v3.d[0]
        TBNZ    w1, #2, 15f
        B       16f
14:
        STR     d3, [x10], #8
        STR     d1, [x9], #8
        STR     d2, [x8], #8
        STR     d0, [x6], #8
        EXT     v1.16b, v1.16b, v1.16b, #8
        EXT     v3.16b, v3.16b, v3.16b, #8
        EXT     v0.16b, v0.16b, v0.16b, #8
        EXT     v2.16b, v2.16b, v2.16b, #8
        MOV     v1.d[1], v3.d[0]
        MOV     v0.d[1], v2.d[0]
        TBZ     w1, #2, 16f
15:
        ST1     {v1.s}[2], [x10], #4
        ST1     {v1.s}[0], [x9], #4
        ST1     {v0.s}[2], [x8], #4
        ST1     {v0.s}[0], [x6], #4
        EXT     v1.16b, v1.16b, v1.16b, #4
        EXT     v0.16b, v0.16b, v0.16b, #4
16:
        TBNZ    w1, #1, 19f
        TBZ     w1, #0, 18f
17:
        ST1     {v1.b}[8], [x10]
        ST1     {v1.b}[0], [x9]
        ST1     {v0.b}[8], [x8]
        ST1     {v0.b}[0], [x6]
18:
        LDP     x20, x19, [sp, #32]
        LDP     d9, d8, [sp, #16]
        LDP     d11, d10, [sp], #64
        RET
19:
        ST1     {v1.h}[4], [x10], #2
        ST1     {v1.h}[0], [x9], #2
        ST1     {v0.h}[4], [x8], #2
        ST1     {v0.h}[0], [x6], #2
        EXT     v1.16b, v1.16b, v1.16b, #2
        EXT     v0.16b, v0.16b, v0.16b, #2
        TBNZ    w1, #0, 17b
        B       18b

END_FUNCTION xnn_qs8_igemm_minmax_ukernel_4x16__aarch64_neon_mlal_lane_prfm_cortex_a53

#ifdef __ELF__
.section ".note.GNU-stack","",%progbits
#endif
