/*
 * WaveGene.h
 *
 *  Created on: 2019/12/7
 *      Author: Xu Wei
 */

#include "WaveGene.h"

#define BUFFSIZE 16

/* CSL UART data buffers */
char      buffer[BUFFSIZE] = {0};

/* Interrupt vector start address */
extern void VECSTART(void);
/* ISR function declarations */
void uart_lsiIsr(void);
void uart_ctoIsr(void);
void uart_txIsr(void);
void uart_rxIsr(void);
interrupt void UART_intrDispatch(void);

/* init the uart periph*/
CSL_Status UartInit(void) {
	/* Init Variables */
	CSL_UartIsrAddr isrAddr;
	CSL_Status status;
    CSL_UartConfig Config;

    /* Enable UART to FTDI chip */
    EZDSP5535_GPIO_init();
    EZDSP5535_GPIO_setDirection( 15, GPIO_OUT );
    EZDSP5535_GPIO_setOutput( 15, 0 );

    /*
	 * Configuring for baud rate of 115200
	 * Divisor = UART input clock frequency / (Desired baud rate*16)
	 * = 100MHz / 115200 / 16
	 * = 54 = 0x36
	 */
	Config.DLL = 0x36;  // Set baud rate
	Config.DLH = 0x00;

	Config.FCR = 0x0000;            // Clear UART TX & RX FIFOs
	Config.LCR = 0x0003;            // 8-bit words,
									// 1 STOP bit generated,
									// No Parity, No Stick paritiy,
									// No Break control
	Config.MCR = 0x0000;            // RTS & CTS disabled,
									// Loopback mode disabled,
									// Autoflow disabled

	status = UART_init(&uartObj, CSL_UART_INST_0, UART_INTERRUPT);
	hUart = (CSL_UartHandle)&uartObj;
	//status |= UART_reset(hUart);
	UART_getConfig(hUart,&Config);
	status |= UART_config(hUart,&Config);
	//status |= UART_resetOff(hUart);

	CSL_SYSCTRL_REGS->EBSR &= ~0xF000;   //
	CSL_SYSCTRL_REGS->EBSR |=  0x1000;   // Set parallel port to mode 1 (SPI, GPIO, UART, and I2S2)

	/* Send the details of the test to HyperTerminal */
	status = UART_fputs(hUart,"\r\n\nUART INTERRUPT TEST!",0);
	if(CSL_SOK != status)
	{
		printf("UART_fputs failed error code %d\n",status);
		return(status);
	}

	status = UART_fputs(hUart,"\r\nTEST READS A CHARACTER FROM HYPERTERMINAL CONTINUOUSLY",0);
	if(CSL_SOK != status)
	{
		printf("UART_fputs failed error code %d\n",status);
		return(status);
	}

	status = UART_fputs(hUart,"\r\nENTER '$' TO END THE TEST\r\n",0);
	if(CSL_SOK != status)
	{
		printf("UART_fputs failed error code %d\n",status);
		return(status);
	}
	/* Configure and Register the UART interrupts */
	isrAddr.rbiAddr  = uart_rxIsr;
	isrAddr.tbeiAddr = uart_txIsr;
	isrAddr.ctoi     = uart_ctoIsr;
	isrAddr.lsiAddr  = uart_lsiIsr;
	/* Disable interrupt */
	IRQ_globalDisable();

	/* Clear any pending interrupts */
	IRQ_clearAll();

	/* Disable all the interrupts */
	IRQ_disableAll();

	IRQ_setVecs((Uint32)(&VECSTART));

	/* Configuring Interrupt */
	IRQ_plug (UART_EVENT, &UART_intrDispatch);

	/* Enabling Interrupt */
	IRQ_enable(UART_EVENT);
	IRQ_globalEnable();

	/* Set the UART callback function */
	status = UART_setCallback(hUart,&isrAddr);
	if(status != CSL_SOK)
	{
		printf("UART_setCallback Failed\n");
		return(status);
	}

	/* Enable the UART Events */
	status = UART_eventEnable(hUart, CSL_UART_RECVOR_REG_DATA_INTERRUPT);
	if(status != CSL_SOK)
	{
		printf("UART_eventEnable Failed\n");
		return(status);
	}
	return (CSL_SOK);
}

void UartClose(void) {
	/* Disable UART interrupts */
	IRQ_disable(UART_EVENT);

	/* Disable GLobal Interrupts */
	IRQ_globalDisable();

	/* Clear any pending interrupts */
	IRQ_clearAll();

	/* Disable all the interrupts */
	IRQ_disableAll();
}

/* Interrupt Service*/
interrupt void UART_intrDispatch(void)
{
	Uint16 eventId = 0;

	IRQ_disable(UART_EVENT);

	/* Get the event Id which caused interrupt */
	eventId = UART_getEventId(hUart);

	if (((void (*)(void))(hUart->UART_isrDispatchTable[eventId])))
	{
		((void (*)(void))(hUart->UART_isrDispatchTable[eventId]))();
	}

	IRQ_enable(UART_EVENT);

	return;
}

void uart_lsiIsr(void)
{

}

/**
 *  \brief  Interrupt Service Routine to handle UART Character Timeout Interrupt
 *
 *  \param  none
 *
 *  \return none
 */
void uart_ctoIsr(void)
{

}

/**
 *  \brief  Interrupt Service Routine to handle UART Transmit Interrupt
 *
 *  \param  none
 *
 *  \return none
 */
void uart_txIsr(void)
{

}

/**
 *  \brief  Interrupt Service Routine to handle UART Receive Interrupt
 *
 *  \param  none
 *
 *  \return none
 */
void uart_rxIsr(void)
{
	UART_read( hUart,buffer,0,0);
}
