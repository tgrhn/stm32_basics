//-------------------------------Debug Start-----------------------------
#include "FWDebug.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


BYTE ucFlash[_DISP_CALIBRATION_TOTAL_END] = {0};
BYTE g_pucDdcciRxBuf[128] = {0};

DWORD tGAMMA_INDEX[] =
{
#if(_OGC_SUPPORT == _ON)
    _OGC_GAMMA1_ADDRESS,
#if(_OGC_TOTAL_GAMMA > 1)
    _OGC_GAMMA2_ADDRESS,
#if(_OGC_TOTAL_GAMMA > 2)
    _OGC_GAMMA3_ADDRESS,
#if(_OGC_TOTAL_GAMMA > 3)
    _OGC_GAMMA4_ADDRESS,
#if(_OGC_TOTAL_GAMMA > 4)
    _OGC_GAMMA5_ADDRESS,
#endif
#endif
#endif
#endif
#endif

#if(_OCC_SUPPORT == _ON)
    _OCC_GAMMA10_ADDRESS,
#endif

#if(_OGC_DICOM_SUPPORT == _ON)
    _OGC_DICOM_ADDRESS,
#endif

#if((_OGC_SUPPORT == _ON)&&(_RGB_GAMMA_FUNCTION == _ON))
    _OGC_RGBGAMMA1_ADDRESS,
#if(_OGC_TOTAL_GAMMA > 1)
    _OGC_RGBGAMMA2_ADDRESS,
#if(_OGC_TOTAL_GAMMA > 2)
    _OGC_RGBGAMMA3_ADDRESS,
#if(_OGC_TOTAL_GAMMA > 3)
    _OGC_RGBGAMMA4_ADDRESS,
#if(_OGC_TOTAL_GAMMA > 4)
    _OGC_RGBGAMMA5_ADDRESS,
#endif
#endif
#endif
#endif
#endif // end of #if((_OGC_SUPPORT == _ON)&&(_RGB_GAMMA_FUNCTION == _ON))


};

typedef enum
{
#if(_OGC_SUPPORT == _ON)
    _GAMMA1_POSITION,
#if(_OGC_TOTAL_GAMMA > 1)
    _GAMMA2_POSITION,
#if(_OGC_TOTAL_GAMMA > 2)
    _GAMMA3_POSITION,
#if(_OGC_TOTAL_GAMMA > 3)
    _GAMMA4_POSITION,
#if(_OGC_TOTAL_GAMMA > 4)
    _GAMMA5_POSITION,
#endif
#endif
#endif
#endif
#endif

#if(_OCC_SUPPORT == _ON)
    _OCC_POSITION,
#endif

#if(_OGC_DICOM_SUPPORT == _ON)
    _DICOM_POSITION,
#endif

#if((_OGC_SUPPORT == _ON)&&(_RGB_GAMMA_FUNCTION == _ON))
    _RGB_GAMMA1_POSITION,
#if(_OGC_TOTAL_GAMMA > 1)
    _RGB_GAMMA2_POSITION,
#if(_OGC_TOTAL_GAMMA > 2)
    _RGB_GAMMA3_POSITION,
#if(_OGC_TOTAL_GAMMA > 3)
    _RGB_GAMMA4_POSITION,
#if(_OGC_TOTAL_GAMMA > 4)
    _RGB_GAMMA5_POSITION,
#endif
#endif
#endif
#endif
#endif

	_NONE_VALUE,
} EnumOGCTypePos;

BYTE pData[16] = {0};

int g_pusGammaCount[][3] =
{

#if(_OGC_SUPPORT == _ON)
    {2052, 2052, 2052},
#if(_OGC_TOTAL_GAMMA > 1)
    {2052, 2052, 2052},
#if(_OGC_TOTAL_GAMMA > 2)
    {2052, 2052, 2052},
#if(_OGC_TOTAL_GAMMA > 3)
    {2052, 2052, 2052},
#if(_OGC_TOTAL_GAMMA > 4)
    {2052, 2052, 2052},
#endif
#endif
#endif
#endif
#endif  // End of #if(_OGC_SUPPORT == _ON)

#if(_OCC_SUPPORT == _ON)
    {2200, 2200, 2200},
#endif

#if(_OGC_DICOM_SUPPORT == _ON)
    {2052, 2052, 2052},
#endif

#if((_OGC_SUPPORT == _ON)&&(_RGB_GAMMA_FUNCTION == _ON))
    {2052, 2052, 2052},
#if(_OGC_TOTAL_GAMMA > 1)
    {2052, 2052, 2052},
#if(_OGC_TOTAL_GAMMA > 2)
    {2052, 2052, 2052},
#if(_OGC_TOTAL_GAMMA > 3)
    {2052, 2052, 2052},
#if(_OGC_TOTAL_GAMMA > 4)
    {2052, 2052, 2052},
#endif
#endif
#endif
#endif
#endif  // End of #if(_OGC_SUPPORT == _ON)
};

float fMeas[][3] =
{
	74.8336,0.696962,0.296676,
	0.271329,0.244858,0.2484,
	28.6051,0.148219,0.057248,
	226.328,0.210721,0.711443,
	325.826,0.295765,0.307444,
	314.466,0.297952,0.309892,
	296.316,0.297944,0.308727,
	265.466,0.29808,0.30903,
	227.65,0.298172,0.309152,
	184.786,0.298472,0.308967,
	140.047,0.297975,0.30801,
	101.585,0.298861,0.308048,
	69.9116,0.298403,0.306872,
	40.5013,0.298239,0.306104,
	19.1352,0.297929,0.305308,
	7.28451,0.298166,0.306083,
	2.19913,0.291105,0.300479,
	0.873908,0.279102,0.287412,
	0.490087,0.265307,0.271086,
	0.332025,0.252111,0.257307,
};

