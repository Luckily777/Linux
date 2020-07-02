[root@luckily day11]# vim shmsend.c
[root@luckily day11]# vim shmread.c
[root@luckily day11]# gcc shmread.c - p read
gcc : 错误：read：没有那个文件或目录
[root@luckily day11]# gcc shmread.c - o read
[root@luckily day11]# mkdir sem
[root@luckily day11]# cd sem
[root@luckily sem]# ls
[root@luckily sem]# vim semcreat.c
[root@luckily sem]# gcc semcreat.c
[root@luckily sem]# . / a, out
bash : . / a, out : 没有那个文件或目录
[root@luckily sem]# . / a.out
creat ok
[root@luckily sem]# ipcs - m

------------共享内存段--------------
键        shmid      拥有者  权限     字节     nattch     状态
0x00000000 294912     root       777        16384      1          目标
0x00000000 327681     root       777        2129920    2          目标
0x00000000 491522     root       600        524288     2          目标
0x00000000 524291     root       777        2129920    2          目标
0x00000000 622596     root       600        524288     2          目标
0x00000000 655365     root       600        524288     2          目标
0x00000000 786438     root       600        16777216   2          目标
0x00000000 819207     root       600        524288     2          目标
0x00000000 851976     root       777        1916928    2          目标
0x000004d2 884745     root       644        4          0

[root@luckily sem]# vim setval.v
[root@luckily sem]# rm - rf setval.v
[root@luckily sem]# ls
a.out  semcreat.c
[root@luckily sem]# vim setval.c
[root@luckily sem]# gcc setval.c
/ tmp / ccP1hqnD.o：在函数‘main’中：
setval.c:(.text + 0x40)：对‘scafn’未定义的引用
collect2 : 错误：ld 返回 1
[root@luckily sem]# vim setval.c
[root@luckily sem]# gcc setval.c - osetval
[root@luckily sem]# . / setval
val : 5
[root@luckily sem]# vim getval.c
[root@luckily sem]# make getval.c
make : 对“getval.c”无需做任何事。
[root@luckily sem]# make getval
cc     getval.c - o getval
[root@luckily sem]# ls
getval  getval.c  semcreat.c  setval  setval.c
[root@luckily sem]# . / getval
5
[root@luckily sem]# vim pv.c
[root@luckily sem]# gcc pv.c - pv
gcc : 错误：unrecognized command line option ‘ - pv’
[root@luckily sem]# gcc pv.c - opv
[root@luckily sem]# . / pv
[root@luckily sem]# . / getval
4
[root@luckily sem]# vim p.c
[root@luckily sem]# rm pv.c
rm：是否删除普通文件 "pv.c"？y
[root@luckily sem]# vim v.c
[root@luckily sem]# gcc v.c - ov
[root@luckily sem]# . / v
[root@luckily sem]# . / getval
5
[root@luckily sem]# ipcs - m

------------共享内存段--------------
键        shmid      拥有者  权限     字节     nattch     状态
0x00000000 294912     root       777        16384      1          目标
0x00000000 327681     root       777        2129920    2          目标
0x00000000 491522     root       600        524288     2          目标
0x00000000 524291     root       777        2129920    2          目标
0x00000000 622596     root       600        524288     2          目标
0x00000000 655365     root       600        524288     2          目标
0x00000000 786438     root       600        16777216   2          目标
0x00000000 819207     root       600        524288     2          目标
0x00000000 851976     root       777        1916928    2          目标
0x000004d2 884745     root       644        4          0

[root@luckily sem]# ipcrm - S 1234
[root@luckily sem]# ipcs - m

------------共享内存段--------------
键        shmid      拥有者  权限     字节     nattch     状态
0x00000000 294912     root       777        16384      1          目标
0x00000000 327681     root       777        2129920    2          目标
0x00000000 491522     root       600        524288     2          目标
0x00000000 524291     root       777        2129920    2          目标
0x00000000 622596     root       600        524288     2          目标
0x00000000 655365     root       600        524288     2          目标
0x00000000 786438     root       600        16777216   2          目标
0x00000000 819207     root       600        524288     2          目标
0x00000000 851976     root       777        1916928    2          目标
0x000004d2 884745     root       644        4          0

[root@luckily sem]# ipcs

-------- - 消息队列---------- -
键        msqid      拥有者  权限     已用字节数 消息

