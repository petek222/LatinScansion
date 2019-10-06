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

// Node structure to encapsulate linked-list representation of line
// Each line represented as a linked-list of letter nodes
// Each node can hold its own character, as well as its metrical marking if it has one
struct letter {
    char character;
    char meter;
    letter *nextLetter;
};

// Basic typedef for easier reference for letter pointers
typedef letter *letterPtr;


class LatinScan {

public:

    // Other data structure like set? or just another helper method for diphthongs?
    std::set<std::string> diphthongs;

    // LatinScan Default Constructor
    LatinScan();

    // LatinScan Alternate Constructor
    LatinScan(std::string scanLine);

    // Helper method performs line reversal for easier initial assignment
    LatinScan reverseLine(); 

    // Elides desired vowel-endings
    void elision();

    // Performs initial marking on line
    LatinScan initialMark();

    // Marks Diphthongs based on public diphthongs dataset
    LatinScan markDiphthongs();

    // Mark double consonants in line
    LatinScan markDoubleConsonants();

    // Placeholder for remainder marking
    LatinScan markRemainder();


    // *********************************
    // Output/Helper methods 
    void trimSpace();
       
    void printLine();

    void printMeter();

private:
    letter *myHead;
    int mySize;

    //int feetCount; ////Critical for final fill-in

    bool checkVowel(letterPtr c); // helper method checks for vowel

};

#endif //LATINSCANSION_LATINSCANSION_H

//// DECLENSION AND CONJUGATION REFERENCE ON SEPERATE PAGE










