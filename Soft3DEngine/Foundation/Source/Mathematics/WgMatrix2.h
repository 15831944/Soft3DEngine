///////////////////////////////////////////////////////////
//                                                       //
//                    WgMatrix2.h                        //
//                                                       //
//  - Interface for Matrix2 class                        //
//                                                       //
//  - Written By Woong Gyu La a.k.a. Chris               //
//       on 2009.10.06                                   //
//                                                       //
///////////////////////////////////////////////////////////

#ifndef __WG_MATRIX_2_H__
#define __WG_MATRIX_2_H__

// Matrix operations are applied on the left.  For example, given a matrix M
// and a vector V, matrix-times-vector is M*V.  That is, V is treated as a
// column vector.  Some graphics APIs use V*M where V is treated as a row
// vector.  In this context the "M" matrix is really a transpose of the M as
// represented in Wild Magic.  Similarly, to apply two matrix operations M0
// and M1, in that order, you compute M1*M0 so that the transform of a vector
// is (M1*M0)*V = M1*(M0*V).  Some graphics APIs use M0*M1, but again these
// matrices are the transpose of those as represented in Wild Magic.  You
// must therefore be careful about how you interface the transformation code
// with graphics APIS.
//
// For memory organization it might seem natural to chose Real[N][N] for the
// matrix storage, but this can be a problem on a platform/console that
// chooses to store the data in column-major rather than row-major format.
// To avoid potential portability problems, the matrix is stored as Real[N*N]
// and organized in row-major order.  That is, the entry of the matrix in row
// r (0 <= r < N) and column c (0 <= c < N) is stored at index i = c+N*r
// (0 <= i < N*N).

// Rotation matrices are of the form
//   R = cos(t) -sin(t)
//       sin(t)  cos(t)
// where t > 0 indicates a counterclockwise rotation in the xy-plane.

#include "WgFoundationLIB.h"
#include "WgVector2.h"

namespace WGSoft3D
{
template <class Real>
class Matrix2
{
public:
    // If bZero is true, create the zero matrix.  Otherwise, create the
    // identity matrix.
    Matrix2 (bool bZero = true);

    // copy constructor
    Matrix2 (const Matrix2& rkM);

    // input Mrc is in row r, column c.
    Matrix2 (Real fM00, Real fM01, Real fM10, Real fM11);

    // Create a matrix from an array of numbers.  The input array is
    // interpreted based on the Boolean input as
    //   true:  entry[0..3] = {m00,m01,m10,m11}  [row major]
    //   false: entry[0..3] = {m00,m10,m01,m11}  [column major]
    Matrix2 (const Real afEntry[4], bool bRowMajor);

    // Create matrices based on vector input.  The Boolean is interpreted as
    //   true: vectors are columns of the matrix
    //   false: vectors are rows of the matrix
    Matrix2 (const Vector2<Real>& rkU, const Vector2<Real>& rkV,
        bool bColumns);
    Matrix2 (const Vector2<Real>* akV, bool bColumns);

    // create a diagonal matrix
    Matrix2 (Real fM00, Real fM11);

    // create a rotation matrix (positive angle - counterclockwise)
    Matrix2 (Real fAngle);

    // create a tensor product U*V^T
    Matrix2 (const Vector2<Real>& rkU, const Vector2<Real>& rkV);

    // create various matrices
    void MakeZero ();
    void MakeIdentity ();
    void MakeDiagonal (Real fM00, Real fM11);
    void FromAngle (Real fAngle);
    void MakeTensorProduct (const Vector2<Real>& rkU,
        const Vector2<Real>& rkV);

    // member access
    inline operator const Real* () const;
    inline operator Real* ();
    inline const Real* operator[] (int iRow) const;
    inline Real* operator[] (int iRow);
    inline Real operator() (int iRow, int iCol) const;
    inline Real& operator() (int iRow, int iCol);
    void SetRow (int iRow, const Vector2<Real>& rkV);
    Vector2<Real> GetRow (int iRow) const;
    void SetColumn (int iCol, const Vector2<Real>& rkV);
    Vector2<Real> GetColumn (int iCol) const;
    void GetColumnMajor (Real* afCMajor) const;

