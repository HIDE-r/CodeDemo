#!/usr/bin/env perl

# \u 修改下一个字符为大写
# \U 修改后面所有字符大写 
# \l 修改下一个字符小写 
# \L 修改后面所有字符小写 
# \Q 使后面的所有字符都成为字面符号
# \E 结束\U \L或\Q的效果

print "\uabc", "\n"; # 输出Abc
print "\Uabc", "\n"; # 输出ABC
print "ab\Ucxyz", "\n";   # 输出abCXYZ
print "ab\Ucx\Eyz", "\n"; # 输出abCXyz


