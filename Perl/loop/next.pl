#!/usr/bin/env perl

use feature 'say';
# 当变量i等于5时进入下一轮循环
# 该循环将输出1 2 3 4 6 7 8 9 10
for my $i (1..10){
  $i == 5 and next;
  say $i;
}

