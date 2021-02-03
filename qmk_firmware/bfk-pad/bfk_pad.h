/**
 * Copyright 2020 Alexander Lomachenko
 */

#pragma once

#include "quantum.h"

#define LAYOUT( \
    k02,      k22, k32, k42, \
    k01, k11, k21, k31, k41, \
    k00, k10, k20, k30, k40 \
) { \
    {k02, KC_NO, k22, k32, k42}, \
    {k01, k11,   k21, k31, k41}, \
    {k00, k10,   k20, k30, k40 } \
}
