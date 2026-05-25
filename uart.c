#include "uart.h"

int uart_is_busy() {
        return (uart0->status & 0x02);
}

int uart_tx_fifo_full() {
        return (uart0->status & 0x04);
}

int uart_indata_ready() {
	return (uart0->status & 0x01);
}

int uart_putchar(const char c) {
	while(uart_tx_fifo_full()) {
	}
        uart0->write = c & 0x000000FF;
}

char uart_readchar() {
	while(!uart_indata_ready()) {
	}
	return uart0->read & 0xFF;
}	
