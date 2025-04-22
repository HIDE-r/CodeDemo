#!/usr/bin/env perl

use feature 'say';

my %h;
my ($x, $y) = qw(x y);

$h{$x, $y, "name"} = "junmajinlong.com";

# 当使用逗号分隔多份数据组合为key时，Perl会自动将每份数据使用下标连接符(默认值为\034)连接起来，最终得到的字符串作为key。\034通常可以认为是安全的连接符，它是一个ASCII中的控制字符，几乎不会出现在文本数据中
say $h{$x, $y, "name"};
say $h{"$x\034$y\034name"};  # 等价形式

