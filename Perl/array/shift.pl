#!/usr/bin/env perl

use feature 'say';
# shift移除并返回数组第一个元素，数组为空则返回undef

my @arr2 = (11,22,33);
say shift @arr2;  # 11
say shift @arr2;  # 22
say shift @arr2;  # 33
say shift @arr2;  # undef，警告模式下会给出警告
