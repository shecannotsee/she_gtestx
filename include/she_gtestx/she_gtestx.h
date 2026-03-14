#ifndef SHE_GTESTX_SHE_GTESTX_H_
#define SHE_GTESTX_SHE_GTESTX_H_

#include <gtest/gtest.h>

#define SHE_GTESTX_PP_CAT_(left, right) left##right
#define SHE_GTESTX_PP_CAT(left, right) SHE_GTESTX_PP_CAT_(left, right)
#define SHE_GTESTX_PP_EXPAND(...) __VA_ARGS__

#define SHE_GTESTX_PP_CAT3_(a, b, c) a##b##c
#define SHE_GTESTX_PP_CAT3(a, b, c) SHE_GTESTX_PP_CAT3_(a, b, c)

#define SHE_GTESTX_PP_CAT5_(a, b, c, d, e) a##b##c##d##e
#define SHE_GTESTX_PP_CAT5(a, b, c, d, e) SHE_GTESTX_PP_CAT5_(a, b, c, d, e)

#define SHE_GTESTX_PP_CAT7_(a, b, c, d, e, f, g) a##b##c##d##e##f##g
#define SHE_GTESTX_PP_CAT7(a, b, c, d, e, f, g) SHE_GTESTX_PP_CAT7_(a, b, c, d, e, f, g)

#define SHE_GTESTX_PP_CAT9_(a, b, c, d, e, f, g, h, i) a##b##c##d##e##f##g##h##i
#define SHE_GTESTX_PP_CAT9(a, b, c, d, e, f, g, h, i) SHE_GTESTX_PP_CAT9_(a, b, c, d, e, f, g, h, i)

#define SHE_GTESTX_PP_CAT11_(a, b, c, d, e, f, g, h, i, j, k) a##b##c##d##e##f##g##h##i##j##k
#define SHE_GTESTX_PP_CAT11(a, b, c, d, e, f, g, h, i, j, k) SHE_GTESTX_PP_CAT11_(a, b, c, d, e, f, g, h, i, j, k)

#define SHE_GTESTX_PP_ARG_N_( \
    _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, n, ...) n
#define SHE_GTESTX_PP_RSEQ_N_ 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0
#define SHE_GTESTX_PP_NARG_(...) SHE_GTESTX_PP_ARG_N_(__VA_ARGS__)
#define SHE_GTESTX_PP_NARG(...) SHE_GTESTX_PP_EXPAND(SHE_GTESTX_PP_NARG_(__VA_ARGS__, SHE_GTESTX_PP_RSEQ_N_))

#define SHE_GTESTX_LEVELS_1(level1) level1
#define SHE_GTESTX_LEVELS_2(level1, level2) SHE_GTESTX_PP_CAT3(level1, __, level2)
#define SHE_GTESTX_LEVELS_3(level1, level2, level3) \
  SHE_GTESTX_PP_CAT5(level1, __, level2, __, level3)
#define SHE_GTESTX_LEVELS_4(level1, level2, level3, level4) \
  SHE_GTESTX_PP_CAT7(level1, __, level2, __, level3, __, level4)
#define SHE_GTESTX_LEVELS_5(level1, level2, level3, level4, level5) \
  SHE_GTESTX_PP_CAT9(level1, __, level2, __, level3, __, level4, __, level5)
#define SHE_GTESTX_LEVELS_6(level1, level2, level3, level4, level5, level6) \
  SHE_GTESTX_PP_CAT11(level1, __, level2, __, level3, __, level4, __, level5, __, level6)
#define SHE_GTESTX_LEVELS_7(level1, level2, level3, level4, level5, level6, level7) \
  SHE_GTESTX_PP_CAT3(SHE_GTESTX_LEVELS_6(level1, level2, level3, level4, level5, level6), __, level7)
#define SHE_GTESTX_LEVELS_8(level1, level2, level3, level4, level5, level6, level7, level8) \
  SHE_GTESTX_PP_CAT3(SHE_GTESTX_LEVELS_7(level1, level2, level3, level4, level5, level6, level7), __, level8)
