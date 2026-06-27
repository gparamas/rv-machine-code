#include "qspi.h"


inline int qspi_data_ready() {
	return qspi0->status & 0x10;
}

inline int qspi_fifo_full() {
	return qspi0->status & 0x8;
}

inline int qspi_has_error() {
	return qspi0->status & 0x6;
}

inline int qspi_module_busy() {
	return qspi0->status & 0x1;
}

inline void send_cmd(uint32_t cmd, uint32_t num_read, uint32_t num_send) {
	qspi0->write_data = cmd;
	qspi0->write_data = num_read;
	qspi0->write_data = num_send;
}

inline uint32_t read_data() {
	while(!qspi_data_ready) {
	}
	return qspi0->read_data;
}


void send_wren() {
	send_cmd(WREN_CMD, 0, 0);

	while(qspi_module_busy()) {
	}
}

void send_wrsr() {
	send_cmd(WRSR_CMD, 0 ,2);
	qspi0->write_data = 0x40;
	qspi0->write_data = 0x40;

	while(qspi_module_busy()) {
	}
}

uint32_t send_rdsr(int wait_busy) {
	if(wait_busy) {
		send_cmd(RDSR_CMD, 0xFFFFFFFF, 0);
		while(1) {
			while(!qspi_data_ready) {
			}
			if(!(qspi0->read_data & 0x1)) {
				qspi0->config = 0x1;
				while(qspi_module_busy) {
				}
				return 0;
			}
		}
	}
	else {
		send_cmd(RDSR_CMD, 1, 0);
		while(!qspi_data_ready) {
		}
		return qspi0->read_data;
	}
}


void send_4read_noXIP(uint8_t toggle_bits, uint32_t num_read, uint32_t addr, uint32_t* data) {
	send_cmd(FREAD_CMD, num_read, 2);
	qspi0->write_data = (addr << 8) & toggle_bits;
	qspi0->write_data = 0;

	for(int i = 0; i < num_read; i++) {
		data[i] = read_data();
	}
}

void send_4read_XIP(uint8_t toggle_bits, uint32_t num_read, uint32_t addr, uint32_t* data) {
	send_cmd((addr << 8) & toggle_bits, num_read, 1);
	qspi0->write_data = 0;

	for(int i = 0; i < num_read; i++) {
		data[i] = read_data();
	}
}

inline void write_data(uint32_t data) {
	while(qspi_fifo_full) {
	}
	qspi0->write_data = data;
}

void send_4pp(uint32_t num_send, uint32_t addr, uint32_t* data, uint8_t first) {
	send_cmd(FPP_CMD, 0, num_send);
	qspi0->write_data = (addr << 8) & first;
	for(int i = 0; i < num_send; i++) {
		write_data(data[i]);
	}
}

uint32_t send_rdscur() {
	send_cmd(RDSCUR_CMD, 1, 0);
	return read_data();
}

void send_burstread(uint32_t mode) {
	send_cmd(SETBURSTLEN_CMD, 0, 1);
	qspi0->write_data = mode;
	while(qspi_module_busy()) {
	}
}

void send_erase(uint32_t erase_code, uint32_t addr) {
	send_cmd(erase_code, 0, 3);
	qspi0->write_data = addr & 0xFF;
	qspi0->write_data = (addr >> 8) & 0xFF;
	qspi0->write_data = (addr >> 16) & 0xFF;

	while(qspi_module_busy) {
	}
}
