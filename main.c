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
#include <stdbool.h>
#include <getopt.h>

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
        exit(1);
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
        exit(1);
    }
    
    if (exp == 0) {
        return 1;
    }

    double epsilon = 0.000001;
    double x = 1.0;

    while (1) {
        double nextX = ((exp - 1) * x + base / exponentiation(x, exp - 1)) / exp;

        if (nextX - x < epsilon && x - nextX < epsilon) {
            break; // Convergence reached
        }

        x = nextX;
    }

    return x;
}

void displayHelp() {
    printf("Usage: calculator [OPTION]...\n");
    printf("A simple calculator program that performs basic mathematical operations.\n");
    printf("\nOptions:\n");
    printf("  -a A B      Calculate the sum of two numbers A and B.\n");
    printf("  -s A B      Calculate the difference of two numbers A and B.\n");
    printf("  -m A B      Calculate the product of two numbers A and B.\n");
    printf("  -d A B      Calculate the division of two numbers A and B.\n");
    printf("  -e BASE EXP Calculate the exponentiation of BASE to the power of EXP.\n");
    printf("  -r BASE EXP Calculate the root of BASE to the power of 1/EXP.\n");
    printf("  -h          Display this help message and exit.\n");
}

void run(int argc, char **argv) {
    if (argc == 1) {
        displayHelp();
        exit(0);
    }

    int opt;
    double result;

    while ((opt = getopt(argc, argv, "a:s:m:d:e:r:h")) != -1) {
        switch (opt) {
            case 'a':
                result = addition(atof(optarg), atof(argv[optind]));
                printf("Addition result: %.3lf\n", result);
                break;
            case 's':
                result = subtraction(atof(optarg), atof(argv[optind]));
                printf("Subtraction result: %.3lf\n", result);
                break;
            case 'm':
                result = multiplication(atof(optarg), atof(argv[optind]));
                printf("Multiplication result: %.3lf\n", result);
                break;
            case 'd':
                result = division(atof(optarg), atof(argv[optind]));
                printf("Division result: %.3lf\n", result);
                break;
            case 'e':
                result = exponentiation(atof(optarg), atof(argv[optind]));
                printf("Exponentiation result: %.3lf\n", result);
                break;
            case 'r':
                result = calculateRoot(atof(optarg), atof(argv[optind]));
                printf("Root result: %.3lf\n", result);
                break;
            case 'h':
                displayHelp();
                exit(0);
            default:
                fprintf(stderr, "Invalid command line option. Use '-h' for help.\n");
                exit(1);
        }
    }
}

int main(int argc, char **argv) {
    run(argc, argv);
    return 0;
}
