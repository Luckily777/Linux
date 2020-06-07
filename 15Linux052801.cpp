//¼ÆËãÆ÷ÏîÄ¿

#ifndef __GLOBAL_H__
#define __GLOBAL_H__

int add(int a, int b);
int sub(int a, int b);
#endif //__GLOBAL_H__



#include <global.h>

int add(int a, int b) {
	return a + b;
}

#include <global.h>

int sub(int a, int b) {
	return a - b;
}

#include <global.h>
#include <stdio.h>

int main(void) {
	printf("add= %d\n", add(20, 30));
	printf("sub =%d\n", sub(20, 30));
}
