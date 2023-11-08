# Simple Calculator (simcalc)

## Introduction
`simcalc` is a command-line program that performs basic mathematical operations, including addition, subtraction, multiplication, division, exponentiation, and root calculations. This program is free software and is distributed under the GNU General Public License (GPL) version 3.0 or later.

## Usage
```
simcalc [OPTION]...
```

## Options
- `-a, --addition A B`                Calculate the sum of two numbers A and B.
- `-s, --subtraction A B`             Calculate the difference of two numbers A and B.
- `-m, --multiplication A B`          Calculate the product of two numbers A and B.
- `-d, --division A B`                Calculate the division of two numbers A and B.
- `-e, --exponentiation BASE EXP`     Calculate the exponentiation of BASE to the power of EXP.
- `-r, --root BASE EXP`               Calculate the root of BASE to the power of 1/EXP.
- `-h, --help`                        Display this help message and exit.
- `-v, --version`                     Display the program version and exit.

## Example Usage
- To add two numbers, 5 and 3:
  ```
  simcalc -a 5 3
  ```

- To subtract 10 from 25:
  ```
  simcalc -s 25 10
  ```

- To multiply 6 by 4:
  ```
  simcalc -m 6 4
  ```

- To divide 20 by 4:
  ```
  simcalc -d 20 4
  ```

- To calculate the square of 5:
  ```
  simcalc -e 5 2
  ```

- To calculate the cube root of 8:
  ```
  simcalc -r 8 3
  ```

## License
This program is free software and is distributed under the terms of the GNU General Public License (GPL) version 3.0 or later. For more details, please see the [GNU General Public License](http://www.gnu.org/licenses/).

## Version
`simcalc` version: 0.1

## Author
- Darius Drake

Please refer to the GNU General Public License for more details regarding the terms and conditions of using this software.
