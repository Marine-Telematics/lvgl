#ifndef LV_CONF_H
#define LV_CONF_H

#include <stdint.h>

/*====================
   COLOR SETTINGS
 *====================*/
#define LV_COLOR_DEPTH         16
#define LV_COLOR_16_SWAP       1
#define LV_COLOR_SCREEN_TRANSP 0
#define LV_COLOR_MIX_ROUND_OFS 0
#define LV_COLOR_CHROMA_KEY    lv_color_hex(0x00ff00) /*pure green*/

/*=========================
   MEMORY SETTINGS
 *=========================*/

#define LV_MEM_CUSTOM         1
#define LV_MEM_SIZE           (48 * 1024 /* 48Kb as described in lvgl docs */)
#define LV_MEM_CUSTOM_INCLUDE <stdlib.h> /*Header for the dynamic memory function*/
#define LV_MEM_CUSTOM_ALLOC   malloc
#define LV_MEM_CUSTOM_FREE    free
#define LV_MEM_CUSTOM_REALLOC realloc
#define LV_MEM_BUF_MAX_NUM    16
#define LV_MEMCPY_MEMSET_STD  0

/*====================
   HAL SETTINGS
 *====================*/

#define LV_DISP_DEF_REFR_PERIOD  30 /*[ms]*/
#define LV_INDEV_DEF_READ_PERIOD 30 /*[ms]*/

#define LV_TICK_CUSTOM               1
#define LV_TICK_CUSTOM_INCLUDE       <esp_timer.h>
#define LV_TICK_CUSTOM_SYS_TIME_EXPR (esp_timer_get_time() / 1000)

#define LV_DPI_DEF 130 /*[px/inch]*/

/*=======================
 * FEATURE CONFIGURATION
 *=======================*/

/*-------------
 * Drawing
 *-----------*/

/*Enable complex draw engine.
 *Required to draw shadow, gradient, rounded corners, circles, arc, skew lines,
 *image transformations or any masks*/
#define LV_DRAW_COMPLEX      1
#define LV_SHADOW_CACHE_SIZE 0
#define LV_CIRCLE_CACHE_SIZE 4

#define LV_LAYER_SIMPLE_BUF_SIZE          (24 * 1024)
#define LV_LAYER_SIMPLE_FALLBACK_BUF_SIZE (3 * 1024)
#define LV_IMG_CACHE_DEF_SIZE             0
#define LV_GRADIENT_MAX_STOPS             2
#define LV_GRAD_CACHE_DEF_SIZE            0
#define LV_DITHER_GRADIENT                0
#define LV_DISP_ROT_MAX_BUF               (10 * 1024)

/*-------------
 * GPU
 *-----------*/

#define LV_USE_GPU_ARM2D        0
#define LV_USE_GPU_STM32_DMA2D  0
#define LV_USE_GPU_SWM341_DMA2D 0
#define LV_USE_GPU_NXP_PXP      0
#define LV_USE_GPU_NXP_VG_LITE  0
#define LV_USE_GPU_SDL          0

/*-------------
 * Logging
 *-----------*/

#define LV_USE_LOG 1

/*How important log should be added:
 *LV_LOG_LEVEL_TRACE       A lot of logs to give detailed information
 *LV_LOG_LEVEL_INFO        Log important events
 *LV_LOG_LEVEL_WARN        Log if something unwanted happened but didn't cause a
 *problem LV_LOG_LEVEL_ERROR       Only critical issue, when the system may fail
 *LV_LOG_LEVEL_USER        Only logs added by the user
 *LV_LOG_LEVEL_NONE        Do not log anything*/
#define LV_LOG_LEVEL LV_LOG_LEVEL_WARN

#define LV_LOG_PRINTF 1

#define LV_LOG_TRACE_MEM        1
#define LV_LOG_TRACE_TIMER      1
#define LV_LOG_TRACE_INDEV      1
#define LV_LOG_TRACE_DISP_REFR  1
#define LV_LOG_TRACE_EVENT      1
#define LV_LOG_TRACE_OBJ_CREATE 1
#define LV_LOG_TRACE_LAYOUT     1
#define LV_LOG_TRACE_ANIM       1

/*-------------
 * Asserts
 *-----------*/

#define LV_USE_ASSERT_NULL 1 /*Check if the parameter is NULL. (Very fast, recommended)*/
#define LV_USE_ASSERT_MALLOC                                              \
    1 /*Checks is the memory is successfully allocated or no. (Very fast, \
         recommended)*/
