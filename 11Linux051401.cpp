//进程
[root@luckily ~]# cd study
[root@luckily study]# cd day07
[root@luckily day07]# ls
01.c  02.c  a.out  myshell.c
[root@luckily day07]# vim myshell.c
[root@luckily day07]# gcc myshell.c
[root@luckily day07]# . / a.out
[Luckily shell] # ls
01.c  02.c  a.out  myshell.c
[Luckily shell] # ls - l
总用量 24
- rw - r--r--. 1 root root  348 5月  23 11:39 01.c
- rw - r--r--. 1 root root  570 5月  23 12 : 09 02.c
- rwxr - xr - x. 1 root root 8984 5月  23 13:26 a.out
- rw - r--r--. 1 root root 1354 5月  23 13 : 26 myshell.c
[Luckily shell] # pwd
/ root / study / day07
[Luckily shell] # touch mmc.txt
[Luckily shell] # ls
01.c  02.c  a.out  mmc.txt  myshell.c
[Luckily shell] # mf - f mmc.txt
mf : command not found
[Luckily shell] #  ^ C
[root@luckily day07]# ls
01.c  02.c  a.out  mmc.txt  myshell.c
[root@luckily day07]# rm - f mmc.txt
[root@luckily day07]# ls
01.c  02.c  a.out  myshell.c
[root@luckily ~]# ls
1587552516.log                              passwd   test.txt.bak  视频  下载
anaconda - ks.cfg                             program  公共          图片  音乐
mysql57 - community - release - el7 - 8.noarch.rpm  study    模板          文档  桌面
[root@luckily ~]# cd study
[root@luckily study]# ls
day01  day02  day03  day04  day05  day06  day07
[root@luckily study]# cd day07
[root@luckily day07]# ls
01.c  02.c  a.out  myshell.c
[root@luckily day07]# vim 03.
[root@luckily day07]# rename 03. 03.c
rename : 参数不够

用法：
rename[选项] 表达式 替换文件...

选项：
- v, --verbose    解释正在进行的操作
- s, --symlink    在符号链接上执行

- h, --help     显示此帮助并退出
- V, --version  输出版本信息并退出

