//---------------------------------------------------------------------------

#ifndef TestH
#define TestH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>

#include "OGCOCC_Export.h"
//---------------------------------------------------------------------------
class TfrmTest : public TForm
{
__published:	// IDE-managed Components
    TPageControl *PageControl1;
    TTabSheet *TabSheet1;
    void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmTest(TComponent* Owner);
    __fastcall TfrmTest::~TfrmTest();
    void __fastcall OGCChartandReport(float fGammaIndex, COLOR_INPUT_STRUCT *Gamma_measure, int number);
    void __fastcall OGCRGBGammaChartandReport(float fGammaIndex, COLOR_INPUT_STRUCT *Gamma_measure, int number, BYTE ucMode);
    void __fastcall DICOMChartandReport(COLOR_INPUT_STRUCT *DICOM_measure, int number, BYTE ucPanelBitNum);
    void __fastcall TG18ChartandReport(COLOR_INPUT_STRUCT *DICOM_measure, int number, int step, BYTE ucPanelBitNum);
    void __fastcall AMDHDRChartandReport(int nEOTFIndex, COLOR_INPUT_STRUCT *Gamma_measure, int number, BYTE ucPanelBitNum);
    void __fastcall OCCDeltaEChartandReportForCustomer(BYTE ucColorDomain, COLOR_INPUT_STRUCT *sRGBVerify, int nPatternLength, String strModule, String strSN, String strTester);
    void __fastcall OCCDeltaEChartandReport(BYTE ucColorDomain, COLOR_INPUT_STRUCT *sRGBVerify, int nPatternLength);
    void __fastcall OCCGammaCTChartandReportForCustomer(BYTE ucColorDomain, COLOR_INPUT_STRUCT *Gamma_measure, int number, String strModule, String strSN, String strTester);
    void __fastcall OCCGammaCTChartandReport(BYTE ucColorDomain, COLOR_INPUT_STRUCT *Gamma_measure, int number);
    void __fastcall HDRVerifyChartandReport(BYTE ucColorDomain, COLOR_INPUT_STRUCT *sRGBVerify, float PanelMaxLv);
    void __fastcall ShowColorDomainGamut(BYTE ucColorDomain);
    void __fastcall ShowMeasuredGamut(COLOR_INPUT_STRUCT *sRGBVerify, int nPatternLength);
    bool __fastcall JudgeOCCVerifyResult(COLOR_OUTPUT_STRUCT *Result, float fAvgDeltaE, float fMaxDeltaE, int nPatternLength);
    void __fastcall ClearUI(void);
    void __fastcall AddOCCPages(BYTE ucColorDomain, int *cnt);
    void __fastcall AddOGCPages(int *cnt);
    void __fastcall AddDICOMPages(int *cnt);
    void __fastcall AddTG18Pages(int cnt);
    void __fastcall AddGamutPages(int *cnt);
    void __fastcall AddRGBGammaPages(int *cnt);
    void __fastcall AddAMDHDRPages(int *cnt);
    void __fastcall ShowReportUI(BYTE ucVerifyType);
    void __fastcall ShowGamutandMeasure(BYTE ucColorDomain, COLOR_INPUT_STRUCT *sRGBVerify, int nPatternLength);
  //  bool g_bOCCVerifyOK;

};
//---------------------------------------------------------------------------
extern PACKAGE TfrmTest *frmTest;
extern void GetGammaGrayRef(float *GammaGrayRef, float minLv, float maxLv, float fGammaIndex);
extern String strColorDomainName[];
//---------------------------------------------------------------------------
#endif
