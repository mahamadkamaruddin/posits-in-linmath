#ifndef LINMATH_POSIT_H
#define LINMATH_POSIT_H

#include "/workspaces/posits-in-linmath/softposit_cpp/include/softposit.h"


#define LINMATH_H_DEFINE_VEC_POSIT(n) \
typedef posit32_t vec##n##_posit[n]; \
static inline void vec##n##_posit_add(vec##n##_posit r, vec##n##_posit const a, vec##n##_posit const b) { \
    for (int i = 0; i < n; ++i) \
        r[i] = p32_add(a[i], b[i]); \
} \
static inline void vec##n##_posit_sub(vec##n##_posit r, vec##n##_posit const a, vec##n##_posit const b) { \
    for (int i = 0; i < n; ++i) \
        r[i] = p32_sub(a[i], b[i]); \
}

LINMATH_H_DEFINE_VEC_POSIT(2)
LINMATH_H_DEFINE_VEC_POSIT(3)
LINMATH_H_DEFINE_VEC_POSIT(4)

#endif // LINMATH_POSIT_H