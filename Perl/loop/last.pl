#!/usr/bin/env perl

use feature 'say';
# 当变量i等于5时退出循环
# 该循环将输出1 2 3 4
for my $i (1..10){
  if($i==5){
    last;
  }
  say $i;
}

