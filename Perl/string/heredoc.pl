#!/usr/bin/env perl

# 可以为heredoc的起始符加上单引号、双引号以及反引号。它们的效果和普通的单、双、反引号的效果一样：
#
# 单引号内只允许\\ \'这两种转义
# 双引号内允许变量内插、表达式内插、反斜线转义、反斜线字符序列
# 加反引号` `，表示将字符串放进Shell环境执行(和Shell的命令替换效果差不多)
# 不加引号等价于加双引号，加反斜线前缀\EOF等价于加单引号
$heredoc = <<EOF;
here is heredoc.
heredoc newline.
EOF

print $heredoc . "\n";

print <<`EOF`;
  date +"%F %T"
EOF

print "\n";
# 从Perl v5.26开始，可以在heredoc的起始符EOF或被引用的EOF前加上波浪号
# 加上前缀波浪号，使得heredoc允许终止符被缩进，但是heredoc的内容必须不能出现在终止符之前，否则报错
print <<~EOF;
  line1
    line2
  line3
  EOF
