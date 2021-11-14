/**
 * @file Constant.hpp
 * @author paul
 * @date 25.08.20
 * Description here TODO
 */
#ifndef SYM_COMPILETIMECONSTANT_HPP
#define SYM_COMPILETIMECONSTANT_HPP

#include "Expression.hpp"
#include "Variable.hpp"

namespace sym {
    template<std::size_t ID>
    class Variable;

    template<typename T, T val_>
    class CompiletimeConstant {
        static constexpr auto val = val_;

      public:
        template<typename... Bindings>
        constexpr auto resolve(Bindings...) const -> T;

        template<typename T_, T_ val0, std::size_t ID>
        friend constexpr auto gradient(const CompiletimeConstant<T_, val0> &, const Variable<ID> &);

        template<typename T_, T_ val0>
        friend auto toString(const CompiletimeConstant<T_, val0> &x) -> std::string;
    };

    template<typename T, T val>
    template<typename... Bindings>
    constexpr auto CompiletimeConstant<T, val>::resolve(Bindings...) const -> T {
        return val;
    }

    template<typename T_, T_ val0, std::size_t ID>
    constexpr auto gradient(const CompiletimeConstant<T_, val0> &, const Variable<ID> &) {
        return CompiletimeConstant<T_, 0>{};
    }

    template<typename T_, T_ val0>
    auto toString(const CompiletimeConstant<T_, val0> &x) -> std::string {
        return std::to_string(x.val);
    }
} // namespace sym

#endif // SYM_COMPILETIMECONSTANT_HPP
