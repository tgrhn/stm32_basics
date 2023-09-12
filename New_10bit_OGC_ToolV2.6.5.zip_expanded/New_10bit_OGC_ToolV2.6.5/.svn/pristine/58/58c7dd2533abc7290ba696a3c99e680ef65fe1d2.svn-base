/********************************************************************************/
/*   The  Software  is  proprietary,  confidential,  and  valuable to Realsil   */
/*   Semiconductor  Corporation  ("Realsil").  All  rights, including but not   */
/*   limited  to  copyrights,  patents,  trademarks, trade secrets, mask work   */
/*   rights, and other similar rights and interests, are reserved to Realsil.   */
/*   Without  prior  written  consent  from  Realsil,  copying, reproduction,   */
/*   modification,  distribution,  or  otherwise  is strictly prohibited. The   */
/*   Software  shall  be  kept  strictly  in  confidence,  and  shall  not be   */
/*   disclosed to or otherwise accessed by any third party.                     */
/*   c<2003> - <2014>                                                           */
/*   The Software is provided "AS IS" without any warranty of any kind,         */
/*   express, implied, statutory or otherwise.                                  */
/********************************************************************************/

#ifndef _COMM_EXPORT_H_
#define _COMM_EXPORT_H_

#include "Common.h"
#include "Comm_Include.h"

typedef struct STRUCT_REG_FORMER_VALUE
{
    BYTE ucPageIndex;
    BYTE ucDebugSlave;
    BOOL bDebugSlave;
    BYTE ucIspSlave;
    BOOL bIspSlave;
    BYTE ucAuxPowerVal;
    BOOL bAuxPower;
    BYTE ucClkFreqVal;
    BOOL bClkFreq;
    BYTE ucClkGateVal;
    BOOL bClkGate;
    BYTE ucHWAutoVal;
    BOOL bHWAuto;
    STRUCT_REG_FORMER_VALUE()
        : bDebugSlave(FALSE)
        , bIspSlave(FALSE)
        , bAuxPower(FALSE)
        , bClkFreq(FALSE)
        , bClkGate(FALSE)
        , bHWAuto(FALSE)
    {}
}STRUCT_REG_FORMER_VALUE;

//////////////////////////////////////////////////////////////////////////
// struct define
//////////////////////////////////////////////////////////////////////////
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsInitiallize)();
// rsGetCommCount: 
// Get current device count, this function must be called after rsInitiallize has been called
typedef WORD (*func_rsGetCommCount)();
typedef STRUCT_ENUM_COMM_ID (*func_rsGetCommID)();
typedef void (*func_rsGetCommName)(TCHAR* szName, WORD usLength);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsGetCommFile)(STRUCT_COMM_INFO *stCommVer);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsSetCommByIndex)(WORD usCommIndex);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsSetCommByID)(STRUCT_ENUM_COMM_ID enumCommID);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsSetDebugSlave)(BYTE ucDebugSlave);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsSetIspSlave)(BYTE ucIspSlave);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsSetIspContinuousSlave)(BYTE ucIspContinuousSlave);
typedef BYTE (*func_rsGetDebugSlave)();
typedef BYTE (*func_rsGetIspSlave)();
typedef BYTE (*func_rsGetIspContinuousSlave)();
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsSetDebugMode)(STRUCT_ENUM_DEBUG_TYPE enumDebugType);
typedef STRUCT_ENUM_DEBUG_TYPE (*func_rsGetDebugMode)();
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsReadReg)(BYTE ucReg, BYTE* pucValue);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsWriteReg)(BYTE ucReg, BYTE ucValue);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsReadRegs)(BYTE ucReg, WORD usLength, LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsWriteRegs)(BYTE ucReg, WORD usLength, LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsWriteRegBit)(BYTE ucReg, BYTE ucAnd, BYTE ucOr);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsWritePortRegBit)(BYTE ucAddrReg, BYTE ucDataReg, BYTE ucAnd, BYTE ucOr);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsReadRegEx)(WORD usReg, BYTE* pucValue);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsWriteRegEx)(WORD usReg, BYTE ucValue);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsReadRegsEx)(WORD usReg, WORD usLength, LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsWriteRegsEx)(WORD usReg, WORD usLength, LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsWriteRegBitEx)(WORD usReg, BYTE ucAnd, BYTE ucOr);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsWritePortRegBitEx)(WORD usAddrReg, WORD usDataReg, BYTE ucAnd, BYTE ucOr);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsReadSysDevice)(BYTE ucSlave, BYTE ucSub, BYTE ucLength, LPBYTE pucBuf);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsWriteSysDevice)(BYTE ucSlave, BYTE ucSub, BYTE ucLength, LPBYTE pucBuf);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsReadWordSysDevice)(BYTE ucSlave, WORD usSub, BYTE ucLength, LPBYTE pucBuf);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsWriteWordSysDevice)(BYTE ucSlave, WORD usSub, BYTE ucLength, LPBYTE pucBuf);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsScalerStop)();
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsScalerRun)();

