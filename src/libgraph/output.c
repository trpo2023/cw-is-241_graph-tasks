#include <stdio.h>
#include <stdlib.h>

#include <libgraph/all_search.h>
#include <libgraph/input.h>
#include <libgraph/krput.h>
#include <libgraph/long_quest.h>
#include <libgraph/output.h>

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
            printf("\nНайдено %d пути(ей):\n", aim->number);
            for (int i = 0; i < aim->number; i++) {
                printf("%d. ", i + 1);
                int j = 0;
                for (j = 0; j < MAX_SIZE && aim->all_paths[i][j + 1] != -1;
                     j++) {
                    printf("%d - > ", aim->all_paths[i][j] + 1);
                }
                printf("%d", aim->all_paths[i][j] + 1);
                printf("\n");
            }
            break;
        case 2:;
            FILE* fp = fopen("output.txt", "w");
            fprintf(fp, "Найдено %d пути(ей):\n", aim->number);
            for (int i = 0; i < aim->number; i++) {
                fprintf(fp, "%d. ", i + 1);
                int j = 0;
                for (j = 0; j < MAX_SIZE && aim->all_paths[i][j + 1] != -1;
                     j++) {
                    fprintf(fp, "%d - > ", aim->all_paths[i][j] + 1);
                }
                fprintf(fp, "%d", aim->all_paths[i][j] + 1);
                fprintf(fp, "\n");
            }
            fclose(fp);
            printf("Файл был записан\n");
            break;
        case 3:;
            printf("\nНайдено %d пути(ей):\n", aim->number);
            for (int i = 0; i < aim->number; i++) {
                printf("%d. ", i + 1);
                int j = 0;
                for (j = 0; j < MAX_SIZE && aim->all_paths[i][j + 1] != -1;
                     j++) {
                    printf("%d - > ", aim->all_paths[i][j] + 1);
                }
                printf("%d", aim->all_paths[i][j] + 1);
                printf("\n");
            }

            FILE* f = fopen("output.txt", "w");
            fprintf(f, "Найдено %d пути(ей):\n", aim->number);
            for (int i = 0; i < aim->number; i++) {
                fprintf(f, "%d. ", i + 1);
                int j = 0;
                for (j = 0; j < MAX_SIZE && aim->all_paths[i][j + 1] != -1;
                     j++) {
                    fprintf(f, "%d - > ", aim->all_paths[i][j] + 1);
                }
                fprintf(f, "%d", aim->all_paths[i][j] + 1);
                fprintf(f, "\n");
            }
            fclose(f);
            printf("\nФайл был сохранен\n");
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
            printf("\nВывод кратчайшего пути:\n");
            for (int i = 0; i <= kr->k - 1; i++) {
                printf("%3d ", kr->ver[i]);
                if (i != kr->k - 1) {
                    printf(" - > ");
                }
            }
            printf(" = %d", kr->ves);
            printf("\n");
            break;
        case 2:;
            FILE* fp = fopen("output.txt", "w");
            fprintf(fp, "Вывод кратчайшего пути:\n");
            for (int i = 0; i <= kr->k - 1; i++) {
                fprintf(fp, "%3d ", kr->ver[i]);
                if (i != kr->k - 1) {
                    fprintf(fp, " - > ");
                }
            }
            fprintf(fp, " = %d", kr->ves);
            fprintf(fp, "\n");
            fclose(fp);
            printf("\nФайл был сохранен\n");
            break;
        case 3:;
            printf("\nВывод кратчайшего пути:\n");
            for (int i = 0; i <= kr->k - 1; i++) {
                printf("%3d ", kr->ver[i]);
                if (i != kr->k - 1) {
                    printf(" - > ");
                }
            }
            printf(" = %d", kr->ves);
            printf("\n");

            FILE* f = fopen("output.txt", "w");
            fprintf(f, "Вывод кратчайшего пути:\n");
            for (int i = 0; i <= kr->k - 1; i++) {
                fprintf(f, "%3d ", kr->ver[i]);
                if (i != kr->k - 1) {
                    fprintf(f, " - > ");
                }
            }
            fprintf(f, " =  %d", kr->ves);
            fprintf(f, "\n");
            fclose(f);
            printf("\nФайл был сохранен\n");
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
            int j = 0;
            printf("\nДлина длинейшего пути:\n");
            for (j = 0; j < MAX_SIZE && target->path[j + 1] != -1; j++) {
                printf("%d -> ", target->path[j] + 1);
            }
            printf("%d = %d", target->path[j] + 1, target->path_dist);
            printf("\n");
            break;
        case 2:;
            FILE* fp = fopen("output.txt", "w");
            j = 0;
            fprintf(fp, "Длина длинейшего пути:\n");
            for (j = 0; j < MAX_SIZE && target->path[j + 1] != -1; j++) {
                fprintf(fp, "%d - > ", target->path[j] + 1);
            }
            fprintf(fp, "%d = %d", target->path[j] + 1, target->path_dist);
            fprintf(fp, "\n");
            fclose(fp);
            printf("\nФайл был сохранен\n");
            break;
        case 3:;
            j = 0;
            printf("\nДлина длинейшего пути:\n");
            for (j = 0; j < MAX_SIZE && target->path[j + 1] != -1; j++) {
                printf("%d -> ", target->path[j] + 1);
            }
            printf("%d = %d", target->path[j] + 1, target->path_dist);
            printf("\n");

            FILE* f = fopen("output.txt", "w");
            j = 0;
            fprintf(f, "Длина длинейшего пути:\n");
            for (j = 0; j < MAX_SIZE && target->path[j + 1] != -1; j++) {
                fprintf(f, "%d - > ", target->path[j] + 1);
            }
            fprintf(f, "%d = %d", target->path[j] + 1, target->path_dist);
            fprintf(f, "\n");
            fclose(f);
            printf("\nФайл был сохранен\n");
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