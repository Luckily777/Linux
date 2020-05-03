[root@luckily ~]# vim ~./vimrc
[root@luckily ~]# ~$ vim ~/.vimrc
bash: ~$: 未找到命令...
[root@luckily ~]# ls
1587552516.log                              passwd     test.txt.bak  图片  桌面
anaconda-ks.cfg                             program    公共          文档
hehe                                        study      模板          下载
mysql57-community-release-el7-8.noarch.rpm  test.txt2  视频          音乐
[root@luckily ~]# vim ~/.vimrc
[root@luckily ~]# cd /etc/vim
bash: cd: /etc/vim: 没有那个文件或目录
[root@luckily ~]# ls
1587552516.log                              passwd     test.txt.bak  图片  桌面
anaconda-ks.cfg                             program    公共          文档
hehe                                        study      模板          下载
mysql57-community-release-el7-8.noarch.rpm  test.txt2  视频          音乐
[root@luckily ~]# cd /etc
[root@luckily etc]# ls
abrt                        hosts.allow               profile.d
adjtime                     hosts.deny                protocols
aliases                     hp                        pulse
aliases.db                  idmapd.conf               purple
alsa                        init.d                    python
alternatives                inittab                   qemu-ga
anacrontab                  inputrc                   qemu-kvm
asound.conf                 iproute2                  radvd.conf
at.deny                     ipsec.conf                ras
audisp                      ipsec.d                   rc0.d
audit                       ipsec.secrets             rc1.d
avahi                       iscsi                     rc2.d
bash_completion.d           issue                     rc3.d
bashrc                      issue.net                 rc4.d
binfmt.d                    java                      rc5.d
bluetooth                   jvm                       rc6.d
brltty                      jvm-commmon               rc.d
brltty.conf                 kdump.conf                rc.local
centos-release              kernel                    rdma
centos-release-upstream     krb5.conf                 redhat-release
chkconfig.d                 krb5.conf.d               request-key.conf
chromium                    ksmtuned.conf             request-key.d
chrony.conf                 ld.so.cache               resolv.conf
chrony.keys                 ld.so.conf                rpc
cifs-utils                  ld.so.conf.d              rpm
cron.d                      libaudit.conf             rsyncd.conf
cron.daily                  libblockdev               rsyslog.conf
cron.deny                   libibverbs.d              rsyslog.d
cron.hourly                 libnl                     rwtab
cron.monthly                libpaper.d                rwtab.d
crontab                     libreport                 samba
cron.weekly                 libuser.conf              sane.d
crypttab                    libvirt                   sasl2
csh.cshrc                   locale.conf               scl
csh.login                   localtime                 securetty
cups                        login.defs                security
cupshelpers                 logrotate.conf            selinux
dbus-1                      logrotate.d               services
dconf                       lsm                       sestatus.conf
default                     lvm                       setroubleshoot
depmod.d                    machine-id                setuptool.d
dhcp                        magic                     sgml
DIR_COLORS                  mail.rc                   shadow
DIR_COLORS.256color         makedumpfile.conf.sample  shadow-
DIR_COLORS.lightbgcolor     man_db.conf               shells
dleyna-server-service.conf  maven                     skel
dnsmasq.conf                mcelog                    smartmontools
dnsmasq.d                   mke2fs.conf               sos.conf
dracut.conf                 modprobe.d                speech-dispatcher
dracut.conf.d               modules-load.d            ssh
e2fsck.conf                 motd                      ssl
egl                         mtab                      statetab
enscript.cfg                mtools.conf               statetab.d
environment                 multipath                 subgid
ethertypes                  my.cnf                    subgid-
exports                     my.cnf.d                  subuid
exports.d                   nanorc                    subuid-
favicon.png                 ndctl                     sudo.conf
fcoe                        netconfig                 sudoers
festival                    NetworkManager            sudoers.d
filesystems                 networks                  sudo-ldap.conf
firefox                     nfs.conf                  sysconfig
firewalld                   nfsmount.conf             sysctl.conf
flatpak                     nsswitch.conf             sysctl.d
fonts                       nsswitch.conf.bak         systemd
fprintd.conf                ntp                       system-release
fstab                       numad.conf                system-release-cpe
fuse.conf                   oddjob                    tcsd.conf
fwupd                       oddjobd.conf              terminfo
gconf                       oddjobd.conf.d            tmpfiles.d
gcrypt                      openldap                  trusted-key.key
gdbinit                     opt                       tuned
gdbinit.d                   os-release                udev
gdm                         PackageKit                udisks2
geoclue                     pam.d                     unbound
GeoIP.conf                  papersize                 updatedb.conf
ghostscript                 passwd                    UPower
glvnd                       passwd-                   usb_modeswitch.conf
gnupg                       pbm2ppa.conf              vconsole.conf
GREP_COLORS                 pinforc                   vimrc
groff                       pkcs11                    virc
group                       pki                       vmware-tools
group-                      plymouth                  wgetrc
grub2.cfg                   pm                        wpa_supplicant
grub.d                      pnm2ppa.conf              wvdial.conf
gshadow                     polkit-1                  X11
gshadow-                    popt.d                    xdg
gss                         postfix                   xinetd.d
gssproxy                    ppp                       xml
host.conf                   prelink.conf.d            yum
hostname                    printcap                  yum.conf
hosts                       profile                   yum.repos.d
[root@luckily etc]# vim vimrc
[root@luckily etc]# cd
[root@luckily ~]# cd study
[root@luckily study]# cd day03
[root@luckily day03]# vim process.c
[root@luckily day03]# vim SetNum.c
[root@luckily day03]# vim SetNum.c
[root@luckily day03]# mv SetNum.c  Linux
[root@luckily day03]# ls
Jindutiao  Jindutiao.c  Linux  process  process.c
[root@luckily day03]# Linux
bash: Linux: 未找到命令...
[root@luckily day03]# cd Linux
bash: cd: Linux: 不是目录
[root@luckily day03]# vim Linux
[root@luckily day03]# mv Linux  SetNum.c
[root@luckily day03]# cd
[root@luckily ~]# cd study
[root@luckily study]# ls
day01  day02  day03  Linux
[root@luckily study]# cd day03
[root@luckily day03]# mv SetNum.c  /study/Linux
mv: 无法将"SetNum.c" 移动至"/study/Linux": 没有那个文件或目录
[root@luckily day03]# mv SetNum.c  /study
[root@luckily day03]# ls
Jindutiao  Jindutiao.c  process  process.c
[root@luckily day03]# cd ..
[root@luckily study]# ls
day01  day02  day03  Linux
[root@luckily study]# cd Linux
[root@luckily Linux]# ls
Linux050201.c
[root@luckily Linux]# cd ..
[root@luckily study]# cd day03
[root@luckily day03]# ls
Jindutiao  Jindutiao.c  process  process.c
[root@luckily day03]# ls
Jindutiao  Jindutiao.c  process  process.c
[root@luckily day03]# cd ..
[root@luckily study]# ls
day01  day02  day03  Linux
[root@luckily study]# ls 3l
ls: 无法访问3l: 没有那个文件或目录
[root@luckily study]# ls -l
总用量 0
drwxr-xr-x. 2 root root 67 4月  25 10:26 day01
drwxr-xr-x. 3 root root 83 4月  28 17:40 day02
drwxr-xr-x. 2 root root 74 5月   3 17:03 day03
drwxr-xr-x. 3 root root 39 5月   2 16:17 Linux
[root@luckily study]# cd day01
[root@luckily day01]# ls
042401.c  042501.c  042502.c  a.out
[root@luckily day01]# cd ..
[root@luckily study]# cd day02
[root@luckily day02]# ls
042801.c  042802.c  042803.c  a.out  progress
[root@luckily day02]# cd ..
[root@luckily study]# cd ..
[root@luckily ~]# ls
1587552516.log                              passwd     test.txt.bak  图片  桌面
anaconda-ks.cfg                             program    公共          文档
hehe                                        study      模板          下载
mysql57-community-release-el7-8.noarch.rpm  test.txt2  视频          音乐
[root@luckily ~]# rm -f test.txt2
[root@luckily ~]# ls
1587552516.log                              passwd        公共  文档
anaconda-ks.cfg                             program       模板  下载
hehe                                        study         视频  音乐
mysql57-community-release-el7-8.noarch.rpm  test.txt.bak  图片  桌面
[root@luckily ~]# rm -f hehe
[root@luckily ~]# ls
1587552516.log                              passwd   test.txt.bak  视频  下载
anaconda-ks.cfg                             program  公共          图片  音乐
mysql57-community-release-el7-8.noarch.rpm  study    模板          文档  桌面
[root@luckily ~]# cd study
[root@luckily study]# ls
day01  day02  day03  Linux
[root@luckily study]# cd Linux
[root@luckily Linux]# ls
Linux050201.c
[root@luckily Linux]# cd ..
[root@luckily study]# cd ..
[root@luckily ~]# cd study
[root@luckily study]# cd day03
[root@luckily day03]# ls
Jindutiao  Jindutiao.c  process  process.c
[root@luckily day03]# cd ..
[root@luckily study]# cd Linux
[root@luckily Linux]# ls
Linux050201.c
[root@luckily Linux]# vim SetNum.c
[root@luckily Linux]# vim SetNum.c
[root@luckily Linux]# git add SetNum.c
[root@luckily Linux]# git commit .
终止提交因为提交说明为空。
[root@luckily Linux]# git push
warning: push.default 未设置，它的默认值将会在 Git 2.0 由 'matching'
修改为 'simple'。若要不再显示本信息并在其默认值改变后维持当前使用习惯，
进行如下设置：

  git config --global push.default matching

