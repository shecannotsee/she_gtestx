#include <string_view>

#include <she_gtestx/she_gtestx.h>

namespace {

class FixtureSample : public ::testing::Test {};

SHE_GTESTX_TEST(alpha, beta, gamma, registers_flat_suite_name) {
  EXPECT_TRUE(true);
}

SHE_GTESTX_TEST_F(FixtureSample, alpha, beta, gamma, registers_flat_test_name) {
  EXPECT_TRUE(true);
}

SHE_GTESTX_TEST(level01,
                level02,
                level03,
                level04,
                level05,
                level06,
                level07,
                level08,
                level09,
                level10,
                level11,
                level12,
                level13,
                level14,
                level15,
                level16,
                supports_sixteen_level_suite_names) {
  EXPECT_TRUE(true);
}

SHE_GTESTX_TEST_F(FixtureSample,
                  level01,
                  level02,
                  level03,
                  level04,
                  level05,
                  level06,
                  level07,
                  level08,
                  level09,
                  level10,
                  level11,
                  level12,
                  level13,
                  level14,
                  level15,
                  level16,
                  supports_sixteen_level_fixture_names) {
  EXPECT_TRUE(true);
}

auto has_registered_test(std::string_view suite_name, std::string_view test_name) -> bool {
  const auto* unit_test = ::testing::UnitTest::GetInstance();
  for (int suite_index = 0; suite_index < unit_test->total_test_suite_count(); ++suite_index) {
    const auto* suite = unit_test->GetTestSuite(suite_index);
    if (suite_name != suite->name()) {
      continue;
    }
    for (int test_index = 0; test_index < suite->total_test_count(); ++test_index) {
      const auto* test = suite->GetTestInfo(test_index);
      if (test_name == test->name()) {
        return true;
      }
    }
  }
  return false;
}

}  // namespace

TEST(SheGtestxHeader, ExposesVersionConstants) {
  EXPECT_EQ(she_gtestx::kVersionMajor, 0);
  EXPECT_EQ(she_gtestx::kVersionMinor, 1);
  EXPECT_EQ(she_gtestx::kVersionPatch, 0);
}

TEST(SheGtestxRegistration, FlattensHierarchicalSuiteNames) {
  EXPECT_TRUE(has_registered_test("alpha__beta__gamma", "registers_flat_suite_name"));
}

TEST(SheGtestxRegistration, FlattensHierarchicalFixtureTestNames) {
  EXPECT_TRUE(has_registered_test("FixtureSample", "alpha__beta__gamma__registers_flat_test_name"));
}

TEST(SheGtestxRegistration, SupportsSixteenLevelSuiteNames) {
  EXPECT_TRUE(has_registered_test("level01__level02__level03__level04__level05__level06__level07__level08__level09__level10__level11__level12__level13__level14__level15__level16",
                                  "supports_sixteen_level_suite_names"));
}

TEST(SheGtestxRegistration, SupportsSixteenLevelFixtureNames) {
  EXPECT_TRUE(has_registered_test("FixtureSample",
                                  "level01__level02__level03__level04__level05__level06__level07__level08__level09__level10__level11__level12__level13__level14__level15__level16__supports_sixteen_level_fixture_names"));
}
