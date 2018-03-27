# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/27 03:39:52 by gudemare          #+#    #+#              #
#    Updated: 2018/03/27 09:27:33 by gudemare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash
VM="corewar"
REF_VM="ressource/zaz_vm"
CHAMPS_DIR="ressource/champs/COR"
TESTS_DIR="test_dumps"

DISP_OK="\e[32m.\e[0m"
DISP_END="\e[32me\e[0m"
DISP_BAD="\e[31mF\e[0m"
DISP_ONE_END="\e[35mW\e[0m"

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
exec 0>&-
exec 2>&-
printf "\e[2J\e[H"
echo "\t---=== Corewar Dump Testing ===---"
echo "\tFrom $1 to $3 with step = $2"
printf "$DISP_OK = OK ; $DISP_END = Fight ended ; $DISP_BAD = Bad diff ; $DISP_ONE_END = Fight ended on one VM only\n"
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
		if [ `basename $champ` = "42.cor" ] \
			|| [ `basename $champ` = "barriere.cor" ] \
			|| ( [[ (`basename $champ` = "car.cor" \
			|| `basename $champ` = "bee_gees.cor" \
			|| `basename $champ` = "mandragore.cor") ]] \
			&& [ $i -gt 5000 ] ); then
			break
		fi
		(FILE_VM="$TESTS_DIR/vm_dump_`basename $champ`_$i.log"
		FILE_REF_VM="$TESTS_DIR/ref_vm_dump_`basename $champ`_$i.log"
		./$VM $champ -dump $i 2>/dev/null | tail -n 64 > $FILE_VM &
		./$REF_VM $champ -d $i 2>/dev/null | tail -n 64 > $FILE_REF_VM &
		wait
		if [ `cat $FILE_VM $FILE_REF_VM | grep -c ^0x0 ` -lt 128 ] ; then
			if [ `cat $FILE_VM $FILE_REF_VM | grep -c ^0x0 ` -ge 64 ] ; then
				res=$DISP_ONE_END
			else
				res=$DISP_END
		fi
		else
			diff $FILE_VM $FILE_REF_VM &>/dev/null && res=$DISP_OK || res=$DISP_BAD ;
		fi
		rm $FILE_VM $FILE_REF_VM 2>/dev/null
		printf "\e[s\e[$vpos;${hpos}H$res\e[u"
		exec 3>&-
		exec 4>&-
		exec 1>&-
		) &
		let "hpos+=1"
	done
	wait
	let "vpos++"
done
wait
rm -rf $TESTS_DIR 2>/dev/null
