/**
 * @file Greater.hpp
 * @author paul
 * @date 17.11.21
 * Description here TODO
 */
#ifndef SYM_GREATER_HPP
#define SYM_GREATER_HPP

#include "../Expression.hpp"

namespace sym {
    template<Expression Lhs, Expression Rhs>
    class Greater {
      public:
        constexpr explicit Greater(Lhs lhs, Rhs rhs) : lhs{lhs}, rhs{rhs} {
        }

        template<typename... Bindings>
        constexpr auto resolve(const Bindings &...bindings) const {
            return lhs.resolve(bindings...) > rhs.resolve(bindings...);
        }

        template<Expression Lhs_, Expression Rhs_>
        friend auto toString(const Greater<Lhs_, Rhs_> &greater) -> std::string;

      private:
        Lhs lhs;
        Rhs rhs;
    };

    template<typename Lhs_, typename Rhs_>
    auto toString(const Greater<Lhs_, Rhs_> &greater) -> std::string {
        return "(" + sym::toString(greater.lhs) + ")>(" + sym::toString(greater.rhs) + ")";
    }

} // namespace sym

#endif // SYM_GREATER_HPP