//---------------------------------------------------------------------------

#ifndef DeltaEVerifyH
#define DeltaEVerifyH
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
class TfrmDeltaEVerify : public TForm
{
__published:	// IDE-managed Components
    TChart *chartDeltaE;
    TBarSeries *serBarDeltaE;
    TButton *btnSaveToBmp;
    TSaveDialog *SaveDialog1;
    void __fastcall btnSaveToBmpClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmDeltaEVerify(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmDeltaEVerify *frmDeltaEVerify;
//---------------------------------------------------------------------------
#endif
