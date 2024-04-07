/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Select hand configuration */
#if 1
    #define MASTER_LEFT
#else
    #define MASTER_RIGHT
#endif

#define PERMISSIVE_HOLD
#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 165

#define MK_KINETIC_SPEED
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_INTERVAL 6
#define MOUSEKEY_MOVE_DELTA 60
#define MOUSEKEY_INITIAL_SPEED 300
#define MOUSEKEY_BASE_SPEED 6000

#define MOUSEKEY_WHEEL_INITIAL_MOVEMENTS 6
#define MOUSEKEY_WHEEL_BASE_MOVEMENTS 60

#ifdef OLED_ENABLE
    #define OLED_TIMEOUT 30000
    #define OLED_UPDATE_INTERVAL 40

    #define SPLIT_LAYER_STATE_ENABLE
    #define SPLIT_LED_STATE_ENABLE
#endif
