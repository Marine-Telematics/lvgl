#ifndef LV_CONF_H
#define LV_CONF_H

#include <stdint.h>

#define LV_COLOR_DEPTH         1
#define LV_COLOR_16_SWAP       0
#define LV_COLOR_SCREEN_TRANSP 0
#define LV_COLOR_MIX_ROUND_OFS 0
#define LV_COLOR_CHROMA_KEY    lv_color_hex(0x00ff00) /*pure green*/

#define LV_MEM_CUSTOM 0
#define LV_MEM_SIZE   (48U * 1024U) /*[bytes]*/
#define LV_MEM_ADR    0             /*0: unused*/
#undef LV_MEM_POOL_INCLUDE
#undef LV_MEM_POOL_ALLOC

#define LV_MEM_BUF_MAX_NUM   16
#define LV_MEMCPY_MEMSET_STD 0

#define LV_DISP_DEF_REFR_PERIOD  30 /*[ms]*/
#define LV_INDEV_DEF_READ_PERIOD 30 /*[ms]*/

#define LV_TICK_CUSTOM 0
// #define LV_TICK_CUSTOM_INCLUDE       "esp_timer.h"
// #define LV_TICK_CUSTOM_SYS_TIME_EXPR (esp_timer_get_time() / 1000)

#define LV_DPI_DEF 130 /*[px/inch]*/

#define LV_DRAW_COMPLEX      1
#define LV_SHADOW_CACHE_SIZE 0
#define LV_CIRCLE_CACHE_SIZE 4

#define LV_LAYER_SIMPLE_BUF_SIZE          (24 * 1024)
#define LV_LAYER_SIMPLE_FALLBACK_BUF_SIZE (3 * 1024)

#define LV_IMG_CACHE_DEF_SIZE  0
#define LV_GRADIENT_MAX_STOPS  2
#define LV_GRAD_CACHE_DEF_SIZE 0

#define LV_DITHER_GRADIENT  0
#define LV_DISP_ROT_MAX_BUF (10 * 1024)

#define LV_USE_GPU_ARM2D        0
#define LV_USE_GPU_STM32_DMA2D  0
#define LV_USE_GPU_RA6M3_G2D    0
#define LV_USE_GPU_SWM341_DMA2D 0
#define LV_USE_GPU_NXP_PXP      0
#define LV_USE_GPU_NXP_VG_LITE  0
#define LV_USE_GPU_SDL          0

#define LV_USE_LOG   1
#define LV_LOG_LEVEL LV_LOG_LEVEL_WARN

#define LV_LOG_PRINTF           0
#define LV_LOG_TRACE_MEM        1
#define LV_LOG_TRACE_TIMER      1
#define LV_LOG_TRACE_INDEV      1
#define LV_LOG_TRACE_DISP_REFR  1
#define LV_LOG_TRACE_EVENT      1
#define LV_LOG_TRACE_OBJ_CREATE 1
#define LV_LOG_TRACE_LAYOUT     1
#define LV_LOG_TRACE_ANIM       1

#define LV_USE_ASSERT_NULL          1
#define LV_USE_ASSERT_MALLOC        1
#define LV_USE_ASSERT_STYLE         0
#define LV_USE_ASSERT_MEM_INTEGRITY 0
#define LV_USE_ASSERT_OBJ           0
#define LV_ASSERT_HANDLER_INCLUDE   <stdint.h>
#define LV_ASSERT_HANDLER           abort();

#define LV_USE_PERF_MONITOR  0
#define LV_USE_MEM_MONITOR   0
#define LV_USE_REFR_DEBUG    0
#define LV_SPRINTF_CUSTOM    0
#define LV_SPRINTF_USE_FLOAT 0

#define LV_USE_USER_DATA 1

#define LV_ENABLE_GC         0
#define LV_BIG_ENDIAN_SYSTEM 0
#define LV_ATTRIBUTE_TICK_INC
#define LV_ATTRIBUTE_TIMER_HANDLER
#define LV_ATTRIBUTE_FLUSH_READY
#define LV_ATTRIBUTE_MEM_ALIGN_SIZE 1
#define LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_LARGE_CONST
#define LV_ATTRIBUTE_LARGE_RAM_ARRAY
#define LV_ATTRIBUTE_FAST_MEM
#define LV_ATTRIBUTE_DMA
#define LV_EXPORT_CONST_INT(int_value)                                \
    struct _silence_gcc_warning /*The default value just prevents GCC \
                                   warning*/
#define LV_USE_LARGE_COORD 0

#define LV_FONT_MONTSERRAT_8  1
#define LV_FONT_MONTSERRAT_10 1
#define LV_FONT_MONTSERRAT_12 1
#define LV_FONT_MONTSERRAT_14 1
#define LV_FONT_MONTSERRAT_16 0
#define LV_FONT_MONTSERRAT_18 0
#define LV_FONT_MONTSERRAT_20 0
#define LV_FONT_MONTSERRAT_22 0
#define LV_FONT_MONTSERRAT_24 0
#define LV_FONT_MONTSERRAT_26 0
#define LV_FONT_MONTSERRAT_28 0
#define LV_FONT_MONTSERRAT_30 0
#define LV_FONT_MONTSERRAT_32 0
#define LV_FONT_MONTSERRAT_34 0
#define LV_FONT_MONTSERRAT_36 0
#define LV_FONT_MONTSERRAT_38 0
#define LV_FONT_MONTSERRAT_40 0
#define LV_FONT_MONTSERRAT_42 0
#define LV_FONT_MONTSERRAT_44 0
#define LV_FONT_MONTSERRAT_46 0
#define LV_FONT_MONTSERRAT_48 0

