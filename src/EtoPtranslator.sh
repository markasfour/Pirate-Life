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

if [ $1 -eq ""]; then
	echo "Welcome to English to Pirate translator!"

	echo "Enter your English sentence: "

	read sentence

	P_sent=$sentence
	
	#trans to pirate
	Trans_to_Pirate

	echo "Translated to Pirate:"
	echo $P_sent
fi
