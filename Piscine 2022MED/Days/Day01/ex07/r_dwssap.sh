cat /etc/passwd | grep -v "#" | awk 'NR>1 {print}' |awk 'NR%2==0' | awk -F: '{print $1}' | rev | sort -r | sed $FT_LINE1','$FT_LINE2'!d' | tr '\n' ',' | sed 's/,/, /g' | sed 's/, $/./' | tr -d '\n'