#define LV_FONT_MONTSERRAT_12_SUBPX      0
#define LV_FONT_MONTSERRAT_28_COMPRESSED 0 /*bpp = 3*/
#define LV_FONT_DEJAVU_16_PERSIAN_HEBREW \
    0 /*Hebrew, Arabic, Persian letters and all their forms*/
#define LV_FONT_SIMSUN_16_CJK 0 /*1000 most common CJK radicals*/

#define LV_FONT_UNSCII_8  0
#define LV_FONT_UNSCII_16 0

#define LV_FONT_CUSTOM_DECLARE

#define LV_FONT_DEFAULT        &lv_font_montserrat_12
#define LV_FONT_FMT_TXT_LARGE  0
#define LV_USE_FONT_COMPRESSED 0

#define LV_USE_FONT_SUBPX 0
#if LV_USE_FONT_SUBPX
/*Set the pixel order of the display. Physical order of RGB channels.
 * Doesn't matter with "normal" fonts.*/
#define LV_FONT_SUBPX_BGR 0 /*0: RGB; 1:BGR order*/
#endif

#define LV_USE_FONT_PLACEHOLDER 1

/**
 * Select a character encoding for strings.
 * Your IDE or editor should have the same character encoding
 * - LV_TXT_ENC_UTF8
 * - LV_TXT_ENC_ASCII
 */
#define LV_TXT_ENC LV_TXT_ENC_UTF8

#define LV_TXT_BREAK_CHARS                  " ,.;:-_"
#define LV_TXT_LINE_BREAK_LONG_LEN          0
#define LV_TXT_LINE_BREAK_LONG_PRE_MIN_LEN  3
#define LV_TXT_LINE_BREAK_LONG_POST_MIN_LEN 3
#define LV_TXT_COLOR_CMD                    "#"

#define LV_USE_BIDI                 0
#define LV_USE_ARABIC_PERSIAN_CHARS 0

#define LV_USE_ARC       1
#define LV_USE_BAR       1
#define LV_USE_BTN       1
#define LV_USE_BTNMATRIX 1
#define LV_USE_CANVAS    1
#define LV_USE_CHECKBOX  1
#define LV_USE_DROPDOWN  1 /*Requires: lv_label*/
#define LV_USE_IMG       1 /*Requires: lv_label*/

#define LV_USE_LABEL            1
#define LV_LABEL_TEXT_SELECTION 1 /*Enable selecting text of the label*/
#define LV_LABEL_LONG_TXT_HINT                                           \
    1 /*Store some extra info in labels to speed up drawing of very long \
         texts*/

#define LV_USE_LINE 1

#define LV_USE_ROLLER 1 /*Requires: lv_label*/
#if LV_USE_ROLLER
#define LV_ROLLER_INF_PAGES \
    7 /*Number of extra "pages" when the roller is infinite*/
#endif

#define LV_USE_SLIDER 1 /*Requires: lv_bar*/

#define LV_USE_SWITCH 1

#define LV_USE_TEXTAREA 1 /*Requires: lv_label*/
#if LV_USE_TEXTAREA != 0
#define LV_TEXTAREA_DEF_PWD_SHOW_TIME 1500 /*ms*/
#endif

#define LV_USE_TABLE 1

#define LV_USE_ANIMIMG             1
#define LV_USE_CALENDAR            0
#define LV_USE_CHART               1
#define LV_USE_COLORWHEEL          1
#define LV_USE_IMGBTN              1
#define LV_USE_KEYBOARD            0
#define LV_USE_LED                 1
#define LV_USE_LIST                1
#define LV_USE_MENU                1
#define LV_USE_METER               1
#define LV_USE_MSGBOX              1
#define LV_USE_SPAN                1
#define LV_SPAN_SNIPPET_STACK_SIZE 64
#define LV_USE_SPINBOX             1
#define LV_USE_SPINNER             1
#define LV_USE_TABVIEW             1
#define LV_USE_TILEVIEW            1
#define LV_USE_WIN                 1

#define LV_USE_THEME_DEFAULT             1
#define LV_THEME_DEFAULT_DARK            1
#define LV_THEME_DEFAULT_GROW            1
#define LV_THEME_DEFAULT_TRANSITION_TIME 80

#define LV_USE_THEME_BASIC 0
#define LV_USE_THEME_MONO  1

#define LV_USE_FLEX 1
#define LV_USE_GRID 1

#define LV_USE_FS_STDIO                0
#define LV_USE_FS_POSIX                0
#define LV_USE_FS_WIN32                0
#define LV_USE_FS_FATFS                0
#define LV_USE_FS_LITTLEFS             0
#define LV_USE_PNG                     0
#define LV_USE_BMP                     0
#define LV_USE_SJPG                    0
#define LV_USE_GIF                     0
#define LV_USE_QRCODE                  0
#define LV_USE_FREETYPE                0
#define LV_USE_TINY_TTF                0
#define LV_USE_RLOTTIE                 0
#define LV_USE_FFMPEG                  0
#define LV_USE_SNAPSHOT                0
#define LV_USE_MONKEY                  0
#define LV_USE_GRIDNAV                 0
#define LV_USE_FRAGMENT                0
#define LV_USE_IMGFONT                 0
#define LV_USE_MSG                     0
#define LV_USE_IME_PINYIN              0
#define LV_BUILD_EXAMPLES              1
#define LV_USE_DEMO_WIDGETS            0
#define LV_USE_DEMO_KEYPAD_AND_ENCODER 0
#define LV_USE_DEMO_BENCHMARK          0
#define LV_USE_DEMO_STRESS             0
#define LV_USE_DEMO_MUSIC              0

#endif /*LV_CONF_H*/