float fMeasRGB[][3] =
{
	// Red Scale

	46.1563,0.654508,0.326749,
	43.7917,0.653585,0.326548,
	40.2575,0.652298,0.326295,
	34.4572,0.650206,0.325804,
	27.9047,0.647802,0.325284,
	21.4439,0.645004,0.324686,
	16.306,0.642099,0.324204,
	11.8724,0.638684,0.323598,
	7.15633,0.634703,0.320946,
	3.82158,0.621609,0.319925,
	1.69165,0.589639,0.316222,
	0.665008,0.508281,0.304505,
	0.335741,0.387028,0.288028,
	0.25333,0.312146,0.278674,
	0.228498,0.285872,0.273924,
    0, 0, 0,
    0, 0, 0,
    0, 0, 0,
    0, 0, 0,
    0, 0, 0,

	// Green Scale
	139.407,0.298258,0.618827,
	135.047,0.296733,0.617858,
	122.829,0.29369,0.615558,
	106.119,0.290806,0.612961,
	86.0486,0.288237,0.610186,
	66.6202,0.28623,0.607579,
	50.14,0.284752,0.605242,
	35.8226,0.283639,0.602637,
	21.5745,0.282603,0.598364,
	11.3093,0.281359,0.592879,
	4.71291,0.281025,0.57296,
	1.56343,0.279597,0.517282,
	0.560788,0.27858,0.40905,
	0.325322,0.277699,0.330343,
	0.247857,0.277874,0.289272,
    0, 0, 0,
    0, 0, 0,
    0, 0, 0,
    0, 0, 0,
    0, 0, 0,

	// Blue Scale
	14.8023,0.145724,0.0641709,
	13.9191,0.145825,0.0625836,
	12.2075,0.14596,0.0606551,
	10.1726,0.146149,0.0592203,
	8.03195,0.146334,0.058295,
	6.11577,0.146653,0.0579531,
	4.60365,0.146915,0.0580834,
	3.37963,0.147462,0.0586669,
	2.086,0.14885,0.0605243,
	1.13956,0.151801,0.0632446,
	0.5967,0.159535,0.0773182,
	0.328707,0.184528,0.119279,
	0.246972,0.229929,0.19397,
	0.231557,0.254138,0.236088,
	0.2235,0.271112,0.261173,
    0, 0, 0,
    0, 0, 0,
    0, 0, 0,
    0, 0, 0,
    0, 0, 0,

};

float fOCCMeas[][3] =
{
	129.62,0.4156,0.318956,
	223.235,0.366029,0.415197,
	197.236,0.288844,0.421035,
	206.1,0.254872,0.33409,
	161.689,0.284363,0.282179,
	180.005,0.324693,0.283263,
	311.959,0.31283,0.329199,
};

float fFS2Meas[][3] =
{
	311.959,0.31283,0.329199,
};

float fOCCVerify7Pattern[][3] =
{
    59.8064, 0.510925, 0.335079,
    155.066, 0.407226, 0.461065,
    123.998, 0.304457, 0.486352,
    132.551, 0.247151, 0.330873,
    73.7429, 0.260476, 0.235318,
    98.0791, 0.332954, 0.254368,
    313.181, 0.324569, 0.334487,
};

void UserCommonFlashWrite(BYTE ucBank, DWORD usAddr, WORD usLength, BYTE* pucData)
{
    unsigned long end = _DISP_CALIBRATION_TOTAL_END;

    if((ucBank<<16) + usAddr + usLength > _DISP_CALIBRATION_TOTAL_END)
    {
        ShowMessage("Exceed Address Range!");
        return;
    }
    for(unsigned long i = 0 ; i < usLength; i++)
    {
        ucFlash[(ucBank<<16) + usAddr + i] = pucData[i];
    }
}

void UserCommonFlashRead(BYTE ucBank, WORD usAddr, WORD usLength, BYTE* pucData)
{
    memcpy(pucData, ucFlash + (ucBank<<16) + usAddr, usLength);
}

