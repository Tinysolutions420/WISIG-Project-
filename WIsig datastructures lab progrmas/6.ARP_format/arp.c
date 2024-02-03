#include <stdio.h>
#include <stddef.h>
#include "arp.h"
int main() {
	arp_header arp;
	printf("Size of arp header: %zu bytes\n", sizeof(arp));
	printf("Size of arp header: %zu bits\n", (sizeof(arp)) * 8);
	printf("hardware type offset: %zu, size: %zu\n", offsetof(arp_header, ht), sizeof(arp.ht));
	printf("protocol type offset: %zu, size: %zu\n", offsetof(arp_header, pt), sizeof(arp.pt));
	printf("hardware type size offset: %zu, size: %zu\n", offsetof(arp_header, ht_s), sizeof(arp.ht_s));
	printf("protocol type size offset: %zu, size: %zu\n", offsetof(arp_header, pt_s), sizeof(arp.pt_s));
	printf("operational code offset: %zu, size: %zu\n", offsetof(arp_header, opc), sizeof(arp.opc));
	printf("source hardware offset: %zu, size: %zu\n", offsetof(arp_header, sht), sizeof(arp.sht));
	printf("source protocol offset: %zu, size: %zu\n", offsetof(arp_header, spt), sizeof(arp.spt));
	printf("target hardware offset: %zu, size: %zu\n", offsetof(arp_header, tht), sizeof(arp.tht));
	printf("target protocol type offset: %zu, size: %zu\n", offsetof(arp_header, tpt), sizeof(arp.tpt));
	
return 0;

}
