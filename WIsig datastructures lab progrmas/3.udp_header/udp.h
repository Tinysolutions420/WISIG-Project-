#ifndef UDP_HEADER_H
#define UDP_HEADER_H
#include <stdint.h>
typedef struct {
	uint16_t source_port;
	uint16_t dest_port;
	uint16_t length;
	uint16_t checksum;
} UDP_HEADER;
#endif
