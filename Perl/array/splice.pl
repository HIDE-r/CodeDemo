#!/usr/bin/env perl

use 5.010;

# splice ARRAY				清空ARRAY
print "\nsplice ARRAY:\n";
@arr=qw(perl py php shell);

@new_arr=splice @arr;
say "original arr: @arr";   # 输出：空
say "new arr: @new_arr";    # 输出原列表内容

# splice ARRAY,OFFSET			从OFFSET处开始删除元素直到结尾
print "\nsplice ARRAY,OFFSET:\n";
@arr=qw(perl py php shell);

@new_arr=splice @arr,2;
say "original arr: @arr";   # 输出：perl py
say "new arr: @new_arr";    # 输出：php shell

# splice ARRAY,OFFSET,LENGTH		表示从OFFSET处开始向后删除LENGTH个元素。
print "\nsplice ARRAY,OFFSET,LENGTH:\n";
@arr=qw(perl py php shell ruby);

@new_arr=splice @arr,2,2;
say "original arr: @arr";   # 输出：perl py ruby
say "new arr: @new_arr";    # 输出：php shell

# splice ARRAY,OFFSET,LENGTH,LIST	表示将LIST插入到删除的位置，也就是替换数组的部分位置连续的元素。
print "\nsplice ARRAY,OFFSET,LENGTH,LIST:\n";
@arr=qw(perl py php shell ruby);
@list=qw(java c);

@new_arr=splice @arr,2,2,@list;
say "original arr: @arr";   # 输出：perl py java c ruby
say "new arr: @new_arr";    # 输出：php shell
