//�鿴mariadb
[root@luckily ~]# rpm - qa | grep mariadb

[root@luckily ~]# yum install - y mariadb - server
[root@luckily ~]# yum install - y mariadb - devel


//ת��yumԴ

[root@luckily ~]# cd / etc / yum.repos.d /
[root@luckily yum.repos.d]# mv / etc / yum.repos.d / CentOS - Base.repo / etc / yum.repos.d / CentOS - Base.repo_bak
mv���Ƿ񸲸�"/etc/yum.repos.d/CentOS-Base.repo_bak"�� y
[root@luckily yum.repos.d]# wget - O / etc / yum.repos.d / CentOS - Base.repo http ://mirrors.aliyun.com/repo/Centos-7.repo
--2020 - 08 - 05 17:02 : 07--http ://mirrors.aliyun.com/repo/Centos-7.repo
    ���ڽ������� mirrors.aliyun.com(mirrors.aliyun.com)... 111.32.158.127, 111.32.130.240, 111.32.158.129, ...
    �������� mirrors.aliyun.com(mirrors.aliyun.com) | 111.32.158.127 | : 80...�����ӡ�
    �ѷ��� HTTP �������ڵȴ���Ӧ... 200 OK
    ���ȣ�2523(2.5K)[application / octet - stream]
    ���ڱ����� : �� / etc / yum.repos.d / CentOS - Base.repo��

    100 % [============================================ = > ] 2, 523       --. - K / s ��ʱ 0s

    2020 - 08 - 05 17:02 : 07 (152 MB / s) - �ѱ��� �� / etc / yum.repos.d / CentOS - Base.repo��[2523 / 2523])

    [root@luckily yum.repos.d]# yum makecache
    �Ѽ��ز����fastestmirror, langpacks
    Loading mirror speeds from cached hostfile
    * base: mirrors.aliyun.com
    * extras : mirrors.aliyun.com
    * updates : mirrors.aliyun.com
    base | 3.6 kB  00 : 00 : 00
    extras | 2.9 kB  00 : 00 : 00
    mysql - connectors - community | 2.5 kB  00 : 00 : 00
    mysql - tools - community | 2.5 kB  00 : 00 : 00
    mysql57 - community | 2.5 kB  00 : 00 : 00
    updates | 2.9 kB  00 : 00 : 00
    Ԫ���ݻ����ѽ���


//�鿴
[root@luckily ~]# ps aux | grep mysqld
//�޸ĵ�¼
[root@luckily ~]# vim / etc / my.cnf

//�鿴״̬

[root@luckily ~]# service mysqld status
Redirecting to / bin / systemctl status mysqld.service
�� mysqld.service - MySQL Server
Loaded : loaded(/ usr / lib / systemd / system / mysqld.service; enabled; vendor preset : disabled)
Active : active(running) since �� 2020 - 08 - 05 16:59 : 53 CST; 27min ago

