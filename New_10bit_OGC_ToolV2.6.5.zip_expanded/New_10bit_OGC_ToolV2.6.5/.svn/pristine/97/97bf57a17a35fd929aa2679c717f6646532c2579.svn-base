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

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//this include should be used in Borland C
#include <vcl.h>
//this include should be used in VC
//#include <stdafx.h>
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

#include "Ca210Ctrl_Export.h"

func_caConnect caConnect = NULL;
func_caConnect caSetChannel = NULL;
func_caDisConnect caDisConnect = NULL;
func_caMeasure caMeasure = NULL;
func_caZeroCal caZeroCal = NULL;
//func_caGetAverageMeasureXYZ caGetAverageMeasureXYZ = NULL;
func_caSetSyncMode caSetSyncMode = NULL;
func_caSetSpeed caSetSpeed = NULL;
func_caGetCATypeName caGetCATypeName = NULL;
func_caGetCAVersionName caGetCAVersionName = NULL;

//---------------------------------------------------------------------------
// Description  : Initial the ca210 control dll
// Input Value  : szDLLName, the dll name or full path name
// Output Value : return the handle of DLL, return 0 if initial failed
// Decription : this function must called before dll function is called
//---------------------------------------------------------------------------
HINSTANCE InitCa210CtrlDLL(LPCTSTR szDLLName)
{
    HINSTANCE hInst = LoadLibrary(szDLLName);

    if (hInst == NULL)
    {
        return NULL;
    }

    caConnect = NULL;
    caSetChannel = NULL;
    caDisConnect = NULL;
    caMeasure = NULL;
    caZeroCal = NULL;
//    caGetAverageMeasureXYZ = NULL;
    caSetSyncMode = NULL;
    caSetSpeed = NULL;
    caGetCATypeName = NULL;
    caGetCAVersionName = NULL;
    
    caConnect = (func_caConnect)GetProcAddress(hInst, "ca210Connect");
    caSetChannel = (func_caConnect)GetProcAddress(hInst, "ca210SetChannel");
    caDisConnect = (func_caDisConnect)GetProcAddress(hInst, "ca210DisConnect");
    caMeasure = (func_caMeasure)GetProcAddress(hInst, "ca210Measure");
    caZeroCal = (func_caZeroCal)GetProcAddress(hInst, "ca210ZeroCal");
//    caGetAverageMeasureXYZ = (func_caGetAverageMeasureXYZ)GetProcAddress(hInst, "ca210GetAverageMeasureXYZ");
    caSetSyncMode = (func_caSetSyncMode)GetProcAddress(hInst, "ca210SetSyncMode");
    caSetSpeed = (func_caSetSpeed)GetProcAddress(hInst, "ca210SetSpeed");
    caGetCATypeName = (func_caGetCATypeName)GetProcAddress(hInst,"ca210GetCATypeName");
    caGetCAVersionName = (func_caGetCAVersionName)GetProcAddress(hInst,"ca210GetCAVersionName");
    
    if ((caConnect!=NULL) && (caDisConnect!=NULL) && (caMeasure!=NULL) && (caZeroCal!=NULL)/* && (caGetAverageMeasureXYZ!=NULL)*/
     && (caSetSyncMode != NULL) && (caSetSpeed != NULL) && (caSetChannel != NULL) && (caGetCATypeName != NULL) && (caGetCAVersionName != NULL))
    {
        return hInst;
    }
    
    FreeLibrary(hInst);
    return NULL;
}

//---------------------------------------------------------------------------
// Description  : fred the ca210 control dll
// Input Value  : hInst, the handle of the dll, get from function InitCa210CtrlDLL
// Output Value : NULL
//---------------------------------------------------------------------------
VOID FreeCa210CtrlDLL(HINSTANCE hInst)
{
    if (hInst != NULL)
    {
        FreeLibrary(hInst);
    }
}
