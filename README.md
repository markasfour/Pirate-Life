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

The current working version of English-to-Pirate translator with no parameters passed in allows a user to enter a sentence in English and, in return, receive a Pirate translated version of their sentence. 
The translated text is automatically copied to your general clipboard so you can paste the translation by using `right-click > paste` or by using `CTRL-V`.

If the user runs English-to-Pirate translator with the first  parameter containing a path to a file, a translated copy of the file will be outputted.

If the user runs English-to-Pirate translator with the second parameter being `write`, the file provided in the first parameter will be overwritten with the translated copy. 

##Bugs and Limitations

* Only one sentence can be entered at a time per execution of the program

##Future Plans

* Make a clean user interface

* Tidy the code so that adding to the Pirate dictionary can easily be done by anyone

* Add to Pirate dictionary

* Allow users to copy their translated text to a clipboard with a simple prompt (as opposed to highlighting the test and copying it)

* Add additional language translation support (i.e. English to Old English)