#define LV_USE_ASSERT_STYLE                                       \
    1 /*Check if the styles are properly initialized. (Very fast, \
         recommended)*/
#define LV_USE_ASSERT_MEM_INTEGRITY \
    0                       /*Check the integrity of `lv_mem` after critical operations. (Slow)*/
#define LV_USE_ASSERT_OBJ 0 /*Check the object's type and existence (e.g. not deleted). (Slow)*/

#define LV_ASSERT_HANDLER_INCLUDE <stdint.h>
#define LV_ASSERT_HANDLER         abort();
/*1: Show CPU usage and FPS count*/
#define LV_USE_PERF_MONITOR    0
#define LV_USE_MEM_MONITOR     0
#define LV_USE_MEM_MONITOR_POS LV_ALIGN_BOTTOM_LEFT

#define LV_USE_REFR_DEBUG    0
#define LV_SPRINTF_CUSTOM    0
#define LV_SPRINTF_USE_FLOAT 0
#define LV_USE_USER_DATA     1

#define LV_ENABLE_GC 0

/*=====================
 *  COMPILER SETTINGS
 *====================*/

/*For big endian systems set to 1*/
#define LV_BIG_ENDIAN_SYSTEM 0

/*Define a custom attribute to `lv_tick_inc` function*/
#define LV_ATTRIBUTE_TICK_INC

/*Define a custom attribute to `lv_timer_handler` function*/
#define LV_ATTRIBUTE_TIMER_HANDLER

/*Define a custom attribute to `lv_disp_flush_ready` function*/
#define LV_ATTRIBUTE_FLUSH_READY

/*Required alignment size for buffers*/
#define LV_ATTRIBUTE_MEM_ALIGN_SIZE 1

/*Will be added where memories needs to be aligned (with -Os data might not be
 * aligned to boundary by default). E.g. __attribute__((aligned(4)))*/
#define LV_ATTRIBUTE_MEM_ALIGN

/*Attribute to mark large constant arrays for example font's bitmaps*/
#define LV_ATTRIBUTE_LARGE_CONST

/*Compiler prefix for a big array declaration in RAM*/
#define LV_ATTRIBUTE_LARGE_RAM_ARRAY

/*Place performance critical functions into a faster memory (e.g RAM)*/
#define LV_ATTRIBUTE_FAST_MEM

/*Prefix variables that are used in GPU accelerated operations, often these need
 * to be placed in RAM sections that are DMA accessible*/
#define LV_ATTRIBUTE_DMA DMA_ATTR

/*Export integer constant to binding. This macro is used with constants in the
 *form of LV_<CONST> that should also appear on LVGL binding API such as
 *Micropython.*/
#define LV_EXPORT_CONST_INT(int_value)                                \
    struct _silence_gcc_warning /*The default value just prevents GCC \
                                   warning*/

/*Extend the default -32k..32k coordinate range to -4M..4M by using int32_t for
 * coordinates instead of int16_t*/
#define LV_USE_LARGE_COORD 0

/*==================
 *   FONT USAGE
 *===================*/

/*Montserrat fonts with ASCII range and some symbols using bpp = 4
 *https://fonts.google.com/specimen/Montserrat*/
#define LV_FONT_MONTSERRAT_8  0
#define LV_FONT_MONTSERRAT_10 0
#define LV_FONT_MONTSERRAT_12 1
#define LV_FONT_MONTSERRAT_14 0
#define LV_FONT_MONTSERRAT_16 0
#define LV_FONT_MONTSERRAT_18 1
#define LV_FONT_MONTSERRAT_20 0
#define LV_FONT_MONTSERRAT_22 0
#define LV_FONT_MONTSERRAT_24 0
#define LV_FONT_MONTSERRAT_26 0
#define LV_FONT_MONTSERRAT_28 0
#define LV_FONT_MONTSERRAT_30 0
#define LV_FONT_MONTSERRAT_32 0
#define LV_FONT_MONTSERRAT_34 0
#define LV_FONT_MONTSERRAT_36 0
#define LV_FONT_MONTSERRAT_38 1
#define LV_FONT_MONTSERRAT_40 0
#define LV_FONT_MONTSERRAT_42 0
#define LV_FONT_MONTSERRAT_44 0
#define LV_FONT_MONTSERRAT_46 0
#define LV_FONT_MONTSERRAT_48 1

