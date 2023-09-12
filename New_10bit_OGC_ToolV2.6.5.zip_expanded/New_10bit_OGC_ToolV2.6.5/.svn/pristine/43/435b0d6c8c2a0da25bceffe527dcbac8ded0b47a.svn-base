//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CTVerify.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmCTVerify *frmCTVerify;
//---------------------------------------------------------------------------
__fastcall TfrmCTVerify::TfrmCTVerify(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfrmCTVerify::btnSavetoBmpClick(TObject *Sender)
{
    if(SaveDialog1->Execute())
    {
    	chartCT->SaveToBitmapFile(SaveDialog1->FileName);
    }
}
//---------------------------------------------------------------------------

