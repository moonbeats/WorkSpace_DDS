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

#include "WaveGene.h"

struct SwitchState ss = {0, 0, {100,500,1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000},  {0, 1, 2, 3, 4}};

void switch_int ( ) {
	if (EZDSP5535_SAR_init()) {
		/* Initialize SAR */
		printf("    init SAR suceed.\n");
	}

    printf("    Press SW1 to change frequency.\n");
    printf("    Press SW2 to change waveform.\n");
}
/* 
 *  switch_test( )
 *      Tests Switches and SAR module.
 */
Int16 switch_test( )
{
    Int16 key;
    static Int16 key_tmp = 0;

    key = EZDSP5535_SAR_getKey();
    if (key == key_tmp) ;
    else {
    	switch (key) {
    	    case SW1:
    	    	change_wave_freq();
    	    	break;
    	    case SW2:
    	    	change_wave_form();
    	    	break;
    	    case SW12:
    	    	break;
    	    }
    	key_tmp = key;
    }

    return 0;
}

void change_wave_freq() {

	if (ss.freq_idx < FREQ_SIZE) {
		wave.Freq = ss.freq_flag[ss.freq_idx];
		ss.freq_idx ++;
	}
	else {
		ss.freq_idx = 0;
		wave.Freq = ss.freq_flag[ss.freq_idx];
		ss.freq_idx ++;
	}
	printf("Wave Frequency is  %d HZ\n",wave.Freq);//DGF add
}
void change_wave_form() {

	if (ss.form_idx < FORM_SIZE) {
		wave.type = ss.form_flag[ss.form_idx];
		ss.form_idx ++;
	}
	else {
		ss.form_idx = 0;
		wave.type = ss.form_flag[ss.form_idx];
		ss.form_idx ++;
	}
	//printf(" Generating %s wave \n",wave.type);//DGF add 这李打印怎么格式化
}
