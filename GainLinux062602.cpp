[root@luckily ~]# ls
1587552516.log                              passwd   test.txt.bak  视频  下载
anaconda - ks.cfg                             program  公共          图片  音乐
mysql57 - community - release - el7 - 8.noarch.rpm  study    模板          文档  桌面
[root@luckily ~]# vim 0626.c
[root@luckily ~]# tar czvf 0626.tar.gz 0626
tar: 0626：无法 stat : 没有那个文件或目录
tar : 由于前次错误，将以上次的错误状态退出
[root@luckily ~]# tar - czvf 0626.tar.gz 0626
tar: 0626：无法 stat : 没有那个文件或目录
tar : 由于前次错误，将以上次的错误状态退出
[root@luckily ~]# tar - czvf 0626.tar.gz 0626.c
0626.c
[root@luckily ~]# ls
0626.c           mysql57 - community - release - el7 - 8.noarch.rpm  test.txt.bak  图片  桌面
0626.tar.gz      passwd                                      公共          文档
1587552516.log   program                                     模板          下载
anaconda - ks.cfg  study                                       视频          音乐
[root@luckily ~]# rm - rf 0626.c
[root@luckily ~]# ls
0626.tar.gz                                 passwd        公共  文档
1587552516.log                              program       模板  下载
anaconda - ks.cfg                             study         视频  音乐
mysql57 - community - release - el7 - 8.noarch.rpm  test.txt.bak  图片  桌面
[root@luckily ~]# tar - xzvf 0626.tar.gz
0626.c
[root@luckily ~]# ls
0626.c           mysql57 - community - release - el7 - 8.noarch.rpm  test.txt.bak  图片  桌面
0626.tar.gz      passwd                                      公共          文档
1587552516.log   program                                     模板          下载
anaconda - ks.cfg  study                                       视频          音乐
[root@luckily ~]# rm - f 0626.c
[root@luckily ~]# rm - f 0626.tar.gz
