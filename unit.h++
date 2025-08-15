#ifndef UNIT_HPP
#define UNIT_HPP
#define _si_pfx(name, time)\
constexpr ldouble operator""##name(const ldouble val)\
{ return val * time; }
namespace math
{
    using ldouble = long double;
    // inline namespace si_pfx
    // {
    _si_pfx(_y,  1e-24l);
    _si_pfx(_z,  1e-21l);
    _si_pfx(_a,  1e-18l);
    _si_pfx(_f,  1e-15l);
    _si_pfx(_p,  1e-12l);
    _si_pfx(_n,  1e-9l);
    _si_pfx(_u,  1e-6l);
    _si_pfx(_m,  1e-3l);
    _si_pfx(_c,  1e-2l);
    _si_pfx(_d,  1e-1l);
    _si_pfx(_da, 1e1l);
    _si_pfx(_h,  1e2l);
    _si_pfx(_k,  1e3l);
    _si_pfx(_M,  1e6l);
    _si_pfx(_G,  1e9l);
    _si_pfx(_T,  1e12l);
    _si_pfx(_P,  1e15l);
    _si_pfx(_E,  1e18l);
    _si_pfx(_Z,  1e21l);
    _si_pfx(_Y,  1e24l);
    // }
}
#endif