    // assignment
    inline Matrix2& operator= (const Matrix2& rkM);

    // comparison
    bool operator== (const Matrix2& rkM) const;
    bool operator!= (const Matrix2& rkM) const;
    bool operator<  (const Matrix2& rkM) const;
    bool operator<= (const Matrix2& rkM) const;
    bool operator>  (const Matrix2& rkM) const;
    bool operator>= (const Matrix2& rkM) const;

    // arithmetic operations
    inline Matrix2 operator+ (const Matrix2& rkM) const;
    inline Matrix2 operator- (const Matrix2& rkM) const;
    inline Matrix2 operator* (const Matrix2& rkM) const;
    inline Matrix2 operator* (Real fScalar) const;
    inline Matrix2 operator/ (Real fScalar) const;
    inline Matrix2 operator- () const;

    // arithmetic updates
    inline Matrix2& operator+= (const Matrix2& rkM);
    inline Matrix2& operator-= (const Matrix2& rkM);
    inline Matrix2& operator*= (Real fScalar);
    inline Matrix2& operator/= (Real fScalar);

    // matrix times vector
    inline Vector2<Real> operator* (const Vector2<Real>& rkV) const;  // M * v

    // other operations
    Matrix2 Transpose () const;  // M^T
    Matrix2 TransposeTimes (const Matrix2& rkM) const;  // this^T * M
    Matrix2 TimesTranspose (const Matrix2& rkM) const;  // this * M^T
    Matrix2 Inverse () const;
    Matrix2 Adjoint () const;
    Real Determinant () const;
    Real QForm (const Vector2<Real>& rkU,
        const Vector2<Real>& rkV) const;  // u^T*M*v

    // The matrix must be a rotation for these functions to be valid.  The
    // last function uses Gram-Schmidt orthonormalization applied to the
    // columns of the rotation matrix.  The angle must be in radians, not
    // degrees.
    void ToAngle (Real& rfAngle) const;
    void Orthonormalize ();

    // The matrix must be symmetric.  Factor M = R * D * R^T where
    // R = [u0|u1] is a rotation matrix with columns u0 and u1 and
    // D = diag(d0,d1) is a diagonal matrix whose diagonal entries are d0 and
    // d1.  The eigenvector u[i] corresponds to eigenvector d[i].  The
    // eigenvalues are ordered as d0 <= d1.
    void EigenDecomposition (Matrix2& rkRot, Matrix2& rkDiag) const;

    WG3D_FOUNDATION_ITEM static const Matrix2 ZERO;
    WG3D_FOUNDATION_ITEM static const Matrix2 IDENTITY;

private:
    // support for comparisons
    int CompareArrays (const Matrix2& rkM) const;

    // matrix stored in row-major order
    Real m_afEntry[4];
};

class WG3D_FOUNDATION_ITEM Matrix2x
{
public:
    // If bZero is true, create the zero matrix.  Otherwise, create the
    // identity matrix.
    Matrix2x (bool bZero = true);

    // copy constructor
    Matrix2x (const Matrix2x& rkM);

    // input Mrc is in row r, column c.
    Matrix2x (fixed fM00, fixed fM01, fixed fM10, fixed fM11);

    // Create a matrix from an array of numbers.  The input array is
    // interpreted based on the Boolean input as
    //   true:  entry[0..3] = {m00,m01,m10,m11}  [row major]
    //   false: entry[0..3] = {m00,m10,m01,m11}  [column major]
    Matrix2x (const fixed afEntry[4], bool bRowMajor);

    // Create matrices based on vector input.  The Boolean is interpreted as
    //   true: vectors are columns of the matrix
    //   false: vectors are rows of the matrix
    Matrix2x (const Vector2x& rkU, const Vector2x& rkV,
        bool bColumns);
    Matrix2x (const Vector2x* akV, bool bColumns);

    // create a diagonal matrix
    Matrix2x (fixed fM00, fixed fM11);

    // create a rotation matrix (positive angle - counterclockwise)
    Matrix2x (fixed fAngle);

    // create a tensor product U*V^T
    Matrix2x (const Vector2x& rkU, const Vector2x& rkV);

