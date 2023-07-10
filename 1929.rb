require 'prime';M,N=gets.split.map(&:to_i);Prime.each(N){|p|puts p if p>=M}
