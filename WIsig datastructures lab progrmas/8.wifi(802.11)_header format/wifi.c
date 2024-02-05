#include <stdio.h>
#include "wifi.h"
int main() {
	wifi_union_frame wife;
	printf("Size of the wifi_frame: %zu bytes\n", sizeof(wifi_frame));
	printf("Size of the wifi_frame: %zu bytes\n", (sizeof(wifi_frame)) * 8);
	printf("Size of the wifi frame %zu bytes\n", sizeof(wifi_union_frame));
	printf("Size of the wifi frame %zu bytes\n", (sizeof(wifi_union_frame)) * 8);
	
	return 0;
	
}
