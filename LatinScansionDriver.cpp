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