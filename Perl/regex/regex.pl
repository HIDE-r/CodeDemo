#!/usr/bin/env perl

use feature 'say';

my $str = "abAB12cdCD34";
say "matched" if($str =~ /\d+/);
say "not matched" if($str =~ /xy/);

######### 列表上下文 #########

# 捕获分组： 
# 在列表上下文，匹配成功，且使用小括号分组捕获时，返回各分组内容
my @arr = $str=~/(\d+)/;
say "@arr";   # 12
@arr = $str=~/(\d+)[^0-9]+(\d+)/;
say "@arr";   # 12 34

# 无捕获分组:
# 在列表上下文，匹配成功，且未使用小括号分组捕获时，
# 如果未使用g修饰符全局匹配，则返回列表`(1)`表示匹配成功, 列表 () 表示匹配失败
# 如果使用g修饰符全局匹配，则返回全局匹配成功的内容列表
my @arr1 = $str=~/\s+/;
say "@arr1";   # 1
my @arr2 = $str=~/\d+/g;
say "@arr2";   # 12 34
