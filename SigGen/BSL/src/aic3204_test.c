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

#define AIC3204_I2C_ADDR 0x18

#include "ezdsp5535.h"
#include "ezdsp5535_gpio.h"
#include "ezdsp5535_i2c.h"
#include "stdio.h"

extern Int16 aic3204_tone_headphone( );
extern Int16 aic3204_loop_linein( );

/*
 *
 *  AIC3204_rget( regnum, *regval )
 *
 *      Return value of codec register regnum
 *
 */
Int16 AIC3204_rget(  Uint16 regnum, Uint16* regval )
{
    Int16  retcode = 0;
    Uint16 cmd[2];

    cmd[0] = regnum & 0x007F;       // 7-bit Device Register
    cmd[1] = 0;

    retcode |= EZDSP5535_I2C_write( AIC3204_I2C_ADDR, cmd, 1 );
    retcode |= EZDSP5535_I2C_read( AIC3204_I2C_ADDR, cmd, 1 );

    *regval = cmd[0];
    EZDSP5535_wait( 10 );
    return retcode;
}

/*
 *
 *  AIC3204_rset( regnum, regval )
 *
 *      Set codec register regnum to value regval
 *
 */
Int16 AIC3204_rset( Uint16 regnum, Uint16 regval )
{
    Uint16 cmd[2];
    cmd[0] = regnum & 0x007F;       // 7-bit Device Register
    cmd[1] = regval;                // 8-bit Register Data

    EZDSP5535_waitusec( 300 );

    return EZDSP5535_I2C_write( AIC3204_I2C_ADDR, cmd, 2 );
}

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  AIC3204 Initialisation of both sampling frequency and gain in dB.       *
 *      Initialise the registers                        *
 *                                                                          *
 * ------------------------------------------------------------------------ */
