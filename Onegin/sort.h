#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR_BEGIN 100
#define STR_ADD 50

#define SYM_BEGIN 50
#define SYM_ADD 50

enum mem_status {   //Состояние выделенной памяти:
    EMPTY = 0,      //Есть место, куда положить;
    OVERFLOW = 1,   //Переполнение;
    NO_LINE = 2,    //Нет строки, куда писать.
    BEGIN = 3,       //нет ни памяти на строки, ни на символы
};

char** count_poem();
void sort_poem(char** poem);
void print_poem(char** poem, int max_str);
void generate_file_with_poem(char** poem);
void free_poem(char** poem, int max_str);
