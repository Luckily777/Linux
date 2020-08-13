//数据库的基础操作

[root@Seven7 ~]# netstat - anp | grep 3306
tcp        0      0 0.0.0.0:3306            0.0.0.0 : *LISTEN      1572 / mysqld
[root@Seven7 ~]# serive mariadb status
- bash: serive: command not found
[root@Seven7 ~]# mysql
Welcome to the MariaDB monitor.Commands end with; or \g.
Your MariaDB connection id is 6
Server version : 5.5.65 - MariaDB MariaDB Server

Copyright(c) 2000, 2018, Oracle, MariaDB Corporation Aband others.

Type 'help;' or '\h' for help.Type '\c' to clear the current input statement.

MariaDB[(none)] > serive mariadb status;
ERROR 1064 (42000) : You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'serive mariadb status' at line 1
MariaDB[(none)] > quit;
Bye
[root@Seven7 ~]# serive mariadb status
- bash: serive: command not found
[root@Seven7 ~]# service mariadb status
Redirecting to / bin / systemctl status mariadb.service
● mariadb.service - MariaDB database server
Loaded : loaded(/ usr / lib / systemd / system / mariadb.service; disabled; vendor preset : disabled)
Active : active(running) since Fri 2020 - 08 - 07 15:37 : 53 CST; 6 days ago
Process : 1387 ExecStartPost = / usr / libexec / mariadb - wait - ready $MAINPID(code = exited, status = 0 / SUCCESS)
Process : 1350 ExecStartPre = / usr / libexec / mariadb - prepare - db - dir % n(code = exited, status = 0 / SUCCESS)
Main PID : 1386 (mysqld_safe)
CGroup : / system.slice / mariadb.service
├─1386 / bin / sh / usr / bin / mysqld_safe --basedir = / usr
└─1572 / usr / libexec / mysqld --basedir = / usr --datadir = / var / lib / mysql --plugin - dir = / ...

Aug 07 15 : 37 : 51 Seven7 systemd[1] : Starting MariaDB database server...
Aug 07 15 : 37 : 51 Seven7 mariadb - prepare - db - dir[1350] : Database MariaDB is probably initiali...e.
Aug 07 15 : 37 : 51 Seven7 mariadb - prepare - db - dir[1350] : If this is not the case, make sure th...r.
Aug 07 15:37 : 51 Seven7 mysqld_safe[1386] : 200807 15 : 37 : 51 mysqld_safe Logging to '/var/lo...g'.
    Aug 07 15 : 37 : 51 Seven7 mysqld_safe[1386] : 200807 15 : 37 : 51 mysqld_safe Starting mysqld dae...sql
    Aug 07 15 : 37 : 53 Seven7 systemd[1] : Started MariaDB database server.
    Hint : Some lines were ellipsized, use - l to show in full.
    [root@Seven7 ~]# mysql
    Welcome to the MariaDB monitor.Commands end with; or \g.
    Your MariaDB connection id is 7
    Server version : 5.5.65 - MariaDB MariaDB Server

    Copyright(c) 2000, 2018, Oracle, MariaDB Corporation Aband others.

    Type 'help;' or '\h' for help.Type '\c' to clear the current input statement.

    MariaDB[(none)] > show databases;
+-------------------- +
| Database |
+-------------------- +
| information_schema |
| day01              |
| mysql              |
| performance_schema |
| scott              |
| test1 |
+-------------------- +
6 rows in set(0.00 sec)

MariaDB[(none)] > show tables;
ERROR 1046 (3D000) : No database selected
MariaDB[(none)] > ues day01;
ERROR 1064 (42000) : You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'ues day01' at line 1
MariaDB[(none)] > use day01;
Reading table information for completion of tableand column names
You can turn off this feature to get a quicker startup with - A

Database changed
MariaDB[day01] > show tables;
+---------------- - +
| Tables_in_day01 |
+---------------- - +
| time1           |
| user_info |
+---------------- - +
2 rows in set(0.00 sec)

MariaDB[day01] > create database helloworld charset = utf8;
Query OK, 1 row affected(0.00 sec)

MariaDB[day01] > show create database helloworld;
+------------ + -------------------------------------------------------------------- - +
| Database | Create Database |
+------------ + -------------------------------------------------------------------- - +
| helloworld | CREATE DATABASE `helloworld` /*!40100 DEFAULT CHARACTER SET utf8 */ |
+------------ + -------------------------------------------------------------------- - +
1 row in set(0.00 sec)

MariaDB[day01] > drop database helloworld;
Query OK, 0 rows affected(0.00 sec)
