[root@luckily day11]# vim shmsend.c
[root@luckily day11]# vim shmread.c
[root@luckily day11]# gcc shmread.c - p read
gcc : ����read��û���Ǹ��ļ���Ŀ¼
[root@luckily day11]# gcc shmread.c - o read
[root@luckily day11]# mkdir sem
[root@luckily day11]# cd sem
[root@luckily sem]# ls
[root@luckily sem]# vim semcreat.c
[root@luckily sem]# gcc semcreat.c
[root@luckily sem]# . / a, out
bash : . / a, out : û���Ǹ��ļ���Ŀ¼
[root@luckily sem]# . / a.out
creat ok
[root@luckily sem]# ipcs - m

------------�����ڴ��--------------
��        shmid      ӵ����  Ȩ��     �ֽ�     nattch     ״̬
0x00000000 294912     root       777        16384      1          Ŀ��
0x00000000 327681     root       777        2129920    2          Ŀ��
0x00000000 491522     root       600        524288     2          Ŀ��
0x00000000 524291     root       777        2129920    2          Ŀ��
0x00000000 622596     root       600        524288     2          Ŀ��
0x00000000 655365     root       600        524288     2          Ŀ��
0x00000000 786438     root       600        16777216   2          Ŀ��
0x00000000 819207     root       600        524288     2          Ŀ��
0x00000000 851976     root       777        1916928    2          Ŀ��
0x000004d2 884745     root       644        4          0

[root@luckily sem]# vim setval.v
[root@luckily sem]# rm - rf setval.v
[root@luckily sem]# ls
a.out  semcreat.c
[root@luckily sem]# vim setval.c
[root@luckily sem]# gcc setval.c
/ tmp / ccP1hqnD.o���ں�����main���У�
setval.c:(.text + 0x40)���ԡ�scafn��δ���������
collect2 : ����ld ���� 1
[root@luckily sem]# vim setval.c
[root@luckily sem]# gcc setval.c - osetval
[root@luckily sem]# . / setval
val : 5
[root@luckily sem]# vim getval.c
[root@luckily sem]# make getval.c
make : �ԡ�getval.c���������κ��¡�
[root@luckily sem]# make getval
cc     getval.c - o getval
[root@luckily sem]# ls
getval  getval.c  semcreat.c  setval  setval.c
[root@luckily sem]# . / getval
5
[root@luckily sem]# vim pv.c
[root@luckily sem]# gcc pv.c - pv
gcc : ����unrecognized command line option �� - pv��
[root@luckily sem]# gcc pv.c - opv
[root@luckily sem]# . / pv
[root@luckily sem]# . / getval
4
[root@luckily sem]# vim p.c
[root@luckily sem]# rm pv.c
rm���Ƿ�ɾ����ͨ�ļ� "pv.c"��y
[root@luckily sem]# vim v.c
[root@luckily sem]# gcc v.c - ov
[root@luckily sem]# . / v
[root@luckily sem]# . / getval
5
[root@luckily sem]# ipcs - m

------------�����ڴ��--------------
��        shmid      ӵ����  Ȩ��     �ֽ�     nattch     ״̬
0x00000000 294912     root       777        16384      1          Ŀ��
0x00000000 327681     root       777        2129920    2          Ŀ��
0x00000000 491522     root       600        524288     2          Ŀ��
0x00000000 524291     root       777        2129920    2          Ŀ��
0x00000000 622596     root       600        524288     2          Ŀ��
0x00000000 655365     root       600        524288     2          Ŀ��
0x00000000 786438     root       600        16777216   2          Ŀ��
0x00000000 819207     root       600        524288     2          Ŀ��
0x00000000 851976     root       777        1916928    2          Ŀ��
0x000004d2 884745     root       644        4          0

[root@luckily sem]# ipcrm - S 1234
[root@luckily sem]# ipcs - m

------------�����ڴ��--------------
��        shmid      ӵ����  Ȩ��     �ֽ�     nattch     ״̬
0x00000000 294912     root       777        16384      1          Ŀ��
0x00000000 327681     root       777        2129920    2          Ŀ��
0x00000000 491522     root       600        524288     2          Ŀ��
0x00000000 524291     root       777        2129920    2          Ŀ��
0x00000000 622596     root       600        524288     2          Ŀ��
0x00000000 655365     root       600        524288     2          Ŀ��
0x00000000 786438     root       600        16777216   2          Ŀ��
0x00000000 819207     root       600        524288     2          Ŀ��
0x00000000 851976     root       777        1916928    2          Ŀ��
0x000004d2 884745     root       644        4          0

[root@luckily sem]# ipcs

-------- - ��Ϣ����---------- -
��        msqid      ӵ����  Ȩ��     �����ֽ��� ��Ϣ

