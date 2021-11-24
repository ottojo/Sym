#include <Symbolic/Operators.hpp>
#include <Symbolic/Simplifier/CompileTime.hpp>
#include <gtest/gtest.h>

TEST(Simplifier, MergeConstant) {
    sym::CompiletimeConstant<int, 1> a;
    sym::CompiletimeConstant<int, 2> b;
    auto sum = a + b;

    auto newSum = sym::simplifier::MergeConstant<decltype(sum)>::newVal;

    EXPECT_TRUE((std::is_same_v<decltype(newSum), sym::CompiletimeConstant<int, 3>>) );
}

TEST(Simplifier, MergeIdentity) {
    sym::Variable<'a'> a;
    sym::CompiletimeConstant<int, 0> b;
    auto sum = a + b;

    EXPECT_TRUE(sym::simplifier::MergeIdentity<decltype(sum)>::status == sym::simplifier::MergeStatus::KEEP_LHS);
}

TEST(Simplifier, MergeDisappear) {
    sym::Variable<'a'> a;
    sym::CompiletimeConstant<int, 0> b;
    auto prod = a * b;
    auto simplified = sym::simplifier::MergeDisappear<decltype(prod)>::newVal;

    EXPECT_TRUE((std::is_same_v<decltype(simplified), sym::CompiletimeConstant<int, 0>>) );
}