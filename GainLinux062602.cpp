[root@luckily ~]# ls
1587552516.log                              passwd   test.txt.bak  ��Ƶ  ����
anaconda - ks.cfg                             program  ����          ͼƬ  ����
mysql57 - community - release - el7 - 8.noarch.rpm  study    ģ��          �ĵ�  ����
[root@luckily ~]# vim 0626.c
[root@luckily ~]# tar czvf 0626.tar.gz 0626
tar: 0626���޷� stat : û���Ǹ��ļ���Ŀ¼
tar : ����ǰ�δ��󣬽����ϴεĴ���״̬�˳�
[root@luckily ~]# tar - czvf 0626.tar.gz 0626
tar: 0626���޷� stat : û���Ǹ��ļ���Ŀ¼
tar : ����ǰ�δ��󣬽����ϴεĴ���״̬�˳�
[root@luckily ~]# tar - czvf 0626.tar.gz 0626.c
0626.c
[root@luckily ~]# ls
0626.c           mysql57 - community - release - el7 - 8.noarch.rpm  test.txt.bak  ͼƬ  ����
0626.tar.gz      passwd                                      ����          �ĵ�
1587552516.log   program                                     ģ��          ����
anaconda - ks.cfg  study                                       ��Ƶ          ����
[root@luckily ~]# rm - rf 0626.c
[root@luckily ~]# ls
0626.tar.gz                                 passwd        ����  �ĵ�
1587552516.log                              program       ģ��  ����
anaconda - ks.cfg                             study         ��Ƶ  ����
mysql57 - community - release - el7 - 8.noarch.rpm  test.txt.bak  ͼƬ  ����
[root@luckily ~]# tar - xzvf 0626.tar.gz
0626.c
[root@luckily ~]# ls
0626.c           mysql57 - community - release - el7 - 8.noarch.rpm  test.txt.bak  ͼƬ  ����
0626.tar.gz      passwd                                      ����          �ĵ�
1587552516.log   program                                     ģ��          ����
anaconda - ks.cfg  study                                       ��Ƶ          ����
[root@luckily ~]# rm - f 0626.c
[root@luckily ~]# rm - f 0626.tar.gz
