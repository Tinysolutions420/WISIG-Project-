#ifndef RTP_HEADER_H
#define RTP_HEADER_H
#include <stdint.h>
typedef struct {
	uint8_t version : 2;
	uint8_t padding : 1;
	uint8_t ext : 1;
	uint8_t c_c : 4;
	uint8_t marker : 1;
	uint8_t pt : 7;
	uint16_t seq_num;
	uint32_t tym_stmp;
	uint32_t ssrc;
	uint32_t csrc;
} rtp_header;

typedef union {
	rtp_header head;
	uint8_t bytes[sizeof(rtp_header)];
} rtp_header_union;

#endif
