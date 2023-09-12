//---------------------------------------------------------------------------

#ifndef GamutVerifySingleH
#define GamutVerifySingleH
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

#include "OGCOCC_Export.h"
//---------------------------------------------------------------------------
class TfrmGamutVerifySingle : public TForm
{
__published:	// IDE-managed Components
    TChart *ChartGamut;
    TLineSeries *serTargetGamut;
    TPointSeries *serMeasure;
private:	// User declarations
public:		// User declarations
    __fastcall TfrmGamutVerifySingle(TComponent* Owner);
    void  __fastcall ShowColorDomainGamut(BYTE ucColorDomain);
    void  __fastcall ShowMeasuredGamut(COLOR_INPUT_STRUCT *sRGBVerify, int nPatternLength);

    COLOR_INPUT_STRUCT sRGBVerify[256];
    int nPatternLength;
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmGamutVerifySingle *frmGamutVerifySingle;
//---------------------------------------------------------------------------
#endif
