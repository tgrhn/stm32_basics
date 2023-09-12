//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RGBGammaVerify.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmRGBGammaVerify *frmRGBGammaVerify;
//---------------------------------------------------------------------------
__fastcall TfrmRGBGammaVerify::TfrmRGBGammaVerify(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmRGBGammaVerify::btnSavetoBmpClick(TObject *Sender)
{
    if(SaveDialog1->Execute())
    {
    	chartGamma->SaveToBitmapFile(SaveDialog1->FileName);
    }
}
//---------------------------------------------------------------------------