#define SHE_GTESTX_LEVELS_9(level1, level2, level3, level4, level5, level6, level7, level8, level9) \
  SHE_GTESTX_PP_CAT3(SHE_GTESTX_LEVELS_8(level1, level2, level3, level4, level5, level6, level7, level8), __, level9)
#define SHE_GTESTX_LEVELS_10(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10) \
  SHE_GTESTX_PP_CAT3(SHE_GTESTX_LEVELS_9(level1, level2, level3, level4, level5, level6, level7, level8, level9), __, level10)
#define SHE_GTESTX_LEVELS_11(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11) \
  SHE_GTESTX_PP_CAT3(SHE_GTESTX_LEVELS_10(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10), __, level11)
#define SHE_GTESTX_LEVELS_12(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12) \
  SHE_GTESTX_PP_CAT3(SHE_GTESTX_LEVELS_11(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11), __, level12)
#define SHE_GTESTX_LEVELS_13(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12, level13) \
  SHE_GTESTX_PP_CAT3(SHE_GTESTX_LEVELS_12(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12), __, level13)
#define SHE_GTESTX_LEVELS_14(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12, level13, level14) \
  SHE_GTESTX_PP_CAT3(SHE_GTESTX_LEVELS_13(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12, level13), __, level14)
#define SHE_GTESTX_LEVELS_15(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12, level13, level14, level15) \
  SHE_GTESTX_PP_CAT3(SHE_GTESTX_LEVELS_14(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12, level13, level14), __, level15)
#define SHE_GTESTX_LEVELS_16(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12, level13, level14, level15, level16) \
  SHE_GTESTX_PP_CAT3(SHE_GTESTX_LEVELS_15(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12, level13, level14, level15), __, level16)

#define SHE_GTESTX_NAME_1(level1, test_name) SHE_GTESTX_PP_CAT3(level1, __, test_name)
#define SHE_GTESTX_NAME_2(level1, level2, test_name) \
  SHE_GTESTX_PP_CAT5(level1, __, level2, __, test_name)
#define SHE_GTESTX_NAME_3(level1, level2, level3, test_name) \
  SHE_GTESTX_PP_CAT7(level1, __, level2, __, level3, __, test_name)
#define SHE_GTESTX_NAME_4(level1, level2, level3, level4, test_name) \
  SHE_GTESTX_PP_CAT9(level1, __, level2, __, level3, __, level4, __, test_name)
#define SHE_GTESTX_NAME_5(level1, level2, level3, level4, level5, test_name) \
  SHE_GTESTX_PP_CAT11(level1, __, level2, __, level3, __, level4, __, level5, __, test_name)
#define SHE_GTESTX_NAME_6(level1, level2, level3, level4, level5, level6, test_name) \
  SHE_GTESTX_PP_CAT3(SHE_GTESTX_LEVELS_6(level1, level2, level3, level4, level5, level6), __, test_name)
#define SHE_GTESTX_NAME_7(level1, level2, level3, level4, level5, level6, level7, test_name) \
  SHE_GTESTX_PP_CAT3(SHE_GTESTX_LEVELS_7(level1, level2, level3, level4, level5, level6, level7), __, test_name)
#define SHE_GTESTX_NAME_8(level1, level2, level3, level4, level5, level6, level7, level8, test_name) \
  SHE_GTESTX_PP_CAT3(SHE_GTESTX_LEVELS_8(level1, level2, level3, level4, level5, level6, level7, level8), __, test_name)
#define SHE_GTESTX_NAME_9(level1, level2, level3, level4, level5, level6, level7, level8, level9, test_name) \
  SHE_GTESTX_PP_CAT3(SHE_GTESTX_LEVELS_9(level1, level2, level3, level4, level5, level6, level7, level8, level9), __, test_name)
#define SHE_GTESTX_NAME_10(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, test_name) \
  SHE_GTESTX_PP_CAT3(SHE_GTESTX_LEVELS_10(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10), __, test_name)
#define SHE_GTESTX_NAME_11(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, test_name) \
  SHE_GTESTX_PP_CAT3(SHE_GTESTX_LEVELS_11(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11), __, test_name)
