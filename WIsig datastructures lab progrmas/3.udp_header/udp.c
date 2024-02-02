#include <stdio.h>
#include "udp.h"
int main() {
	UDP_HEADER udpHe;
	size_t sizeOfHeader = sizeof(udpHe);
	printf("Size of UdpHeader: %lu bits\n", (sizeOfHeader) * 8);
	printf("Size of UdpHeader: %lu bytes\n", sizeOfHeader);
	return 0;
}
