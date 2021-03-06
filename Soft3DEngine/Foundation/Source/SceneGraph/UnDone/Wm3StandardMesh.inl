// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

//----------------------------------------------------------------------------
inline StandardMesh& StandardMesh::Vertices (bool bCached)
{
    m_bCachedVertices = bCached;
    return *this;
}
//----------------------------------------------------------------------------
inline StandardMesh& StandardMesh::Indices (bool bCached)
{
    m_bCachedIndices = bCached;
    return *this;
}
//----------------------------------------------------------------------------
inline StandardMesh& StandardMesh::Normals (bool bCreate, bool bCached)
{
    m_bNormals = bCreate;
    m_bCachedNormals = bCached;
    return *this;
}
//----------------------------------------------------------------------------
inline StandardMesh& StandardMesh::UVs (bool bCreate, bool bCached)
{
    m_bUVs = bCreate;
    m_bCachedUVs = bCached;
    return *this;
}
//----------------------------------------------------------------------------
inline StandardMesh& StandardMesh::Inside (bool bInside)
{
    m_bInside = bInside;
    return *this;
}
//----------------------------------------------------------------------------
inline Vector2fArrayPtr StandardMesh::GetUVs () const
{
    return m_spkUVs;
}
//----------------------------------------------------------------------------

