##validando modalidade

import re

w = 'BADM36'
valida_modalidade = re.match('(FUTE22|NATA58|VOLE11|PENT05|BASQ05|VOLA11|TENI01|TENI02|GOLF99|GINA41|GINA14|BADM36)$', w)

if(valida_modalidade):
    print(True)
else:
    print(False)