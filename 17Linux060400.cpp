//����˹����Ĳ������޸�

[root@luckily ~]# cd study
[root@luckily study]# ls
day01  day02  day03  day04  day05  day06  day07  day08  day09  day0a  day0b  day0c
[root@luckily study]# cd day0c
[root@luckily day0c]# ls
01.1.c  01.2.c  01.c  02.c  03.c  04.c  05.c  a.out  mykill  tetris.c
[root@luckily day0c]# vim keyboard.h
[root@luckily day0c]# vim keyboard.c
[root@luckily day0c]# vim tetris.c
[root@luckily day0c]# vim tetris.c
[root@luckily day0c]# gcc tetris.c - L - lkeyboard - I.
tetris.c:21 : 8 : ���󣺱�����t���г�ʼֵ�趨�����Ͳ���ȫ
struct data t = { .x = 5, .y = 5 };
^
tetris.c:21 : 8 : ���󣺳�ʼֵ�趨������δ֪���ֶΡ�x��
tetris.c : 21 : 8 : ���棺�ṹ��ʼֵ�趨�����ж���Ԫ��[Ĭ������]
tetris.c : 21 : 8 : ���棺(�ڡ�t���ĳ�ʼ������)[Ĭ������]
tetris.c : 21 : 8 : ���󣺳�ʼֵ�趨������δ֪���ֶΡ�y��
tetris.c : 21 : 8 : ���棺�ṹ��ʼֵ�趨�����ж���Ԫ��[Ĭ������]
tetris.c : 21 : 8 : ���棺(�ڡ�t���ĳ�ʼ������)[Ĭ������]
tetris.c : �ں�����set_back���� :
    tetris.c : 85 : 17 : ��������ָ����ȫ���͵�ָ��
    background[t->y + i][t->x + j] = 1;
