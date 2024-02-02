#ifndef PROTOCOL_H
#define PROTOCOL_H
#include <stdint.h>
typedef struct {
	uint8_t version;
	uint8_t message_type;
	uint16_t length;
} Protocol_Header;

#endif
