#include <stdio.h>
#include <string.h>

#define MAX_SIZE_IP_NUM	12
#define MAX_SIZE_IP_LEN 17

int is_ipv4_addr(char *ip);

int main()
{
	char str[MAX_SIZE_IP_NUM][MAX_SIZE_IP_LEN] = {
		"192.168.0.1",
		"192.168. 1.1",
		"256.168.0.1",
		"19a.168.2.3",
		"192.168.2.1 ",
		"192.168.2.",
		"1921.168.1.1",
		"192.1 2.3.",
		"192.1..1.4",
		"192.1..1",
		"192.168.01.0",
		"192.192.192.1921"};
	for (int i = 0; i < MAX_SIZE_IP_NUM; i++) {
		printf("#%s#   ", str[i]);
		if (is_ipv4_addr(str[i]) == 0) {
			printf("true\r\n");
		} else {
			printf("false\r\n");
		}
	}
	return 0;
}

int is_ipv4_addr(char *ip)
{
	if (ip == NULL || ip[0] == '0' || ip[0] == '\0') {
		return -1;
	}

	for (int i = 0, count = 0; i < strlen(ip); i++) {
		if ((ip[i] != '.') && (ip[i] < '0' || ip[i] > '9')) {
			return -1;
		}
		if (ip[i] == '.') {
			count++;
			if (count > 3) {
				return -1;
			}
		}
	}

	int ip_num[4] = {0, 0, 0, 0};
	char ip_s[4][4];
	memset(ip_s, 0, sizeof(char[4]) * 4);

	sscanf(ip, "%[^.].%[^.].%[^.].%[^ ]", ip_s[0], ip_s[1], ip_s[2], ip_s[3]);
	sscanf(ip_s[0], "%d", &ip_num[0]);
	sscanf(ip_s[1], "%d", &ip_num[1]);
	sscanf(ip_s[2], "%d", &ip_num[2]);
	sscanf(ip_s[3], "%d", &ip_num[3]);

	for (int i = 0; i < 4; i++) {
		if (strlen(ip_s[i]) == 0 
		|| (ip_s[i][0] == '0' && ip_s[i][1] != '\0') 
		|| ip_num[i] < 0 || ip_num[i] > 255) {
			return -1;
		}
	}

	return 0;
}
