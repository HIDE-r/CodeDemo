#!/usr/bin/env perl

my $res;
my $ok = eval { $res = some_func(); 1};
if ($ok){
  # ...代码正确...
} else {
  # ...eval代码出错...
  my $err = $@;
}

