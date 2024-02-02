#ifndef IPV4_HEADER_H
#define IPV4_HEADER_H
#include <stdint.h>

typedef struct {
	uint8_t version_hl; // version + bit internet head(4 + 4)
	uint8_t type_of_service; 
	uint16_t total_length;  
	uint16_t identification;
	uint16_t flag_fragments; // (3 + 13)
	uint8_t time_to_live;
	uint8_t protocol;
	uint16_t header_checksum;
	uint32_t source_address;
	uint32_t dest_address;
	uint32_t option_pad; // option + padding (24 + 8)
} IPv4_Header;

#endif