BYTE UserCommonDdcciDispCalibCalCheckSum(BYTE ucCheckType)
{
    WORD usI = 0, usJ = 0;
    BYTE pData[16] = {0};
    pData[0] = 0;
    String str = "";

    switch(ucCheckType)
    {
        case OGC:

            for(usJ = 0; usJ < 3; usJ++)
            {
                for(usI = 0; usI < 2052; usI = usI + 8)
                {
                    UserCommonFlashRead(12, ((((WORD)0) << 12) + _OGC_GAMMA1_ADDRESS+usJ*2052 + usI), 2, pData+2);
                    pData[0] += pData[2];
                    pData[0] += pData[3];
                }
            }


#if(_OGC_TOTAL_GAMMA == 1)
            return pData[0];
#endif

            for(usJ = 0; usJ < 3; usJ++)
            {
                for(usI = 0; usI < 2052; usI = usI + 8)
                {
                    UserCommonFlashRead(12, ((((WORD)0) << 12) + _OGC_GAMMA2_ADDRESS+usJ*2052 + usI), 2, pData+2);
                    pData[0] += pData[2];
                    pData[0] += pData[3];
                }
            }
#if(_OGC_TOTAL_GAMMA == 2)
            return pData[0];
#endif
            for(usJ = 0; usJ < 3; usJ++)
            {
                for(usI = 0; usI < 2052; usI = usI + 8)
                {
                    UserCommonFlashRead(12, ((((WORD)0) << 12) + _OGC_GAMMA3_ADDRESS+usJ*2052 + usI), 2, pData+2);
                    pData[0] += pData[2];
                    pData[0] += pData[3];
                }
            }

#if(_OGC_TOTAL_GAMMA == 3)
            return pData[0];
#endif

            for(usJ = 0; usJ < 3; usJ++)
            {
                for(usI = 0; usI < 2052; usI = usI + 8)
                {
                    UserCommonFlashRead(12, ((((WORD)0) << 12) + _OGC_GAMMA4_ADDRESS+usJ*2052 + usI), 2, pData+2);
                    pData[0] += pData[2];
                    pData[0] += pData[3];
                }
            }
#if(_OGC_TOTAL_GAMMA == 4)
            return pData[0];
#endif

            for(usJ = 0; usJ < 3; usJ++)
            {
                for(usI = 0; usI < 2052; usI = usI + 8)
                {
                    UserCommonFlashRead(12, ((((WORD)0) << 12) + _OGC_GAMMA5_ADDRESS+usJ*2052 + usI), 2, pData+2);
                    pData[0] += pData[2];
                    pData[0] += pData[3];
                }
            }

#if(_OGC_TOTAL_GAMMA == 5)
            return pData[0];
#endif
            break;

        case OCC:

            for(usJ = 0; usJ < 3; usJ++)
            {
                for(usI = 0; usI < 148; usI++)
                {
                    UserCommonFlashRead(12, ((((WORD)0) << 12) + _OCC_GAMMA10_ADDRESS+usJ*2200 + usI), 1, pData+2);
                    pData[0] += pData[2];
                }

                for(usI = 164; usI < 2200; usI = usI + 8)
                {
                    UserCommonFlashRead(12, ((((WORD)0) << 12) + _OCC_GAMMA10_ADDRESS+usJ*2200 + usI), 2, pData+2);
                    pData[0] += pData[2];
                    pData[0] += pData[3];
                }
            }

            break;

        case _DICOM_TYPE:

            for(usJ = 0; usJ < 3; usJ++)
            {
                for(usI = 0; usI < 2052; usI = usI + 8)
                {
                    UserCommonFlashRead(_OGC_FLASH_BANK, ((((WORD)_OGC_FLASH_PAGE) << 12) + _OGC_DICOM_ADDRESS+usJ*2052 + usI), 2, pData+2);
                    pData[0] += pData[2];
                    pData[0] += pData[3];
                }
            }

            break;

        case _RGB_GAIN_TYPE:

            for(usI = _OGC_RGB_GAIN_ADDRESS; usI < (_OGC_RGB_GAIN_ADDRESS + _OGC_RGB_GAIN_ACTUAL_SIZE); usI++)
            {
                UserCommonFlashRead(_OGC_FLASH_BANK, ((((WORD)_OGC_FLASH_PAGE) << 12) + usI), 1, pData+2);

                pData[0] += pData[2];
            }

            break;

        case _COLOR_MATRIX_TYPE:

            for(usI = _OCC_SRGBMATRIX_ADDRESS; usI < (_OCC_SRGBMATRIX_ADDRESS + _OCC_COLORMATRIX_TABLE_SIZE * 2); usI++)
            {
                UserCommonFlashRead(_OGC_FLASH_BANK, ((((WORD)_OGC_FLASH_PAGE) << 12) + usI), 1, pData+2);
                pData[0] += pData[2];
            }

            break;

         default:

            break;
    }
    return pData[0];
}

