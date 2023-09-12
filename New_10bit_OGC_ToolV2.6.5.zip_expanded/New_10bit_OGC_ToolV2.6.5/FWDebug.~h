
#ifndef FWDebugH
#define FWDebugH
#include <vcl.h>
#include "OGCOCC_Export.h"

#define _FALSE  false
#define _TRUE   true


#define _OGC_SUPPORT   _OFF
#define _OCC_SUPPORT   _ON
#define _OCC_LUT_MODE  _OFF
#define _OGC_DICOM_SUPPORT   _OFF
#define _RGB_GAMMA_FUNCTION _OFF

#define _OGC_TYPE                   0
#define _OCC_TYPE                   1
#define _DICOM_TYPE                 2
#define _RGB_GAIN_TYPE              3
#define _COLOR_MATRIX_TYPE          4

//#define _OCC_POSITION   0
#define _OGC_TOTAL_GAMMA 5
#define _OGC_TOTAL_CT    6
#define _OGC_FLASH_BANK  0//12
#define _OGC_FLASH_PAGE  0

#define _OGC_RGB_GAIN_TOTAL_SPACE                   0x100
#define _OGC_GAMMA_TABLE_SIZE                       0x1A00 // 2200*3 = 0x19C8 2052 * 3 = 0x180C
#define _OGC_RGB_GAIN_ACTUAL_SIZE                   (_OGC_TOTAL_GAMMA * _OGC_TOTAL_CT * 6)

#define _OCC_COLOR_MATRIX_TOTAL_SPACE               0x900 // Max: 324*7 = 972 = 0x3CC ; sRGB/Adobe/SoftProof/Userdefine/EBU/Rec709/DCI-P3
#define _OCC_COLORMATRIX_TABLE_SIZE                 (_OCC_LUT_MODE == _ON ? 312 : 18)
#define _OGC_HEADER_LENGTH                          (4 + (_OGC_TOTAL_GAMMA + 1 + _OGC_TOTAL_CT + 1))
#define _OCC_HEADER_LENGTH                          6
#define _DICOM_HEADER_LENGTH                        5
#define _WHITE_LV_HEADER_LENGTH                     6

#define _OGC_RGB_GAIN_ADDRESS                       0
#define _OGC_HEADER_ADDRESS                         (_OGC_RGB_GAIN_ADDRESS + _OGC_RGB_GAIN_ACTUAL_SIZE)
#define _OCC_HEADER_ADDRESS                         (_OGC_HEADER_ADDRESS + _OGC_HEADER_LENGTH)
#define _DICOM_HEADER_ADDRESS                       (_OCC_HEADER_ADDRESS + _OCC_HEADER_LENGTH)
#define _WHITE_LV_HEADER_ADDRESS                    (_DICOM_HEADER_ADDRESS + _DICOM_HEADER_LENGTH)
#define _OGC_GAMMA1_ADDRESS                         (_OGC_RGB_GAIN_ADDRESS + _OGC_RGB_GAIN_TOTAL_SPACE)
#define _OGC_GAMMA2_ADDRESS                         (_OGC_GAMMA1_ADDRESS + _OGC_GAMMA_TABLE_SIZE * _OGC_SUPPORT * (_OGC_TOTAL_GAMMA > 1 ? 1 : 0))
#define _OGC_GAMMA3_ADDRESS                         (_OGC_GAMMA2_ADDRESS + _OGC_GAMMA_TABLE_SIZE * _OGC_SUPPORT * (_OGC_TOTAL_GAMMA > 2 ? 1 : 0))
#define _OGC_GAMMA4_ADDRESS                         (_OGC_GAMMA3_ADDRESS + _OGC_GAMMA_TABLE_SIZE * _OGC_SUPPORT * (_OGC_TOTAL_GAMMA > 3 ? 1 : 0))
#define _OGC_GAMMA5_ADDRESS                         (_OGC_GAMMA4_ADDRESS + _OGC_GAMMA_TABLE_SIZE * _OGC_SUPPORT * (_OGC_TOTAL_GAMMA > 4 ? 1 : 0))

