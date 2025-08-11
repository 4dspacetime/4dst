#ifndef COMPAT_FUNC_HPP
#define COMPAT_FUNC_HPP
#include <atomic>
#include <chrono>
#include <functional>
#include <iostream>
#include <string>
namespace func
{
    using namespace std::chrono;
    using func_t  = std::function<void ()>;
    using desc_t  = std::string;
    using time_t  = nanoseconds;
    using clock_t = high_resolution_clock;
    using ullong  = unsigned long long;
    // inline namespace cls
    // {
    struct wrp
    {
        func_t body, cstr, dstr;
        desc_t desc;
        wrp
        (
            const func_t body,
            const func_t cstr = [] {},
            const func_t dstr = [] {},
            const desc_t desc = "wrp"
        ) : body(body), cstr(cstr), dstr(dstr), desc(desc) {}
        void operator()() const
        {
            cstr();
            body();
            dstr();
        }
    };
    struct tmr
    {
        func_t body;
        desc_t desc;
        tmr
        (
            const func_t body,
            const desc_t desc = "tmr"
        ) : body(body), desc(desc) {}
        time_t operator()() const
        {
            const time_point<clock_t> begin = clock_t::now();
            body();
            return clock_t::now() - begin;
        }
    };
    struct dbg
    {
        func_t body;
        desc_t desc;
        dbg
        (
            const func_t body,
            const desc_t desc = "dbg"
        ) : body(body), desc(desc) {}
        void operator()() const
        {
            std::cout << "File: " << __FILE__ << '.' << std::endl;
            std::cout << "Line: " << __LINE__ << '.' << std::endl;
            std::cout << "Beginning of " << desc << '.' << std::endl;
            body();
            std::cout << "End of       " << desc << '.' << std::endl;
        }
    };
    // }
    // inline namespace func
    // {
    void if_else
    (
        const bool cond,
        const func_t func1,
        const func_t func0 = [] {}
    )
    {
        cond ? func1() : func0();
    }
    void loop
    (
        const ullong i,
        const func_t func = [] {}
    )
    {
        for (std::atomic_ullong j(0); j < i; j++)
            func();
    }
    void loop
    (
        const ullong i,
        const std::function<void (const ullong)> func
    )
    {
        for (std::atomic_ullong j(0); j < i; j++)
            func(j);
    }
    [[noreturn]] void inf_loop(const func_t func = [] {})
    {
        for (;;)
            func();
    }
    // }
}
#endif