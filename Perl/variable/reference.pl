#!/usr/bin/env perl

# 变量name是一个引用，指向堆数据"junmajinlong"
# 即：(name)0xabc -> "junmajinlong"
my $name = "junmajinlong";

# 获取堆数据的引用，即它的地址，将地址保存到另一个变量中
my $name_ref = \$name;

# 因此，$name_ref等价于变量$name
print "$name\n";        # ${name}
print "$$name_ref\n";   # ${$name_ref}


