#!/usr/bin/env perl
@names = ("google", "runoob", "taobao");

# @names 数组在标量上下文会转换为数组长度
print "length: " . scalar(@names) . "\n";

# 不推荐直接写数组, 无法清晰知道上下文
print "length: " . @names . "\n";

# 数组长度是指最大序号 +1
$names[50]="test";

print "length: " . scalar(@names) . "\n";
