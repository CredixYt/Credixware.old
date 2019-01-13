// Author: Valve Corporation
// Licence: https://github.com/ValveSoftware/source-sdk-2013/blob/master/LICENSE
#ifndef VECTOR2D_H
#define VECTOR2D_H

#include "../basetypes.h"

class Vector2D
{
public:
	vec_t x, y;
	Vector2D(void) {
	}
	Vector2D(vec_t X, vec_t Y) {
		x = X;
		y = Y;
	}
	Vector2D(const float *pFloat) {
		x = *pFloat;
		y = *pFloat;
	}
	void Init(vec_t ix = 0.0f, vec_t iy = 0.0f) {
		x = ix;
		y = iy;
	}
	bool IsValid() const;
	vec_t operator[](int i) const;
	vec_t& operator[](int i);
	vec_t* Base();
	vec_t const* Base() const;
	void Random(float minVal, float maxVal);
	bool operator==(const Vector2D& v) const;
	bool operator!=(const Vector2D& v) const;
	Vector2D&	operator+=(const Vector2D &v);
	Vector2D&	operator-=(const Vector2D &v);
	Vector2D&	operator*=(const Vector2D &v);
	Vector2D&	operator*=(float s);
	Vector2D&	operator/=(const Vector2D &v);
	Vector2D&	operator/=(float s);
	void	Negate();
	vec_t	Length() const;
	vec_t	LengthSqr(void) const;
	bool IsZero(float tolerance = 0.01f) const
	{
		return (x > -tolerance && x < tolerance &&
			y > -tolerance && y < tolerance);
	}
	vec_t	NormalizeInPlace();
	bool	IsLengthGreaterThan(float val) const;
	bool	IsLengthLessThan(float val) const;
	vec_t	DistTo(const Vector2D &vOther) const;
	vec_t	DistToSqr(const Vector2D &vOther) const;
	void	CopyToArray(float* rgfl) const;
	void	MulAdd(const Vector2D& a, const Vector2D& b, float scalar);
	vec_t	Dot(const Vector2D& vOther) const;
	Vector2D& operator=(const Vector2D &vOther);
#ifndef VECTOR_NO_SLOW_OPERATIONS
	Vector2D(const Vector2D &vOther);
	Vector2D	operator-(void) const;
	Vector2D	operator+(const Vector2D& v) const;
	Vector2D	operator-(const Vector2D& v) const;
	Vector2D	operator*(const Vector2D& v) const;
	Vector2D	operator/(const Vector2D& v) const;
	Vector2D	operator*(float fl) const;
	Vector2D	operator/(float fl) const;
	Vector2D	Cross(const Vector2D &vOther) const;
	Vector2D	Min(const Vector2D &vOther) const;
	Vector2D	Max(const Vector2D &vOther) const;
#else
private:
	Vector2D(const Vector2D& vOther);
#endif
};

#endif