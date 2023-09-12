//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Measure.h"
#include "Dll/Ca210Ctrl_Export.h"
#include "Unit1.h"
#include "OGCOCC_Export.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

enum
{
    _PATTERN_R,
    _PATTERN_G,
    _PATTERN_B,
    _PATTERN_Y,
    _PATTERN_C,
    _PATTERN_M,
    _PATTERN_GRAY,
};
extern unsigned long HextoInt(char hexnum[10],int bitnum);
extern BYTE CalculateCheckSum(BYTE ucLength, BYTE *Command);
extern bool SendCommand(BYTE ucLength, BYTE* Command);
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMeasure *frmMeasure;
//---------------------------------------------------------------------------
__fastcall TfrmMeasure::TfrmMeasure(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmMeasure::btnMeasureClick(TObject *Sender)
{
    int nPatternLen = StrToInt(rgStep->Items->Strings[rgStep->ItemIndex]);
    int nInterval = 1024/nPatternLen;
    BYTE Command[10];
	int i = 0;
	BYTE ucLength = 4;
	CA210DATASTRUCT MeaData;
    int R,G,B;
    int nLevel = 0;
    
    ofstream fout("Output/UserMeasure.csv");
    fout<<"Lv,x,y"<<endl;
    
    Command[0] = 0x03;                  
    Command[1] = HextoInt(frmDemo->edtCommand->Text.c_str(), 2);                   
	Command[2] = rgSource->ItemIndex == 0 ? 0xAB : 0xBB;

	
    for(i = 0; i < nPatternLen; i++)
    {
        switch(rgChannelSel->ItemIndex)
        {
            case _PATTERN_R:
            default:
                     R = nLevel; G = 0; B = 0; break;
            case _PATTERN_G: R = 0; G = nLevel; B = 0; break;
            case _PATTERN_B: R = 0; G = 0; B = nLevel; break;
            case _PATTERN_Y: R = nLevel; G = nLevel; B = 0; break;
            case _PATTERN_C: R = 0; G = nLevel; B = nLevel; break;
            case _PATTERN_M: R = nLevel; G = 0; B = nLevel; break;
            case _PATTERN_GRAY: R = nLevel; G = nLevel; B = nLevel; break;
        }
        
        nLevel += nInterval;
        
        if(nLevel == 1024)
        {
            nLevel = 1023;
        }
        
    	Command[3] = R >> 8;
    	Command[4] = R & 0xFF;
    	Command[5] = G >> 8;
    	Command[6] = G & 0xFF;
    	Command[7] = B >> 8;
    	Command[8] = B & 0xFF;
    	Command[9] = CalculateCheckSum(9, Command);
    	ucLength = 10;

      	if(!SendCommand(ucLength, Command))
        {
            fout.close();
            return;
        }
    	
    	Sleep(200);
        MeaData = caMeasure();

        fout<<MeaData.fLv<<", "<<MeaData.fSx<<","<<MeaData.fSy<<endl;
    }

    fout.close();

    Command[3] = (rgSource->ItemIndex == 0) ?  0xAC : _OCC_VERIFY_END;
    Command[4] = CalculateCheckSum(4, Command);
    ucLength = 5;
    SendCommand(ucLength, Command);
    ShowMessage("Measure End!");
}
//---------------------------------------------------------------------------
void __fastcall TfrmMeasure::btnGetOCCLUTClick(TObject *Sender)
{
/*
    // Get Ref Curve
    float GammaIndex = 1.0f;
    float GammaRef[1090] = {0};
    float Min = StrToFloat(edtBlackLv->Text);
    float Max = StrToFloat(edtWhiteLv->Text);
    float gain = 1;
    
    for (int i=0; i<5; i++)
    {
        GammaRef[i] = (float)(Min + (Max - Min) * pow((double)i/1047552, (double)GammaIndex)*gain);
    }
    for (int i=5; i<8; i++)
    {
        GammaRef[i] =(float)(Min + (Max - Min)  * pow((double)(4+(i-4)*4)/1047552,(double)GammaIndex)*gain);
    }
    for (int i=8; i<23; i++)
    {
        GammaRef[i] =(float)(Min + (Max - Min)  * pow((double(16+(i-7)*16)/1047552),(double)GammaIndex)*gain);
    }
    for (int i=23; i<51; i++)
    {
        GammaRef[i] = (float)(Min + (Max - Min)  * pow((double(256+(i-22)*64)/1047552),(double)GammaIndex)*gain);
    }
    for (int i=51; i<75; i++)
    {
        GammaRef[i] = (float)(Min + (Max - Min)  * pow((double(2048+(i-50)*256)/1047552),(double)GammaIndex)*gain);
    }
    for (int i=75; i<1090; i++)
    {
        GammaRef[i] = (float)(Min + (Max - Min)  * pow((double(8192+(i-74)*1024)/1047552),(double)GammaIndex)*gain);
    }

    // Get Measrue Curve
    float fGammaMeasure[16384] = {0};
    float fTargetGamma = 2.2;

    for(int i = 0; i < 16368; i++)
    {
        fGammaMeasure[i] =  Min + (Max - Min) *pow(i/16368, fTargetGamma);
    }

    // Get LUT
    for(int i = 0; i < )

    */
}
//---------------------------------------------------------------------------

