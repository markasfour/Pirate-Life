# English-to-Pirate
Simple and fun English to Pirate translator that uses bash shell scripting.

##Download and run

Clone this repository by running the following in a terminal:

    git clone http://github.com/markasfour/English-to-Pirate

Then enter the `src` folder.
There you will find the `EtoPtranslator.sh` executable.
Execute the program by running the following in a terminal:

    ./EtoPtranslator.sh

##Features

The current working version of English-to-Pirate translator allows a user to enter a sentence in English and, in return, receive a Pirate translated version of their sentence.

##Bugs and Limitations

* Translation of some words will erroneously be changes (i.e. `yesterday` will be changed to `ayeterday` because `yes` is found at the start of `yesterday`)

* Only one sentence can be entered at a time per execution of the program

##Future Plans

* Allow users to enter multiple queries without terminating the program

* Allow users to pass in a file to be translated and give the option of either overwriting the file or to simply echo the translated file

* Make a clean user interface

* Tidy the code so that adding to the Pirate dictionary can easily be done by anyone

* Add to Pirate dictionary
