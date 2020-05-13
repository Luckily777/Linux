//C语言和C++编译后，所产生的不同的结果，

//const是一个不变的变量，它自身所修饰的变量是没有办法改变的，但是变量的空间是可以通过其他方式来进行改变的。

6   2 #include <stdlib.h>
7   3
8   4 int main(void) {
    9   5         const int a = 10;
    10   6         int* p = (int*)&a;
    11   7 * p = 11;
    12   8
        13   9         printf("p= %d,a = %d\n", *p, a);
    14  10
}
15
16 #汇编代码
17   1.file   "test.c"
18   2.section.rodata
19   3.LC0:
20   4.string "p= %d,a = %d\n"
21   5.text
22   6.globl  main
23   7.type   main, @function
24   8 main:
25   9.LFB2 :
    26  10.cfi_startproc
    27  11         pushq % rbp
    28  12.cfi_def_cfa_offset 16
    29  13.cfi_offset 6, -16
    30  14         movq % rsp, % rbp
    31  15.cfi_def_cfa_register 6
    32  16         subq    $16, % rsp
    33  17         movl    $10, -12(% rbp)   #const int a = 10
    34  18         leaq - 12(% rbp), % rax  # % rax = &a
    35  19         movq % rax, -8(% rbp)
    36  20         movq - 8(% rbp), % rax
    37  21         movl    $11, (% rax)
    38  22         movl - 12(% rbp), % edx
    39  23         movq - 8(% rbp), % rax
    40  24         movl(% rax), % eax
    41  25         movl % eax, % esi



    2. 
    1 #include <stdio.h>
    2 #include <stdlib.h>
    3
    4 int main(void) {
    5         int a;
    6
        7         scanf("%d", a);
    8
        9         printf("a = %d\n", a);
    10
}
