#include <ctest.h>
#include <stdlib.h>

#include <libgraph/all_search.h>
#include <libgraph/input.h>
#include <libgraph/krput.h>
#include <libgraph/long_quest.h>

CTEST(all_search, search)
{
    Matrix* graph_1 = (Matrix*)malloc(sizeof(Matrix));
    graph_1->matrix = prepare_two_dim_arr(graph_1->matrix);

    graph_1->matrix[0][0] = 0;
    graph_1->matrix[0][1] = 5;
    graph_1->matrix[0][2] = 0;
    graph_1->matrix[0][3] = 4;
    graph_1->matrix[0][4] = 6;

    graph_1->matrix[1][0] = 5;
    graph_1->matrix[1][1] = 0;
    graph_1->matrix[1][2] = 3;
    graph_1->matrix[1][3] = 0;
    graph_1->matrix[1][4] = 0;

    graph_1->matrix[2][0] = 0;
    graph_1->matrix[2][1] = 3;
    graph_1->matrix[2][2] = 0;
    graph_1->matrix[2][3] = 6;
    graph_1->matrix[2][4] = 10;

    graph_1->matrix[3][0] = 4;
    graph_1->matrix[3][1] = 0;
    graph_1->matrix[3][2] = 6;
    graph_1->matrix[3][3] = 0;
    graph_1->matrix[3][4] = 5;

    graph_1->matrix[4][0] = 6;
    graph_1->matrix[4][1] = 0;
    graph_1->matrix[4][2] = 10;
    graph_1->matrix[4][3] = 5;
    graph_1->matrix[4][4] = 0;

    graph_1->matrix_size = 5;

    Paths* aim = (Paths*)malloc(sizeof(Paths));
    aim->all_paths = prepare_two_dim_arr(aim->all_paths);
    aim->number = 0;

    int start = 1;
    int end = 5;
    aim = how_many_paths(start - 1, end - 1, graph_1, aim);
    int expected = 5;
    int result = aim->number;
    ASSERT_EQUAL(expected, result);
    aim->number = 0;

    start = 4;
    end = 2;
    aim = how_many_paths(start - 1, end - 1, graph_1, aim);
    expected = 6;
    result = aim->number;
    ASSERT_EQUAL(expected, result);
    aim->number = 0;

    start = 2;
    end = 3;
    aim = how_many_paths(start - 1, end - 1, graph_1, aim);
    expected = 5;
    result = aim->number;
    ASSERT_EQUAL(expected, result);
    aim->number = 0;

    for (int i = 0; i < graph_1->matrix_size; i++) {
        free(graph_1->matrix[i]);
    }
    free(graph_1);

    Matrix* graph_2 = (Matrix*)malloc(sizeof(Matrix));
    graph_2->matrix = prepare_two_dim_arr(graph_2->matrix);

    graph_2->matrix[0][0] = 0;
    graph_2->matrix[0][1] = 19;
    graph_2->matrix[0][2] = 10;
    graph_2->matrix[0][3] = 0;
    graph_2->matrix[0][4] = 0;
    graph_2->matrix[0][5] = 0;
    graph_2->matrix[0][6] = 0;

    graph_2->matrix[1][0] = 19;
    graph_2->matrix[1][1] = 0;
    graph_2->matrix[1][2] = 15;
    graph_2->matrix[1][3] = 0;
    graph_2->matrix[1][4] = 0;
    graph_2->matrix[1][5] = 0;
    graph_2->matrix[1][6] = 0;

    graph_2->matrix[2][0] = 10;
    graph_2->matrix[2][1] = 15;
    graph_2->matrix[2][2] = 0;
    graph_2->matrix[2][3] = 7;
    graph_2->matrix[2][4] = 0;
    graph_2->matrix[2][5] = 4;
    graph_2->matrix[2][6] = 0;

    graph_2->matrix[3][0] = 0;
    graph_2->matrix[3][1] = 0;
    graph_2->matrix[3][2] = 7;
    graph_2->matrix[3][3] = 0;
    graph_2->matrix[3][4] = 23;
    graph_2->matrix[3][5] = 0;
    graph_2->matrix[3][6] = 0;

    graph_2->matrix[4][0] = 0;
    graph_2->matrix[4][1] = 0;
    graph_2->matrix[4][2] = 0;
    graph_2->matrix[4][3] = 23;
    graph_2->matrix[4][4] = 0;
    graph_2->matrix[4][5] = 8;
    graph_2->matrix[4][6] = 12;

    graph_2->matrix[5][0] = 0;
    graph_2->matrix[5][1] = 0;
    graph_2->matrix[5][2] = 4;
    graph_2->matrix[5][3] = 0;
    graph_2->matrix[5][4] = 8;
    graph_2->matrix[5][5] = 0;
    graph_2->matrix[5][6] = 0;

    graph_2->matrix[6][0] = 0;
    graph_2->matrix[6][1] = 0;
    graph_2->matrix[6][2] = 0;
    graph_2->matrix[6][3] = 0;
    graph_2->matrix[6][4] = 0;
    graph_2->matrix[6][5] = 12;
    graph_2->matrix[6][6] = 0;

    graph_2->matrix_size = 7;

    start = 2;
    end = 5;
    aim = how_many_paths(start - 1, end - 1, graph_2, aim);
    expected = 4;
    result = aim->number;
    ASSERT_EQUAL(expected, result);
    aim->number = 0;

    start = 3;
    end = 7;
    aim = how_many_paths(start - 1, end - 1, graph_2, aim);
    expected = 2;
    result = aim->number;
    ASSERT_EQUAL(expected, result);
    aim->number = 0;

    start = 1;
    end = 4;
    aim = how_many_paths(start - 1, end - 1, graph_2, aim);
    expected = 4;
    result = aim->number;
    ASSERT_EQUAL(expected, result);
    aim->number = 0;

    for (int i = 0; i < graph_2->matrix_size; i++) {
        free(graph_2->matrix[i]);
    }
    free(graph_2);

    for (int i = 0; i < aim->number; i++) {
        free(aim->all_paths[i]);
    }
    free(aim);
}

