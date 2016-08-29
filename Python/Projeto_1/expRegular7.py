## validando local da partida

import re

y = 'EXTERNO'
valida_local = re.match('(CIDADEOLIMPICA|EXTERNO|LAGOA|MARACANA)$', y)

if(valida_local):
    print(True)
else:
    print(False)