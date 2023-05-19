#include <stdio.h>
#include <stdlib.h>

#include "all_search.h"

#include "input.h"
#include "krput.h"
#include "long_quest.h"
#include "output.h"

void output(char choice, Paths* aim, Clover* kr, Roads* target)
{
    printf("\nКуда выводить решение:\n");
    printf("1)В консоль\n2)В текстовый документ\n3)В консоль и в текстовый "
           "документ\n");
    int choys;
    scanf("%d", &choys);

    switch (choice) {
    //Количество различных путей
    case '1':;
        switch (choys) {
        case 1:;

            break;
        case 2:;

            break;
        case 3:;

            break;
        default:
            printf("Выбранный номер задачи находится вне диапазона\n");
            break;
        }
        break;
    //Кратчайший путь
    case '2':;
        switch (choys) {
        case 1:;

            break;
        case 2:;

            break;
        case 3:;

            break;
        default:
            printf("Выбранный номер задачи находится вне диапазона\n");
            break;
        }
        break;
    //Длинейший путь
    case '3':
        switch (choys) {
        case 1:;

            break;
        case 2:;

            break;
        case 3:;

            break;
        default:
            printf("Выбранный номер задачи находится вне диапазона\n");
            break;
        }
        break;
    default:
        printf("Выбранный номер задачи находится вне диапазона\n");
        break;
    }
}