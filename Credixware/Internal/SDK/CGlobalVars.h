// Author: Valve Corporation
// Licence: https://github.com/ValveSoftware/source-sdk-2013/blob/master/LICENSE
#ifndef CGLOBALVARS_H
#define CGLOBALVARS_H

class CGlobalVars
{
public:
	float realtime;
	int framecount;
	float absoluteframetime;
	float absoluteframestarttimestddev;
	float curtime;
	float frametime;
	int maxClients;
	int tickcount;
	float interval_per_tick;
	float interpolation_amount;
	int simTicksThisFrame;
	int network_protocol;
	void* pSaveData;
	bool m_bClient;
	bool m_bRemoteClient;
private:
	int nTimestampNetworkingBase;
	int nTimestampRandomizeWindow;
};

#endif