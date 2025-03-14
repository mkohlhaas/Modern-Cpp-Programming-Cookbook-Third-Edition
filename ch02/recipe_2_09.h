#pragma once

#include <array>
#include <chrono>
#include <complex>

namespace recipe_2_09
{
    namespace compunits
    {
        constexpr size_t
        operator"" _KB(unsigned long long const size)
        {
            return static_cast<size_t>(size * 1024);
        }
    } // namespace compunits

    inline void
    examples_kb()
    {
        using namespace compunits;

        [[maybe_unused]] auto size{4_KB};                        // size_t

        using byte                   = unsigned char;
        [[maybe_unused]] auto buffer = std::array<byte, 1_KB>{}; // std::array<unsigned char, 1024>
    }

    namespace units
    {
        enum class unit
        {
            kilogram,
            liter,
            meter,
            piece,
        };

        template <unit U>
        class quantity
        {
            const double amount;

          public:
            constexpr explicit quantity(double const a) : amount(a)
            {
            }

            explicit
            operator double() const
            {
                return amount;
            }
        };

        template <unit U>
        constexpr quantity<U>
        operator+(quantity<U> const &q1, quantity<U> const &q2)
        {
            return quantity<U>(static_cast<double>(q1) + static_cast<double>(q2));
        }

        template <unit U>
        constexpr quantity<U>
        operator-(quantity<U> const &q1, quantity<U> const &q2)
        {
            return quantity<U>(static_cast<double>(q1) - static_cast<double>(q2));
        }

        namespace unit_literals
        {
            constexpr quantity<unit::kilogram> operator"" _kg(long double const amount)
            {
                return quantity<unit::kilogram>{static_cast<double>(amount)};
            }

            constexpr quantity<unit::kilogram> operator"" _kg(unsigned long long const amount)
            {
                return quantity<unit::kilogram>{static_cast<double>(amount)};
            }

            constexpr quantity<unit::liter> operator"" _l(long double const amount)
            {
                return quantity<unit::liter>{static_cast<double>(amount)};
            }

            constexpr quantity<unit::meter> operator"" _m(long double const amount)
            {
                return quantity<unit::meter>{static_cast<double>(amount)};
            }

            constexpr quantity<unit::piece> operator"" _pcs(unsigned long long const amount)
            {
                return quantity<unit::piece>{static_cast<double>(amount)};
            }
        } // namespace unit_literals
    } // namespace units

    inline void
    example_units()
    {
        using namespace units;
        using namespace unit_literals;

        auto                  q1{1_kg};
        auto                  q2{4.5_kg};
        [[maybe_unused]] auto q3{q1 + q2};
        [[maybe_unused]] auto q4{q2 - q1};

        // auto q5{ 1.0_m + 1_pcs }; // error, cannot add meters and pieces
        // auto q6{ 1_l };   // error, cannot have an integer number of liters
        // auto q7{ 2.0_pcs } // error, can only have an integer number of pieces
    }

    inline void
    execute()
    {
        {
            [[maybe_unused]] auto b{true};    // boolean
            [[maybe_unused]] auto s{"text"};  // const char[7]
            [[maybe_unused]] auto i{42};      // int
            [[maybe_unused]] auto d{42.5};    // double
            [[maybe_unused]] auto p{nullptr}; // nullptr_t

                                              // with prefixes
            [[maybe_unused]] auto t1{L"text"};           // const wchar_t[5]
            [[maybe_unused]] auto t2{LR"(has ' and ")"}; // const wchar_t[5]
            [[maybe_unused]] auto hx{0xBAD};             // int (in hexadecimal representation)

                                                         // with suffixes
            [[maybe_unused]] auto a{42u};   // unsigned int
            [[maybe_unused]] auto l{42l};   // signed long
            [[maybe_unused]] auto f{42.5f}; // float
        }

        {
            using namespace std::string_literals;
            auto s1{"text"s};                   // std::string
            auto s2{L"text"s};                  // std::wstring
            auto s3{u"text"s};                  // std::u16string
            auto s4{U"text"s};                  // std::u32string

            using namespace std::string_view_literals;
            [[maybe_unused]] auto s5{"text"sv}; // std::string_view
        }

        {
            using namespace std::chrono_literals;
            [[maybe_unused]] auto timer{2h + 42min + 15s}; // std::chrono::duration<long long>
        }

        {
            using namespace std::complex_literals;
            [[maybe_unused]] auto c{12.0 + 4.5i}; // std::complex<double>
        }

        examples_kb();

        example_units();
    }
} // namespace recipe_2_09
