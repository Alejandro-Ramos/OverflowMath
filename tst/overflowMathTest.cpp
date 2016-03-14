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

void addTest();
void test(signed long int num, signed long int modifier,
          signed long int minNum, signed long int maxNum,
          std::string datatype, char operation);
void test(unsigned long int num, unsigned long int modifier,
          unsigned long int minNum, unsigned long int maxNum,
          std::string datatype, char operation);
void subtractTest();

int main() {
    bool hasRunBefore = false;
    unsigned short int selection;
    std::cout << "Tests for overflowMath library" << '\n' << std::endl;
    while (true) {
        if (hasRunBefore) {
            std::cout << "\n\n";  // user friendly spacing
        } else {
            hasRunBefore = true;
        }
        std::cout << "Select a function to test" << '\n';
        std::cout << "(0) - End program" << '\n';
        std::cout << "(1) - add" << '\n';
        std::cout << "(2) - subtract" << '\n';
        std::cout << "Selection: ";
        std::cin >> selection;
        if (std::cin.fail() ||
            !(selection >= 0) || !(selection <= 2)) {
            std::cout << "Invalid input" << std::endl;
            return 1;
        }
        std::cin.clear();
        std::cin.ignore();
        switch (selection) {
            case 0:
                std::cout << "Ending program" << '\n' << std::endl;
                return 0;
                break;
            case 1:
                std::cout << "Testing add" << '\n' << std::endl;
                addTest();
                break;
            case 2:
                std::cout << "Testing subtract" << '\n' << std::endl;
                subtractTest();
                break;
        }
    }
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
        /*case 2: // multiply
            std::cout << overflowMath::multiply(num, modifier, minNum
                (signed long int)maxNum) << std::endl;
            break;
        case 3: // divide
            std::cout << overflowMath::divide(num, modifer, minNum
                (signed long int)maxNum) << std::endl;
            break; */
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
        /*case 2: // multiply
        std::cout << overflowMath::multiply(num, modifier, minNum
        (signed long int)maxNum) << std::endl;
        break;
        case 3: // divide
        std::cout << overflowMath::divide(num, modifer, minNum
        (signed long int)maxNum) << std::endl;
        break; */
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
}

void subtractTest() {
    test(-100, 100, std::numeric_limits<signed char>::min(),
        (signed long int)std::numeric_limits<signed char>::max(),
        "signed char", 0);
    std::cout << "Press enter to continue with the tests" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    test(100, -100, std::numeric_limits<signed char>::min(),
        (signed long int)std::numeric_limits<signed char>::max(),
        "signed char", 0);
    std::cout << "Press enter to continue with the tests" << '\n';
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    test(100, 50, 75, (signed long int)100, "signed char", 0);
    std::cout << "Press enter to continue with the tests" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    test(0, -100, -50, (signed long int)75, "signed char", 0);
    std::cout << '\n' << "Press enter to select another function to test"
              << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
