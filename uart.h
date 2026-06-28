#include <stdint.h>

#ifndef UART_H
#define UART_H

#define UART_BASE 0x34000

typedef struct {
	volatile uint32_t status;
	volatile uint32_t error;
	volatile uint32_t data_size;
	volatile uint32_t lbit_period;
	volatile uint32_t hbit_period;
	volatile uint32_t write;
	volatile uint32_t read;
} uart_t;

#define uart0 ((uart_t*) UART_BASE)


int uart_is_busy();
int uart_tx_fifo_full();
int uart_indata_ready();
int uart_putchar(const char c);
char uart_readchar();

#endif
