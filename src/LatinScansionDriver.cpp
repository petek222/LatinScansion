//
// Created by Peter Koncelik on 2019-02-08.
//

#include <iostream>
#include "LatinScansion.h"

// main below checks each step

int main() {

    LatinScan check("urbs antiqua fuit tyrii tenuere coloni");

    check.elision();

    check.trimSpace();

    std::cout << std::endl;

    check.initialMark();

    check.markDiphthongs();

    // Print statements are currently housed in method-call hierarchy

    return 0;
}

    // GENERAL LOGIC PROCESS OF DEVELOPMENT:
    // 1.) will assign initial meters within linked list: (DONE)
    // ie. 5th and 6th feet, long syllable on first vowel (DONE) 
    // 2.) Mark diphthongs and double-consonant vowels as long (DONE)
    // 3.) Mark inflected endings as best as possible (see handout back/Any final -o as long)
    // 4.) Fill in the rest (trickiest)
    // 5.) Write in user-inuput function.

    //// IMPORTANT NOTE: MARK INFLECTED ENDINGS AFTER ELISION, BUT BEFORE TRIMMING SPACE. THIS WAY
    //// WORDS WILL STILL BE SPACED FOR FINAL-ENDING MARKINGS

    //// KEEP A COUNT OF CURRENT AMOUNT OF FEET: THIS WILL TELL PROGRAM WHAT IT NEEDS AND FILL


    // NOTE 1: HAVE A METHOD GO THROUGH AND MARK OFF ALL QU COMBOS AS CONSONANTS OR SOMETHING
    // NOTE 2: HAVE A METHOD ACCOUNT FOR CAPITALIZATION AND PUNCTUATION (ie. periods, commas,
    // colons, quotation marks, single quotes, etc.)


    // NOTE: For marking diphthongs, mark first vowel as long and put another placeholder for the second
    // (ie. 1) :MAKE SURE THIS ISNT PRINTED IN THE PRINTMETER FUNCTION