若要不再显示本信息并从现在开始采用新的使用习惯，设置：

  git config --global push.default simple

参见 'git help config' 并查找 'push.default' 以获取更多信息。
（'simple' 模式由 Git 1.7.11 版本引入。如果您有时要使用老版本的 Git，
为保持兼容，请用 'current' 代替 'simple' 模式）

Username for 'https://github.com': luckily777
Password for 'https://luckily777@github.com': 
To https://github.com/Luckily777/Linux.git
 ! [rejected]        master -> master (fetch first)
error: 无法推送一些引用到 'https://github.com/Luckily777/Linux.git'
提示：更新被拒绝，因为远程版本库包含您本地尚不存在的提交。这通常是因为另外
提示：一个版本库已推送了相同的引用。再次推送前，您可能需要先合并远程变更
提示：（如 'git pull'）。
提示：详见 'git push --help' 中的 'Note about fast-forwards' 小节。
[root@luckily Linux]# git config -- global push.default simple
error: key does not contain a section: global
[root@luckily Linux]# git add SetNum.c
[root@luckily Linux]# git commit . 
[master 3fcaae1] 设置行号
 1 file changed, 10 insertions(+)
 create mode 100644 SetNum.c
[root@luckily Linux]# git push
warning: push.default 未设置，它的默认值将会在 Git 2.0 由 'matching'
修改为 'simple'。若要不再显示本信息并在其默认值改变后维持当前使用习惯，
进行如下设置：

  git config --global push.default matching