#define SHE_GTESTX_NAME_12(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12, test_name) \
  SHE_GTESTX_PP_CAT3(SHE_GTESTX_LEVELS_12(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12), __, test_name)
#define SHE_GTESTX_NAME_13(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12, level13, test_name) \
  SHE_GTESTX_PP_CAT3(SHE_GTESTX_LEVELS_13(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12, level13), __, test_name)
#define SHE_GTESTX_NAME_14(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12, level13, level14, test_name) \
  SHE_GTESTX_PP_CAT3(SHE_GTESTX_LEVELS_14(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12, level13, level14), __, test_name)
#define SHE_GTESTX_NAME_15(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12, level13, level14, level15, test_name) \
  SHE_GTESTX_PP_CAT3(SHE_GTESTX_LEVELS_15(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12, level13, level14, level15), __, test_name)
#define SHE_GTESTX_NAME_16(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12, level13, level14, level15, level16, test_name) \
  SHE_GTESTX_PP_CAT3(SHE_GTESTX_LEVELS_16(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12, level13, level14, level15, level16), __, test_name)

#define SHE_GTESTX_TEST_1(level1, test_name) TEST(SHE_GTESTX_LEVELS_1(level1), test_name)
#define SHE_GTESTX_TEST_2(level1, level2, test_name) TEST(SHE_GTESTX_LEVELS_2(level1, level2), test_name)
#define SHE_GTESTX_TEST_3(level1, level2, level3, test_name) \
  TEST(SHE_GTESTX_LEVELS_3(level1, level2, level3), test_name)
#define SHE_GTESTX_TEST_4(level1, level2, level3, level4, test_name) \
  TEST(SHE_GTESTX_LEVELS_4(level1, level2, level3, level4), test_name)
#define SHE_GTESTX_TEST_5(level1, level2, level3, level4, level5, test_name) \
  TEST(SHE_GTESTX_LEVELS_5(level1, level2, level3, level4, level5), test_name)
#define SHE_GTESTX_TEST_6(level1, level2, level3, level4, level5, level6, test_name) \
  TEST(SHE_GTESTX_LEVELS_6(level1, level2, level3, level4, level5, level6), test_name)
#define SHE_GTESTX_TEST_7(level1, level2, level3, level4, level5, level6, level7, test_name) \
  TEST(SHE_GTESTX_LEVELS_7(level1, level2, level3, level4, level5, level6, level7), test_name)
#define SHE_GTESTX_TEST_8(level1, level2, level3, level4, level5, level6, level7, level8, test_name) \
  TEST(SHE_GTESTX_LEVELS_8(level1, level2, level3, level4, level5, level6, level7, level8), test_name)
#define SHE_GTESTX_TEST_9(level1, level2, level3, level4, level5, level6, level7, level8, level9, test_name) \
  TEST(SHE_GTESTX_LEVELS_9(level1, level2, level3, level4, level5, level6, level7, level8, level9), test_name)
#define SHE_GTESTX_TEST_10(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, test_name) \
  TEST(SHE_GTESTX_LEVELS_10(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10), test_name)
#define SHE_GTESTX_TEST_11(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, test_name) \
  TEST(SHE_GTESTX_LEVELS_11(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11), test_name)
#define SHE_GTESTX_TEST_12(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12, test_name) \
  TEST(SHE_GTESTX_LEVELS_12(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12), test_name)
#define SHE_GTESTX_TEST_13(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12, level13, test_name) \
  TEST(SHE_GTESTX_LEVELS_13(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12, level13), test_name)
#define SHE_GTESTX_TEST_14(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12, level13, level14, test_name) \
  TEST(SHE_GTESTX_LEVELS_14(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12, level13, level14), test_name)
#define SHE_GTESTX_TEST_15(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12, level13, level14, level15, test_name) \
  TEST(SHE_GTESTX_LEVELS_15(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12, level13, level14, level15), test_name)
#define SHE_GTESTX_TEST_16(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12, level13, level14, level15, level16, test_name) \
  TEST(SHE_GTESTX_LEVELS_16(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12, level13, level14, level15, level16), test_name)