typedef WORD (*func_rsGetI2CPageLength)();
typedef WORD (*func_rsGetNativePageLength)();
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsI2CWrite)(BYTE ucSlave, BYTE ucSub, WORD usLength, const LPBYTE pucBuf);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsI2CRead)(BYTE ucSlave, BYTE ucSub, WORD usLength, LPBYTE pucBuf);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsI2CWriteByte)(BYTE ucSlave, BYTE ucSub, BYTE ucValue);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsI2CCurrentRead)(BYTE ucSlave, WORD usLength, LPBYTE pucBuf);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsI2CWordWrite)(BYTE ucSlave, WORD usSub, WORD usLength, const LPBYTE pucBuf);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsI2C2SubWrite)(BYTE ucSlave, BYTE ucSub0, BYTE ucSub1, WORD usLength, const LPBYTE pucBuf);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsI2CWordRead)(BYTE ucSlave, WORD usSub, WORD usLength, LPBYTE pucBuf);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsI2C2SubRead)(BYTE ucSlave, BYTE ucSub0, BYTE ucSub1, WORD usLength, LPBYTE pucBuf);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsI2CWriteEx)(BYTE ucSlave, BYTE ucSub, WORD usLength, const LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsI2CReadEx)(BYTE ucSlave, BYTE ucSub, WORD usLength, LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsI2CCurrentReadEx)(BYTE ucSlave, WORD usLength, LPBYTE pucBuf);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsI2CWordWriteEx)(BYTE ucSlave, WORD usSub, WORD usLength, const LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsI2C2SubWriteEx)(BYTE ucSlave, BYTE ucSub0, BYTE ucSub1, WORD usLength, const LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsI2CWordReadEx)(BYTE ucSlave, WORD usSub, WORD usLength, LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsI2C2SubReadEx)(BYTE ucSlave, BYTE ucSub0, BYTE ucSub1, WORD usLength, LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsAdjustOption)();
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsSetI2CSpeed)(WORD usSpeed);
typedef WORD (*func_rsGetI2CSpeed)();
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsSetAuxMode)(STRUCT_AUXMODE_STRUCT stAuxMode);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsSetWaitingMode)(STRUCT_WAITING_STRUCT stWaiting);
typedef STRUCT_WAITING_STRUCT (*func_rsGetWaitingMode)();
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsWriteMcuReg)(WORD usReg, BYTE ucValue);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsWriteMcuRegBit)(WORD usReg, BYTE ucAnd, BYTE ucOr);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsReadMcuReg)(WORD usReg, BYTE* pucValue);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsWriteMcuRegs)(WORD usReg, WORD usLength, LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsReadMcuRegs)(WORD usReg, WORD usLength, LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsWriteContinuousMcuReg)(BYTE ucSub, WORD usLength, LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsReadContinuousMcuReg)(BYTE ucSub, WORD usLength, LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsReleaseDev)();
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsNativeWrite)(INT nAddress, WORD usLength, const LPBYTE pucBuf);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsNativeRead)(INT nAddress, WORD usLength, LPBYTE pucBuf);
typedef void (*func_rsSetConfigFilePath)(TCHAR *pcConfigFilePath);
typedef HANDLE (*func_rsGetDeviceHandler)();
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsResetFirmware)();
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsEnterIspMode)(WORD usRetryTimes);
typedef DWORD (*func_rsGetSMBUSDataType)();
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsSetSMBUSDataType)(DWORD ulSMBUSDataType);
typedef BYTE (*func_rsGetDeviceCount)();
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsRemoveDevice)();
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsAutoDetectSlaveAddr)();
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsDDCCIWrite)(BYTE ucSlave, BYTE ucSub, BYTE ucLength, const LPBYTE pucBuf);
typedef STRUCT_ENUM_ERROR_TYPE (*func_rsDDCCIRead)(BYTE ucSlave, BYTE ucSub, BYTE ucLength, LPBYTE pucBuf);

