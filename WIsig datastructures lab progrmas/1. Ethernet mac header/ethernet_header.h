#ifndef ETHERNET_HEADER_H
#define ETHERNET_HEADER_H
#include <stdint.h>
typedef struct {
	uint64_t bits:62;
}Preamble_62;
typedef struct {
	Preamble_62 preamble;
	uint8_t start_of_frame_delimiter:2;
	uint64_t dest_address:48;
	uint64_t source_address:48;
	uint16_t length_or_type;
} ETHERNET_HEADER;

typedef union {
	ETHERNET_HEADER ethHe;
	char padding[1];
} SizeUnion;

#endif
