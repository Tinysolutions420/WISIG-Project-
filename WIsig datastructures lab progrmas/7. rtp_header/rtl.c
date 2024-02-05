#include <stdio.h>
#include "rtl.h"
int main() {
	rtp_header_union head;
	printf("Size of rtp_header: %zu bytes\n", sizeof(rtp_header));
	printf("Size of rtp_header: %zu bits\n", (sizeof(rtp_header)) * 8);
	printf("Size of rtp header: %zu bytes\n",sizeof(rtp_header_union));
	printf("Size of rtp header: %zu bits\n",(sizeof(rtp_header_union)) * 8);
	
	return 0;
	
}
