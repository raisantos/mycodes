puts "Insira o numero n de elementos dos vetores:"
n = gets.to_i

vetor_1 = []
for i in (0...n)
	puts "Insira o elemento numero #{i+1} do vetor 1"
	vetor_1[i] = gets.to_i
end

vetor_2 = []
for i in (0...n)
	puts "Insira o elemento numero #{i+1} do vetor 2"
	vetor_2[i] = gets.to_i
end

soma = 0
for i in (0...n)
	soma+=vetor_1[i]*vetor_2[i]
end

print soma
puts 
