#!/usr/bin/env perl

use feature 'say';

# 迭代每个列表元素时，元素是按引用传递给控制变量的，控制变量在栈中保存了元素的内存地址，每次迭代时控制变量的地址都发生改变。因此可以推断，每次迭代时，Perl都会重新声明控制变量，每次声明的控制变量仅在本次迭代过程中有效。
#
# 控制变量是可以省略的，此时将使用Perl的默认标量变量$_。
my @arr = (11, 22, 33, 44);
my $v = 3333;
say \$v;
say '---- before ----';
for my $v (@arr) { say \$v; }
say '---- after ----';
say \$v;
say "$v";

# 输出：
#   SCALAR(0x22f3d10)
#   ---- before ----
#   SCALAR(0x2277ab0)
#   SCALAR(0x2277a98)
#   SCALAR(0x2277b40)
#   SCALAR(0x2277b58)
#   ---- after ----
#   SCALAR(0x22f3d10)
#   3333

