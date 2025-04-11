#!/usr/bin/env perl

foreach my $arg (@ARGV) {
	print "arg: $arg\n";
}

print '$ARGV[0] ---> ',$ARGV[0],"\n",
      '$ARGV[1] ---> ',$ARGV[1],"\n",
      '$ARGV[2] ---> ',$ARGV[2],"\n",

print '$ARGV ---> ',$ARGV,"\n",
