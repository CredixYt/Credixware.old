// Author: Valve Corporation
// Licence: https://github.com/ValveSoftware/source-sdk-2013/blob/master/LICENSE
#ifndef CINPUT_H
#define CINPUT_H

#include "IInput.h"
#include "IClientThinkable.h"

enum JoystickAxis_t
{
	JOY_AXIS_X = 0,
	JOY_AXIS_Y,
	JOY_AXIS_Z,
	JOY_AXIS_U,
	JOY_AXIS_R,
	JOY_AXIS_V,
	MAX_JOYSTICK_AXES,
};

class CKeyboardKey
{
public:
	char				name[32];
	kbutton_t			*pkey;
	CKeyboardKey		*next;
};

template< class T >
class CHandle : public CBaseHandle
{
public:
	CHandle();
	CHandle(int iEntry, int iSerialNumber);
	CHandle(const CBaseHandle &handle);
	CHandle(T *pVal);
	static CHandle<T> FromIndex(int index);
	T*		Get() const;
	void	Set(const T* pVal);
	operator T*();
	operator T*() const;
	bool	operator !() const;
	bool	operator==(T *val) const;
	bool	operator!=(T *val) const;
	const CBaseHandle& operator=(const T *val);
	T*		operator->() const;
};

/*class CInput : public IInput
{
public:
	CInput(void);
	~CInput(void);
	virtual		void		Init_All(void);
	virtual		void		Shutdown_All(void);
	virtual		int			GetButtonBits(int);
	virtual		void		CreateMove(int sequence_number, float input_sample_frametime, bool active);
	virtual		void		ExtraMouseSample(float frametime, bool active);
	virtual		bool		WriteUsercmdDeltaToBuffer(bf_write *buf, int from, int to, bool isnewcommand);
	virtual		void		EncodeUserCmdToBuffer(bf_write& buf, int slot);
	virtual		void		DecodeUserCmdFromBuffer(bf_read& buf, int slot);
	virtual		CUserCmd	*GetUserCmd(int sequence_number);
	virtual		void		MakeWeaponSelection(C_BaseCombatWeapon *weapon);
	virtual		float		KeyState(kbutton_t *key);
	virtual		int			KeyEvent(int down, ButtonCode_t keynum, const char *pszCurrentBinding);
	virtual		kbutton_t	*FindKey(const char *name);
	virtual		void		ControllerCommands(void);
	virtual		void		Joystick_Advanced(void);
	virtual		void		Joystick_SetSampleTime(float frametime);
	virtual		void		IN_SetSampleTime(float frametime);
	virtual		void		AccumulateMouse(void);
	virtual		void		ActivateMouse(void);
	virtual		void		DeactivateMouse(void);
	virtual		void		ClearStates(void);
	virtual		float		GetLookSpring(void);
	virtual		void		GetFullscreenMousePos(int *mx, int *my, int *unclampedx = NULL, int *unclampedy = NULL);
	virtual		void		SetFullscreenMousePos(int mx, int my);
	virtual		void		ResetMouse(void);
	virtual		float		GetLastForwardMove(void);
	virtual		float		Joystick_GetForward(void);
	virtual		float		Joystick_GetSide(void);
	virtual		float		Joystick_GetPitch(void);
	virtual		float		Joystick_GetYaw(void);
	virtual		void		ClearInputButton(int bits);
	virtual		void		CAM_Think(void);
	virtual		int			CAM_IsThirdPerson(void);
	virtual		void		CAM_ToThirdPerson(void);
	virtual		void		CAM_ToFirstPerson(void);
	virtual		void		CAM_StartMouseMove(void);
	virtual		void		CAM_EndMouseMove(void);
	virtual		void		CAM_StartDistance(void);
	virtual		void		CAM_EndDistance(void);
	virtual		int			CAM_InterceptingMouse(void);
	virtual		void		CAM_ToOrthographic();
	virtual		bool		CAM_IsOrthographic() const;
	virtual		void		CAM_OrthographicSize(float& w, float& h) const;
	virtual		float		CAM_CapYaw(float fVal) const { return fVal; }
	virtual		float		CAM_CapPitch(float fVal) const { return fVal; }
	virtual		void		LevelInit(void);
	virtual		void		CAM_SetCameraThirdData(CameraThirdData_t *pCameraData, const QAngle &vecCameraOffset);
	virtual		void		CAM_CameraThirdThink(void);
	virtual	bool		EnableJoystickMode();
protected:
	void		Init_Camera(void);
	void		Init_Keyboard(void);
	void		Init_Mouse(void);
	void		Shutdown_Keyboard(void);
	void		AddKeyButton(const char *name, kbutton_t *pkb);
	void		ScaleMovements(CUserCmd *cmd);
	void		ComputeForwardMove(CUserCmd *cmd);
	void		ComputeUpwardMove(CUserCmd *cmd);
	void		ComputeSideMove(CUserCmd *cmd);
	void		AdjustAngles(float frametime);
	void		ClampAngles(QAngle& viewangles);
	void		AdjustPitch(float speed, QAngle& viewangles);
	virtual void AdjustYaw(float speed, QAngle& viewangles);
	float		DetermineKeySpeed(float frametime);
	void		GetAccumulatedMouseDeltasAndResetAccumulators(float *mx, float *my);
	void		GetMouseDelta(float inmousex, float inmousey, float *pOutMouseX, float *pOutMouseY);
	void		ScaleMouse(float *x, float *y);
	virtual void ApplyMouse(QAngle& viewangles, CUserCmd *cmd, float mouse_x, float mouse_y);
	virtual void MouseMove(CUserCmd *cmd);
	void		ControllerMove(float frametime, CUserCmd *cmd);
	void		JoyStickMove(float frametime, CUserCmd *cmd);
	float		ScaleAxisValue(const float axisValue, const float axisThreshold);
	virtual float JoyStickAdjustYaw(float flSpeed) { return flSpeed; }
	void		GetMousePos(int &x, int &y);
	void		SetMousePos(int x, int y);
	void		GetWindowCenter(int&x, int& y);
	void		CheckMouseAcclerationVars();
	void		ValidateUserCmd(CUserCmd *usercmd, int sequence_number);
public:
	typedef struct
	{
		unsigned int AxisFlags;
		unsigned int AxisMap;
		unsigned int ControlMap;
	} joy_axis_t;
	void		DescribeJoystickAxis(char const *axis, joy_axis_t *mapping);
	char const	*DescribeAxis(int index);
	enum
	{
		GAME_AXIS_NONE = 0,
		GAME_AXIS_FORWARD,
		GAME_AXIS_PITCH,
		GAME_AXIS_SIDE,
		GAME_AXIS_YAW,
		MAX_GAME_AXES
	};
	enum
	{
		CAM_COMMAND_NONE = 0,
		CAM_COMMAND_TOTHIRDPERSON = 1,
		CAM_COMMAND_TOFIRSTPERSON = 2
	};
	enum
	{
		MOUSE_ACCEL_THRESHHOLD1 = 0,
		MOUSE_ACCEL_THRESHHOLD2,
		MOUSE_SPEED_FACTOR,
		NUM_MOUSE_PARAMS,
	};
	bool		m_fMouseInitialized;
	bool		m_fMouseActive;
	bool		m_fJoystickAdvancedInit;
	bool		m_fHadJoysticks;
	float		m_flAccumulatedMouseXMovement;
	float		m_flAccumulatedMouseYMovement;
	float		m_flPreviousMouseXPosition;
	float		m_flPreviousMouseYPosition;
	float		m_flRemainingJoystickSampleTime;
	float		m_flKeyboardSampleTime;
	bool		m_fRestoreSPI;
	int			m_rgOrigMouseParms[NUM_MOUSE_PARAMS];
	int			m_rgNewMouseParms[NUM_MOUSE_PARAMS];
	bool		m_rgCheckMouseParam[NUM_MOUSE_PARAMS];
	bool		m_fMouseParmsValid;
	joy_axis_t m_rgAxes[MAX_JOYSTICK_AXES];
	CKeyboardKey *m_pKeys;
	bool		m_fCameraInterceptingMouse;
	bool		m_fCameraInThirdPerson;
	bool		m_fCameraMovingWithMouse;
	bool		m_fCameraDistanceMove;
	int			m_nCameraOldX;
	int			m_nCameraOldY;
	int			m_nCameraX;
	int			m_nCameraY;
	bool		m_CameraIsOrthographic;
	QAngle		m_angPreviousViewAngles;
	float		m_flLastForwardMove;
	float m_flPreviousJoystickForward;
	float m_flPreviousJoystickSide;
	float m_flPreviousJoystickPitch;
	float m_flPreviousJoystickYaw;
	class CVerifiedUserCmd
	{
	public:
		CUserCmd	m_cmd;
		CRC32_t		m_crc;
	};
	CUserCmd	*m_pCommands;
	CVerifiedUserCmd *m_pVerifiedCommands;
	CameraThirdData_t	*m_pCameraThirdData;
	CHandle< C_BaseCombatWeapon > m_hSelectedWeapon;
};*/

