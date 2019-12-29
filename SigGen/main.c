/*
 * main.c
 */
#include "WaveGene.h"
#include "stdio.h"
#include "ezdsp5535.h"

#define SAMPLES_PER_SECOND 48000
#define GAIN_IN_dB 30


extern Int16 aic3204_test(Uint32, Uint32 );

/*********************************** XW ***********************************/
struct WAVE wave;

/*********************************** XW ***********************************/
void main(void) {
	/* Init the ezdsp5535 board */
	EZDSP5535_init();

	/*********************************** XW ***********************************/
	wave.Freq = 1000;
	wave.type = 0;
	wave.Amp=20000;
	switch_int ( );
	while(1) {
		//switch_test();
		aic3204_tone_headphone();
	}

	/*********************************** XW ***********************************/
}
