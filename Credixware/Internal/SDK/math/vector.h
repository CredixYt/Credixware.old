// Author: Valve Corporation
// Licence: https://github.com/ValveSoftware/source-sdk-2013/blob/master/LICENSE
#ifndef VECTOR_H
#define VECTOR_H

#include "../basetypes.h"
#include "vector2d.h"

class VectorByValue;

class Vector
{
public:
	vec_t x, y, z;
	Vector(void) {
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}
	Vector(vec_t X, vec_t Y, vec_t Z) {
		x = X;
		y = Y;
		z = Z;
	}
	explicit Vector(vec_t XYZ) {
		x = XYZ;
		y = XYZ;
		z = XYZ;
	}
	void Init(vec_t ix = 0.0f, vec_t iy = 0.0f, vec_t iz = 0.0f) {
		x = ix;
		y = iy;
		z = iz;
	}
	bool IsValid() const;
	void Invalidate();
	vec_t operator[](int i) const;
	vec_t& operator[](int i);
	vec_t* Base();
	vec_t const* Base() const;
	Vector2D& AsVector2D();
	const Vector2D& AsVector2D() const;
	void Random(vec_t minVal, vec_t maxVal);
	inline void Zero();
	bool operator==(const Vector& v) const;
	bool operator!=(const Vector& v) const;
	FORCEINLINE Vector&	operator+=(const Vector &v);
	FORCEINLINE Vector&	operator-=(const Vector &v);
	FORCEINLINE Vector&	operator*=(const Vector &v);
	FORCEINLINE Vector&	operator*=(float s);
	FORCEINLINE Vector&	operator/=(const Vector &v);
	FORCEINLINE Vector&	operator/=(float s);
	FORCEINLINE Vector&	operator+=(float fl);
	FORCEINLINE Vector&	operator-=(float fl);		
	void	Negate();
	inline vec_t	Length() const;
	FORCEINLINE vec_t LengthSqr(void) const
	{
		CHECK_VALID(*this);
		return (x*x + y * y + z * z);
	}
	bool IsZero(float tolerance = 0.01f) const
	{
		return (x > -tolerance && x < tolerance &&
			y > -tolerance && y < tolerance &&
			z > -tolerance && z < tolerance);
	}
	vec_t	NormalizeInPlace();
	Vector	Normalized() const;
	bool	IsLengthGreaterThan(float val) const;
	bool	IsLengthLessThan(float val) const;
	FORCEINLINE bool WithinAABox(Vector const &boxmin, Vector const &boxmax);
	vec_t	DistTo(const Vector &vOther) const;
	FORCEINLINE vec_t DistToSqr(const Vector &vOther) const
	{
		Vector delta;

		delta.x = x - vOther.x;
		delta.y = y - vOther.y;
		delta.z = z - vOther.z;

		return delta.LengthSqr();
	}
	void	CopyToArray(float* rgfl) const;
	void	MulAdd(const Vector& a, const Vector& b, float scalar);
	vec_t	Dot(const Vector& vOther) const;
	Vector& operator=(const Vector &vOther);
	vec_t	Length2D(void) const;
	vec_t	Length2DSqr(void) const;
	operator VectorByValue &() { return *((VectorByValue *)(this)); }
	operator const VectorByValue &() const { return *((const VectorByValue *)(this)); }
#ifndef VECTOR_NO_SLOW_OPERATIONS
	Vector	operator-(void) const;
	Vector	operator+(const Vector& v) const;
	Vector	operator-(const Vector& v) const;
	Vector	operator*(const Vector& v) const;
	Vector	operator/(const Vector& v) const;
	Vector	operator*(float fl) const;
	Vector	operator/(float fl) const;
	Vector	Cross(const Vector &vOther) const;
	Vector	Min(const Vector &vOther) const;
	Vector	Max(const Vector &vOther) const;
#else
private:
	Vector(const Vector& vOther);
#endif
};

class VectorByValue : public Vector
{
public:
	VectorByValue(void) : Vector() {}
	VectorByValue(vec_t X, vec_t Y, vec_t Z) : Vector(X, Y, Z) {}
	VectorByValue(const VectorByValue& vOther) { *this = vOther; }
};

class QAngleByValue;

class QAngle
{
public:
	vec_t x, y, z;
	QAngle(void);
	QAngle(vec_t X, vec_t Y, vec_t Z);
	operator QAngleByValue &() { return *((QAngleByValue *)(this)); }
	operator const QAngleByValue &() const { return *((const QAngleByValue *)(this)); }
	void Init(vec_t ix = 0.0f, vec_t iy = 0.0f, vec_t iz = 0.0f);
	void Random(vec_t minVal, vec_t maxVal);
	bool IsValid() const;
	void Invalidate();
	vec_t operator[](int i) const;
	vec_t& operator[](int i);
	vec_t* Base();
	vec_t const* Base() const;
	bool operator==(const QAngle& v) const;
	bool operator!=(const QAngle& v) const;
	QAngle&	operator+=(const QAngle &v);
	QAngle&	operator-=(const QAngle &v);
	QAngle&	operator*=(float s);
	QAngle&	operator/=(float s);
	vec_t	Length() const;
	vec_t	LengthSqr() const;
	QAngle& operator=(const QAngle& src);
	QAngle	operator-(void) const;
	QAngle	operator+(const QAngle& v) const;
	QAngle	operator-(const QAngle& v) const;
	QAngle	operator*(float fl) const;
	QAngle	operator/(float fl) const;
};

class QAngleByValue : public QAngle
{
public:
	QAngleByValue(void) : QAngle() {}
	QAngleByValue(vec_t X, vec_t Y, vec_t Z) : QAngle(X, Y, Z) {}
	QAngleByValue(const QAngleByValue& vOther) { *this = vOther; }
};

#endif