class CRsComm
{
public:
    CRsComm();
    ~CRsComm();

public:
    BOOL LoadCommDllFile(TCHAR* pcFile);
    void FreeCommDllFile();
    STRUCT_ENUM_ERROR_TYPE Initiallize();
    // Get current device count, this function must be called after rsInitiallize has been called
    WORD GetCommCount();
    STRUCT_ENUM_COMM_ID GetCommID();
    void GetCommName(TCHAR* szName, WORD usLength);
    STRUCT_ENUM_ERROR_TYPE GetCommFile(STRUCT_COMM_INFO *pstCommVer);
    STRUCT_ENUM_ERROR_TYPE SetCommByIndex(WORD usCommIndex);
    STRUCT_ENUM_ERROR_TYPE SetCommByID(STRUCT_ENUM_COMM_ID enumCommID);
    STRUCT_ENUM_ERROR_TYPE SetDebugSlave(BYTE ucDebugSlave);
    STRUCT_ENUM_ERROR_TYPE SetIspSlave(BYTE ucIspSlave);
    STRUCT_ENUM_ERROR_TYPE SetIspContinuousSlave(BYTE ucIspContinuousSlave);
    BYTE GetDebugSlave();
    BYTE GetIspSlave();
    BYTE GetIspContinuousSlave();
    STRUCT_ENUM_ERROR_TYPE SetDebugMode(STRUCT_ENUM_DEBUG_TYPE enumDebugType);
    STRUCT_ENUM_DEBUG_TYPE GetDebugMode();
    virtual STRUCT_ENUM_ERROR_TYPE ReadReg(BYTE ucReg, BYTE* pucValue);
    virtual STRUCT_ENUM_ERROR_TYPE WriteReg(BYTE ucReg, BYTE ucValue);
    STRUCT_ENUM_ERROR_TYPE ReadRegs(BYTE ucReg, WORD usLength, LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc);
    STRUCT_ENUM_ERROR_TYPE WriteRegs(BYTE ucReg, WORD usLength, LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc);
    STRUCT_ENUM_ERROR_TYPE WriteRegBit(BYTE ucReg, BYTE ucAnd, BYTE ucOr);
    STRUCT_ENUM_ERROR_TYPE WritePortRegBit(BYTE ucAddrReg, BYTE ucDataReg, BYTE ucAnd, BYTE ucOr);
    virtual STRUCT_ENUM_ERROR_TYPE ReadRegEx(WORD usReg, BYTE* pucValue);
    virtual STRUCT_ENUM_ERROR_TYPE WriteRegEx(WORD usReg, BYTE ucValue);
    STRUCT_ENUM_ERROR_TYPE ReadRegsEx(WORD usReg, WORD usLength, LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc);
    STRUCT_ENUM_ERROR_TYPE WriteRegsEx(WORD usReg, WORD usLength, LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc);
    STRUCT_ENUM_ERROR_TYPE WriteRegBitEx(WORD usReg, BYTE ucAnd, BYTE ucOr);
    STRUCT_ENUM_ERROR_TYPE WritePortRegBitEx(WORD usAddrReg, WORD usDataReg, BYTE ucAnd, BYTE ucOr);
    STRUCT_ENUM_ERROR_TYPE ReadSysDevice(BYTE ucSlave, BYTE ucSub, BYTE ucLength, LPBYTE pucBuf);
    STRUCT_ENUM_ERROR_TYPE WriteSysDevice(BYTE ucSlave, BYTE ucSub, BYTE ucLength, LPBYTE pucBuf);
    STRUCT_ENUM_ERROR_TYPE ReadWordSysDevice(BYTE ucSlave, WORD usSub, BYTE ucLength, LPBYTE pucBuf);
    STRUCT_ENUM_ERROR_TYPE WriteWordSysDevice(BYTE ucSlave, WORD usSub, BYTE ucLength, LPBYTE pucBuf);
    virtual STRUCT_ENUM_ERROR_TYPE ScalerStop();
    virtual STRUCT_ENUM_ERROR_TYPE ScalerRun();

