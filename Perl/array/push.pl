#!/usr/bin/env perl

use feature 'say';
# push向数组尾部追加一个元素或一个列表，返回追加完成后数组长度

my @arr1 = (11,22,33);
push @arr1, 44;      # 追加单个元素
push @arr1, 55, 66;  # 追加列表，列表的小括号被省略
say push @arr1, (77,88); # 输出8，push返回数组长度

say "@arr1";  # 11 22 33 44 55 66 77 88
