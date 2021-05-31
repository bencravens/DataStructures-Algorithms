#include <stdio.h>
#include <stdlib.h>

#define OCEAN_MAX 41981

struct ocean_datum {
    int x;
    int y;
    double conc;
};

void print_ocean_datum(struct ocean_datum *o){
    printf("%d %d %.4f\n", o->x, o->y, o->conc);
}

int read_ocean_datum(struct ocean_datum* o) {
    return 3 == scanf("%d %d %lg", &o->x, &o->y, &o->conc);
}

void insertion_sort(struct ocean_datum* o, int n){
    /*define variables for insertion sort...*/
    int i;
    int j;
    struct ocean_datum key;

    /*use insertion sort to sort the array*/
    for (i=1;i<n;i++){
        key = o[i];
        j = i - 1;
        while (j>=0 & (o[j].conc) > key.conc) {
            o[j+1] = o[j];
            j = j - 1;
        }
        o[j+1] = key;
    }

}

int main(void) {
    struct ocean_datum ocean_data[OCEAN_MAX];
    int num_items;
    int i;
    
    num_items = 0;
    while (num_items < OCEAN_MAX && read_ocean_datum(&ocean_data[num_items])) {
        num_items++;
    }
    
    /*sort the data here*/
    insertion_sort(ocean_data,num_items);
    
    for(i=0;i<num_items;i++){
        print_ocean_datum(&ocean_data[i]);
    }
    
    return EXIT_SUCCESS;
}