CTEST(input, read_matrix)
{
    int expected;
    int result;

    Matrix* graph_1 = (Matrix*)malloc(sizeof(Matrix));
    graph_1->matrix = prepare_two_dim_arr(graph_1->matrix);
    graph_1->matrix_size = 0;

    read_matrix("test1.txt", graph_1);

    int exp_1[5][5]
            = {{0, 5, 0, 4, 6},
               {5, 0, 3, 0, 0},
               {0, 3, 0, 6, 10},
               {4, 0, 6, 0, 5},
               {6, 0, 10, 5, 0}};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            expected = graph_1->matrix[i][j];
            result = exp_1[i][j];
            ASSERT_EQUAL(expected, result);
        }
    }
    for (int i = 0; i < graph_1->matrix_size; i++) {
        free(graph_1->matrix[i]);
    }
    free(graph_1);

    Matrix* graph_2 = (Matrix*)malloc(sizeof(Matrix));
    graph_2->matrix = prepare_two_dim_arr(graph_2->matrix);
    graph_2->matrix_size = 0;

    read_matrix("test2.txt", graph_1);

    int exp_2[7][7]
            = {{0, 19, 10, 0, 0, 0, 0},
               {19, 0, 15, 0, 0, 0, 0},
               {10, 15, 0, 7, 0, 4, 0},
               {0, 0, 7, 0, 23, 0, 0},
               {0, 0, 0, 23, 0, 8, 12},
               {0, 0, 4, 0, 8, 0, 0},
               {0, 0, 0, 0, 12, 0, 0}};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            expected = graph_2->matrix[i][j];
            result = exp_2[i][j];
            ASSERT_EQUAL(expected, result);
        }
    }
    for (int i = 0; i < graph_2->matrix_size; i++) {
        free(graph_2->matrix[i]);
    }
    free(graph_2);
}

