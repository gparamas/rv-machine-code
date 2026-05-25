#include "uart.h"

int main() {
	char a = uart_is_busy();
	char c = uart_indata_ready();
	uart_putchar('a');
}
