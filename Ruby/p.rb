words = [1, 2, 3, 1, 2]
 
#puts Hash[words.group_by{ |w| w }.map { |w, words| [w, words.size] }]

v = Hash[words.group_by {|w| w}]
puts v

#words = %w(dog dog cat)
#puts words 
#puts Hash[words.group_by{ |w| w }.map { |w, words| [w, words.size] }]
