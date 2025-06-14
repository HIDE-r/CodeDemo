#!/usr/bin/env perl

# 常见的标量上下文包括：
#
# - 标量变量作为左值，例如$arr = xxx，赋值操作符左边的$表明这是一个标量上下文，赋值操作符右边需要提供标量数据
# - 加减乘除等算术运算符、大小比较、等值比较、字符串串联、字符串重复，等等，这些操作符要求标量上下文，需要标量数据
# - if、while的条件表达式部分，是标量上下文，严格来说是布尔标量上下文，要求布尔值
# - 操作数值、操作字符串的环境，需要标量上下文，例如正则匹配、正则替换、abs()取绝对值，等等
#
# 常见的列表上下文包括：
#
# - 数组变量作为左值，例如@arr = xxx，赋值操作符左边的@表明这是一个列表上下文，赋值操作符右边需要提供列表数据
# - hash变量作为左值，例如%p = xxx，其中%表明这是一个列表上下文，赋值操作符右边需要提供列表数据
# - print/say的参数，例如say 11,22,33;，各参数组成一个列表
# - for、foreach、each等迭代语句，需要列表上下文
# - 用于操作列表的函数，其某个参数需要列表上下文，例如grep、sort、map等列表类函数

use feature 'say';

my @arr = 33;    # 隐式转换
my @arr = (33);  # 显式转换

my @arr = @arr0;   # 隐式转换
my @arr = (@arr0); # 显式转换

my @arr = %p;     # 隐式转换
my @arr = (%p);   # 显式转换

# 如果提供的是数组或者hash，则perl会尝试自动隐式地将它们转换为标量类型。转换规则如下：
#
# - 数组转换为标量得到的是数组的长度
# - hash转换为标量得到的是M/N格式的字符串，N表示hash的容量，M表示hash当前的键值对数量

my @arr = (11,22,33,44);

say 1+@arr; # 5，等价于1+4

say @arr+0; # 使用加0操作得到标量环境且不影响标量结果

say ~~@arr; # 单个~是位取反操作，要求标量数据，两次位取反得到原数据的标量形式

say scalar @arr; # 使用scalar强制转换为标量数据

# 标量上下文中的列表，会返回最后一个列表元素作为标量数据，其他元素被丢弃。
# 实际上，当遇到标量上下文中的列表时，会从前向后逐步评估每一个元素，然后丢弃这个元素的评估结果，直到评估完最后一个元素返回它。
my $a = (11,22,33);
my $b = qw(11 22 33);
say $a, "-", $b;   # 输出：33-33

my $c = ($a = 3, $b = 4);
say "$a-$b-$c";   # 输出：3-4-4
