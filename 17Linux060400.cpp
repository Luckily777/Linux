//俄罗斯方块的操作和修改

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
tetris.c:21 : 8 : 错误：变量‘t’有初始值设定但类型不完全
struct data t = { .x = 5, .y = 5 };
^
tetris.c:21 : 8 : 错误：初始值设定项里有未知的字段‘x’
tetris.c : 21 : 8 : 警告：结构初始值设定项中有多余元素[默认启用]
tetris.c : 21 : 8 : 警告：(在‘t’的初始化附近)[默认启用]
tetris.c : 21 : 8 : 错误：初始值设定项里有未知的字段‘y’
tetris.c : 21 : 8 : 警告：结构初始值设定项中有多余元素[默认启用]
tetris.c : 21 : 8 : 警告：(在‘t’的初始化附近)[默认启用]
tetris.c : 在函数‘set_back’中 :
    tetris.c : 85 : 17 : 错误：提领指向不完全类型的指针
    background[t->y + i][t->x + j] = 1;
^
tetris.c:85 : 25 : 错误：提领指向不完全类型的指针
background[t->y + i][t->x + j] = 1;
^
tetris.c: 在函数‘tetris_timer’中:
tetris.c : 92 : 14 : 错误：提领指向不完全类型的指针
drap_shape(t->x, t->y, shape_arr[0], BC);
^
tetris.c:92 : 20 : 错误：提领指向不完全类型的指针
drap_shape(t->x, t->y, shape_arr[0], BC);
^
tetris.c:93 : 16 : 错误：提领指向不完全类型的指针
if (can_move(t->x, t->y + 1, shape_arr[0])) {
    ^
        tetris.c:93 : 22 : 错误：提领指向不完全类型的指针
        if (can_move(t->x, t->y + 1, shape_arr[0])) {
            ^
                tetris.c:94 : 4 : 错误：提领指向不完全类型的指针
                t->y++;
            ^
                tetris.c:95 : 15 : 错误：提领指向不完全类型的指针
                drap_shape(t->x, t->y, shape_arr[0], FC);
            ^
                tetris.c:95 : 21 : 错误：提领指向不完全类型的指针
                drap_shape(t->x, t->y, shape_arr[0], FC);
            ^
                tetris.c:100 : 4 : 错误：提领指向不完全类型的指针
                t->y = 0;
            ^
                tetris.c:101 : 4 : 错误：提领指向不完全类型的指针
                t->x = 4;
            ^
                tetris.c:102 : 15 : 错误：提领指向不完全类型的指针
                drap_shape(t->x, t->y, shape_arr[0], FC);
            ^
                tetris.c:102 : 21 : 错误：提领指向不完全类型的指针
                drap_shape(t->x, t->y, shape_arr[0], FC);
            ^
                tetris.c: 在函数‘tetris’中:
            tetris.c : 130 : 15 : 错误：提领指向不完全类型的指针
                drap_shape(t->x, t->y, shape_arr[0], BC);
            ^
                tetris.c:130 : 21 : 错误：提领指向不完全类型的指针
                drap_shape(t->x, t->y, shape_arr[0], BC);
            ^
                tetris.c:132 : 17 : 错误：提领指向不完全类型的指针
                if (can_move(t->x, t->y, shape_arr[0]) == 0) {
                    ^
                        tetris.c:132 : 23 : 错误：提领指向不完全类型的指针
                        if (can_move(t->x, t->y, shape_arr[0]) == 0) {
                            ^
                                tetris.c:137 : 15 : 错误：提领指向不完全类型的指针
                                drap_shape(t->x, t->y, shape_arr[0], FC);
                            ^
                                tetris.c:137 : 21 : 错误：提领指向不完全类型的指针
                                drap_shape(t->x, t->y, shape_arr[0], FC);
                            ^
                                tetris.c:140 : 15 : 错误：提领指向不完全类型的指针
                                drap_shape(t->x, t->y, shape_arr[0], BC);
                            ^
                                tetris.c:140 : 21 : 错误：提领指向不完全类型的指针
                                drap_shape(t->x, t->y, shape_arr[0], BC);
                            ^
                                tetris.c:141 : 17 : 错误：提领指向不完全类型的指针
                                if (can_move(t->x, t->y + 1, shape_arr[0])) {
                                    ^
                                        tetris.c:141 : 23 : 错误：提领指向不完全类型的指针
                                        if (can_move(t->x, t->y + 1, shape_arr[0])) {
                                            ^
                                                tetris.c:142 : 5 : 错误：提领指向不完全类型的指针
                                                t->y++;
                                            ^
                                                tetris.c:143 : 16 : 错误：提领指向不完全类型的指针
                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                            ^
                                                tetris.c:143 : 22 : 错误：提领指向不完全类型的指针
                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                            ^
                                                tetris.c:146 : 16 : 错误：提领指向不完全类型的指针
                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                            ^
                                                tetris.c:146 : 22 : 错误：提领指向不完全类型的指针
                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                            ^
                                                tetris.c:150 : 15 : 错误：提领指向不完全类型的指针
                                                drap_shape(t->x, t->y, shape_arr[0], BC);
                                            ^
                                                tetris.c:150 : 21 : 错误：提领指向不完全类型的指针
                                                drap_shape(t->x, t->y, shape_arr[0], BC);
                                            ^
                                                tetris.c:151 : 17 : 错误：提领指向不完全类型的指针
                                                if (can_move(t->x - 1, t->y, shape_arr[0])) {
                                                    ^
                                                        tetris.c:151 : 27 : 错误：提领指向不完全类型的指针
                                                        if (can_move(t->x - 1, t->y, shape_arr[0])) {
                                                            ^
                                                                tetris.c:152 : 5 : 错误：提领指向不完全类型的指针
                                                                t->x--;
                                                            ^
                                                                tetris.c:153 : 16 : 错误：提领指向不完全类型的指针
                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                            ^
                                                                tetris.c:153 : 22 : 错误：提领指向不完全类型的指针
                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                            ^
                                                                tetris.c:156 : 16 : 错误：提领指向不完全类型的指针
                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                            ^
                                                                tetris.c:156 : 22 : 错误：提领指向不完全类型的指针
                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                            ^
                                                                tetris.c:160 : 15 : 错误：提领指向不完全类型的指针
                                                                drap_shape(t->x, t->y, shape_arr[0], BC);
                                                            ^
                                                                tetris.c:160 : 21 : 错误：提领指向不完全类型的指针
                                                                drap_shape(t->x, t->y, shape_arr[0], BC);
                                                            ^
                                                                tetris.c:161 : 17 : 错误：提领指向不完全类型的指针
                                                                if (can_move(t->x + 1, t->y, shape_arr[0])) {
                                                                    ^
                                                                        tetris.c:161 : 27 : 错误：提领指向不完全类型的指针
                                                                        if (can_move(t->x + 1, t->y, shape_arr[0])) {
                                                                            ^
                                                                                tetris.c:162 : 5 : 错误：提领指向不完全类型的指针
                                                                                t->x++;
                                                                            ^
                                                                                tetris.c:163 : 16 : 错误：提领指向不完全类型的指针
                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                            ^
                                                                                tetris.c:163 : 22 : 错误：提领指向不完全类型的指针
                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                            ^
                                                                                tetris.c:166 : 16 : 错误：提领指向不完全类型的指针
                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                            ^
                                                                                tetris.c:166 : 22 : 错误：提领指向不完全类型的指针
                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                            ^
                                                                                [root@luckily day0c]# gcc - o keyboard.c
                                                                                gcc : 致命错误：没有输入文件
                                                                                编译中断。
                                                                                [root@luckily day0c]#  - shared - fPIC libkeybash : complete: -h : 无效选项
                                                                                complete : 用法:complete[-abcdefgjksuv][-pr][-DE][-o 选项][-A 动作][-G 全局模式][-W 词语列表][-F 函数][-C 命令][-X 过滤模式][-P 前缀][-S 后缀][名称 ...]

                                                                                [root@luckily day0c]#  - shared - fPIC libkeyboard.so
                                                                                bash : -shared : 未找到命令...
                                                                                [root@luckily day0c]#  - shared - fPIC libkeyboard.so keybash : complete: -h : 无效选项
                                                                                complete : 用法:complete[-abcdefgjksuv][-pr][-DE][-o 选项][-A 动作][-G 全局模式][-W 词语列表][-F 函数][-C 命令][-X 过滤模式][-P 前缀][-S 后缀][名称 ...]

                                                                                [root@luckily day0c]# gcc - shared - fPIC libkeyboard.so keyboard.c
                                                                                gcc : 错误：libkeyboard.so：没有那个文件或目录
                                                                                [root@luckily day0c]# gcc - shared - fPIC - o  libkeyboard.so keyboard.c
                                                                                [root@luckily day0c]# ls
                                                                                01.1.c  01.c  03.c  05.c   keyboard.c  libkeyboard.so  tetris.c
                                                                                01.2.c  02.c  04.c  a.out  keyboard.h  mykill
                                                                                [root@luckily day0c]# gcc tetris.c - L - lkeyboard - I.
                                                                                tetris.c:21 : 8 : 错误：变量‘t’有初始值设定但类型不完全
                                                                                struct data t = { .x = 5, .y = 5 };
                                                                            ^
                                                                                tetris.c:21 : 8 : 错误：初始值设定项里有未知的字段‘x’
                                                                                tetris.c : 21 : 8 : 警告：结构初始值设定项中有多余元素[默认启用]
                                                                                tetris.c : 21 : 8 : 警告：(在‘t’的初始化附近)[默认启用]
                                                                                tetris.c : 21 : 8 : 错误：初始值设定项里有未知的字段‘y’
                                                                                tetris.c : 21 : 8 : 警告：结构初始值设定项中有多余元素[默认启用]
                                                                                tetris.c : 21 : 8 : 警告：(在‘t’的初始化附近)[默认启用]
                                                                                tetris.c : 在函数‘set_back’中 :
                                                                                tetris.c : 85 : 17 : 错误：提领指向不完全类型的指针
                                                                                background[t->y + i][t->x + j] = 1;
                                                                            ^
                                                                                tetris.c:85 : 25 : 错误：提领指向不完全类型的指针
                                                                                background[t->y + i][t->x + j] = 1;
                                                                            ^
                                                                                tetris.c: 在函数‘tetris_timer’中:
                                                                            tetris.c : 92 : 14 : 错误：提领指向不完全类型的指针
                                                                                drap_shape(t->x, t->y, shape_arr[0], BC);
                                                                            ^
                                                                                tetris.c:92 : 20 : 错误：提领指向不完全类型的指针
                                                                                drap_shape(t->x, t->y, shape_arr[0], BC);
                                                                            ^
                                                                                tetris.c:93 : 16 : 错误：提领指向不完全类型的指针
                                                                                if (can_move(t->x, t->y + 1, shape_arr[0])) {
                                                                                    ^
                                                                                        tetris.c:93 : 22 : 错误：提领指向不完全类型的指针
                                                                                        if (can_move(t->x, t->y + 1, shape_arr[0])) {
                                                                                            ^
                                                                                                tetris.c:94 : 4 : 错误：提领指向不完全类型的指针
                                                                                                t->y++;
                                                                                            ^
                                                                                                tetris.c:95 : 15 : 错误：提领指向不完全类型的指针
                                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                                            ^
                                                                                                tetris.c:95 : 21 : 错误：提领指向不完全类型的指针
                                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                                            ^
                                                                                                tetris.c:100 : 4 : 错误：提领指向不完全类型的指针
                                                                                                t->y = 0;
                                                                                            ^
                                                                                                tetris.c:101 : 4 : 错误：提领指向不完全类型的指针
                                                                                                t->x = 4;
                                                                                            ^
                                                                                                tetris.c:102 : 15 : 错误：提领指向不完全类型的指针
                                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                                            ^
                                                                                                tetris.c:102 : 21 : 错误：提领指向不完全类型的指针
                                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                                            ^
                                                                                                tetris.c: 在函数‘tetris’中:
                                                                                            tetris.c : 130 : 15 : 错误：提领指向不完全类型的指针
                                                                                                drap_shape(t->x, t->y, shape_arr[0], BC);
                                                                                            ^
                                                                                                tetris.c:130 : 21 : 错误：提领指向不完全类型的指针
                                                                                                drap_shape(t->x, t->y, shape_arr[0], BC);
                                                                                            ^
                                                                                                tetris.c:132 : 17 : 错误：提领指向不完全类型的指针
                                                                                                if (can_move(t->x, t->y, shape_arr[0]) == 0) {
                                                                                                    ^
                                                                                                        tetris.c:132 : 23 : 错误：提领指向不完全类型的指针
                                                                                                        if (can_move(t->x, t->y, shape_arr[0]) == 0) {
                                                                                                            ^
                                                                                                                tetris.c:137 : 15 : 错误：提领指向不完全类型的指针
                                                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                                                            ^
                                                                                                                tetris.c:137 : 21 : 错误：提领指向不完全类型的指针
                                                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                                                            ^
                                                                                                                tetris.c:140 : 15 : 错误：提领指向不完全类型的指针
                                                                                                                drap_shape(t->x, t->y, shape_arr[0], BC);
                                                                                                            ^
                                                                                                                tetris.c:140 : 21 : 错误：提领指向不完全类型的指针
                                                                                                                drap_shape(t->x, t->y, shape_arr[0], BC);
                                                                                                            ^
                                                                                                                tetris.c:141 : 17 : 错误：提领指向不完全类型的指针
                                                                                                                if (can_move(t->x, t->y + 1, shape_arr[0])) {
                                                                                                                    ^
                                                                                                                        tetris.c:141 : 23 : 错误：提领指向不完全类型的指针
                                                                                                                        if (can_move(t->x, t->y + 1, shape_arr[0])) {
                                                                                                                            ^
                                                                                                                                tetris.c:142 : 5 : 错误：提领指向不完全类型的指针
                                                                                                                                t->y++;
                                                                                                                            ^
                                                                                                                                tetris.c:143 : 16 : 错误：提领指向不完全类型的指针
                                                                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                                                                            ^
                                                                                                                                tetris.c:143 : 22 : 错误：提领指向不完全类型的指针
                                                                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                                                                            ^
                                                                                                                                tetris.c:146 : 16 : 错误：提领指向不完全类型的指针
                                                                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                                                                            ^
                                                                                                                                tetris.c:146 : 22 : 错误：提领指向不完全类型的指针
                                                                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                                                                            ^
                                                                                                                                tetris.c:150 : 15 : 错误：提领指向不完全类型的指针
                                                                                                                                drap_shape(t->x, t->y, shape_arr[0], BC);
                                                                                                                            ^
                                                                                                                                tetris.c:150 : 21 : 错误：提领指向不完全类型的指针
                                                                                                                                drap_shape(t->x, t->y, shape_arr[0], BC);
                                                                                                                            ^
                                                                                                                                tetris.c:151 : 17 : 错误：提领指向不完全类型的指针
                                                                                                                                if (can_move(t->x - 1, t->y, shape_arr[0])) {
                                                                                                                                    ^
                                                                                                                                        tetris.c:151 : 27 : 错误：提领指向不完全类型的指针
                                                                                                                                        if (can_move(t->x - 1, t->y, shape_arr[0])) {
                                                                                                                                            ^
                                                                                                                                                tetris.c:152 : 5 : 错误：提领指向不完全类型的指针
                                                                                                                                                t->x--;
                                                                                                                                            ^
                                                                                                                                                tetris.c:153 : 16 : 错误：提领指向不完全类型的指针
                                                                                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                                                                                            ^
                                                                                                                                                tetris.c:153 : 22 : 错误：提领指向不完全类型的指针
                                                                                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                                                                                            ^
                                                                                                                                                tetris.c:156 : 16 : 错误：提领指向不完全类型的指针
                                                                                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                                                                                            ^
                                                                                                                                                tetris.c:156 : 22 : 错误：提领指向不完全类型的指针
                                                                                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                                                                                            ^
                                                                                                                                                tetris.c:160 : 15 : 错误：提领指向不完全类型的指针
                                                                                                                                                drap_shape(t->x, t->y, shape_arr[0], BC);
                                                                                                                                            ^
                                                                                                                                                tetris.c:160 : 21 : 错误：提领指向不完全类型的指针
                                                                                                                                                drap_shape(t->x, t->y, shape_arr[0], BC);
                                                                                                                                            ^
                                                                                                                                                tetris.c:161 : 17 : 错误：提领指向不完全类型的指针
                                                                                                                                                if (can_move(t->x + 1, t->y, shape_arr[0])) {
                                                                                                                                                    ^
                                                                                                                                                        tetris.c:161 : 27 : 错误：提领指向不完全类型的指针
                                                                                                                                                        if (can_move(t->x + 1, t->y, shape_arr[0])) {
                                                                                                                                                            ^
                                                                                                                                                                tetris.c:162 : 5 : 错误：提领指向不完全类型的指针
                                                                                                                                                                t->x++;
                                                                                                                                                            ^
                                                                                                                                                                tetris.c:163 : 16 : 错误：提领指向不完全类型的指针
                                                                                                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                                                                                                            ^
                                                                                                                                                                tetris.c:163 : 22 : 错误：提领指向不完全类型的指针
                                                                                                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                                                                                                            ^
                                                                                                                                                                tetris.c:166 : 16 : 错误：提领指向不完全类型的指针
                                                                                                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                                                                                                            ^
                                                                                                                                                                tetris.c:166 : 22 : 错误：提领指向不完全类型的指针
                                                                                                                                                                drap_shape(t->x, t->y, shape_arr[0], FC);
                                                                                                                                                            ^
                                                                                                                                                                [root@luckily day0c]# vim tetris.c
                                                                                                                                                                [root@luckily day0c]# gcc tetris.c - L - lkeyboard - I.
                                                                                                                                                                / tmp / ccvrHKfC.o：在函数‘tetris_timer’中：
                                                                                                                                                                tetris.c:(.text + 0x554)：对‘drap_back’未定义的引用
                                                                                                                                                                / tmp / ccvrHKfC.o：在函数‘handler_int’中：
                                                                                                                                                                tetris.c : (.text + 0x655)：对‘recover_keyboard’未定义的引用
                                                                                                                                                                / tmp / ccvrHKfC.o：在函数‘tetris’中：
                                                                                                                                                                tetris.c : (.text + 0x74f)：对‘get_key’未定义的引用
                                                                                                                                                                tetris.c : (.text + 0x75c)：对‘is_up’未定义的引用
                                                                                                                                                                tetris.c : (.text + 0xe7e)：对‘is_down’未定义的引用
                                                                                                                                                                tetris.c : (.text + 0x1181)：对‘is_left’未定义的引用
                                                                                                                                                                tetris.c : (.text + 0x1482)：对‘is_right’未定义的引用
                                                                                                                                                                / tmp / ccvrHKfC.o：在函数‘main’中：
                                                                                                                                                                tetris.c : (.text + 0x17ab)：对‘init_keyboard’未定义的引用
                                                                                                                                                                collect2 : 错误：ld 返回 1
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
                                                                                                                                                                [][][][][][][][][][] 回 1
                                                                                                                                                                [][][][][][][][][][]# gcc tetris.c - L. - lkeyboard - I.
                                                                                                                                                                [][][][][][][][][][] 数‘tetris_timer’中：
                                                                                                                                                                [][][][][][][][][][]4)：对‘drap_back’未定义的引用
                                                                                                                                                                [][][][][][][][][][] 回 1
                                                                                                                                                                [][][][][][][][][][]# vim tetris.c
                                                                                                                                                                [][][][][][][][][][]# gcc tetris.c - L. - lkeyboard - I.
                                                                                                                                                                [][][][][][][][][][]：expected ‘ = ’, ‘, ’, ‘; ’, ‘asm’ or ‘__attribute__’ before ‘_shape’
                                                                                                                                                                void draw _shape(int x, int y, struct shape p, int c) {
                                                                                                                                                                ^
                                                                                                                                                                    [root@luckily day0c]# vim tetris.c
                                                                                                                                                                    [root@luckily day0c]# gcc tetris.c - L. - lkeyboard - I.
                                                                                                                                                                    [root@luckily day0c]# . / a.out
