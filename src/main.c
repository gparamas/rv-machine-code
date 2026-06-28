#include "../uart.h"
//#include <stdlib.h>
#include "../qspi.h"

int main() {
	/*int* ptr = malloc(100);
	for(int i = 0; i < 100; i++) {
		ptr[i] = i;
	}*/
	uint32_t array[10] = {0};

	send_wren();
	send_wrsr();
	send_rdsr(1);
	send_4read_noXIP(0x00, 10, 0, array);
	for(int i = 0; i < 10; i++) {
		uart_putchar(array[i]);
	}
}
