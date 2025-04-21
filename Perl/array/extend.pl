#!/usr/bin/env perl

use feature 'say';

my @arr = (11,22,33);
@arr = (@arr, 44, 55);  # 扩展数组
say "@arr";  # 11 22 33 44 55
