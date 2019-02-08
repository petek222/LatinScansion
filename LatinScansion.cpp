//
// Created by Peter Koncelik on 2019-02-08.
//

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
            curr->meter = '0'; // default value of 0 for unassigned meter
            curr->nextLetter = myHead;

            myHead = curr;
            mySize++;
        }
    }
}

void LatinScan::elision() {

    letterPtr pre, cur, pass;

    for (pass = myHead, pre = myHead, cur = myHead; cur != nullptr; pass = pre, pre = cur, cur = cur->nextLetter) {

        if (cur->character == ' ') {

            if (pre->character == 'a' || pre->character == 'e' || pre->character == 'i' ||
        pre->character == 'o' || pre->character ==  'u' || pre->character == 'y') {

                if (cur->nextLetter->character == 'a' || cur->nextLetter->character == 'e' ||
                    cur->nextLetter->character == 'i' || cur->nextLetter->character == 'o' ||
                    cur->nextLetter->character == 'u' || cur->nextLetter->character == 'y' ||
                    cur->nextLetter->character == 'h') {

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