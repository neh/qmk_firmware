// Copyright 2022 Nathan Howell (@Nathan Howell)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define MATRIX_ROWS 5
#define MATRIX_COLS 10

#define MATRIX_ROW_PINS \
    { A4, A5, A6, A7, A8 }
#define MATRIX_COL_PINS \
    { B0, B1, B2, B3, B4, B10, B11, B12, A14, A13 }

#define DIODE_DIRECTION COL2ROW
