##validando e-mail

import re

t = 'a4r.l0s@teste.com'
valida_email = re.search(r'[\w.-]+@[\w.-]+[.]', t)

if(valida_email):
    print(True)
else:
    print(False)