#include <stdio.h>
#include <stdlib.h>
#include "htable.h"

int main(void) {
    htable my_htable = htable_new(9);
    htable_insert(my_htable,"test");
    htable_insert(my_htable,"test");
    htable_insert(my_htable,"hellomate aaa aaaa aaaaa");
    htable_insert(my_htable,"test1");
    htable_insert(my_htable,"test2");
    htable_insert(my_htable,"test3");
    htable_insert(my_htable,"ben cravens is cool");
    htable_print(my_htable,stdout);
    htable_free(my_htable);
    return EXIT_SUCCESS;
}
