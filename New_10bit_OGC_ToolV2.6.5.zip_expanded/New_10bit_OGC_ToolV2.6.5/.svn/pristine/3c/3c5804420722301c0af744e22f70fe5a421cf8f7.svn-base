//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Test.h"
#include "Unit1.h"
#include "DeltaEVerify.h"
#include "CTVerify.h"
#include "GammaVerify.h"
#include "GamutVerify.h"
#include "GamutVerifySingle.h"
#include "RGBGammaVerify.h"
#include "TG18Verify.h"
#include "TG18Gamma.h"
#include <math.h>

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmTest *frmTest;
TfrmGammaVerify *frmGammaVerifyM[_TOTAL_COLORSPACE_NUM];  // OCC
TfrmDeltaEVerify *frmDeltaEVerifyM[_TOTAL_COLORSPACE_NUM];// OCC
TfrmCTVerify *frmCTVerifyM[_TOTAL_COLORSPACE_NUM];// OCC
TfrmGamutVerifySingle *frmGamutVerifySingleM[_TOTAL_COLORSPACE_NUM];// OCC
//TCheckBox *chkbColorSpace[_TOTAL_COLORSPACE_NUM]; // OCC
// frmGammaVerify,frmDeltaEVerify & frmCTVerify are for OGC
TfrmGammaVerify *frmGammaVerify_FreesyncII;
TfrmDeltaEVerify *frmDeltaUV; // OGC deltaUV
TfrmGammaVerify *frmDICOMGammaVerify;// DICOM
extern float fPanelRGBWxy[4][2];
extern BYTE g_ucVerifyType;

String strColorDomainName[] =
{
    "sRGB",
    "AdobeRGB",
    "UserDefine",
    "EBU",
    "SoftProof",
    "Rec.709",
    "DCI-P3",
    "SMPTE-C",
    "UserDefine2",
    "Bypass",
    "Panel Org",
    "Measured"
};

extern float fGamutPoint[_TOTAL_COLORSPACE_NUM + 1][3][2];

//---------------------------------------------------------------------------
__fastcall TfrmTest::TfrmTest(TComponent* Owner)
    : TForm(Owner)
{
    for(int i = 0; i < _TOTAL_COLORSPACE_NUM; i++)
    {
        frmGammaVerifyM[i]  = new TfrmGammaVerify(this);
        frmDeltaEVerifyM[i] = new TfrmDeltaEVerify(this);
        frmCTVerifyM[i]     = new TfrmCTVerify(this);
        frmGamutVerifySingleM[i]     = new TfrmGamutVerifySingle(this);
        //LineSeriesGamut[i] = new TLineSeries(this);
    }

    //LineSeriesGamut[_TOTAL_COLORSPACE_NUM] = new TLineSeries(this);
    //PointSeriesGamut = new TPointSeries(this);

    frmDeltaUV = new TfrmDeltaEVerify(this);
    frmDeltaUV->chartDeltaE->Title->Text->Clear();
    frmDeltaUV->chartDeltaE->Title->Text->Add("DeltaUV");
    frmDeltaUV->chartDeltaE->LeftAxis->Maximum = 0.1;
    frmDeltaUV->chartDeltaE->BottomAxis->Maximum = 255;
    frmDeltaUV->chartDeltaE->BottomAxis->Minimum = 65;
    frmDICOMGammaVerify = new TfrmGammaVerify(this);

    frmTG18Verify = new TfrmTG18Verify(this);
    frmTG18GammaVerify = new TfrmTG18GammaVerify(this);

	frmGammaVerify_FreesyncII = new TfrmGammaVerify(this);
    frmGammaVerifyM[_REC_709]->rgRefGammaIndex->ItemIndex = 2;

    frmGammaVerifyM[_EBU]->rgRefGammaIndex->Items->Clear();
    TStringList* ItemList = new TStringList();
	ItemList->Clear();
    ItemList->Add("2.2");
    ItemList->Add("2.35");
    frmGammaVerifyM[_EBU]->rgRefGammaIndex->Items->AddStrings(ItemList);
    frmGammaVerifyM[_EBU]->rgRefGammaIndex->ItemIndex = 1;

    frmGammaVerifyM[_DCI_P3]->rgRefGammaIndex->Items->Clear();
    TStringList* ItemList2 = new TStringList();
    ItemList2->Clear();
    ItemList2->Add("2.2");
    ItemList2->Add("2.6");
    frmGammaVerifyM[_DCI_P3]->rgRefGammaIndex->Items->AddStrings(ItemList2);
    frmGammaVerifyM[_DCI_P3]->rgRefGammaIndex->ItemIndex = 1;

    frmDICOMGammaVerify->rgRefGammaIndex->Visible = false;
	frmGammaVerify_FreesyncII->rgRefGammaIndex->Visible = false;

    delete ItemList;

}

__fastcall TfrmTest::~TfrmTest()
{
    for(int i = 0; i < _TOTAL_COLORSPACE_NUM; i++)
    {
        frmGammaVerifyM[i]->~TfrmGammaVerify();
        frmDeltaEVerifyM[i]->~TfrmDeltaEVerify();
        frmCTVerifyM[i]->~TfrmCTVerify();
        frmGamutVerifySingleM[i]->~TfrmGamutVerifySingle();
        //chkbColorSpace[i]->~TCheckBox();
        //LineSeriesGamut[i]->~TLineSeries();
    }

    //LineSeriesGamut[_TOTAL_COLORSPACE_NUM]->~TLineSeries();
    //PointSeriesGamut->~TPointSeries();

    frmDeltaUV->~TfrmDeltaEVerify();
    frmDICOMGammaVerify->~TfrmGammaVerify();
	frmGammaVerify_FreesyncII->~TfrmGammaVerify();
}
//---------------------------------------------------------------------------

void __fastcall TfrmTest::AddOCCPages(BYTE ucColorDomain, int *cnt)
{
    TTabSheet* TabGamma = new TTabSheet(PageControl1);
    TabGamma->PageControl = PageControl1;
    TabGamma->Caption = strColorDomainName[ucColorDomain] + " Gamma";
    frmGammaVerifyM[ucColorDomain]->Parent = PageControl1->Pages[*cnt];
    frmGammaVerifyM[ucColorDomain]->Show();
    (*cnt)++;

    TTabSheet* TabCT = new TTabSheet(PageControl1);
    TabCT->PageControl = PageControl1;
    TabCT->Caption = strColorDomainName[ucColorDomain] + " CT";
    frmCTVerifyM[ucColorDomain]->Parent = PageControl1->Pages[*cnt];
    frmCTVerifyM[ucColorDomain]->Show();
    (*cnt)++;

    TTabSheet* TabDeltaE = new TTabSheet(PageControl1);
    TabDeltaE->PageControl = PageControl1;
    TabDeltaE->Caption = strColorDomainName[ucColorDomain] + " DeltaE";
    frmDeltaEVerifyM[ucColorDomain]->Parent = PageControl1->Pages[*cnt];
    frmDeltaEVerifyM[ucColorDomain]->Show();
    (*cnt)++;

    TTabSheet* TabGamut = new TTabSheet(PageControl1);
    TabGamut->PageControl = PageControl1;
    TabGamut->Caption = strColorDomainName[ucColorDomain] + " Gamut";
    frmGamutVerifySingleM[ucColorDomain]->Parent = PageControl1->Pages[*cnt];
    frmGamutVerifySingleM[ucColorDomain]->Show();
    (*cnt)++;
}
//---------------------------------------------------------------------------
void __fastcall TfrmTest::AddOGCPages(int *cnt)
{
    TTabSheet* TabGamma = new TTabSheet(PageControl1);
    TabGamma->PageControl = PageControl1;
    TabGamma->Caption = "OGC Gamma";
    frmGammaVerify->Parent = PageControl1->Pages[*cnt];
    frmGammaVerify->Show();
    (*cnt)++;

    TTabSheet* TabCT = new TTabSheet(PageControl1);
    TabCT->PageControl = PageControl1;
    TabCT->Caption = "OGC CT";
    frmCTVerify->Parent = PageControl1->Pages[*cnt];
    frmCTVerify->Show();
    (*cnt)++;

    TTabSheet* TabDeltaUV = new TTabSheet(PageControl1);
    TabDeltaUV->PageControl = PageControl1;
    TabDeltaUV->Caption = "OGC DeltaUV";
    frmDeltaUV->Parent = PageControl1->Pages[*cnt];
    frmDeltaUV->Show();
    (*cnt)++;
}
//---------------------------------------------------------------------------
void __fastcall TfrmTest::AddDICOMPages(int *cnt)
{
    TTabSheet* TabGamma = new TTabSheet(PageControl1);
    TabGamma->PageControl = PageControl1;
    TabGamma->Caption = "DICOM Gamma";
    frmDICOMGammaVerify->Parent = PageControl1->Pages[*cnt];
    frmDICOMGammaVerify->Show();
    (*cnt)++;
}
//---------------------------------------------------------------------------
void __fastcall TfrmTest::AddTG18Pages(int cnt)
{
		TTabSheet* TabGamma = new TTabSheet(PageControl1);
	    TabGamma->PageControl = PageControl1;
	    TabGamma->Caption = "TG18 Gamma";
	    frmTG18GammaVerify->Parent = PageControl1->Pages[cnt];
	    frmTG18GammaVerify->Show();
	    cnt++;

        TTabSheet* TabTG18 = new TTabSheet(PageControl1);
	    TabTG18->PageControl = PageControl1;
	    TabTG18->Caption = "TG18";
	    frmTG18Verify->Parent = PageControl1->Pages[cnt];
	    frmTG18Verify->Show();
	    cnt++;

}
//---------------------------------------------------------------------------
void __fastcall TfrmTest::AddGamutPages(int *cnt)
{
    TTabSheet* TabGamut = new TTabSheet(PageControl1);
    TabGamut->PageControl = frmTest->PageControl1;
    TabGamut->Caption = "Gamut";
    //int count = frmTest->PageControl1->PageCount;
    frmGamutVerify->Parent = frmTest->PageControl1->Pages[*cnt];
    frmGamutVerify->Show();
    (*cnt)++;
}