#define SHE_GTESTX_TEST_F_1(fixture, level1, test_name) \
  TEST_F(fixture, SHE_GTESTX_NAME_1(level1, test_name))
#define SHE_GTESTX_TEST_F_2(fixture, level1, level2, test_name) \
  TEST_F(fixture, SHE_GTESTX_NAME_2(level1, level2, test_name))
#define SHE_GTESTX_TEST_F_3(fixture, level1, level2, level3, test_name) \
  TEST_F(fixture, SHE_GTESTX_NAME_3(level1, level2, level3, test_name))
#define SHE_GTESTX_TEST_F_4(fixture, level1, level2, level3, level4, test_name) \
  TEST_F(fixture, SHE_GTESTX_NAME_4(level1, level2, level3, level4, test_name))
#define SHE_GTESTX_TEST_F_5(fixture, level1, level2, level3, level4, level5, test_name) \
  TEST_F(fixture, SHE_GTESTX_NAME_5(level1, level2, level3, level4, level5, test_name))
#define SHE_GTESTX_TEST_F_6(fixture, level1, level2, level3, level4, level5, level6, test_name) \
  TEST_F(fixture, SHE_GTESTX_NAME_6(level1, level2, level3, level4, level5, level6, test_name))
#define SHE_GTESTX_TEST_F_7(fixture, level1, level2, level3, level4, level5, level6, level7, test_name) \
  TEST_F(fixture, SHE_GTESTX_NAME_7(level1, level2, level3, level4, level5, level6, level7, test_name))
#define SHE_GTESTX_TEST_F_8(fixture, level1, level2, level3, level4, level5, level6, level7, level8, test_name) \
  TEST_F(fixture, SHE_GTESTX_NAME_8(level1, level2, level3, level4, level5, level6, level7, level8, test_name))
#define SHE_GTESTX_TEST_F_9(fixture, level1, level2, level3, level4, level5, level6, level7, level8, level9, test_name) \
  TEST_F(fixture, SHE_GTESTX_NAME_9(level1, level2, level3, level4, level5, level6, level7, level8, level9, test_name))
#define SHE_GTESTX_TEST_F_10(fixture, level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, test_name) \
  TEST_F(fixture, SHE_GTESTX_NAME_10(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, test_name))
#define SHE_GTESTX_TEST_F_11(fixture, level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, test_name) \
  TEST_F(fixture, SHE_GTESTX_NAME_11(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, test_name))
#define SHE_GTESTX_TEST_F_12(fixture, level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12, test_name) \
  TEST_F(fixture, SHE_GTESTX_NAME_12(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12, test_name))
#define SHE_GTESTX_TEST_F_13(fixture, level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12, level13, test_name) \
  TEST_F(fixture, SHE_GTESTX_NAME_13(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12, level13, test_name))
#define SHE_GTESTX_TEST_F_14(fixture, level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12, level13, level14, test_name) \
  TEST_F(fixture, SHE_GTESTX_NAME_14(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12, level13, level14, test_name))
#define SHE_GTESTX_TEST_F_15(fixture, level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12, level13, level14, level15, test_name) \
  TEST_F(fixture, SHE_GTESTX_NAME_15(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12, level13, level14, level15, test_name))
#define SHE_GTESTX_TEST_F_16(fixture, level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12, level13, level14, level15, level16, test_name) \
  TEST_F(fixture, SHE_GTESTX_NAME_16(level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, level11, level12, level13, level14, level15, level16, test_name))

