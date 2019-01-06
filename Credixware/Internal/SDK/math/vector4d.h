// Author: Valve Corporation
// Licence: https://github.com/ValveSoftware/source-sdk-2013/blob/master/LICENSE
#ifndef VECTOR4D_H
#define VECTOR4D_H

class Vector4D
{
public:
	vec_t x, y, z, w;
	Vector4D(void);
	Vector4D(vec_t X, vec_t Y, vec_t Z, vec_t W);
	Vector4D(const float *pFloat);
	void Init(vec_t ix = 0.0f, vec_t iy = 0.0f, vec_t iz = 0.0f, vec_t iw = 0.0f);
	bool IsValid() const;
	vec_t operator[](int i) const;
	vec_t& operator[](int i);
	inline vec_t* Base();
	inline vec_t const* Base() const;
	Vector& AsVector3D();
	Vector const& AsVector3D() const;
	Vector2D& AsVector2D();
	Vector2D const& AsVector2D() const;
	void Random(vec_t minVal, vec_t maxVal);
	bool operator==(const Vector4D& v) const;
	bool operator!=(const Vector4D& v) const;
	Vector4D&	operator+=(const Vector4D &v);
	Vector4D&	operator-=(const Vector4D &v);
	Vector4D&	operator*=(const Vector4D &v);
	Vector4D&	operator*=(float s);
	Vector4D&	operator/=(const Vector4D &v);
	Vector4D&	operator/=(float s);
	void	Negate();
	vec_t	Length() const;
	vec_t	LengthSqr(void) const;
	bool IsZero(float tolerance = 0.01f) const
	{
		return (x > -tolerance && x < tolerance &&
			y > -tolerance && y < tolerance &&
			z > -tolerance && z < tolerance &&
			w > -tolerance && w < tolerance);
	}
	vec_t	DistTo(const Vector4D &vOther) const;
	vec_t	DistToSqr(const Vector4D &vOther) const;
	void	CopyToArray(float* rgfl) const;
	void	MulAdd(Vector4D const& a, Vector4D const& b, float scalar);
	vec_t	Dot(Vector4D const& vOther) const;
public:
	Vector4D(Vector4D const& vOther);
	Vector4D& operator=(Vector4D const& src);
};

#endif