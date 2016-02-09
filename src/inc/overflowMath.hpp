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


/*  This namespace holds all of the functions that wrap around simple math
 *  operators while preventing integer overflows and underflows.
 */

#ifndef OVERFLOWMATH_HPP // for inclusion guard
#define OVERFLOWMATH_HPP

namespace overflowMath {
    // Addition functions to stop overflow
    signed long int add(const signed long int& num,
                        const signed long int& modifier,
                        const signed long int& minNum,
                        const signed long int& maxNum);
    unsigned long int add(const unsigned long int& num,
                          const unsigned long int& modifier,
                          const unsigned long int& minNum,
                          const unsigned long int& maxNum);

    // Subtraction
    signed long int subtract(const signed long int& num,
                             const signed long int& modifier,
                             const signed long int& minNum,
                             const signed long int& maxNum);
    unsigned long int subtract(const unsigned long int& num,
                               const unsigned long int& modifier,
                               const unsigned long int& minNum,
                               const unsigned long int& maxNum);

    // Multiplication
    signed long int multiply(const signed long int& num,
                             const signed long int& modifier,
                             const signed long int& minNum,
                             const signed long int& maxNum);
    unsigned long int multiply(const unsigned long int& num,
                               const unsigned long int& modifier,
                               const unsigned long int& minNum,
                               const unsigned long int& maxNum);

    // Division
    signed long int divide(const signed long int& num,
                           const signed long int& modifier,
                           const signed long int& minNum,
                           const signed long int& maxNum);
    unsigned long int divide(const unsigned long int& num,
                             const unsigned long int& modifier,
                             const unsigned long int& minNum,
                             const unsigned long int& maxNum);
}
#endif // inclusion guard
