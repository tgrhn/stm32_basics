//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Unit1.cpp", frmDemo);
USEFORM("CTVerify.cpp", frmCTVerify);
USEFORM("DeltaEVerify.cpp", frmDeltaEVerify);
USEFORM("GammaVerify.cpp", frmGammaVerify);
USEFORM("GamutVerify.cpp", frmGamutVerify);
USEFORM("Test.cpp", frmTest);
USEFORM("GamutVerifySingle.cpp", frmGamutVerifySingle);
USEFORM("Measure.cpp", frmMeasure);
USEFORM("RGBGammaVerify.cpp", frmRGBGammaVerify);
USEFORM("TG18Gamma.cpp", frmTG18GammaVerify);
USEFORM("TG18Verify.cpp", frmTG18Verify);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->CreateForm(__classid(TfrmDemo), &frmDemo);
         Application->CreateForm(__classid(TfrmCTVerify), &frmCTVerify);
         Application->CreateForm(__classid(TfrmDeltaEVerify), &frmDeltaEVerify);
         Application->CreateForm(__classid(TfrmGammaVerify), &frmGammaVerify);
         Application->CreateForm(__classid(TfrmGamutVerify), &frmGamutVerify);
         Application->CreateForm(__classid(TfrmTest), &frmTest);
         Application->CreateForm(__classid(TfrmGamutVerifySingle), &frmGamutVerifySingle);
         Application->CreateForm(__classid(TfrmMeasure), &frmMeasure);
         Application->CreateForm(__classid(TfrmRGBGammaVerify), &frmRGBGammaVerify);
         Application->CreateForm(__classid(TfrmTG18GammaVerify), &frmTG18GammaVerify);
         Application->CreateForm(__classid(TfrmTG18Verify), &frmTG18Verify);
      //   Application->CreateForm(__classid(TForm2), &Form2);
         Application->Run();
    }
    catch (Exception &exception)
    {
         Application->ShowException(&exception);
    }
    catch (...)
    {
         try
         {
             throw Exception("");
         }
         catch (Exception &exception)
         {
             Application->ShowException(&exception);
         }
    }
    return 0;
}
//---------------------------------------------------------------------------
