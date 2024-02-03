#ifndef ARP_HEADER_H
#define ARP_HEADER_H
#include <stdint.h>
typedef struct {
	uint16_t ht;
	uint16_t pt;
	uint8_t ht_s;
	uint8_t pt_s;
	uint16_t opc;
	uint32_t sht;
	uint32_t spt;
	uint32_t tht;
	uint32_t tpt;
} arp_header;

#endif
