// Author: Valve Corporation
// Licence: https://github.com/ValveSoftware/source-sdk-2013/blob/master/LICENSE
#ifndef VPLANE_H
#define VPLANE_H

typedef int SideType;

#define VP_EPSILON	0.01f

class VPlane
{
public:
	VPlane();
	VPlane(const Vector &vNormal, vec_t dist);
	void		Init(const Vector &vNormal, vec_t dist);
	vec_t		DistTo(const Vector &vVec) const;
	VPlane&		operator=(const VPlane &thePlane);
	SideType	GetPointSide(const Vector &vPoint, vec_t sideEpsilon = VP_EPSILON) const;
	SideType	GetPointSideExact(const Vector &vPoint) const;
	SideType	BoxOnPlaneSide(const Vector &vMin, const Vector &vMax) const;
	VPlane		Flip();
	Vector		GetPointOnPlane() const;
	Vector		SnapPointToPlane(const Vector &vPoint) const;
public:
	Vector		m_Normal;
	vec_t		m_Dist;
};

#endif