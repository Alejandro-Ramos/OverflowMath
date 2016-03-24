/*  OverflowMath is an open source (LGPLv3) library to handle math without
 *  causing integer overflows or underflows. It is designed for C++.
 *
 *  Copyright (C) 2016 Alejandro Ramos
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


/*  This program is made to test the library's functions
 */

#include <iostream>
#include <climits>
#include <string>
#include "../src/inc/overflowMath.hpp"

void test(signed long int num, signed long int modifier,
          signed long int minNum, signed long int maxNum,
          std::string datatype, char operation);
void test(unsigned long int num, unsigned long int modifier,
          unsigned long int minNum, unsigned long int maxNum,
          std::string datatype, char operation);
void addTest();
void subtractTest();
void multiplyTest();
void divideTest();
void manualTest();

int main() {
    bool hasRunBefore = false;
    unsigned char selection;
    std::cout << "Tests for the OverflowMath library" << '\n' << std::endl;
    while (true) {
        if (hasRunBefore) {
            std::cout << "\n\n";  // user friendly spacing
        } else {
            hasRunBefore = true;
        }
            do {
            std::cout << "Select a function to test" << '\n';
            std::cout << "(0) - End program" << '\n';
            std::cout << "(1) - Manual test" << '\n';
            std::cout << "(2) - add" << '\n';
            std::cout << "(3) - subtract" << '\n';
            std::cout << "(4) - multiply" << '\n';
            std::cout << "(5) - divide" << '\n';
            std::cout << "Selection: ";
            std::cin >> selection;
            if (std::cin.fail() || selection < '0' || selection > '5') {
                std::cout << "Invalid input" << std::endl;
                error = true;
            } else {
                error = false;
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } while (error);
        switch (selection) {
            case '0':
                std::cout << "Press enter to end the program" << '\n';
                std::cout << std::endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return 0;
                break;
            case '1':
                std::cout << "Manual test" << '\n' << std::endl;
                manualTest();
                break;
            case '2':
                std::cout << "Testing add" << '\n' << std::endl;
                addTest();
                break;
            case '3':
                std::cout << "Testing subtract" << '\n' << std::endl;
                subtractTest();
                break;
            case '4':
                std::cout << "Testing multiply" << '\n' << std::endl;
                multiplyTest();
                break;
            case '5':
                std::cout << "Testing divide" << '\n' << std::endl;
                divideTest();
                break;
        }
    }
    return 0;
}

void test(signed long int num, signed long int modifier,
          signed long int minNum, signed long int maxNum,
          std::string datatype, char operation) {
    std::cout << datatype << " num = " << num << '\n';
    std::cout << datatype << " modifier = " << modifier << '\n';
    std::cout << datatype << " minNum = " << minNum << '\n';
    std::cout << datatype << " maxNum = " << maxNum << '\n';
    std::cout << "Result = " << std::flush;
    switch (operation) {
        case 0: // add
            std::cout << overflowMath::add(num, modifier, minNum, maxNum);
            std::cout << std::endl;
            break;
        case 1: // subtract
            std::cout << overflowMath::subtract(num, modifier, minNum, maxNum);
            std::cout << std::endl;
            break;
        case 2: // multiply
            std::cout << overflowMath::multiply(num, modifier, minNum, maxNum);
            std::cout << std::endl;
            break;
        case 3: // divide
            std::cout << overflowMath::divide(num, modifier, minNum, maxNum);
            std::cout << std::endl;
            break;
    }
}
void test(unsigned long int num, unsigned long int modifier,
          unsigned long int minNum, unsigned long int maxNum,
          std::string datatype, char operation) {
    std::cout << datatype << " num = " << num << '\n';
    std::cout << datatype << " modifier = " << modifier << '\n';
    std::cout << datatype << " minNum = " << minNum << '\n';
    std::cout << datatype << " maxNum = " << maxNum << '\n';
    std::cout << "Result = " << std::flush;
    switch (operation) {
        case 0: // add
            std::cout << overflowMath::add(num, modifier, minNum, maxNum);
            std::cout << std::endl;
            break;
        case 1: // subtract
            std::cout << overflowMath::subtract(num, modifier, minNum, maxNum);
            std::cout << std::endl;
            break;
        case 2: // multiply
            std::cout << overflowMath::multiply(num, modifier, minNum, maxNum);
            std::cout << std::endl;
            break;
        case 3: // divide
            std::cout << overflowMath::divide(num, modifier, minNum, maxNum);
            std::cout << std::endl;
            break;
    }
}

void addTest() {
    test(100, 200, std::numeric_limits<signed char>::min(),
        (signed long int)std::numeric_limits<signed char>::max(),
        "signed char", 0);
    std::cout << "Press enter to continue with the tests" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    test(50, 75, std::numeric_limits<signed char>::min(),
        (signed long int)100, "signed char", 0);
    std::cout << "Press enter to continue with the tests" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    test(-100, -100, std::numeric_limits<signed char>::min(),
        (signed long int)std::numeric_limits<signed char>::max(),
        "signed char", 0);
    std::cout << "Press enter to continue with the tests" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    test(50, -100, 0,
        (signed long int)std::numeric_limits<signed char>::max(),
        "signed char", 0);
    std::cout << "Press enter to select another function to test"
              << std::endl;
    std::cin.ignore(std::numeric_limits<signed char>::max(), '\n');
}

void subtractTest() {
    test(-100, 100, std::numeric_limits<signed char>::min(),
        (signed long int)std::numeric_limits<signed char>::max(),
        "signed char", 1);
    std::cout << "Press enter to continue with the tests" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    test(100, -100, std::numeric_limits<signed char>::min(),
        (signed long int)std::numeric_limits<signed char>::max(),
        "signed char", 1);
    std::cout << "Press enter to continue with the tests" << '\n';
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    test(100, 50, 75, (signed long int)100, "signed char", 1);
    std::cout << "Press enter to continue with the tests" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    test(0, -100, -50, (signed long int)75, "signed char", 1);
    std::cout << '\n' << "Press enter to select another function to test"
              << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void multiplyTest() {
    test(2, 100, std::numeric_limits<signed char>::min(),
         (signed long int)std::numeric_limits<signed char>::max(),
         "signed char", 2);
    std::cout << "Press enter to continue with the tests" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    test(-2, 100, std::numeric_limits<signed char>::min(),
         (signed long int)std::numeric_limits<signed char>::max(),
         "signed char", 2);
    std::cout << "Press enter to continue with the tests" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    test(2, 50, std::numeric_limits<signed char>::min(), (signed long int)75,
         "signed char", 2);
    std::cout << "Press enter to continue with the tests" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    test(2, -50, -75, (signed long int)std::numeric_limits<signed char>::min(),
         "signed char", 2);
    std::cout << '\n' << "Press enter to select another function to test"
              << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void divideTest() {
    test(100, 2, 75, (signed long int)std::numeric_limits<signed char>::max(),
         "signed char", 3);
    std::cout << "Press enter to continue with the tests" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    test(100, -2, -25,
         (signed long int)std::numeric_limits<signed char>::max(),
         "signed char", 3);
    std::cout << "Press enter to continue with the tests" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    test(100, 5, (signed long int)std::numeric_limits<signed char>::min(),
         10, "signed char", 3);
    std::cout << "Press enter to continue with the tests" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    test(100, -5, (signed long int)std::numeric_limits<signed char>::min(),
         -10, "signed char", 3);
    std::cout << '\n' << "Press enter to select another function to test"
              << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/*  Function to allow manual testing of the functions in OverflowMath
 *  It is very long, with a lot of code repetition, so I may decide to make
 *  it smaller or split it into smaller parts at a future date.
 */
void manualTest() {
    char selection;
    bool isSigned = true;
    bool error = false;
    char operation;

    unsigned long int unsignedNum;
    unsigned long int unsignedModifier;
    unsigned long int unsignedMinNum;
    unsigned long int unsignedMaxNum;

    signed long int signedNum;
    signed long int signedModifier;
    signed long int signedMinNum;
    signed long int signedMaxNum;

    std::cout << "Each operation takes the values of 'num, 'modifier',\n";
    std::cout << "'minNum', and 'maxNum'.\n\n";

    // get datatype
    do {
        std::cout << "Enter 0 for signed, or 1 for unsigned long int" << '\n';
        std::cout << "signed long int can go from ";
        std::cout << std::numeric_limits<signed long int>::min();
        std::cout << " to ";
        std::cout << std::numeric_limits<signed long int>::max() << '\n';
        std::cout << "unsigned long int can go from ";
        std::cout << std::numeric_limits<unsigned long int>::min();
        std::cout << " to ";
        std::cout << std::numeric_limits<unsigned long int>::max() << '\n';
        std::cin >> selection;
        if (std::cin.fail() ||
            !(selection >= '0') || !(selection <= '1')) {
            std::cout << "Invalid input" << std::endl;
            error = true;
        } else {
            error = false;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (error);
    if (selection == '1') isSigned = false;

    // get num value
    do {
        std::cout << "num ";
        if (isSigned) {
            std::cout << "(signed) = ";
            std::cin >> signedNum;
        } else {
            std::cout << "(unsigned) = ";
            std::cin >> unsignedNum;
        }
        if (std::cin.fail()) {
            std::cout << "Invalid input" << std::endl;
            error = true;
        } else {
            error = false;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (error);

    // get modifier value
    do {
        std::cout << "modifier ";
        if (isSigned) {
            std::cout << "(signed) = ";
            std::cin >> signedModifier;
        } else {
            std::cout << "(unsigned) = ";
            std::cin >> unsignedModifier;
        }
        if (std::cin.fail()) {
            std::cout << "Invalid input" << std::endl;
            error = true;
        } else {
            error = false;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (error);

    // get minNum value
    do {
        std::cout << "minNum ";
        if (isSigned) {
            std::cout << "(signed) = ";
            std::cin >> signedMinNum;
        } else {
            std::cout << "(unsigned) = ";
            std::cin >> unsignedMinNum;
        }
        if (std::cin.fail()) {
            std::cout << "Invalid input" << std::endl;
            error = true;
        } else {
            error = false;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (error);

    // get maxNum value
    do {
        std::cout << "maxNum ";
        if (isSigned) {
            std::cout << "(signed) = ";
            std::cin >> signedMaxNum;
        } else {
            std::cout << "(unsigned) = ";
            std::cin >> unsignedMaxNum;
        }
        if (std::cin.fail()) {
            std::cout << "Invalid input" << std::endl;
            error = true;
        } else {
            error = false;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (error);
    std::cout << "Please select an operation to perform\n";
    do {
        std::cout << "(0) Addition" << '\n';
        std::cout << "(1) Subtraction" << '\n';
        std::cout << "(2) Multiplication" << '\n';
        std::cout << "(3) Division" << '\n';
        std::cin >> operation;
        if (std::cin.fail() ||
            !(operation >= '0') || !(operation <= '3')) {
            std::cout << "Invalid input" << std::endl;
            error = true;
        }
        else {
            error = false;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (error);

    // the ascii codes for numbers start at 48, so one can subtract 48 to get
    // the number the ascii code represents
    operation = operation - 48;
    std::cout << "All parameters entered, testing operation" << std::endl;
    if (isSigned) {
        test(signedNum, signedModifier, signedMinNum, signedMaxNum,
             "signed long int", operation);
    } else {
        test(unsignedNum, unsignedModifier, unsignedMinNum, unsignedMaxNum,
             "unsigned long int", operation);
    }

    std::cout << "Press enter to select another function to test" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