//---------------------------------------------------------------------------
void __fastcall TfrmTest::AddRGBGammaPages(int *cnt)
{
    TTabSheet* TabGamut = new TTabSheet(PageControl1);
    TabGamut->PageControl = frmTest->PageControl1;
    TabGamut->Caption = "RGB Gamma";
    //int count = frmTest->PageControl1->PageCount;
    frmRGBGammaVerify->Parent = frmTest->PageControl1->Pages[*cnt];
    frmRGBGammaVerify->Show();
    (*cnt)++;
}
//---------------------------------------------------------------------------
void __fastcall TfrmTest::AddAMDHDRPages(int *cnt)
{
    TTabSheet* TabGamma = new TTabSheet(PageControl1);
    TabGamma->PageControl = PageControl1;
    TabGamma->Caption = "FREESYNC II EOTF";
    frmGammaVerify_FreesyncII->Parent = PageControl1->Pages[*cnt];
    frmGammaVerify_FreesyncII->Show();
    (*cnt)++;
}
//---------------------------------------------------------------------------
void GetGammaGrayRef(float *GammaGrayRef, float minLv, float maxLv, float fGammaIndex)
{
    for(int i = 0; i < 256; i++)
    {
        GammaGrayRef[i] = minLv + pow((double)i/255.0, fGammaIndex) * maxLv;
    }
}
//---------------------------------------------------------------------------
float GetJNDStep(float min, float max)
{
    float step;
    step = (max - min)/1023.0;
    return step;
}

float Max(float fX, float fY)
{
    if(fX>fY)
    {
        return fX;
    }
    return fY;
}

float ABS(float a)
{
    if(a < 0)
    a = -a;

    return a;
}

BYTE GetHDROutput(COLOR_INPUT_STRUCT *sRGBVerify, COLOR_OUTPUT_STRUCT *strOutput, float PanelMaxLv)
{
    float r,g,b;
    float X,Y,Z;
    float x,y;
    float u,v;
    float Lv;
    BYTE bPass = 0;
    float LvError;
    float uError, vError;
	float TempRGB[3] = {0};
	float TempXYZ[3] = {0};

    for(int nIndex = 0; nIndex < 18; nIndex++)
    {
	    TempRGB[0] = sRGBVerify[nIndex].R;
		TempRGB[1] = sRGBVerify[nIndex].G;
		TempRGB[2] = sRGBVerify[nIndex].B;

	    // 20170214 Hung modify for HDR sRGBpanel
	    g_rtdColormapGetHDRTargetXYZ(_HDR_BT2020, TempRGB, TempXYZ);

		X = TempXYZ[0];
		Y = TempXYZ[1];
		Z = TempXYZ[2];

	    x = X/(X+Y+Z);
		y = Y/(X+Y+Z);
		Lv = Y *10000;

		u = 4*x/(12*y-2*x+3);
		v = 9*y/(12*y-2*x+3);

		strOutput[nIndex].DeltaE94 = sqrt(pow(u-sRGBVerify[nIndex].u,2)+ pow(v-sRGBVerify[nIndex].v,2));

		strOutput[nIndex].CH[0] = u;
		strOutput[nIndex].CH[1] = v;
		strOutput[nIndex].Lab[0]= Lv;
		strOutput[nIndex].Lab[1]= x;
		strOutput[nIndex].Lab[2]= y;

		strOutput[nIndex].XYZ[0]= X;
		strOutput[nIndex].XYZ[1]= Y;
		strOutput[nIndex].XYZ[2]= Z;

	    uError = ABS(u-sRGBVerify[nIndex].u);    //delta u
		vError = ABS(v-sRGBVerify[nIndex].v);    //delta v
	    LvError = ABS(Lv-sRGBVerify[nIndex].Lv)/Lv*100;
	    strOutput[nIndex].DeltaE00 = LvError ;

        if(nIndex < 4 )    //Gray 1-2 Lv Error & duv Check
        {
           if((uError > 0.014) || (vError > 0.019))
            bPass = 1;

           if(LvError >= 25)
            bPass = 1;
        }
        else if(nIndex < 7 )    //Gray 1-2 Lv Error & duv Check
        {
           if((uError > 0.008) || (vError > 0.011))
            bPass = 1;
        }
        else if(nIndex < 15) // Gray 3-10 duv Check
        {
           if((uError > 0.006) || (vError > 0.009))
            bPass = 1;
        }
        else // sRGB R/G/B pattern
        {
           if(strOutput[nIndex].DeltaE94 > 0.04)
             bPass = 2;
        }

     }
     return bPass;
}

