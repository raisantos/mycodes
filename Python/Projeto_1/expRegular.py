import re

def login(s):
    valida_login = re.search(r'[^a-zA-Z0-9_]', s)

    if valida_login:                      
        return False 
    else:
        valida_login = re.search(r'^[a-z].*[a-zA-Z0-9]', s)
        if(valida_login):
            return True
        else:
            return False

def email(t):
    valida_email = re.search(r'[\w.-]+@[\w.-]+[.]', t)
        
    if(valida_email):
        return True
    else:
        return False
    
def calcula_cpf(v):
    resultado = ''
    digitos_finais = v[12:14] ##digitos guarda os ultimos dois digitos do cpf
    
    armazena_num = []
    for i in range (11):
        if(v[i]!='.'):
            armazena_num.append(int(v[i]))
    
    num = 10
    soma = 0
    for i in range (9):
        aux = armazena_num[i]*num
        soma+=aux
        num-=1
    
    resto_divisao = soma%11
    if(resto_divisao < 2):
        primeiro_digito = 0 ##primeiro digito depois do traco
    else:
        primeiro_digito = 11-resto_divisao    
     
    num2 = 11
    soma2 = 0
    for i in range (9):
        aux2 = armazena_num[i]*num2
        soma2+=aux2
        num2-=1
    soma2 = soma2+(primeiro_digito*2)    
    
    resto_divisao2 = soma2%11
    if(resto_divisao2 < 2):
        segundo_digito = 0 ##segundo digito depois do traco
    else:
        segundo_digito = 11-resto_divisao2
    
    resultado = resultado + str(primeiro_digito) + str(segundo_digito)
    
    if(resultado == digitos_finais):
        return True
    else:
        return False

def cpf(u):
    valida_cpf = re.match('([0-9]{3}[\.][0-9]{3}[\.][0-9]{3}[-][0-9]{2}$)', u)
    
    if(valida_cpf):
        if(calcula_cpf(u)):
            return True
        else:
            return False
    else:
        return False

def modalidade(w):
    valida_modalidade = re.match('(FUTE22|NATA58|VOLE11|PENT05|BASQ05|VOLA11|TENI01|TENI02|GOLF99|GINA41|GINA14|BADM36)$', w)
    
    if(valida_modalidade):
        return True
    else:
        return False
    
def partida(x):
    valida_partida = re.search(r'[a-wy-z]', x) 
    
    if(valida_partida):
        return False
    else:
        valida_partida = re.match('([^AEIOU][AEIOU][^AEIOU]|[^AEIOU][^AEIOU][AEIOU]|[AEIOU][^AEIOU][^AEIOU])(x)([^AEIOU][AEIOU][^AEIOU]|[^AEIOU][^AEIOU][AEIOU]|[AEIOU][^AEIOU][^AEIOU])$', x)
        if(valida_partida):
            return True
        else:
            return False    

def local(y):
    valida_local = re.match('(CIDADEOLIMPICA|EXTERNO|LAGOA|MARACANA)$', y)
    
    if(valida_local):
        return True
    else:
        return False

def assento(z):
    valida_assento = re.match('[A-Z]{1,2}\d{1,2}$', z)
    
    if(valida_assento):
        return True
    else:
        return False
    
##principal, chamada das funcoes
ingresso = str(input())
campos = ingresso.split(" ")

if(login(campos[0]) and email(campos[1]) and cpf(campos[2]) and modalidade(campos[3]) and partida(campos[4]) and local(campos[5]) and assento(campos[6])):
    print(True)
else:
    print(False)