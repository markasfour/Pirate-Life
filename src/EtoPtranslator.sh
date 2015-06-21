#!/bin/bash

function Trans_to_Pirate
{
	#basic pirate translations
	echo $P_sent | sed "s/\<allow\>/let be/g"\
	| sed "s/\<Allow\>/Let be/g"\
	| sed "s/\<allowed\>/freed/g"\
	| sed "s/\<Allowed\>/Freed/g"\
	| sed "s/\<allowing\>/be letting/g"\
	| sed "s/\<Allowing\>/Be letting/g"\
	| sed "s/\<allows\>/lets/g"\
	| sed "s/\<Allows\>/Lets/g"\
	| sed "s/\<and\>/\'n/g"\
	| sed "s/\<And\>/i\'N/g"\
	| sed "s/\<are\>/be/g"\
	| sed "s/\<Are\>/Be/g"\
	| sed "s/\<ate\>/swallowed/g"\
	| sed "s/\<Ate\>/Swallowed/g"\
	| sed "s/\<boss\>/captain/g"\
	| sed "s/\<Boss\>/Captain/g"\
	| sed "s/\<boy\>/lad/g"\
	| sed "s/\<Boy\>/Lad/g"\
	| sed "s/\<boys\>/lads/g"\
	| sed "s/\<Boys\>/Lads/g"\
	| sed "s/\<but\>/bu\'/g"\
	| sed "s/\<But\>/Bu\'/g"\
	| sed "s/\<different\>/di\'rent/g"\
	| sed "s/\<Different\>/Di\'rent/g"\
	| sed "s/\<drink\>/swig/g"\
	| sed "s/\<Drink\>/Swig/g"\
	| sed "s/\<drinks\>/swigs/g"\
	| sed "s/\<Drinks\>/Swigs/g"\
	| sed "s/\<drive\>/sail/g"\
	| sed "s/\<Drive\>/Sail/g"\
	| sed "s/\<driving\>/sailing/g"\
	| sed "s/\<Driving\>/Sailing/g"\
	| sed "s/\<drives\>/floats/g"\
	| sed "s/\<Drives\>/Floats/g"\
	| sed "s/\<drove\>/sailed/g"\
	| sed "s/\<Drove\>/Sailed/g"\
	| sed "s/\<eat\>/munch/g"\
	| sed "s/\<Eat\>/Munch/g"\
	| sed "s/\<eating\>/munching/g"\
	| sed "s/\<Eating\>/Munching/g"\
	| sed "s/\<eats\>/munches/g"\
	| sed "s/\<Eats\>/Munches/g"\
	| sed "s/\<for\>/fer/g"\
	| sed "s/\<For\>/Fer/g"\
	| sed "s/\<friend\>/bucko/g"\
	| sed "s/\<Friend\>/Bucko/g"\
	| sed "s/\<friends\>/hearties/g"\
	| sed "s/\<Friends\>/Hearties/g"\
	| sed "s/\<girl\>/lassy/g"\
	| sed "s/\<Girl\>/Lassy/g"\
	| sed "s/\<girls\>/lassies/g"\
	| sed "s/\<Girls\>/Lassies/g"\
	| sed "s/\<government\>/law making scalleywags/g"\
	| sed "s/\<government\>/Law making scalleywags/g"\
	| sed "s/\<hell\>/Davy Jone's Locker/g"\
	| sed "s/\<Hell\>/Davy Jone's Locker/g"\
	| sed "s/\<hello\>/ahoy/g"\
	| sed "s/\<Hello\>/Ahoy/g"\
	| sed "s/\<hey\>/ahoy/g"\
	| sed "s/\<Hey\>/Ahoy/g"\
	| sed "s/\<hi\>/ahoy/g"\
	| sed "s/\<Hi\>/Ahoy/g"\
	| sed "s/\<idiot\>/squiffy/g"\
	| sed "s/\<Idiot\>/Squiffy/g"\
	| sed "s/\<is\>/be/g"\
	| sed "s/\<Is\>/Be/g"\
	| sed "s/\<isn't\>/ain\'t/g"\
	| sed "s/\<Isn't\>/Ain\'t/g"\
	| sed "s/\<is not\>/ain\'t/g"\
	| sed "s/\<Is not\>/Ain\'t/g"\
	| sed "s/\<just\>/jus\'/g"\
	| sed "s/\<Just\>/Jus\'/g"\
	| sed "s/\<knew\>/savvied/g"\
	| sed "s/\<Knew\>/Savvied/g"\
	| sed "s/\<know\>/savvy/g"\
	| sed "s/\<Know\>/Savvy/g"\
	| sed "s/\<knowing\>/savvying/g"\
	| sed "s/\<Knowing\>/Savvying/g"\
	| sed "s/\<knows\>/savvies/g"\
	| sed "s/\<Knows\>/Savvies/g"\
	| sed "s/\<little\>/wee/g"\
	| sed "s/\<Little\>/Wee/g"\
	| sed "s/\<man\>/buccaneer/g"\
	| sed "s/\<Man\>/Buccaneer/g"\
	| sed "s/\<men\>/crew/g"\
	| sed "s/\<Men\>/Crew/g"\
	| sed "s/\<my\>/me/g"\
	| sed "s/\<My\>/Me/g"\
	| sed "s/\<of\>/o\'/g"\
	| sed "s/\<Of\>/O\'/g"\
	| sed "s/\<ok\>/savvy/g"\
	| sed "s/\<Ok\>/Savvy/g"\
	| sed "s/\<okay\>/savvy/g"\
	| sed "s/\<Okay\>/Savvy/g"\
	| sed "s/\<other\>/ot\'er/g"\
	| sed "s/\<Other\>/Ot\'er/g"\
	| sed "s/\<others\>/ot\'ers/g"\
	| sed "s/\<Others\>/Ot\'ers/g"\
	| sed "s/\<person\>/scalleywag/g"\
	| sed "s/\<Person\>/Scalleywag/g"\
	| sed "s/\<people\>/scalleywags/g"\
	| sed "s/\<People\>/Scalleywags/g"\
	| sed "s/\<prize\>/booty/g"\
	| sed "s/\<Prize\>/Booty/g"\
	| sed "s/\<quickly\>/smartly/g"\
	| sed "s/\<Quickly\>/Smartly/g"\
	| sed "s/\<small\>/wee/g"\
	| sed "s/\<Small\>/Wee/g"\
	| sed "s/\<sexy\>/saucy/g"\
	| sed "s/\<Sexy\>/Saucy/g"\
	| sed "s/\<speak\>/shout/g"\
	| sed "s/\<Speak\>/Shout/g"\
	| sed "s/\<stop\>/avast/g"\
	| sed "s/\<Stop\>/Avast/g"\
	| sed "s/\<talk\>/speak/g"\
	| sed "s/\<Talk\>/Speak/g"\
	| sed "s/\<talked\>/spoked/g"\
	| sed "s/\<Talked\>/Spoked/g"\
	| sed "s/\<talking\>/speaking/g"\
	| sed "s/\<Talking\>/Speaking/g"\
	| sed "s/\<talks\>/speaks/g"\
	| sed "s/\<Talks\>/Speaks/g"\
	| sed "s/\<there\>/thar/g"\
	| sed "s/\<There\>/Thar/g"\
	| sed "s/\<today\>/this day/g"\
	| sed "s/\<Today\>/This day/g"\
	| sed "s/\<treasure\>/booty/g"\
	| sed "s/\<Treasure\>/Booty/g"\
	| sed "s/\<understand\>/savvy/g"\
	| sed "s/\<Understand\>/Savvy/g"\
	| sed "s/\<until\>/\'til/g"\
	| sed "s/\<Until\>/\'Til/g"\
	| sed "s/\<want to\>/wanna/g"\
	| sed "s/\<Want to\>/Wanna/g"\
	| sed "s/\<what\>/wha\'/g"\
	| sed "s/\<What\>/Wha\'/g"\
	| sed "s/\<with\>/wit\'/g"\
	| sed "s/\<With\>/Wit\'/g"\
	| sed "s/\<woman\>/wench/g"\
	| sed "s/\<Woman\>/Wench/g"\
	| sed "s/\<women\>/beauties/g"\
	| sed "s/\<Women\>/Beauties/g"\
	| sed "s/\<wood\>/lumber/g"\
	| sed "s/\<Wood\>/Lumber/g"\
	| sed "s/\<world\>/worl\'/g"\
	| sed "s/\<World\>/worl\'/g"\
	| sed "s/\<would\>/wou\'d/g"\
	| sed "s/\<Would\>/Wou\'d/g"\
	| sed "s/\<wow\>/shiver me timbers/g"\
	| sed "s/\<Wow\>/Shiver me timbers/g"\
	| sed "s/\<yes\>/aye/g"\
	| sed "s/\<Yes\>/Aye aye/g"\
	| sed "s/\<you\>/ye/g"\
	| sed "s/\<You\>/Ye/g"\
	| sed "s/\<your\>/yer/g"\
	| sed "s/\<Your\>/yer/g"\
	| sed "s/ever/e\'r/g"\
	| sed "s/\>Ever/E\'r/g"\
	| sed "s/ing\>/in\'/g"\
	| sed "s/ld\>/l\'/g"\
	| sed "s/nd\>/n\'/g"\
	| sed "s/\!/\! ARRGH\!/g"\
	| xclip -sel c -f
}