CTEST(long_quest, quest)
{
    Matrix* quest_1 = (Matrix*)malloc(sizeof(Matrix));
    quest_1->matrix = prepare_two_dim_arr(quest_1->matrix);

    quest_1->matrix[0][0] = 0;
    quest_1->matrix[0][1] = 5;
    quest_1->matrix[0][2] = 0;
    quest_1->matrix[0][3] = 4;
    quest_1->matrix[0][4] = 6;

    quest_1->matrix[1][0] = 5;
    quest_1->matrix[1][1] = 0;
    quest_1->matrix[1][2] = 3;
    quest_1->matrix[1][3] = 0;
    quest_1->matrix[1][4] = 0;

    quest_1->matrix[2][0] = 0;
    quest_1->matrix[2][1] = 3;
    quest_1->matrix[2][2] = 0;
    quest_1->matrix[2][3] = 6;
    quest_1->matrix[2][4] = 10;

    quest_1->matrix[3][0] = 4;
    quest_1->matrix[3][1] = 0;
    quest_1->matrix[3][2] = 6;
    quest_1->matrix[3][3] = 0;
    quest_1->matrix[3][4] = 5;

    quest_1->matrix[4][0] = 6;
    quest_1->matrix[4][1] = 0;
    quest_1->matrix[4][2] = 10;
    quest_1->matrix[4][3] = 5;
    quest_1->matrix[4][4] = 0;

    quest_1->matrix_size = 5;

    Roads* target = (Roads*)malloc(sizeof(Roads));
    target->path = malloc(MAX_SIZE * sizeof(int));
    if (!target->path) {
        free(target->path);
    }
    target->path_dist = 0;

    int start = 1;
    int end = 5;
    target = which_longer(start - 1, end - 1, quest_1, target);
    int expected = 20;
    int result = target->path_dist;
    ASSERT_EQUAL(expected, result);
    target->path_dist = 0;

    start = 5;
    end = 3;
    target = which_longer(start - 1, end - 1, quest_1, target);
    expected = 17;
    result = target->path_dist;
    ASSERT_EQUAL(expected, result);
    target->path_dist = 0;

    start = 1;
    end = 2;
    target = which_longer(start - 1, end - 1, quest_1, target);
    expected = 22;
    result = target->path_dist;
    ASSERT_EQUAL(expected, result);
    target->path_dist = 0;

    for (int i = 0; i < quest_1->matrix_size; i++) {
        free(quest_1->matrix[i]);
    }
    free(quest_1);

    Matrix* quest_2 = (Matrix*)malloc(sizeof(Matrix));
    quest_2->matrix = prepare_two_dim_arr(quest_2->matrix);

    quest_2->matrix[0][0] = 0;
    quest_2->matrix[0][1] = 19;
    quest_2->matrix[0][2] = 10;
    quest_2->matrix[0][3] = 0;
    quest_2->matrix[0][4] = 0;
    quest_2->matrix[0][5] = 0;
    quest_2->matrix[0][6] = 0;

    quest_2->matrix[1][0] = 19;
    quest_2->matrix[1][1] = 0;
    quest_2->matrix[1][2] = 15;
    quest_2->matrix[1][3] = 0;
    quest_2->matrix[1][4] = 0;
    quest_2->matrix[1][5] = 0;
    quest_2->matrix[1][6] = 0;

    quest_2->matrix[2][0] = 10;
    quest_2->matrix[2][1] = 15;
    quest_2->matrix[2][2] = 0;
    quest_2->matrix[2][3] = 7;
    quest_2->matrix[2][4] = 0;
    quest_2->matrix[2][5] = 4;
    quest_2->matrix[2][6] = 0;

    quest_2->matrix[3][0] = 0;
    quest_2->matrix[3][1] = 0;
    quest_2->matrix[3][2] = 7;
    quest_2->matrix[3][3] = 0;
    quest_2->matrix[3][4] = 23;
    quest_2->matrix[3][5] = 0;
    quest_2->matrix[3][6] = 0;

    quest_2->matrix[4][0] = 0;
    quest_2->matrix[4][1] = 0;
    quest_2->matrix[4][2] = 0;
    quest_2->matrix[4][3] = 23;
    quest_2->matrix[4][4] = 0;
    quest_2->matrix[4][5] = 8;
    quest_2->matrix[4][6] = 12;

    quest_2->matrix[5][0] = 0;
    quest_2->matrix[5][1] = 0;
    quest_2->matrix[5][2] = 4;
    quest_2->matrix[5][3] = 0;
    quest_2->matrix[5][4] = 8;
    quest_2->matrix[5][5] = 0;
    quest_2->matrix[5][6] = 0;

    quest_2->matrix[6][0] = 0;
    quest_2->matrix[6][1] = 0;
    quest_2->matrix[6][2] = 0;
    quest_2->matrix[6][3] = 0;
    quest_2->matrix[6][4] = 0;
    quest_2->matrix[6][5] = 12;
    quest_2->matrix[6][6] = 0;

    quest_2->matrix_size = 7;

    start = 1;
    end = 4;
    target = which_longer(start - 1, end - 1, quest_2, target);
    expected = 69;
    result = target->path_dist;
    ASSERT_EQUAL(expected, result);
    target->path_dist = 0;

    start = 4;
    end = 7;
    target = which_longer(start - 1, end - 1, quest_2, target);
    expected = 35;
    result = target->path_dist;
    ASSERT_EQUAL(expected, result);
    target->path_dist = 0;

    start = 6;
    end = 3;
    target = which_longer(start - 1, end - 1, quest_2, target);
    expected = 38;
    result = target->path_dist;
    ASSERT_EQUAL(expected, result);
    target->path_dist = 0;

    for (int i = 0; i < quest_2->matrix_size; i++) {
        free(quest_2->matrix[i]);
    }
    free(quest_2);

    for (int i = 0; i < target->path_dist; i++) {
        free(target->path);
    }
    free(target);
}

