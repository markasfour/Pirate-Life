# Pirate Life
Simple and fun in-terminal English to Pirate translator and Pirate Game.

##Download and run

Clone this repository by running the following in a terminal:

    git clone http://github.com/markasfour/Pirate-Life

Use the most up-to-date version by running:

    git checkout v3

Execute the program by running the following in a terminal:

    ./pirate.sh

Note #1: Make sure `pirate.sh` is an executable locally.
If it is not, run the following in a terminal:

	chmod u+x pirate.sh

Note #2: Make sure `xclip` is installed on your system (used for copying to clipboard feature).
If it is not, run the following in a terminal:

	sudo apt-get install xclip

##Features

* Fully playable pirate game in pre-alpha stages of completion.

* Enter a sentence in English and, in return, receive a Pirate translated version of their sentence. 

* The translated text automatically copied to general clipboard (paste the translation by using `right-click > paste` or by using `ctrl+v`)

* If the user runs `./pirate.sh` with the first  parameter containing a path to a file, a translated copy of the file will be outputted.

* If the user runs `./pirate.sh` with the second parameter being `-w`, the file provided in the first parameter will be overwritten with the translated copy. 

* Automatic pirate insult generator.

##Bugs and Limitations

* Please report bugs here on GitHub under issues

* Pirate game still in development

* Full functionality only in Linux environment

##Future Plans

* Add to Pirate dictionary

* Pirate game will be complete by `v4`
