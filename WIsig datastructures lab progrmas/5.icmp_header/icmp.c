#include <stdio.h>
#include <stddef.h>
#include "icmp.h"
int main() {
	icmp_header icmp;
	printf("Size of icmp header: %zu bytes\n", sizeof(icmp));
	printf("icmp_type offset: %zu, size: %zu\n", offsetof(icmp_header, icmp_type), sizeof(icmp.icmp_type));
	printf("icmp_code offset: %zu, size: %zu\n", offsetof(icmp_header, icmp_code), sizeof(icmp.icmp_code));
	printf("icmp_checksum offset: %zu, size: %zu\n", offsetof(icmp_header, icmp_checksum), sizeof(icmp.icmp_checksum));
	printf("identifier offset: %zu, size: %zu\n", offsetof(icmp_header, identifier), sizeof(icmp.identifier));
	printf("seq_num offset: %zu, size: %zu\n", offsetof(icmp_header, seq_num), sizeof(icmp.seq_num));
	printf("icmp_dt offset: %zu, size: %zu\n", offsetof(icmp_header, icmp_dt), sizeof(icmp.icmp_dt));

size_t totalHeaderSize = sizeof(icmp.icmp_type) + sizeof(icmp.icmp_code) + sizeof(icmp.icmp_checksum) + sizeof(icmp.identifier) + sizeof(icmp.seq_num) + sizeof(icmp.icmp_dt);

printf("total header size: %zu bytes\n", totalHeaderSize);
printf("total header size: %zu bits\n", (totalHeaderSize) * 8);
return 0;

}
