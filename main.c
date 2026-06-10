#include "uart.h"
#include <stdlib.h>

int main() {
	int* ptr = malloc(100);
	for(int i = 0; i < 100; i++) {
		ptr[i] = i;
	}
	for(int i = 0; i < 100; i++) {
		uart_putchar(ptr[i]);
	}
}
