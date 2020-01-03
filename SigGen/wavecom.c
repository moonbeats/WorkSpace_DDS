
#include "stdio.h"
#include "ezdsp5535.h"
#include "ezdsp5535_i2s.h"
#include "csl_i2s.h"
#include "dsplib.h"
#include "WaveGene.h"

extern Int16 AIC3204_rset( Uint16 regnum, Uint16 regval);
extern Int16 switch_test( );


/*****************************************************************************/
/* generate_sinewave()                                                       */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/* Generate a sinewave. Based on sampling rate of 48000 Hz.                  */
/*                                                                           */
/*                                                                           */
/* PARAMETER 1: The frequency of the sinewave between 10 Hz and 16000 Hz.    */
/* PARAMETER 2: The maximum amplitude of the sinewave between 1 to 32767.    */
/*                                                                           */
/*****************************************************************************/
signed int generate_sinewave(signed short int frequency, signed short int amplitude)
{

 short int sinusoid;
 signed long result;
 static short int count = 0;

 /* Multiply frequency by scaling factor of 32767 / 48000 */

 result = ( (long)frequency * 22368 ) >> 14 ;

 if ( result > 32767)
      result = 32767; /* Maximum value for highest frequency */
 else if ( 0 == result)
      result = 1;     /* Minimum value for lowest fequency */
 else if ( result < -32767)
      result = -32767;

 count += (short int) result;

 /* Obtain sine of input */
 sine ( &count, &sinusoid, 1);

 if ( amplitude > 32767 )
      amplitude = 32767; /* Range limit amplitude */

 /* Scale sine wave to have maximum value set by amplitude */
 result =  ( (long) sinusoid * amplitude ) >> 15;

 return ( (signed int ) result );
}

/*****************************************************************************/
/* generate_squarewave()                                                       */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/* Generate a squarewave. Based on sampling rate of 48000 Hz.                  */
/*                                                                           */
/*                                                                           */
/* PARAMETER 1: The frequency of the squarewave between 10 Hz and 16000 Hz.    */
/* PARAMETER 2: The maximum amplitude of the squarewave between 1 to 32767.    */
/*                                                                           */
/*****************************************************************************/
signed int generate_squarewave(signed short int frequency, signed short int amplitude)
{
	signed long result;
	static short int count = 0;
	signed long squre;

	result = ( (long)frequency * 22368 ) >> 14 ;
	if ( result > 32767)
	     result = 32767; /* Maximum value for highest frequency */
	else if ( 0 == result)
	     result = 1;     /* Minimum value for lowest fequency */
	else if ( result < -32767)
	     result = -32767;

	count += (short int) result;
	if (count <= 0)
		squre = 1;
	else if(count >0)
		squre = -1;

	if ( amplitude > 32767 )
	      amplitude = 32767;

	result = ( (long) squre* amplitude) ;
	return ( (signed int ) result );
}
/*****************************************************************************/
/* generate_sawwave()                                                       */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/* Generate a sawwave. Based on sampling rate of 48000 Hz.                  */
/*                                                                           */
/*                                                                           */
/* PARAMETER 1: The frequency of the sawwave between 10 Hz and 16000 Hz.    */
/* PARAMETER 2: The maximum amplitude of the sawwave between 1 to 32767.    */
/*                                                                           */
/*****************************************************************************/
signed int generate_sawwave(signed short int frequency, signed short int amplitude)
{
	signed long result;
	static short int count = 0;


	result = ( (long)frequency * 22368 ) >> 14 ;
	if ( result > 32767)
	     result = 32767; /* Maximum value for highest frequency */
	else if ( 0 == result)
	     result = 1;     /* Minimum value for lowest frequency */
	else if ( result < -32767)
	     result = -32767;

	count += (short int) result;


	if ( amplitude > 32767 )
	      amplitude = 32767;

	result =  (long) count ;
	return ( (signed int ) result );
}
/*****************************************************************************/
/* generate_angwave()                                                       */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/* Generate a angwave. Based on sampling rate of 48000 Hz.                  */
/*                                                                           */
/*                                                                           */
/* PARAMETER 1: The frequency of the angwave between 10 Hz and 16000 Hz.    */
/* PARAMETER 2: The maximum amplitude of the angwave between 1 to 32767.    */
/*                                                                           */
/*****************************************************************************/
signed int generate_angwave(signed short int frequency, signed short int amplitude)
{
	signed long result;
	static short int count = 0;
	signed long ang;



	result = ( (long)frequency * 22368 ) >> 14 ;
	if ( result > 32767)
	     result = 32767; /* Maximum value for highest frequency */
	else if ( 0 == result)
	     result = 1;     /* Minimum value for lowest fequency */
	else if ( result < -32767)
	     result = -32767;

	count += (short int) result;

	if (count>=0)
		ang = 32767-count;
	else if (count<0)
		ang = 32767+count;

	result=(long)ang;

	if ( amplitude > 32767 )
	      amplitude = 32767;


	return ( (signed int ) result );
}

/*****************************************************************************/
/* generate_bpskwave()                                                       */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/* Generate a bpskwave. Based on sampling rate of 48000 Hz.                  */
/*                                                                           */
/*                                                                           */
/* PARAMETER 1: The frequency of the bpskwave between 10 Hz and 16000 Hz.    */
/* PARAMETER 2: The maximum amplitude of the bpskwave between 1 to 32767.    */
/*                                                                           */
/*****************************************************************************/
signed int generate_bpskwave(signed short int frequency, signed short int amplitude,signed short int sigmod)
{
	signed long result;
	static short int count = 0;
	 short int sinusoid;



	result = ( (long)frequency * 22368 ) >> 14 ;
	if ( result > 32767)
	     result = 32767; /* Maximum value for highest frequency */
	else if ( 0 == result)
	     result = 1;     /* Minimum value for lowest fequency */
	else if ( result < -32767)
	     result = -32767;

	count += (short int) result;

	sine ( &count, &sinusoid, 1);
	if (sigmod == 1)
		result = sinusoid;
	else if(sigmod == 0)
		result = - sinusoid;
	if ( amplitude > 32767 )
	      amplitude = 32767;


	 result =  ( (long) sinusoid * amplitude ) >> 15;

	 return ( (signed int ) result );
}


signed int generate_wave(struct WAVE wave)
{
	signed long result;


	signed short int frequency = wave.Freq;
	signed short int amplitude = wave.Amp;

	switch(wave.type)
	{
	case SIN:
		result= generate_sinewave( frequency,  amplitude);
		break;

	case SQUARE:
		result= generate_squarewave(frequency, amplitude);
		break;

	case TRI:
		result= generate_sawwave( frequency,  amplitude);
		break;

	case ANG:
		result= generate_angwave(frequency,amplitude);
		break;
	case BPSK:
		break;

	}

	return ( (signed int ) result );
}



Int16 aic3204_tone_headphone()
{
	signed int out;

     /* Initialize I2S */
    EZDSP5535_I2S_init();

    while(1)
    {
    	switch_test();

		out = generate_wave(wave);

    	/* Write 16-bit left channel Data */
    	EZDSP5535_I2S_writeLeft( out);

    	/* Write 16-bit right channel Data */
    	EZDSP5535_I2S_writeRight(out);
    }



    EZDSP5535_I2S_close();    // Disble I2S
    AIC3204_rset( 0,  0x00 );  // Select page 0
    AIC3204_rset( 1,  0x01 );  // Reset codec

    return 0;
}