void PrintLUTRange(void)
{
    ofstream fout("Output/LUTRange.txt");
    fout<<"_OGC_GAMMA1_ADDRESS:\t"<<(hex)<<(int)_OGC_GAMMA1_ADDRESS<<" - "<<(hex)<<(int)(_OGC_GAMMA1_ADDRESS+2052)<<" - "<<(hex)<<(int)(_OGC_GAMMA1_ADDRESS+2052*2)<<" - "<<(hex)<<(int)(_OGC_GAMMA1_ADDRESS+2052*3)<<endl;
    fout<<"_OGC_GAMMA2_ADDRESS:\t"<<(hex)<<(int)_OGC_GAMMA2_ADDRESS<<" - "<<(hex)<<(int)(_OGC_GAMMA2_ADDRESS+2052)<<" - "<<(hex)<<(int)(_OGC_GAMMA2_ADDRESS+2052*2)<<" - "<<(hex)<<(int)(_OGC_GAMMA2_ADDRESS+2052*3)<<endl;
    fout<<"_OGC_GAMMA3_ADDRESS:\t"<<(hex)<<(int)_OGC_GAMMA3_ADDRESS<<" - "<<(hex)<<(int)(_OGC_GAMMA3_ADDRESS+2052)<<" - "<<(hex)<<(int)(_OGC_GAMMA3_ADDRESS+2052*2)<<" - "<<(hex)<<(int)(_OGC_GAMMA3_ADDRESS+2052*3)<<endl;
    fout<<"_OGC_GAMMA4_ADDRESS:\t"<<(hex)<<(int)_OGC_GAMMA4_ADDRESS<<" - "<<(hex)<<(int)(_OGC_GAMMA4_ADDRESS+2052)<<" - "<<(hex)<<(int)(_OGC_GAMMA4_ADDRESS+2052*2)<<" - "<<(hex)<<(int)(_OGC_GAMMA4_ADDRESS+2052*3)<<endl;
    fout<<"_OGC_GAMMA5_ADDRESS:\t"<<(hex)<<(int)_OGC_GAMMA5_ADDRESS<<" - "<<(hex)<<(int)(_OGC_GAMMA5_ADDRESS+2052)<<" - "<<(hex)<<(int)(_OGC_GAMMA5_ADDRESS+2052*2)<<" - "<<(hex)<<(int)(_OGC_GAMMA5_ADDRESS+2052*3)<<endl;
    fout<<"_OCC_GAMMA10_ADDRESS:\t"<<(hex)<<(int)_OCC_GAMMA10_ADDRESS<<endl;
    fout<<"_OCC_SRGBMATRIX_ADDRESS:\t"<<(hex)<<(int)_OCC_SRGBMATRIX_ADDRESS<<endl;
    fout<<"_OGC_DICOM_ADDRESS:\t"<<(hex)<<(int)_OGC_DICOM_ADDRESS<<endl;

    fout<<"_OGC_RGBGAMMA1_ADDRESS:\t"<<(hex)<<(int)_OGC_RGBGAMMA1_ADDRESS<<" - "<<(hex)<<(int)(_OGC_RGBGAMMA1_ADDRESS+2052)<<" - "<<(hex)<<(int)(_OGC_RGBGAMMA1_ADDRESS+2052*2)<<" - "<<(hex)<<(int)(_OGC_RGBGAMMA1_ADDRESS+2052*3)<<endl;
    fout<<"_OGC_RGBGAMMA2_ADDRESS:\t"<<(hex)<<(int)_OGC_RGBGAMMA2_ADDRESS<<" - "<<(hex)<<(int)(_OGC_RGBGAMMA2_ADDRESS+2052)<<" - "<<(hex)<<(int)(_OGC_RGBGAMMA2_ADDRESS+2052*2)<<" - "<<(hex)<<(int)(_OGC_RGBGAMMA2_ADDRESS+2052*3)<<endl;
    fout<<"_OGC_RGBGAMMA3_ADDRESS:\t"<<(hex)<<(int)_OGC_RGBGAMMA3_ADDRESS<<" - "<<(hex)<<(int)(_OGC_RGBGAMMA3_ADDRESS+2052)<<" - "<<(hex)<<(int)(_OGC_RGBGAMMA3_ADDRESS+2052*2)<<" - "<<(hex)<<(int)(_OGC_RGBGAMMA3_ADDRESS+2052*3)<<endl;
    fout<<"_OGC_RGBGAMMA4_ADDRESS:\t"<<(hex)<<(int)_OGC_RGBGAMMA4_ADDRESS<<" - "<<(hex)<<(int)(_OGC_RGBGAMMA4_ADDRESS+2052)<<" - "<<(hex)<<(int)(_OGC_RGBGAMMA4_ADDRESS+2052*2)<<" - "<<(hex)<<(int)(_OGC_RGBGAMMA4_ADDRESS+2052*3)<<endl;
    fout<<"_OGC_RGBGAMMA5_ADDRESS:\t"<<(hex)<<(int)_OGC_RGBGAMMA5_ADDRESS<<" - "<<(hex)<<(int)(_OGC_RGBGAMMA5_ADDRESS+2052)<<" - "<<(hex)<<(int)(_OGC_RGBGAMMA5_ADDRESS+2052*2)<<" - "<<(hex)<<(int)(_OGC_RGBGAMMA5_ADDRESS+2052*3)<<endl;
    fout<<"_DISP_CALIBRATION_TOTAL_END:\t"<<(hex)<<(int)_DISP_CALIBRATION_TOTAL_END<<endl;

    fout.close();
}

void UserCommonDdcciDispCalibReadFlash(DWORD dwAddr, WORD usLength, BYTE *pucData)
{   /*
    if((dwAddr < 0x10000)&&(dwAddr + usLength >= 0x10000))
    {
        UserCommonFlashRead(_OGC_FLASH_BANK, dwAddr, 0x10000 - dwAddr, pucData);
        UserCommonFlashRead(_OGC_FLASH_BANK + 1, 0, usLength - (0x10000 - dwAddr), pucData + 0x10000 - dwAddr);
    }
    else */
    {
        UserCommonFlashRead(_OGC_FLASH_BANK + (dwAddr >> 16) , dwAddr & 0xFFFF, usLength, pucData);
    }
}

void UserCommonDdcciDispCalibWriteFlash(DWORD dwAddr, WORD usLength, BYTE *pucData)
{   /*
    if((dwAddr < 0x10000)&&(dwAddr + usLength >= 0x10000))
    {
        UserCommonFlashWrite(_OGC_FLASH_BANK, dwAddr, 0x10000 - dwAddr, pucData);
        UserCommonFlashWrite(_OGC_FLASH_BANK + 1, 0, usLength + dwAddr - 0x10000, pucData + 0x10000 - dwAddr);
    }
    else */
    {
        //UserCommonFlashWrite(_OGC_FLASH_BANK + (dwAddr >> 16) , dwAddr & 0xFFFF, usLength, pucData);
        if(dwAddr >= 0x10000)
        {
            UserCommonFlashWrite(_OGC_FLASH_BANK + 1 , dwAddr & 0xFFFF, usLength, pucData);
        }
        else
        {
            UserCommonFlashWrite(_OGC_FLASH_BANK  , dwAddr & 0xFFFF, usLength, pucData);
        }
    }
}


