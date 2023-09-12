//---------------------------------------------------------------------------

#ifndef HDRStepH
#define HDRStepH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
    TRadioGroup *rgStep;
    TGroupBox *GroupBox1;
    TCheckBox *chkbPatternR;
    TCheckBox *chkbPatternG;
    TCheckBox *chkbPatternB;
    TCheckBox *chkbPatternGray;
    TEdit *Edit1;
private:	// User declarations
public:		// User declarations
    __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
