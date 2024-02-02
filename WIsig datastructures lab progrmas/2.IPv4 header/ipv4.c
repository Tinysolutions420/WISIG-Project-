#include <stdio.h>
#include "ipv4.h"
int main() {
	IPv4_Header ipv4_He;
	size_t sizeOfHeader = sizeof(ipv4_He);
	printf("Size of IPv4Header: %lu bits\n", (sizeOfHeader * 8));
	printf("size of ipv4Header in bytes: %lu bytes\n", sizeOfHeader);
	return 0;
}