/*
void UserCommonDdcciDispCalibSaveLUT(BYTE ucTotalLength)
{
    BYTE ucLUTLength = 0;
    BYTE ucPointer = 5;
    BYTE ucGammaIndex = 0;
    BYTE ucRGB = 0;
    WORD usStartAddr = _OGC_GAMMA1_ADDRESS;
    WORD usLastLUT = 0;
    WORD usCurrLUT = 0;
    BYTE ucIntoLUT[128] = {0};
    BYTE j = 0;
    WORD usInto = 0;
    bool bIsLastLUT = _FALSE;
    BYTE ucTempLen = 0;
    int nRemain = 0;
    int cnt = 0;
    //int nNum = 0;
    BYTE ucCurPointer = 0;
    int nWriteCnt = 0;
    bool bWriteDirectly = _FALSE;

    // ucTotalLength - 1: exclude checksum
    while(ucPointer < (ucTotalLength - 1))
    {
        // LUT Length (exclude ID and Length Bytes)
        ucLUTLength = g_ucDdcciRxBuf[ucPointer] - 2;

        ucGammaIndex = (g_ucDdcciRxBuf[ucPointer + 1] >> 4) & 0x0F;
        ucRGB = g_ucDdcciRxBuf[ucPointer + 1] & 0x0F;
        ucPointer += 2;


#if(_OCC_SUPPORT == _ON)
        if(ucGammaIndex == _OCC_POSITION)
        {
            usStartAddr = tGAMMA_INDEX[_OCC_POSITION] + (ucRGB) * 2200;
        }
        else
#endif
        {
            usStartAddr = tGAMMA_INDEX[ucGammaIndex] + (ucRGB) * 2052;
        }

        bIsLastLUT = _FALSE;
#if(_OCC_SUPPORT == _ON)
        if((ucGammaIndex == _OCC_POSITION) && (g_pusGammaCount[ucGammaIndex][ucRGB] == 2200))
        {
            bIsLastLUT = _TRUE;
        }
        else if((ucGammaIndex != _OCC_POSITION) && (g_pusGammaCount[ucGammaIndex][ucRGB] == 2052))
        {
            bIsLastLUT = _TRUE;
        }
#else
        if(g_pusGammaCount[ucGammaIndex][ucRGB] == 2052)
        {
            bIsLastLUT = _TRUE;
        }
#endif

        if(bIsLastLUT)
        {
            nRemain = (ucLUTLength - 2)*4 + 4;
        }
        else
        {
#if(_OCC_SUPPORT == _ON)
            if((ucGammaIndex == _OCC_POSITION)&& (g_pusGammaCount[ucGammaIndex][ucRGB] <=164))
            {
                nRemain = ucLUTLength;
            }
            else
#endif
            {
                nRemain = ucLUTLength*4;
            }
        }

        ucCurPointer = ucPointer + ucLUTLength - 1;

        while(nRemain > 0)
        {
            if(nRemain > 128)
            {
                cnt = (bIsLastLUT == _TRUE) ? 124 : 128;
                nRemain -= cnt;
            }
            else
            {
                cnt = nRemain;
                nRemain = 0;
            }

            nWriteCnt = cnt;
            cnt--;
            while(cnt > 0)
            {
                usCurrLUT = (g_ucDdcciRxBuf[ucCurPointer - 1] << 8) | g_ucDdcciRxBuf[ucCurPointer];

                if(ucCurPointer == ucPointer + ucLUTLength - 1)
                {
                    if(bIsLastLUT == _TRUE)
                    {
                        ucIntoLUT[cnt--] = 0;
                        ucIntoLUT[cnt--] = 0;

                        // Save 1024
                        ucIntoLUT[cnt--] = usCurrLUT & 0xFF;
                        ucIntoLUT[cnt--] = usCurrLUT >> 8;
                        ucCurPointer -= 2;
                        continue;
                    }
                    else
                    {
                        UserCommonDdcciDispCalibReadFlash(((WORD)_OGC_FLASH_PAGE << 12) + usStartAddr + g_pusGammaCount[ucGammaIndex][ucRGB], 2, pData);
                        usLastLUT = (pData[0] << 8) | pData[1];
                    }
                }
                else
                {
                    usLastLUT = (g_ucDdcciRxBuf[ucCurPointer + 1] << 8) | g_ucDdcciRxBuf[ucCurPointer + 2];
                }

                if(bIsLastLUT)
                {
                    // Last interpolation: 1020, 1021, 1022; 1023 = 1024
                    ucIntoLUT[cnt--] = usLastLUT & 0xFF;
                    ucIntoLUT[cnt--] = (usLastLUT >> 8) & 0x3F;

                    for(j = 1; j < 4; j++)
                    {
                        usInto = usLastLUT - (float)(usLastLUT - usCurrLUT) * j / 3 + 0.5;
                        ucIntoLUT[cnt--] = usInto & 0xFF;
                        ucIntoLUT[cnt--] = (usInto >> 8);
                    }

                    bIsLastLUT = _FALSE;
                }
                else
                {
#if(_OCC_SUPPORT == _ON)
                    if(ucGammaIndex == _OCC_POSITION)
                    {
                        if(g_pusGammaCount[ucGammaIndex][ucRGB] - (nWriteCnt - cnt - 1) <= 164) // Latch: No Intopolation
                        {
                            bWriteDirectly = _TRUE;

                            if((nWriteCnt - cnt - 1) != 0)
                            {
                                UserCommonDdcciDispCalibWriteFlash(((WORD)_OGC_FLASH_PAGE << 12) + (usStartAddr + g_pusGammaCount[ucGammaIndex][ucRGB] - (nWriteCnt - cnt - 1)), nWriteCnt - cnt - 1, ucIntoLUT + cnt + 1);
                                g_pusGammaCount[ucGammaIndex][ucRGB] -= nWriteCnt - cnt - 1;
                                if(g_pusGammaCount[ucGammaIndex][ucRGB]  < 0)
                                {
                                    ShowMessage("1!!");
                                }
                            }
                            break;
                        }
                        else
                        {
                            for(j = 1; j <= 4; j++)
                            {
                                usInto = usLastLUT - ((usLastLUT - usCurrLUT)*j + 2)/4;
                                ucIntoLUT[cnt--] = usInto & 0xFF;
                                ucIntoLUT[cnt--] = (usInto>>8)& 0x3F;
                            }
                        }
                    }
                    else
#endif
                    {
                        for(j = 1; j <= 4; j++)
                        {
                            usInto = usLastLUT - ((usLastLUT - usCurrLUT)*j + 2)/4;
                            ucIntoLUT[cnt--] = usInto & 0xFF;
                            ucIntoLUT[cnt--] = usInto>>8;
                        }
                    }
                }
                ucCurPointer -= 2;
            }

#if(_OCC_SUPPORT == _ON)
            if(bWriteDirectly == _TRUE)
            {
                if(g_pusGammaCount[ucGammaIndex][ucRGB] <= 148) // Latch: No Intopolation
                {
                    ucTempLen = ucCurPointer - ucPointer + 1;
                    UserCommonDdcciDispCalibWriteFlash(((WORD)_OGC_FLASH_PAGE << 12) + (usStartAddr + g_pusGammaCount[ucGammaIndex][ucRGB] - ucTempLen), ucTempLen, &g_ucDdcciRxBuf[ucPointer]);
                    g_pusGammaCount[ucGammaIndex][ucRGB] = g_pusGammaCount[ucGammaIndex][ucRGB] - ucTempLen;
                    if(g_pusGammaCount[ucGammaIndex][ucRGB]  < 0)
                    {
                        ShowMessage("2!!");
                    }
                    bWriteDirectly = _FALSE;
                    break;
                }
                else if(g_pusGammaCount[ucGammaIndex][ucRGB] <= 164) // add 16 0s
                {
                    memset(pData, 0, 16);
                    UserCommonDdcciDispCalibWriteFlash(((WORD)_OGC_FLASH_PAGE << 12) + (usStartAddr + g_pusGammaCount[ucGammaIndex][ucRGB] - 16), 16, pData);
                    g_pusGammaCount[ucGammaIndex][ucRGB] = 148;

                    ucTempLen = ucCurPointer - ucPointer + 1;
                    UserCommonDdcciDispCalibWriteFlash(((WORD)_OGC_FLASH_PAGE << 12) + (usStartAddr + g_pusGammaCount[ucGammaIndex][ucRGB] - ucTempLen), ucTempLen, &g_ucDdcciRxBuf[ucPointer]);
                    g_pusGammaCount[ucGammaIndex][ucRGB] = g_pusGammaCount[ucGammaIndex][ucRGB] - ucTempLen;
                    if(g_pusGammaCount[ucGammaIndex][ucRGB]  < 0)
                    {
                        ShowMessage("3!!");
                    }
                    bWriteDirectly = _FALSE;
                    break;
                }
                bWriteDirectly = _FALSE;
            }
            else
#endif
            {
                UserCommonDdcciDispCalibWriteFlash(((WORD)_OGC_FLASH_PAGE << 12) + (usStartAddr + g_pusGammaCount[ucGammaIndex][ucRGB] - nWriteCnt), nWriteCnt, ucIntoLUT);
                g_pusGammaCount[ucGammaIndex][ucRGB] -= nWriteCnt;
                if(g_pusGammaCount[ucGammaIndex][ucRGB]  < 0)
                {
                    ShowMessage("4!!");
                }
            }
        }
        ucPointer += ucLUTLength;
    }
} */
void UserCommonDdcciDispCalibSaveLUT(BYTE ucTotalLength)
{
    BYTE ucLUTLength = 0;
    BYTE ucPointer = 5;
    BYTE ucGammaIndex = 0;
    BYTE ucRGB = 0;
    DWORD ulStartAddr = _OGC_GAMMA1_ADDRESS;
    WORD usLastLUT = 0;
    WORD usCurrLUT = 0;
    BYTE pucIntoLUT[128] = {0};
    BYTE ucJ = 0;
    WORD usInto = 0;
    bool bIsLastLUT = _FALSE;
    BYTE ucTempLen = 0;
    int shRemain = 0;
    int shCnt = 0;
    // int nNum = 0;
    BYTE ucCurPointer = 0;
    int shWriteCnt = 0;
    bool bWriteDirectly = _FALSE;

    // ucTotalLength - 1: exclude checksum
    while(ucPointer < (ucTotalLength - 1))
    {
        // LUT Length (exclude ID and Length Bytes)
        ucLUTLength = g_pucDdcciRxBuf[ucPointer] - 2;

        ucGammaIndex = (g_pucDdcciRxBuf[ucPointer + 1] >> 4) & 0x0F;
        ucRGB = g_pucDdcciRxBuf[ucPointer + 1] & 0x0F;
        ucPointer += 2;


#if(_OCC_SUPPORT == _ON)
        if(ucGammaIndex == _OCC_POSITION)
        {
            ulStartAddr = tGAMMA_INDEX[_OCC_POSITION] + (ucRGB) * 2200;
        }
        else
#endif
        {
            ulStartAddr = tGAMMA_INDEX[ucGammaIndex] + (ucRGB) * 2052;
        }

        bIsLastLUT = _FALSE;
#if(_OCC_SUPPORT == _ON)
        if((ucGammaIndex == _OCC_POSITION) && (g_pusGammaCount[ucGammaIndex][ucRGB] == 2200))
        {
            bIsLastLUT = _TRUE;
        }
        else if((ucGammaIndex != _OCC_POSITION) && (g_pusGammaCount[ucGammaIndex][ucRGB] == 2052))
        {
            bIsLastLUT = _TRUE;
        }
#else
        if(g_pusGammaCount[ucGammaIndex][ucRGB] == 2052)
        {
            bIsLastLUT = _TRUE;
        }
#endif
        if(bIsLastLUT)
        {
            shRemain = (ucLUTLength - 2) * 4 + 4;
        }
        else
        {
#if(_OCC_SUPPORT == _ON)
            if((ucGammaIndex == _OCC_POSITION) && (g_pusGammaCount[ucGammaIndex][ucRGB] <= 164))
            {
                shRemain = ucLUTLength;
            }
            else
#endif
            {
                shRemain = ucLUTLength * 4;
            }
        }

        ucCurPointer = ucPointer + ucLUTLength - 1;

        while(shRemain > 0)
        {
            if(shRemain > 128)
            {
                shCnt = (bIsLastLUT == _TRUE) ? 124 : 128;
                shRemain -= shCnt;
            }
            else
            {
                shCnt = shRemain;
                shRemain = 0;
            }
            shWriteCnt = shCnt;
            shCnt--;
            while(shCnt > 0)
            {
                usCurrLUT = (g_pucDdcciRxBuf[ucCurPointer - 1] << 8) | g_pucDdcciRxBuf[ucCurPointer];

                if(ucCurPointer == ucPointer + ucLUTLength - 1)
                {
                    if(bIsLastLUT == _TRUE)
                    {
                        pucIntoLUT[shCnt--] = 0;
                        pucIntoLUT[shCnt--] = 0;

                        // Save 1024
                        pucIntoLUT[shCnt--] = usCurrLUT & 0xFF;
                        pucIntoLUT[shCnt--] = usCurrLUT >> 8;
                        ucCurPointer -= 2;
                        continue;
                    }
                    else
                    {
                        UserCommonDdcciDispCalibReadFlash(((DWORD)_OGC_FLASH_PAGE << 12) + ulStartAddr + g_pusGammaCount[ucGammaIndex][ucRGB], 2, pData);
                        usLastLUT = (pData[0] << 8) | pData[1];
                    }
                }
                else
                {
                    usLastLUT = (g_pucDdcciRxBuf[ucCurPointer + 1] << 8) | g_pucDdcciRxBuf[ucCurPointer + 2];
                }

                if(bIsLastLUT)
                {
                    // Last interpolation: 1020, 1021, 1022; 1023 = 1024
                    pucIntoLUT[shCnt--] = usLastLUT & 0xFF;
                    pucIntoLUT[shCnt--] = (usLastLUT >> 8) & 0x3F;

                    for(ucJ = 1; ucJ < 4; ucJ++)
                    {
                        usInto = usLastLUT - (2 * (DWORD)(usLastLUT - usCurrLUT) * ucJ + 3) / 6;
                        pucIntoLUT[shCnt--] = usInto & 0xFF;
                        pucIntoLUT[shCnt--] = (usInto >> 8);
                    }

                    bIsLastLUT = _FALSE;
                }
                else
                {
#if(_OCC_SUPPORT == _ON)
                    if(ucGammaIndex == _OCC_POSITION)
                    {
                        if(g_pusGammaCount[ucGammaIndex][ucRGB] - (shWriteCnt - shCnt - 1) <= 164) // Latch: No Intopolation
                        {
                            bWriteDirectly = _TRUE;

                            if((shWriteCnt - shCnt - 1) != 0)
                            {
                                UserCommonDdcciDispCalibWriteFlash(((DWORD)_OGC_FLASH_PAGE << 12) + (ulStartAddr + g_pusGammaCount[ucGammaIndex][ucRGB] - (shWriteCnt - shCnt - 1)), shWriteCnt - shCnt - 1, pucIntoLUT + shCnt + 1);
                                g_pusGammaCount[ucGammaIndex][ucRGB] -= shWriteCnt - shCnt - 1;
                                if(g_pusGammaCount[ucGammaIndex][ucRGB]  < 0)
                                {
                                    ShowMessage("1!!");
                                }
                            }
                            break;
                        }
                        else
                        {
                            for(ucJ = 1; ucJ <= 4; ucJ++)
                            {
                                usInto = usLastLUT - ((usLastLUT - usCurrLUT) * ucJ + 2) / 4;
                                pucIntoLUT[shCnt--] = usInto & 0xFF;
                                pucIntoLUT[shCnt--] = (usInto >> 8) & 0x3F;
                            }
                        }
                    }
                    else
#endif
                    {
                        for(ucJ = 1; ucJ <= 4; ucJ++)
                        {
                            usInto = usLastLUT - ((usLastLUT - usCurrLUT) * ucJ + 2) / 4;
                            pucIntoLUT[shCnt--] = usInto & 0xFF;
                            pucIntoLUT[shCnt--] = usInto >> 8;
                        }
                    }
                }
                ucCurPointer -= 2;
            }

#if(_OCC_SUPPORT == _ON)
            if(bWriteDirectly == _TRUE)
            {
                if(g_pusGammaCount[ucGammaIndex][ucRGB] <= 148) // Latch: No Intopolation
                {
                    ucTempLen = ucCurPointer - ucPointer + 1;
                    UserCommonDdcciDispCalibWriteFlash(((DWORD)_OGC_FLASH_PAGE << 12) + (ulStartAddr + g_pusGammaCount[ucGammaIndex][ucRGB] - ucTempLen), ucTempLen, &g_pucDdcciRxBuf[ucPointer]);
                    g_pusGammaCount[ucGammaIndex][ucRGB] = g_pusGammaCount[ucGammaIndex][ucRGB] - ucTempLen;
                    if(g_pusGammaCount[ucGammaIndex][ucRGB]  < 0)
                    {
                        ShowMessage("2!!");
                    }
                    bWriteDirectly = _FALSE;
                    break;
                }
                else if(g_pusGammaCount[ucGammaIndex][ucRGB] <= 164) // add 16 0s
                {
                    memset(pData, 0, 16);
                    UserCommonDdcciDispCalibWriteFlash(((DWORD)_OGC_FLASH_PAGE << 12) + (ulStartAddr + g_pusGammaCount[ucGammaIndex][ucRGB] - 16), 16, pData);
                    g_pusGammaCount[ucGammaIndex][ucRGB] = 148;

                    ucTempLen = ucCurPointer - ucPointer + 1;
                    UserCommonDdcciDispCalibWriteFlash(((DWORD)_OGC_FLASH_PAGE << 12) + (ulStartAddr + g_pusGammaCount[ucGammaIndex][ucRGB] - ucTempLen), ucTempLen, &g_pucDdcciRxBuf[ucPointer]);
                    g_pusGammaCount[ucGammaIndex][ucRGB] = g_pusGammaCount[ucGammaIndex][ucRGB] - ucTempLen;
                    if(g_pusGammaCount[ucGammaIndex][ucRGB]  < 0)
                    {
                        ShowMessage("3!!");
                    }
                    bWriteDirectly = _FALSE;
                    break;
                }
                bWriteDirectly = _FALSE;
            }
            else
#endif
            {
                UserCommonDdcciDispCalibWriteFlash(((DWORD)_OGC_FLASH_PAGE << 12) + (ulStartAddr + (DWORD)g_pusGammaCount[ucGammaIndex][ucRGB] - shWriteCnt), shWriteCnt, pucIntoLUT);
                g_pusGammaCount[ucGammaIndex][ucRGB] -= shWriteCnt;

                if(g_pusGammaCount[ucGammaIndex][ucRGB]  < 0)
                {
                    ShowMessage("4!!");
                }
            }
        }
        ucPointer += ucLUTLength;
    }
}

