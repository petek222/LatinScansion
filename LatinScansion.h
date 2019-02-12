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


struct letter {
    char character;
    char meter;
    letter *nextLetter;
};

typedef letter *letterPtr;


class LatinScan {

public:

    //std::find!!!!!
    std::vector<char> vowel = {'a','e','i','o','u','y'};
    std::vector<std::string> diphthong = {"ae","oe","au","ei","eu","ui"};

    LatinScan();

    LatinScan(std::string scanLine);

    // RUNS INFINITELY: CHECK REVERSAL ON PAPER
    LatinScan reverseLine(); // helper method will make initial assignment easier

    void printLine();

    void printMeter();

    void elision();

    void trimSpace();

    void initialMark();

    // GENERAL LOGIC PROCESS OF DEVELOPMENT:
    // 1.) will assign initial meters within linked list: (DONE)
    // ie. 5th and 6th feet, long syllable on first vowel (DONE) 
    // 2.) Mark diphthongs and double-consonant vowels as long
    // 3.) Mark inflected endings as best as possible (see handout back)
    // 4.) Fill in the rest (trickiest)


    // NOTE: For marking diphthongs, mark first vowel as long and put another placeholder for the second
    // (ie. 1) :MAKE SURE THIS ISNT PRINTED IN THE PRINTMETER FUNCTION

private:
    letter *myHead;
    int mySize;

    bool checkVowel(letterPtr c); // helper method checks for vowel

};

#endif //LATINSCANSION_LATINSCANSION_H










