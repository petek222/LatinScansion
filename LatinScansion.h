//
// Created by Peter Koncelik on 2019-02-08.
//

#ifndef LATINSCANSION_LATINSCANSION_H
#define LATINSCANSION_LATINSCANSION_H

#include <cstddef>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <cmath>


struct letter {
    char character;
    char meter;
    letter *nextLetter;
};

typedef letter *letterPtr;


class LatinScan {

public:

    // Other data structure like set? or just another helper method for diphthongs?
    std::set<std::string> diphthongs;

    LatinScan();

    LatinScan(std::string scanLine);

    LatinScan reverseLine(); // helper method will make initial assignment easier

    void printLine();

    void printMeter();

    void elision();

    void trimSpace();

    LatinScan initialMark();

    LatinScan markDiphthongs();

    LatinScan markDoubleConsonants();

    //// This is a poor method just as a placeholder: REFINE
    LatinScan markRemainder();
    //// Must be replaced with inflected ending monitor and proper fill-ins based on prev meter logic

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

private:
    letter *myHead;
    int mySize;

    //int feetCount; ////THIS PRIVATE VARIABLE WILL BE CRITICAL FOR FINAL FILL-IN

    bool checkVowel(letterPtr c); // helper method checks for vowel

};

#endif //LATINSCANSION_LATINSCANSION_H

//// IN APPLICATION: PUT A DECLENSION AND CONJUGATION REFERENCE ON SEPERATE PAGE

//// SHOW EACH STEP FOR BETTER INSTRUCTION/UNDERSTANDING









