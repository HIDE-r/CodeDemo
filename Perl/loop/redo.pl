#!/usr/bin/env perl

use feature 'say';
# 当变量i等于5时，再次执行第5轮循环
# 该循环将输出2 3 4 6 6 7 8 9 10 11
for my $i (1..10){
  $i++;
  $i == 5 and redo;
  say $i;
}

