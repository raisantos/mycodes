##funcao de validacao do cpf

v = '111.222.333-96'
resultado = ''
digitos_finais = v[12:14] ##digitos guarda os ultimos dois digitos do cpf
print(digitos_finais)

##transforma a string em inteiros
armazena_num = []
for i in range (11):
    if(v[i]!='.'):
        armazena_num.append(int(v[i]))

print(armazena_num)

## multiplicando cada elemento do vetor, como o algoritmo pede
num = 10
soma = 0
for i in range (9):
    aux = armazena_num[i]*num
    soma+=aux
    num-=1
    
print(soma)

##calculando primeiro digito
resto_divisao = soma%11
if(resto_divisao < 2):
    primeiro_digito = 0 ##primeiro digito depois do traco
else:
    primeiro_digito = 11-resto_divisao
    
print(primeiro_digito) ##neste caso, primeiro_digito == 9

## multiplicando cada elemento novamente, junto com o primeiro digito achado 
num2 = 11
soma2 = 0
for i in range (9):
    aux2 = armazena_num[i]*num2
    soma2+=aux2
    num2-=1
soma2 = soma2+(primeiro_digito*2)    
print(soma2)

##calculando segundo digito
resto_divisao2 = soma2%11
if(resto_divisao2 < 2):
    segundo_digito = 0 ##segundo digito depois do traco
else:
    segundo_digito = 11-resto_divisao2
    
print(segundo_digito) ##neste caso segundo digito == 6

resultado = resultado + str(primeiro_digito) + str(segundo_digito)
print(resultado)

if(resultado == digitos_finais):
    print(True)
else:
    print(False)