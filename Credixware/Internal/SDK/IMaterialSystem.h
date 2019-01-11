// Author: Valve Corporation
// Licence: https://github.com/ValveSoftware/source-sdk-2013/blob/master/LICENSE
#ifndef IMATERIALSYSTEM_H
#define IMATERIALSYSTEM_H

#include "IAppSystem.h"
#include "basetypes.h"

DECLARE_POINTER_HANDLE(MaterialLock_t);

typedef void(*MaterialBufferReleaseFunc_t)();
typedef void(*MaterialBufferRestoreFunc_t)(int nChangeFlags);
typedef void(*ModeChangeCallbackFunc_t)(void);

typedef int VertexBufferHandle_t;
typedef unsigned short MaterialHandle_t;

class IMaterialProxyFactory;
class IMaterialSystemHardwareConfig;
class IShader;
class ITexture;
class IMatRenderContext;
class IFileList;
struct MaterialThreadMode_t;
struct MaterialSystem_Config_t;
struct MaterialSystemHardwareIdentifier_t;

struct MaterialAdapterInfo_t
{
	char m_pDriverName[512];
	unsigned int m_VendorID;
	unsigned int m_DeviceID;
	unsigned int m_SubSysID;
	unsigned int m_Revision;
	int m_nDXSupportLevel;
	int m_nMaxDXSupportLevel;
	unsigned int m_nDriverVersionHigh;
	unsigned int m_nDriverVersionLow;
};

struct MaterialVideoMode_t
{
	int m_Width;
	int m_Height;
	ImageFormat m_Format;
	int m_RefreshRate;
};

enum HDRType_t
{
	HDR_TYPE_NONE,
	HDR_TYPE_INTEGER,
	HDR_TYPE_FLOAT,
};

enum RenderTargetSizeMode_t
{
	RT_SIZE_NO_CHANGE = 0,
	RT_SIZE_DEFAULT = 1,
	RT_SIZE_PICMIP = 2,
	RT_SIZE_HDR = 3,
	RT_SIZE_FULL_FRAME_BUFFER = 4,
	RT_SIZE_OFFSCREEN = 5,
	RT_SIZE_FULL_FRAME_BUFFER_ROUNDED_UP = 6,
	RT_SIZE_REPLAY_SCREENSHOT = 7,
	RT_SIZE_LITERAL = 8
};

enum MaterialRenderTargetDepth_t
{
	MATERIAL_RT_DEPTH_SHARED = 0x0,
	MATERIAL_RT_DEPTH_SEPARATE = 0x1,
	MATERIAL_RT_DEPTH_NONE = 0x2,
	MATERIAL_RT_DEPTH_ONLY = 0x3,
};

enum CompiledVtfFlags
{
	TEXTUREFLAGS_POINTSAMPLE = 0x00000001,
	TEXTUREFLAGS_TRILINEAR = 0x00000002,
	TEXTUREFLAGS_CLAMPS = 0x00000004,
	TEXTUREFLAGS_CLAMPT = 0x00000008,
	TEXTUREFLAGS_ANISOTROPIC = 0x00000010,
	TEXTUREFLAGS_HINT_DXT5 = 0x00000020,
	TEXTUREFLAGS_SRGB = 0x00000040,
	TEXTUREFLAGS_NORMAL = 0x00000080,
	TEXTUREFLAGS_NOMIP = 0x00000100,
	TEXTUREFLAGS_NOLOD = 0x00000200,
	TEXTUREFLAGS_ALL_MIPS = 0x00000400,
	TEXTUREFLAGS_PROCEDURAL = 0x00000800,
	TEXTUREFLAGS_ONEBITALPHA = 0x00001000,
	TEXTUREFLAGS_EIGHTBITALPHA = 0x00002000,
	TEXTUREFLAGS_ENVMAP = 0x00004000,
	TEXTUREFLAGS_RENDERTARGET = 0x00008000,
	TEXTUREFLAGS_DEPTHRENDERTARGET = 0x00010000,
	TEXTUREFLAGS_NODEBUGOVERRIDE = 0x00020000,
	TEXTUREFLAGS_SINGLECOPY = 0x00040000,
	TEXTUREFLAGS_STAGING_MEMORY = 0x00080000,
	TEXTUREFLAGS_IMMEDIATE_CLEANUP = 0x00100000,
	TEXTUREFLAGS_IGNORE_PICMIP = 0x00200000,
	TEXTUREFLAGS_UNUSED_00400000 = 0x00400000,
	TEXTUREFLAGS_NODEPTHBUFFER = 0x00800000,
	TEXTUREFLAGS_UNUSED_01000000 = 0x01000000,
	TEXTUREFLAGS_CLAMPU = 0x02000000,
	TEXTUREFLAGS_VERTEXTEXTURE = 0x04000000,
	TEXTUREFLAGS_SSBUMP = 0x08000000,
	TEXTUREFLAGS_UNUSED_10000000 = 0x10000000,
	TEXTUREFLAGS_BORDER = 0x20000000,
	TEXTUREFLAGS_UNUSED_40000000 = 0x40000000,
	TEXTUREFLAGS_UNUSED_80000000 = 0x80000000,
};