更多信息请参阅 rename(1)。
[root@luckily day07]# man rename
[root@luckily day07]# rm - f 03.
[root@luckily day07]# vim 03.c
[root@luckily day07]# gcc 03.c
[root@luckily day07]# . / a.out
execl : No such file or directory
[root@luckily day07]# vim 03.c
[root@luckily day07]# vim myenv.c
[root@luckily day07]# gcc myenv.c
/ tmp / ccOpucUp.o：在函数‘main’中：
myenv.c:(.text + 0x32)：对‘prinytf’未定义的引用
collect2 : 错误：ld 返回 1
[root@luckily day07]# vim myenv.c
[root@luckily day07]# gcc myenv.c
[root@luckily day07]# . / a.out
LC_PAPER = zh_CN.UTF - 8
XDG_VTNR = 1
SSH_AGENT_PID = 2504
XDG_SESSION_ID = 1
HOSTNAME = luckily.com
LC_MONETARY = zh_CN.UTF - 8
IMSETTINGS_INTEGRATE_DESKTOP = yes
VTE_VERSION = 5202
TERM = xterm - 256color
SHELL = / bin / bash
XDG_MENU_PREFIX = gnome -
HISTSIZE = 1000
GNOME_TERMINAL_SCREEN = / org / gnome / Terminal / screen / 2417b61f_2a3b_4a27_b440_a26d49d7f841
LC_NUMERIC = zh_CN.UTF - 8
IMSETTINGS_MODULE = none
USER = root
LS_COLORS = rs = 0:di = 38; 5; 27:ln = 38; 5; 51:mh = 44; 38; 5; 15:pi = 40; 38; 5; 11:so = 38; 5; 13:do = 38; 5; 5:bd = 48; 5; 232; 38; 5; 11:cd = 48; 5; 232; 38; 5; 3: or = 48; 5; 232; 38; 5; 9:mi = 05; 48; 5; 232; 38; 5; 15:su = 48; 5; 196; 38; 5; 15:sg = 48; 5; 11; 38; 5; 16:ca = 48; 5; 196; 38; 5; 226:tw = 48; 5; 10; 38; 5; 16:ow = 48; 5; 10; 38; 5; 21:st = 48; 5; 21; 38; 5; 15:ex = 38; 5; 34:*.tar = 38; 5; 9:*.tgz = 38; 5; 9:*.arc = 38; 5; 9:*.arj = 38; 5; 9:*.taz = 38; 5; 9:*.lha = 38; 5; 9:*.lz4 = 38; 5; 9:*.lzh = 38; 5; 9:*.lzma = 38; 5; 9:*.tlz = 38; 5; 9:*.txz = 38; 5; 9:*.tzo = 38; 5; 9:*.t7z = 38; 5; 9:*.zip = 38; 5; 9:*.z = 38; 5; 9:*.Z = 38; 5; 9:*.dz = 38; 5; 9:*.gz = 38; 5; 9:*.lrz = 38; 5; 9:*.lz = 38; 5; 9:*.lzo = 38; 5; 9:*.xz = 38; 5; 9:*.bz2 = 38; 5; 9:*.bz = 38; 5; 9:*.tbz = 38; 5; 9:*.tbz2 = 38; 5; 9:*.tz = 38; 5; 9:*.deb = 38; 5; 9:*.rpm = 38; 5; 9:*.jar = 38; 5; 9:*.war = 38; 5; 9:*.ear = 38; 5; 9:*.sar = 38; 5; 9:*.rar = 38; 5; 9:*.alz = 38; 5; 9:*.ace = 38; 5; 9:*.zoo = 38; 5; 9:*.cpio = 38; 5; 9:*.7z = 38; 5; 9:*.rz = 38; 5; 9:*.cab = 38; 5; 9:*.jpg = 38; 5; 13:*.jpeg = 38; 5; 13:*.gif = 38; 5; 13:*.bmp = 38; 5; 13:*.pbm = 38; 5; 13:*.pgm = 38; 5; 13:*.ppm = 38; 5; 13:*.tga = 38; 5; 13:*.xbm = 38; 5; 13:*.xpm = 38; 5; 13:*.tif = 38; 5; 13:*.tiff = 38; 5; 13:*.png = 38; 5; 13:*.svg = 38; 5; 13:*.svgz = 38; 5; 13:*.mng = 38; 5; 13:*.pcx = 38; 5; 13:*.mov = 38; 5; 13:*.mpg = 38; 5; 13:*.mpeg = 38; 5; 13:*.m2v = 38; 5; 13:*.mkv = 38; 5; 13:*.webm = 38; 5; 13:*.ogm = 38; 5; 13:*.mp4 = 38; 5; 13:*.m4v = 38; 5; 13:*.mp4v = 38; 5; 13:*.vob = 38; 5; 13:*.qt = 38; 5; 13:*.nuv = 38; 5; 13:*.wmv = 38; 5; 13:*.asf = 38; 5; 13:*.rm = 38; 5; 13:*.rmvb = 38; 5; 13:*.flc = 38; 5; 13:*.avi = 38; 5; 13:*.fli = 38; 5; 13:*.flv = 38; 5; 13:*.gl = 38; 5; 13:*.dl = 38; 5; 13:*.xcf = 38; 5; 13:*.xwd = 38; 5; 13:*.yuv = 38; 5; 13:*.cgm = 38; 5; 13:*.emf = 38; 5; 13:*.axv = 38; 5; 13:*.anx = 38; 5; 13:*.ogv = 38; 5; 13:*.ogx = 38; 5; 13:*.aac = 38; 5; 45:*.au = 38; 5; 45:*.flac = 38; 5; 45:*.mid = 38; 5; 45:*.midi = 38; 5; 45:*.mka = 38; 5; 45:*.mp3 = 38; 5; 45:*.mpc = 38; 5; 45:*.ogg = 38; 5; 45:*.ra = 38; 5; 45:*.wav = 38; 5; 45:*.axa = 38; 5; 45:*.oga = 38; 5; 45:*.spx = 38; 5; 45:*.xspf = 38; 5; 45:
GNOME_TERMINAL_SERVICE = : 1.106
SSH_AUTH_SOCK = / run / user / 0 / keyring / ssh
SESSION_MANAGER = local / unix : @ / tmp / .ICE - unix / 2366, unix / unix: / tmp / .ICE - unix / 2366
USERNAME = root
GNOME_SHELL_SESSION_MODE = classic
PATH = / usr / local / bin : / usr / local / sbin : / usr / bin : / usr / sbin : / bin : / sbin : / root / bin
MAIL = / var / spool / mail / root
DESKTOP_SESSION = gnome - classic
QT_IM_MODULE = ibus
XDG_SESSION_TYPE = x11
PWD = / root / study / day07
XMODIFIERS = @im = ibus
LANG = zh_CN.UTF - 8
GDM_LANG = zh_CN.UTF - 8
LC_MEASUREMENT = zh_CN.UTF - 8
GDMSESSION = gnome - classic
HISTCONTROL = ignoredups
XDG_SEAT = seat0
HOME = / root
SHLVL = 2
GNOME_DESKTOP_SESSION_ID = this - is - deprecated
XDG_SESSION_DESKTOP = gnome - classic
LOGNAME = root
XDG_DATA_DIRS = / root / .local / share / flatpak / exports / share / : / var / lib / flatpak / exports / share / : / usr / local / share / : / usr / share /
DBUS_SESSION_BUS_ADDRESS = unix : abstract = / tmp / dbus - fSOXc7Gchn, guid = 51ac02c259e85cbb626382ba5ec92fb3
LESSOPEN = ||/usr / bin / lesspipe.sh % s
WINDOWPATH = 1
XDG_RUNTIME_DIR = / run / user / 0
DISPLAY = : 0
XDG_CURRENT_DESKTOP = GNOME - Classic : GNOME
LC_TIME = zh_CN.UTF - 8
COLORTERM = truecolor
XAUTHORITY = / run / gdm / auth - for - root - HytmEV / database
_ = . / a.out
OLDPWD = / root / study
段错误(吐核)
[root@luckily day07]# vim myenv.c
[root@luckily day07]# vim 03.c
[root@luckily day07]# gcc 03.c
[root@luckily day07]# . / a.out
execle : No such file or directory
[root@luckily day07]# vim 03.c
[root@luckily day07]# gcc 03.c
[root@luckily day07]# . / a.out
execl : No such file or directory
[root@luckily day07]# vim 03.c
[root@luckily day07]# vim myenv.c
[root@luckily day07]# gcc myenv.c
[root@luckily day07]# . / a.out
LC_PAPER = zh_CN.UTF - 8
XDG_VTNR = 1
SSH_AGENT_PID = 2504
XDG_SESSION_ID = 1
HOSTNAME = luckily.com
LC_MONETARY = zh_CN.UTF - 8
IMSETTINGS_INTEGRATE_DESKTOP = yes
VTE_VERSION = 5202
TERM = xterm - 256color
SHELL = / bin / bash
XDG_MENU_PREFIX = gnome -
HISTSIZE = 1000
GNOME_TERMINAL_SCREEN = / org / gnome / Terminal / screen / 2417b61f_2a3b_4a27_b440_a26d49d7f841
LC_NUMERIC = zh_CN.UTF - 8
IMSETTINGS_MODULE = none
USER = root
LS_COLORS = rs = 0:di = 38; 5; 27:ln = 38; 5; 51:mh = 44; 38; 5; 15:pi = 40; 38; 5; 11:so = 38; 5; 13:do = 38; 5; 5:bd = 48; 5; 232; 38; 5; 11:cd = 48; 5; 232; 38; 5; 3: or = 48; 5; 232; 38; 5; 9:mi = 05; 48; 5; 232; 38; 5; 15:su = 48; 5; 196; 38; 5; 15:sg = 48; 5; 11; 38; 5; 16:ca = 48; 5; 196; 38; 5; 226:tw = 48; 5; 10; 38; 5; 16:ow = 48; 5; 10; 38; 5; 21:st = 48; 5; 21; 38; 5; 15:ex = 38; 5; 34:*.tar = 38; 5; 9:*.tgz = 38; 5; 9:*.arc = 38; 5; 9:*.arj = 38; 5; 9:*.taz = 38; 5; 9:*.lha = 38; 5; 9:*.lz4 = 38; 5; 9:*.lzh = 38; 5; 9:*.lzma = 38; 5; 9:*.tlz = 38; 5; 9:*.txz = 38; 5; 9:*.tzo = 38; 5; 9:*.t7z = 38; 5; 9:*.zip = 38; 5; 9:*.z = 38; 5; 9:*.Z = 38; 5; 9:*.dz = 38; 5; 9:*.gz = 38; 5; 9:*.lrz = 38; 5; 9:*.lz = 38; 5; 9:*.lzo = 38; 5; 9:*.xz = 38; 5; 9:*.bz2 = 38; 5; 9:*.bz = 38; 5; 9:*.tbz = 38; 5; 9:*.tbz2 = 38; 5; 9:*.tz = 38; 5; 9:*.deb = 38; 5; 9:*.rpm = 38; 5; 9:*.jar = 38; 5; 9:*.war = 38; 5; 9:*.ear = 38; 5; 9:*.sar = 38; 5; 9:*.rar = 38; 5; 9:*.alz = 38; 5; 9:*.ace = 38; 5; 9:*.zoo = 38; 5; 9:*.cpio = 38; 5; 9:*.7z = 38; 5; 9:*.rz = 38; 5; 9:*.cab = 38; 5; 9:*.jpg = 38; 5; 13:*.jpeg = 38; 5; 13:*.gif = 38; 5; 13:*.bmp = 38; 5; 13:*.pbm = 38; 5; 13:*.pgm = 38; 5; 13:*.ppm = 38; 5; 13:*.tga = 38; 5; 13:*.xbm = 38; 5; 13:*.xpm = 38; 5; 13:*.tif = 38; 5; 13:*.tiff = 38; 5; 13:*.png = 38; 5; 13:*.svg = 38; 5; 13:*.svgz = 38; 5; 13:*.mng = 38; 5; 13:*.pcx = 38; 5; 13:*.mov = 38; 5; 13:*.mpg = 38; 5; 13:*.mpeg = 38; 5; 13:*.m2v = 38; 5; 13:*.mkv = 38; 5; 13:*.webm = 38; 5; 13:*.ogm = 38; 5; 13:*.mp4 = 38; 5; 13:*.m4v = 38; 5; 13:*.mp4v = 38; 5; 13:*.vob = 38; 5; 13:*.qt = 38; 5; 13:*.nuv = 38; 5; 13:*.wmv = 38; 5; 13:*.asf = 38; 5; 13:*.rm = 38; 5; 13:*.rmvb = 38; 5; 13:*.flc = 38; 5; 13:*.avi = 38; 5; 13:*.fli = 38; 5; 13:*.flv = 38; 5; 13:*.gl = 38; 5; 13:*.dl = 38; 5; 13:*.xcf = 38; 5; 13:*.xwd = 38; 5; 13:*.yuv = 38; 5; 13:*.cgm = 38; 5; 13:*.emf = 38; 5; 13:*.axv = 38; 5; 13:*.anx = 38; 5; 13:*.ogv = 38; 5; 13:*.ogx = 38; 5; 13:*.aac = 38; 5; 45:*.au = 38; 5; 45:*.flac = 38; 5; 45:*.mid = 38; 5; 45:*.midi = 38; 5; 45:*.mka = 38; 5; 45:*.mp3 = 38; 5; 45:*.mpc = 38; 5; 45:*.ogg = 38; 5; 45:*.ra = 38; 5; 45:*.wav = 38; 5; 45:*.axa = 38; 5; 45:*.oga = 38; 5; 45:*.spx = 38; 5; 45:*.xspf = 38; 5; 45:
GNOME_TERMINAL_SERVICE = : 1.106
SSH_AUTH_SOCK = / run / user / 0 / keyring / ssh
SESSION_MANAGER = local / unix : @ / tmp / .ICE - unix / 2366, unix / unix: / tmp / .ICE - unix / 2366
USERNAME = root
GNOME_SHELL_SESSION_MODE = classic
PATH = / usr / local / bin : / usr / local / sbin : / usr / bin : / usr / sbin : / bin : / sbin : / root / bin
MAIL = / var / spool / mail / root
DESKTOP_SESSION = gnome - classic
QT_IM_MODULE = ibus
XDG_SESSION_TYPE = x11
PWD = / root / study / day07
XMODIFIERS = @im = ibus
LANG = zh_CN.UTF - 8
GDM_LANG = zh_CN.UTF - 8
LC_MEASUREMENT = zh_CN.UTF - 8
GDMSESSION = gnome - classic
HISTCONTROL = ignoredups
XDG_SEAT = seat0
HOME = / root
SHLVL = 2
GNOME_DESKTOP_SESSION_ID = this - is - deprecated
XDG_SESSION_DESKTOP = gnome - classic
LOGNAME = root
XDG_DATA_DIRS = / root / .local / share / flatpak / exports / share / : / var / lib / flatpak / exports / share / : / usr / local / share / : / usr / share /
DBUS_SESSION_BUS_ADDRESS = unix : abstract = / tmp / dbus - fSOXc7Gchn, guid = 51ac02c259e85cbb626382ba5ec92fb3
LESSOPEN = ||/usr / bin / lesspipe.sh % s
WINDOWPATH = 1
XDG_RUNTIME_DIR = / run / user / 0
DISPLAY = : 0
XDG_CURRENT_DESKTOP = GNOME - Classic : GNOME
LC_TIME = zh_CN.UTF - 8
COLORTERM = truecolor
XAUTHORITY = / run / gdm / auth - for - root - HytmEV / database
_ = . / a.out
OLDPWD = / root / study
段错误(吐核)
[root@luckily day07]# vim myenv.c
[root@luckily day07]# gcc myenv.c - o myenv
[root@luckily day07]# . / muenv
bash : . / muenv : 没有那个文件或目录
[root@luckily day07]# . / myenv
LC_PAPER = zh_CN.UTF - 8
XDG_VTNR = 1
SSH_AGENT_PID = 2504
XDG_SESSION_ID = 1
HOSTNAME = luckily.com
LC_MONETARY = zh_CN.UTF - 8
IMSETTINGS_INTEGRATE_DESKTOP = yes
VTE_VERSION = 5202
TERM = xterm - 256color
SHELL = / bin / bash
XDG_MENU_PREFIX = gnome -
HISTSIZE = 1000
GNOME_TERMINAL_SCREEN = / org / gnome / Terminal / screen / 2417b61f_2a3b_4a27_b440_a26d49d7f841
LC_NUMERIC = zh_CN.UTF - 8
IMSETTINGS_MODULE = none
USER = root
LS_COLORS = rs = 0:di = 38; 5; 27:ln = 38; 5; 51:mh = 44; 38; 5; 15:pi = 40; 38; 5; 11:so = 38; 5; 13:do = 38; 5; 5:bd = 48; 5; 232; 38; 5; 11:cd = 48; 5; 232; 38; 5; 3: or = 48; 5; 232; 38; 5; 9:mi = 05; 48; 5; 232; 38; 5; 15:su = 48; 5; 196; 38; 5; 15:sg = 48; 5; 11; 38; 5; 16:ca = 48; 5; 196; 38; 5; 226:tw = 48; 5; 10; 38; 5; 16:ow = 48; 5; 10; 38; 5; 21:st = 48; 5; 21; 38; 5; 15:ex = 38; 5; 34:*.tar = 38; 5; 9:*.tgz = 38; 5; 9:*.arc = 38; 5; 9:*.arj = 38; 5; 9:*.taz = 38; 5; 9:*.lha = 38; 5; 9:*.lz4 = 38; 5; 9:*.lzh = 38; 5; 9:*.lzma = 38; 5; 9:*.tlz = 38; 5; 9:*.txz = 38; 5; 9:*.tzo = 38; 5; 9:*.t7z = 38; 5; 9:*.zip = 38; 5; 9:*.z = 38; 5; 9:*.Z = 38; 5; 9:*.dz = 38; 5; 9:*.gz = 38; 5; 9:*.lrz = 38; 5; 9:*.lz = 38; 5; 9:*.lzo = 38; 5; 9:*.xz = 38; 5; 9:*.bz2 = 38; 5; 9:*.bz = 38; 5; 9:*.tbz = 38; 5; 9:*.tbz2 = 38; 5; 9:*.tz = 38; 5; 9:*.deb = 38; 5; 9:*.rpm = 38; 5; 9:*.jar = 38; 5; 9:*.war = 38; 5; 9:*.ear = 38; 5; 9:*.sar = 38; 5; 9:*.rar = 38; 5; 9:*.alz = 38; 5; 9:*.ace = 38; 5; 9:*.zoo = 38; 5; 9:*.cpio = 38; 5; 9:*.7z = 38; 5; 9:*.rz = 38; 5; 9:*.cab = 38; 5; 9:*.jpg = 38; 5; 13:*.jpeg = 38; 5; 13:*.gif = 38; 5; 13:*.bmp = 38; 5; 13:*.pbm = 38; 5; 13:*.pgm = 38; 5; 13:*.ppm = 38; 5; 13:*.tga = 38; 5; 13:*.xbm = 38; 5; 13:*.xpm = 38; 5; 13:*.tif = 38; 5; 13:*.tiff = 38; 5; 13:*.png = 38; 5; 13:*.svg = 38; 5; 13:*.svgz = 38; 5; 13:*.mng = 38; 5; 13:*.pcx = 38; 5; 13:*.mov = 38; 5; 13:*.mpg = 38; 5; 13:*.mpeg = 38; 5; 13:*.m2v = 38; 5; 13:*.mkv = 38; 5; 13:*.webm = 38; 5; 13:*.ogm = 38; 5; 13:*.mp4 = 38; 5; 13:*.m4v = 38; 5; 13:*.mp4v = 38; 5; 13:*.vob = 38; 5; 13:*.qt = 38; 5; 13:*.nuv = 38; 5; 13:*.wmv = 38; 5; 13:*.asf = 38; 5; 13:*.rm = 38; 5; 13:*.rmvb = 38; 5; 13:*.flc = 38; 5; 13:*.avi = 38; 5; 13:*.fli = 38; 5; 13:*.flv = 38; 5; 13:*.gl = 38; 5; 13:*.dl = 38; 5; 13:*.xcf = 38; 5; 13:*.xwd = 38; 5; 13:*.yuv = 38; 5; 13:*.cgm = 38; 5; 13:*.emf = 38; 5; 13:*.axv = 38; 5; 13:*.anx = 38; 5; 13:*.ogv = 38; 5; 13:*.ogx = 38; 5; 13:*.aac = 38; 5; 45:*.au = 38; 5; 45:*.flac = 38; 5; 45:*.mid = 38; 5; 45:*.midi = 38; 5; 45:*.mka = 38; 5; 45:*.mp3 = 38; 5; 45:*.mpc = 38; 5; 45:*.ogg = 38; 5; 45:*.ra = 38; 5; 45:*.wav = 38; 5; 45:*.axa = 38; 5; 45:*.oga = 38; 5; 45:*.spx = 38; 5; 45:*.xspf = 38; 5; 45:
GNOME_TERMINAL_SERVICE = : 1.106
SSH_AUTH_SOCK = / run / user / 0 / keyring / ssh
SESSION_MANAGER = local / unix : @ / tmp / .ICE - unix / 2366, unix / unix: / tmp / .ICE - unix / 2366
USERNAME = root
GNOME_SHELL_SESSION_MODE = classic
PATH = / usr / local / bin : / usr / local / sbin : / usr / bin : / usr / sbin : / bin : / sbin : / root / bin
MAIL = / var / spool / mail / root
DESKTOP_SESSION = gnome - classic
QT_IM_MODULE = ibus
XDG_SESSION_TYPE = x11
PWD = / root / study / day07
XMODIFIERS = @im = ibus
LANG = zh_CN.UTF - 8
GDM_LANG = zh_CN.UTF - 8
LC_MEASUREMENT = zh_CN.UTF - 8
GDMSESSION = gnome - classic
HISTCONTROL = ignoredups
XDG_SEAT = seat0
HOME = / root
SHLVL = 2
GNOME_DESKTOP_SESSION_ID = this - is - deprecated
XDG_SESSION_DESKTOP = gnome - classic
LOGNAME = root
XDG_DATA_DIRS = / root / .local / share / flatpak / exports / share / : / var / lib / flatpak / exports / share / : / usr / local / share / : / usr / share /
DBUS_SESSION_BUS_ADDRESS = unix : abstract = / tmp / dbus - fSOXc7Gchn, guid = 51ac02c259e85cbb626382ba5ec92fb3
LESSOPEN = ||/usr / bin / lesspipe.sh % s
WINDOWPATH = 1
XDG_RUNTIME_DIR = / run / user / 0
DISPLAY = : 0
XDG_CURRENT_DESKTOP = GNOME - Classic : GNOME
LC_TIME = zh_CN.UTF - 8
COLORTERM = truecolor
XAUTHORITY = / run / gdm / auth - for - root - HytmEV / database
_ = . / myenv
OLDPWD = / root / study
段错误(吐核)
[root@luckily day07]# vim myenv
[root@luckily day07]# vim myenv.c
[root@luckily day07]# gcc myenv.c - o myenv
[root@luckily day07]# . / myenv
LC_PAPER = zh_CN.UTF - 8
XDG_VTNR = 1
SSH_AGENT_PID = 2504
XDG_SESSION_ID = 1
HOSTNAME = luckily.com
LC_MONETARY = zh_CN.UTF - 8
IMSETTINGS_INTEGRATE_DESKTOP = yes
VTE_VERSION = 5202
TERM = xterm - 256color
SHELL = / bin / bash
XDG_MENU_PREFIX = gnome -
HISTSIZE = 1000
GNOME_TERMINAL_SCREEN = / org / gnome / Terminal / screen / 2417b61f_2a3b_4a27_b440_a26d49d7f841
LC_NUMERIC = zh_CN.UTF - 8
IMSETTINGS_MODULE = none
USER = root
LS_COLORS = rs = 0:di = 38; 5; 27:ln = 38; 5; 51:mh = 44; 38; 5; 15:pi = 40; 38; 5; 11:so = 38; 5; 13:do = 38; 5; 5:bd = 48; 5; 232; 38; 5; 11:cd = 48; 5; 232; 38; 5; 3: or = 48; 5; 232; 38; 5; 9:mi = 05; 48; 5; 232; 38; 5; 15:su = 48; 5; 196; 38; 5; 15:sg = 48; 5; 11; 38; 5; 16:ca = 48; 5; 196; 38; 5; 226:tw = 48; 5; 10; 38; 5; 16:ow = 48; 5; 10; 38; 5; 21:st = 48; 5; 21; 38; 5; 15:ex = 38; 5; 34:*.tar = 38; 5; 9:*.tgz = 38; 5; 9:*.arc = 38; 5; 9:*.arj = 38; 5; 9:*.taz = 38; 5; 9:*.lha = 38; 5; 9:*.lz4 = 38; 5; 9:*.lzh = 38; 5; 9:*.lzma = 38; 5; 9:*.tlz = 38; 5; 9:*.txz = 38; 5; 9:*.tzo = 38; 5; 9:*.t7z = 38; 5; 9:*.zip = 38; 5; 9:*.z = 38; 5; 9:*.Z = 38; 5; 9:*.dz = 38; 5; 9:*.gz = 38; 5; 9:*.lrz = 38; 5; 9:*.lz = 38; 5; 9:*.lzo = 38; 5; 9:*.xz = 38; 5; 9:*.bz2 = 38; 5; 9:*.bz = 38; 5; 9:*.tbz = 38; 5; 9:*.tbz2 = 38; 5; 9:*.tz = 38; 5; 9:*.deb = 38; 5; 9:*.rpm = 38; 5; 9:*.jar = 38; 5; 9:*.war = 38; 5; 9:*.ear = 38; 5; 9:*.sar = 38; 5; 9:*.rar = 38; 5; 9:*.alz = 38; 5; 9:*.ace = 38; 5; 9:*.zoo = 38; 5; 9:*.cpio = 38; 5; 9:*.7z = 38; 5; 9:*.rz = 38; 5; 9:*.cab = 38; 5; 9:*.jpg = 38; 5; 13:*.jpeg = 38; 5; 13:*.gif = 38; 5; 13:*.bmp = 38; 5; 13:*.pbm = 38; 5; 13:*.pgm = 38; 5; 13:*.ppm = 38; 5; 13:*.tga = 38; 5; 13:*.xbm = 38; 5; 13:*.xpm = 38; 5; 13:*.tif = 38; 5; 13:*.tiff = 38; 5; 13:*.png = 38; 5; 13:*.svg = 38; 5; 13:*.svgz = 38; 5; 13:*.mng = 38; 5; 13:*.pcx = 38; 5; 13:*.mov = 38; 5; 13:*.mpg = 38; 5; 13:*.mpeg = 38; 5; 13:*.m2v = 38; 5; 13:*.mkv = 38; 5; 13:*.webm = 38; 5; 13:*.ogm = 38; 5; 13:*.mp4 = 38; 5; 13:*.m4v = 38; 5; 13:*.mp4v = 38; 5; 13:*.vob = 38; 5; 13:*.qt = 38; 5; 13:*.nuv = 38; 5; 13:*.wmv = 38; 5; 13:*.asf = 38; 5; 13:*.rm = 38; 5; 13:*.rmvb = 38; 5; 13:*.flc = 38; 5; 13:*.avi = 38; 5; 13:*.fli = 38; 5; 13:*.flv = 38; 5; 13:*.gl = 38; 5; 13:*.dl = 38; 5; 13:*.xcf = 38; 5; 13:*.xwd = 38; 5; 13:*.yuv = 38; 5; 13:*.cgm = 38; 5; 13:*.emf = 38; 5; 13:*.axv = 38; 5; 13:*.anx = 38; 5; 13:*.ogv = 38; 5; 13:*.ogx = 38; 5; 13:*.aac = 38; 5; 45:*.au = 38; 5; 45:*.flac = 38; 5; 45:*.mid = 38; 5; 45:*.midi = 38; 5; 45:*.mka = 38; 5; 45:*.mp3 = 38; 5; 45:*.mpc = 38; 5; 45:*.ogg = 38; 5; 45:*.ra = 38; 5; 45:*.wav = 38; 5; 45:*.axa = 38; 5; 45:*.oga = 38; 5; 45:*.spx = 38; 5; 45:*.xspf = 38; 5; 45:
GNOME_TERMINAL_SERVICE = : 1.106
SSH_AUTH_SOCK = / run / user / 0 / keyring / ssh
SESSION_MANAGER = local / unix : @ / tmp / .ICE - unix / 2366, unix / unix: / tmp / .ICE - unix / 2366
USERNAME = root
GNOME_SHELL_SESSION_MODE = classic
PATH = / usr / local / bin : / usr / local / sbin : / usr / bin : / usr / sbin : / bin : / sbin : / root / bin
MAIL = / var / spool / mail / root
DESKTOP_SESSION = gnome - classic
QT_IM_MODULE = ibus
XDG_SESSION_TYPE = x11
PWD = / root / study / day07
XMODIFIERS = @im = ibus
LANG = zh_CN.UTF - 8
GDM_LANG = zh_CN.UTF - 8
LC_MEASUREMENT = zh_CN.UTF - 8
GDMSESSION = gnome - classic
HISTCONTROL = ignoredups
XDG_SEAT = seat0
HOME = / root
SHLVL = 2
GNOME_DESKTOP_SESSION_ID = this - is - deprecated
XDG_SESSION_DESKTOP = gnome - classic
LOGNAME = root
XDG_DATA_DIRS = / root / .local / share / flatpak / exports / share / : / var / lib / flatpak / exports / share / : / usr / local / share / : / usr / share /
DBUS_SESSION_BUS_ADDRESS = unix : abstract = / tmp / dbus - fSOXc7Gchn, guid = 51ac02c259e85cbb626382ba5ec92fb3
LESSOPEN = ||/usr / bin / lesspipe.sh % s
WINDOWPATH = 1
XDG_RUNTIME_DIR = / run / user / 0
DISPLAY = : 0
XDG_CURRENT_DESKTOP = GNOME - Classic : GNOME
LC_TIME = zh_CN.UTF - 8
COLORTERM = truecolor
XAUTHORITY = / run / gdm / auth - for - root - HytmEV / database
_ = . / myenv
OLDPWD = / root / study
[root@luckily day07]# vim 03.c
[root@luckily day07]# gcc 03.c
[root@luckily day07]# . / a.out
LC_PAPER = zh_CN.UTF - 8
XDG_VTNR = 1
SSH_AGENT_PID = 2504
XDG_SESSION_ID = 1
HOSTNAME = luckily.com
LC_MONETARY = zh_CN.UTF - 8
IMSETTINGS_INTEGRATE_DESKTOP = yes
VTE_VERSION = 5202
TERM = xterm - 256color
SHELL = / bin / bash
XDG_MENU_PREFIX = gnome -
HISTSIZE = 1000
GNOME_TERMINAL_SCREEN = / org / gnome / Terminal / screen / 2417b61f_2a3b_4a27_b440_a26d49d7f841
LC_NUMERIC = zh_CN.UTF - 8
IMSETTINGS_MODULE = none
USER = root
LS_COLORS = rs = 0:di = 38; 5; 27:ln = 38; 5; 51:mh = 44; 38; 5; 15:pi = 40; 38; 5; 11:so = 38; 5; 13:do = 38; 5; 5:bd = 48; 5; 232; 38; 5; 11:cd = 48; 5; 232; 38; 5; 3: or = 48; 5; 232; 38; 5; 9:mi = 05; 48; 5; 232; 38; 5; 15:su = 48; 5; 196; 38; 5; 15:sg = 48; 5; 11; 38; 5; 16:ca = 48; 5; 196; 38; 5; 226:tw = 48; 5; 10; 38; 5; 16:ow = 48; 5; 10; 38; 5; 21:st = 48; 5; 21; 38; 5; 15:ex = 38; 5; 34:*.tar = 38; 5; 9:*.tgz = 38; 5; 9:*.arc = 38; 5; 9:*.arj = 38; 5; 9:*.taz = 38; 5; 9:*.lha = 38; 5; 9:*.lz4 = 38; 5; 9:*.lzh = 38; 5; 9:*.lzma = 38; 5; 9:*.tlz = 38; 5; 9:*.txz = 38; 5; 9:*.tzo = 38; 5; 9:*.t7z = 38; 5; 9:*.zip = 38; 5; 9:*.z = 38; 5; 9:*.Z = 38; 5; 9:*.dz = 38; 5; 9:*.gz = 38; 5; 9:*.lrz = 38; 5; 9:*.lz = 38; 5; 9:*.lzo = 38; 5; 9:*.xz = 38; 5; 9:*.bz2 = 38; 5; 9:*.bz = 38; 5; 9:*.tbz = 38; 5; 9:*.tbz2 = 38; 5; 9:*.tz = 38; 5; 9:*.deb = 38; 5; 9:*.rpm = 38; 5; 9:*.jar = 38; 5; 9:*.war = 38; 5; 9:*.ear = 38; 5; 9:*.sar = 38; 5; 9:*.rar = 38; 5; 9:*.alz = 38; 5; 9:*.ace = 38; 5; 9:*.zoo = 38; 5; 9:*.cpio = 38; 5; 9:*.7z = 38; 5; 9:*.rz = 38; 5; 9:*.cab = 38; 5; 9:*.jpg = 38; 5; 13:*.jpeg = 38; 5; 13:*.gif = 38; 5; 13:*.bmp = 38; 5; 13:*.pbm = 38; 5; 13:*.pgm = 38; 5; 13:*.ppm = 38; 5; 13:*.tga = 38; 5; 13:*.xbm = 38; 5; 13:*.xpm = 38; 5; 13:*.tif = 38; 5; 13:*.tiff = 38; 5; 13:*.png = 38; 5; 13:*.svg = 38; 5; 13:*.svgz = 38; 5; 13:*.mng = 38; 5; 13:*.pcx = 38; 5; 13:*.mov = 38; 5; 13:*.mpg = 38; 5; 13:*.mpeg = 38; 5; 13:*.m2v = 38; 5; 13:*.mkv = 38; 5; 13:*.webm = 38; 5; 13:*.ogm = 38; 5; 13:*.mp4 = 38; 5; 13:*.m4v = 38; 5; 13:*.mp4v = 38; 5; 13:*.vob = 38; 5; 13:*.qt = 38; 5; 13:*.nuv = 38; 5; 13:*.wmv = 38; 5; 13:*.asf = 38; 5; 13:*.rm = 38; 5; 13:*.rmvb = 38; 5; 13:*.flc = 38; 5; 13:*.avi = 38; 5; 13:*.fli = 38; 5; 13:*.flv = 38; 5; 13:*.gl = 38; 5; 13:*.dl = 38; 5; 13:*.xcf = 38; 5; 13:*.xwd = 38; 5; 13:*.yuv = 38; 5; 13:*.cgm = 38; 5; 13:*.emf = 38; 5; 13:*.axv = 38; 5; 13:*.anx = 38; 5; 13:*.ogv = 38; 5; 13:*.ogx = 38; 5; 13:*.aac = 38; 5; 45:*.au = 38; 5; 45:*.flac = 38; 5; 45:*.mid = 38; 5; 45:*.midi = 38; 5; 45:*.mka = 38; 5; 45:*.mp3 = 38; 5; 45:*.mpc = 38; 5; 45:*.ogg = 38; 5; 45:*.ra = 38; 5; 45:*.wav = 38; 5; 45:*.axa = 38; 5; 45:*.oga = 38; 5; 45:*.spx = 38; 5; 45:*.xspf = 38; 5; 45:
GNOME_TERMINAL_SERVICE = : 1.106
SSH_AUTH_SOCK = / run / user / 0 / keyring / ssh
SESSION_MANAGER = local / unix : @ / tmp / .ICE - unix / 2366, unix / unix: / tmp / .ICE - unix / 2366
USERNAME = root
GNOME_SHELL_SESSION_MODE = classic
PATH = / usr / local / bin : / usr / local / sbin : / usr / bin : / usr / sbin : / bin : / sbin : / root / bin
MAIL = / var / spool / mail / root
DESKTOP_SESSION = gnome - classic
QT_IM_MODULE = ibus
XDG_SESSION_TYPE = x11
PWD = / root / study / day07
XMODIFIERS = @im = ibus
LANG = zh_CN.UTF - 8
GDM_LANG = zh_CN.UTF - 8
LC_MEASUREMENT = zh_CN.UTF - 8
GDMSESSION = gnome - classic
HISTCONTROL = ignoredups
XDG_SEAT = seat0
HOME = / root
SHLVL = 2
GNOME_DESKTOP_SESSION_ID = this - is - deprecated
XDG_SESSION_DESKTOP = gnome - classic
LOGNAME = root
XDG_DATA_DIRS = / root / .local / share / flatpak / exports / share / : / var / lib / flatpak / exports / share / : / usr / local / share / : / usr / share /
DBUS_SESSION_BUS_ADDRESS = unix : abstract = / tmp / dbus - fSOXc7Gchn, guid = 51ac02c259e85cbb626382ba5ec92fb3
LESSOPEN = ||/usr / bin / lesspipe.sh % s
WINDOWPATH = 1
XDG_RUNTIME_DIR = / run / user / 0
DISPLAY = : 0
XDG_CURRENT_DESKTOP = GNOME - Classic : GNOME
LC_TIME = zh_CN.UTF - 8
COLORTERM = truecolor
XAUTHORITY = / run / gdm / auth - for - root - HytmEV / database
_ = . / a.out
OLDPWD = / root / study
