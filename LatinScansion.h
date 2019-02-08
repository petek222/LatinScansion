//
// Created by Peter Koncelik on 2019-02-08.
//

#ifndef LATINSCANSION_LATINSCANSION_H
#define LATINSCANSION_LATINSCANSION_H

#endif //LATINSCANSION_LATINSCANSION_H

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

    void elision();

    void trimSpace();

    // 1.) will assign initial meters within linked list:
    // ie. 5th and 6th feet, long syllable on first vowel

    // 2.) Mark diphthongs and double-consonant vowels as long

    // 3.) Mark inflected endings as best as possible (see handout back)

    // 4.) Fill in the rest (trickiest)


private:

    letter *myHead;
    int mySize;

};









