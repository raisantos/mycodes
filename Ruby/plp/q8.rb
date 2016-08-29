print "Insira o numero n de elementos do vetor: "
n = gets.to_i

vetor = []
for i in (0...n)
	vetor[i] = i+1
end

print vetor.permutation.to_a
puts
