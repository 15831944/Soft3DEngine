///////////////////////////////////////////////////////////
//                                                       //
//                    WgIntArray.h                       //
//                                                       //
//  - Interface for Int Array class                      //
//                                                       //
//  - Written By Woong Gyu La a.k.a. Chris               //
//       on 2009.10.07                                   //
//                                                       //
///////////////////////////////////////////////////////////

#ifndef __WG_INTARRAY_H__
#define __WG_INTARRAY_H__

#include "WgFoundationLIB.h"
#include "WgTSharedArray.h"

namespace WGSoft3D
{
typedef TSharedArray<int> IntArray;
typedef Pointer<IntArray> IntArrayPtr;
}

#endif