//---------------------------------------------------------------------------
void __fastcall TfrmTest::OGCChartandReport(float fGammaIndex, COLOR_INPUT_STRUCT *Gamma_measure, int number)
{
	int i,j;
	int index;
	int nStep;
    float Gamma_ref_Lv[256];
    float FinalX, FinalY;
    int CompensateCT;
    float stdX, stdY;

    frmGammaVerify->LineSeriesGammaRef->Active = true;
    frmGammaVerify->LineSeriesGammaRef->Clear();
    frmGammaVerify->PointSeriesGammaMeas->Active = true;
    frmGammaVerify->PointSeriesGammaMeas->Clear();
    frmDeltaEVerify->serBarDeltaE->Active = true;
    frmDeltaEVerify->serBarDeltaE->Clear();
    frmDeltaUV->serBarDeltaE->Active = true;
    frmDeltaUV->serBarDeltaE->Clear();
    frmCTVerify->LineSeriesCT->Active = true;
    frmCTVerify->LineSeriesCT->Clear();

    nStep = (number == 255)? 1 : 256/number;

	COLOR_OUTPUT_STRUCT *Result = new COLOR_OUTPUT_STRUCT[number + 1];

	GetGammaGrayRef(Gamma_ref_Lv, Gamma_measure[0].Lv, Gamma_measure[number].Lv, fGammaIndex);

    for(i = 0; i < 256; i++)
    {
        frmGammaVerify->LineSeriesGammaRef->AddXY(i, Gamma_ref_Lv[i]);	//Gamma reference
    }

    for(i = 0, index = 0; i < 255; i += nStep, index++)
    {
        frmGammaVerify->PointSeriesGammaMeas->AddXY(i, Gamma_measure[index].Lv);	//Gamma measure(point)

        if(index != 0)
        {
            g_rtdsRGBColorSetInput(Gamma_measure + index);
            g_rtdsRGBColorgetValues(0, g_rtdGammaGetPanelBitNum()); // Calculate DeltaE94
            g_rtdsRGBColorGetOutput(Result + index);
        }

        if(i>=64)   //Only print the gray larger than 64
        {
            //Gamma_measure[index].duv = pow((pow(Gamma_measure[number].u - Gamma_measure[index].u, 2) + pow(Gamma_measure[number].v - Gamma_measure[index].v, 2)), 0.5); // peichen modify 20110215

           /* FinalX = Gamma_measure[index].Sx;
            FinalY = Gamma_measure[index].Sy;

            CompensateCT = -437*pow((FinalX-0.332)/(FinalY-0.1858),3) +
                           3601*pow((FinalX-0.332)/(FinalY-0.1858),2) -
                           6861*(FinalX-0.332)/(FinalY-0.1858) + 5514.31;   // Calculate CT*/
            frmCTVerify->LineSeriesCT->AddXY(i, Gamma_measure[index].lT);
            frmDeltaUV->serBarDeltaE->AddXY(i, Gamma_measure[index].duv);
        }
    }

    frmGammaVerify->PointSeriesGammaMeas->AddXY(255, Gamma_measure[number].Lv);

    Gamma_measure[number].Sx = Gamma_measure[number].Sx;
    Gamma_measure[number].Sy = Gamma_measure[number].Sy;
    g_rtdsRGBColorSetInput(Gamma_measure + number);
    g_rtdsRGBColorgetValues(0, g_rtdGammaGetPanelBitNum());
    g_rtdsRGBColorGetOutput(Result + number);

    /*FinalX = Gamma_measure[number].Sx;
    FinalY = Gamma_measure[number].Sy;

    CompensateCT = -437*pow((FinalX-0.332)/(FinalY-0.1858),3) +
                   3601*pow((FinalX-0.332)/(FinalY-0.1858),2) -
                   6861*(FinalX-0.332)/(FinalY-0.1858) + 5514.31;*/

    frmCTVerify->LineSeriesCT->AddXY(255, Gamma_measure[index].lT);
    frmDeltaUV->serBarDeltaE->AddXY(255, Gamma_measure[number].duv);

	String strFileName = "Output/Gamma" + FormatFloat( "###0.0 ", fGammaIndex)+"Test_" + IntToStr(number) + "Points.csv";
	ofstream fout7(strFileName.c_str());

	fout7<<"R,"<<"G,"<<"B,"<<"Lv,"<<"Sx,"<<"Sy,"<<"X,"<<"Y,"<<"Z,"<<"u',"<<"v',"<<",";
	fout7<<"DeltaE76,"<<"DeltaE94,"<<"DeltaE00,"<<"Delta uv,"<<",";
	fout7<<"L*,"<<"a*,"<<"b*,"<<"C*,"<<"H*"<<endl;

	for(i = 0, index = 0; i < 255; i += nStep, index++)
	{
        if(index != 0)
        {
        	g_rtdsRGBColorSetInput(Gamma_measure + index);
			g_rtdsRGBColorgetValues(0, g_rtdGammaGetPanelBitNum());
		    g_rtdsRGBColorGetOutput(Result + index);

            fout7<< Gamma_measure[index].R<<","<< Gamma_measure[index].G<<","<< Gamma_measure[index].B<<",";
            fout7<< Gamma_measure[index].Lv<<","<< Gamma_measure[index].Sx<<","<< Gamma_measure[index].Sy<<",";
            fout7<< Result[index].XYZ[0]<<","<< Result[index].XYZ[1]<<","<< Result[index].XYZ[2]<<",";
            fout7<< Gamma_measure[index].u<<","<< Gamma_measure[index].v<<",,";
            fout7<< Result[index].DeltaE76<<","<< Result[index].DeltaE94<<","<< Result[index].DeltaE00<<","<< Gamma_measure[index].duv<<",,";
            fout7<< Result[index].Lab[0]<<","<< Result[index].Lab[1]<<","<< Result[index].Lab[2]<<",";
            fout7<< Result[index].CH[0]<<","<< Result[index].CH[1]<<endl;
        }
	}

	fout7.close();

    //File output
    String strTestFileName = "Output/Gamma" + FormatFloat( "###0.0", fGammaIndex) + "_Verify.txt";
    ofstream fout(strTestFileName.c_str());
    fout<<"Target Gamma:  Gamma"<<(float)fGammaIndex<<endl;
    fout<<"Step"<<"\t"<<"Ref_Lv"<<"\t"<<"Measure_Lv"<<"\t"<<"Measure_x"<<"\t"<<"Measure_y"<<"\t"<<"Temp"<<"\t"<<"Error%"<<endl;

    for(i = 0, j = 0, index = 0; i < 255; i++)
    {
        if(i == j)
        {
            if(((i / nStep) + 1) < 10)
            {
                fout<<(i/nStep)+1<<"\t"<<Gamma_ref_Lv[i]<<"\t"<<Gamma_measure[index].Lv<<"\t"<<Gamma_measure[index].Sx<<"\t"<<Gamma_measure[index].Sy<<"\t"<<Gamma_measure[index].lT<<"\t"<<(fabs(Gamma_ref_Lv[i] - Gamma_measure[index].Lv)/Gamma_ref_Lv[i] * 100)<<endl;
            }
            else
            {
                 fout<<(i/nStep)+1<<"\t"<<Gamma_ref_Lv[i]<<"\t"<<Gamma_measure[index].Lv<<"\t"<<Gamma_measure[index].Sx<<"\t"<<Gamma_measure[index].Sy<<"\t"<<Gamma_measure[index].lT<<"\t"<<(fabs(Gamma_ref_Lv[i] - Gamma_measure[index].Lv)/Gamma_ref_Lv[i] * 100)<<endl;
            }

            j += nStep;
            index++;
        }
    }

    fout<<(256/nStep)+1<<"\t"<<Gamma_ref_Lv[255]<<"\t"<<Gamma_measure[number].Lv<<"\t"<<Gamma_measure[number].Sx<<"\t"<<Gamma_measure[number].Sy<<"\t"<<Gamma_measure[number].lT<<"\t"<<(fabs(Gamma_ref_Lv[255] - Gamma_measure[number].Lv)/Gamma_ref_Lv[255] * 100)<<endl;
    fout.close();
	delete []Result;
}

void __fastcall TfrmTest::AMDHDRChartandReport(int nEOTFIndex, COLOR_INPUT_STRUCT *EOTF_measure, int number, BYTE ucPanelBitNum)
{
	int i,j;
	int index;
	int step;

    float EOTF_ref_Lv[1024];
	float EOTF_ref_Lv_256[256]; // Hung
    float EOTF_ref_JND[1024];

    step = (number == 255)? 1 : 256/number;

	ofstream foutggg("Output/EOTF_GrayRef.txt");

	GetGammaGrayRef(EOTF_ref_Lv, EOTF_measure[0].Lv, EOTF_measure[number].Lv, 2.2);

	foutggg.close();

	// draw Chart
	frmGammaVerify_FreesyncII->LineSeriesGammaRef->Active = true;
	frmGammaVerify_FreesyncII->LineSeriesGammaRef->Clear();
	frmGammaVerify_FreesyncII->PointSeriesGammaMeas->Active = true;
	frmGammaVerify_FreesyncII->PointSeriesGammaMeas->Clear();

	//Draw DICOM reference Curve
    for(i = 0; i < 256; i++) // Hung
    {
        frmGammaVerify_FreesyncII->LineSeriesGammaRef->AddXY(i, EOTF_ref_Lv[i]);
    }

	// Draw Measure result
    for(i = 0, index = 0; i < 255; i += step, index++)
    {
        frmGammaVerify_FreesyncII->PointSeriesGammaMeas->AddXY(i, EOTF_measure[index].Lv);	//DICOM measure(point)
    }
    if(number < 256)
    {
        frmGammaVerify_FreesyncII->PointSeriesGammaMeas->AddXY(255, EOTF_measure[number].Lv);	//DICOM measure(point)
    }
    else
    {
        frmGammaVerify_FreesyncII->PointSeriesGammaMeas->AddXY(255, EOTF_measure[255].Lv);
    }

    String strFileName = "Output/EOTFtest_" + IntToStr(number) + "Points.csv";

    ofstream fout77(strFileName.c_str());

    fout77<<"R,"<<"G,"<<"B,"<<",";
	fout77<<"Lv,"<<"x,"<<"y,"<<"Temp,"<<",";
    fout77<<"Ref_Lv,"<<""<<"Error%,"<<endl;

    COLOR_OUTPUT_STRUCT *Result = new COLOR_OUTPUT_STRUCT[number + 1];

    for(i = 0, index = 0; i < 255; i += step, index++)
    {
        if(index != 0)
        {
            g_rtdsRGBColorSetInput(EOTF_measure + index);
            g_rtdsRGBColorgetValues(0, g_rtdGammaGetPanelBitNum());
            g_rtdsRGBColorGetOutput(Result + index);
        }

        fout77<< EOTF_measure[index].R<<","<< EOTF_measure[index].G<<","<< EOTF_measure[index].B<<",,";
        fout77<< EOTF_measure[index].Lv<<","<< EOTF_measure[index].Sx<<","<< EOTF_measure[index].Sy<<","<< EOTF_measure[index].lT<<",,";
        fout77<< EOTF_ref_Lv[i]<<","<< (fabs(EOTF_ref_Lv[i] - EOTF_measure[index].Lv)/EOTF_ref_Lv[i] * 100)<<endl;
    }

	g_rtdsRGBColorSetInput(EOTF_measure + number);
    g_rtdsRGBColorgetValues(0, g_rtdGammaGetPanelBitNum()); // Calculate DeltaE94
    g_rtdsRGBColorGetOutput(Result + number);

    if(number > 255);
     number = 255;

    fout77<< EOTF_measure[number].R<<","<< EOTF_measure[number].G<<","<< EOTF_measure[number].B<<",,";
    fout77<< EOTF_measure[number].Lv<<","<< EOTF_measure[number].Sx<<","<< EOTF_measure[number].Sy<<","<< EOTF_measure[number].lT<<",,";
    fout77<< EOTF_ref_Lv[255]<<","<< (fabs(EOTF_ref_Lv[255] - EOTF_measure[number].Lv)/EOTF_ref_Lv[255] * 100)<<endl;
    fout77.close();
    delete []Result;
    Result = NULL;
}

