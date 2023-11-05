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
#include <stdbool.h>

double sum(double a, double b)
{
    return a + b;
}

double res(double a, double b)
{
    return a - b;
}

double mul(double a, double b)
{
    return a * b;
}

double div(double a, double b)
{
    return a / b;
}

void getInput(double *a, double *b)
{
    // variable de control para validar input
    bool validInput = false;

    // input 1
    while (!validInput)
    {
        printf("Intruduzca el primer numero: ");
        if (scanf("%lf", a) == 1)
        {
            validInput = true;
        }
        else
        {
            while (getchar() != '\n');
            printf("Introduzca un numero valido.\n\n");
        }
	}

    // reseteamos la variable validInput para validar el input 2
    validInput = false;

    // input 2
    while (!validInput)
    {
        printf("Intruduzca el segundo numero: ");
        if (scanf("%lf", b) == 1)
        {
            validInput = true;
        }
        else
        {
            while (getchar() != '\n');
            printf("Introduzca un numero valido.\n\n");
        }
    }
}

void run()
{
    // declaraciones
    double numA, numB, result;
    int option, status, temp;

    // obtiene los numeros a operar
    getInput(&numA, &numB);

    // menu principal
    printf("¿Que operación desea realizar? [1,2,3,4] \n");
    printf("\t1. Suma\n");
    printf("\t2. Resta\n");
    printf("\t3. Multiplicación\n");
    printf("\t4. División\n");
    printf("Elije: ");

    // obtiene la opción elegida del menu
    status = scanf("%d", &option);

    // valida que la opción elegida sea un entero
    while(status!=1){
        while((temp=getchar()) != EOF && temp != '\n');
        printf("Entrada invaldia... Introduzca una opción valida [1,2,3,4]: ");
        status = scanf("%d", &option);
    }
	
    // casos para cada opción del menu
    switch (option)
    {
        // suma
        case 1:
            result = sum(numA, numB);
            break;
        // resta
        case 2:
            result = res(numA, numB);
            break;
        // multiplicación
        case 3:
            result = mul(numA, numB);
            break;
        // división
        case 4:
            result = div(numA, numB);
            break;
        // imprime solo un salto de línea de lo contrario
        default:
            printf("\n");
    }

    // resultado
    printf("El resultado es: %.3lf \n", result);
}

int main(int argc, char **argv)
{
    run();
    return 0;
}
