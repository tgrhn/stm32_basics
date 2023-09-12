//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GamutVerifySingle.h"

extern float fGamutPoint[_TOTAL_COLORSPACE_NUM + 1][3][2]; 
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmGamutVerifySingle *frmGamutVerifySingle;
//---------------------------------------------------------------------------
__fastcall TfrmGamutVerifySingle::TfrmGamutVerifySingle(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void  __fastcall TfrmGamutVerifySingle::ShowColorDomainGamut(BYTE ucColorDomain)
{
    serTargetGamut->XValues->Order = loNone;
    serTargetGamut->YValues->Order = loNone;
    serTargetGamut->Active = true;
    serTargetGamut->Clear();
    serTargetGamut->AddXY(fGamutPoint[ucColorDomain][0][0], fGamutPoint[ucColorDomain][0][1]);
    serTargetGamut->AddXY(fGamutPoint[ucColorDomain][1][0], fGamutPoint[ucColorDomain][1][1]);
    serTargetGamut->AddXY(fGamutPoint[ucColorDomain][2][0], fGamutPoint[ucColorDomain][2][1]);
    serTargetGamut->AddXY(fGamutPoint[ucColorDomain][0][0], fGamutPoint[ucColorDomain][0][1]);
}
//---------------------------------------------------------------------------
void  __fastcall TfrmGamutVerifySingle::ShowMeasuredGamut(COLOR_INPUT_STRUCT *sRGBVerify, int nPatternLength)
{
    // Show Gamut Measure
    serMeasure->Active = true;
    serMeasure->Clear();
    
    for(int i = 0; i < nPatternLength; i++)
    {
        serMeasure->AddXY(sRGBVerify[i].Sx, sRGBVerify[i].Sy);    
    }  
}