第八节课 第一个小时的操作代码


[root@luckily ~]# cd study
[root@luckily study]# ls
day01  day02  day03  day04
[root@luckily study]# mk day05
bash : mk: 未找到命令...
[root@luckily study]# mkdir day05
[root@luckily study]# ls
day01  day02  day03  day04  day05
[root@luckily study]# cd day05
[root@luckily day05]# vim 8Linux051001.c
[root@luckily day05]# gcc 8Linux051001.c
8Linux051001.c: 在函数‘main’中:
8Linux051001.c : 5 : 2 : 错误：‘pid_pid’未声明(在此函数内第一次使用)
pid_pid = fork();
^
8Linux051001.c:5 : 2 : 附注：每个未声明的标识符在其出现的函数内只报告一次
8Linux051001.c : 6 : 9 : 错误：‘pid’未声明(在此函数内第一次使用)
switch (pid) {
    ^
        [root@luckily day05]# vim 8Linux051001.c
        [root@luckily day05]# gcc 8Linux051001.c
        [root@luckily day05]# . / a.out
        parent : &p
        child : 0x4005bd
        [root@luckily day05]# vim 8Linux051001.c
        [root@luckily day05]# gcc 8Linux051001.c
        [root@luckily day05]# . / a.out
        parent : 0x4005bd
        child : 0x4005bd
        [root@luckily day05]# vim 8Linux051001.c
        [root@luckily day05]# gcc 8Linux051001.c
        8Linux051001.c: 在函数‘main’中:
    8Linux051001.c : 12 : 45 : 错误：‘d_data’未声明(在此函数内第一次使用)
        printf("child : %p,&g_data = %p\n", &main, &d_data);
    ^
        8Linux051001.c:12 : 45 : 附注：每个未声明的标识符在其出现的函数内只报告一次
        [root@luckily day05]# vim 8Linux051001.c
        [root@luckily day05]# gcc 8Linux051001.c
        [root@luckily day05]# . / a.out
        parent : 0x4005bd, & g_data = 0x601044
        child : 0x4005bd, & g_data = 0x601044
        [root@luckily day05]# vim 8Linux051001.c
        [root@luckily day05]# gcc 8Linux051001.c
        [root@luckily day05]# . / a.out
        child : 0x40060d, & g_data = 0x60104c, g_data = 200
        parent : 0x40060d, & g_data = 0x60104c, g_data = 100
        [root@luckily day05]# name = "苍老师"
        bash: name: 未找到命令...
        [root@luckily day05]# name = "苍老师"
        [root@luckily day05]# echo $name
        苍老师
        [root@luckily day05]# echp "$name 属于世界的"
        bash: echp: 未找到命令...
        [root@luckily day05]# echo "$name 属于世界的"
        苍老师 属于世界的
        [root@luckily day05]# pstree | grep - A 2 - B 2 "bash"
        | -gnome - keyring - d-- - 3 * [{gnome - keyring - d}]
        | -gnome - shell - cal-- - 5 * [{gnome - shell - cal}]
        | -gnome - terminal-- + -bash - +-grep
        |                 |      `-pstree
        |                 |-gnome - pty - helpe
        [root@luckily day05]# pstree | grep - A 2 - B 2 "bash"
        | -gnome - keyring - d-- - 3 * [{gnome - keyring - d}]
        | -gnome - shell - cal-- - 5 * [{gnome - shell - cal}]
        | -gnome - terminal-- + -bash - +-grep
        |                 |      `-pstree
        |                 |-gnome - pty - helpe
        [root@luckily day05]# bash
        [root@luckily day05]# pstree | grep - A 2 - B 2 "bash"
        | -gnome - keyring - d-- - 3 * [{gnome - keyring - d}]
        | -gnome - shell - cal-- - 5 * [{gnome - shell - cal}]
        | -gnome - terminal-- + -bash-- - bash - +-grep
        |                 |             `-pstree
        |                 |-gnome - pty - helpe
        [root@luckily day05]# echo $name

        [root@luckily day05]# exit
        exit
        [root@luckily day05]# pstree | grep - A 2 - B 2 "bash"
        | -gnome - keyring - d-- - 3 * [{gnome - keyring - d}]
        | -gnome - shell - cal-- - 5 * [{gnome - shell - cal}]
        | -gnome - terminal-- + -bash - +-grep
        |                 |      `-pstree
        |                 |-gnome - pty - helpe
        [root@luckily day05]# echo $name
        苍老师
        [root@luckily day05]# export name
        [root@luckily day05]# bash
        [root@luckily day05]# pstree | grep - A 2 - B 2 "bash"
        | -gnome - keyring - d-- - 3 * [{gnome - keyring - d}]
        | -gnome - shell - cal-- - 5 * [{gnome - shell - cal}]
        | -gnome - terminal-- + -bash-- - bash - +-grep
        |                 |             `-pstree
        |                 |-gnome - pty - helpe
        [root@luckily day05]# echo $name
        苍老师
        [root@luckily day05]#  env
        XDG_VTNR = 1
        LC_PAPER = zh_CN.UTF - 8
        XDG_SESSION_ID = 1
        SSH_AGENT_PID = 2491
        LC_MONETARY = zh_CN.UTF - 8
        HOSTNAME = luckily.com
        IMSETTINGS_INTEGRATE_DESKTOP = yes
        XDG_MENU_PREFIX = gnome -
        SHELL = / bin / bash
        TERM = xterm - 256color
        VTE_VERSION = 5202
        HISTSIZE = 1000
        GNOME_TERMINAL_SCREEN = / org / gnome / Terminal / screen / e55fb8e8_a1c8_4098_ab9e_70801e0cb490
        LC_NUMERIC = zh_CN.UTF - 8
        IMSETTINGS_MODULE = none
        USER = root
        name = 苍老师
        LS_COLORS = rs = 0:di = 38; 5; 27:ln = 38; 5; 51:mh = 44; 38; 5; 15:pi = 40; 38; 5; 11:so = 38; 5; 13:do = 38; 5; 5:bd = 48; 5; 232; 38; 5; 11:cd = 48; 5; 232; 38; 5; 3: or = 48; 5; 232; 38; 5; 9:mi = 05; 48; 5; 232; 38; 5; 15:su = 48; 5; 196; 38; 5; 15:sg = 48; 5; 11; 38; 5; 16:ca = 48; 5; 196; 38; 5; 226:tw = 48; 5; 10; 38; 5; 16:ow = 48; 5; 10; 38; 5; 21:st = 48; 5; 21; 38; 5; 15:ex = 38; 5; 34:*.tar = 38; 5; 9:*.tgz = 38; 5; 9:*.arc = 38; 5; 9:*.arj = 38; 5; 9:*.taz = 38; 5; 9:*.lha = 38; 5; 9:*.lz4 = 38; 5; 9:*.lzh = 38; 5; 9:*.lzma = 38; 5; 9:*.tlz = 38; 5; 9:*.txz = 38; 5; 9:*.tzo = 38; 5; 9:*.t7z = 38; 5; 9:*.zip = 38; 5; 9:*.z = 38; 5; 9:*.Z = 38; 5; 9:*.dz = 38; 5; 9:*.gz = 38; 5; 9:*.lrz = 38; 5; 9:*.lz = 38; 5; 9:*.lzo = 38; 5; 9:*.xz = 38; 5; 9:*.bz2 = 38; 5; 9:*.bz = 38; 5; 9:*.tbz = 38; 5; 9:*.tbz2 = 38; 5; 9:*.tz = 38; 5; 9:*.deb = 38; 5; 9:*.rpm = 38; 5; 9:*.jar = 38; 5; 9:*.war = 38; 5; 9:*.ear = 38; 5; 9:*.sar = 38; 5; 9:*.rar = 38; 5; 9:*.alz = 38; 5; 9:*.ace = 38; 5; 9:*.zoo = 38; 5; 9:*.cpio = 38; 5; 9:*.7z = 38; 5; 9:*.rz = 38; 5; 9:*.cab = 38; 5; 9:*.jpg = 38; 5; 13:*.jpeg = 38; 5; 13:*.gif = 38; 5; 13:*.bmp = 38; 5; 13:*.pbm = 38; 5; 13:*.pgm = 38; 5; 13:*.ppm = 38; 5; 13:*.tga = 38; 5; 13:*.xbm = 38; 5; 13:*.xpm = 38; 5; 13:*.tif = 38; 5; 13:*.tiff = 38; 5; 13:*.png = 38; 5; 13:*.svg = 38; 5; 13:*.svgz = 38; 5; 13:*.mng = 38; 5; 13:*.pcx = 38; 5; 13:*.mov = 38; 5; 13:*.mpg = 38; 5; 13:*.mpeg = 38; 5; 13:*.m2v = 38; 5; 13:*.mkv = 38; 5; 13:*.webm = 38; 5; 13:*.ogm = 38; 5; 13:*.mp4 = 38; 5; 13:*.m4v = 38; 5; 13:*.mp4v = 38; 5; 13:*.vob = 38; 5; 13:*.qt = 38; 5; 13:*.nuv = 38; 5; 13:*.wmv = 38; 5; 13:*.asf = 38; 5; 13:*.rm = 38; 5; 13:*.rmvb = 38; 5; 13:*.flc = 38; 5; 13:*.avi = 38; 5; 13:*.fli = 38; 5; 13:*.flv = 38; 5; 13:*.gl = 38; 5; 13:*.dl = 38; 5; 13:*.xcf = 38; 5; 13:*.xwd = 38; 5; 13:*.yuv = 38; 5; 13:*.cgm = 38; 5; 13:*.emf = 38; 5; 13:*.axv = 38; 5; 13:*.anx = 38; 5; 13:*.ogv = 38; 5; 13:*.ogx = 38; 5; 13:*.aac = 38; 5; 45:*.au = 38; 5; 45:*.flac = 38; 5; 45:*.mid = 38; 5; 45:*.midi = 38; 5; 45:*.mka = 38; 5; 45:*.mp3 = 38; 5; 45:*.mpc = 38; 5; 45:*.ogg = 38; 5; 45:*.ra = 38; 5; 45:*.wav = 38; 5; 45:*.axa = 38; 5; 45:*.oga = 38; 5; 45:*.spx = 38; 5; 45:*.xspf = 38; 5; 45:
    GNOME_TERMINAL_SERVICE = : 1.105
        SSH_AUTH_SOCK = / run / user / 0 / keyring / ssh
        USERNAME = root
        SESSION_MANAGER = local / unix : @ / tmp / .ICE - unix / 2353, unix / unix: / tmp / .ICE - unix / 2353
        GNOME_SHELL_SESSION_MODE = classic
        DESKTOP_SESSION = gnome - classic
        MAIL = / var / spool / mail / root
        PATH = / usr / local / bin : / usr / local / sbin : / usr / bin : / usr / sbin : / bin : / sbin : / root / bin
        QT_IM_MODULE = ibus
        PWD = / root / study / day05
        XDG_SESSION_TYPE = x11
        XMODIFIERS = @im = ibus
        LANG = zh_CN.UTF - 8
        GDM_LANG = zh_CN.UTF - 8
        LC_MEASUREMENT = zh_CN.UTF - 8
        GDMSESSION = gnome - classic
        HISTCONTROL = ignoredups
        SHLVL = 3
        HOME = / root
        XDG_SEAT = seat0
        GNOME_DESKTOP_SESSION_ID = this - is - deprecated
        LOGNAME = root
        XDG_SESSION_DESKTOP = gnome - classic
        DBUS_SESSION_BUS_ADDRESS = unix:abstract = / tmp / dbus - Gsb0cDwsUi, guid = 2aa158323f31538cbf1044255ebf412a
        XDG_DATA_DIRS = / root / .local / share / flatpak / exports / share / : / var / lib / flatpak / exports / share / : / usr / local / share / : / usr / share /
        LESSOPEN = ||/usr / bin / lesspipe.sh % s
        WINDOWPATH = 1
        DISPLAY = : 0
        XDG_RUNTIME_DIR = / run / user / 0
        XDG_CURRENT_DESKTOP = GNOME - Classic : GNOME
        LC_TIME = zh_CN.UTF - 8
        XAUTHORITY = / run / gdm / auth - for - root - zfGLm2 / database
        COLORTERM = truecolor
        _ = / usr / bin / env
        [root@luckily day05]# cat 8Linux051001.c
#include <stdio.h>
#include <unistd.h>

        int g_data = 100;
    int main(void) {
        pid_t pid = fork();
        switch (pid) {
        case -1:
            printf("fork error\n");
            break;
        case 0:
            g_data = 200;
            printf("child : %p,&g_data = %p,g_data=%d\n", &main, &g_data, g_data);
            break;
        default:
            sleep(1);
            printf("parent : %p, &g_data = %p,g_data = %d\n", &main, &g_data, g_data);
            break;
        }
        sleep(1);
    }
    [root@luckily day05]# vim enc, c
        [root@luckily day05]# vim enc.c
        [root@luckily day05]# ls
        8Linux051001.c  a.out  enc, c  enc.c
        [root@luckily day05]# rm - f ene, c
        [root@luckily day05]# ls
        8Linux051001.c  a.out  enc, c  enc.c
        [root@luckily day05]# rm - i enc, c
        rm：是否删除普通文件 "enc,c"？
        [root@luckily day05]# ls
        8Linux051001.c  a.out  enc, c  enc.c
        [root@luckily day05]# rm - i enc, c
        rm：是否删除普通文件 "enc,c"？y
        [root@luckily day05]# ls
        8Linux051001.c  a.out  enc.c
        [root@luckily day05]# rm - f ene.c
        [root@luckily day05]# ls
        8Linux051001.c  a.out  enc.c
        [root@luckily day05]# rm - f enc.c
        [root@luckily day05]# ls
        8Linux051001.c  a.out
        [root@luckily day05]# vim env.c
        [root@luckily day05]# gcc env.c
        [root@luckily day05]# . / a.out abc def
        . / a.out
        abc
        def
        [root@luckily day05]# vim env.c
        [root@luckily day05]# gcc env.c
        [root@luckily day05]# . / a.out abc def
        argc = 3
        argv[0] = . / a.out
        argv[1] = abc
        argv[2] = def
        [root@luckily day05]# vim env.c
        [root@luckily day05]# gcc env.c
        env.c: 在函数‘main’中:
    env.c : 12 : 19 : 警告：比较指针和整数[默认启用]
        for (i = 0; i < envp[i != NULL]; i++) {
            ^
                env.c:12 : 12 : 警告：比较指针和整数[默认启用]
                for (i = 0; i < envp[i != NULL]; i++) {
                    ^
                        [root@luckily day05]# vim env.c
                        [root@luckily day05]# gcc env.c
                        env.c: 在函数‘main’中:
                    env.c : 12 : 12 : 警告：比较指针和整数[默认启用]
                        for (i = 0; i < envp[i] != NULL]; i++) {
                            ^
                                env.c:12 : 20 : 警告：比较指针和整数[默认启用]
                                for (i = 0; i < envp[i] != NULL]; i++) {
                                    ^
                                        env.c:12 : 26 : 错误：expected ‘; ’ before ‘]’ token
                                        for (i = 0; i < envp[i] != NULL]; i++) {
                                            ^
                                                env.c:12 : 26 : 错误：expected expression before ‘]’ token
                                                env.c:12 : 26 : 错误：expected statement before ‘]’ token
                                                env.c:12 : 31 : 错误：expected ‘; ’ before ‘)’ token
                                                for (i = 0; i < envp[i] != NULL]; i++) {
                                                    ^
                                                        env.c:12 : 31 : 错误：expected statement before ‘)’ token
                                                        [root@luckily day05]# vim env.c
                                                        [root@luckily day05]# gcc env.c
                                                        env.c: 在函数‘main’中:
                                                    env.c : 12 : 12 : 警告：比较指针和整数[默认启用]
                                                        for (i = 0; i < envp[i] != NULL; i++) {
                                                            ^
                                                                env.c:12 : 20 : 警告：比较指针和整数[默认启用]
                                                                for (i = 0; i < envp[i] != NULL; i++) {
                                                                    ^
                                                                        [root@luckily day05]# vim env.c
                                                                        [root@luckily day05]# gcc env.c
                                                                        env.c: 在函数‘main’中:
                                                                    env.c : 12 : 12 : 警告：比较指针和整数[默认启用]
                                                                        for (i = 0; i < envp[i] != NULL; i++) {
                                                                            ^
                                                                                env.c:12 : 20 : 警告：比较指针和整数[默认启用]
                                                                                for (i = 0; i < envp[i] != NULL; i++) {
                                                                                    ^
                                                                                        [root@luckily day05]# . / a.out
                                                                                        argc = 1
                                                                                        0 : XDG_VTNR = 1
                                                                                        1 : LC_PAPER = zh_CN.UTF - 8
                                                                                        2 : XDG_SESSION_ID = 1
                                                                                        3 : SSH_AGENT_PID = 2491
                                                                                        4 : LC_MONETARY = zh_CN.UTF - 8
                                                                                        5 : HOSTNAME = luckily.com
                                                                                        6 : IMSETTINGS_INTEGRATE_DESKTOP = yes
                                                                                        7 : XDG_MENU_PREFIX = gnome -
                                                                                        8 : SHELL = / bin / bash
                                                                                        9 : TERM = xterm - 256color
                                                                                        10 : VTE_VERSION = 5202
                                                                                        11 : HISTSIZE = 1000
                                                                                        12 : GNOME_TERMINAL_SCREEN = / org / gnome / Terminal / screen / e55fb8e8_a1c8_4098_ab9e_70801e0cb490
                                                                                        13 : LC_NUMERIC = zh_CN.UTF - 8
                                                                                        14 : IMSETTINGS_MODULE = none
                                                                                        15 : USER = root
                                                                                        16 : name = 苍老师
                                                                                        17 : LS_COLORS = rs = 0 : di = 38; 5; 27:ln = 38; 5; 51:mh = 44; 38; 5; 15:pi = 40; 38; 5; 11:so = 38; 5; 13:do = 38; 5; 5:bd = 48; 5; 232; 38; 5; 11:cd = 48; 5; 232; 38; 5; 3: or = 48; 5; 232; 38; 5; 9:mi = 05; 48; 5; 232; 38; 5; 15:su = 48; 5; 196; 38; 5; 15:sg = 48; 5; 11; 38; 5; 16:ca = 48; 5; 196; 38; 5; 226:tw = 48; 5; 10; 38; 5; 16:ow = 48; 5; 10; 38; 5; 21:st = 48; 5; 21; 38; 5; 15:ex = 38; 5; 34:*.tar = 38; 5; 9:*.tgz = 38; 5; 9:*.arc = 38; 5; 9:*.arj = 38; 5; 9:*.taz = 38; 5; 9:*.lha = 38; 5; 9:*.lz4 = 38; 5; 9:*.lzh = 38; 5; 9:*.lzma = 38; 5; 9:*.tlz = 38; 5; 9:*.txz = 38; 5; 9:*.tzo = 38; 5; 9:*.t7z = 38; 5; 9:*.zip = 38; 5; 9:*.z = 38; 5; 9:*.Z = 38; 5; 9:*.dz = 38; 5; 9:*.gz = 38; 5; 9:*.lrz = 38; 5; 9:*.lz = 38; 5; 9:*.lzo = 38; 5; 9:*.xz = 38; 5; 9:*.bz2 = 38; 5; 9:*.bz = 38; 5; 9:*.tbz = 38; 5; 9:*.tbz2 = 38; 5; 9:*.tz = 38; 5; 9:*.deb = 38; 5; 9:*.rpm = 38; 5; 9:*.jar = 38; 5; 9:*.war = 38; 5; 9:*.ear = 38; 5; 9:*.sar = 38; 5; 9:*.rar = 38; 5; 9:*.alz = 38; 5; 9:*.ace = 38; 5; 9:*.zoo = 38; 5; 9:*.cpio = 38; 5; 9:*.7z = 38; 5; 9:*.rz = 38; 5; 9:*.cab = 38; 5; 9:*.jpg = 38; 5; 13:*.jpeg = 38; 5; 13:*.gif = 38; 5; 13:*.bmp = 38; 5; 13:*.pbm = 38; 5; 13:*.pgm = 38; 5; 13:*.ppm = 38; 5; 13:*.tga = 38; 5; 13:*.xbm = 38; 5; 13:*.xpm = 38; 5; 13:*.tif = 38; 5; 13:*.tiff = 38; 5; 13:*.png = 38; 5; 13:*.svg = 38; 5; 13:*.svgz = 38; 5; 13:*.mng = 38; 5; 13:*.pcx = 38; 5; 13:*.mov = 38; 5; 13:*.mpg = 38; 5; 13:*.mpeg = 38; 5; 13:*.m2v = 38; 5; 13:*.mkv = 38; 5; 13:*.webm = 38; 5; 13:*.ogm = 38; 5; 13:*.mp4 = 38; 5; 13:*.m4v = 38; 5; 13:*.mp4v = 38; 5; 13:*.vob = 38; 5; 13:*.qt = 38; 5; 13:*.nuv = 38; 5; 13:*.wmv = 38; 5; 13:*.asf = 38; 5; 13:*.rm = 38; 5; 13:*.rmvb = 38; 5; 13:*.flc = 38; 5; 13:*.avi = 38; 5; 13:*.fli = 38; 5; 13:*.flv = 38; 5; 13:*.gl = 38; 5; 13:*.dl = 38; 5; 13:*.xcf = 38; 5; 13:*.xwd = 38; 5; 13:*.yuv = 38; 5; 13:*.cgm = 38; 5; 13:*.emf = 38; 5; 13:*.axv = 38; 5; 13:*.anx = 38; 5; 13:*.ogv = 38; 5; 13:*.ogx = 38; 5; 13:*.aac = 38; 5; 45:*.au = 38; 5; 45:*.flac = 38; 5; 45:*.mid = 38; 5; 45:*.midi = 38; 5; 45:*.mka = 38; 5; 45:*.mp3 = 38; 5; 45:*.mpc = 38; 5; 45:*.ogg = 38; 5; 45:*.ra = 38; 5; 45:*.wav = 38; 5; 45:*.axa = 38; 5; 45:*.oga = 38; 5; 45:*.spx = 38; 5; 45:*.xspf = 38; 5; 45:
                                                                                    18 : GNOME_TERMINAL_SERVICE = : 1.105
                                                                                        19 : SSH_AUTH_SOCK = / run / user / 0 / keyring / ssh
                                                                                        20 : USERNAME = root
                                                                                        21 : SESSION_MANAGER = local / unix : @ / tmp / .ICE - unix / 2353, unix / unix: / tmp / .ICE - unix / 2353
                                                                                        22 : GNOME_SHELL_SESSION_MODE = classic
                                                                                        23 : DESKTOP_SESSION = gnome - classic
                                                                                        24 : MAIL = / var / spool / mail / root
   : PATH = / usr / local / bin : / usr / local / sbin : / usr / bin : / usr / sbin : / bin : / sbin : / root / bin
     : QT_IM_MODULE = ibus
 : PWD = / root / study / day05
 : XDG_SESSION_TYPE = x11
 : XMODIFIERS = @im = ibus
 : LANG = zh_CN.UTF - 8
 : GDM_LANG = zh_CN.UTF - 8
                                                                                        32 : LC_MEASUREMENT = zh_CN.UTF - 8
                                                                                        33 : GDMSESSION = gnome - classic
                                                                                        34 : HISTCONTROL = ignoredups
                                                                                        35 : SHLVL = 3
                                                                                        36 : HOME = / root
                                                                                        37 : XDG_SEAT = seat0
                                                                                        38 : GNOME_DESKTOP_SESSION_ID = this - is - deprecated
                                                                                        39 : LOGNAME = root
                                                                                        40 : XDG_SESSION_DESKTOP = gnome - classic
                                                                                        41 : DBUS_SESSION_BUS_ADDRESS = unix : abstract = / tmp / dbus - Gsb0cDwsUi, guid = 2aa158323f31538cbf1044255ebf412a
                                                                                        42 : XDG_DATA_DIRS = / root / .local / share / flatpak / exports / share / : / var / lib / flatpak / exports / share / : / usr / local / share / : / usr / share /
                                                                                        43 : LESSOPEN = ||/usr / bin / lesspipe.sh % s
                                                                                        44 : WINDOWPATH = 1
                                                                                        45 : DISPLAY = : 0
                                                                                        46 : XDG_RUNTIME_DIR = / run / user / 0
                                                                                        47 : XDG_CURRENT_DESKTOP = GNOME - Classic : GNOME
                                                                                        48 : LC_TIME = zh_CN.UTF - 8
                                                                                        49 : XAUTHORITY = / run / gdm / auth - for - root - zfGLm2 / database
                                                                                        50 : COLORTERM = truecolor
                                                                                        51 : _ = . / a.out
                                                                                        [root@luckily day05]# vim env.c
                                                                                        [root@luckily day05]# gcc env.c
                                                                                        [root@luckily day05]# . / a.out
                                                                                        argc = 1
                                                                                        [root@luckily day05]# vim env.c
                                                                                        [root@luckily day05]# gcc env.c
                                                                                        [root@luckily day05]# . / a.out
                                                                                        argc = 1
                                                                                        NULL
                                                                                        [root@luckily day05]# vim env.c
                                                                                        [root@luckily day05]# gcc env.c
                                                                                        env.c: 在函数‘main’中:
                                                                                    env.c : 22 : 16 : 错误：‘shell’未声明(在此函数内第一次使用)
                                                                                        printf("%s\n", shell == NULL ? "NULL" : shell);
                                                                                    ^
                                                                                        env.c:22 : 16 : 附注：每个未声明的标识符在其出现的函数内只报告一次
                                                                                        [root@luckily day05]# vim env.c
                                                                                        [root@luckily day05]# gcc env.c
                                                                                        [root@luckily day05]# gcc env.c
                                                                                        [root@luckily day05]# . / a.out
                                                                                        argc = 1
                                                                                        / bin / bash
                                                                                        [root@luckily day05]# vim env.c
                                                                                        [root@luckily day05]# cat env.c
#include <stdio.h>
#include <stdlib.h>

                                                                                        //argc:命令行参数的个数
                                                                                        //argv:命令行参数
                                                                                        int main(int argc, char* argv[], char* envp[]) {
                                                                                        int i;

                                                                                        printf("argc = %d\n", argc);

                                                                                        /*for(i=0;i<argc;i++){
                                                                                            printf("argv[%d]= %s\n",i,argv[i]);
                                                                                        }*/


                                                                                        /* for(i=0;i<envp[i]!=NULL;i++){
                                                                                                    printf("%d : %s\n",i,envp[i]);
                                                                                             }
                                                                                        */

                                                                                        char* shell = getenv("SHELL"); //获取环境变量
                                                                                        printf("%s\n", shell == NULL ? "NULL" : shell);
                                                                                    }
                                                                                    [root@luckily day05]# vim env.c
                                                                                        [root@luckily day05]# gcc env.c
                                                                                        [root@luckily day05]# . / a.out
                                                                                        argc = 1
                                                                                        / bin / bash
                                                                                        putenv() ok
                                                                                        [root@luckily day05]# vim env.c
                                                                                        [root@luckily day05]# gcc env.c
                                                                                        [root@luckily day05]# . / a.out
                                                                                        argc = 1
                                                                                        / bin / bash
                                                                                        putenv() ok
                                                                                        abc
