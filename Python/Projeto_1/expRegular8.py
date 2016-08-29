##validando assento

import re

z = 'A2'
valida_assento = re.match('[A-Z]{1,2}\d{1,2}$', z)

if(valida_assento):
    print(True)
else:
    print(False)