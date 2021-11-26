﻿
#ifndef BASIC_PROPERTY
#define BASIC_PROPERTY

#include <Definition/Concepts.hpp>
#include <functional>

namespace spesium {
    template<typename T>
    class BasicProperty {
       public:
        using value_type = T;
        using reference = value_type&;
        using const_reference = const value_type&;
        using rvalue_reference = value_type&&;
        using const_property_reference = const BasicProperty<value_type>&;
        using index_type = const uint64_t&;

       public:
        /// @brief プロパティ
        /// @param target プロパティを適用する変数
        /// @param getter ゲッターのオーバーライド
        /// @param setter セッターのオーバーライド
        explicit BasicProperty( reference target, std::function<value_type&()>&& getter = nullptr, std::function<void( value_type )>&& setter = nullptr ) noexcept :
            base( target ), get( std::move( getter ) ), set( std::move( setter ) ) {
        }

        ~BasicProperty() = default;

       public:
        [[nodiscard]] constexpr operator value_type() const {
            return Get();
        }

        /// @brief 変換可能な値にキャスト
        template<std::convertible_to<value_type> U>
        [[nodiscard]] constexpr auto Cast() const noexcept -> U {
            return static_cast<U>( base );
        }

        /// @brief メンバ選択演算子
        constexpr auto operator->() const -> decltype( auto ) {
            return &base;
        }

        /// @brief 添字演算子
        /// @n 基本的には .at などのメンバ関数を使うべき
        template<typename U = value_type>
        constexpr auto operator[]( index_type index ) const -> decltype( std::declval<U>()[std::declval<index_type>()] ) {
            return base[index];
        }

        /// @brief 後置インクリメント
        template<typename U = value_type>
        constexpr auto operator++( int ) & noexcept -> reference requires concepts::post_increment_to<U> {
            auto pre { base };
            base++;
            return pre;
        }

        /// @brief 後置デクリメント
        template<typename U = value_type>
        constexpr auto operator--( int ) & noexcept -> reference requires concepts::post_decrement_to<U> {
            auto pre { base };
            base--;
            return pre;
        }

        /// @brief 前置インクリメント
        template<typename U = value_type>
        constexpr auto operator++() & noexcept -> reference requires concepts::pre_increment_to<U> {
            ++base;
            return base;
        }

        /// @brief 前置デクリメント
        template<typename U = value_type>
        constexpr auto operator--() & noexcept -> reference requires concepts::pre_decrement_to<U> {
            --base;
            return base;
        }

        /// @brief 論理否定演算子
        [[nodiscard]] constexpr auto operator!() const -> bool requires std::convertible_to<bool, value_type> {
            return !static_cast<bool>( base );
        }

        /// @brief 単項プラス演算子
        constexpr auto operator+() const noexcept -> reference {
            return *this;
        }

        /// @brief 単項マイナス演算子
        constexpr auto operator-() const -> value_type {
            return std::negate()( base );
        }

        /// @brief 関節参照演算子
        [[nodiscard]] constexpr auto operator*() const noexcept -> reference {
            return base;
        }

        /// @brief 代入演算子
        constexpr auto operator=( const_reference value ) & -> reference {
            Set( value );
            return base;
        }

        /// @brief 代入演算子
        constexpr auto operator=( const_property_reference value ) & -> reference {
            Set( value.base );
            return base;
        }

        /// @brief ムーブ代入演算子
        constexpr auto operator=( rvalue_reference value ) & noexcept -> reference {
            Set( std::move( value ) );
            return base;
        }

        /// @brief 複合代入演算子
        template<typename U = value_type>
        constexpr auto operator+=( const U& value ) -> reference requires concepts::add_to<value_type, U> {
            base += value;
            return base;
        }

        /// @brief 複合代入演算子
        template<typename U = value_type>
        constexpr auto operator-=( const U& value ) -> reference requires concepts::subtract_to<value_type, U> {
            base -= value;
            return base;
        }

        /// @brief 複合代入演算子
        template<typename U = value_type>
        constexpr auto operator*=( const U& value ) -> reference requires concepts::multiplication_to<value_type, U> {
            base *= value;
            return base;
        }

        /// @brief 複合代入演算子
        template<typename U = value_type>
        constexpr auto operator/=( const U& value ) -> reference requires concepts::division_to<value_type, U> {
            base /= value;
            return base;
        }

        /// @brief 複合代入演算子
        template<typename U = value_type>
        constexpr auto operator%=( const U& value ) -> reference requires concepts::modulo_to<value_type, U> {
            base %= value;
            return base;
        }

        /// @brief 複合代入演算子
        template<typename U = value_type>
        constexpr auto operator<<=( const U& value ) -> reference requires concepts::left_shift_to<value_type, U> {
            base <<= value;
            return base;
        }

        /// @brief 複合代入演算子
        template<typename U = value_type>
        constexpr auto operator>>=( const U& value ) -> reference requires concepts::right_shift_to<value_type, U> {
            base >>= value;
            return base;
        }

        [[nodiscard]] constexpr auto Get() const -> reference {
            return ( get ) ? get() : base;
        }

        constexpr void Set( const_reference value ) {
            if ( set ) { set( value ); }
            else {
                base = value;
            }
        }

       private:
        reference base;
        std::function<value_type&()> get { nullptr };
        std::function<void( value_type )> set { nullptr };
    };
}  // namespace spesium

#endif  // !BASIC_PROPERTY
