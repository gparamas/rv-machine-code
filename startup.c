void *memset(void *s, int c, unsigned int n) {
    char *p = s;
    while (n--) *p++ = c;
    return s;
}

void start() {
	extern char _bss_start;
	extern char _end;
	char* bss_start = &_bss_start;
	char* bss_end = &_end;
	memset(bss_start, 0, bss_end - bss_start);
}
