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

#ifndef _COMM_INCLUDE_H_
#define _COMM_INCLUDE_H_

#include "Common.h"

// Auto increase type for read/write register
typedef enum
{
    _INCTYPE_START = 0,
    _INCTYPE_NONE = _INCTYPE_START,
    _INCTYPE_AUTO,
    _INCTYPE_END,
    //To resolve transfer parameter error when use comm.dll in BCB. 
    //because sizeof(enum) = 4bytes in VC, sizeof(enum) = 1bytes in BCB(Default)   
    _INCTYPE_FINIAL = 0xFFFFFFFF
}STRUCT_ENUM_INC_TYPE;

// Debug mode type
typedef enum
{
    _DEBUG_START = 0,
    _DEBUG_UNKNOWN = _DEBUG_START,
    // Debug by FW
    _DEBUG_DEBUG,
    // Debug by isp mode
    _DEBUG_ISP,
    _DEBUG_XDATA,
    _DEBUG_END,
    //To resolve transfer parameter error when use comm.dll in BCB. 
    //because sizeof(enum) = 4bytes in VC, sizeof(enum) = 1bytes in BCB(Default)   
    _DEBUG_FINIAL = 0xFFFFFFFF

}STRUCT_ENUM_DEBUG_TYPE;

typedef struct  
{
    TCHAR strName[_MAX_PATH];
    TCHAR cszCommFile[_MAX_PATH];
}STRUCT_COMM_INFO;

typedef enum
{
    _ENUM_COMM_START = 0,
    _ENUM_COMM_UNKNOWN = _ENUM_COMM_START,
    _ENUM_COMM_AUX,
    _ENUM_COMM_SMBUS,
    _ENUM_COMM_REALTEKUSB,
    _ENUM_COMM_FTDIUSB,
    _ENUM_COMM_GFXI2C,
    _ENUM_COMM_END,
    //To resolve transfer parameter error when use comm.dll in BCB. 
    //because sizeof(enum) = 4bytes in VC, sizeof(enum) = 1bytes in BCB(Default)   
    _ENUM_COMM_FINIAL = 0xFFFFFFFF
}STRUCT_ENUM_COMM_ID;

// Waiting mode type
typedef enum
{
    _WAITING_START = 0,
    _WAITING_NONE = _WAITING_START,
    _WAITING_POLLING,
    _WAITING_DELAY,
    _WAITING_END,
    //To resolve transfer parameter error when use comm.dll in BCB. 
    //because sizeof(enum) = 4bytes in VC, sizeof(enum) = 1bytes in BCB(Default)   
    _WAITING_FINIAL = 0xFFFFFFFF
}STRUCT_ENUM_WAITING_TYPE;

typedef struct  
{
    STRUCT_ENUM_WAITING_TYPE enumWaiting;
    DWORD ulWaitingTime;
}STRUCT_WAITING_STRUCT;

typedef enum
{
    _ENUM_AUX_NONE = 0,
    _ENUM_AUX_SNIFFER,
    _ENUM_AUX_FPGA,
    //To resolve transfer parameter error when use comm.dll in BCB. 
    //because sizeof(enum) = 4bytes in VC, sizeof(enum) = 1bytes in BCB(Default)   
    _ENUM_AUX_FINIAL = 0xFFFFFFFF
}STRUCT_ENUM_AUX_MODE;

typedef struct  
{
    STRUCT_ENUM_AUX_MODE enumAuxMode;
    DWORD ulAuxPollingTime;
}STRUCT_AUXMODE_STRUCT;


// Communication type
typedef enum
{
    _ENUM_SMBUS_DATA_TYPE_START = 0,
    _ENUM_SMBUS_DATA_TYPE_UNKNOWN = _ENUM_SMBUS_DATA_TYPE_START,
    _ENUM_SMBUS_NORMAL_DATA_TYPE = 1, // normal write,don't Change define for current code
    _ENUM_SMBUS_BLOCK_DATA_TYPE = 1 << 1, // block write
    _ENUM_SMBUS_NORMAL_DATA_TYPE_READ = 1 << 2,
    _ENUM_SMBUS_BLOCK_DATA_TYPE_READ = 1 << 3,
    //To resolve transfer parameter error when use comm.dll in BCB. 
    //because sizeof(enum) = 4bytes in VC, sizeof(enum) = 1bytes in BCB(Default)   
    _ENUM_SMBUS_DATA_TYPE_FINIAL = 0xFFFFFFFF
}STRUCT_ENUM_SMBUS_DATA_TYPE;

#endif // End of #ifndef _COMM_INCLUDE_H_

