//
// Created by Peter Koncelik on 2019-02-08.
//

#include <iostream>

#include "LatinScansion.h"

int main() {

    LatinScan check("arma eirumque yano");

    check.elision();

    check.trimSpace();

    return 0;
}