CTEST(krput, shortest)
{
    Matrix* graph_1 = (Matrix*)malloc(sizeof(Matrix));
    graph_1->matrix = prepare_two_dim_arr(graph_1->matrix);

    graph_1->matrix[0][0] = 0;
    graph_1->matrix[0][1] = 5;
    graph_1->matrix[0][2] = 0;
    graph_1->matrix[0][3] = 4;
    graph_1->matrix[0][4] = 6;

    graph_1->matrix[1][0] = 5;
    graph_1->matrix[1][1] = 0;
    graph_1->matrix[1][2] = 3;
    graph_1->matrix[1][3] = 0;
    graph_1->matrix[1][4] = 0;

    graph_1->matrix[2][0] = 0;
    graph_1->matrix[2][1] = 3;
    graph_1->matrix[2][2] = 0;
    graph_1->matrix[2][3] = 6;
    graph_1->matrix[2][4] = 10;

    graph_1->matrix[3][0] = 4;
    graph_1->matrix[3][1] = 0;
    graph_1->matrix[3][2] = 6;
    graph_1->matrix[3][3] = 0;
    graph_1->matrix[3][4] = 5;

    graph_1->matrix[4][0] = 6;
    graph_1->matrix[4][1] = 0;
    graph_1->matrix[4][2] = 10;
    graph_1->matrix[4][3] = 5;
    graph_1->matrix[4][4] = 0;

    graph_1->matrix_size = 5;

    Clover* kr = (Clover*)malloc(sizeof(Clover));
    kr->ver = malloc(MAX_SIZE * sizeof(int));
    if (!kr->ver) {
        free(kr->ver);
    }
    kr->k = 1;
    kr->ves = 0;

    int start = 1;
    int end = 5;
    kr = krPut(graph_1, start, end, kr);
    int expected = 6;
    int result = kr->ves;
    ASSERT_EQUAL(expected, result);
    kr->ves = 0;

    start = 4;
    end = 2;
    kr = krPut(graph_1, start, end, kr);
    expected = 9;
    result = kr->ves;
    ASSERT_EQUAL(expected, result);
    kr->ves = 0;

    start = 2;
    end = 3;
    kr = krPut(graph_1, start, end, kr);
    expected = 3;
    result = kr->ves;
    ASSERT_EQUAL(expected, result);
    kr->ves = 0;

    for (int i = 0; i < graph_1->matrix_size; i++) {
        free(graph_1->matrix[i]);
    }
    free(graph_1);

    Matrix* graph_2 = (Matrix*)malloc(sizeof(Matrix));
    graph_2->matrix = prepare_two_dim_arr(graph_2->matrix);

    graph_2->matrix[0][0] = 0;
    graph_2->matrix[0][1] = 19;
    graph_2->matrix[0][2] = 10;
    graph_2->matrix[0][3] = 0;
    graph_2->matrix[0][4] = 0;
    graph_2->matrix[0][5] = 0;
    graph_2->matrix[0][6] = 0;

    graph_2->matrix[1][0] = 19;
    graph_2->matrix[1][1] = 0;
    graph_2->matrix[1][2] = 15;
    graph_2->matrix[1][3] = 0;
    graph_2->matrix[1][4] = 0;
    graph_2->matrix[1][5] = 0;
    graph_2->matrix[1][6] = 0;

    graph_2->matrix[2][0] = 10;
    graph_2->matrix[2][1] = 15;
    graph_2->matrix[2][2] = 0;
    graph_2->matrix[2][3] = 7;
    graph_2->matrix[2][4] = 0;
    graph_2->matrix[2][5] = 4;
    graph_2->matrix[2][6] = 0;

    graph_2->matrix[3][0] = 0;
    graph_2->matrix[3][1] = 0;
    graph_2->matrix[3][2] = 7;
    graph_2->matrix[3][3] = 0;
    graph_2->matrix[3][4] = 23;
    graph_2->matrix[3][5] = 0;
    graph_2->matrix[3][6] = 0;

    graph_2->matrix[4][0] = 0;
    graph_2->matrix[4][1] = 0;
    graph_2->matrix[4][2] = 0;
    graph_2->matrix[4][3] = 23;
    graph_2->matrix[4][4] = 0;
    graph_2->matrix[4][5] = 8;
    graph_2->matrix[4][6] = 12;

    graph_2->matrix[5][0] = 0;
    graph_2->matrix[5][1] = 0;
    graph_2->matrix[5][2] = 4;
    graph_2->matrix[5][3] = 0;
    graph_2->matrix[5][4] = 8;
    graph_2->matrix[5][5] = 0;
    graph_2->matrix[5][6] = 0;

    graph_2->matrix[6][0] = 0;
    graph_2->matrix[6][1] = 0;
    graph_2->matrix[6][2] = 0;
    graph_2->matrix[6][3] = 0;
    graph_2->matrix[6][4] = 0;
    graph_2->matrix[6][5] = 12;
    graph_2->matrix[6][6] = 0;

    graph_2->matrix_size = 7;

    start = 2;
    end = 5;
    kr = krPut(graph_2, start, end, kr);
    expected = 27;
    result = kr->ves;
    ASSERT_EQUAL(expected, result);
    kr->ves = 0;

    start = 3;
    end = 7;
    kr = krPut(graph_2, start, end, kr);
    expected = 24;
    result = kr->ves;
    ASSERT_EQUAL(expected, result);
    kr->ves = 0;

    start = 1;
    end = 4;
    kr = krPut(graph_2, start, end, kr);
    expected = 17;
    result = kr->ves;
    ASSERT_EQUAL(expected, result);
    kr->ves = 0;

    for (int i = 0; i < graph_2->matrix_size; i++) {
        free(graph_2->matrix[i]);
    }
    free(graph_2);

    free(kr->ver);
    free(kr);
}
