// Author: Valve Corporation
// Licence: https://github.com/ValveSoftware/source-sdk-2013/blob/master/LICENSE
#ifndef VMATRIX_H
#define VMATRIX_H

#include "vplane.h"

class VMatrix
{
public:

	VMatrix();
	VMatrix(
		vec_t m00, vec_t m01, vec_t m02, vec_t m03,
		vec_t m10, vec_t m11, vec_t m12, vec_t m13,
		vec_t m20, vec_t m21, vec_t m22, vec_t m23,
		vec_t m30, vec_t m31, vec_t m32, vec_t m33
	);
	VMatrix(const Vector& forward, const Vector& left, const Vector& up);
	VMatrix(const Vector& forward, const Vector& left, const Vector& up, const Vector& translation);
	VMatrix(const struct matrix3x4_t& matrix3x4);
	void		Init(
		vec_t m00, vec_t m01, vec_t m02, vec_t m03,
		vec_t m10, vec_t m11, vec_t m12, vec_t m13,
		vec_t m20, vec_t m21, vec_t m22, vec_t m23,
		vec_t m30, vec_t m31, vec_t m32, vec_t m33
	);
	void		Init(const matrix3x4_t& matrix3x4);
	inline float* operator[](int i)
	{
		return m[i];
	}
	inline const float* operator[](int i) const
	{
		return m[i];
	}
	inline float *Base()
	{
		return &m[0][0];
	}
	inline const float *Base() const
	{
		return &m[0][0];
	}
	void		SetLeft(const Vector &vLeft);
	void		SetUp(const Vector &vUp);
	void		SetForward(const Vector &vForward);
	void		GetBasisVectors(Vector &vForward, Vector &vLeft, Vector &vUp) const;
	void		SetBasisVectors(const Vector &vForward, const Vector &vLeft, const Vector &vUp);
	Vector &	GetTranslation(Vector &vTrans) const;
	void		SetTranslation(const Vector &vTrans);
	void		PreTranslate(const Vector &vTrans);
	void		PostTranslate(const Vector &vTrans);
	matrix3x4_t& As3x4();
	const matrix3x4_t& As3x4() const;
	void		CopyFrom3x4(const matrix3x4_t &m3x4);
	void		Set3x4(matrix3x4_t& matrix3x4) const;
	bool		operator==(const VMatrix& src) const;
	bool		operator!=(const VMatrix& src) const { return !(*this == src); }
	Vector		GetLeft() const;
	Vector		GetUp() const;
	Vector		GetForward() const;
	Vector		GetTranslation() const;
public:
	void		V3Mul(const Vector &vIn, Vector &vOut) const;
	void		V4Mul(const Vector4D &vIn, Vector4D &vOut) const;
	Vector		ApplyRotation(const Vector &vVec) const;
	Vector		operator*(const Vector &vVec) const;
	Vector		VMul3x3(const Vector &vVec) const;
	Vector		VMul3x3Transpose(const Vector &vVec) const;
	Vector		VMul4x3(const Vector &vVec) const;
	Vector		VMul4x3Transpose(const Vector &vVec) const;
public:
	void		TransformPlane(const VPlane &inPlane, VPlane &outPlane) const;
	VPlane		operator*(const VPlane &thePlane) const;
public:
	VMatrix&	operator=(const VMatrix &mOther);
	void		MatrixMul(const VMatrix &vm, VMatrix &out) const;
	const VMatrix& operator+=(const VMatrix &other);
	VMatrix		operator*(const VMatrix &mOther) const;
	VMatrix		operator+(const VMatrix &other) const;
	VMatrix		operator-(const VMatrix &other) const;
	VMatrix		operator-() const;
	VMatrix		operator~() const;
public:
	void		Identity();
	bool		IsIdentity() const;
	void		SetupMatrixOrgAngles(const Vector &origin, const QAngle &vAngles);
	void		SetupMatrixAngles(const QAngle &vAngles);
	bool		InverseGeneral(VMatrix &vInverse) const;
	void		InverseTR(VMatrix &mRet) const;
	bool		IsRotationMatrix() const;
	VMatrix		InverseTR() const;
	Vector		GetScale() const;
	VMatrix		Scale(const Vector &vScale);
	VMatrix		NormalizeBasisVectors() const;
	VMatrix		Transpose() const;
	VMatrix		Transpose3x3() const;
public:
	vec_t		m[4][4];
};

#endif