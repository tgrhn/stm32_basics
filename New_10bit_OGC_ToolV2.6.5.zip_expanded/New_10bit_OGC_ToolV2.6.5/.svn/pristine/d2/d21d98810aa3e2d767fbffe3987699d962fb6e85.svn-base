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

//#include "stdafx.h"
#include "Comm_Export.h"
extern CRsComm g_stComm;

//////////////////////////////////////////////////////////////////////////
// CRsComm
//////////////////////////////////////////////////////////////////////////
CRsComm::CRsComm()
{
    m_hCommDll = NULL;
}

CRsComm::~CRsComm()
{

}

BOOL CRsComm::LoadCommDllFile(TCHAR* pcFile)
{
    FreeCommDllFile();
    
    m_hCommDll = LoadLibrary(pcFile);
    if(m_hCommDll == NULL)
    {
        return FALSE;
    }

    m_rsGetI2CPageLength = (func_rsGetI2CPageLength)GetProcAddress(m_hCommDll, "GetI2CPageLength");
    if(m_rsGetI2CPageLength == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsGetNativePageLength = (func_rsGetNativePageLength)GetProcAddress(m_hCommDll, "GetNativePageLength");
    if(m_rsGetNativePageLength == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsI2CWrite = (func_rsI2CWrite)GetProcAddress(m_hCommDll, "I2CWrite");
    if(m_rsI2CWrite == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsI2CRead = (func_rsI2CRead)GetProcAddress(m_hCommDll, "I2CRead");
    if(m_rsI2CRead == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsI2CWriteByte = (func_rsI2CWriteByte)GetProcAddress(m_hCommDll, "I2CWriteByte");
    if(m_rsI2CWriteByte == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsI2CCurrentRead = (func_rsI2CCurrentRead)GetProcAddress(m_hCommDll, "I2CCurrentRead");
    if(m_rsI2CCurrentRead == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsI2CWordWrite = (func_rsI2CWordWrite)GetProcAddress(m_hCommDll, "I2CWordWrite");
    if(m_rsI2CWordWrite == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsI2C2SubWrite = (func_rsI2C2SubWrite)GetProcAddress(m_hCommDll, "I2C2SubWrite");
    if(m_rsI2C2SubWrite == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsI2CWordRead = (func_rsI2CWordRead)GetProcAddress(m_hCommDll, "I2CWordRead");
    if(m_rsI2CWordRead == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsI2C2SubRead = (func_rsI2C2SubRead)GetProcAddress(m_hCommDll, "I2C2SubRead");
    if(m_rsI2C2SubRead == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsI2CWriteEx = (func_rsI2CWriteEx)GetProcAddress(m_hCommDll, "I2CWriteEx");
    if(m_rsI2CWriteEx == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsI2CReadEx = (func_rsI2CReadEx)GetProcAddress(m_hCommDll, "I2CReadEx");
    if(m_rsI2CReadEx == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsI2CCurrentReadEx = (func_rsI2CCurrentReadEx)GetProcAddress(m_hCommDll, "I2CCurrentReadEx");
    if(m_rsI2CCurrentReadEx == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsI2CWordWriteEx = (func_rsI2CWordWriteEx)GetProcAddress(m_hCommDll, "I2CWordWriteEx");
    if(m_rsI2CWordWriteEx == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsI2C2SubWriteEx = (func_rsI2C2SubWriteEx)GetProcAddress(m_hCommDll, "I2C2SubWriteEx");
    if(m_rsI2C2SubWriteEx == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsI2CWordReadEx = (func_rsI2CWordReadEx)GetProcAddress(m_hCommDll, "I2CWordReadEx");
    if(m_rsI2CWordReadEx == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsI2C2SubReadEx = (func_rsI2C2SubReadEx)GetProcAddress(m_hCommDll, "I2C2SubReadEx");
    if(m_rsI2C2SubReadEx == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsAdjustOption = (func_rsAdjustOption)GetProcAddress(m_hCommDll, "AdjustOption");
    if(m_rsAdjustOption == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsSetI2CSpeed = (func_rsSetI2CSpeed)GetProcAddress(m_hCommDll, "SetI2CSpeed");
    if(m_rsSetI2CSpeed == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsGetI2CSpeed = (func_rsGetI2CSpeed)GetProcAddress(m_hCommDll, "GetI2CSpeed");
    if(m_rsGetI2CSpeed == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsSetAuxMode = (func_rsSetAuxMode)GetProcAddress(m_hCommDll, "SetAuxMode");
    if(m_rsSetAuxMode == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsSetWaitingMode = (func_rsSetWaitingMode)GetProcAddress(m_hCommDll, "SetWaitingMode");
    if(m_rsSetWaitingMode == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsGetWaitingMode = (func_rsGetWaitingMode)GetProcAddress(m_hCommDll, "GetWaitingMode");
    if(m_rsGetWaitingMode == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsInitiallize = (func_rsInitiallize)GetProcAddress(m_hCommDll, "Initiallize");
    if(m_rsInitiallize == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsGetCommCount = (func_rsGetCommCount)GetProcAddress(m_hCommDll, "GetCommCount");
    if(m_rsGetCommCount == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsGetCommID = (func_rsGetCommID)GetProcAddress(m_hCommDll, "GetCommID");
    if(m_rsGetCommID == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsGetCommName = (func_rsGetCommName)GetProcAddress(m_hCommDll, "GetCommName");
    if(m_rsGetCommName == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsGetCommFile = (func_rsGetCommFile)GetProcAddress(m_hCommDll, "GetCommFile");
    if (m_rsGetCommFile == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsSetCommByIndex = (func_rsSetCommByIndex)GetProcAddress(m_hCommDll, "SetCommByIndex");
    if(m_rsSetCommByIndex == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsSetCommByID = (func_rsSetCommByID)GetProcAddress(m_hCommDll, "SetCommByID");
    if(m_rsSetCommByID == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsSetDebugSlave = (func_rsSetDebugSlave)GetProcAddress(m_hCommDll, "SetDebugSlave");
    if(m_rsSetDebugSlave == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsSetIspSlave = (func_rsSetIspSlave)GetProcAddress(m_hCommDll, "SetIspSlave");
    if(m_rsSetIspSlave == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsSetIspContinuousSlave = (func_rsSetIspContinuousSlave)GetProcAddress(m_hCommDll, "SetIspContinuousSlave");
    if(m_rsSetIspContinuousSlave == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsGetDebugSlave = (func_rsGetDebugSlave)GetProcAddress(m_hCommDll, "GetDebugSlave");
    if(m_rsGetDebugSlave == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsGetIspSlave = (func_rsGetIspSlave)GetProcAddress(m_hCommDll, "GetIspSlave");
    if(m_rsGetIspSlave == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsGetIspContinuousSlave = (func_rsGetIspContinuousSlave)GetProcAddress(m_hCommDll, "GetIspContinuousSlave");
    if(m_rsGetIspContinuousSlave == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsSetDebugMode = (func_rsSetDebugMode)GetProcAddress(m_hCommDll, "SetDebugMode");
    if(m_rsSetDebugMode == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsGetDebugMode = (func_rsGetDebugMode)GetProcAddress(m_hCommDll, "GetDebugMode");
    if(m_rsGetDebugMode == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsReadReg = (func_rsReadReg)GetProcAddress(m_hCommDll, "ReadReg");
    if(m_rsReadReg == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsWriteReg = (func_rsWriteReg)GetProcAddress(m_hCommDll, "WriteReg");
    if(m_rsWriteReg == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsReadRegs = (func_rsReadRegs)GetProcAddress(m_hCommDll, "ReadRegs");
    if (m_rsReadRegs == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsWriteRegs = (func_rsWriteRegs)GetProcAddress(m_hCommDll, "WriteRegs");
    if(m_rsWriteRegs == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsWriteRegBit = (func_rsWriteRegBit)GetProcAddress(m_hCommDll, "WriteRegBit");
    if (m_rsWriteRegBit == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsWritePortRegBit = (func_rsWritePortRegBit)GetProcAddress(m_hCommDll, "WritePortRegBit");
    if (m_rsWritePortRegBit == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsReadRegEx = (func_rsReadRegEx)GetProcAddress(m_hCommDll, "ReadRegEx");
    if(m_rsReadRegEx == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsWriteRegEx = (func_rsWriteRegEx)GetProcAddress(m_hCommDll, "WriteRegEx");
    if(m_rsWriteRegEx == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsReadRegsEx = (func_rsReadRegsEx)GetProcAddress(m_hCommDll, "ReadRegsEx");
    if (m_rsReadRegsEx == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsWriteRegsEx = (func_rsWriteRegsEx)GetProcAddress(m_hCommDll, "WriteRegsEx");
    if(m_rsWriteRegsEx == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsWriteRegBitEx = (func_rsWriteRegBitEx)GetProcAddress(m_hCommDll, "WriteRegBitEx");
    if (m_rsWriteRegBitEx == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsWritePortRegBitEx = (func_rsWritePortRegBitEx)GetProcAddress(m_hCommDll, "WritePortRegBitEx");
    if (m_rsWritePortRegBitEx == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsReadSysDevice = (func_rsReadSysDevice)GetProcAddress(m_hCommDll, "ReadSysDevice");
    if(m_rsReadSysDevice == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsWriteSysDevice = (func_rsWriteSysDevice)GetProcAddress(m_hCommDll, "WriteSysDevice");
    if(m_rsWriteSysDevice == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsReadWordSysDevice = (func_rsReadWordSysDevice)GetProcAddress(m_hCommDll, "ReadWordSysDevice");
    if(m_rsReadWordSysDevice == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsWriteWordSysDevice = (func_rsWriteWordSysDevice)GetProcAddress(m_hCommDll, "WriteWordSysDevice");
    if(m_rsWriteWordSysDevice == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsScalerStop = (func_rsScalerStop)GetProcAddress(m_hCommDll, "ScalerStop");
    if (m_rsScalerStop == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsScalerRun = (func_rsScalerRun)GetProcAddress(m_hCommDll, "ScalerRun");
    if(m_rsScalerRun == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsWriteMcuReg = (func_rsWriteMcuReg)GetProcAddress(m_hCommDll, "WriteMcuReg");
    if(m_rsWriteMcuReg == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsWriteMcuRegBit = (func_rsWriteMcuRegBit)GetProcAddress(m_hCommDll, "WriteMcuRegBit");
    if(m_rsWriteMcuRegBit == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsReadMcuReg = (func_rsReadMcuReg)GetProcAddress(m_hCommDll, "ReadMcuReg");
    if(m_rsReadMcuReg == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsWriteMcuRegs = (func_rsWriteMcuRegs)GetProcAddress(m_hCommDll, "WriteMcuRegs");
    if(m_rsWriteMcuRegs == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsReadMcuRegs = (func_rsReadMcuRegs)GetProcAddress(m_hCommDll, "ReadMcuRegs");
    if(m_rsReadMcuRegs == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsWriteContinuousMcuReg = (func_rsWriteContinuousMcuReg)GetProcAddress(m_hCommDll, "WriteContinuousMcuReg");
    if(m_rsWriteContinuousMcuReg == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsReadContinuousMcuReg = (func_rsReadContinuousMcuReg)GetProcAddress(m_hCommDll, "ReadContinuousMcuReg");
    if(m_rsReadContinuousMcuReg == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsReleaseDev = (func_rsReleaseDev)GetProcAddress(m_hCommDll, "ReleaseDev");
    if(m_rsReleaseDev == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }
    m_rsNativeWrite = (func_rsNativeWrite)GetProcAddress(m_hCommDll, "NativeWrite");
    if(m_rsNativeWrite == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsNativeRead = (func_rsNativeRead)GetProcAddress(m_hCommDll, "NativeRead");
    if(m_rsNativeRead == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsSetConfigFilePath = (func_rsSetConfigFilePath)GetProcAddress(m_hCommDll, "SetSettingFilePath");
    if(m_rsSetConfigFilePath == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsGetDeviceHandler = (func_rsGetDeviceHandler)GetProcAddress(m_hCommDll, "GetDeviceHandler");
    if(m_rsGetDeviceHandler == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsResetFirmware = (func_rsResetFirmware)GetProcAddress(m_hCommDll, "ResetFirmware");
    if(m_rsResetFirmware == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsEnterIspMode = (func_rsEnterIspMode)GetProcAddress(m_hCommDll, "EnterIspMode");
    if(m_rsEnterIspMode == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsGetSMBUSDataType = (func_rsGetSMBUSDataType)GetProcAddress(m_hCommDll, "GetSMBUSDataType");
    if(m_rsGetSMBUSDataType == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsSetSMBUSDataType = (func_rsSetSMBUSDataType)GetProcAddress(m_hCommDll, "SetSMBUSDataType");
    if(m_rsSetSMBUSDataType == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }
    m_rsGetDeviceCount = (func_rsGetDeviceCount)GetProcAddress(m_hCommDll, "GetDeviceCount");
    if(m_rsGetDeviceCount == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }
    m_rsRemoveDevice = (func_rsRemoveDevice)GetProcAddress(m_hCommDll, "RemoveDevice");
    if(m_rsRemoveDevice == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }
    m_rsAutoDetectSlaveAddr = (func_rsAutoDetectSlaveAddr)GetProcAddress(m_hCommDll, "AutoDetectSlaveAddr");
    if(m_rsAutoDetectSlaveAddr == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }

    m_rsDDCCIWrite = (func_rsDDCCIWrite)GetProcAddress(m_hCommDll, "DDCCIWrite");
    if(m_rsDDCCIWrite == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }
    m_rsDDCCIRead = (func_rsDDCCIRead)GetProcAddress(m_hCommDll, "DDCCIRead");
    if(m_rsDDCCIRead == NULL)
    {
        FreeCommDllFile();
        return FALSE;
    }
    return TRUE;
}

void CRsComm::FreeCommDllFile()
{
    if(m_hCommDll == NULL)
    {
        return;
    }

    FreeLibrary(m_hCommDll);
    m_hCommDll = NULL;
}

STRUCT_ENUM_ERROR_TYPE CRsComm::Initiallize()
{
    if(m_rsInitiallize == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsInitiallize();
}

// Get current device count, this function must be called after rsInitiallize has been called
WORD CRsComm::GetCommCount()
{
    if(m_rsGetCommCount == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsGetCommCount();
}

STRUCT_ENUM_COMM_ID CRsComm::GetCommID()
{
    if(m_rsGetCommID == NULL)
    {
        return _ENUM_COMM_UNKNOWN;
    }

    return m_rsGetCommID();
}

void CRsComm::GetCommName(TCHAR* szName, WORD usLength)
{
    if(m_rsGetCommName == NULL)
    {
        return;
    }

    return m_rsGetCommName(szName, usLength);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::GetCommFile(STRUCT_COMM_INFO *pstCommVer)
{
    if(m_rsGetCommFile == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsGetCommFile(pstCommVer);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::SetCommByIndex(WORD usCommIndex)
{
    if(m_rsSetCommByIndex == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsSetCommByIndex(usCommIndex);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::SetCommByID(STRUCT_ENUM_COMM_ID enumCommID)
{
    if(m_rsSetCommByID == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsSetCommByID(enumCommID);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::SetDebugSlave(BYTE ucDebugSlave)
{
    if(m_rsSetDebugSlave == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsSetDebugSlave(ucDebugSlave);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::SetIspSlave(BYTE ucIspSlave)
{
    if(m_rsSetIspSlave == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsSetIspSlave(ucIspSlave);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::SetIspContinuousSlave(BYTE ucIspContinuousSlave)
{
    if(m_rsSetIspContinuousSlave == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsSetIspContinuousSlave(ucIspContinuousSlave);
}

BYTE CRsComm::GetDebugSlave()
{
    if(m_rsGetDebugSlave == NULL)
    {
        return 0;
    }

    return m_rsGetDebugSlave();
}

BYTE CRsComm::GetIspSlave()
{
    if(m_rsGetIspSlave == NULL)
    {
        return 0;
    }

    return m_rsGetIspSlave();
}

BYTE CRsComm::GetIspContinuousSlave()
{
    if(m_rsGetIspContinuousSlave == NULL)
    {
        return 0;
    }

    return m_rsGetIspContinuousSlave();
}

STRUCT_ENUM_ERROR_TYPE CRsComm::SetDebugMode(STRUCT_ENUM_DEBUG_TYPE enumDebugType)
{
    if(m_rsSetDebugMode == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsSetDebugMode(enumDebugType);
}

STRUCT_ENUM_DEBUG_TYPE CRsComm::GetDebugMode()
{
    if(m_rsGetDebugMode == NULL)
    {
        return _DEBUG_UNKNOWN;
    }

    return m_rsGetDebugMode();
}

STRUCT_ENUM_ERROR_TYPE CRsComm::ReadReg(BYTE ucReg, BYTE* pucValue)
{
    if(m_rsReadReg == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsReadReg(ucReg, pucValue);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::WriteReg(BYTE ucReg, BYTE ucValue)
{
    if(m_rsWriteReg == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsWriteReg(ucReg, ucValue);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::ReadRegs(BYTE ucReg, WORD usLength, LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc)
{
    if(m_rsReadRegs == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsReadRegs(ucReg, usLength, pucBuf, enumInc);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::WriteRegs(BYTE ucReg, WORD usLength, LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc)
{
    if(m_rsWriteRegs == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsWriteRegs(ucReg, usLength, pucBuf, enumInc);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::WriteRegBit(BYTE ucReg, BYTE ucAnd, BYTE ucOr)
{
    if(m_rsWriteRegBit == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsWriteRegBit(ucReg, ucAnd, ucOr);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::WritePortRegBit(BYTE ucAddrReg, BYTE ucDataReg, BYTE ucAnd, BYTE ucOr)
{
    if(m_rsWritePortRegBit == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsWritePortRegBit(ucAddrReg, ucDataReg, ucAnd, ucOr);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::ReadRegEx(WORD usReg, BYTE* pucValue)
{
    if(m_rsReadRegEx == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsReadRegEx(usReg, pucValue);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::WriteRegEx(WORD usReg, BYTE ucValue)
{
    if(m_rsWriteRegEx == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsWriteRegEx(usReg, ucValue);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::ReadRegsEx(WORD usReg, WORD usLength, LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc)
{
    if(m_rsReadRegsEx == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsReadRegsEx(usReg, usLength, pucBuf, enumInc);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::WriteRegsEx(WORD usReg, WORD usLength, LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc)
{
    if(m_rsWriteRegsEx == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsWriteRegsEx(usReg, usLength, pucBuf, enumInc);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::WriteRegBitEx(WORD usReg, BYTE ucAnd, BYTE ucOr)
{
    if(m_rsWriteRegBitEx == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsWriteRegBitEx(usReg, ucAnd, ucOr);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::WritePortRegBitEx(WORD usAddrReg, WORD usDataReg, BYTE ucAnd, BYTE ucOr)
{
    if(m_rsWritePortRegBitEx == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsWritePortRegBitEx(usAddrReg, usDataReg, ucAnd, ucOr);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::ReadSysDevice(BYTE ucSlave, BYTE ucSub, BYTE ucLength, LPBYTE pucBuf)
{
    if(m_rsReadSysDevice == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsReadSysDevice(ucSlave, ucSub, ucLength, pucBuf);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::WriteSysDevice(BYTE ucSlave, BYTE ucSub, BYTE ucLength, LPBYTE pucBuf)
{
    if(m_rsWriteSysDevice == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsWriteSysDevice(ucSlave, ucSub, ucLength, pucBuf);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::ReadWordSysDevice(BYTE ucSlave, WORD usSub, BYTE ucLength, LPBYTE pucBuf)
{
    if(m_rsReadWordSysDevice == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsReadWordSysDevice(ucSlave, usSub, ucLength, pucBuf);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::WriteWordSysDevice(BYTE ucSlave, WORD usSub, BYTE ucLength, LPBYTE pucBuf)
{
    if(m_rsWriteWordSysDevice == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsWriteWordSysDevice(ucSlave, usSub, ucLength, pucBuf);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::ScalerStop()
{
    if(m_rsScalerStop == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsScalerStop();
}

STRUCT_ENUM_ERROR_TYPE CRsComm::ScalerRun()
{
    if(m_rsScalerRun == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsScalerRun();
}

WORD CRsComm::GetI2CPageLength()
{
    if(m_rsGetI2CPageLength == NULL)
    {
        return 0;
    }

    return m_rsGetI2CPageLength();
}

WORD CRsComm::GetNativePageLength()
{
    if(m_rsGetNativePageLength == NULL)
    {
        return 0;
    }

    return m_rsGetNativePageLength();
}

STRUCT_ENUM_ERROR_TYPE CRsComm::I2CWrite(BYTE ucSlave, BYTE ucSub, WORD usLength, const LPBYTE pucBuf)
{
    if(m_rsI2CWrite == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsI2CWrite(ucSlave, ucSub, usLength, pucBuf);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::I2CRead(BYTE ucSlave, BYTE ucSub, WORD usLength, LPBYTE pucBuf)
{
    if(m_rsI2CRead == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsI2CRead(ucSlave, ucSub, usLength, pucBuf);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::I2CWriteByte(BYTE ucSlave, BYTE ucSub, BYTE ucValue)
{
    if(m_rsI2CWriteByte == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsI2CWriteByte(ucSlave, ucSub, ucValue);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::I2CCurrentRead(BYTE ucSlave, WORD usLength, LPBYTE pucBuf)
{
    if(m_rsI2CCurrentRead == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsI2CCurrentRead(ucSlave, usLength, pucBuf);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::I2CWordWrite(BYTE ucSlave, WORD usSub, WORD usLength, const LPBYTE pucBuf)
{
    if(m_rsI2CWordWrite == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsI2CWordWrite(ucSlave, usSub, usLength, pucBuf);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::I2C2SubWrite(BYTE ucSlave, BYTE ucSub0, BYTE ucSub1, WORD usLength, const LPBYTE pucBuf)
{
    if(m_rsI2C2SubWrite == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsI2C2SubWrite(ucSlave, ucSub0, ucSub1, usLength, pucBuf);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::I2CWordRead(BYTE ucSlave, WORD usSub, WORD usLength, LPBYTE pucBuf)
{
    if(m_rsI2CWordRead == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsI2CWordRead(ucSlave, usSub, usLength, pucBuf);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::I2C2SubRead(BYTE ucSlave, BYTE ucSub0, BYTE ucSub1, WORD usLength, LPBYTE pucBuf)
{
    if(m_rsI2C2SubRead == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsI2C2SubRead(ucSlave, ucSub0, ucSub1, usLength, pucBuf);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::I2CWriteEx(BYTE ucSlave, BYTE ucSub, WORD usLength, const LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc)
{
    if(m_rsI2CWriteEx == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsI2CWriteEx(ucSlave, ucSub, usLength, pucBuf, enumInc);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::I2CReadEx(BYTE ucSlave, BYTE ucSub, WORD usLength, LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc)
{
    if(m_rsI2CReadEx == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsI2CReadEx(ucSlave, ucSub, usLength, pucBuf, enumInc);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::I2CCurrentReadEx(BYTE ucSlave, WORD usLength, LPBYTE pucBuf)
{
    if(m_rsI2CCurrentReadEx == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsI2CCurrentReadEx(ucSlave, usLength, pucBuf);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::I2CWordWriteEx(BYTE ucSlave, WORD usSub, WORD usLength, const LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc)
{
    if(m_rsI2CWordWriteEx == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsI2CWordWriteEx(ucSlave, usSub, usLength, pucBuf, enumInc);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::I2C2SubWriteEx(BYTE ucSlave, BYTE ucSub0, BYTE ucSub1, WORD usLength, const LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc)
{
    if(m_rsI2C2SubWriteEx == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsI2C2SubWriteEx(ucSlave, ucSub0, ucSub1, usLength, pucBuf, enumInc);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::I2CWordReadEx(BYTE ucSlave, WORD usSub, WORD usLength, LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc)
{
    if(m_rsI2CWordReadEx == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsI2CWordReadEx(ucSlave, usSub, usLength, pucBuf, enumInc);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::I2C2SubReadEx(BYTE ucSlave, BYTE ucSub0, BYTE ucSub1, WORD usLength, LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc)
{
    if(m_rsI2C2SubReadEx == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsI2C2SubReadEx(ucSlave, ucSub0, ucSub1, usLength, pucBuf, enumInc);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::AdjustOption()
{
    if(m_rsAdjustOption == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsAdjustOption();
}

STRUCT_ENUM_ERROR_TYPE CRsComm::SetI2CSpeed(WORD usSpeed)
{
    if(m_rsSetI2CSpeed == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsSetI2CSpeed(usSpeed);
}

WORD CRsComm::GetI2CSpeed()
{
    if(m_rsGetI2CSpeed == NULL)
    {
        return 0;
    }

    return m_rsGetI2CSpeed();
}

STRUCT_ENUM_ERROR_TYPE CRsComm::SetAuxMode(STRUCT_AUXMODE_STRUCT stAuxMode)
{
    if(m_rsSetAuxMode == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsSetAuxMode(stAuxMode);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::SetWaitingMode(STRUCT_WAITING_STRUCT stWaiting)
{
    if(m_rsSetWaitingMode == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsSetWaitingMode(stWaiting);
}

STRUCT_WAITING_STRUCT CRsComm::GetWaitingMode()
{
    STRUCT_WAITING_STRUCT stWaiting;

    if(m_rsGetWaitingMode == NULL)
    {
        stWaiting.enumWaiting = _WAITING_NONE;
        stWaiting.ulWaitingTime = 0;
        return stWaiting;
    }

    return m_rsGetWaitingMode();
}

STRUCT_ENUM_ERROR_TYPE CRsComm::WriteMcuReg(WORD usReg, BYTE ucValue)
{
    if(m_rsWriteMcuReg == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsWriteMcuReg(usReg, ucValue);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::WriteMcuRegBit(WORD usReg, BYTE ucAnd, BYTE ucOr)
{
    if(m_rsWriteMcuRegBit == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsWriteMcuRegBit(usReg, ucAnd, ucOr);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::ReadMcuReg(WORD usReg, BYTE* pucValue)
{
    if(m_rsReadMcuReg == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsReadMcuReg(usReg, pucValue);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::WriteMcuRegs(WORD usReg, WORD usLength, LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc)
{
    if(m_rsWriteMcuRegs == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsWriteMcuRegs(usReg, usLength, pucBuf, enumInc);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::ReadMcuRegs(WORD usReg, WORD usLength, LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc)
{
    if(m_rsReadMcuRegs == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsReadMcuRegs(usReg, usLength, pucBuf, enumInc);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::WriteContinuousMcuReg(BYTE ucSub, WORD usLength, LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc)
{
    if(m_rsWriteContinuousMcuReg == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsWriteContinuousMcuReg(ucSub, usLength, pucBuf, enumInc);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::ReadContinuousMcuReg(BYTE ucSub, WORD usLength, LPBYTE pucBuf, STRUCT_ENUM_INC_TYPE enumInc)
{
    if(m_rsReadContinuousMcuReg == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsReadContinuousMcuReg(ucSub, usLength, pucBuf, enumInc);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::ReleaseDev()
{
    if(m_rsReleaseDev == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsReleaseDev();
}

STRUCT_ENUM_ERROR_TYPE CRsComm::NativeWrite(INT nAddress, WORD usLength, const LPBYTE pucBuf)
{
    if(m_rsNativeWrite == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsNativeWrite(nAddress, usLength, pucBuf);
}

STRUCT_ENUM_ERROR_TYPE CRsComm::NativeRead(INT nAddress, WORD usLength, LPBYTE pucBuf)
{
    if(m_rsNativeRead == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsNativeRead(nAddress, usLength, pucBuf);
}

void CRsComm::SetConfigFilePath(TCHAR* pcSettingFilePath)
{
    if(m_rsSetConfigFilePath == NULL)
    {
        return;
    }

    return m_rsSetConfigFilePath(pcSettingFilePath);
}

HANDLE CRsComm::GetDeviceHandler()
{
    if(m_rsGetDeviceHandler == NULL)
    {
        return NULL;
    }

    return m_rsGetDeviceHandler();
}

STRUCT_ENUM_ERROR_TYPE CRsComm::ResetFirmware()
{
    if(m_rsResetFirmware == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsResetFirmware();
}

STRUCT_ENUM_ERROR_TYPE CRsComm::EnterIspMode(WORD usRetryTimes)
{
    if(m_rsEnterIspMode == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsEnterIspMode(usRetryTimes);
}

DWORD CRsComm::GetSMBUSDataType()
{
    if(m_rsGetSMBUSDataType == NULL)
    {
        return _ENUM_SMBUS_DATA_TYPE_UNKNOWN;
    }

    return m_rsGetSMBUSDataType();
}

STRUCT_ENUM_ERROR_TYPE CRsComm::SetSMBUSDataType(DWORD ulSMBUSDataType)
{
    if(m_rsSetSMBUSDataType == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsSetSMBUSDataType(ulSMBUSDataType);
}
BYTE CRsComm::GetDeviceCount()
{
    if(m_rsGetDeviceCount == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsGetDeviceCount();
}
STRUCT_ENUM_ERROR_TYPE CRsComm::RemoveDevice()
{
    if(m_rsRemoveDevice == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsRemoveDevice();
}
STRUCT_ENUM_ERROR_TYPE CRsComm::AutoDetectSlaveAddr()
{
    if(m_rsAutoDetectSlaveAddr == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }

    return m_rsAutoDetectSlaveAddr();
}
STRUCT_ENUM_ERROR_TYPE CRsComm::DDCCIWrite(BYTE ucSlave, BYTE ucSub, BYTE ucLength, const LPBYTE pucBuf)
{
    if(m_rsDDCCIWrite == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }
    return m_rsDDCCIWrite(ucSlave, ucSub, ucLength, pucBuf);

}
STRUCT_ENUM_ERROR_TYPE CRsComm::DDCCIRead(BYTE ucSlave, BYTE ucSub, BYTE ucLength, LPBYTE pucBuf)
{
    if(m_rsDDCCIRead == NULL)
    {
        return _ERROR_COMM_NO_INITIAL;
    }
    return m_rsDDCCIRead(ucSlave, ucSub, ucLength, pucBuf);

}

BYTE g_ucDDCCISlaveAddress = 0x6E;

STRUCT_ENUM_ERROR_TYPE g_rtdOGCWriteDDCCI(BYTE byLength, LPBYTE pBuffer, int nIICDelay, BYTE byUsePolling, BYTE ucI2CSpeed)
{
    BYTE byBuf[256] = {0};
    int i =0;
    STRUCT_ENUM_ERROR_TYPE enumError = _ERROR_SUCCESS;

    byBuf[0] = g_ucDDCCISlaveAddress;
    byBuf[1] = 0x51;
    byBuf[2] = (BYTE)(byLength|0x80);
    for (i=3; i<3+byLength; i++)
    {
        byBuf[i] = *(pBuffer+i-3);
    }
    for (i=0; i<3+byLength; i++)
    {
        byBuf[3+byLength] ^= byBuf[i];
    }

    enumError = g_stComm.I2CWriteEx(byBuf[0],byBuf[1] , byLength+2, byBuf+2, _INCTYPE_NONE);
    return enumError;
}

STRUCT_ENUM_ERROR_TYPE g_rtdReadDDCCI(BYTE ucSlave, BYTE ucSub, BYTE byLength, LPBYTE pBuffer, int nIICDelay, BYTE ucI2CSpeed, bool byUsePolling)
{
    BYTE byBuf[256] = {0};
    BYTE byChecksum = 0x50;
    int i =0;
    STRUCT_ENUM_ERROR_TYPE enumError = _ERROR_SUCCESS;
    
    enumError = g_stComm.I2CReadEx(ucSlave ,ucSub, byLength, byBuf, _INCTYPE_NONE);
    
    if(enumError != _ERROR_SUCCESS)
    {
        return enumError;
    }

    if (byBuf[0] == g_ucDDCCISlaveAddress)
    {
        for (i=0; i<(byBuf[1]&0x7f)+2; i++)
        {
            byChecksum ^= byBuf[i];
        }
        if (byChecksum == byBuf[(byBuf[1]&0x7f)+2])
        {
            for (i=0; i<(byBuf[1]&0x7f)+3; i++)
            {
                *(pBuffer+i) = byBuf[i];
            }
            return _ERROR_SUCCESS;
        }
        else
        {
            return _ERROR_DDCCI_READ_CHECKSUM_ERROR;
        }
    }
    else
    {
        return _ERROR_DDCCI_READ_SLAVE_ADDEESS;
    }

}

