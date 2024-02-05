#ifndef WIFI_FRAME_H
#define WIFI_FRAME_H
#include <stdint.h>
typedef struct {
	uint16_t prot_version : 2;
	uint16_t type : 2;
	uint16_t sub_type : 4;
	uint16_t to_ds : 1;
	uint16_t from_ds : 1;
	uint16_t more_flag : 1;
	uint16_t retry : 1;
	uint16_t power_mgmt : 1;
	uint16_t more_data : 1;
	uint16_t protected_frame : 1;
	uint16_t order : 1;
} Frame_ctrl;

typedef struct { 
	Frame_ctrl frame;
	uint16_t duration;
	uint8_t mac_add1[6];
	uint8_t mac_add2[6];
	uint8_t mac_add3[6];
	uint8_t mac_add4[6];
	uint16_t seq_ctrl;
	uint8_t data[2312];
	uint32_t crc;
} wifi_frame;

typedef union {
	wifi_frame wifi;
	uint8_t bytes[sizeof(wifi_frame)];
} wifi_union_frame;

#endif
