#include <stdio.h>
#include "tcp.h"
int main() {
	tcp_header_t tcpHe = {
		.source_port = 1234,
		.dest_port = 5678,
		.sequence_number = 123456,
		.ack_number = 846041,
		.checksum = 0,
		.urget_pointer = 0,
		.offset_reserved = 0 * 50,
		.window_size = 5652,
		.option_pad = 7855 
	};
	
	return 0;
}
