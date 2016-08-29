##validando CPF

import re

"""u = '111.222.333-44'
valida_cpf = re.search(r'([0-9]{3}[\.][0-9]{3}[\.][0-9]{3}[-][0-9]{2,2})', u)

if(valida_cpf):
    print(True)
else:
    print(False)"""

u = '111.222.333-44'
valida_cpf = re.match('([0-9]{3}[\.][0-9]{3}[\.][0-9]{3}[-][0-9]{2}$)', u, re.IGNORECASE)

if(valida_cpf):
    print(True)
else:
    print(False)