/*Demonstrate special features*/
#define LV_FONT_MONTSERRAT_12_SUBPX      0
#define LV_FONT_MONTSERRAT_28_COMPRESSED 0 /*bpp = 3*/
#define LV_FONT_DEJAVU_16_PERSIAN_HEBREW 0 /*Hebrew, Arabic, Persian letters and all their forms*/
#define LV_FONT_SIMSUN_16_CJK            0 /*1000 most common CJK radicals*/

/*Pixel perfect monospace fonts*/
#define LV_FONT_UNSCII_8  0
#define LV_FONT_UNSCII_16 0

#define LV_FONT_CUSTOM_DECLARE      \
    LV_FONT_DECLARE(olney_light_15) \
    LV_FONT_DECLARE(icons)          \
    LV_FONT_DECLARE(icons_68) LV_FONT_DECLARE(boat_icon_65)
#define LV_FONT_DEFAULT &olney_light_15

/*Enable handling large font and/or fonts with a lot of characters.
 *The limit depends on the font size, font face and bpp.
 *Compiler error will be triggered if a font needs it.*/
#define LV_FONT_FMT_TXT_LARGE 0

/*Enables/disables support for compressed fonts.*/
#define LV_USE_FONT_COMPRESSED 0

/*Enable subpixel rendering*/
#define LV_USE_FONT_SUBPX 1

/*=================
 *  TEXT SETTINGS
 *=================*/

/**
 * Select a character encoding for strings.
 * Your IDE or editor should have the same character encoding
 * - LV_TXT_ENC_UTF8
 * - LV_TXT_ENC_ASCII
 */
#define LV_TXT_ENC LV_TXT_ENC_UTF8

/*Can break (wrap) texts on these chars*/
#define LV_TXT_BREAK_CHARS " ,.;:-_"

/*If a word is at least this long, will break wherever "prettiest"
 *To disable, set to a value <= 0*/
#define LV_TXT_LINE_BREAK_LONG_LEN 0

/*Minimum number of characters in a long word to put on a line before a break.
 *Depends on LV_TXT_LINE_BREAK_LONG_LEN.*/
#define LV_TXT_LINE_BREAK_LONG_PRE_MIN_LEN 3

/*Minimum number of characters in a long word to put on a line after a break.
 *Depends on LV_TXT_LINE_BREAK_LONG_LEN.*/
#define LV_TXT_LINE_BREAK_LONG_POST_MIN_LEN 3

/*The control character to use for signalling text recoloring.*/
#define LV_TXT_COLOR_CMD "#"

#define LV_USE_BIDI                 0
#define LV_USE_ARABIC_PERSIAN_CHARS 0

/*==================
 *  WIDGET USAGE
 *================*/

/*Documentation of the widgets:
 * https://docs.lvgl.io/latest/en/html/widgets/index.html*/

#define LV_USE_ARC 1

#define LV_USE_BAR 1

#define LV_USE_BTN 1

#define LV_USE_BTNMATRIX 1

#define LV_USE_CANVAS 1

#define LV_USE_CHECKBOX 1

#define LV_USE_DROPDOWN 1 /*Requires: lv_label*/

#define LV_USE_IMG 1 /*Requires: lv_label*/

#define LV_USE_LABEL            1
#define LV_LABEL_TEXT_SELECTION 1 /*Enable selecting text of the label*/
#define LV_LABEL_LONG_TXT_HINT                                           \
    1 /*Store some extra info in labels to speed up drawing of very long \
         texts*/

#define LV_USE_LINE 1

#define LV_USE_ROLLER       1 /*Requires: lv_label*/
#define LV_ROLLER_INF_PAGES 7 /*Number of extra "pages" when the roller is infinite*/

#define LV_USE_SLIDER 1 /*Requires: lv_bar*/

#define LV_USE_SWITCH 1

#define LV_USE_TEXTAREA 1 /*Requires: lv_label*/
#if LV_USE_TEXTAREA != 0
#define LV_TEXTAREA_DEF_PWD_SHOW_TIME 1500 /*ms*/
#endif

#define LV_USE_TABLE 1

/*==================
 * EXTRA COMPONENTS
 *==================*/

/*-----------
 * Widgets
 *----------*/
#define LV_USE_ANIMIMG 1

#define LV_USE_CALENDAR 0
#if LV_USE_CALENDAR
#define LV_CALENDAR_WEEK_STARTS_MONDAY 0
#if LV_CALENDAR_WEEK_STARTS_MONDAY
#define LV_CALENDAR_DEFAULT_DAY_NAMES            \
    {                                            \
        "Mo", "Tu", "We", "Th", "Fr", "Sa", "Su" \
    }