function Print_Skull
{
	echo "       Welcome to English to Pirate translator!"
	echo "                       "______
	echo "                    ".-\""     " \"-.
	echo "                   "/"           " \\
	echo "       _          "\|"              "\|"         " _ 
	echo "      "\( \\ "        "\|,"  ".-."  ".-."  ",\|"         "/ \)
	echo "       "\> \"=._"     "\| \)\(__\/"  "\\__\)\(" "\|"     "_.=\" \<
	echo "      "\(_/\"=._\"=._ \|/"     "/\\ "    "\\\| _.=\"_.=\"\\_\)
	echo "             "\"=._ \(_"     "^^"     "_\) _.=\" 
	echo "                 "\"=\\__\|IIIIII\|__/=\"
	echo "                _".=\"\| \\IIIIII/ \|\"=._
	echo "      _     _".=\"_.=\"\\ "         "/\"=._\"=._"     "_
	echo "     "\( \\_.=\"_.=\""     "\`--------\`"     "\"=._\"=._/ \)
	echo "      "\> _.=\""                            "\"=._ \<
	echo "     "\(_/"                                    "\\_\)
	echo "" 
}

function Menu
{
	clear
	Print_Skull
	printf "                        ${GREEN}MENU${NC}\n"
	echo "     ------------------------------------------"
	echo "     |     S to translate inputed sentences   |"
	echo "     ------------------------------------------"
	echo "     |F to translate a file (to overwrite, -w)|"
	echo "     ------------------------------------------"
	echo "     |               Q to quit                |"
	echo "     ------------------------------------------"
	echo ""
	
	MenuInput=""
	while [[ $MenuInput != "S" && $MenuInput != "F" && $MenuInput != Q ]]; do
		read MenuInput
	done

	if [[ $MenuInput == "S" ]]; then
		clear
		Print_Skull
		echo "       Enter Q to return to menu, C to clear"
		echo ""
		SentenceTrans
	elif [[ $MenuInput == "F" ]]; then
		clear
		Print_Skull
		echo "Enter the path to yer file, Q to return to menu: "
		read file
		if [[ $file == "Q" ]]; then
			Menu
		fi
		From_Start=0
		FileTrans $file
	elif [[ $MenuInput == "Q" ]]; then
		clear
		echo "Till we set sail again, me lad."
		exit 0
	fi
}

function SentenceTrans
{
	sentence=""
	while [[ $sentence != "Q" ]]; do
		printf "${GREEN}Enter your English sentence: ${NC}"
		read sentence

		if [[ $sentence == "Q" ]]; then
			Menu
		elif [[ $sentence == "C" ]]; then
			clear
			Print_Skull
			echo "       Enter Q to return to menu, C to clear"
			echo ""
		else
			P_sent=$sentence
			#TRANSLATE
			echo ""
			printf "${RED}Translated to Pirate: ${NC}"
			Trans_to_Pirate

			echo "" 
		fi
	done
}

function FileTrans
{
	if [[ $2 == "-w" ]]; then
		printf "${RED}Be ye sure ye wanna overwrite yer file? (Y/N): ${NC}"
		echo ""
		read writebool
		#VALIDATE OVERWRITE
		while [[ $writebool != "Y" && $writebool != "N" ]]; do
			read writebool
		done

		if [[ $writebool == "N" ]]; then
			echo "Ye scallywag"
			echo ""
		fi
	fi
		
	printf "${GREEN}Openin' yer file ${NC}" 
	echo ""
	echo ""

	#READ FROM FILE
	while IFS='' read -r line || [[ -n $line ]]; do
		P_sent=$line
			
		#OVERWRITE
		if [[ $writebool == "Y" ]]; then
			Trans_to_Pirate >> $TMPFILE 
		else
			Trans_to_Pirate
		fi
	done < "$1"
		
	#OVERWRITE CONT
	if [[ $writebool == "Y" ]]; then
		cat $TMPFILE > $1
		rm $TMPFILE
	fi

	echo ""
	printf "${RED}Finished wit' yer file ${NC}\n"
	if [[ $From_Start == 0 ]]; then
		echo "Translate another file? (Y/N) "
		Another_file=""
		while [[ $Another_file != "Y" && $Another_file != "N" ]]; do
			read Another_file
		done

		if [[ $Another_file == "Y" ]]; then
			clear
			Print_Skull
			echo "Enter the path to yer file, Q to return to menu: "
			read file
			if [[ $file == "Q" ]]; then
				Menu
			fi
			From_Start=0
			FileTrans $file
		else
			Menu
		fi
	else
		exit 0
	fi
}

#Main function
clear
Print_Skull

#Variables
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'
TMPFILE=$1
TMPFILE+=".tmp" 

while true; do
	if [[ $1 == "" ]]; then #NO PARAMETERS INCLUDED WHEN RAN
		Menu	

	else #PARAMETERS INCLUDED WHEN RAN 
		From_Start=1
		FileTrans $1 $2
	fi
done

if [[ $1 == "" ]]; then
	clear
else
	echo ""
fi

echo "Till we set sail again, me lad!"
