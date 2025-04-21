#!/usr/bin/env perl

# Perl中可以使用q实现单引号相同的引用功能，使用qq实现双引号相同的引用功能。
# q()和qq()的括号，它们是引用的起始符和终止符，它们可以被替换为其他成对的符号：要么是前后相同的单个标点字符，要么是对称的括号(大括号、小括号、尖括号、中括号都可以)。
use feature 'say';

say q!abc!;
say q<abc>;
say qq{abc};

say qq{abc\}def};  # 转义终止符
say qq{abc\{def};  # 转义起始符
say qq ad\aefa;    # 转义起始符a，输出daef, 这里起始a和终止a是成对的, 作为起始符和终止符

say qq{ab{cd}e};   # ab{cd}e