#else
#define LV_CALENDAR_DEFAULT_DAY_NAMES            \
    {                                            \
        "Su", "Mo", "Tu", "We", "Th", "Fr", "Sa" \
    }
#endif

#define LV_CALENDAR_DEFAULT_MONTH_NAMES                                                        \
    {                                                                                          \
        "January", "February", "March", "April", "May", "June", "July", "August", "September", \
            "October", "November", "December"                                                  \
    }
#define LV_USE_CALENDAR_HEADER_ARROW    1
#define LV_USE_CALENDAR_HEADER_DROPDOWN 1
#endif /*LV_USE_CALENDAR*/

#define LV_USE_CHART 0

#define LV_USE_COLORWHEEL 0

#define LV_USE_IMGBTN 1

#define LV_USE_KEYBOARD 0

#define LV_USE_LED 0

#define LV_USE_LIST 1

#define LV_USE_MENU 1

#define LV_USE_METER 1

#define LV_USE_MSGBOX 1

#define LV_USE_SPAN                1
#define LV_SPAN_SNIPPET_STACK_SIZE 64

#define LV_USE_SPINBOX 1

#define LV_USE_SPINNER 1

#define LV_USE_TABVIEW 0

#define LV_USE_TILEVIEW 1

#define LV_USE_WIN 1

/*-----------
 * Themes
 *----------*/

/*A simple, impressive and very complete theme*/
#define LV_USE_THEME_DEFAULT             1
#define LV_THEME_DEFAULT_DARK            1
#define LV_THEME_DEFAULT_GROW            1
#define LV_THEME_DEFAULT_TRANSITION_TIME 80
#define LV_USE_THEME_BASIC               1
#define LV_USE_THEME_MONO                1

/*-----------
 * Layouts
 *----------*/

/*A layout similar to Flexbox in CSS.*/
#define LV_USE_FLEX 1

/*A layout similar to Grid in CSS.*/
#define LV_USE_GRID 1

/*---------------------
 * 3rd party libraries
 *--------------------*/

/*File system interfaces for common APIs */

/*API for fopen, fread, etc*/
#define LV_USE_FS_STDIO 0

/*API for open, read, etc*/
#define LV_USE_FS_POSIX 0

#define LV_USE_FS_WIN32 0

/*API for FATFS (needs to be added separately). Uses f_open, f_read, etc*/
#define LV_USE_FS_FATFS 0

/*PNG decoder library*/
#define LV_USE_PNG 0

/*BMP decoder library*/
#define LV_USE_BMP 0

/* JPG + split JPG decoder library.
 * Split JPG is a custom format optimized for embedded systems. */
#define LV_USE_SJPG 0

/*GIF decoder library*/
#define LV_USE_GIF 0

/*QR code library*/
#define LV_USE_QRCODE 0

/*FreeType library*/
#define LV_USE_FREETYPE 0

/*Rlottie library*/
#define LV_USE_RLOTTIE 0

/*FFmpeg library for image decoding and playing videos
 *Supports all major image formats so do not enable other image decoder with
 *it*/
#define LV_USE_FFMPEG 0

/*-----------
 * Others
 *----------*/

/*1: Enable API to take snapshot for object*/
#define LV_USE_SNAPSHOT 0

/*1: Enable Monkey test*/
#define LV_USE_MONKEY 0

/*1: Enable grid navigation*/
#define LV_USE_GRIDNAV 0

/*1: Enable lv_obj fragment*/
#define LV_USE_FRAGMENT 0

/*1: Support using images as font in label or span widgets */
#define LV_USE_IMGFONT 0

/*1: Enable a published subscriber based messaging system */
#define LV_USE_MSG 1

/*1: Enable Pinyin input method*/
/*Requires: lv_keyboard*/
#define LV_USE_IME_PINYIN 0

#define LV_BUILD_EXAMPLES 0

#define LV_USE_DEMO_WIDGETS            0
#define LV_USE_DEMO_KEYPAD_AND_ENCODER 0
/*Benchmark your system*/
#define LV_USE_DEMO_BENCHMARK      1
#define LV_DEMO_BENCHMARK_RGB565A8 0
#define LV_USE_DEMO_STRESS         0
#define LV_USE_DEMO_MUSIC          0
#endif /*LV_CONF_H*/
