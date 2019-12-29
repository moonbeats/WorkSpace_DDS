/*
 * WaveGene.h
 *
 *  Created on: 2019/12/7
 *      Author: Xu Wei
 */

#ifndef WAVEGENE_H_
#define WAVEGENE_H_
/* Include 	Related head files*/
#include <stdio.h>
#include "ezdsp5535.h"
#include "csl_gpio.h"
#include "ezdsp5535_gpio.h"
#include "csl_uart.h"
#include "csl_uartAux.h"
#include "csl_intc.h"
#include "csl_general.h"
#include "ezdsp5535_led.h"
#include "ezdsp5535_sar.h"

/* define the data structure */
struct WAVE
{
 volatile signed short int Freq;
 volatile signed short int Amp;
 volatile enum {
  SIN = 0,
  SQUARE,
  TRI
 } type;
};
extern struct WAVE wave;

/*********************************** XW ***********************************/
/*
void TabelSearch(struct WAVE* pwave, int phase);
void WaveGenerate(struct WAVE* pwave);
*/

#define FREQ_SIZE 12
#define FORM_SIZE 3

struct SwitchState {
	volatile Uint32 freq_idx;
	volatile Uint32 form_idx;
	volatile Uint32 freq_flag[FREQ_SIZE];
	volatile int form_flag[FORM_SIZE];
};
//
extern struct SwitchState ss;

void switch_int();
Int16 switch_test();
void change_wave_freq();
void change_wave_form();

/*********************************** XW ***********************************/

#endif /* WAVEGENE_H_ */
