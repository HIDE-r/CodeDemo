#!/usr/bin/env perl

use Carp 'croak';
sub f{
  croak "error in f";
}

f;
