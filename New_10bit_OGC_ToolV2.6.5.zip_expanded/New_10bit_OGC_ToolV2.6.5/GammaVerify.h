//---------------------------------------------------------------------------

#ifndef GammaVerifyH
#define GammaVerifyH
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
class TfrmGammaVerify : public TForm
{
__published:	// IDE-managed Components
    TChart *chartGamma;
    TPointSeries *PointSeriesGammaMeas;
    TLineSeries *LineSeriesGammaRef;
    TRadioGroup *rgRefGammaIndex;
    TButton *btnSavetoBmp;
    TSaveDialog *SaveDialog1;
    void __fastcall btnSavetoBmpClick(TObject *Sender);
    void __fastcall rgRefGammaIndexClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmGammaVerify(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmGammaVerify *frmGammaVerify;
extern void GetGammaGrayRef(float *GammaGrayRef, float minLv, float maxLv, float fGammaIndex);
//---------------------------------------------------------------------------
#endif