void __fastcall TfrmTest::OGCRGBGammaChartandReport(float fGammaIndex, COLOR_INPUT_STRUCT *Gamma_measure, int number, BYTE ucMode)
{
	int i,j;
	int index;
	int nStep;
    float Gamma_ref_Lv[256];
    float FinalX, FinalY;
    int CompensateCT;
    float stdX, stdY;
    TLineSeries *GammaRef;
    TPointSeries *GammaMeas;
    String strMode[] = {"R", "G", "B"};

    switch(ucMode)
    {
        case _R:
            GammaRef = frmRGBGammaVerify->LineSeriesRGammaRef;
            GammaMeas = frmRGBGammaVerify->PointSeriesRGammaMeas;
            break;

        case _G:
            GammaRef = frmRGBGammaVerify->LineSeriesGGammaRef;
            GammaMeas = frmRGBGammaVerify->PointSeriesGGammaMeas;
            break;

        case _B:
            GammaRef = frmRGBGammaVerify->LineSeriesBGammaRef;
            GammaMeas = frmRGBGammaVerify->PointSeriesBGammaMeas;
            break;

        default:
            break;
    }

    GammaRef->Active = true;
    GammaRef->Clear();
    GammaMeas->Active = true;
    GammaMeas->Clear();

    nStep = (number == 255)? 1 : 256 / number;

	GetGammaGrayRef(Gamma_ref_Lv, Gamma_measure[0].Lv, Gamma_measure[number].Lv, fGammaIndex);

    for(i = 0; i < 256; i++)
    {
        GammaRef->AddXY(i, Gamma_ref_Lv[i]);	//Gamma reference
    }

    for(i = 0, index = 0; i < 255; i += nStep, index++)
    {
        GammaMeas->AddXY(i, Gamma_measure[index].Lv);	//Gamma measure(point)
    }

    GammaMeas->AddXY(255, Gamma_measure[number].Lv);

	String strFileName = "Output/RGBGamma" + FormatFloat( "###0.0 ", fGammaIndex)+"Test" + strMode[ucMode] + "_" + IntToStr(number) + "Points.csv";
	ofstream fout7(strFileName.c_str());

	fout7<<"R,"<<"G,"<<"B,"<<"Lv,"<<"Sx,"<<"Sy,"<<"RefLv,"<<"ErrorRate"<<endl;

	for(i = 0, index = 0; i < 255; i += nStep, index++)
	{
        if(index != 0)
        {
            fout7<< Gamma_measure[index].R<<","<< Gamma_measure[index].G<<","<< Gamma_measure[index].B<<",";
            fout7<< Gamma_measure[index].Lv<<","<< Gamma_measure[index].Sx<<","<< Gamma_measure[index].Sy<<",";
            fout7<< Gamma_ref_Lv[i]<<","<<(100.0 * abs(Gamma_ref_Lv[i] - Gamma_measure[index].Lv)/Gamma_ref_Lv[i])<<"%"<<endl;
        }
	}

	fout7.close();

}

void __fastcall TfrmTest::DICOMChartandReport(COLOR_INPUT_STRUCT *DICOM_measure, int number, BYTE ucPanelBitNum)
{
	int i,j;
	int index;
	int step;

    float DICOM_ref_Lv[1024];
	float DICOM_ref_Lv_256[256]; // Hung
    float DICOM_ref_JND[1024];

    step = (number == 255)? 1 : 256/number;

	ofstream foutgg("Output/DICOM_GrayRef.txt");

	for(i = 0; i < 1024; i++)
	{
		DICOM_ref_Lv[i] = g_rtdDICOMGetDICOMRef(i);
		foutgg<<DICOM_ref_Lv[i]<<endl;
	}
	foutgg.close();

	// draw Chart
	frmDICOMGammaVerify->LineSeriesGammaRef->Active = true;
	frmDICOMGammaVerify->LineSeriesGammaRef->Clear();
	frmDICOMGammaVerify->PointSeriesGammaMeas->Active = true;
	frmDICOMGammaVerify->PointSeriesGammaMeas->Clear();

	//Draw DICOM reference Curve
    for(i = 0; i < 256; i++) // Hung
    {
		if(ucPanelBitNum == 8) // 8 bit panel
        {
        	j = i*4;
		}
		else
		{
			j = (i == 255) ? 1023: (i *4);
		}
        frmDICOMGammaVerify->LineSeriesGammaRef->AddXY(i, DICOM_ref_Lv[j]);
		DICOM_ref_Lv_256[i] = DICOM_ref_Lv[j]; // Hung
    }

	// Draw Measure result
    for(i = 0, index = 0; i < 255; i += step, index++)
    {
        frmDICOMGammaVerify->PointSeriesGammaMeas->AddXY(i, DICOM_measure[index].Lv);	//DICOM measure(point)
    }
    if(number < 256)
    {
        frmDICOMGammaVerify->PointSeriesGammaMeas->AddXY(255, DICOM_measure[number].Lv);	//DICOM measure(point)
    }
    else
    {
        frmDICOMGammaVerify->PointSeriesGammaMeas->AddXY(255, DICOM_measure[255].Lv);
    }

    String strFileName = "Output/DICOMtest_" + IntToStr(number) + "Points.csv";

    ofstream fout7(strFileName.c_str());

    fout7<<"R,"<<"G,"<<"B,"<<",";
	fout7<<"Lv,"<<"x,"<<"y,"<<"Temp,"<<",";
    fout7<<"Ref_Lv,"<<""<<"Error%,"<<endl;

    COLOR_OUTPUT_STRUCT *Result = new COLOR_OUTPUT_STRUCT[number + 1];

    for(i = 0, index = 0; i < 255; i += step, index++)
    {
        if(index != 0)
        {
            g_rtdsRGBColorSetInput(DICOM_measure + index);
            g_rtdsRGBColorgetValues(0, g_rtdGammaGetPanelBitNum());
            g_rtdsRGBColorGetOutput(Result + index);
        }

        fout7<< DICOM_measure[index].R<<","<< DICOM_measure[index].G<<","<< DICOM_measure[index].B<<",,";
        fout7<< DICOM_measure[index].Lv<<","<< DICOM_measure[index].Sx<<","<< DICOM_measure[index].Sy<<","<< DICOM_measure[index].lT<<",,";
        fout7<< DICOM_ref_Lv_256[i]<<","<< (fabs(DICOM_ref_Lv_256[i] - DICOM_measure[index].Lv)/DICOM_ref_Lv_256[i] * 100)<<endl;
    }

	g_rtdsRGBColorSetInput(DICOM_measure + number);
    g_rtdsRGBColorgetValues(0, g_rtdGammaGetPanelBitNum()); // Calculate DeltaE94
    g_rtdsRGBColorGetOutput(Result + number);

    if(number > 255);
     number = 255;

    fout7<< DICOM_measure[number].R<<","<< DICOM_measure[number].G<<","<< DICOM_measure[number].B<<",,";
    fout7<< DICOM_measure[number].Lv<<","<< DICOM_measure[number].Sx<<","<< DICOM_measure[number].Sy<<","<< DICOM_measure[number].lT<<",,";
    fout7<< DICOM_ref_Lv_256[255]<<","<< (fabs(DICOM_ref_Lv_256[255] - DICOM_measure[number].Lv)/DICOM_ref_Lv_256[255] * 100)<<endl;
    fout7.close();
    delete []Result;
    Result = NULL;
}

