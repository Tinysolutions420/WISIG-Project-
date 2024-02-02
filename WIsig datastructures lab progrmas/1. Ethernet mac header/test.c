#include <stdio.h>
#include "protocol.h"

int main() {
	Protocol_Header header;
	printf("Size of ProtocolHeader: %lu bytes\n", sizeof(header));
	size_t sumOfBytes = sizeof(header.version) + sizeof(header.message_type) +   sizeof(header.length);
	printf("sum of header bytes: %lu bytes\n", sumOfBytes);
	
	return 0;
}
