--Questao 1 -> Fatorial
fat :: (Integral x) => x -> x 								--calcula o fatorial recursivamente.
fat 0 = 1													--fatorial de um numero é igual ao numero multiplicado pelo
fat n = n * fat(n - 1)										--fatorial do anterior.
--Fim Questao 1
--------------------------------------------------------------
--Questao 2 -> Fibonacci
fib :: (Integral x) => x -> x 								--Calcula o N numero de fibonacci recursivamente
fib 1 = 0													--Casos base
fib 2 = 1													--O N-ésimo numero de fibonacci é igual ao seus dois antecessores.
fib 3 = 1
fib n = fib(n-1) + fib(n-2)
--Fim Questao 2
--------------------------------------------------------------
--Questao 3 -> Uniao
esta_em x [] = False								--Funçao que recebe um valor e um vetor
esta_em x (y:ys)
    |x == y = True
    |otherwise = esta_em x ys

uniao:: [Int] -> [Int] -> [Int]								--Pega duas listas e une
uniao (as) (b:bs)
	|not (esta_em b as)= uniao as bs ++ b  					--Se o item 'b' nao estiver na lista 'as', ele acrescenta no vetor que será retornado
    |otherwise = uniao as bs as								--Se não, simplesmente tenta com o proximo elemento
--Fim Questao 3        
--------------------------------------------------------------
--Questao 4 -> Intersecçao
esta_em x [] = False								--Funçao que recebe um valor e um vetor
esta_em x (y:ys)
    |x == y = True
    |otherwise = esta_em x ys
    
interseccao xs [] = []										--Pega duas listas e retorna uma lista com numeros presentes nas duas 
interseccao xs (y:ys)										
    |esta_em y xs == False = interseccao xs ys				--Se o item 'y' estiver na lista 'xs', tenta com o proximo elemento
    |otherwise = interseccao xs ys ++ [y]					--Se nao, acrescenta o item.
--Fim Questao 4
--------------------------------------------------------------
--Questao 5 -> Roda Esquerda								
rodar_esquerda x (ys)										--Recebe um valor 'x' e um lista 'ys' e roda a lista 'ys' a esquerda 'x' vezes. 
    | x == 0 = ys											--Caso base, se 'x' for igual 0, nao roda a lista
    |otherwise = rodar_esquerda (x-1) (tail ys ++ [head ys])--roda a esquerda 'x-1' vezes com o primeiro elemento concatenado no fim da cauda da lista.
--Fim Questao 5
--------------------------------------------------------------
--Questao 6 -> Roda Direita    
rodar_direita x (ys)										--Recebe um valor 'x' e um lista 'ys' e roda a lista 'ys' a direita 'x' vezes.
    | x == 0 = ys											--Caso base, se 'x' for igual 0, nao roda a lista
    |otherwise = rodar_direita (x-1) ([last ys] ++ init ys) --roda a direita 'x-1' vezes com o ultimo elemento concatenado com a lista menos o ultimo elemento
--Fim Questao 6
--------------------------------------------------------------
--Questao 7 -> Seleciona 
seleciona :: [Char] -> [Int] -> [Char]						--Recebe uma lista de Char e uma lista de Inteiros e retorna uma lista com os Char nas posiçoes dadas pela lista de Inteiros
seleciona a b = [a !! (x-1) | x <- b]						--Copia o Char na lista 'a' na posiçao 'x-1' onde esse 'x' é um elemento da lista 'b'
--Fim Questao 7
--------------------------------------------------------------
--Questao 8 -> Primo
primo n = if(fatores n) == [1,n] 					-- se a lista de divisores for igual a [1,n] entao N é primo
			then True
			else False
fatores n = [i | i <- [1..n] , mod n i == 0]		-- cria uma lista com todos os divisores de n
--Fim Questao 8
--------------------------------------------------------------
--Questao 9 -> Quadrado Perfeito
func n = [quadrado i | i <- [1..n]]					-- cria um vetor com o quadrado de todos os numero de 1..N

quadrado :: (Integral a) => a -> a                  -- calcula recursivamente o quadrado de um numero
quadrado 1 = 1
quadrado n = quadrado (n-1) + (n-1) + n 

item_lista :: (Integral a) => [a] -> a -> Bool 		-- verifica se um item esta contido na lista
item_lista [] _ = False 							-- se for uma lista vazia retorna false
item_lista (x:xs) a = if x == a                     -- se a head for igual ao elemento retorna true, senao repete a funçao com a 
			then True 					-- cauda da lista
			else item_lista xs a

raiz_quadrada ::(Integral a) => a -> Bool 			-- verifica se o elemento possui raiz quadrada
raiz_quadrada 1 = True
raiz_quadrada a = item_lista (func a) a	
--Fim Questao 9
--------------------------------------------------------------
--Questao 10 -> Conjunto das Partes
subsets [] = [[]]									--Recebe uma lista e retorna uma lista com todas as partiçoes da lista recebida
subsets (x:xs) = 									
	let subsets_xs = subsets xs						--
    in subsets_xs ++ [(x:z) | z <- subsets_xs]		--
--Fim Questao 10
--------------------------------------------------------------
--Funçoes Auxiliares
esta_em x [] = False								--Funçao que recebe um valor e um vetor
esta_em x (y:ys)
    |x == y = True
    |otherwise = esta_em x ys
    
func n = [quadrado i | i <- [1..n]]					-- cria um vetor com o quadrado de todos os numero de 1..N

quadrado :: (Integral a) => a -> a                  -- calcula recursivamente o quadrado de um numero
quadrado 1 = 1
quadrado n = quadrado (n-1) + (n-1) + n 

item_lista :: (Integral a) => [a] -> a -> Bool 		-- verifica se um item esta contido na lista
item_lista [] _ = False 							-- se for uma lista vazia retorna false
item_lista (x:xs) a = if x == a                     -- se a head for igual ao elemento retorna true, senao repete a funçao com a 
				  		then True 					-- cauda da lista
						else item_lista xs a
--Fim Funçoes Auxiliares
