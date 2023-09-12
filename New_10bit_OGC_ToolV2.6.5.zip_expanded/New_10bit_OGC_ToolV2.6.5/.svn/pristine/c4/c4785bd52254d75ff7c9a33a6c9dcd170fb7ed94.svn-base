//---------------------------------------------------------------------------

#ifndef GamutVerifyH
#define GamutVerifyH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include "Dll/OGCOCC_Export.h"
//---------------------------------------------------------------------------
class TfrmGamutVerify : public TForm
{
__published:	// IDE-managed Components
    TChart *ChartGamut;
    TLineSeries *serStdSRGBGamut;
    TLineSeries *serPanelOrgGamut;
    TLineSeries *serUserDefineGamut;
    TLineSeries *serStdAdobeGamut;
    TLineSeries *serEBUGamut;
    TLineSeries *serPanelGamutAfterCal;
    TPointSeries *serMeasure;
    TLineSeries *serSoftProof;
    TLineSeries *serRec709;
    TLineSeries *serDCIP3;
    TLineSeries *serSMPTEC;
    TLineSeries *serUserDefineGamut2;
    TButton *btnShowGamut;
    void __fastcall btnShowGamutClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmGamutVerify(TComponent* Owner);

    TLineSeries *LineSeriesGamut[_TOTAL_COLORSPACE_NUM + 1]; // for Gamut Display
    TPointSeries *PointSeriesGamut;
    COLOR_INPUT_STRUCT sRGBVerify[256];
    int nPatternLength;


};
//---------------------------------------------------------------------------
extern PACKAGE TfrmGamutVerify *frmGamutVerify;
//---------------------------------------------------------------------------
#endif
