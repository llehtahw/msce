#include <iostream>
#include <sstream>
template <size_t...Sz>
struct value_list { };

template <size_t S, size_t...Sz>
struct value_list<S, Sz...> { };


template <typename, typename> struct value_list_cat;
template <size_t...Sz1, size_t...Sz2>
struct value_list_cat <value_list<Sz1...>, value_list<Sz2...>> {
    using type = value_list<Sz1..., Sz2...>;
};


template <typename, typename> struct value_list_intersect;
template <size_t H1, size_t H2, size_t...Sz1, size_t...Sz2>
struct value_list_intersect <value_list<H1, Sz1...>, value_list<H2, Sz2...>> {
    static_assert(sizeof...(Sz1) == sizeof...(Sz2), "wtf???");
    using type = typename value_list_cat<
        value_list<H1, H2>,
        typename value_list_intersect<value_list<Sz1...>, value_list<Sz2...>>::type
    >::type;
};

template <>
struct value_list_intersect<value_list<>, value_list<>> {
    using type = value_list<>;
};


template <size_t, typename> struct value_list_get;

template <size_t Head, size_t...Sz>
struct value_list_get<0, value_list<Head, Sz...>> {
    static constexpr size_t value = Head;
};

template <size_t N, size_t Head, size_t...Sz>
struct value_list_get<N, value_list<Head, Sz...>> : value_list_get<N-1, value_list<Sz...>> {
    static_assert(N <= sizeof...(Sz), "wtf???");
};


template <typename> struct value_list_reverse;

template <>
struct value_list_reverse<value_list<>> {
    using type = value_list<>;
};

template <size_t Head, size_t...Sz>
struct value_list_reverse<value_list<Head, Sz...>> :
    value_list_cat<typename value_list_reverse<value_list<Sz...>>::type, value_list<Head>> { };


template <typename> struct value_list_sort;

namespace details {
    template <typename, size_t, typename> struct sort_insert;
    template <size_t...Ns0, size_t N, size_t Head, size_t...Ns1>
    struct sort_insert<value_list<Ns0...>, N, value_list<Head, Ns1...>> {
        using type = typename std::conditional<
            N <= Head,
              value_list<Ns0..., N, Head, Ns1...>,
              typename sort_insert<value_list<Ns0..., Head>, N, value_list<Ns1...>>::type
        >::type;
    };

    template <size_t...Ns0, size_t N>
    struct sort_insert<value_list<Ns0...>, N, value_list<>> {
        using type = value_list<Ns0..., N>;
    };
}

template <>
struct value_list_sort<value_list<>> {
    using type = value_list<>;
};

template <size_t Head, size_t...Sz>
struct value_list_sort<value_list<Head, Sz...>> : details::sort_insert<value_list<>, Head, typename value_list_sort<value_list<Sz...>>::type>{ };


template <size_t...Sz>
std::string value_list_to_string(value_list<Sz...>) {
    std::stringstream ss;
    ss << "value_list<";
    size_t i = 0;
    char n[] = {
        ((ss << Sz << (++i == sizeof...(Sz) ? "" : ", ")), '\0')...
    };
    (void)n;
    ss << ">";
    return ss.str();
}