------------�����ڴ��--------------
��        shmid      ӵ����  Ȩ��     �ֽ�     nattch     ״̬
0x00000000 294912     root       777        16384      1          Ŀ��
0x00000000 327681     root       777        2129920    2          Ŀ��
0x00000000 491522     root       600        524288     2          Ŀ��
0x00000000 524291     root       777        2129920    2          Ŀ��
0x00000000 622596     root       600        524288     2          Ŀ��
0x00000000 655365     root       600        524288     2          Ŀ��
0x00000000 786438     root       600        16777216   2          Ŀ��
0x00000000 819207     root       600        524288     2          Ŀ��
0x00000000 851976     root       777        1916928    2          Ŀ��
0x000004d2 884745     root       644        4          0

-------- - �ź�������---------- -
��        semid      ӵ����  Ȩ��     nsems

[root@luckily sem]# vim mutex.c
[root@luckily sem]# gcc mutex.c
/ tmp / ccmP8bzp.o���ں�����main���У�
mutex.c:(.text + 0x13b)���ԡ�print_char��δ���������
mutex.c : (.text + 0x14c)���ԡ�print_char��δ���������
collect2 : ����ld ���� 1
[root@luckily sem]# vim mutex.c
[root@luckily sem]# gcc mutex.c
[root@luckily sem]# . / a.out
xxoooxxoooxxox ^ C
[root@luckily sem]# vim mutex.c
[root@luckily sem]# gcc mutex.c
mutex.c: �ں�����sem_setval����:
mutex.c : 36 : 14 : ���󣺡�su���Ĵ洢��Сδ֪
union semun su;
^
mutex.c: ���ļ�������
mutex.c : 42 : 6 : ���棺�롮p�����ͳ�ͻ[Ĭ������]
void p(int id) {
    ^
        mutex.c:12 : 3 : ��ע����p������һ����ʽ�����ڴ�
        p(semid);
    ^
        mutex.c:51 : 6 : ���棺�롮v�����ͳ�ͻ[Ĭ������]
        void v(int id) {
        ^
            mutex.c:19 : 3 : ��ע����v������һ����ʽ�����ڴ�
            v(semid);
        ^
            [root@luckily sem]# vim mutex.c
            [root@luckily sem]# gcc mutex.c
            mutex.c: �ں�����sem_setval����:
        mutex.c : 36 : 14 : ���󣺡�su���Ĵ洢��Сδ֪
            union semun su;
        ^
            mutex.c: ���ļ�������
            mutex.c : 42 : 6 : ���棺�롮P�����ͳ�ͻ[Ĭ������]
            void P(int id) {
            ^
                mutex.c:12 : 3 : ��ע����P������һ����ʽ�����ڴ�
                P(semid);
            ^
                mutex.c:51 : 6 : ���棺�롮V�����ͳ�ͻ[Ĭ������]
                void V(int id) {
                ^
                    mutex.c:19 : 3 : ��ע����V������һ����ʽ�����ڴ�
                    V(semid);
                ^
                    [root@luckily sem]# vim mutex.c
                    [root@luckily sem]# gcc mutex.c
                    mutex.c: �ں�����sem_setval����:
                mutex.c : 36 : 14 : ���󣺡�su���Ĵ洢��Сδ֪
                    union semun su;
                ^
                    mutex.c: ���ļ�������
                    mutex.c : 42 : 6 : ���棺�롮P�����ͳ�ͻ[Ĭ������]
                    void P(int id) {
                    ^
                        mutex.c:12 : 3 : ��ע����P������һ����ʽ�����ڴ�
                        P(semid);
                    ^
                        mutex.c:51 : 6 : ���棺�롮V�����ͳ�ͻ[Ĭ������]
                        void V(int id) {
                        ^
                            mutex.c:19 : 3 : ��ע����V������һ����ʽ�����ڴ�
                            V(semid);
                        ^
                            [root@luckily sem]# vim mutex.c
                            [root@luckily sem]# gcc mutex.c
                            mutex.c:42 : 6 : ���棺�롮P�����ͳ�ͻ[Ĭ������]
                            void P(int id) {
                            ^
                                mutex.c:12 : 3 : ��ע����P������һ����ʽ�����ڴ�
                                P(semid);
                            ^
                                mutex.c:51 : 6 : ���棺�롮V�����ͳ�ͻ[Ĭ������]
                                void V(int id) {
                                ^
                                    mutex.c:19 : 3 : ��ע����V������һ����ʽ�����ڴ�
                                    V(semid);
                                ^
                                    [root@luckily sem]# vim mutex.c
                                    [root@luckily sem]# gcc mutex.c
                                    mutex.c:42 : 6 : ���棺�롮P�����ͳ�ͻ[Ĭ������]
                                    void P(int id) {
                                    ^
                                        mutex.c:12 : 3 : ��ע����P������һ����ʽ�����ڴ�
                                        P(semid);
                                    ^
                                        mutex.c:51 : 6 : ���棺�롮V�����ͳ�ͻ[Ĭ������]
                                        void V(int id) {
                                        ^
                                            mutex.c:19 : 3 : ��ע����V������һ����ʽ�����ڴ�
                                            V(semid);
                                        ^
                                            [root@luckily sem]# . / a.out
                                            xxooxxoox^ C
                                            [root@luckily sem]# 
