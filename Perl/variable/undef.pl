#!/usr/bin/env perl

# use strict;
use utf8;

my $name = "foo";
my $gender = undef;
print defined($name), "\n";   # 1

print "name is ";
if(defined($name)){
  print "defined", "\n";
} else {
  print "undefined", "\n";
}

print "gender is ";
if(defined($gender)){
  print "defined", "\n";
} else {
  print "undefined", "\n";
}

# 没有定义变量默认为 undef
print "age is ";
if(defined($age)){
  print "defined", "\n";
} else {
  print "undefined", "\n";
}
