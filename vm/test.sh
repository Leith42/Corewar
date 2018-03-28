# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/27 03:39:52 by gudemare          #+#    #+#              #
#    Updated: 2018/03/28 17:49:30 by gudemare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash
PID=$$

DISP_OK="\e[32m.\e[0m"
DISP_END="\e[32me\e[0m"
DISP_BAD="\e[31mF\e[0m"
DISP_ONE_END="\e[35mW\e[0m"
DISP_SKIP="\e[33mS\e[0m"

#Modify your variables here
VM="corewar"
REF_VM="ressource/zaz_vm"
CHAMPS_DIR="ressource/champs/COR"
TESTS_DIR="test_dumps_$PID"

#Display and arguments check
if [ `tput lines` -le $((`ls -1 $CHAMPS_DIR/*.cor | wc -l` + 3)) ] ; then
	printf "Abort : not enough rows.\n"
	exit 1
elif [ -z $1 ] ; then
	printf "Usage : ./vm/test.sh [low step high | duels]\n"
	exit 1
elif [ $1 = "duels" ] ; then
	break
elif [ `tput cols` -le $(( (($3 - $1) / $2) + 1 + 24 )) ] \
	|| [ `tput cols` -le 72 ] ; then
printf "Abort : not enough columns.\n"
exit 1
fi

#individual champion dump test. {low, step, high, champ, vpos}
run_individual_check()
{
	champ=$4
	vpos=$5
	if [[ (`basename $champ` = "car.cor" \
		|| `basename $champ` = "bee_gees.cor" \
		|| `basename $champ` = "mandragore.cor") ]] ; then
		maxcycles=5000
	elif [[ (`basename $champ` = "ultimate-surrender.cor" \
		|| `basename $champ` = "mise_a_jour_windows95.cor") ]] ; then
		maxcycles=25000
	else
		maxcycles=`$REF_VM -v 2 $champ 2>/dev/null | grep cycle | tail -n 1 | cut -d ' ' -f 5`
	fi
	hpos=24
	lastcheck=0
	for i in `seq $1 $2 $3`
	do
		if [[ $i -gt $maxcycles ]] || [[ $maxcycles -eq 0 ]] ; then
			lastcheck=1
		fi
		(FILE_VM="$TESTS_DIR/vm_dump_`basename $champ`_$i.log"
		FILE_REF_VM="$TESTS_DIR/ref_vm_dump_`basename $champ`_$i.log"
		touch $FILE_VM $FILE_REF_VM
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
			diff $FILE_VM $FILE_REF_VM &>/dev/null && res=$DISP_OK || res=$DISP_BAD
		fi
		rm $FILE_VM $FILE_REF_VM 2>/dev/null
		printf "\e[s\e[$vpos;${hpos}H$res\e[u"
		exec 3>&- && exec 4>&- && exec 1>&-) &
		if [ $lastcheck -eq 1 ] ; then
			break
		fi
		let "hpos+=1"
	done
}

#duel test. {champ, vpos, CHAMPS_DIR}
run_duel_checks()
{
	champ=$1
	vpos=$2
	CHAMPS_DIR=$3
	hpos=24
	for opponent in $CHAMPS_DIR/*.cor
	do
		if [[ (`basename $champ` = "car.cor" \
			|| `basename $champ` = "bee_gees.cor" \
			|| `basename $champ` = "42.cor" \
			|| `basename $champ` = "barriere.cor" \
			|| `basename $champ` = "mandragore.cor" \
			|| `basename $opponent` = "car.cor" \
			|| `basename $opponent` = "bee_gees.cor" \
			|| `basename $opponent` = "42.cor" \
			|| `basename $opponent` = "barriere.cor" \
			|| `basename $opponent` = "mandragore.cor") ]] ; then
			printf "\e[s\e[$vpos;${hpos}H$DISP_SKIP\e[u"
			let "hpos+=1"
			continue
		fi
		(FILE_VM="$TESTS_DIR/vm_duel_winner_`basename $champ`_vs_`basename $opponent`.log"
		FILE_REF_VM="$TESTS_DIR/ref_vm_duel_winner_`basename $champ`_vs_`basename $opponent`.log"
		touch $FILE_VM $FILE_REF_VM
		./$REF_VM $champ $opponent 2>/dev/null | tail -n 1 | grep -e "\".*\"" -o | cut -c 2- | rev | cut -c 2- | rev > $FILE_REF_VM &
		./$VM $champ $opponent 2>/dev/null | tail -n 1 | grep -e "(.*)" -o | cut -c 2- | rev | cut -c 2- | rev > $FILE_VM &
		wait
		diff $FILE_VM $FILE_REF_VM &>/dev/null && res=$DISP_OK || res=$DISP_BAD
		printf "\e[s\e[$vpos;${hpos}H$res\e[u"
		rm $FILE_VM $FILE_REF_VM 2>/dev/null) &
		let "hpos+=1"
	done
	wait
}

exec 0>&- && exec 2>&-
printf "\e[2J\e[H"
echo "\t---=== Corewar Tester ===---"
if [ $1 = "duels" ] ; then
	echo "\t\tDuel mode"
	printf "$DISP_OK = OK ; $DISP_BAD = Bad diff ; $DISP_SKIP = Skip\n"
	printf "\x1b[23C"
	for champ in $CHAMPS_DIR/*.cor
	do
		printf "\e[36m`basename $champ | cut -c 1`"
	done
	echo ""
	vpos=5
else
	echo "\tFrom $1 to $3 with step = $2"
	printf "$DISP_OK = OK ; $DISP_END = Fight ended ; $DISP_BAD = Bad diff ; $DISP_ONE_END = Fight ended on one VM only\n"
	vpos=4
fi
mkdir -p $TESTS_DIR
for champ in $CHAMPS_DIR/*.cor
do
	printf "\e[36m`basename $champ | rev | cut -c 5- | rev`\n"
done
for champ in $CHAMPS_DIR/*.cor
do
	if [ $1 = "duels" ] ; then
		run_duel_checks $champ $vpos $CHAMPS_DIR
	else
		run_individual_check $1 $2 $3 $champ $vpos
	fi
	(( vpos++ ))
done
wait
rm -rf $TESTS_DIR 2>/dev/null
