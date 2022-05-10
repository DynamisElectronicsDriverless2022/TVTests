#include "intrp2d_l_pw.h"
#include "rtwtypes.h"

real_T intrp2d_l_pw(const uint32_T bpIndex[], const real_T frac[], const real_T
                    table[], const uint32_T stride)
{
  real_T yL_0d0;
  real_T yL_0d1;
  uint32_T offset_1d;
  offset_1d = bpIndex[1U] * stride + bpIndex[0U];
  yL_0d0 = table[offset_1d];
  yL_0d0 += (table[offset_1d + 1U] - yL_0d0) * frac[0U];
  offset_1d += stride;
  yL_0d1 = table[offset_1d];
  return (((table[offset_1d + 1U] - yL_0d1) * frac[0U] + yL_0d1) - yL_0d0) *
    frac[1U] + yL_0d0;
}
