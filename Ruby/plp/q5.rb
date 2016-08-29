print "Linhas da matriz: "
linhas = gets.to_i
print "Colunas da matriz: "
colunas = gets.to_i

matriz = []
for i in (0...linhas)
	matriz[i] = Array.new(colunas)
	for j in (0...colunas)
		matriz[i][j] = gets.to_i
	end
end

vetor = []
for i in (0...colunas)
	vetor[i] = gets.to_i
end

for i in (0...linhas)
	res = 0
	for j in (0...colunas)
		res+=matriz[i][j]*vetor[j]
	end
	print res, " "
end
puts