------------共享内存段--------------
键        shmid      拥有者  权限     字节     nattch     状态
0x00000000 294912     root       777        16384      1          目标
0x00000000 327681     root       777        2129920    2          目标
0x00000000 491522     root       600        524288     2          目标
0x00000000 524291     root       777        2129920    2          目标
0x00000000 622596     root       600        524288     2          目标
0x00000000 655365     root       600        524288     2          目标
0x00000000 786438     root       600        16777216   2          目标
0x00000000 819207     root       600        524288     2          目标
0x00000000 851976     root       777        1916928    2          目标
0x000004d2 884745     root       644        4          0

-------- - 信号量数组---------- -
键        semid      拥有者  权限     nsems

[root@luckily sem]# vim mutex.c
[root@luckily sem]# gcc mutex.c
/ tmp / ccmP8bzp.o：在函数‘main’中：
mutex.c:(.text + 0x13b)：对‘print_char’未定义的引用
mutex.c : (.text + 0x14c)：对‘print_char’未定义的引用
collect2 : 错误：ld 返回 1
[root@luckily sem]# vim mutex.c
[root@luckily sem]# gcc mutex.c
[root@luckily sem]# . / a.out
xxoooxxoooxxox ^ C
[root@luckily sem]# vim mutex.c
[root@luckily sem]# gcc mutex.c
mutex.c: 在函数‘sem_setval’中:
mutex.c : 36 : 14 : 错误：‘su’的存储大小未知
union semun su;
^
mutex.c: 在文件作用域：
mutex.c : 42 : 6 : 警告：与‘p’类型冲突[默认启用]
void p(int id) {
    ^
        mutex.c:12 : 3 : 附注：‘p’的上一个隐式声明在此
        p(semid);
    ^
        mutex.c:51 : 6 : 警告：与‘v’类型冲突[默认启用]
        void v(int id) {
        ^
            mutex.c:19 : 3 : 附注：‘v’的上一个隐式声明在此
            v(semid);
        ^
            [root@luckily sem]# vim mutex.c
            [root@luckily sem]# gcc mutex.c
            mutex.c: 在函数‘sem_setval’中:
        mutex.c : 36 : 14 : 错误：‘su’的存储大小未知
            union semun su;
        ^
            mutex.c: 在文件作用域：
            mutex.c : 42 : 6 : 警告：与‘P’类型冲突[默认启用]
            void P(int id) {
            ^
                mutex.c:12 : 3 : 附注：‘P’的上一个隐式声明在此
                P(semid);
            ^
                mutex.c:51 : 6 : 警告：与‘V’类型冲突[默认启用]
                void V(int id) {
                ^
                    mutex.c:19 : 3 : 附注：‘V’的上一个隐式声明在此
                    V(semid);
                ^
                    [root@luckily sem]# vim mutex.c
                    [root@luckily sem]# gcc mutex.c
                    mutex.c: 在函数‘sem_setval’中:
                mutex.c : 36 : 14 : 错误：‘su’的存储大小未知
                    union semun su;
                ^
                    mutex.c: 在文件作用域：
                    mutex.c : 42 : 6 : 警告：与‘P’类型冲突[默认启用]
                    void P(int id) {
                    ^
                        mutex.c:12 : 3 : 附注：‘P’的上一个隐式声明在此
                        P(semid);
                    ^
                        mutex.c:51 : 6 : 警告：与‘V’类型冲突[默认启用]
                        void V(int id) {
                        ^
                            mutex.c:19 : 3 : 附注：‘V’的上一个隐式声明在此
                            V(semid);
                        ^
                            [root@luckily sem]# vim mutex.c
                            [root@luckily sem]# gcc mutex.c
                            mutex.c:42 : 6 : 警告：与‘P’类型冲突[默认启用]
                            void P(int id) {
                            ^
                                mutex.c:12 : 3 : 附注：‘P’的上一个隐式声明在此
                                P(semid);
                            ^
                                mutex.c:51 : 6 : 警告：与‘V’类型冲突[默认启用]
                                void V(int id) {
                                ^
                                    mutex.c:19 : 3 : 附注：‘V’的上一个隐式声明在此
                                    V(semid);
                                ^
                                    [root@luckily sem]# vim mutex.c
                                    [root@luckily sem]# gcc mutex.c
                                    mutex.c:42 : 6 : 警告：与‘P’类型冲突[默认启用]
                                    void P(int id) {
                                    ^
                                        mutex.c:12 : 3 : 附注：‘P’的上一个隐式声明在此
                                        P(semid);
                                    ^
                                        mutex.c:51 : 6 : 警告：与‘V’类型冲突[默认启用]
                                        void V(int id) {
                                        ^
                                            mutex.c:19 : 3 : 附注：‘V’的上一个隐式声明在此
                                            V(semid);
                                        ^
                                            [root@luckily sem]# . / a.out
                                            xxooxxoox^ C
                                            [root@luckily sem]# 
