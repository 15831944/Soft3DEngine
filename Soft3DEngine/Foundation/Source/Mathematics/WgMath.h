///////////////////////////////////////////////////////////
//                                                       //
//                    WgMath.h                           //
//                                                       //
//  - Interface for Math class                           //
//                                                       //
//  - Written By Woong Gyu La a.k.a. Chris               //
//       on 2009.10.01                                   //
//                                                       //
///////////////////////////////////////////////////////////

#ifndef __WG_MATH_H__
#define __WG_MATH_H__

#include "WgFoundationLIB.h"
#include "WgSystem.h"

namespace WGSoft3D
{

template <class Real>
class Math
{
public:
    // Wrappers to hide implementations of functions.  The ACos and ASin
    // functions clamp the input argument to [-1,1] to avoid NaN issues
    // when the input is slightly larger than 1 or slightly smaller than -1.
    // Other functions have the potential for using a fast and approximate
    // algorithm rather than calling the standard math library functions.
    static Real ACos (Real fValue);
    static Real ASin (Real fValue);
    static Real ATan (Real fValue);
    static Real ATan2 (Real fY, Real fX);
    static Real Ceil (Real fValue);
    static Real Cos (Real fValue);
    static Real Exp (Real fValue);
    static Real FAbs (Real fValue);
    static Real Floor (Real fValue);
    static Real FMod (Real fX, Real fY);
    static Real InvSqrt (Real fValue);
    static Real Log (Real fValue);
    static Real Log2 (Real fValue);
    static Real Log10 (Real fValue);
    static Real Pow (Real fBase, Real fExponent);
    static Real Sin (Real fValue);
    static Real Sqr (Real fValue);
    static Real Sqrt (Real fValue);
    static Real Tan (Real fValue);

    // Return -1 if the input is negative, 0 if the input is zero, and +1
    // if the input is positive.
    static int Sign (int iValue);
    static Real Sign (Real fValue);

    // Generate a random number in [0,1].  The random number generator may
    // be seeded by a first call to UnitRandom with a positive seed.
    static Real UnitRandom (unsigned int uiSeed = 0);

    // Generate a random number in [-1,1].  The random number generator may
    // be seeded by a first call to SymmetricRandom with a positive seed.
    static Real SymmetricRandom (unsigned int uiSeed = 0);

    // Generate a random number in [min,max].  The random number generator may
    // be seeded by a first call to IntervalRandom with a positive seed.
    static Real IntervalRandom (Real fMin, Real fMax,
        unsigned int uiSeed = 0);

    // Fast evaluation of trigonometric and inverse trigonometric functions
    // using polynomial approximations.  The speed ups were measured on an
    // AMD 2800 (2.08 GHz) processor using Visual Studion .NET 2003 with a
    // release build.

    // The input must be in [0,pi/2].
    // max error sin0 = 1.7e-04, speed up = 4.0
    // max error sin1 = 1.9e-08, speed up = 2.8
    static Real FastSin0 (Real fAngle);
    static Real FastSin1 (Real fAngle);

    // The input must be in [0,pi/2]
    // max error cos0 = 1.2e-03, speed up = 4.5
    // max error cos1 = 6.5e-09, speed up = 2.8
    static Real FastCos0 (Real fAngle);
    static Real FastCos1 (Real fAngle);

    // The input must be in [0,pi/4].
    // max error tan0 = 8.1e-04, speed up = 5.6
    // max error tan1 = 1.9e-08, speed up = 3.4
    static Real FastTan0 (Real fAngle);
    static Real FastTan1 (Real fAngle);

    // The input must be in [0,1].
    // max error invsin0 = 6.8e-05, speed up = 7.5
    // max error invsin1 = 1.4e-07, speed up = 5.5
    static Real FastInvSin0 (Real fValue);
    static Real FastInvSin1 (Real fValue);

    // The input must be in [0,1].
    // max error invcos0 = 6.8e-05, speed up = 7.5
    // max error invcos1 = 1.4e-07, speed up = 5.7
    static Real FastInvCos0 (Real fValue);
    static Real FastInvCos1 (Real fValue);

    // The input must be in [-1,1]. 
    // max error invtan0 = 1.2e-05, speed up = 2.8
    // max error invtan1 = 2.3e-08, speed up = 1.8
    static Real FastInvTan0 (Real fValue);
    static Real FastInvTan1 (Real fValue);

    // A fast approximation to 1/sqrt.
    static Real FastInvSqrt (Real fValue);

    // Fast approximations to exp(-x).  The input x must be in [0,infinity).
    // max error negexp0 = 0.00024, speed up = 25.4
    // max error negexp1 = 0.000024, speed up = 25.4
    // max error negexp2 = 0.0000024, speed up = 20.5
    // max error negexp3 = 0.00000025, speed up = 17.3
    static Real FastNegExp0 (Real fValue);
    static Real FastNegExp1 (Real fValue);
    static Real FastNegExp2 (Real fValue);
    static Real FastNegExp3 (Real fValue);

