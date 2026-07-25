file="server_access.log"
sed 's/card=[0-9-]*/card=XXXX-XXXX-XXXX-XXXX/' $file | sed 's/HTTP\/1.0/HTTP\/1.1/' | sed '/^#/d'