#!/usr/bin/env perl

use feature 'say';

# $& 或 $MATCH 获取匹配到的内容
my $str = "abAB12cdCD34";
say "matched: $&" if($str =~ /\d+/);

