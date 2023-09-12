/********************************************************************************/
/*   The  Software  is  proprietary,  confidential,  and  valuable to Realtek   */
/*   Semiconductor  Corporation  ("Realtek").  All  rights, including but not   */
/*   limited  to  copyrights,  patents,  trademarks, trade secrets, mask work   */
/*   rights, and other similar rights and interests, are reserved to Realtek.   */
/*   Without  prior  written  consent  from  Realtek,  copying, reproduction,   */
/*   modification,  distribution,  or  otherwise  is strictly prohibited. The   */
/*   Software  shall  be  kept  strictly  in  confidence,  and  shall  not be   */
/*   disclosed to or otherwise accessed by any third party.                     */
/*   c<2003> - <2008>                                                           */
/*   The Software is provided "AS IS" without any warranty of any kind,         */
/*   express, implied, statutory or otherwise.                                  */
/********************************************************************************/


#ifndef _CA210CTRL_H_
#define _CA210CTRL_H_

//#include "..\ColorTool\ConstDef.h"

enum SYNC_MODE_TYPE
{
    SYNC_MODE_NTSC = 0,
    SYNC_MODE_PAL,
    SYNC_MODE_EXT,
    SYNC_MODE_UNIV,
    SYNC_MODE_INT
};

enum SPEED_TYPE
{
    SPEED_SLOW = 0,
    SPEED_FAST,
    SPEED_AUTO
};

//this structure include all data user can get from ca210
typedef struct tagCA210DATASTRUCT
{
    float   fX;
    float   fY;
    float   fZ;
    float   fFlckrJEITA;
    long    lNumber;
    float   fLv;
    float   fUd;
    float   fVd;
    long    lT;
    float   fDEUser;
    float   fFlckrFMA;
    float   fSy;
    float   fSx;
    float   fDuv;
    float   fUsUser;
    float   fVsUser;
    float   fLsUser;
    float   fLvfL;
    float   fR;
    float   fG;
    float   fB;
    long    lRd;
    long    lRad;
    long    lRfma;
    long    lRjeita;
}CA210DATASTRUCT, *LPCA210DATASTRUCT;

//define function point
typedef bool (*func_caConnect)(long lChannelNO);
typedef bool (*func_caSetChannel)(long lChannelNO);
typedef void (*func_caDisConnect)();
typedef CA210DATASTRUCT (*func_caMeasure)();
typedef void (*func_caZeroCal)();
//typedef XYZCOLOR (*func_caGetAverageMeasureXYZ)(INT nTimes);
typedef void (*func_caSetSyncMode)(INT nSyncMode);
typedef void (*func_caSetSpeed)(INT nSpeed);
typedef int  (*func_caGetCATypeName)(BYTE *bCAType);
typedef int  (*func_caGetCAVersionName)(BYTE *bCAVersion);

//---------------------------------------------------------------------------
// Description  : Connect to CA210
// Input Value  : None
// Output Value : return true if connect success, else return false
//---------------------------------------------------------------------------
extern func_caConnect caConnect;

//---------------------------------------------------------------------------
// Description  : Select Channel CA210
// Input Value  : None
// Output Value : return true if connect success, else return false
//---------------------------------------------------------------------------
extern func_caSetChannel caSetChannel;

//---------------------------------------------------------------------------
// Description  : DisConnect to CA210
// Input Value  : None
// Output Value : None
//---------------------------------------------------------------------------
extern func_caDisConnect caDisConnect;

//---------------------------------------------------------------------------
// Description  : Measure and get the data from ca210
// Input Value  : None
// Output Value : the structure include all data ca210 got once measure
//---------------------------------------------------------------------------
extern func_caMeasure caMeasure;

//---------------------------------------------------------------------------
// Description  : Call Zero calculate function, user should set ca210 to 0-cal level
// Input Value  : None
// Output Value : None
//---------------------------------------------------------------------------
extern func_caZeroCal caZeroCal;

//---------------------------------------------------------------------------
// Description  : Call Average Measure function
// Input Value  : None
// Output Value : None
//---------------------------------------------------------------------------
//extern func_caGetAverageMeasureXYZ caGetAverageMeasureXYZ;

//---------------------------------------------------------------------------
// Description  : Set Measure Sync Mode
// Input Value  : nSyncMode: select one from SYNC_MODE_TYPE
// Output Value : None
//---------------------------------------------------------------------------
extern func_caSetSyncMode caSetSyncMode;

//---------------------------------------------------------------------------
// Description  : Set Measure Speed
// Input Value  : nSpeed: select one from SPEED_TYPE
// Output Value : None
//---------------------------------------------------------------------------
extern func_caSetSpeed caSetSpeed;

//---------------------------------------------------------------------------
// Description  : Get CAType
// Input Value  : CAType
// Output Value : None
//---------------------------------------------------------------------------
extern func_caGetCATypeName caGetCATypeName;

//---------------------------------------------------------------------------
// Description  : Get CAVersion
// Input Value  : CAVersion
// Output Value : None
//---------------------------------------------------------------------------
extern func_caGetCAVersionName caGetCAVersionName;

//golob function to dynamic load libary
HINSTANCE InitCa210CtrlDLL(LPCTSTR szDLLName);
VOID FreeCa210CtrlDLL(HINSTANCE hInst);

#endif //#ifndef _CA210CTRL_H_