unsigned long AIC3204_init(Uint32 SamplingFrequency, Uint32 ADCgain)
{
    unsigned int PLLPR = 0x91; // Default to 48000 Hz
    unsigned int gain;
    unsigned long output;

    if ( ADCgain >= 48)
     {
      gain = 95;      //  Limit gain to 47.5 dB
      ADCgain = 48;   // For display using printf()
     }
    else
    {
     gain = (ADCgain << 1); // Convert 1dB steps to 0.5dB steps
    }

    switch (SamplingFrequency)
    {
     case 48000:
     	PLLPR = 0x91; // 1001 0001b. PLL on. P = 1, R = 1.
     	printf("Sampling frequency 48000 Hz Gain = %2d dB\n", (int)ADCgain);
     	output = 48000;
     break;

     case 24000:
      	PLLPR = 0xA1; // 1010 0001b. PLL on. P = 2, R = 1.
      	printf("Sampling frequency 24000 Hz Gain = %2d dB\n", (int)ADCgain);
      	output = 24000;
     break;

     case 16000:
     	PLLPR = 0xB1; // 1011 0001b. PLL on. P = 3, R = 1.
      	printf("Sampling frequency 16000 Hz Gain = %2d dB\n", (int)ADCgain);
      	output = 16000;
     break;

     case 12000:
        PLLPR = 0xC1; //1100 0001b. PLL on. P = 4, R = 1.
        printf("Sampling frequency 12000 Hz Gain = %2d dB\n", (int)ADCgain);
        output = 12000;
     break;

     case 9600:
     	PLLPR = 0xD1; //1101 0001b. PLL on. P = 5, R = 1.
       	printf("Sampling frequency 9600 Hz Gain = %2d dB\n", (int)ADCgain);
       	output = 9600;
     break;

     case 8000:
     	PLLPR = 0xE1; //1110 0001b. PLL on. P = 6, R = 1.
     	printf("Sampling frequency 8000 Hz Gain = %2d dB\n", (int)ADCgain);
     	output = 8000;
     break;

     case 6857:
     	PLLPR = 0xF1; //1111 0001b. PLL on. P = 7, R = 1.
     	printf("Sampling frequency 6857 Hz Gain = %2d dB\n", (int)ADCgain);
     	output = 6857;
     break;

     default:
     	PLLPR = 0x91; // 1001 0001b. PLL on. P = 1, R = 1.
     	printf("Sampling frequency not recognised. Default to 48000 Hz Gain = %2d dB\n", (int)ADCgain);
     	output = 48000;
     break;
    }

    /* Configure AIC3204 */

    AIC3204_rset( 0,  0x00 );  // Select page 0
	AIC3204_rset( 1,  0x01 );  // Reset codec
	EZDSP5535_waitusec(1000);  // Wait 1ms after reset
	AIC3204_rset( 0,  0x01 );  // Select page 1
	AIC3204_rset( 1,  0x08 );  // Disable crude AVDD generation from DVDD
	AIC3204_rset( 2,  0x01 );  // Enable Analog Blocks, use LDO power
	AIC3204_rset( 123,0x05 );  // Force reference to power up in 40ms
	EZDSP5535_waitusec(50000); // Wait at least 40ms
	AIC3204_rset( 0,  0x00 );  // Select page 0

	/* PLL and Clocks config and Power Up  */
	AIC3204_rset( 27, 0x0d );  // BCLK and WCLK are set as o/p; AIC3204(Master)
	AIC3204_rset( 28, 0x00 );  // Data ofset = 0
	AIC3204_rset( 4,  0x03 );  // PLL setting: PLLCLK <- MCLK, CODEC_CLKIN <-PLL CLK
	AIC3204_rset( 6,  0x07 );  // PLL setting: J=7
	AIC3204_rset( 7,  0x06 );  // PLL setting: HI_BYTE(D=1680)
	AIC3204_rset( 8,  0x90 );  // PLL setting: LO_BYTE(D=1680)
	AIC3204_rset( 30, 0x88 );  // For 32 bit clocks per frame in Master mode ONLY
							   // BCLK=DAC_CLK/N =(12288000/8) = 1.536MHz = 32*fs
	AIC3204_rset( 5,  PLLPR );  // PLL setting: Power up PLL, P=1 and R=1
	EZDSP5535_waitusec(10000); // Wait for PLL to come up
	AIC3204_rset( 13, 0x00 );  // Hi_Byte(DOSR) for DOSR = 128 decimal or 0x0080 DAC oversamppling
	AIC3204_rset( 14, 0x80 );  // Lo_Byte(DOSR) for DOSR = 128 decimal or 0x0080
	AIC3204_rset( 20, 0x80 );  // AOSR for AOSR = 128 decimal or 0x0080 for decimation filters 1 to 6
	AIC3204_rset( 11, 0x82 );  // Power up NDAC and set NDAC value to 2
	AIC3204_rset( 12, 0x87 );  // Power up MDAC and set MDAC value to 7
	AIC3204_rset( 18, 0x87 );  // Power up NADC and set NADC value to 7
	AIC3204_rset( 19, 0x82 );  // Power up MADC and set MADC value to 2

	/* DAC ROUTING and Power Up */
	AIC3204_rset( 0,  0x01 );  // Select page 1
	AIC3204_rset( 12, 0x08 );  // LDAC AFIR routed to HPL
	AIC3204_rset( 13, 0x08 );  // RDAC AFIR routed to HPR
	AIC3204_rset( 0,  0x00 );  // Select page 0
	AIC3204_rset( 64, 0x02 );  // Left vol=right vol
	AIC3204_rset( 65, 0x00 );  // Left DAC gain to 0dB VOL; Right tracks Left
	AIC3204_rset( 63, 0xd4 );  // Power up left,right data paths and set channel
	AIC3204_rset( 0,  0x01 );  // Select page 1
	AIC3204_rset( 16, 0x00 );  // Unmute HPL , 0dB gain
	AIC3204_rset( 17, 0x00 );  // Unmute HPR , 0dB gain
	AIC3204_rset( 9 , 0x30 );  // Power up HPL,HPR
	EZDSP5535_waitusec(100 );  // Wait

	/* ADC ROUTING and Power Up */
	AIC3204_rset( 0,  0x01 );  // Select page 1
	AIC3204_rset( 52, 0x30 );  // STEREO 1 Jack
							   // IN2_L to LADC_P through 40 kohm
	AIC3204_rset( 55, 0x30 );  // IN2_R to RADC_P through 40 kohmm
	AIC3204_rset( 54, 0x03 );  // CM_1 (common mode) to LADC_M through 40 kohm
	AIC3204_rset( 57, 0xc0 );  // CM_1 (common mode) to RADC_M through 40 kohm
	AIC3204_rset( 59, gain );  // MIC_PGA_L unmute
	AIC3204_rset( 60, gain );  // MIC_PGA_R unmute
	AIC3204_rset( 0,  0x00 );  // Select page 0
	AIC3204_rset( 81, 0xc0 );  // Powerup Left and Right ADC
	AIC3204_rset( 82, 0x00 );  // Unmute Left and Right ADC
	AIC3204_rset( 0,  0x00 );  // Select page 0
	EZDSP5535_waitusec(100 );  // Wait

 	return(output);
}

/*
 * 
 *  aic3204_test( )
 *
 *      Test different configurations of the AIC3204
 */
Int16 aic3204_test( Uint32 SamplingFrequency, Uint32 ADCgain )
{
    /* Initialize I2C */
    EZDSP5535_I2C_init( );
    
    /* Codec tests */
    AIC3204_init(SamplingFrequency, ADCgain);
    printf( " -> Tone on Headphone.\n" );
    if ( aic3204_tone_headphone( ) )           // Output test
        return 1;
       
    EZDSP5535_wait( 100 );  // Wait    
    //AIC3204_init(SamplingFrequency, ADCgain);
    //printf( "<-> Audio Loopback from Stereo IN --> to HP OUT\n" );
    //if ( aic3204_loop_linein( ) )              // Loop test
    //    return 3;
        
    return 0;
}
