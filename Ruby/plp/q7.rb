print "Insira o numero n de elementos do vetor: "
n = gets.to_i
print "Insira os k termos: "
k = gets.to_i

vetor = []
for i in (0...n)
	vetor[i] = i+1
end

print vetor.combination(k).to_a
puts
