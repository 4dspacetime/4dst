#ifndef MATH_HPP
#define MATH_HPP
#define _val(name, val) constexpr ldouble name = val
#define _si_unit(name)\
struct name\
{\
    ldouble data;\
    name()                   : data(0)    {}\
    name(const ldouble data) : data(data) {}\
}
#define _si_base_unit(name) si_unit(name)
#define _si_pfx(name, time)\
constexpr ldouble operator""##name(const ldouble val)\
{ return val * time; }
namespace math
{
    using ldouble = long double;
    // inline namespace val
    // {
    _val(e,         2.718281828459045235360287471352662l);
    _val(log2e,     1.442695040888963407359924681001892l);
    _val(lge,       0.434294481903251827651128918916605l);
    _val(ln2,       0.693147180559945309417232121458176l);
    _val(ln10,      2.302585092994045684017991454684364l);
    _val(pi,        3.141592653589793238462643383279503l);
    _val(pi_2,      1.570796326794896619231321691639751l);
    _val(pi_4,      0.785398163397448309615660845819876l);
    _val(_1_pi,     0.318309886183790671537767526745029l);
    _val(_2_pi,     0.636619772367581343075535053490057l);
    _val(_2_sqrtpi, 1.128379167095512573896158903121545l);
    _val(sqrt2,     1.414213562373095048801688724209698l);
    _val(sqrt1_2,   0.707106781186547524400844362104849l);
    // }
    // inline namespace si_base_unit
    // {
    _si_base_unit(metre);
    _si_base_unit(kilo);
    _si_base_unit(second);
    _si_base_unit(ampere);
    _si_base_unit(kelvin);
    _si_base_unit(mole);
    _si_base_unit(candela);
    // }
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