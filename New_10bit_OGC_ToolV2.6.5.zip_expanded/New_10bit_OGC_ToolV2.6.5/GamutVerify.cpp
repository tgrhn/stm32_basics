//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GamutVerify.h"

#include "Test.h"
extern String strColorDomainName[];


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmGamutVerify *frmGamutVerify;
TCheckBox   *chkbColorDomain[_TOTAL_COLORSPACE_NUM + 2];
//---------------------------------------------------------------------------
__fastcall TfrmGamutVerify::TfrmGamutVerify(TComponent* Owner)
    : TForm(Owner)
{
    for(int i = 0; i < _TOTAL_COLORSPACE_NUM + 2; i++)
    {
        chkbColorDomain[i] = new TCheckBox(this);
        chkbColorDomain[i]->Left = 4 + (i%4)*120;
        chkbColorDomain[i]->Top = ChartGamut->Height + 4 + (i/4)*17;
        chkbColorDomain[i]->Caption = strColorDomainName[i];
        chkbColorDomain[i]->Parent = frmGamutVerify;
    }

    chkbColorDomain[_BYPASS]->Checked = 0;
    chkbColorDomain[_BYPASS]->Enabled = 0;

    LineSeriesGamut[_SRGB] = serStdSRGBGamut;
    LineSeriesGamut[_ADOBERGB] = serStdAdobeGamut;
    LineSeriesGamut[_USER_DEFINE] = serUserDefineGamut;
    LineSeriesGamut[_EBU] = serEBUGamut;
    LineSeriesGamut[_SOFT_PROOF] = serSoftProof;
    LineSeriesGamut[_REC_709] = serRec709;
    LineSeriesGamut[_DCI_P3] = serDCIP3;
	LineSeriesGamut[_SMPTE_C] = serSMPTEC;
	LineSeriesGamut[_USER_DEFINE_2] = serUserDefineGamut2;
    LineSeriesGamut[_PANEL_ORG] = serPanelOrgGamut;
    PointSeriesGamut = serMeasure;
}
//---------------------------------------------------------------------------
void __fastcall TfrmGamutVerify::btnShowGamutClick(TObject *Sender)
{
    for(int i = 0; i < _TOTAL_COLORSPACE_NUM  + 2; i++)
    {
        if(chkbColorDomain[i]->Checked)
        {
            if(i < _TOTAL_COLORSPACE_NUM  + 1)
            {
                frmTest->ShowColorDomainGamut(i);
            }
            else
            {
                frmTest->ShowMeasuredGamut(sRGBVerify, nPatternLength);
            }
        }
        else
        {
            if(i < _TOTAL_COLORSPACE_NUM  + 1)
            {
               if (i != _BYPASS)
                LineSeriesGamut[i]->Active = false;
            }
            else
            {
                PointSeriesGamut->Active = false;
            }
        }

    }
}
//---------------------------------------------------------------------------



