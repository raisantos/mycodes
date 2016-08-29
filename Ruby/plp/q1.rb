puts "Insira o numero n de elementos :"
n = gets.to_i

vetor = []
for i in (0...n)
	puts "Insira o elemento numero #{i+1}"
	vetor[i] = gets.to_i
end

print vetor.reverse, "\n"
 
