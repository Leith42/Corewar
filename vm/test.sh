# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/27 03:39:52 by gudemare          #+#    #+#              #
#    Updated: 2018/03/27 08:09:01 by gudemare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash
VM="corewar"
REF_VM="ressource/zaz_vm"
CHAMPS_DIR="ressource/champs/COR"
TESTS_DIR="test_dumps"

if [ `tput lines` -le $((`ls -1 $CHAMPS_DIR/*.cor | wc -l` + 3)) ] ; then
	printf "Abort : not enough rows.\n"
	exit 1
elif [ `tput cols` -le $((($3 / $2) + 1 + 24)) ] ; then
	printf "Abort : not enough rows.\n"
	exit 1
elif [ -z $3 ] ; then
	printf "Usage : ./vm/test.sh low step high\n"
	exit 1
fi
printf "\e[2J\e[H"
echo "\t---=== Corewar Dump Testing ===---"
echo "\tFrom $1 to $3 with step = $2\n"
mkdir -p $TESTS_DIR
for champ in $CHAMPS_DIR/*.cor
do
	printf "\e[36m`basename $champ | rev | cut -c 5- | rev`\n"
done
vpos=4
for champ in $CHAMPS_DIR/*.cor
do
	hpos=24
	for i in `seq $1 $2 $3`
	do
		if [[ (`basename $champ` = "car.cor" \
			|| `basename $champ` = "bee_gees.cor" \
			|| `basename $champ` = "mandragore.cor") ]] \
			&& [ $i -gt 5000 ] ; then
			break
		fi
		(exec 0>&-
		exec 2>&-
		FILE_VM="$TESTS_DIR/vm_dump_`basename $champ`_$i.log"
		FILE_REF_VM="$TESTS_DIR/ref_vm_dump_`basename $champ`_$i.log"
		./$VM $champ -dump $i 2>/dev/null | tail -n 64 > $FILE_VM &
		./$REF_VM $champ -d $i 2>/dev/null | tail -n 64 > $FILE_REF_VM &
		wait
		diff $FILE_VM $FILE_REF_VM &>/dev/null && res="\e[32m." || res="\e[31mF" ;
		rm $FILE_VM $FILE_REF_VM 2>/dev/null
		printf "\e[s\e[$vpos;${hpos}H$res\e[0m\e[u") &
		let "hpos+=1"
	done
	let "vpos++"
done
wait
rm -rf $TESTS_DIR 2>/dev/null
