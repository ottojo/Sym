/**
 * @file Constant.cpp
 * @author paul
 * @date 25.08.20
 * Description here TODO
 */

#include "Symbolic/Constant.hpp"

#include <gtest/gtest.h>

TEST(Constant, Expression) {
    EXPECT_TRUE((sym::IsExpression<sym::Constant<int>>::val));
}

TEST(Constant, Resolve) {
    sym::Constant<int> c{42};

    EXPECT_EQ(c.resolve(), 42);
}

TEST(Constant, GradResolve) {
    sym::Constant<int> c{42};

    EXPECT_EQ(sym::gradient(c, sym::Variable<int>{0}).resolve(), 0);
}

TEST(Constant, IsConstant) {
    EXPECT_TRUE(sym::Constant<int>::isConstant());
}