#define _OCC_GAMMA10_ADDRESS                        (_OGC_GAMMA5_ADDRESS + _OGC_GAMMA_TABLE_SIZE * _OGC_SUPPORT)
#define _OCC_SRGBMATRIX_ADDRESS                     (_OCC_GAMMA10_ADDRESS + _OGC_GAMMA_TABLE_SIZE * _OCC_SUPPORT)
#define _OCC_ADOBEMATRIX_ADDRESS                    (_OCC_SRGBMATRIX_ADDRESS + _OCC_COLORMATRIX_TABLE_SIZE * _OCC_SUPPORT)
#define _OCC_USERDEFINE_ADDRESS                     (_OCC_ADOBEMATRIX_ADDRESS + _OCC_COLORMATRIX_TABLE_SIZE * _OCC_SUPPORT)
#define _OCC_EBU_ADDRESS                            (_OCC_SRGBMATRIX_ADDRESS)
#define _OCC_SOFTPROOF_ADDRESS                      (_OCC_USERDEFINE_ADDRESS + _OCC_COLORMATRIX_TABLE_SIZE * _OCC_SUPPORT)
#define _OCC_REC709_ADDRESS                         (_OCC_SOFTPROOF_ADDRESS + _OCC_COLORMATRIX_TABLE_SIZE * _OCC_SUPPORT)
#define _OCC_DCIP3_ADDRESS                          (_OCC_REC709_ADDRESS + _OCC_COLORMATRIX_TABLE_SIZE * _OCC_SUPPORT)

#define _OGC_DICOM_ADDRESS                          (_OCC_SRGBMATRIX_ADDRESS + _OCC_COLOR_MATRIX_TOTAL_SPACE * _OCC_SUPPORT)

#define _OGC_RGBGAMMA1_ADDRESS                         ((_OGC_TOTAL_GAMMA > 3) ? 0x10000 : (_OGC_DICOM_ADDRESS + _OGC_GAMMA_TABLE_SIZE * _OGC_DICOM_SUPPORT))
#define _OGC_RGBGAMMA2_ADDRESS                         (_OGC_RGBGAMMA1_ADDRESS + _OGC_GAMMA_TABLE_SIZE * _OGC_SUPPORT *_RGB_GAMMA_FUNCTION)
#define _OGC_RGBGAMMA3_ADDRESS                         (_OGC_RGBGAMMA2_ADDRESS + _OGC_GAMMA_TABLE_SIZE * _OGC_SUPPORT *_RGB_GAMMA_FUNCTION*(_OGC_TOTAL_GAMMA > 1 ? 1 : 0))
#define _OGC_RGBGAMMA4_ADDRESS                         (_OGC_RGBGAMMA3_ADDRESS + _OGC_GAMMA_TABLE_SIZE * _OGC_SUPPORT *_RGB_GAMMA_FUNCTION*(_OGC_TOTAL_GAMMA > 2 ? 1 : 0))
#define _OGC_RGBGAMMA5_ADDRESS                         (_OGC_RGBGAMMA4_ADDRESS + _OGC_GAMMA_TABLE_SIZE * _OGC_SUPPORT *_RGB_GAMMA_FUNCTION*(_OGC_TOTAL_GAMMA > 3 ? 1 : 0))

#define _DISP_CALIBRATION_TOTAL_END                    (_OGC_RGBGAMMA5_ADDRESS + _OGC_GAMMA_TABLE_SIZE * _OGC_SUPPORT *_RGB_GAMMA_FUNCTION*(_OGC_TOTAL_GAMMA > 4 ? 1 : 0))
#define _DISP_CALIBRATION_TOTAL_SPACE               (_DISP_CALIBRATION_TOTAL_END - _OGC_RGB_GAIN_ADDRESS)

#define _OGC_CHKSUM_ADDRESS                            (_OCC_GAMMA10_ADDRESS - 1)
#define _OGC_RGBGAMMA_CHKSUM_ADDRESS                   (_OGC_RGBGAMMA5_ADDRESS + _OGC_GAMMA_TABLE_SIZE - 1)
#define _OCC_CHKSUM_ADDRESS                            (_OCC_SRGBMATRIX_ADDRESS - 1)
#define _OCC_COLOR_MATRIX_CHKSUM_ADDRESS               (_OGC_DICOM_ADDRESS - 1)
#define _OGC_DICOM_CHKSUM_ADDRESS                      (_OGC_DICOM_ADDRESS + _OGC_GAMMA_TABLE_SIZE - 1)
#define _OGC_FINISH_ADDRESS                            (_OGC_CHKSUM_ADDRESS - 1)
#define _OCC_FINISH_ADDRESS                            (_OCC_CHKSUM_ADDRESS - 1)
#define _OGC_DICOM_FINISH_ADDRESS                      (_OGC_DICOM_CHKSUM_ADDRESS - 1)


void UserCommonDdcciDispCalibSaveLUT(BYTE ucTotalLength);
BYTE GetCheckSum();
void PrintFlash();

extern BYTE ucFlash[_DISP_CALIBRATION_TOTAL_END];
extern BYTE g_pucDdcciRxBuf[128];
extern int g_pusGammaCount[][3];
extern float fMeas[][3];
extern float fMeasRGB[][3];
extern float fOCCMeas[][3];
extern float fFS2Meas[][3];
extern BYTE UserCommonDdcciDispCalibCalCheckSum(BYTE ucCheckType) ;
void PrintLUTRange(void);
#endif