class CInput
{
public:
	class CVerifiedUserCmd
	{
	public:
		CUserCmd	m_cmd;
		CRC32_t		m_crc;
	};
public:
	void*               pvftable;                     //0x00
	bool                m_fTrackIRAvailable;          //0x04
	bool                m_fMouseInitialized;          //0x05
	bool                m_fMouseActive;               //0x06
	bool                m_fJoystickAdvancedInit;      //0x07
	char                pad_0x08[0x2C];               //0x08
	void*               m_pKeys;                      //0x34
	char                pad_0x38[0x64];               //0x38
	char                pad_0x39[0x8];               //0x38
	int					pad_0x41;
	int					pad_0x42;
	bool                m_fCameraInterceptingMouse;   //0x9C
	bool                m_fCameraInThirdPerson;       //0x9D
	bool                m_fCameraMovingWithMouse;     //0x9E
	Vector				m_vecCameraOffset;            //0xA0
	bool                m_fCameraDistanceMove;        //0xAC
	int                 m_nCameraOldX;                //0xB0
	int                 m_nCameraOldY;                //0xB4
	int                 m_nCameraX;                   //0xB8
	int                 m_nCameraY;                   //0xBC
	bool                m_CameraIsOrthographic;       //0xC0
	Vector              m_angPreviousViewAngles;      //0xC4
	Vector              m_angPreviousViewAnglesTilt;  //0xD0
	float               m_flLastForwardMove;          //0xDC
	int                 m_nClearInputState;           //0xE0
	char                pad_0xE4[0x8];                //0xE4
	CUserCmd*           m_pCommands;                  //0xEC
	CVerifiedUserCmd*   m_pVerifiedCommands;          //0xF0
};
#endif