void __fastcall TfrmTest::TG18ChartandReport(COLOR_INPUT_STRUCT *DICOM_measure, int number, int step, BYTE ucPanelBitNum) //justin_sun
{
	int i,j;
	int index;
	float AmbientLight;
	float JNDStep, MaxJND, MinJND;
    float DICOM_ref_Lv[1024];
	float DICOM_ref_Lv_256[256]; // Hung
    float DICOM_Lv[256];
	float Delta_i[256];
	float Delta_id[256];
	float MaxDelta = 0;
	float Delta_08[256];
	float Delta_09[256];
	float Delta_11[256];
	float Delta_12[256];

    //step = (number == 255)? 1 : 256/number;
    AmbientLight = g_rtdDICOMGetDICOMAL();
	JNDStep = g_rtdDICOMGetJNDStep();
	MaxJND = g_rtdDICOMGetMaxJND();
	MinJND = g_rtdDICOMGetMinJND();

	ofstream foutgg("Output/TG18Verify_Mea.txt");
	for(i = 0; i < number; i++)
	{
		DICOM_Lv[i] = DICOM_measure[i].Lv + AmbientLight;
		foutgg<<DICOM_Lv[i]<<endl;
	}
	foutgg.close();

	ofstream foutgh("Output/TG18Verify_Ref.txt");

	for(i = 0; i < 1024; i++)
	{
		DICOM_ref_Lv[i] = g_rtdDICOMGetDICOMRef(i);
		foutgh<<DICOM_ref_Lv[i]<<endl;
	}
	foutgh.close();

	// draw Chart
	frmTG18GammaVerify->LineSeriesGammaRef->Active = true;
	frmTG18GammaVerify->LineSeriesGammaRef->Clear();
	frmTG18GammaVerify->PointSeriesGammaMeas->Active = true;
	frmTG18GammaVerify->PointSeriesGammaMeas->Clear();

	frmTG18Verify->LineSeriesGammaRef->Active = true;
	frmTG18Verify->LineSeriesGammaRef->Clear();
	frmTG18Verify->PointSeriesGammaMeas->Active = true;
	frmTG18Verify->PointSeriesGammaMeas->Clear();

	//Draw DICOM reference Curve
    for(i = 0; i < 256; i++) // Hung
    {
		if(ucPanelBitNum == 8) // 8 bit panel
        {
        	j = i*4;
		}
		else
		{
			//j = (i == 255) ? 1023: (i *4);
			j = (i *4) *1023/1020;
		}

		DICOM_ref_Lv_256[i] = DICOM_ref_Lv[j]+ AmbientLight; // justin_sun
		frmTG18GammaVerify->LineSeriesGammaRef->AddXY(MinJND + j * JNDStep , log(DICOM_ref_Lv_256[i])/log(10));
    }

	// Draw Measure result
    for(i = 0, index = 0; i < 256; i += step, index++)
    {
    	if(ucPanelBitNum == 8) // 8 bit panel
        {
        	j = i*4;
		}
		else
		{
			//j = (i == 255) ? 1023: (i *4);
			j = (i *4) *1023/1020;
		}
        frmTG18GammaVerify->PointSeriesGammaMeas->AddXY(MinJND + j * JNDStep, log(DICOM_Lv[index])/log(10));	//DICOM measure(point)
    }
	//Draw TG18
	for(i = 0; i < number - 1; i++)
	{
		float JNDNow,JNDNext,JNDDelta;
	    if(ucPanelBitNum == 8) // 8 bit panel
        {
        	JNDNext = (i+1) * JNDStep * step * 4;
			JNDNow = i * JNDStep * step * 4;
		}
		else
		{
			JNDNext = (i+1) * JNDStep * step * 4 *1023/1020;
			JNDNow = i * JNDStep * step * 4 *1023/1020;
		}
		JNDDelta = JNDNext - JNDNow;
		Delta_i[i] = 2*(DICOM_Lv[i+1] - DICOM_Lv[i])/((DICOM_Lv[i+1] + DICOM_Lv[i]) * JNDDelta);
		frmTG18Verify -> PointSeriesGammaMeas->AddXY(MinJND + JNDNow + JNDDelta/2, log(Delta_i[i])/log(10));
	}

	for(i = 0; i < number - 1; i++)
	{
		float JNDNow,JNDNext,JNDDelta;
	    if(ucPanelBitNum == 8) // 8 bit panel
        {
        	JNDNext = (i+1) * JNDStep * step * 4;
			JNDNow = i * JNDStep * step * 4;
		}
		else
		{
			JNDNext = (i+1) * JNDStep * step * 4 *1023/1020;
			JNDNow = i * JNDStep * step * 4 *1023/1020;
		}
		JNDDelta = JNDNext - JNDNow;
		Delta_id[i] = 2*(DICOM_ref_Lv_256[(i+1)*step] - DICOM_ref_Lv_256[i*step])/((DICOM_ref_Lv_256[(i+1)*step] + DICOM_ref_Lv_256[i*step]) * JNDDelta);
		Delta_08[i] = Delta_id[i] * 0.8;
		Delta_09[i] = Delta_id[i] * 0.9;
		Delta_11[i] = Delta_id[i] * 1.1;
		Delta_12[i] = Delta_id[i] * 1.2;
		frmTG18Verify -> LineSeriesGammaRef->AddXY(MinJND + JNDNow + JNDDelta/2, log(Delta_id[i])/log(10));
		frmTG18Verify -> Series1->AddXY(MinJND + JNDNow + JNDDelta/2, log(Delta_08[i])/log(10));
		frmTG18Verify -> Series2->AddXY(MinJND + JNDNow + JNDDelta/2, log(Delta_09[i])/log(10));
		frmTG18Verify -> Series3->AddXY(MinJND + JNDNow + JNDDelta/2, log(Delta_11[i])/log(10));
		frmTG18Verify -> Series4->AddXY(MinJND + JNDNow + JNDDelta/2, log(Delta_12[i])/log(10));
	}

	for(i = 0; i < number - 1; i++)
	{
		if(MaxDelta < fabs(Delta_i[i] - Delta_id[i])/Delta_id[i])
			MaxDelta = fabs(Delta_i[i] - Delta_id[i])/Delta_id[i];
	}

	frmTG18Verify ->EditMaxKDelta->Text = MaxDelta * 100;

	String strFileName = "Output/DICOMtest_TG18.csv";
    ofstream fout7(strFileName.c_str());

    fout7<<"R,"<<"G,"<<"B,"<<",";
	fout7<<"Lv,"<<"x,"<<"y,"<<"Temp,"<<",";
	fout7<<"Ref_Lv,"<<",";
    fout7<<"Delta_i,"<<""<<"Delta_id,"<<""<<"MaxDelta,"<<endl;

	for(i = 0, index = 0; i <= 256; i += step, index++)
    {
        fout7<< DICOM_measure[index].R<<","<< DICOM_measure[index].G<<","<< DICOM_measure[index].B<<",,";
        fout7<< DICOM_Lv[index]<<","<< DICOM_measure[index].Sx<<","<< DICOM_measure[index].Sy<<","<< DICOM_measure[index].lT<<",,";
        fout7<< DICOM_ref_Lv_256[i]<<",,";
		fout7<< Delta_i[index]<<","<<Delta_id[index];
		if(i == 0)
		{
			fout7<<","<<MaxDelta<<endl;
		}
		else
		{
			fout7<<endl;
		}
    }
	fout7.close();
}

