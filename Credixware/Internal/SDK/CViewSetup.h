// Author: Valve Corporation
// Licence: https://github.com/ValveSoftware/source-sdk-2013/blob/master/LICENSE
#ifndef CVIEWSETUP_H
#define CVIEWSETUP_H

enum StereoEye_t
{
	STEREO_EYE_MONO = 0,
	STEREO_EYE_LEFT = 1,
	STEREO_EYE_RIGHT = 2,
	STEREO_EYE_MAX = 3,
};

class CViewSetup
{
public:
	CViewSetup()
	{
		m_flAspectRatio = 0.0f;
		m_bRenderToSubrectOfLargerScreen = false;
		m_bDoBloomAndToneMapping = true;
		m_bOrtho = false;
		m_bOffCenter = false;
		m_bCacheFullSceneState = false;
		m_bViewToProjectionOverride = false;
		m_eStereoEye = STEREO_EYE_MONO;
	}
	int			x;
	int			m_nUnscaledX;
	int			y;
	int			m_nUnscaledY;
	int			width;
	int			m_nUnscaledWidth;
	int			height;
	StereoEye_t m_eStereoEye;
	int			m_nUnscaledHeight;
	bool		m_bOrtho;
	float		m_OrthoLeft;
	float		m_OrthoTop;
	float		m_OrthoRight;
	float		m_OrthoBottom;
	float		fov;
	float		fovViewmodel;
	Vector		origin;
	QAngle		angles;
	float		zNear;
	float		zFar;
	float		zNearViewmodel;
	float		zFarViewmodel;
	bool		m_bRenderToSubrectOfLargerScreen;
	float		m_flAspectRatio;
	bool		m_bOffCenter;
	float		m_flOffCenterTop;
	float		m_flOffCenterBottom;
	float		m_flOffCenterLeft;
	float		m_flOffCenterRight;
	bool		m_bDoBloomAndToneMapping;
	bool		m_bCacheFullSceneState;
	bool        m_bViewToProjectionOverride;
	VMatrix     m_ViewToProjection;
};


#endif