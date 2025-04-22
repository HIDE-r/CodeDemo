#!/usr/bin/env perl

use feature 'say';
# Perl提供了一个名为each的函数，它可用于迭代数组和hash。
# 在列表上下文，each会返回数组的(index, value)或hash的(key, value)
# 在标量上下文，each会返回当前所处的index或key。
# 但是，each是有问题的：each @arr取完最后一个元素后，不会重置迭代指针，下次再执行each @arr，在列表上下文将返回空列表，在标量上下文将返回undef，再之后才继续从索引0、1、2开始。
# Perl官方手册(perldoc -f each)建议尽量使用foreach迭代取代while each

my @arr = (11,22,33,44);

# 列表上下文，each返回(index, value)
while(my ($idx, $v) = each @arr) {
  say "index: $idx, value: $v";
}

# 错误范例, each 没有重置迭代指针

print "\neach 错误范例:\n";
my @arr = (11,22,33,44);
for my $v (@arr){
  say "index: ".(each @arr).", value: $v";
}
for my $v (@arr){
  say "index: ".(each @arr).", value: $v";
}
