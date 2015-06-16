#!/bin/bash

function Trans_to_Pirate
{
	#basic pirate translations
	echo $P_sent | sed "s/\<and\>/\'n/g"\
	| sed "s/\<And\>/i\'N/g"\
	| sed "s/\<are\>/be/g"\
	| sed "s/\<Are\>/Be/g"\
	| sed "s/\<boss\>/captain/g"\
	| sed "s/\<Boss\>/Captain/g"\
	| sed "s/\<boy\>/lad/g"\
	| sed "s/\<Boy\>/Lad/g"\
	| sed "s/\<boys\>/lads/g"\
	| sed "s/\<Boys\>/Lads/g"\
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
	| sed "s/\<my\>/me/g"\
	| sed "s/\<My\>/Me/g"\
	| sed "s/\<of\>/o\'/g"\
	| sed "s/\<Of\>/O\'/g"\
	| sed "s/\<prize\>/booty/g"\
	| sed "s/\<Prize\>/Booty/g"\
	| sed "s/\<quickly\>/smartly/g"\
	| sed "s/\<Quickly\>/Smartly/g"\
	| sed "s/\<sexy\>/saucy/g"\
	| sed "s/\<Sexy\>/Saucy/g"\
	| sed "s/\<stop\>/avast/g"\
	| sed "s/\<Stop\>/Avast/g"\
	| sed "s/\<there\>/thar/g"\
	| sed "s/\<There\>/Thar/g"\
	| sed "s/\<today\>/this day/g"\
	| sed "s/\<Today\>/This day/g"\
	| sed "s/\<treasure\>/booty/g"\
	| sed "s/\<Treasure\>/Booty/g"\
	| sed "s/\<want to\>/wanna/g"\
	| sed "s/\<Want to\>/Wanna/g"\
	| sed "s/\<world\>/worl\'/g"\
	| sed "s/\<World\>/worl\'/g"\
	| sed "s/\<wow\>/shiver me timbers/g"\
	| sed "s/\<Wow\>/Shiver me timbers/g"\
	| sed "s/\<yes\>/aye/g"\
	| sed "s/\<Yes\>/Aye aye/g"\
	| sed "s/\<you\>/ye/g"\
	| sed "s/\<You\>/Ye/g"\
	| sed "s/\<your\>/yer/g"\
	| sed "s/\<Your\>/yer/g"\
	| sed "s/ing\>/in\'/g"\
	| sed "s/\!/\! ARRGH\!/g"
}

function Print_Skull
{
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


#Main function
clear
echo "       Welcome to English to Pirate translator!"
Print_Skull
echo "            Enter Q to quit, C to clear"
echo ""

#Variables
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'
TMPFILE=$1
TMPFILE+=".tmp" 

while true; do
	if [[ $1 == "" ]]; then #NO PARAMETERS INCLUDED WHEN RAN
		
		printf "${GREEN}Enter your English sentence: ${NC}"
		read sentence

		if [[ $sentence == "Q" ]]; then
			break
		elif [[ $sentence == "C" ]]; then
			clear
			echo "       Welcome to English to Pirate translator!"
			Print_Skull
			echo "            Enter Q to quit, C to clear"
			echo ""
		else
			P_sent=$sentence
			
			#TRANSLATE
			echo ""
			printf "${RED}Translated to Pirate: ${NC}"
			Trans_to_Pirate

			echo "" 
		fi
	else #PARAMETERS INCLUDED WHEN RAN 
		if [[ $2 == "write" ]]; then
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
		break;
	fi
done

if [[ $1 == "" ]]; then
	clear
else
	echo ""
fi

echo "Till we set sail again, me lad!"
