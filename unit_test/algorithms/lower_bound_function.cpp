#include "../../algorithms/lower_bound_function.cpp"


#include <functional>
#include <gtest/gtest.h>


class LowerBoundFunctionParameterizedTest : public ::testing::TestWithParam<std::tuple<int, int, std::vector<int>, int>> {};

TEST_P(LowerBoundFunctionParameterizedTest, lower_bound) {
    auto[a, b, v, target] = GetParam();

    std::function<int(int)> g = [&v](int x) { return v[(size_t)x]; };

    ASSERT_EQ(g(lower_bound_function(g, target, a, b)), *std::lower_bound(v.begin(), v.end(), target));
}

INSTANTIATE_TEST_CASE_P(
    LowerBoundFunctionParameters,
    LowerBoundFunctionParameterizedTest,
    ::testing::Values(
        std::make_tuple(0, 2, std::vector<int>{5, 10, 50}, 10),
        std::make_tuple(1, 3, std::vector<int>{1, 2, 3, 4}, 3),
        std::make_tuple(0, 2, std::vector<int>{10, 20, 30, 40, 50}, 25)
    )
);
