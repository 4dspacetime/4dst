#ifndef TYPE_HPP
#define TYPE_HPP
#if __cplusplus < 202302
#include "compat/type.h++"
#else
#include <any>
#include <array>
#include <atomic>
#include <bitset>
#include <deque>
#include <exception>
#include <expected>
#include <forward_list>
#include <initializer_list>
#include <list>
#include <map>
#include <mdspan>
#include <memory>
#include <optional>
#include <set>
#include <source_location>
#include <span>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <variant>
#include <vector>
#include <version>
#ifdef __cpp_lib_flat_map
#include <flat_map>
#endif
#ifdef __cpp_lib_flat_set
#include <flat_set>
#endif
#define tpl_t    template <class type> using
#define tpl_va_t template <class ...type> using
#define tpl2_t   template <class type, class type2> using
#define tpl_ts_t template <class type, std::size_t size> using
namespace type
{
    // inline namespace cntr
    // {
    using int_t          = long long;
    using uint_t         = unsigned long long;
    using flt_t          = long double;
    tpl_t vol_t          = std::atomic<type>;
    tpl_ts_t stat_arr_t  = std::array<type, size>;
    tpl_t dyn_arr_t      = std::vector<type>;
    tpl_t deque_t        = std::deque<type>;
    tpl_t lst_t          = std::forward_list<type>;
    tpl_t delst_t        = std::list<type>;
    tpl_t set_t          = std::set<type>;
    tpl2_t map_t         = std::map<type, type2>;
    tpl_t mltset_t       = std::multiset<type>;
    tpl2_t mltmap_t      = std::multimap<type, type2>;
    tpl_t hsh_set_t      = std::unordered_set<type>;
    tpl2_t hsh_map_t     = std::unordered_map<type, type2>;
    tpl_t hsh_mltset_t   = std::unordered_multiset<type>;
    tpl2_t hsh_mltmap_t  = std::unordered_multimap<type, type2>;
#ifdef __cpp_lib_flat_map
    tpl2_t flt_map_t     = std::flat_map<type, type2>;
    tpl2_t flt_mltmap_t  = std::flat_multimap<type, type2>;
#endif
#ifdef __cpp_lib_flat_set
    tpl_t flt_set_t      = std::flat_set<type>;
    tpl_t flt_mltset_t   = std::flat_multiset<type>;
#endif
    tpl_t spn_t          = std::span<type>;
    template <class type, std::size_t ...size>
    using stat_mdspn_t   = std::mdspan<type,
        std::extents<std::size_t, size...>>;
    tpl_ts_t dyn_mdspn_t = std::mdspan<type,
        std::dextents<std::size_t, size>>;
    // }
    // inline namespace util
    // {
    tpl_t uniq_ptr_t     = std::unique_ptr<type>;
    tpl_t shrd_ptr_t     = std::shared_ptr<type>;
    tpl_t wk_ptr_t       = std::weak_ptr<type>;
    using ex_t           = std::exception;
    tpl_t init_lst_t     = std::initializer_list<type>;
    using src_loc        = std::source_location;
    tpl2_t pr_t          = std::pair<type, type2>;
    tpl_va_t tup_t       = std::tuple<type...>;
    tpl_t opt_t          = std::optional<type>;
    tpl2_t exp_t         = std::expected<type, type2>;
    tpl_va_t var_t       = std::variant<type...>;
    using any_t          = std::any;
    template <size_t size>
    using bitset_t       = std::bitset<size>;
    // }
}
#endif
#endif