    // common constants
    WG3D_FOUNDATION_ITEM static const Real EPSILON;
    WG3D_FOUNDATION_ITEM static const Real ZERO_TOLERANCE;
    WG3D_FOUNDATION_ITEM static const Real MAX_REAL;
    WG3D_FOUNDATION_ITEM static const Real PI;
    WG3D_FOUNDATION_ITEM static const Real TWO_PI;
    WG3D_FOUNDATION_ITEM static const Real HALF_PI;
    WG3D_FOUNDATION_ITEM static const Real INV_PI;
    WG3D_FOUNDATION_ITEM static const Real INV_TWO_PI;
    WG3D_FOUNDATION_ITEM static const Real DEG_TO_RAD;
    WG3D_FOUNDATION_ITEM static const Real RAD_TO_DEG;
    WG3D_FOUNDATION_ITEM static const Real LN_2;
    WG3D_FOUNDATION_ITEM static const Real LN_10;
    WG3D_FOUNDATION_ITEM static const Real INV_LN_2;
    WG3D_FOUNDATION_ITEM static const Real INV_LN_10;
};

class WG3D_FOUNDATION_ITEM Mathx
{
public:
    // Wrappers to hide implementations of functions.  The ACos and ASin
    // functions clamp the input argument to [-1,1] to avoid NaN issues
    // when the input is slightly larger than 1 or slightly smaller than -1.
    // Other functions have the potential for using a fast and approximate
    // algorithm rather than calling the standard math library functions.
    static fixed ACos (fixed fValue);
    static fixed ASin (fixed fValue);
    static fixed ATan (fixed fValue);
    static fixed ATan2 (fixed fY, fixed fX);
    static fixed Ceil (fixed fValue);
    static fixed Cos (fixed fValue);
    static fixed Exp (fixed fValue);
    static fixed FAbs (fixed fValue);
    static fixed Floor (fixed fValue);
    static fixed FMod (fixed fX, fixed fY);
    static fixed InvSqrt (fixed fValue);
    static fixed Log (fixed fValue);
    static fixed Log2 (fixed fValue);
    static fixed Log10 (fixed fValue);
    static fixed Pow (fixed fBase, fixed fExponent);
    static fixed Sin (fixed fValue);
    static fixed Sqr (fixed fValue);
    static fixed Sqrt (fixed fValue);
    static fixed Tan (fixed fValue);

    // Return -1 if the input is negative, 0 if the input is zero, and +1
    // if the input is positive.
    static int Sign (int iValue);
    static fixed Sign (fixed fValue);

    // Generate a random number in [0,1].  The random number generator may
    // be seeded by a first call to UnitRandom with a positive seed.
    static fixed UnitRandom (unsigned int uiSeed = 0);

    // Generate a random number in [-1,1].  The random number generator may
    // be seeded by a first call to SymmetricRandom with a positive seed.
    static fixed SymmetricRandom (unsigned int uiSeed = 0);

    // Generate a random number in [min,max].  The random number generator may
    // be seeded by a first call to IntervalRandom with a positive seed.
    static fixed IntervalRandom (fixed fMin, fixed fMax,
        unsigned int uiSeed = 0);

    // Fast evaluation of trigonometric and inverse trigonometric functions
    // using polynomial approximations.  The speed ups were measured on an
    // AMD 2800 (2.08 GHz) processor using Visual Studion .NET 2003 with a
    // release build.

    // The input must be in [0,pi/2].
    // max error sin0 = 1.7e-04, speed up = 4.0
    // max error sin1 = 1.9e-08, speed up = 2.8
    static fixed FastSin0 (fixed fAngle);
    static fixed FastSin1 (fixed fAngle);

    // The input must be in [0,pi/2]
    // max error cos0 = 1.2e-03, speed up = 4.5
    // max error cos1 = 6.5e-09, speed up = 2.8
    static fixed FastCos0 (fixed fAngle);
    static fixed FastCos1 (fixed fAngle);

    // The input must be in [0,pi/4].
    // max error tan0 = 8.1e-04, speed up = 5.6
    // max error tan1 = 1.9e-08, speed up = 3.4
    static fixed FastTan0 (fixed fAngle);
    static fixed FastTan1 (fixed fAngle);

    // The input must be in [0,1].
    // max error invsin0 = 6.8e-05, speed up = 7.5
    // max error invsin1 = 1.4e-07, speed up = 5.5
    static fixed FastInvSin0 (fixed fValue);
    static fixed FastInvSin1 (fixed fValue);

    // The input must be in [0,1].
    // max error invcos0 = 6.8e-05, speed up = 7.5
    // max error invcos1 = 1.4e-07, speed up = 5.7
    static fixed FastInvCos0 (fixed fValue);
    static fixed FastInvCos1 (fixed fValue);

    // The input must be in [-1,1]. 
    // max error invtan0 = 1.2e-05, speed up = 2.8
    // max error invtan1 = 2.3e-08, speed up = 1.8
    static fixed FastInvTan0 (fixed fValue);
    static fixed FastInvTan1 (fixed fValue);

    // A fast approximation to 1/sqrt.
    static fixed FastInvSqrt (fixed fValue);

    // Fast approximations to exp(-x).  The input x must be in [0,infinity).
    // max error negexp0 = 0.00024, speed up = 25.4
    // max error negexp1 = 0.000024, speed up = 25.4
    // max error negexp2 = 0.0000024, speed up = 20.5
    // max error negexp3 = 0.00000025, speed up = 17.3
    static fixed FastNegExp0 (fixed fValue);
    static fixed FastNegExp1 (fixed fValue);
    static fixed FastNegExp2 (fixed fValue);
    static fixed FastNegExp3 (fixed fValue);

    // common constants
    static const fixed EPSILON;
    static const fixed ZERO_TOLERANCE;
    static const fixed MAX_REAL;
    static const fixed PI;
    static const fixed TWO_PI;
    static const fixed HALF_PI;
    static const fixed INV_PI;
    static const fixed INV_TWO_PI;
    static const fixed DEG_TO_RAD;
    static const fixed RAD_TO_DEG;
    static const fixed LN_2;
    static const fixed LN_10;
    static const fixed INV_LN_2;
    static const fixed INV_LN_10;
};
#include "WgMath.inl"

typedef Math<float> Mathf;
typedef Math<double> Mathd;
}

#endif
