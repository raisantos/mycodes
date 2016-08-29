linhas = gets.to_i
colunas = gets.to_i

vetor = Array.new(linhas)
for i in (0...linhas)
	vetor[i] = Array.new(colunas)
	for j in (0...colunas)
		vetor[i][j] = gets.to_i
	end
end

#----------------------
for k in vetor
	puts k.inspect
end
#----------------------
=begin
cont=0
for i in (0...linhas)
	for j in (0...colunas)
		num = vetor[i][j]
=end
#vetor.each_index{|x| vetor[x].each_index{|y| puts vetor[x][y]}}
=begin			cont+=1
			puts cont
		end
	end
end

if(cont > linhas*colunas)
	puts "tem"
else
	puts "nao tem"
end
=end

v = Array.new(vetor)
print v
puts
