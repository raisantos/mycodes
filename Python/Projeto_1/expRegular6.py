##validando partida
## obs

import re

x = 'BRAxRUS'
valida_partida = re.search(r'[a-wy-z]', x) ##procurar uma maneira de evitar

if(valida_partida):
    print(False)
else:
    valida_partida = re.match('([^AEIOU][AEIOU][^AEIOU]|[^AEIOU][^AEIOU][AEIOU]|[AEIOU][^AEIOU][^AEIOU])(x)([^AEIOU][AEIOU][^AEIOU]|[^AEIOU][^AEIOU][AEIOU]|[AEIOU][^AEIOU][^AEIOU])$', x)
    if(valida_partida):
        print(True)
    else:
        print(False)