///////////////////////////////////////////////////////////
//                                                       //
//                    WgTriMesh.inl                      //
//                                                       //
//  - Inlines for Tri Mesh class                         //
//                                                       //
//  - Written By Woong Gyu La a.k.a. Chris               //
//       on 2009.10.07                                   //
//                                                       //
///////////////////////////////////////////////////////////
//----------------------------------------------------------------------------
inline int TriMesh::GetTriangleQuantity () const
{
    return Indices->GetQuantity()/3;
}
//----------------------------------------------------------------------------

