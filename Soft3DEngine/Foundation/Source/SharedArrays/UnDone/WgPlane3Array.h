// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM3PLANE3ARRAY_H
#define WM3PLANE3ARRAY_H

#include "Wm3FoundationLIB.h"
#include "Wm3TSharedArray.h"
#include "Wm3Plane3.h"

namespace Wm3
{
typedef TSharedArray<Plane3f> Plane3fArray;
typedef Pointer<Plane3fArray> Plane3fArrayPtr;
WM3_REGISTER_STREAM(Plane3fArray);

typedef TSharedArray<Plane3d> Plane3dArray;
typedef Pointer<Plane3dArray> Plane3dArrayPtr;
WM3_REGISTER_STREAM(Plane3dArray);
}

#endif

