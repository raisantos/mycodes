def derangements(n)
  ary = (1 .. n).to_a
  ary.permutation.select do |perm|
    ary.zip(perm).all? {|a,b| a != b}
  end
end

derangements(3).each{|d|p d}