    // create various matrices
    void MakeZero ();
    void MakeIdentity ();
    void MakeDiagonal (fixed fM00, fixed fM11);
    void FromAngle (fixed fAngle);
    void MakeTensorProduct (const Vector2x& rkU,
        const Vector2x& rkV);

    // member access
    inline operator const fixed* () const;
    inline operator fixed* ();
    inline const fixed* operator[] (int iRow) const;
    inline fixed* operator[] (int iRow);
    inline fixed operator() (int iRow, int iCol) const;
    inline fixed& operator() (int iRow, int iCol);
    void SetRow (int iRow, const Vector2x& rkV);
    Vector2x GetRow (int iRow) const;
    void SetColumn (int iCol, const Vector2x& rkV);
    Vector2x GetColumn (int iCol) const;
    void GetColumnMajor (fixed* afCMajor) const;

    // assignment
    inline Matrix2x& operator= (const Matrix2x& rkM);

    // comparison
    bool operator== (const Matrix2x& rkM) const;
    bool operator!= (const Matrix2x& rkM) const;
    bool operator<  (const Matrix2x& rkM) const;
    bool operator<= (const Matrix2x& rkM) const;
    bool operator>  (const Matrix2x& rkM) const;
    bool operator>= (const Matrix2x& rkM) const;

    // arithmetic operations
    inline Matrix2x operator+ (const Matrix2x& rkM) const;
    inline Matrix2x operator- (const Matrix2x& rkM) const;
    inline Matrix2x operator* (const Matrix2x& rkM) const;
    inline Matrix2x operator* (fixed fScalar) const;
    inline Matrix2x operator/ (fixed fScalar) const;
    inline Matrix2x operator- () const;

    // arithmetic updates
    inline Matrix2x& operator+= (const Matrix2x& rkM);
    inline Matrix2x& operator-= (const Matrix2x& rkM);
    inline Matrix2x& operator*= (fixed fScalar);
    inline Matrix2x& operator/= (fixed fScalar);

    // matrix times vector
    inline Vector2x operator* (const Vector2x& rkV) const;  // M * v

    // other operations
    Matrix2x Transpose () const;  // M^T
    Matrix2x TransposeTimes (const Matrix2x& rkM) const;  // this^T * M
    Matrix2x TimesTranspose (const Matrix2x& rkM) const;  // this * M^T
    Matrix2x Inverse () const;
    Matrix2x Adjoint () const;
    fixed Determinant () const;
    fixed QForm (const Vector2x& rkU,
        const Vector2x& rkV) const;  // u^T*M*v

    // The matrix must be a rotation for these functions to be valid.  The
    // last function uses Gram-Schmidt orthonormalization applied to the
    // columns of the rotation matrix.  The angle must be in radians, not
    // degrees.
    void ToAngle (fixed& rfAngle) const;
    void Orthonormalize ();

    // The matrix must be symmetric.  Factor M = R * D * R^T where
    // R = [u0|u1] is a rotation matrix with columns u0 and u1 and
    // D = diag(d0,d1) is a diagonal matrix whose diagonal entries are d0 and
    // d1.  The eigenvector u[i] corresponds to eigenvector d[i].  The
    // eigenvalues are ordered as d0 <= d1.
    void EigenDecomposition (Matrix2x& rkRot, Matrix2x& rkDiag) const;

    static const Matrix2x ZERO;
    static const Matrix2x IDENTITY;

private:
    // support for comparisons
    int CompareArrays (const Matrix2x& rkM) const;

    // matrix stored in row-major order
    fixed m_afEntry[4];
};

// c * M
template <class Real>
inline Matrix2<Real> operator* (Real fScalar, const Matrix2<Real>& rkM);
inline Matrix2x operator* (fixed fScalar, const Matrix2x& rkM);

// v^T * M
template <class Real>
inline Vector2<Real> operator* (const Vector2<Real>& rkV,const Matrix2<Real>& rkM);
inline Vector2x operator* (const Vector2x& rkV,const Matrix2x& rkM);

#include "WgMatrix2.inl"

typedef Matrix2<float> Matrix2f;
typedef Matrix2<double> Matrix2d;

}

#endif