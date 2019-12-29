//////////////////////////////////////////////////////////////////////////////
// * SJTU DSP Tech. Center
// *                                                                          
// * Description: TMS320C5535 Program Demo for Students Experiment
// *                                                                          
// * Copyright (C) 2013 SJTU DSP Tech. Center. All Rights Reserved.
// * Copyright (C) Shanghai Jiao Tong University
// *                                                                          
// * History:
// * 	Date		Authors			Changes
// *	2013/12		Zhe Sheng		Created.
// *                                                                          
// *                                                                          
//////////////////////////////////////////////////////////////////////////////

#include "stdio.h"
#include "ezdsp5535.h"
#include "ezdsp5535_i2s.h"
#include "csl_i2s.h"

extern Int16 AIC3204_rset( Uint16 regnum, Uint16 regval);

/*
 *  AIC3204 Loop
 * 
 *      Loops audio from LINE IN to LINE OUT
 */
Int16 aic3204_loop_linein( )
{
    Int16 sec, msec;
    Int16 sample, data1, data2;
     
    
    /* Initialize I2S */
    EZDSP5535_I2S_init();
     
    /* Play Loop for 5 seconds */
    for ( sec = 0 ; sec < 5 ; sec++ )
    {
        for ( msec = 0 ; msec < 10000 ; msec++ )
        {
            for ( sample = 0 ; sample < 48 ; sample++ )
            {
                /* Read 16-bit left channel Data */
                EZDSP5535_I2S_readLeft(&data1);
                
                /* Read 16-bit right channel Data */
                EZDSP5535_I2S_readRight(&data2);
                
                /* Write 16-bit left channel Data */
                EZDSP5535_I2S_writeLeft(data1);
                
                /* Write 16-bit right channel Data */
                EZDSP5535_I2S_writeRight(data2);
            }
        }
    }
    EZDSP5535_I2S_close();    // Disble I2S
    AIC3204_rset( 1, 0x01 );  // Reset codec
    
    return 0;
}