void __fastcall TfrmTest::OCCDeltaEChartandReportForCustomer(BYTE ucColorDomain, COLOR_INPUT_STRUCT *sRGBVerify, int nPatternLength, String strModule, String strSN, String strTester)
{
    if(ucColorDomain >= _TOTAL_COLORSPACE_NUM)
    {
        ShowMessage("Color Domain Not Supported!");
        return;
    }

    COLOR_OUTPUT_STRUCT *Result = new COLOR_OUTPUT_STRUCT[nPatternLength + 1];
	String strFileName = "Output/" + strColorDomainName[ucColorDomain] + "_" + IntToStr((int)nPatternLength) + "Patterns_" + strSN + ".csv";
    ofstream fout7(strFileName.c_str());
    ofstream fout("Output/OCCDeltaETest.csv");
    fout7<<strModule.c_str()<<","<<strSN.c_str()<<","<<strTester.c_str()<<",";
    fout<<"R,G,B,DeltaE94"<<endl;
    frmDeltaEVerifyM[ucColorDomain]->serBarDeltaE->Active = true;
    frmDeltaEVerifyM[ucColorDomain]->chartDeltaE->BottomAxis->Maximum = nPatternLength + 1;
    frmDeltaEVerifyM[ucColorDomain]->serBarDeltaE->Clear();

	//---------------Print Chart--------------------
	for(int nIndex = 0; nIndex < nPatternLength; nIndex++)
	{
		// Print Chart
		g_rtdsRGBColorSetInput(sRGBVerify + nIndex);
		g_rtdsRGBColorgetValues(ucColorDomain, g_rtdGammaGetPanelBitNum());
		g_rtdsRGBColorGetOutput(Result + nIndex);

        frmDeltaEVerifyM[ucColorDomain]->serBarDeltaE->AddXY(nIndex, Result[nIndex].DeltaE94);
        fout7<<Result[nIndex].DeltaE94<<",";
        fout<<sRGBVerify[nIndex].R<<","<<sRGBVerify[nIndex].G<<","<<sRGBVerify[nIndex].B<<","<<Result[nIndex].DeltaE94<<endl;
	}

    fout7<<strSN.c_str()<<endl;



	fout7.close();
	fout.close();

    g_bOCCVerifyOK &= JudgeOCCVerifyResult(Result, 3, 5, (int)nPatternLength);
	delete []Result;
}

void __fastcall TfrmTest::OCCDeltaEChartandReport(BYTE ucColorDomain, COLOR_INPUT_STRUCT *sRGBVerify, int nPatternLength)
{
    if(ucColorDomain >= _TOTAL_COLORSPACE_NUM)
    {
        ShowMessage("Color Domain Not Supported!");
        return;
    }

	String strFileName = "Output/" + strColorDomainName[ucColorDomain] + "_" + IntToStr((int)nPatternLength) + "Patterns_" + ".csv";
    COLOR_OUTPUT_STRUCT *Result = new COLOR_OUTPUT_STRUCT[nPatternLength + 1];
    ofstream fout7(strFileName.c_str());

    fout7<<"R,"<<"G,"<<"B,"<<"Lv,"<<"Sx,"<<"Sy,"<<"X,"<<"Y,"<<"Z,"<<"u',"<<"v',"<<","<<"DeltaE76,"<<"DeltaE94,"<<"DeltaE00,"<<"Delta uv,"<<","<<"L*,"<<"a*,"<<"b*,"<<"C*,"<<"H*"<<endl;

    frmDeltaEVerifyM[ucColorDomain]->serBarDeltaE->Active = true;
    frmDeltaEVerifyM[ucColorDomain]->chartDeltaE->BottomAxis->Maximum = nPatternLength + 1;
    frmDeltaEVerifyM[ucColorDomain]->serBarDeltaE->Clear();

	//---------------Print Chart--------------------
	for(int nIndex = 0; nIndex < nPatternLength; nIndex++)
	{

		g_rtdsRGBColorSetInput(sRGBVerify + nIndex);
		g_rtdsRGBColorgetValues(ucColorDomain, g_rtdGammaGetPanelBitNum());
		g_rtdsRGBColorGetOutput(Result + nIndex);

        fout7<<sRGBVerify[nIndex].R<<","<<sRGBVerify[nIndex].G<<","<<sRGBVerify[nIndex].B<<",";
        fout7<<sRGBVerify[nIndex].Lv<<","<<sRGBVerify[nIndex].Sx<<","<<sRGBVerify[nIndex].Sy<<",";
        fout7<<Result[nIndex].XYZ[0]<<","<<Result[nIndex].XYZ[1]<<","<<Result[nIndex].XYZ[2]<<",";
        fout7<<sRGBVerify[nIndex].u<<","<<sRGBVerify[nIndex].v<<",,";
        fout7<<Result[nIndex].DeltaE76<<","<<Result[nIndex].DeltaE94<<","<<Result[nIndex].DeltaE00<<","<<sRGBVerify[nIndex].duv<<",,";
        fout7<<Result[nIndex].Lab[0]<<","<<Result[nIndex].Lab[1]<<","<<Result[nIndex].Lab[2]<<",";
        fout7<<Result[nIndex].CH[0]<<","<<Result[nIndex].CH[1]<<endl;

        // Print Chart
        frmDeltaEVerifyM[ucColorDomain]->serBarDeltaE->AddXY(nIndex, Result[nIndex].DeltaE94);
    }

    fout7.close();

    g_bOCCVerifyOK &= JudgeOCCVerifyResult(Result, 3, 5, (int)nPatternLength);

	delete []Result;
}

void __fastcall TfrmTest::OCCGammaCTChartandReportForCustomer(BYTE ucColorDomain, COLOR_INPUT_STRUCT *Gamma_measure, int number, String strModule, String strSN, String strTester)
{
	int i,j;
	int index;
	BYTE step = 256/number;
    float Gamma_ref_Lv[256];
    float FinalX, FinalY;
    int CompensateCT;
    float stdX, stdY;

    if(ucColorDomain >= _TOTAL_COLORSPACE_NUM)
    {
        ShowMessage("Color Domain Not Supported!");
        return;
    }

    frmGammaVerifyM[ucColorDomain]->LineSeriesGammaRef->Active = true;
    frmGammaVerifyM[ucColorDomain]->LineSeriesGammaRef->Clear();
    frmGammaVerifyM[ucColorDomain]->PointSeriesGammaMeas->Active = true;
    frmGammaVerifyM[ucColorDomain]->PointSeriesGammaMeas->Clear();
    frmCTVerifyM[ucColorDomain]->LineSeriesCT->Active = true;
    frmCTVerifyM[ucColorDomain]->LineSeriesCT->Clear();



	COLOR_OUTPUT_STRUCT *Result = new COLOR_OUTPUT_STRUCT[number + 1];

	GetGammaGrayRef(Gamma_ref_Lv, Gamma_measure[0].Lv, Gamma_measure[number].Lv, 2.2);

    for(i = 0; i < 256; i++)
    {
        frmGammaVerifyM[ucColorDomain]->LineSeriesGammaRef->AddXY(i, Gamma_ref_Lv[i]);	//Gamma reference
    }

    for(i = 0, index = 0; i < 255; i += step, index++)
    {
        frmGammaVerifyM[ucColorDomain]->PointSeriesGammaMeas->AddXY(i, Gamma_measure[index].Lv);	//Gamma measure(point)

        if(index != 0)
        {
           // Gamma_measure[index].Sx = Gamma_measure[index].Sx;
           // Gamma_measure[index].Sy = Gamma_measure[index].Sy;

            g_rtdsRGBColorSetInput(Gamma_measure + index);
            g_rtdsRGBColorgetValues(ucColorDomain, g_rtdGammaGetPanelBitNum()); // Calculate DeltaE94
            g_rtdsRGBColorGetOutput(Result + index);
        }


        if(i>=64)   //Only print the gray larger than 64
        {
            //Gamma_measure[index].duv = pow((pow(Gamma_measure[number].u - Gamma_measure[index].u, 2) + pow(Gamma_measure[number].v - Gamma_measure[index].v, 2)), 0.5); // peichen modify 20110215

            //FinalX = Gamma_measure[index].Sx;
            //FinalY = Gamma_measure[index].Sy;
            /*
            CompensateCT = -437*pow((FinalX-0.332)/(FinalY-0.1858),3) +
                           3601*pow((FinalX-0.332)/(FinalY-0.1858),2) -
                           6861*(FinalX-0.332)/(FinalY-0.1858) + 5514.31;   // Calculate CT
                           */
            frmCTVerifyM[ucColorDomain]->LineSeriesCT->AddXY(i, Gamma_measure[index].lT);
        }
    }

    frmGammaVerifyM[ucColorDomain]->PointSeriesGammaMeas->AddXY(255, Gamma_measure[number].Lv);

    Gamma_measure[number].Sx = Gamma_measure[number].Sx;
    Gamma_measure[number].Sy = Gamma_measure[number].Sy;
    g_rtdsRGBColorSetInput(Gamma_measure + number);
    g_rtdsRGBColorgetValues(ucColorDomain, g_rtdGammaGetPanelBitNum());
    g_rtdsRGBColorGetOutput(Result + number);

   // FinalX = Gamma_measure[number].Sx;
   // FinalY = Gamma_measure[number].Sy;
/*
    CompensateCT = -437*pow((FinalX-0.332)/(FinalY-0.1858),3) +
                   3601*pow((FinalX-0.332)/(FinalY-0.1858),2) -
                   6861*(FinalX-0.332)/(FinalY-0.1858) + 5514.31;
*/

    frmCTVerifyM[ucColorDomain]->LineSeriesCT->AddXY(255, Gamma_measure[number].lT);

	String strFileName1 = "Output/";
    strFileName1 += strColorDomainName[ucColorDomain] + "CT_" + strSN + ".csv";
    ofstream fout;
    fout.open(strFileName1.c_str());

    String strFileName2 = "Output/";
    strFileName2 += "Lv_" + strSN + ".csv";
    ofstream fout2;
    fout2.open(strFileName2.c_str());

    fout<<strModule.c_str()<<","<<DateTimeToStr(Now()).c_str()<<","<<strSN.c_str()<<","<<strTester.c_str()<<",";
    fout2<<strModule.c_str()<<","<<DateTimeToStr(Now()).c_str()<<","<<strSN.c_str()<<","<<strTester.c_str()<<",";


    for(i = 0, j = 0, index = 0; i < 255; i++)
    {
        if(i == j)
        {
            if(i != 0)
            {
              fout2<<Gamma_measure[index].Lv<<",";
              fout<<Gamma_measure[index].lT<<",";
            }
            j += step;
            index++;
        }
    }

    fout2<<Gamma_measure[number].Lv<<","<<endl;
	fout<<Gamma_measure[number].lT<<","<<endl;

    fout.close();
    fout2.close();

	delete []Result;
}

