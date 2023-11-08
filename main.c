/* 
 * main.c
 *
 * Copyright 2023 Darius Drake
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdbool.h>
#include <ctype.h>

#define VERSION 0.1

// Function prototypes
bool isNumeric(const char* str);
double addition(double a, double b);
double subtraction(double a, double b);
double multiplication(double a, double b);
double division(double a, double b);
double exponentiation(double base, double exp);
double calculateRoot(double base, double exp);
void displayHelp();
void displayVersion();

int main(int argc, char **argv) {
    if (argc == 1) {
        displayHelp();
        return 1;
    }

    int opt;
    double result;

    static const char* const short_options = "a:s:m:d:e:r:hv";
    static struct option long_options[] = {
        {"addition", required_argument, NULL, 'a'},
        {"subtraction", required_argument, NULL, 's'},
        {"multiplication", required_argument, NULL, 'm'},
        {"division", required_argument, NULL, 'd'},
        {"exponentiation", required_argument, NULL, 'e'},
        {"root", required_argument, NULL, 'r'},
        {"help", no_argument, NULL, 'h'},
        {"version", no_argument, NULL, 'v'},
        {NULL, 0, NULL, 0}
    };

    while ((opt = getopt_long(argc, argv, short_options, long_options, NULL)) != -1) {
        switch (opt) {
            case 'a':
            case 's':
            case 'm':
            case 'd':
            case 'e':
            case 'r':
                if (!isNumeric(optarg)) {
                    fprintf(stderr, "Invalid value. Enter a valid number to convert.\n");
                    return 1;
                }

                if (optind >= argc) {
                    fprintf(stderr, "Error: Missing the second argument for option '-%c'.\n", opt);
                    return 1;
                }

                double firstArg = atof(optarg);
                double secondArg = atof(argv[optind++]);

                switch (opt) {
                    case 'a':
                        result = addition(firstArg, secondArg);
                        printf("Addition result: %.3lf\n", result);
                        break;
                    case 's':
                        result = subtraction(firstArg, secondArg);
                        printf("Subtraction result: %.3lf\n", result);
                        break;
                    case 'm':
                        result = multiplication(firstArg, secondArg);
                        printf("Multiplication result: %.3lf\n", result);
                        break;
                    case 'd':
                        result = division(firstArg, secondArg);
                        printf("Division result: %.3lf\n", result);
                        break;
                    case 'e':
                        result = exponentiation(firstArg, secondArg);
                        printf("Exponentiation result: %.3lf\n", result);
                        break;
                    case 'r':
                        result = calculateRoot(firstArg, secondArg);
                        printf("Root result: %.3lf\n", result);
                        break;
                }
                break;
            case 'h':
                displayHelp();
                return 0;
            case 'v':
                displayVersion();
                return 0;
            default:
                fprintf(stderr, "Use '-h' for help.\n");
                return 1;
        }
    }

    // Check for unsupported options
    for (int i = optind; i < argc; i++) {
        if (argv[i][0] != '-') {
            fprintf(stderr, "Invalid option or argument '%s'. Use '-h, --help' for help.\n", argv[i]);
        }
    }

    return 0;
}


// Function to check if a string is numeric
bool isNumeric(const char* str) {
    for (int i = 0; str[i]; i++) {
        if (!isdigit(str[i]) && str[i] != '.' && str[i] != '-') {
            return false;
        }
    }
    return true;
}

// Function definitions
double addition(double a, double b) {
    return a + b;
}

double subtraction(double a, double b) {
    return a - b;
}

double multiplication(double a, double b) {
    return a * b;
}

double division(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        fprintf(stderr, "Error: Division by zero\n");
        return 1;
    }
}

double exponentiation(double base, double exp) {
    double result = 1.0;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

double calculateRoot(double base, double exp) {
    if (base < 0 && exp != 0) {
        fprintf(stderr, "Error: Cannot calculate the root of a negative number\n");
        return 1;
    }

    if (exp == 0) {
        return 1;
    }

    double epsilon = 0.000001;
    double x = 1.0;

    while (1) {
        double nextX = ((exp - 1) * x + base / exponentiation(x, exp - 1)) / exp;

        if (nextX - x < epsilon && x - nextX < epsilon) {
            break;
        }

        x = nextX;
    }

    return x;
}

void displayHelp() {
    printf("Usage: simcalc [OPTION]...\n");
    printf("A simple simcalc program that performs basic mathematical operations.\n");
    printf("\nOptions:\n");
    printf("\t-a, --addition A B                Calculate the sum of two numbers A and B.\n");
    printf("\t-s, --subtraction A B             Calculate the difference of two numbers A and B.\n");
    printf("\t-m, --multiplication A B          Calculate the product of two numbers A and B.\n");
    printf("\t-d, --division A B                Calculate the division of two numbers A and B.\n");
    printf("\t-e, --exponentiation BASE EXP     Calculate the exponentiation of BASE to the power of EXP.\n");
    printf("\t-r, --root BASE EXP               Calculate the root of BASE to the power of 1/EXP.\n");
    printf("\t-h, --help                        Display this help message and exit.\n");
    printf("\t-v, --version                     Display the program version and exit.\n");
}

void displayVersion() {
    printf("simcalc. version: %.2lf", VERSION);
}
