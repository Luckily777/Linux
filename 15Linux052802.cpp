//ϵͳ�޷�����


#include <stdio.h>

void func(void) {
	printf("hello world\n");
}



#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

//�ֶ����ض�̬��
int main(void) {
	void* p = dlopen("./libmymath.so", RTLD_LAZY);

	void (*pf)(void) = dlsym(p, "func");

	pf();

	dlclose(p);
}


[root@luckily day0b]# . / a.out
hello
[root@luckily day0b]# vim dynamic_test.c
[root@luckily day0b]# gcc - shared - fPIC - olibmymath.so.2 dynamic_test.c
[root@luckily day0b]# ls
a.out  dynamic_test.c  libmymath.so  libmymath.so.1  libmymath.so.2  main.c  program
[root@luckily day0b]# . / a.out
hello
[root@luckily day0b]# rm libmymath.so
rm���Ƿ�ɾ���������� "libmymath.so"��y
[root@luckily day0b]# ln - s libmymath.so.2  libmymath.so
[root@luckily day0b]# . / a.out
hello world