void __fastcall TfrmTest::OCCGammaCTChartandReport(BYTE ucColorDomain, COLOR_INPUT_STRUCT *Gamma_measure, int number)
{
	int i,j;
	int index;
	BYTE step = 256/number;

    float Gamma_ref_Lv[256];

    float FinalX, FinalY;
    int CompensateCT;
    float stdX, stdY;

    if(ucColorDomain >= _TOTAL_COLORSPACE_NUM)
    {
        ShowMessage("Color Domain Not Supported!");
        return;
    }

    frmGammaVerifyM[ucColorDomain]->LineSeriesGammaRef->Active = true;
    frmGammaVerifyM[ucColorDomain]->LineSeriesGammaRef->Clear();
    frmGammaVerifyM[ucColorDomain]->PointSeriesGammaMeas->Active = true;
    frmGammaVerifyM[ucColorDomain]->PointSeriesGammaMeas->Clear();
    frmCTVerifyM[ucColorDomain]->LineSeriesCT->Active = true;
    frmCTVerifyM[ucColorDomain]->LineSeriesCT->Clear();

	COLOR_OUTPUT_STRUCT *Result = new COLOR_OUTPUT_STRUCT[number + 1];

	GetGammaGrayRef(Gamma_ref_Lv, Gamma_measure[0].Lv, Gamma_measure[number].Lv, 2.2);

    for(i = 0; i < 256; i++)
    {
        frmGammaVerifyM[ucColorDomain]->LineSeriesGammaRef->AddXY(i, Gamma_ref_Lv[i]);	//Gamma reference
    }

    for(i = 0, index = 0; i < 255; i += step, index++)
    {
        frmGammaVerifyM[ucColorDomain]->PointSeriesGammaMeas->AddXY(i, Gamma_measure[index].Lv);	//Gamma measure(point)

        if(index != 0)
        {
           // Gamma_measure[index].Sx = Gamma_measure[index].Sx;
          //  Gamma_measure[index].Sy = Gamma_measure[index].Sy;

            g_rtdsRGBColorSetInput(Gamma_measure + index);
            g_rtdsRGBColorgetValues(ucColorDomain, g_rtdGammaGetPanelBitNum()); // Calculate DeltaE94
            g_rtdsRGBColorGetOutput(Result + index);
        }


        if(i>=64)   //Only print the gray larger than 64
        {
            //Gamma_measure[index].duv = pow((pow(Gamma_measure[number].u - Gamma_measure[index].u, 2) + pow(Gamma_measure[number].v - Gamma_measure[index].v, 2)), 0.5); // peichen modify 20110215

           /* FinalX = Gamma_measure[index].Sx;
            FinalY = Gamma_measure[index].Sy;

            CompensateCT = -437*pow((FinalX-0.332)/(FinalY-0.1858),3) +
                           3601*pow((FinalX-0.332)/(FinalY-0.1858),2) -
                           6861*(FinalX-0.332)/(FinalY-0.1858) + 5514.31;   // Calculate CT
            */
            frmCTVerifyM[ucColorDomain]->LineSeriesCT->AddXY(i, Gamma_measure[index].lT);
        }
    }

    frmGammaVerifyM[ucColorDomain]->PointSeriesGammaMeas->AddXY(255, Gamma_measure[number].Lv);

    Gamma_measure[number].Sx = Gamma_measure[number].Sx;
    Gamma_measure[number].Sy = Gamma_measure[number].Sy;

    g_rtdsRGBColorSetInput(Gamma_measure + number);
    g_rtdsRGBColorgetValues(0, g_rtdGammaGetPanelBitNum());
    g_rtdsRGBColorGetOutput(Result + number);

    /*FinalX = Gamma_measure[number].Sx;
    FinalY = Gamma_measure[number].Sy;


    CompensateCT = -437*pow((FinalX-0.332)/(FinalY-0.1858),3) +
                   3601*pow((FinalX-0.332)/(FinalY-0.1858),2) -
                   6861*(FinalX-0.332)/(FinalY-0.1858) + 5514.31;
    */

    frmCTVerifyM[ucColorDomain]->LineSeriesCT->AddXY(255, Gamma_measure[number].lT);

	String strFileName = "Output/" + strColorDomainName[ucColorDomain] + "_GammaCT_Test_" + IntToStr(number) + "Points.csv";

    ofstream fout(strFileName.c_str());

    //fout<<"Target Gamma:  Gamma2.2, CT: 6500K"<<endl;
    fout<<"Step,Ref_Lv,Measure_Lv,Measure_x,Measure_y,Temp,Error%"<<endl;

    for(i = 0, j = 0, index = 0; i < 255; i++)
    {
        if(i == j)
        {
            if(((i / step) + 1) < 10)
            {
                fout<<(i/step)+1<<","<<Gamma_ref_Lv[i]<<","<<Gamma_measure[index].Lv<<","<<Gamma_measure[index].Sx<<","<<Gamma_measure[index].Sy<<","<<Gamma_measure[index].lT<<","<<(fabs(Gamma_ref_Lv[i] - Gamma_measure[index].Lv)/Gamma_ref_Lv[i] * 100)<<endl;
            }
            else
            {
                 fout<<(i/step)+1<<","<<Gamma_ref_Lv[i]<<","<<Gamma_measure[index].Lv<<","<<Gamma_measure[index].Sx<<","<<Gamma_measure[index].Sy<<","<<Gamma_measure[index].lT<<","<<(fabs(Gamma_ref_Lv[i] - Gamma_measure[index].Lv)/Gamma_ref_Lv[i] * 100)<<endl;
            }

            j += step;
            index++;
        }
    }

    fout<<(256/step)+1<<","<<Gamma_ref_Lv[255]<<","<<Gamma_measure[number].Lv<<","<<Gamma_measure[number].Sx<<","<<Gamma_measure[number].Sy<<","<<Gamma_measure[number].lT<<","<<(fabs(Gamma_ref_Lv[255] - Gamma_measure[number].Lv)/Gamma_ref_Lv[255] * 100)<<endl;
    fout.close();
	delete []Result;
}

