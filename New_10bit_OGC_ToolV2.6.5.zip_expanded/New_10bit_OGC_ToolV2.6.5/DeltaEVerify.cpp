//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DeltaEVerify.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmDeltaEVerify *frmDeltaEVerify;
//---------------------------------------------------------------------------
__fastcall TfrmDeltaEVerify::TfrmDeltaEVerify(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmDeltaEVerify::btnSaveToBmpClick(TObject *Sender)
{
    if(SaveDialog1->Execute())
    {
    	chartDeltaE->SaveToBitmapFile(SaveDialog1->FileName);
    }    
}
//---------------------------------------------------------------------------

