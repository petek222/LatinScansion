//
// Created by Peter Koncelik on 2019-02-08.
//


#ifndef LATINSCANSION_LATINSCANSION_CPP
#define LATINSCANSION_LATINSCANSION_CPP

#include "LatinScansion.h"

LatinScan::LatinScan() : myHead(nullptr) {

    // initializes diphthong set with proper values
    diphthongs.insert("ae");
    diphthongs.insert("oe");
    diphthongs.insert("au");
    diphthongs.insert("ei");
    diphthongs.insert("eu");
    diphthongs.insert("ui");
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
        if (a->meter == '/') {
            std::cout << " ";
        }
        else {
            std::cout << a->meter;
        }
    }
    std::cout << std::endl;
}

void LatinScan::elision() {

    letterPtr pre, cur, pass;

    for (pass = myHead, pre = myHead, cur = myHead; cur != nullptr; pass = pre, pre = cur,
            cur = cur->nextLetter) {

        char mEnd[2];
        mEnd[0] = pass->character;
        mEnd[1] = pre->character;

        std::string finalUM;
        finalUM+=mEnd[0];
        finalUM+=mEnd[1];

        if (cur->character == ' ') {

            if (checkVowel(pre) || finalUM == "um") {

                if (checkVowel(cur->nextLetter) || cur->nextLetter->character == 'h') {

                    pass->nextLetter = pre->nextLetter;
                    mySize--;

                    if (finalUM == "um") {
                        pass->meter = '/';
                    }
                }
            }
        }
    }
}

void LatinScan::trimSpace() {

    letterPtr prev2, curr2;

    for (prev2 = myHead, curr2 = myHead; curr2 != nullptr; prev2 = curr2, curr2 = curr2->nextLetter)
    {

        if (curr2->character == ' ') {
            prev2->nextLetter = curr2->nextLetter;
            mySize--;
        }
    }
}

LatinScan LatinScan::initialMark() {
    for (letterPtr a = myHead; a != nullptr; a = a->nextLetter) {

        if (checkVowel(a) && a->meter != '/') {
            a->meter = '-';
            break;
        }
    }

    LatinScan initial = reverseLine(); // reverses the line for easier initial assignment

    int countS = 0;

    letterPtr b;

    // Loop assigns final Spondee
    for (b = initial.myHead; b != nullptr; b = b->nextLetter) {

        if (checkVowel(b) && b->meter != '/') {

            if (b->nextLetter->character != 'q') {

                b->meter = '-';
                countS++;
            }
    }
        if (countS == 2) {
            break; // stops process after assigning final foot
        }
    }

    // Loop assigns 5th-foot Dactyl
    letterPtr c;
    int countD = 0;

    // Try/Catch block for null reference?: "This is not a proper line of dactylic hexameter"
    for (c = b->nextLetter; c != nullptr; c = c->nextLetter) {

        if (checkVowel(c) && c->meter != '/') {

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

    post.markDiphthongs(); // Call down hierarchy to markDipthongs method

    post.printMeter();
    post.printLine();

    return post;
}

LatinScan LatinScan::markDiphthongs() {

    letterPtr qCheck; // ensures qu is counted as consonant (e. qui is NOT a diphthong)
    letterPtr first;
    letterPtr second;

    for (qCheck = myHead, first = myHead, second = myHead->nextLetter; second != nullptr;
    qCheck = first, first = second, second = second->nextLetter) {

        char concat[2];
        concat[0] = first->character;
        concat[1] = second->character;

        std::string concatenate;
        concatenate+=concat[0];
        concatenate+=concat[1];

        std::string checkDiph = concatenate;

        if (diphthongs.find(checkDiph) != diphthongs.end() && qCheck->character != 'q' && first->meter != '/') {
            first->meter = '-';
            second->meter = '/'; // NOTE: slash indicates it has been referenced,
                                 // but does not get a meter assignment
        }
    }

    markDoubleConsonants(); // call down the hierarchy to markDoubleConsonants

    return *this;
}

LatinScan LatinScan::markDoubleConsonants() {
    letterPtr pre;
    letterPtr now;

    for (pre = myHead, now = myHead; now != nullptr; pre = now, now = now->nextLetter) {

        if (checkVowel(pre) && now->nextLetter != nullptr) {

            if (!checkVowel(now) && !checkVowel(now->nextLetter) && now->meter != '/') {
                pre->meter = '-';
            }
            else if (now->character == 'x') {
                pre->meter = '-';
            }
        }
    }

    markRemainder(); // call to markRemainder() function

    return *this;
}

//// REFINE/UPDATE USING feetCount private var: Maybe offload meter into another linked list?
//// Possibly use an array for tracking meter instead?
LatinScan LatinScan::markRemainder() {
    letterPtr rem;
    letterPtr qCheck;



    // Embedded Loop Function Scans down the next vowels and checks meters, filling in as needed
    // IN DEV: NOT COMPLETE: COMMENTED OUT CODE IS PROGRESS, CURRENT IMP MAKES COMPILER

    for ( qCheck = myHead, rem = myHead; rem != nullptr; qCheck = rem, rem=rem->nextLetter) {

//        if ((checkVowel(rem) && rem->meter != '-' && rem->meter != 'u' && rem->meter != '/') {
//
//            for (letterPtr secCheck = qCheck; secCheck != nullptr; secCheck = secCheck->nextLetter) {
//
//                if (checkVowel(secCheck)  && secCheck->meter != '-' && secCheck->meter != 'u' && secCheck->meter != '/') {
//
//                    for (letterPtr thirCheck = qCheck; thirCheck != nullptr; thirCheck = thirCheck->nextLetter) {
//
//                        if ()
//
//                    }
//            }
//        }

        if (checkVowel(rem) && rem->meter != '-' && rem->meter != 'u' && rem->meter != '/'
        && qCheck->character != 'q') {
            rem->meter = 'u';
        }

    }
    return *this;
}

// boolean helper method
bool LatinScan::checkVowel(letterPtr c) {
    return (c->character == 'a' || c->character ==  'e' || c->character ==  'i' ||
           c->character ==  'o' || c->character ==  'u' || c->character ==  'y');
}

#endif //LATINSCANSION_LATINSCANSION_CPP