void __fastcall TfrmTest::HDRVerifyChartandReport(BYTE ucColorDomain, COLOR_INPUT_STRUCT *sRGBVerify, float PanelMaxLv)
{
    COLOR_OUTPUT_STRUCT *Result = new COLOR_OUTPUT_STRUCT[18];
    g_bHDRVerifyOK =  GetHDROutput(sRGBVerify, Result, PanelMaxLv);

    String strFileName = "";

    if(g_bHDRVerifyOK == 0)
    {
       strFileName += "Output/HDRVerifyPass.csv";
    }
    else //if(g_bHDRVerifyOK != 0)
    {
       strFileName += "Output/HDRVerifyFail.csv";
    }

    ofstream fouthdr(strFileName.c_str());

    fouthdr<<"R,"<<"G,"<<"B,"<<"Lv,"<<"Sx,"<<"Sy,"<<"X,"<<"Y,"<<"Z,"<<"u',"<<"v',"<<"Delta uv,"<<"Delta Lv%,"<<"Ideal Lv,"<<"Ideal u',"<<"Ideal v'"<<endl;

	//---------------Print Chart--------------------
	for(int nIndex = 0; nIndex < 18; nIndex++)
	{

        fouthdr<<sRGBVerify[nIndex].R<<","<<sRGBVerify[nIndex].G<<","<<sRGBVerify[nIndex].B<<",";
        fouthdr<<sRGBVerify[nIndex].Lv<<","<<sRGBVerify[nIndex].Sx<<","<<sRGBVerify[nIndex].Sy<<",";
        fouthdr<<Result[nIndex].XYZ[0]<<","<<Result[nIndex].XYZ[1]<<","<<Result[nIndex].XYZ[2]<<",";
        fouthdr<<sRGBVerify[nIndex].u<<","<<sRGBVerify[nIndex].v<<",";
        fouthdr<<Result[nIndex].DeltaE94<<",";
        fouthdr<<Result[nIndex].DeltaE00<<",";
        fouthdr<<Result[nIndex].Lab[0]<<","<<Result[nIndex].CH[0]<<","<<Result[nIndex].CH[1]<<endl;
       }

    fouthdr<<PanelMaxLv<<endl;

    fouthdr.close();
    delete []Result;
}


void  __fastcall TfrmTest::ShowColorDomainGamut(BYTE ucColorDomain)
{
    frmGamutVerify->LineSeriesGamut[ucColorDomain]->XValues->Order = loNone;
    frmGamutVerify->LineSeriesGamut[ucColorDomain]->YValues->Order = loNone;
    frmGamutVerify->LineSeriesGamut[ucColorDomain]->Active = true;
    frmGamutVerify->LineSeriesGamut[ucColorDomain]->Clear();
    frmGamutVerify->LineSeriesGamut[ucColorDomain]->AddXY(fGamutPoint[ucColorDomain][0][0], fGamutPoint[ucColorDomain][0][1]);
    frmGamutVerify->LineSeriesGamut[ucColorDomain]->AddXY(fGamutPoint[ucColorDomain][1][0], fGamutPoint[ucColorDomain][1][1]);
    frmGamutVerify->LineSeriesGamut[ucColorDomain]->AddXY(fGamutPoint[ucColorDomain][2][0], fGamutPoint[ucColorDomain][2][1]);
    frmGamutVerify->LineSeriesGamut[ucColorDomain]->AddXY(fGamutPoint[ucColorDomain][0][0], fGamutPoint[ucColorDomain][0][1]);
}

void  __fastcall TfrmTest::ShowMeasuredGamut(COLOR_INPUT_STRUCT *sRGBVerify, int nPatternLength)
{
    // Show Gamut Measure
    frmGamutVerify->PointSeriesGamut->Active = true;
    frmGamutVerify->PointSeriesGamut->Clear();

    for(int i = 0; i < nPatternLength; i++)
    {
        frmGamutVerify->PointSeriesGamut->AddXY(sRGBVerify[i].Sx, sRGBVerify[i].Sy);
    }
}

void __fastcall TfrmTest::ShowGamutandMeasure(BYTE ucColorDomain, COLOR_INPUT_STRUCT *sRGBVerify, int nPatternLength)
{
    frmGamutVerifySingleM[ucColorDomain]->serTargetGamut->Active = true;
    frmGamutVerifySingleM[ucColorDomain]->serTargetGamut->Clear();
    frmGamutVerifySingleM[ucColorDomain]->serMeasure->Active = true;
    frmGamutVerifySingleM[ucColorDomain]->serMeasure->Clear();
    frmGamutVerifySingleM[ucColorDomain]->nPatternLength = nPatternLength;
    memcpy(frmGamutVerifySingleM[ucColorDomain]->sRGBVerify, sRGBVerify, sizeof(COLOR_INPUT_STRUCT)*nPatternLength);
    frmGamutVerifySingleM[ucColorDomain]->ShowColorDomainGamut(ucColorDomain);
    frmGamutVerifySingleM[ucColorDomain]->ShowMeasuredGamut(sRGBVerify, nPatternLength);
}

bool __fastcall TfrmTest::JudgeOCCVerifyResult(COLOR_OUTPUT_STRUCT *Result, float fAvgDeltaE, float fMaxDeltaE, int nPatternLength)
{
    float fDeltaEAverage = 0;
    float fDeltaEMax = 0;

    for(int i = 0; i < nPatternLength; i++)
    {
        if(Result[i].DeltaE94 > fDeltaEMax)
        {
            fDeltaEMax = Result[i].DeltaE94;
        }

        fDeltaEAverage += Result[i].DeltaE94;
    }

    fDeltaEAverage = fDeltaEAverage / nPatternLength;

    if((fDeltaEAverage < fAvgDeltaE) && (fDeltaEMax < fMaxDeltaE))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void __fastcall TfrmTest::ClearUI(void)
{
    for(int i = 0; i < _TOTAL_COLORSPACE_NUM; i++)
    {
       frmGammaVerifyM[i]->Parent = frmTest;
       frmGammaVerifyM[i]->Close();
       frmDeltaEVerifyM[i]->Parent = frmTest;
       frmDeltaEVerifyM[i]->Close();
       frmCTVerifyM[i]->Parent = frmTest;
       frmCTVerifyM[i]->Close();
       frmGamutVerifySingleM[i]->Parent = frmTest;
       frmGamutVerifySingleM[i]->Close();
    }

    frmCTVerify->Parent = frmTest;
    frmCTVerify->Close();
    frmGammaVerify->Parent = frmTest;
    frmGammaVerify->Close();
    frmDeltaEVerify->Parent = frmTest;
    frmDeltaEVerify->Close();
    frmDeltaUV->Parent = frmTest;
    frmDeltaUV->Close();
    frmDICOMGammaVerify->Parent = frmTest;
    frmDICOMGammaVerify->Close();
    frmGamutVerify->Parent = frmTest;
    frmGamutVerify->Close();
    frmTG18Verify->Parent = frmTest;
    frmTG18GammaVerify->Close();
    frmTG18GammaVerify->Parent = frmTest;
    frmTG18Verify->Close();
	frmGammaVerify_FreesyncII->Parent = frmTest;
	frmGammaVerify_FreesyncII->Close();

    int nPageCnt = frmTest->PageControl1->PageCount;

    if(nPageCnt > 0)
    {
        for(int i = 0; i < nPageCnt; i++)
        {
            frmTest->PageControl1->Pages[0]->~TTabSheet();
        }
    }
}

void __fastcall TfrmTest::ShowReportUI(BYTE ucVerifyType)
{
    int cnt = 0;
    frmTest->ClearUI();

    if((ucVerifyType &(1 << OGC)) != 0)
    {
        frmTest->AddOGCPages(&cnt);

        if(frmDemo->chkbRGBGammaOn->Checked)
        {
            frmTest->AddRGBGammaPages(&cnt);
        }
        //cnt = cnt + 3;
    }

    if((ucVerifyType &(1<< OCC)) != 0)
    {
        WORD wCheckStatus = frmDemo->CheckVerifyStatus();

        int j = 0;

        for(j = 0; j < _TOTAL_COLORSPACE_NUM;  j++)
        {

            if((wCheckStatus & (0x01 << j))!= 0)
            {
                frmTest->AddOCCPages(j, &cnt);
                //cnt += 4;
            }
        }

        AddGamutPages(&cnt);
    }

    if((ucVerifyType &(1<< DICOM)) != 0)
    {
        frmTest->AddDICOMPages(&cnt);
        //cnt++;
    }
    if((ucVerifyType &(1<< (DICOM + 1))) != 0)
    {
        frmTest->AddTG18Pages(cnt);
        cnt++;
    }
	if((ucVerifyType &(1<< FREESYNC2)) != 0)
	{
		frmTest->AddAMDHDRPages(&cnt);
		cnt++;
	}
}
void __fastcall TfrmTest::FormShow(TObject *Sender)
{
    ShowReportUI(g_ucVerifyType);
}
//---------------------------------------------------------------------------
