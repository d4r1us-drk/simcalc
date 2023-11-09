# simcalc - Simple Calculator

## Table of Contents

- [Introduction](#introduction)
- [Building](#building)
- [Usage](#usage)
- [Options](#options)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)

## Introduction
`simcalc` is a command-line program that performs basic mathematical operations, including addition, subtraction, multiplication, division, exponentiation, and root calculations.

## Building

This tool is provided as source code and can be built using `make`. Here
are the build instructions:

1. Clone the repository:

   ```bash
   git clone https://github.com/d4r1us-drk/simcalc.git
   ```

2. Change the directory to the cloned repository:

   ```bash
   cd simcalc
   ```

3. Build the tool using `make`:

   ```bash
   make
   ```

You should now have an executable named `simcalc`. You can copy it to a
location in your PATH for easy access.

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

## Examples
1. To add two numbers, 5 and 3:
  ```
  simcalc -a 5 3
  ```

2. To subtract 10 from 25:
  ```
  simcalc -s 25 10
  ```

3. To multiply 6 by 4:
  ```
  simcalc -m 6 4
  ```

4. To divide 20 by 4:
  ```
  simcalc -d 20 4
  ```

5. To calculate the square of 5:
  ```
  simcalc -e 5 2
  ```

6. To calculate the cube root of 8:
  ```
  simcalc -r 8 3
  ```

## Contributing

If you would like to contribute to Passgen, please create a pull request on the
GitHub repository.

## License

This project is licensed under the GPLv3 License - see the [LICENSE](LICENSE)
file for details.
