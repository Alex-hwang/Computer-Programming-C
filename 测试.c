#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(int argc, char* argv[]) {
	char** p;
	for (p = argv; argc--; p++) {
		printf("%c%s", **p, *p);
	}
	return 0;
}