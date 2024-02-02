#ifndef TCP_HEADER_H
#define TCP_HEADER_H
#include <stdint.h>
typedef struct {
	uint16_t source_port;
	uint16_t dest_port;
	uint32_t sequence_number;
	uint32_t ack_number;
	uint16_t checksum;
	uint16_t urget_pointer;
	uint8_t offset_reserved;
	uint16_t window_size;
	uint32_t option_pad;
} tcp_header_t;

#endif 