enum MaterialContextType_t
{
	MATERIAL_HARDWARE_CONTEXT,
	MATERIAL_QUEUED_CONTEXT,
	MATERIAL_NULL_CONTEXT
};

struct MaterialSystem_SortInfo_t
{
	IMaterial	*material;
	int			lightmapPageID;
};

class IMaterialSystem : public IAppSystem
{
public:
	virtual bool Connect(CreateInterfaceFn factory) = 0;
	virtual void Disconnect() = 0;
	virtual void *QueryInterface(const char *pInterfaceName) = 0;
	virtual InitReturnVal_t Init() = 0;
	virtual void Shutdown() = 0;
	virtual CreateInterfaceFn	Init(char const* pShaderAPIDLL, IMaterialProxyFactory *pMaterialProxyFactory, CreateInterfaceFn fileSystemFactory, CreateInterfaceFn cvarFactory = NULL) = 0;
	virtual void				SetShaderAPI(char const *pShaderAPIDLL) = 0;
	virtual void				SetAdapter(int nAdapter, int nFlags) = 0;
	virtual void				ModInit() = 0;
	virtual void				ModShutdown() = 0;
	virtual void					SetThreadMode(MaterialThreadMode_t mode, int nServiceThread = -1) = 0;
	virtual MaterialThreadMode_t	GetThreadMode() = 0;
	virtual bool					IsRenderThreadSafe() = 0;
	virtual void					ExecuteQueued() = 0;
	virtual IMaterialSystemHardwareConfig *GetHardwareConfig(const char *pVersion, int *returnCode) = 0;
	virtual bool				UpdateConfig(bool bForceUpdate) = 0;
	virtual bool				OverrideConfig(const MaterialSystem_Config_t &config, bool bForceUpdate) = 0;
	virtual const MaterialSystem_Config_t &GetCurrentConfigForVideoCard() const = 0;
	virtual bool				GetRecommendedConfigurationInfo(int nDXLevel, KeyValues * pKeyValues) = 0;
	virtual int					GetDisplayAdapterCount() const = 0;
	virtual int					GetCurrentAdapter() const = 0;
	virtual void				GetDisplayAdapterInfo(int adapter, MaterialAdapterInfo_t& info) const = 0;
	virtual int					GetModeCount(int adapter) const = 0;
	virtual void				GetModeInfo(int adapter, int mode, MaterialVideoMode_t& info) const = 0;
	virtual void				AddModeChangeCallBack(ModeChangeCallbackFunc_t func) = 0;
	virtual void				GetDisplayMode(MaterialVideoMode_t& mode) const = 0;
	virtual bool				SetMode(void* hwnd, const MaterialSystem_Config_t &config) = 0;
	virtual bool				SupportsMSAAMode(int nMSAAMode) = 0;
	virtual const MaterialSystemHardwareIdentifier_t &GetVideoCardIdentifier(void) const = 0;
	virtual void				SpewDriverInfo() const = 0;
	virtual void				GetDXLevelDefaults(uint &max_dxlevel,uint &recommended_dxlevel) = 0;
	virtual void				GetBackBufferDimensions(int &width, int &height) const = 0;
	virtual ImageFormat			GetBackBufferFormat() const = 0;
	virtual bool				SupportsHDRMode(HDRType_t nHDRModede) = 0;
	virtual bool				AddView(void* hwnd) = 0;
	virtual void				RemoveView(void* hwnd) = 0;
	virtual void				SetView(void* hwnd) = 0;
	virtual void				BeginFrame(float frameTime) = 0;
	virtual void				EndFrame() = 0;
	virtual void				Flush(bool flushHardware = false) = 0;
	virtual void				SwapBuffers() = 0;
	virtual void				EvictManagedResources() = 0;
	virtual void				ReleaseResources(void) = 0;
	virtual void				ReacquireResources(void) = 0;
	virtual void				AddReleaseFunc(MaterialBufferReleaseFunc_t func) = 0;
	virtual void				RemoveReleaseFunc(MaterialBufferReleaseFunc_t func) = 0;
	virtual void				AddRestoreFunc(MaterialBufferRestoreFunc_t func) = 0;
	virtual void				RemoveRestoreFunc(MaterialBufferRestoreFunc_t func) = 0;
	virtual void				ResetTempHWMemory(bool bExitingLevel = false) = 0;
	virtual void				HandleDeviceLost() = 0;
	virtual int					ShaderCount() const = 0;
	virtual int					GetShaders(int nFirstShader, int nMaxCount, IShader **ppShaderList) const = 0;
	virtual int					ShaderFlagCount() const = 0;
	virtual const char *		ShaderFlagName(int nIndex) const = 0;
	virtual void				GetShaderFallback(const char *pShaderName, char *pFallbackShader, int nFallbackLength) = 0;
	virtual IMaterialProxyFactory *GetMaterialProxyFactory() = 0;
	virtual void				SetMaterialProxyFactory(IMaterialProxyFactory* pFactory) = 0;
	virtual void				EnableEditorMaterials() = 0;
	virtual void				SetInStubMode(bool bInStubMode) = 0;
	virtual void				DebugPrintUsedMaterials(const char *pSearchSubString, bool bVerbose) = 0;
	virtual void				DebugPrintUsedTextures(void) = 0;
	virtual void				ToggleSuppressMaterial(char const* pMaterialName) = 0;
	virtual void				ToggleDebugMaterial(char const* pMaterialName) = 0;
	virtual bool				UsingFastClipping(void) = 0;
	virtual int					StencilBufferBits(void) = 0;
	virtual void				UncacheAllMaterials() = 0;
	virtual void				UncacheUnusedMaterials(bool bRecomputeStateSnapshots = false) = 0;
	virtual void				CacheUsedMaterials() = 0;
	virtual void				ReloadTextures() = 0;
	virtual void				ReloadMaterials(const char *pSubString = NULL) = 0;
	virtual IMaterial *			CreateMaterial(const char *pMaterialName, KeyValues *pVMTKeyValues) = 0;
	virtual IMaterial *			FindMaterial(char const* pMaterialName, const char *pTextureGroupName, bool complain = true, const char *pComplainPrefix = NULL) = 0;
	virtual bool				IsMaterialLoaded(char const* pMaterialName) = 0;
	virtual MaterialHandle_t	FirstMaterial() {
		typedef MaterialHandle_t(__thiscall* Fn)(void*);
		return Utils::GetVFunc<Fn>(this, 86)(this);
	}
	virtual MaterialHandle_t	NextMaterial(MaterialHandle_t h) {
		typedef MaterialHandle_t(__thiscall* Fn)(void*, MaterialHandle_t);
		return Utils::GetVFunc<Fn>(this, 87)(this, h);
	}
	/*virtual MaterialHandle_t	InvalidMaterial() {
		typedef MaterialHandle_t(__thiscall* Fn)(void*);
		return Utils::GetVFunc<Fn>(this, 88)(this);
	}*/
	virtual MaterialHandle_t	InvalidMaterial() = 0;
	virtual IMaterial*			GetMaterial(MaterialHandle_t h) {
		typedef IMaterial*(__thiscall* Fn)(void*, MaterialHandle_t);
		return Utils::GetVFunc<Fn>(this, 89)(this, h);
	}
	virtual int					GetNumMaterials() const = 0;
	virtual void				SetAsyncTextureLoadCache(void* hFileCache) = 0;
	virtual ITexture *			FindTexture(char const* pTextureName, const char *pTextureGroupName, bool complain = true, int nAdditionalCreationFlags = 0) = 0;
	virtual bool				IsTextureLoaded(char const* pTextureName) const = 0;
	virtual ITexture *			CreateProceduralTexture(const char	*pTextureName, const char *pTextureGroupName, int w, int h, ImageFormat fmt, int nFlags) = 0;
	virtual void				BeginRenderTargetAllocation() = 0;
	virtual void				EndRenderTargetAllocation() = 0;
	virtual ITexture *			CreateRenderTargetTexture(int w, int h, RenderTargetSizeMode_t sizeMode, ImageFormat	format, MaterialRenderTargetDepth_t depth = MATERIAL_RT_DEPTH_SHARED) = 0;
	virtual ITexture *			CreateNamedRenderTargetTextureEx(const char *pRTName, int w, int h, RenderTargetSizeMode_t sizeMode, ImageFormat format, MaterialRenderTargetDepth_t depth = MATERIAL_RT_DEPTH_SHARED, unsigned int textureFlags = TEXTUREFLAGS_CLAMPS | TEXTUREFLAGS_CLAMPT, unsigned int renderTargetFlags = 0) = 0;
	virtual ITexture *			CreateNamedRenderTargetTexture(const char *pRTName, int w, int h, RenderTargetSizeMode_t sizeMode, ImageFormat format, MaterialRenderTargetDepth_t depth = MATERIAL_RT_DEPTH_SHARED, bool bClampTexCoords = true, bool bAutoMipMap = false) = 0;
	virtual ITexture *			CreateNamedRenderTargetTextureEx2(const char *pRTName, int w, int h, RenderTargetSizeMode_t sizeMode, ImageFormat format, MaterialRenderTargetDepth_t depth = MATERIAL_RT_DEPTH_SHARED, unsigned int textureFlags = TEXTUREFLAGS_CLAMPS | TEXTUREFLAGS_CLAMPT, unsigned int renderTargetFlags = 0) = 0;
	virtual void				BeginLightmapAllocation() = 0;
	virtual void				EndLightmapAllocation() = 0;
	virtual int 				AllocateLightmap(int width, int height, int offsetIntoLightmapPage[2], IMaterial *pMaterial) = 0;
	virtual int					AllocateWhiteLightmap(IMaterial *pMaterial) = 0;
	virtual void				UpdateLightmap(int lightmapPageID, int lightmapSize[2], int offsetIntoLightmapPage[2], float *pFloatImage, float *pFloatImageBump1, float *pFloatImageBump2, float *pFloatImageBump3) = 0;
	virtual int					GetNumSortIDs() = 0;
	virtual void				GetSortInfo(MaterialSystem_SortInfo_t *sortInfoArray) = 0;
	virtual void				GetLightmapPageSize(int lightmap, int *width, int *height) const = 0;
	virtual void				ResetMaterialLightmapPageInfo() = 0;
	virtual void				ClearBuffers(bool bClearColor, bool bClearDepth, bool bClearStencil = false) = 0;
	virtual IMatRenderContext *	GetRenderContext() = 0;
	virtual bool				SupportsShadowDepthTextures(void) = 0;
	virtual void				BeginUpdateLightmaps(void) = 0;
	virtual void				EndUpdateLightmaps(void) = 0;
	virtual MaterialLock_t		Lock() = 0;
	virtual void				Unlock(MaterialLock_t) = 0;
	virtual ImageFormat			GetShadowDepthTextureFormat() = 0;
	virtual bool				SupportsFetch4(void) = 0;
	virtual IMatRenderContext *CreateRenderContext(MaterialContextType_t type) = 0;
	virtual IMatRenderContext *SetRenderContext(IMatRenderContext *) = 0;
	virtual bool				SupportsCSAAMode(int nNumSamples, int nQualityLevel) = 0;
	virtual void				RemoveModeChangeCallBack(ModeChangeCallbackFunc_t func) = 0;
	virtual IMaterial *			FindProceduralMaterial(const char *pMaterialName, const char *pTextureGroupName, KeyValues *pVMTKeyValues) = 0;
	virtual ImageFormat			GetNullTextureFormat() = 0;
	virtual void				AddTextureAlias(const char *pAlias, const char *pRealName) = 0;
	virtual void				RemoveTextureAlias(const char *pAlias) = 0;
	virtual int					AllocateDynamicLightmap(int lightmapSize[2], int *pOutOffsetIntoPage, int frameID) = 0;
	virtual void				SetExcludedTextures(const char *pScriptName) = 0;
	virtual void				UpdateExcludedTextures(void) = 0;
	virtual bool				IsInFrame() const = 0;
	virtual void				CompactMemory() = 0;
	virtual void ReloadFilesInList(IFileList *pFilesToReload) = 0;
	virtual	bool				AllowThreading(bool bAllow, int nServiceThread) = 0;
	virtual IMaterial *			FindMaterialEx(char const* pMaterialName, const char *pTextureGroupName, int nContext, bool complain = true, const char *pComplainPrefix = NULL) = 0;
	virtual void				SetRenderTargetFrameBufferSizeOverrides(int nWidth, int nHeight) = 0;
	virtual void				GetRenderTargetFrameBufferDimensions(int & nWidth, int & nHeight) = 0;
	virtual char				*GetDisplayDeviceName() const = 0;
};


#endif