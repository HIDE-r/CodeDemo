#!/usr/bin/env perl

# pop从数组中移除并返回最后一个元素，数组为空则返回undef
use feature 'say';

my @arr1 = (11,22,33);
say pop @arr1;  # 33
say pop @arr1;  # 22
say pop @arr1;  # 11
say pop @arr1;  # undef，警告模式下会给出警告
