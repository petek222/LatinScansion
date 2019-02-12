//
// Created by Peter Koncelik on 2019-02-08.
//


#ifndef LATINSCANSION_LATINSCANSION_CPP
#define LATINSCANSION_LATINSCANSION_CPP

#include "LatinScansion.h"


LatinScan::LatinScan() : myHead(nullptr) {
    // nothing to do
}

LatinScan::LatinScan(std::string scanLine) : myHead(nullptr), mySize(scanLine.length()) {

    for (int i = mySize-1; i >= -1; i--) {

        letterPtr curr(new letter);

        if (i == -1) {
            curr->nextLetter = nullptr;
        }
        else {
            curr->character = scanLine[i];
            curr->meter = ' '; // default value of 0 for unassigned meter
            curr->nextLetter = myHead;

            myHead = curr;
            mySize++;
        }
    }
}

// RUNS INFINITELY: CHECK REVERSAL ON PAPER
LatinScan LatinScan::reverseLine() {

    LatinScan revObject;

    for (letterPtr q = myHead; q != nullptr; q = q->nextLetter) {
        letterPtr add(new letter);

        add->character = q->character;
        add->meter = q->meter;
        add->nextLetter = revObject.myHead;

        revObject.myHead = add;
    }
    return revObject;
}

void LatinScan::printLine() {

    for (letterPtr a = myHead; a != nullptr; a = a->nextLetter) {
        std::cout << a->character;
    }
    std::cout << std::endl;
}

void LatinScan::printMeter() {
    for (letterPtr a = myHead; a != nullptr; a = a->nextLetter) {
        std::cout << a->meter;
    }
    std::cout << std::endl;
}

void LatinScan::elision() {

    letterPtr pre, cur, pass;

    for (pass = myHead, pre = myHead, cur = myHead; cur != nullptr; pass = pre, pre = cur, cur = cur->nextLetter) {

        if (cur->character == ' ') {

            if (checkVowel(pre)) {

                if (checkVowel(cur->nextLetter) || cur->nextLetter->character == 'h') {

                    pass->nextLetter = pre->nextLetter;
                    mySize--;
                }
            }
        }
    }
}

void LatinScan::trimSpace() {

    letterPtr prev2, curr2;

    for (prev2 = myHead, curr2 = myHead; curr2 != nullptr; prev2 = curr2, curr2 = curr2->nextLetter) {

        if (curr2->character == ' ') {
            prev2->nextLetter = curr2->nextLetter;
            mySize--;
        }
    }
}

void LatinScan::initialMark() {
    for (letterPtr a = myHead; a != nullptr; a = a->nextLetter) {

        if (checkVowel(a)) {
            a->meter = '-';
            break;
        }
    }

    LatinScan initial = reverseLine(); // reverses the line for easier initial assignment

    int countS = 0;

    letterPtr b;

    // Loop assigns final Spondee
    // NOTE: ADD PREV POINTER
    for (b = initial.myHead; b != nullptr; b = b->nextLetter) {

        if (checkVowel(b)) {

                b->meter = '-';
                countS++;
    }
        if (countS == 2) {
            break; // stops process after assigning final foot
        }
    }

    // Loop assigns 5th-foot Dactyl
    letterPtr c;
    int countD = 0;

    for (c = b->nextLetter; c != nullptr; c = c->nextLetter) {

        if (checkVowel(c)) {

            // checks for consonantal -qu
            if (c->nextLetter->character != 'q') {

                if (countD < 2) {
                    c->meter = 'u';
                    countD++;
                    continue;
                }
                if (countD ==2) {
                    c->meter = '-';
                    break;
                }
            }
        }
    }


    LatinScan post = initial.reverseLine();

    post.printLine();
    post.printMeter();

}

// boolean helper method
bool LatinScan::checkVowel(letterPtr c) {
    return (c->character == 'a' || c->character ==  'e' || c->character ==  'i' ||
           c->character ==  'o' || c->character ==  'u' || c->character ==  'y');
}

#endif //LATINSCANSION_LATINSCANSION_CPP
