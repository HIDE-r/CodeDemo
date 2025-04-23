#!/usr/bin/env perl

use feature 'say';

my $a=3;

# next总是跳转到continue代码块开头
while($a<8){
  if($a<5){
    say '$a in main if block: ',$a;
    next;
  }
} continue {
  say '$a in continue block: ',$a;
  $a++;
}

