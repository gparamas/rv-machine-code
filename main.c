#include "uart.h"

int main() {
	for(int i = 0; i < 100; i++) {
		uart_putchar(i);
	}
}
