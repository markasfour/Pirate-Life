#!/bin/bash

function Trans_to_Pirate
{
	#basic pirate translations
	P_sent=${P_sent//boy/lad}
	P_sent=${P_sent//Boy/Lad}
	P_sent=${P_sent//boys/lads}
	P_sent=${P_sent//Boys/Lads}

	P_sent=${P_sent//friend/bucko}
	P_sent=${P_sent//Friend/Bucko}

	P_sent=${P_sent//friends/hearties}
	P_sent=${P_sent//Friends/Hearties}
	
	P_sent=${P_sent//girl/lassy}
	P_sent=${P_sent//Girl/Lassy}
	P_sent=${P_sent//girls/lassies}
	P_sent=${P_sent//Girls/Lassies}

	P_sent=${P_sent//hello/ahoy}
	P_sent=${P_sent//Hello/Ahoy}
	
	P_sent=${P_sent//hey/ahoy}
	P_sent=${P_sent//Hey/Ahoy}
	
	P_sent=${P_sent//hi/ahoy}
	P_sent=${P_sent//Hi/Ahoy}
	
	P_sent=${P_sent//my/me}
	P_sent=${P_sent//My/Me}
	
	P_sent=${P_sent//stop/avast}
	P_sent=${P_sent//Stop/Avast}

	P_sent=${P_sent//want to/wanna}
	P_sent=${P_sent//Want to/wanna}

	P_sent=${P_sent//world/worl\'}
	P_sent=${P_sent//World/Worl\'}
	
	P_sent=${P_sent//wow/shiver me timbers}
	P_sent=${P_sent//Wow/Shiver me timbers}

	P_sent=${P_sent//yes/aye}
	P_sent=${P_sent//Yes/Aye aye}

	P_sent=${P_sent//you/ye}
	P_sent=${P_sent//You/Ye}
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
sentence=""
Q_command="Q"
C_command="C"
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

while true; do
	if [[ $1 == "" ]]; then
		
		printf "${GREEN}Enter your English sentence: ${NC}"
		read sentence

		if [ "$sentence" == "$Q_command" ]; then
			break
		elif [ "$sentence" == "$C_command" ]; then
			clear
			Print_Skull
			echo "            Enter Q to quit, C to clear"
			echo ""
		else
			P_sent=$sentence
			
			#trans to pirate
			Trans_to_Pirate

			printf "${RED}Translated to Pirate: ${NC}"
			echo $P_sent
			echo "" 
		fi
	else 
		echo "Openin' yer file" 
		echo ""

		while IFS='' read -r line || [[ -n $line ]]; do
			P_sent=$line
			Trans_to_Pirate
			echo $P_sent

		done < "$1"
		
		echo ""
		echo "Finished wit' yer file"
		break;
	fi
done

echo ""
echo "Till we set sail again, me lad!"
