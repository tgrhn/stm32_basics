//---------------------------------------------------------------------------

#ifndef TG18GammaH
#define TG18GammaH
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
//---------------------------------------------------------------------------
class TfrmTG18GammaVerify : public TForm
{
__published:	// IDE-managed Components
        TChart *chartGamma;
        TPointSeries *PointSeriesGammaMeas;
        TLineSeries *LineSeriesGammaRef;
private:	// User declarations
public:		// User declarations
        __fastcall TfrmTG18GammaVerify(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmTG18GammaVerify *frmTG18GammaVerify;
//---------------------------------------------------------------------------
#endif