BYTE GetCheckSum()
{
    WORD usJ, usI;
    pData[0] = 0;
    for(usJ = 0; usJ < 3; usJ++)
    {
        for(usI = 0; usI < 2052; usI = usI + 8)
        {
            UserCommonFlashRead(12, ((((WORD)0) << 12) + _OGC_GAMMA1_ADDRESS+usJ*2052 + usI), 2, pData+1);
            pData[0] += pData[1];
            pData[0] += pData[2];
        }
    }
    return pData[0];

}


void PrintFlash()
{
    ofstream fout("Output/Flash.txt");
    ofstream fout1("Output/Flash.bin", ios::binary);
    ofstream fout0("Output/FlashBank16.bin", ios::binary);
    ofstream fout2("Output/FlashBank17.bin", ios::binary);
    fout<<"Index\t00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F"<<endl;
    fout<<"======================================================="<<endl;

    for(int i = 0; i < _DISP_CALIBRATION_TOTAL_END; i++)
    {
        if((i%16) == 0)
        {
            fout<<"0x"<<IntToHex(i, 4).c_str()<<":\t";
        }

        fout<<IntToHex(ucFlash[i],2).c_str()<<" ";


        if((i+1)%16 == 0)
        {
            fout<<endl;
        }
    }
    fout1.write(ucFlash, sizeof(ucFlash));
    fout0.write(ucFlash, 0x10000);
    fout2.write(ucFlash + 0x10000, _DISP_CALIBRATION_TOTAL_END - 0x10000);
    fout.close();
    fout1.close();
    fout2.close();
}

