#ifndef __chkvmhdd_h__
#define __chkvmhdd_h__
#endif

//////////////////////////////////////////////////////////////////////////
// Global variables
//////////////////////////////////////////////////////////////////////////
DEFINE_GUID(GUID_DEVCLASS_DISKDRIVE, 0x4d36e967L, 0xe325, 0x11ce, 0xbf, 0xc1, 0x08, 0x00, 0x2b, 0xe1, 0x03, 0x18);

//////////////////////////////////////////////////////////////////////////
// IOCTL code definition
//////////////////////////////////////////////////////////////////////////
#define IOCTL_STORAGE_QUERY_PROPERTY CTL_CODE(IOCTL_STORAGE_BASE, 0x0500, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_VMDETECTORSYS_DEVMODEL_FIX CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_OUT_DIRECT , FILE_ANY_ACCESS)
#define IOCTL_VMDETECTORSYS_VMDISKREG_FIX CTL_CODE(FILE_DEVICE_UNKNOWN, 0x801, METHOD_OUT_DIRECT , FILE_ANY_ACCESS)

//////////////////////////////////////////////////////////////////////////
// Enum definitions
//////////////////////////////////////////////////////////////////////////
typedef enum RegistryKey_t{
	HKCR=0,
	HKCC,
	HKCU,
	HKLM,
	HKU
}RegistryKey;

typedef enum RegistryKeyPatch_t{
	PATCH_WMI_PCI_REGKEY = 0,
	PATCH_WMI_DISKDRIVE_SCSI_REGKEY = 1,
	PATCH_UNKNOWN_REGKEY
}RegistryKeyPatchType;

typedef enum Sid_t{
	EVERYONE=1,
	CREATOR,
	LOCALAUTH,
	NONUNIQUE,
	NTAUTH
}SidType;

//////////////////////////////////////////////////////////////////////////
// Structure definition
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
// Function prototype
//////////////////////////////////////////////////////////////////////////
BOOLEAN CheckStorageProperty();
BOOLEAN CheckIsVmHdd();
BOOLEAN CheckVmIdeReg();
BOOLEAN CheckVmDiskReg();
BOOLEAN CheckVmPartMgrReg();
BOOLEAN VMRegPatcher(int);
BOOLEAN PatchRegistryValueData(RegistryKey, CHAR *, CHAR *, CHAR *, DWORD );
BOOLEAN BlockAccessPartMgrReg();
BOOLEAN BlockAccessVmIdeReg();
BOOLEAN	BlockAccessVmPciReg();