^
tetris.c:85 : 25 : ��������ָ����ȫ���͵�ָ��
background[t->y + i][t->x + j] = 1;
^
tetris.c: �ں�����tetris_timer����:
tetris.c : 92 : 14 : ��������ָ����ȫ���͵�ָ��
drap_shape(t->x, t->y, shape_arr[0], BC);
^
tetris.c:92 : 20 : ��������ָ����ȫ���͵�ָ��
drap_shape(t->x, t->y, shape_arr[0], BC);
^
tetris.c:93 : 16 : ��������ָ����ȫ���͵�ָ��
if (can_move(t->x, t->y + 1, shape_arr[0])) {
    ^
        tetris.c:93 : 22 : ��������ָ����ȫ���͵�ָ��
        if (can_move(t->x, t->y + 1, shape_arr[0])) {
            ^
                tetris.c:94 : 4 : ��������ָ����ȫ���͵�ָ��
                t->y++;
            ^
                tetris.c:95 : 15 : ��������ָ����ȫ���͵�ָ��
                drap_shape(t->x, t->y, shape_arr[0], FC);
            ^
                tetris.c:95 : 21 : ��������ָ����ȫ���͵�ָ��
                drap_shape(t->x, t->y, shape_arr[0], FC);
            ^
                tetris.c:100 : 4 : ��������ָ����ȫ���͵�ָ��
                t->y = 0;
            ^
                tetris.c:101 : 4 : ��������ָ����ȫ���͵�ָ��
                t->x = 4;
            ^
                tetris.c:102 : 15 : ��������ָ����ȫ���͵�ָ��
                drap_shape(t->x, t->y, shape_arr[0], FC);
            ^
                tetris.c:102 : 21 : ��������ָ����ȫ���͵�ָ��
                drap_shape(t->x, t->y, shape_arr[0], FC);
            ^
                tetris.c: �ں�����tetris����:
            tetris.c : 130 : 15 : ��������ָ����ȫ���͵�ָ��
                drap_shape(t->x, t->y, shape_arr[0], BC);
            ^
                tetris.c:130 : 21 : ��������ָ����ȫ���͵�ָ��
                drap_shape(t->x, t->y, shape_arr[0], BC);
            ^
                tetris.c:132 : 17 : ��������ָ����ȫ���͵�ָ��
                if (can_move(t->x, t->y, shape_arr[0]) == 0) {
                    ^
                        tetris.c:132 : 23 : ��������ָ����ȫ���͵�ָ��
                        if (can_move(t->x, t->y, shape_arr[0]) == 0) {
                            ^
                                tetris.c:137 : 15 : ��������ָ����ȫ���͵�ָ��
                                drap_shape(t->x, t->y, shape_arr[0], FC);
                            ^
                                tetris.c:137 : 21 : ��������ָ����ȫ���͵�ָ��
                                drap_shape(t->x, t->y, shape_arr[0], FC);
                            ^
                                tetris.c:140 : 15 : ��������ָ����ȫ���͵�ָ��
                                drap_shape(t->x, t->y, shape_arr[0], BC);
                            ^
                                tetris.c:140 : 21 : ��������ָ����ȫ���͵�ָ��
                                drap_shape(t->x, t->y, shape_arr[0], BC);
                            ^
                                tetris.c:141 : 17 : ��������ָ����ȫ���͵�ָ��
                                if (can_move(t->x, t->y + 1, shape_arr[0])) {
                                    ^
                                        tetris.c:141 : 23 : ��������ָ����ȫ���͵�ָ��
                                        if (can_move(t->x, t->y + 1, shape_arr[0])) {
                                            ^
                                                tetris.c:142 : 5 : ��������ָ����ȫ���͵�ָ��
                                                t->y++;
                                            ^
                                                tetris.c:143 : 16 : ��������ָ����ȫ���͵�ָ��
                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                            ^
                                                tetris.c:143 : 22 : ��������ָ����ȫ���͵�ָ��
                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                            ^
                                                tetris.c:146 : 16 : ��������ָ����ȫ���͵�ָ��
                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                            ^
                                                tetris.c:146 : 22 : ��������ָ����ȫ���͵�ָ��
                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                            ^
                                                tetris.c:150 : 15 : ��������ָ����ȫ���͵�ָ��
                                                drap_shape(t->x, t->y, shape_arr[0], BC);
                                            ^
                                                tetris.c:150 : 21 : ��������ָ����ȫ���͵�ָ��
                                                drap_shape(t->x, t->y, shape_arr[0], BC);
                                            ^
                                                tetris.c:151 : 17 : ��������ָ����ȫ���͵�ָ��
                                                if (can_move(t->x - 1, t->y, shape_arr[0])) {
                                                    ^
                                                        tetris.c:151 : 27 : ��������ָ����ȫ���͵�ָ��
                                                        if (can_move(t->x - 1, t->y, shape_arr[0])) {
                                                            ^
                                                                tetris.c:152 : 5 : ��������ָ����ȫ���͵�ָ��
                                                                t->x--;
                                                            ^
                                                                tetris.c:153 : 16 : ��������ָ����ȫ���͵�ָ��
                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                            ^
                                                                tetris.c:153 : 22 : ��������ָ����ȫ���͵�ָ��
                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                            ^
                                                                tetris.c:156 : 16 : ��������ָ����ȫ���͵�ָ��
                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                            ^
                                                                tetris.c:156 : 22 : ��������ָ����ȫ���͵�ָ��
                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                            ^
                                                                tetris.c:160 : 15 : ��������ָ����ȫ���͵�ָ��
                                                                drap_shape(t->x, t->y, shape_arr[0], BC);
                                                            ^
                                                                tetris.c:160 : 21 : ��������ָ����ȫ���͵�ָ��
                                                                drap_shape(t->x, t->y, shape_arr[0], BC);
                                                            ^
                                                                tetris.c:161 : 17 : ��������ָ����ȫ���͵�ָ��
                                                                if (can_move(t->x + 1, t->y, shape_arr[0])) {
                                                                    ^
                                                                        tetris.c:161 : 27 : ��������ָ����ȫ���͵�ָ��
                                                                        if (can_move(t->x + 1, t->y, shape_arr[0])) {
                                                                            ^
                                                                                tetris.c:162 : 5 : ��������ָ����ȫ���͵�ָ��
                                                                                t->x++;
                                                                            ^
                                                                                tetris.c:163 : 16 : ��������ָ����ȫ���͵�ָ��
                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                            ^
                                                                                tetris.c:163 : 22 : ��������ָ����ȫ���͵�ָ��
                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                            ^
                                                                                tetris.c:166 : 16 : ��������ָ����ȫ���͵�ָ��
                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                            ^
                                                                                tetris.c:166 : 22 : ��������ָ����ȫ���͵�ָ��
                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                            ^
                                                                                [root@luckily day0c]# gcc - o keyboard.c
                                                                                gcc : ��������û�������ļ�
                                                                                �����жϡ�
                                                                                [root@luckily day0c]#  - shared - fPIC libkeybash : complete: -h : ��Чѡ��
                                                                                complete : �÷�:complete[-abcdefgjksuv][-pr][-DE][-o ѡ��][-A ����][-G ȫ��ģʽ][-W �����б�][-F ����][-C ����][-X ����ģʽ][-P ǰ׺][-S ��׺][���� ...]

                                                                                [root@luckily day0c]#  - shared - fPIC libkeyboard.so
                                                                                bash : -shared : δ�ҵ�����...
                                                                                [root@luckily day0c]#  - shared - fPIC libkeyboard.so keybash : complete: -h : ��Чѡ��
                                                                                complete : �÷�:complete[-abcdefgjksuv][-pr][-DE][-o ѡ��][-A ����][-G ȫ��ģʽ][-W �����б�][-F ����][-C ����][-X ����ģʽ][-P ǰ׺][-S ��׺][���� ...]

                                                                                [root@luckily day0c]# gcc - shared - fPIC libkeyboard.so keyboard.c
                                                                                gcc : ����libkeyboard.so��û���Ǹ��ļ���Ŀ¼
                                                                                [root@luckily day0c]# gcc - shared - fPIC - o  libkeyboard.so keyboard.c
                                                                                [root@luckily day0c]# ls
                                                                                01.1.c  01.c  03.c  05.c   keyboard.c  libkeyboard.so  tetris.c
                                                                                01.2.c  02.c  04.c  a.out  keyboard.h  mykill
                                                                                [root@luckily day0c]# gcc tetris.c - L - lkeyboard - I.
                                                                                tetris.c:21 : 8 : ���󣺱�����t���г�ʼֵ�趨�����Ͳ���ȫ
                                                                                struct data t = { .x = 5, .y = 5 };
                                                                            ^
                                                                                tetris.c:21 : 8 : ���󣺳�ʼֵ�趨������δ֪���ֶΡ�x��
                                                                                tetris.c : 21 : 8 : ���棺�ṹ��ʼֵ�趨�����ж���Ԫ��[Ĭ������]
                                                                                tetris.c : 21 : 8 : ���棺(�ڡ�t���ĳ�ʼ������)[Ĭ������]
                                                                                tetris.c : 21 : 8 : ���󣺳�ʼֵ�趨������δ֪���ֶΡ�y��
                                                                                tetris.c : 21 : 8 : ���棺�ṹ��ʼֵ�趨�����ж���Ԫ��[Ĭ������]
                                                                                tetris.c : 21 : 8 : ���棺(�ڡ�t���ĳ�ʼ������)[Ĭ������]
                                                                                tetris.c : �ں�����set_back���� :
                                                                                tetris.c : 85 : 17 : ��������ָ����ȫ���͵�ָ��
                                                                                background[t->y + i][t->x + j] = 1;
                                                                            ^
                                                                                tetris.c:85 : 25 : ��������ָ����ȫ���͵�ָ��
                                                                                background[t->y + i][t->x + j] = 1;
                                                                            ^
                                                                                tetris.c: �ں�����tetris_timer����:
                                                                            tetris.c : 92 : 14 : ��������ָ����ȫ���͵�ָ��
                                                                                drap_shape(t->x, t->y, shape_arr[0], BC);
                                                                            ^
                                                                                tetris.c:92 : 20 : ��������ָ����ȫ���͵�ָ��
                                                                                drap_shape(t->x, t->y, shape_arr[0], BC);
                                                                            ^
                                                                                tetris.c:93 : 16 : ��������ָ����ȫ���͵�ָ��
                                                                                if (can_move(t->x, t->y + 1, shape_arr[0])) {
                                                                                    ^
                                                                                        tetris.c:93 : 22 : ��������ָ����ȫ���͵�ָ��
                                                                                        if (can_move(t->x, t->y + 1, shape_arr[0])) {
                                                                                            ^
                                                                                                tetris.c:94 : 4 : ��������ָ����ȫ���͵�ָ��
                                                                                                t->y++;
                                                                                            ^
                                                                                                tetris.c:95 : 15 : ��������ָ����ȫ���͵�ָ��
                                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                                            ^
                                                                                                tetris.c:95 : 21 : ��������ָ����ȫ���͵�ָ��
                                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                                            ^
                                                                                                tetris.c:100 : 4 : ��������ָ����ȫ���͵�ָ��
                                                                                                t->y = 0;
                                                                                            ^
                                                                                                tetris.c:101 : 4 : ��������ָ����ȫ���͵�ָ��
                                                                                                t->x = 4;
                                                                                            ^
                                                                                                tetris.c:102 : 15 : ��������ָ����ȫ���͵�ָ��
                                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                                            ^
                                                                                                tetris.c:102 : 21 : ��������ָ����ȫ���͵�ָ��
                                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                                            ^
                                                                                                tetris.c: �ں�����tetris����:
                                                                                            tetris.c : 130 : 15 : ��������ָ����ȫ���͵�ָ��
                                                                                                drap_shape(t->x, t->y, shape_arr[0], BC);
                                                                                            ^
                                                                                                tetris.c:130 : 21 : ��������ָ����ȫ���͵�ָ��
                                                                                                drap_shape(t->x, t->y, shape_arr[0], BC);
                                                                                            ^
                                                                                                tetris.c:132 : 17 : ��������ָ����ȫ���͵�ָ��
                                                                                                if (can_move(t->x, t->y, shape_arr[0]) == 0) {
                                                                                                    ^
                                                                                                        tetris.c:132 : 23 : ��������ָ����ȫ���͵�ָ��
                                                                                                        if (can_move(t->x, t->y, shape_arr[0]) == 0) {
                                                                                                            ^
                                                                                                                tetris.c:137 : 15 : ��������ָ����ȫ���͵�ָ��
                                                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                                                            ^
                                                                                                                tetris.c:137 : 21 : ��������ָ����ȫ���͵�ָ��
                                                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                                                            ^
                                                                                                                tetris.c:140 : 15 : ��������ָ����ȫ���͵�ָ��
                                                                                                                drap_shape(t->x, t->y, shape_arr[0], BC);
                                                                                                            ^
                                                                                                                tetris.c:140 : 21 : ��������ָ����ȫ���͵�ָ��
                                                                                                                drap_shape(t->x, t->y, shape_arr[0], BC);
                                                                                                            ^
                                                                                                                tetris.c:141 : 17 : ��������ָ����ȫ���͵�ָ��
                                                                                                                if (can_move(t->x, t->y + 1, shape_arr[0])) {
                                                                                                                    ^
                                                                                                                        tetris.c:141 : 23 : ��������ָ����ȫ���͵�ָ��
                                                                                                                        if (can_move(t->x, t->y + 1, shape_arr[0])) {
                                                                                                                            ^
                                                                                                                                tetris.c:142 : 5 : ��������ָ����ȫ���͵�ָ��
                                                                                                                                t->y++;
                                                                                                                            ^
                                                                                                                                tetris.c:143 : 16 : ��������ָ����ȫ���͵�ָ��
                                                                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                                                                            ^
                                                                                                                                tetris.c:143 : 22 : ��������ָ����ȫ���͵�ָ��
                                                                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                                                                            ^
                                                                                                                                tetris.c:146 : 16 : ��������ָ����ȫ���͵�ָ��
                                                                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                                                                            ^
                                                                                                                                tetris.c:146 : 22 : ��������ָ����ȫ���͵�ָ��
                                                                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                                                                            ^
                                                                                                                                tetris.c:150 : 15 : ��������ָ����ȫ���͵�ָ��
                                                                                                                                drap_shape(t->x, t->y, shape_arr[0], BC);
                                                                                                                            ^
                                                                                                                                tetris.c:150 : 21 : ��������ָ����ȫ���͵�ָ��
                                                                                                                                drap_shape(t->x, t->y, shape_arr[0], BC);
                                                                                                                            ^
                                                                                                                                tetris.c:151 : 17 : ��������ָ����ȫ���͵�ָ��
                                                                                                                                if (can_move(t->x - 1, t->y, shape_arr[0])) {
                                                                                                                                    ^
                                                                                                                                        tetris.c:151 : 27 : ��������ָ����ȫ���͵�ָ��
                                                                                                                                        if (can_move(t->x - 1, t->y, shape_arr[0])) {
                                                                                                                                            ^
                                                                                                                                                tetris.c:152 : 5 : ��������ָ����ȫ���͵�ָ��
                                                                                                                                                t->x--;
                                                                                                                                            ^
                                                                                                                                                tetris.c:153 : 16 : ��������ָ����ȫ���͵�ָ��
                                                                                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                                                                                            ^
                                                                                                                                                tetris.c:153 : 22 : ��������ָ����ȫ���͵�ָ��
                                                                                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                                                                                            ^
                                                                                                                                                tetris.c:156 : 16 : ��������ָ����ȫ���͵�ָ��
                                                                                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                                                                                            ^
                                                                                                                                                tetris.c:156 : 22 : ��������ָ����ȫ���͵�ָ��
                                                                                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                                                                                            ^
                                                                                                                                                tetris.c:160 : 15 : ��������ָ����ȫ���͵�ָ��
                                                                                                                                                drap_shape(t->x, t->y, shape_arr[0], BC);
                                                                                                                                            ^
                                                                                                                                                tetris.c:160 : 21 : ��������ָ����ȫ���͵�ָ��
                                                                                                                                                drap_shape(t->x, t->y, shape_arr[0], BC);
                                                                                                                                            ^
                                                                                                                                                tetris.c:161 : 17 : ��������ָ����ȫ���͵�ָ��
                                                                                                                                                if (can_move(t->x + 1, t->y, shape_arr[0])) {
                                                                                                                                                    ^
                                                                                                                                                        tetris.c:161 : 27 : ��������ָ����ȫ���͵�ָ��
                                                                                                                                                        if (can_move(t->x + 1, t->y, shape_arr[0])) {
                                                                                                                                                            ^
                                                                                                                                                                tetris.c:162 : 5 : ��������ָ����ȫ���͵�ָ��
                                                                                                                                                                t->x++;
                                                                                                                                                            ^
                                                                                                                                                                tetris.c:163 : 16 : ��������ָ����ȫ���͵�ָ��
                                                                                                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                                                                                                            ^
                                                                                                                                                                tetris.c:163 : 22 : ��������ָ����ȫ���͵�ָ��
                                                                                                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                                                                                                            ^
                                                                                                                                                                tetris.c:166 : 16 : ��������ָ����ȫ���͵�ָ��
                                                                                                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                                                                                                            ^
                                                                                                                                                                tetris.c:166 : 22 : ��������ָ����ȫ���͵�ָ��
                                                                                                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                                                                                                            ^
                                                                                                                                                                [root@luckily day0c]# vim tetris.c
                                                                                                                                                                [root@luckily day0c]# gcc tetris.c - L - lkeyboard - I.
                                                                                                                                                                / tmp / ccvrHKfC.o���ں�����tetris_timer���У�
                                                                                                                                                                tetris.c:(.text + 0x554)���ԡ�drap_back��δ���������
                                                                                                                                                                / tmp / ccvrHKfC.o���ں�����handler_int���У�
                                                                                                                                                                tetris.c : (.text + 0x655)���ԡ�recover_keyboard��δ���������
                                                                                                                                                                / tmp / ccvrHKfC.o���ں�����tetris���У�
                                                                                                                                                                tetris.c : (.text + 0x74f)���ԡ�get_key��δ���������
                                                                                                                                                                tetris.c : (.text + 0x75c)���ԡ�is_up��δ���������
                                                                                                                                                                tetris.c : (.text + 0xe7e)���ԡ�is_down��δ���������
                                                                                                                                                                tetris.c : (.text + 0x1181)���ԡ�is_left��δ���������
                                                                                                                                                                tetris.c : (.text + 0x1482)���ԡ�is_right��δ���������
                                                                                                                                                                / tmp / ccvrHKfC.o���ں�����main���У�
                                                                                                                                                                tetris.c : (.text + 0x17ab)���ԡ�init_keyboard��δ���������
                                                                                                                                                                collect2 : ����ld ���� 1
                                                                                                                                                                [root@luckily day0c]# echo "PWD"
                                                                                                                                                                PWD
                                                                                                                                                                [root@luckily day0c]# pwd
                                                                                                                                                                / root / study / day0c
                                                                                                                                                                [root@luckily day0c]# echo 'PWD'
                                                                                                                                                                PWD
                                                                                                                                                                [root@luckily day0c]# echo 'pwd'
                                                                                                                                                                pwd
                                                                                                                                                                [root@luckily day0c]# echo 'PWD'
                                                                                                                                                                PWD
                                                                                                                                                                [root@luckily day0c]# echo '$PWD' > / etc / ld.so.conf.d /
                                                                                                                                                                bind - export - x86_64.conf             libiscsi - x86_64.conf
                                                                                                                                                                dyninst - x86_64.conf                 my.conf
                                                                                                                                                                kernel - 3.10.0 - 1062.el7.x86_64.conf  mysql - x86_64.conf
                                                                                                                                                                [root@luckily day0c]# echo '$PWD' > / etc / ld.so.conf.d / my.conf
                                                                                                                                                                [root@luckily day0c]# cat / etc / ld.so.conf.d / my.conf
                                                                                                                                                                $PWD
                                                                                                                                                                [root@luckily day0c]# echo '$PWD'
                                                                                                                                                                $PWD
                                                                                                                                                                [][][][][][][][][][]# echo "$PWD"
                                                                                                                                                                [][][][][][][][][][]
                                                                                                                                                                [][][][][][][][][][]# echo "$PWD" > / etc / ld.so.conf.d / my.conf
                                                                                                                                                                [][][][][][][][][][]# cat / etc / ld.so.conf.d / my.conf
                                                                                                                                                                [][][][][][][][][root@luckily day0c]# 
                                                                                                                                                                [root@luckily day0c]# ldconfig
                                                                                                                                                                [root@luckily day0c]# ls
                                                                                                                                                                [root@luckily day0c]# .c        keyboard.h      mykill
                                                                                                                                                                [root@luckily day0c]# yboard.c  libkeyboard.so  tetris.c
                                                                                                                                                                [][][][][][][][][][]# vim keyboard.h
                                                                                                                                                                [][][][][][][][][][]# gcc tetris.c - L. - lkyeboard - I.
                                                                                                                                                                [][][][][][][][][][] - lkyeboard
                                                                                                                                                                [][][][][][][][][][] �� 1
                                                                                                                                                                [][][][][][][][][][]# gcc tetris.c - L. - lkeyboard - I.
                                                                                                                                                                [][][][][][][][][][] ����tetris_timer���У�
                                                                                                                                                                [][][][][][][][][][]4)���ԡ�drap_back��δ���������
                                                                                                                                                                [][][][][][][][][][] �� 1
                                                                                                                                                                [][][][][][][][][][]# vim tetris.c
                                                                                                                                                                [][][][][][][][][][]# gcc tetris.c - L. - lkeyboard - I.
                                                                                                                                                                [][][][][][][][][][]��expected �� = ��, ��, ��, ��; ��, ��asm�� or ��__attribute__�� before ��_shape��
                                                                                                                                                                void draw _shape(int x, int y, struct shape p, int c) {
                                                                                                                                                                ^
                                                                                                                                                                    [root@luckily day0c]# vim tetris.c
                                                                                                                                                                    [root@luckily day0c]# gcc tetris.c - L. - lkeyboard - I.
                                                                                                                                                                    [root@luckily day0c]# . / a.out
