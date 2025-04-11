#!/usr/bin/env perl

# echo 1111 | ./null_file_handle.pl	打印 1111
#
# ./null_file_handle.pl argv.pl 	打印 argv.pl 的内容

foreach my $arg (@ARGV) {
	print "arg: $arg\n";
}

# ARGV 数组每个参数作为文件名, 即有外部参数, 遍历文件的每一行
# 当 ARGV 内容为空时, 即没有参数, 默认从 STDIN 读取
#
# $ARGV 表示当前处理行的文件名
while (<>) {
    print "From file $ARGV: $_";
}
