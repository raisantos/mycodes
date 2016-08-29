##validação do login

import re

s = 'a99$9'
#valida_login = re.search(r'[^a-zA-Z0-9]', s)

#if valida_login:                      
#    print 'False' 
#else:
valida_login = re.match(r'^[a-z]*[a-zA-Z0-9]$', s)
if(valida_login):
    print ("True")
else:
    print ("False")
