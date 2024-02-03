#ifndef ICMP_HEADER_H
#define ICMP_HEADER_H
#include <stdint.h>
typedef struct {
	uint8_t icmp_type;
	uint8_t icmp_code;
	uint16_t icmp_checksum;
	uint16_t identifier;
	uint16_t seq_num;
	uint32_t icmp_dt;
} icmp_header;

#endif
