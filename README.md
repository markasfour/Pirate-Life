# English-to-Pirate
Simple and fun in terminal English to Pirate translator that uses bash shell scripting.

##Download and run

Clone this repository by running the following in a terminal:

    git clone http://github.com/markasfour/English-to-Pirate

Then enter the `src` folder.
There you will find the `EtoPtranslator.sh` executable.
Execute the program by running the following in a terminal:

    ./EtoPtranslator.sh

##Features

The current working version of English-to-Pirate translator allows a user to enter a sentence in English and, in return, receive a Pirate translated version of their sentence.

If the user runs English-to-Pirate translator with a parameter containing a path to a file, a translated copy of the file will be outputted.

##Bugs and Limitations

* Translation of some words will erroneously be changes (i.e. `yesterday` will be changed to `ayeterday` because `yes` is found at the start of `yesterday`)

* Only one sentence can be entered at a time per execution of the program

##Future Plans

* Allow users to enter multiple queries without terminating the program

* Allow users to pass in a file to be translated and give the option of either overwriting the file or to simply echo the translated file

* Make a clean user interface

* Tidy the code so that adding to the Pirate dictionary can easily be done by anyone

* Add to Pirate dictionary

* Allow users to copy their translated text to a clipboard with a simple prompt (as opposed to highlighting the test and copying it)

* Add additional language translation support (i.e. English to Old English)
