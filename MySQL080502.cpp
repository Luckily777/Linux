//��¼����MySQL

[root@luckily / ]# service mysqld restart
Redirecting to / bin / systemctl restart mysqld.service
[root@luckily / ]# mysql
Welcome to the MySQL monitor.Commands end with; or \g.
Your MySQL connection id is 2
Server version : 5.7.29 MySQL Community Server(GPL)

Copyright(c) 2000, 2020, Oracleand /or its affiliates.All rights reserved.

Oracle is a registered trademark of Oracle Corporation and /or its
affiliates.Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help.Type '\c' to clear the current input statement.

mysql > use mysql;
Reading table information for completion of tableand column names
You can turn off this feature to get a quicker startup with - A

Database changed
mysql > show tables;//չʾ��Ϣ��
//�鿴�汾
mysql > select version();
//�鿴��������
[root@luckily / ] #netstat - anp | grep 3306��

//��ʾ���ݿ�
show databases;

�������ݿ�
mysql > create database test1;

//��ʾ�������ݿ�����

mysql > show create database test1;

�鿴��������ַ���
mysql > show variables like '%character%';

//ɾ����
mysql > drop database test1;
Query OK, 0 rows affected(0.02 sec)