    WORD GetI2CPageLength();
    WORD GetNativePageLength();
    STRUCT_ENUM_ERROR_TYPE I2CWrite(BYTE ucSlave, BYTE ucSub, WORD usLength, const LPBYTE pucBuf);
    STRUCT_ENUM_ERROR_TYPE I2CRead(BYTE ucSlave, BYTE ucSub, WORD usLength, LPBYTE pucBuf);
    STRUCT_ENUM_ERROR_TYPE I2CWriteByte(BYTE ucSlave, BYTE ucSub, BYTE ucValue);
    STRUCT_ENUM_ERROR_TYPE I2CCurrentRead(BYTE ucSlave, WORD usLength, LPBYTE pucBuf);
    STRUCT_ENUM_ERROR_TYPE I2CWordWrite(BYTE ucSlave, WORD usSub, WORD usLength, const LPBYTE pucBuf);
    STRUCT_ENUM_ERROR_TYPE I2C2SubWrite(BYTE ucSlave, BYTE ucSub0, BYTE ucSub1, WORD usLength, const LPBYTE pucBuf);
    STRUCT_ENUM_ERROR_TYPE I2CWordRead(BYTE ucSlave, WORD usSub, WORD usLength, LPBYTE pucBuf);
    STRUCT_ENUM_ERROR_TYPE I2C2SubRead(BYTE ucSlave, BYTE ucSub0, BYTE ucSub1, WORD usLength, LPBYTE pucBuf);
    STRUCT_ENUM_ERROR_TYPE I2CWriteEx(BYTE ucSlave, BYTE ucSub, WORD usLength, const LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc);
    STRUCT_ENUM_ERROR_TYPE I2CReadEx(BYTE ucSlave, BYTE ucSub, WORD usLength, LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc);
    STRUCT_ENUM_ERROR_TYPE I2CCurrentReadEx(BYTE ucSlave, WORD usLength, LPBYTE pucBuf);
    STRUCT_ENUM_ERROR_TYPE I2CWordWriteEx(BYTE ucSlave, WORD usSub, WORD usLength, const LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc = _INCTYPE_AUTO);
    STRUCT_ENUM_ERROR_TYPE I2C2SubWriteEx(BYTE ucSlave, BYTE ucSub0, BYTE ucSub1, WORD usLength, const LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc = _INCTYPE_AUTO);
    STRUCT_ENUM_ERROR_TYPE I2CWordReadEx(BYTE ucSlave, WORD usSub, WORD usLength, LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc = _INCTYPE_AUTO);
    STRUCT_ENUM_ERROR_TYPE I2C2SubReadEx(BYTE ucSlave, BYTE ucSub0, BYTE ucSub1, WORD usLength, LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc = _INCTYPE_AUTO);
    STRUCT_ENUM_ERROR_TYPE AdjustOption();
    STRUCT_ENUM_ERROR_TYPE SetI2CSpeed(WORD usSpeed);
    WORD GetI2CSpeed();
    STRUCT_ENUM_ERROR_TYPE SetAuxMode(STRUCT_AUXMODE_STRUCT stAuxMode);
    STRUCT_ENUM_ERROR_TYPE SetWaitingMode(STRUCT_WAITING_STRUCT stWaiting);
    STRUCT_WAITING_STRUCT GetWaitingMode();
    STRUCT_ENUM_ERROR_TYPE WriteMcuReg(WORD usReg, BYTE ucValue);
    STRUCT_ENUM_ERROR_TYPE WriteMcuRegBit(WORD usReg, BYTE ucAnd, BYTE ucOr);
    STRUCT_ENUM_ERROR_TYPE ReadMcuReg(WORD usReg, BYTE* pucValue);
    STRUCT_ENUM_ERROR_TYPE WriteMcuRegs(WORD usReg, WORD usLength, LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc);
    STRUCT_ENUM_ERROR_TYPE ReadMcuRegs(WORD usReg, WORD usLength, LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc);
    STRUCT_ENUM_ERROR_TYPE WriteContinuousMcuReg(BYTE ucSub, WORD usLength, LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc);
    STRUCT_ENUM_ERROR_TYPE ReadContinuousMcuReg(BYTE ucSub, WORD usLength, LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc);
    STRUCT_ENUM_ERROR_TYPE ReleaseDev();
    STRUCT_ENUM_ERROR_TYPE NativeWrite(INT nAddress, WORD usLength, const LPBYTE pucBuf);
    STRUCT_ENUM_ERROR_TYPE NativeRead(INT nAddress, WORD usLength, LPBYTE pucBuf);
    void SetConfigFilePath(TCHAR *pcConfigFilePath);
    HANDLE GetDeviceHandler();
    STRUCT_ENUM_ERROR_TYPE ResetFirmware();
    virtual STRUCT_ENUM_ERROR_TYPE EnterIspMode(WORD usRetryTimes);
    DWORD GetSMBUSDataType();
    STRUCT_ENUM_ERROR_TYPE SetSMBUSDataType(DWORD ulSMBUSDataType);
    BYTE GetDeviceCount();
    STRUCT_ENUM_ERROR_TYPE RemoveDevice();
    STRUCT_ENUM_ERROR_TYPE AutoDetectSlaveAddr();
    STRUCT_ENUM_ERROR_TYPE DDCCIWrite(BYTE ucSlave, BYTE ucSub, BYTE ucLength, const LPBYTE pucBuf);
    STRUCT_ENUM_ERROR_TYPE DDCCIRead(BYTE ucSlave, BYTE ucSub, BYTE ucLength, LPBYTE pucBuf);

private:
    HINSTANCE m_hCommDll;
    func_rsGetI2CPageLength m_rsGetI2CPageLength;
    func_rsGetNativePageLength m_rsGetNativePageLength;
    func_rsI2CWrite m_rsI2CWrite;
    func_rsI2CRead m_rsI2CRead;
    func_rsI2CWriteByte m_rsI2CWriteByte;
    func_rsI2CCurrentRead m_rsI2CCurrentRead;
    func_rsI2CWordWrite m_rsI2CWordWrite;
    func_rsI2C2SubWrite m_rsI2C2SubWrite;
    func_rsI2CWordRead m_rsI2CWordRead;
    func_rsI2C2SubRead m_rsI2C2SubRead;
    func_rsI2CWriteEx m_rsI2CWriteEx;
    func_rsI2CReadEx m_rsI2CReadEx;
    func_rsI2CCurrentReadEx m_rsI2CCurrentReadEx;
    func_rsI2CWordWriteEx m_rsI2CWordWriteEx;
    func_rsI2C2SubWriteEx m_rsI2C2SubWriteEx;
    func_rsI2CWordReadEx m_rsI2CWordReadEx;
    func_rsI2C2SubReadEx m_rsI2C2SubReadEx;
    func_rsAdjustOption m_rsAdjustOption;
    func_rsSetI2CSpeed m_rsSetI2CSpeed;
    func_rsGetI2CSpeed m_rsGetI2CSpeed;
    func_rsSetAuxMode m_rsSetAuxMode;
    func_rsSetWaitingMode m_rsSetWaitingMode;
    func_rsGetWaitingMode m_rsGetWaitingMode;
    func_rsInitiallize m_rsInitiallize;
    func_rsGetCommCount m_rsGetCommCount;
    func_rsGetCommID m_rsGetCommID;
    func_rsGetCommName m_rsGetCommName;
    func_rsGetCommFile m_rsGetCommFile;
    func_rsSetCommByIndex m_rsSetCommByIndex;
    func_rsSetCommByID m_rsSetCommByID;
    func_rsSetDebugSlave m_rsSetDebugSlave;
    func_rsSetIspSlave m_rsSetIspSlave;
    func_rsSetIspContinuousSlave m_rsSetIspContinuousSlave;
    func_rsGetDebugSlave m_rsGetDebugSlave;
    func_rsGetIspSlave m_rsGetIspSlave;
    func_rsGetIspContinuousSlave m_rsGetIspContinuousSlave;
    func_rsSetDebugMode m_rsSetDebugMode;
    func_rsGetDebugMode m_rsGetDebugMode;
    func_rsReadReg m_rsReadReg;
    func_rsWriteReg m_rsWriteReg;
    func_rsReadRegs m_rsReadRegs;
    func_rsWriteRegs m_rsWriteRegs;
    func_rsWriteRegBit m_rsWriteRegBit;
    func_rsWritePortRegBit m_rsWritePortRegBit;
    func_rsReadRegEx m_rsReadRegEx;
    func_rsWriteRegEx m_rsWriteRegEx;
    func_rsReadRegsEx m_rsReadRegsEx;
    func_rsWriteRegsEx m_rsWriteRegsEx;
    func_rsWriteRegBitEx m_rsWriteRegBitEx;
    func_rsWritePortRegBitEx m_rsWritePortRegBitEx;
    func_rsReadSysDevice m_rsReadSysDevice;
    func_rsWriteSysDevice m_rsWriteSysDevice;
    func_rsReadWordSysDevice m_rsReadWordSysDevice;
    func_rsWriteWordSysDevice m_rsWriteWordSysDevice;
    func_rsScalerStop m_rsScalerStop;
    func_rsScalerRun m_rsScalerRun;
    func_rsWriteMcuReg m_rsWriteMcuReg;
    func_rsWriteMcuRegs m_rsWriteMcuRegs;
    func_rsReadMcuReg m_rsReadMcuReg;
    func_rsWriteMcuRegBit m_rsWriteMcuRegBit;
    func_rsReadMcuRegs m_rsReadMcuRegs;
    func_rsWriteContinuousMcuReg m_rsWriteContinuousMcuReg;
    func_rsReadContinuousMcuReg m_rsReadContinuousMcuReg;
    func_rsReleaseDev m_rsReleaseDev;
    func_rsNativeWrite m_rsNativeWrite;
    func_rsNativeRead m_rsNativeRead;
    func_rsSetConfigFilePath m_rsSetConfigFilePath; 
    func_rsGetDeviceHandler m_rsGetDeviceHandler;
    func_rsResetFirmware m_rsResetFirmware;
    func_rsEnterIspMode m_rsEnterIspMode;
    func_rsGetSMBUSDataType m_rsGetSMBUSDataType;
    func_rsSetSMBUSDataType m_rsSetSMBUSDataType;
    func_rsGetDeviceCount m_rsGetDeviceCount;
    func_rsRemoveDevice m_rsRemoveDevice;
    func_rsAutoDetectSlaveAddr m_rsAutoDetectSlaveAddr;
    func_rsDDCCIWrite m_rsDDCCIWrite;
    func_rsDDCCIRead m_rsDDCCIRead;
    //////////////////////////////////////////////////////////////////////////
public:
    STRUCT_REG_FORMER_VALUE m_stFormerVal;
};
STRUCT_ENUM_ERROR_TYPE g_rtdOGCWriteDDCCI(BYTE byLength, LPBYTE pBuffer, int nIICDelay, BYTE byUsePolling, BYTE ucI2CSpeed);
STRUCT_ENUM_ERROR_TYPE g_rtdReadDDCCI(BYTE ucSlave, BYTE ucSub, BYTE byLength, LPBYTE pBuffer, int nIICDelay, BYTE ucI2CSpeed, bool byUsePolling);

#endif // End of #ifndef _COMM_EXPORT_H_
