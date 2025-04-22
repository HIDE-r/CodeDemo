#!/usr/bin/env perl

use feature 'say';

# 由列表创建而成，列表的格式为(k1,v1,k2,v2,k3,v3)，即按照一个键一个值的方式构建hash
my %person = (
  "name"  , "junmajinlong",
  "age"   , 23,
  "gender", "male"
);

# Perl中，几乎总是可以使用=>代替逗号。因此，下面是等价的方式：
# 当key的名称符合标识符命名规范时(只包含下划线、字母和数值，且非数值开头)，可以省略key的引号
my %person = (
  "name"  => "junmajinlong",
  "age"   => 23,
  "gender"=> "male"
);

# hash变量不能内插到双引号。
# 在列表上下文，hash变量会自动隐式转换为(k1,v1,k2,v2,k3,v3)格式的列表。
# 在标量上下文，如果hash为空，则转换为数值0，如果hash结构非空，则hash变量会转换为m/n格式的标量，m表示当前的键值对数量，n表示hash结构当前的容量
say "%person";   # 直接输出：%person
