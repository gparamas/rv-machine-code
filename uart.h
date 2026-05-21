#include <stdint.h>

#ifndef UART_H
#define UART_H

#define UART_BASE 0x33000

typedef struct {
	volatile uint8_t status;
	volatile uint8_t error;
	volatile uint8_t data_size;
	volatile uint8_t lbit_period;
	volatile uint8_t hbit_period;
	volatile uint8_t write;
	volatile uint8_t read;
} uart_t;

#define uart0 ((uart_t*) UART_BASE)


int uart_is_busy();
int uart_tx_fifo_full();
int uart_indata_ready();
int uart_putchar(const char c);
char uart_readchar();

#endif
