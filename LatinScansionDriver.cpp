//
// Created by Peter Koncelik on 2019-02-08.
//

#include <iostream>
#include "LatinScansion.h"

// main below checks each step

int main() {

    LatinScan check("arma eirumque yano");

    check.elision();

    check.trimSpace();

    //check.printLine();

    std::cout << std::endl;

    check.initialMark();

    //check.printMeter();

    LatinScan rev = check.reverseLine();

    // printline function prints infinitely: error in reverseLine
    //rev.printLine();

    return 0;
}