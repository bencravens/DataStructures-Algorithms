#include <stdio.h>
#include <stdlib.h>

#define OCEAN_MAX 41981


struct ocean_datum {
    int x;
    int y;
    double conc;
};

void print_ocean_datum(struct ocean_datum *o) {
    printf("%d %d %.4f\n", (*o).x, o->y, o->conc);
}

int read_ocean_datum(struct ocean_datum *o) {
    return 3 == scanf("%d %d %lg", &o->x, &o->y, &o->conc);
}    

void insertion_sort(struct ocean_datum a[], int n){
    
    /*define variables for insertion sort...*/
    int i;
    struct ocean_datum key;
    int j;

    /*use insertion sort to sort the array*/
    for (i=1;i<n;i++){
        key=a[i];
        j = i - 1;
        while (j>=0 & a[j].conc > key.conc) {
            a[j+1] = a[j];
            j = j - 1;
        }
        a[j+1] = key;
    }
}



int main(void) {
    struct ocean_datum ocean_data[OCEAN_MAX];
    int num_items;
    int i;

    /* read in data */
    num_items = 0;
    while (num_items < OCEAN_MAX && read_ocean_datum(&ocean_data[num_items])) {
        num_items++;
    }
    
    insertion_sort(ocean_data,num_items);

    /*print out the array of structs */
    for (i=0; i < num_items; i++) {
        print_ocean_datum(&ocean_data[i]);
    }

    return EXIT_SUCCESS;
}
