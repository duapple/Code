#include "util.h"

char * util_load_file(const char * file)
{
	char *pbuf = NULL;
	int size;
	int read_len;
	FILE *fp = fopen(file, "rb");
	if (fp) {
		fseek(fp, 0, SEEK_END);
		size = ftell(fp);
		fseek(fp, 0, SEEK_SET);

		pbuf = malloc(size + 1);
		if (pbuf) {
			read_len = fread(pbuf, 1, size , fp);
			if (read_len == size) {
				pbuf[read_len] = 0;
			}
		}
		fclose(fp);
	}
	return pbuf;
}
