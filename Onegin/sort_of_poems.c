//В этом файле содержится функция main, выполняющая нормальную работу программы
#include "sort.h"


int main() {
    char** poem = NULL;
    int num_str = 0;
    printf("Saccess!");
    poem = count_poem(&num_str);
    print_poem(poem, num_str);
//    free_poem(poem, num_str);
    return 0;
}
