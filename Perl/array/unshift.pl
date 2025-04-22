#!/usr/bin/env perl

use feature 'say';
# unshift向数组头部添加一个元素或一个列表，返回追加完成后数组长度
my @arr2 = (11,22,33);
unshift @arr2, 'a', 'b';
unshift @arr2, qw(aa bb);
say "@arr2"; # aa bb a b 11 22 33