若要不再显示本信息并从现在开始采用新的使用习惯，设置：

  git config --global push.default simple

参见 'git help config' 并查找 'push.default' 以获取更多信息。
（'simple' 模式由 Git 1.7.11 版本引入。如果您有时要使用老版本的 Git，
为保持兼容，请用 'current' 代替 'simple' 模式）

Username for 'https://github.com': Luckily777
Password for 'https://Luckily777@github.com': 
To https://github.com/Luckily777/Linux.git
 ! [rejected]        master -> master (fetch first)
error: 无法推送一些引用到 'https://github.com/Luckily777/Linux.git'
提示：更新被拒绝，因为远程版本库包含您本地尚不存在的提交。这通常是因为另外
提示：一个版本库已推送了相同的引用。再次推送前，您可能需要先合并远程变更
提示：（如 'git pull'）。
提示：详见 'git push --help' 中的 'Note about fast-forwards' 小节。
[root@luckily Linux]# git pull
remote: Enumerating objects: 13, done.
remote: Counting objects: 100% (13/13), done.
remote: Compressing objects: 100% (11/11), done.
remote: Total 12 (delta 2), reused 11 (delta 1), pack-reused 0
Unpacking objects: 100% (12/12), done.
来自 https://github.com/Luckily777/Linux
   70cf402..8b695a0  master     -> origin/master
Merge made by the 'recursive' strategy.
 7Linux042901.cpp | 62 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 7Linux042902.cpp | 64 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 7Linux042903.cpp | 29 +++++++++++++++++++++++++++++
 7Linux042904.cpp | 22 ++++++++++++++++++++++
 4 files changed, 177 insertions(+)
 create mode 100644 7Linux042901.cpp
 create mode 100644 7Linux042902.cpp
 create mode 100644 7Linux042903.cpp
 create mode 100644 7Linux042904.cpp
[root@luckily Linux]# git add SetNum.c
[root@luckily Linux]# git commit .
# 位于分支 master
# 您的分支领先 'origin/master' 共 2 个提交。
#   （使用 "git push" 来发布您的本地提交）
#
无文件要提交，干净的工作区
[root@luckily Linux]# git push
warning: push.default 未设置，它的默认值将会在 Git 2.0 由 'matching'
修改为 'simple'。若要不再显示本信息并在其默认值改变后维持当前使用习惯，
进行如下设置：

  git config --global push.default matching

若要不再显示本信息并从现在开始采用新的使用习惯，设置：

  git config --global push.default simple

参见 'git help config' 并查找 'push.default' 以获取更多信息。
（'simple' 模式由 Git 1.7.11 版本引入。如果您有时要使用老版本的 Git，
为保持兼容，请用 'current' 代替 'simple' 模式）

Username for 'https://github.com': Luckily777
Password for 'https://Luckily777@github.com': 
Counting objects: 7, done.
Delta compression using up to 4 threads.
Compressing objects: 100% (5/5), done.
Writing objects: 100% (5/5), 620 bytes | 0 bytes/s, done.
Total 5 (delta 2), reused 0 (delta 0)
remote: Resolving deltas: 100% (2/2), completed with 1 local object.
To https://github.com/Luckily777/Linux.git
   8b695a0..7cd999f  master -> master
[root@luckily Linux]# git config --global push.default simple
[root@luckily Linux]# 

