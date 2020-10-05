#include "sort.h"

char** count_poem(int* max_string) {
    char** poem = NULL; //указатель на массив указателей

    char c = 0; //входной символ
    int mem_status = BEGIN; //состояние выделенной памяти

    int max_sym = 0; //максимальное количество символов
    int max_str = 0; //максимальное количество строк
    int num_sym = 0; //счетчик количества символов, помещенных в память
    int num_str = 0; //номер строки, которая сейчас заполняется



    while ((c = getchar()) != EOF) {
        printf("Saccess!");
        if (mem_status == BEGIN) {
            printf("Saccess!");
            poem = (char**) calloc(STR_BEGIN, sizeof(char*));
            max_str += STR_BEGIN;
            *(poem + num_str) = (char*) calloc(SYM_BEGIN, sizeof(char));
            max_sym += SYM_BEGIN;
            mem_status = EMPTY;
        }
        /*if (mem_status == NO_LINE) {
            poem = realloc(poem, (max_str + STR_ADD) * sizeof(char*));
            max_str += STR_ADD;
            *(poem + num_str) = calloc(SYM_BEGIN, sizeof(char));
            max_sym += SYM_BEGIN;
            mem_status = EMPTY;
        }
        if (mem_status == OVERFLOW) {
            *(poem + num_str) = realloc(poem, (num_sym + SYM_ADD) * sizeof(char));
            max_sym += SYM_ADD;
            mem_status == EMPTY;
        } */
        if (mem_status == EMPTY) {
            *(*(poem + num_str) + num_sym) = c;
            num_sym++;
            if (c == '\n'){
                ++num_str;
                num_sym = 0;
            }
            if (num_sym >= max_sym) {
                mem_status = OVERFLOW;
            }
            if (num_str >= max_str) {
                mem_status = NO_LINE;
            }
        }
    }
 /*
    if (c == EOF) {
        switch (mem_status) {
            case EMPTY:
                //положи \0 и закончи строку
                *(*(poem + num_str) + num_sym) = '\n';
                break;
            case OVERFLOW:
                //добавить памяти на один символ и положить туда конец строки
                *(poem + num_str) = realloc(poem, (num_sym + 1) * sizeof(char));
                *(*(poem + num_str) + num_sym) = '\n';
                break;
            case NO_LINE:
                poem = realloc(poem, (max_str + 1) * sizeof(char*));
                max_str++;
                *(poem + num_str) = calloc(1, sizeof(char));
                *(*(poem + num_str) + num_sym) = '\n';
                mem_status = OVERFLOW;
                break;
            default:
                break;
         }
     }
     *max_string = num_str; */
     return poem;
}

void print_poem(char** poem, int max_str) {
    /*int num_str = 0;
    int num_sym = 0;
    printf("\n ------------Attention! a poem!---------------\n");
    for (num_str; num_str <= max_str; num_str++) {
        while(*(*(poem + num_str) + num_sym) != '\n') {
            printf("%c", *(*(poem + num_str) + num_sym));
        }
        printf("\n");
    }
    printf("\n ------------------The end!-------------------\n"); */
    return;
}

void free_poem(char** poem, int max_str) {
    /*for (int num_str = 0; num_str <= max_str; num_str++) {
        free(*(poem + num_str));
    }
    free(poem);*/
    return;
}

void sort_poem(char** poem){}
void generate_file_with_poem(char** poem){}