#define SHE_GTESTX_TEST_SELECT_2 SHE_GTESTX_TEST_1
#define SHE_GTESTX_TEST_SELECT_3 SHE_GTESTX_TEST_2
#define SHE_GTESTX_TEST_SELECT_4 SHE_GTESTX_TEST_3
#define SHE_GTESTX_TEST_SELECT_5 SHE_GTESTX_TEST_4
#define SHE_GTESTX_TEST_SELECT_6 SHE_GTESTX_TEST_5
#define SHE_GTESTX_TEST_SELECT_7 SHE_GTESTX_TEST_6
#define SHE_GTESTX_TEST_SELECT_8 SHE_GTESTX_TEST_7
#define SHE_GTESTX_TEST_SELECT_9 SHE_GTESTX_TEST_8
#define SHE_GTESTX_TEST_SELECT_10 SHE_GTESTX_TEST_9
#define SHE_GTESTX_TEST_SELECT_11 SHE_GTESTX_TEST_10
#define SHE_GTESTX_TEST_SELECT_12 SHE_GTESTX_TEST_11
#define SHE_GTESTX_TEST_SELECT_13 SHE_GTESTX_TEST_12
#define SHE_GTESTX_TEST_SELECT_14 SHE_GTESTX_TEST_13
#define SHE_GTESTX_TEST_SELECT_15 SHE_GTESTX_TEST_14
#define SHE_GTESTX_TEST_SELECT_16 SHE_GTESTX_TEST_15
#define SHE_GTESTX_TEST_SELECT_17 SHE_GTESTX_TEST_16
#define SHE_GTESTX_TEST_SELECT_(count) SHE_GTESTX_PP_CAT(SHE_GTESTX_TEST_SELECT_, count)
#define SHE_GTESTX_TEST_SELECT(count) SHE_GTESTX_TEST_SELECT_(count)
#define SHE_GTESTX_TEST(...) SHE_GTESTX_PP_EXPAND(SHE_GTESTX_TEST_SELECT(SHE_GTESTX_PP_NARG(__VA_ARGS__))(__VA_ARGS__))

#define SHE_GTESTX_TEST_F_SELECT_3 SHE_GTESTX_TEST_F_1
#define SHE_GTESTX_TEST_F_SELECT_4 SHE_GTESTX_TEST_F_2
#define SHE_GTESTX_TEST_F_SELECT_5 SHE_GTESTX_TEST_F_3
#define SHE_GTESTX_TEST_F_SELECT_6 SHE_GTESTX_TEST_F_4
#define SHE_GTESTX_TEST_F_SELECT_7 SHE_GTESTX_TEST_F_5
#define SHE_GTESTX_TEST_F_SELECT_8 SHE_GTESTX_TEST_F_6
#define SHE_GTESTX_TEST_F_SELECT_9 SHE_GTESTX_TEST_F_7
#define SHE_GTESTX_TEST_F_SELECT_10 SHE_GTESTX_TEST_F_8
#define SHE_GTESTX_TEST_F_SELECT_11 SHE_GTESTX_TEST_F_9
#define SHE_GTESTX_TEST_F_SELECT_12 SHE_GTESTX_TEST_F_10
#define SHE_GTESTX_TEST_F_SELECT_13 SHE_GTESTX_TEST_F_11
#define SHE_GTESTX_TEST_F_SELECT_14 SHE_GTESTX_TEST_F_12
#define SHE_GTESTX_TEST_F_SELECT_15 SHE_GTESTX_TEST_F_13
#define SHE_GTESTX_TEST_F_SELECT_16 SHE_GTESTX_TEST_F_14
#define SHE_GTESTX_TEST_F_SELECT_17 SHE_GTESTX_TEST_F_15
#define SHE_GTESTX_TEST_F_SELECT_18 SHE_GTESTX_TEST_F_16
#define SHE_GTESTX_TEST_F_SELECT_(count) SHE_GTESTX_PP_CAT(SHE_GTESTX_TEST_F_SELECT_, count)
#define SHE_GTESTX_TEST_F_SELECT(count) SHE_GTESTX_TEST_F_SELECT_(count)
#define SHE_GTESTX_TEST_F(fixture, ...) \
  SHE_GTESTX_PP_EXPAND(SHE_GTESTX_TEST_F_SELECT(SHE_GTESTX_PP_NARG(fixture, __VA_ARGS__))(fixture, __VA_ARGS__))

namespace she_gtestx {

inline constexpr int kVersionMajor = 0;
inline constexpr int kVersionMinor = 1;
inline constexpr int kVersionPatch = 0;

}  // namespace she_gtestx

#endif  // SHE_GTESTX_SHE_GTESTX_H_
