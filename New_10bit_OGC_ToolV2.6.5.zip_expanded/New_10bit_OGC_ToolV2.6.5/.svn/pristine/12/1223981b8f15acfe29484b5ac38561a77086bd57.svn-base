//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GammaVerify.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmGammaVerify *frmGammaVerify;
//---------------------------------------------------------------------------
__fastcall TfrmGammaVerify::TfrmGammaVerify(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmGammaVerify::btnSavetoBmpClick(TObject *Sender)
{
    if(SaveDialog1->Execute())
    {
    	chartGamma->SaveToBitmapFile(SaveDialog1->FileName);
    }    
}
//---------------------------------------------------------------------------

void __fastcall TfrmGammaVerify::rgRefGammaIndexClick(TObject *Sender)
{
    float Gamma_ref_Lv[256];
    int nIndex = rgRefGammaIndex->ItemIndex > 0? rgRefGammaIndex->ItemIndex : 0;
    String str = rgRefGammaIndex->Items->Strings[nIndex];
    float fGammaIndex = StrToFloat(str);

    double min = PointSeriesGammaMeas->YValues->MinValue;
    double max = PointSeriesGammaMeas->YValues->MaxValue;
    GetGammaGrayRef(Gamma_ref_Lv, min, max, fGammaIndex);

    LineSeriesGammaRef->Clear();

    for(int i = 0; i < 256; i++)
    {
        LineSeriesGammaRef->AddXY(i, Gamma_ref_Lv[i]);	// Gamma reference
    }    
}
//---------------------------------------------------------------------------



