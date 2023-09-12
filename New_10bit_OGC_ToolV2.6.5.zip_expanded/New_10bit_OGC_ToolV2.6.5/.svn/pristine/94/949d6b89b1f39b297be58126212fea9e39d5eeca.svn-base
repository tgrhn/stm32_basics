//---------------------------------------------------------------------------

#ifndef RGBGammaVerifyH
#define RGBGammaVerifyH
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
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TfrmRGBGammaVerify : public TForm
{
__published:	// IDE-managed Components
    TChart *chartGamma;
    TPointSeries *PointSeriesRGammaMeas;
    TLineSeries *LineSeriesRGammaRef;
    TButton *btnSavetoBmp;
    TLineSeries *LineSeriesGGammaRef;
    TPointSeries *PointSeriesBGammaMeas;
    TLineSeries *LineSeriesBGammaRef;
    TPointSeries *PointSeriesGGammaMeas;
    TSaveDialog *SaveDialog1;
    void __fastcall btnSavetoBmpClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmRGBGammaVerify(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmRGBGammaVerify *frmRGBGammaVerify;
//---------------------------------------------------------------------------
#endif
