#include <stdint.h>

#ifndef QSPI_H
#define QSPI_H

#define QSPI_BASE 0x34100

#define WREN_CMD 0x06
#define RDSR_CMD 0x05
#define RDCR_CMD 0x15
#define WRSR_CMD 0x01
#define FREAD_CMD 0x11101011
#define SETBURSTLEN_CMD 0x77
#define SE_CMD 0x20
#define BE64K_CMD 0xD8
#define BE32K_CMD 0x52
#define FPP_CMD 0x00111000
#define RDSCUR_CMD 0x2B

typedef struct {
	volatile uint8_t status;
       	volatile uint8_t config;
	volatile uint8_t read_data;
	volatile uint8_t write_data;
} qspi_t;

#define qspi0 ((qspi_t*) QSPI_BASE)

int qspi_data_ready() __attribute__((always_inline));
int qspi_fifo_full() __attribute__((always_inline));
int qspi_has_error() __attribute__((always_inline));
int qspi_module_busy() __attribute__((always_inline));
void send_cmd(uint32_t cmd, uint32_t num_read, uint32_t num_send) __attribute__((always_inline));
uint32_t read_data() __attribute__((always_inline));
void write_data(uint32_t data) __attribute__((always_inline));
void send_wren();
void send_wrsr();
uint32_t send_rdsr(int wait_busy);
void send_4read_noXIP(uint8_t toggle_bits, uint32_t num_read, uint32_t addr, uint32_t* data);
void send_4read_XIP(uint8_t toggle_bits, uint32_t num_read, uint32_t addr, uint32_t* data);
void send_4pp(uint32_t num_send, uint32_t addr, uint32_t* data, uint8_t first);
uint32_t send_rdscur();
void send_burstread(uint32_t mode);
void send_erase(uint32_t erase_code, uint32_t addr);


#endif
