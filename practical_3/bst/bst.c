#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "mylib.h"

struct bst_node {
    char* key;
    bst left;
    bst right;
};

void print_key(char* str) {
    printf("%s\n", str);
}

bst bst_new() {
    return NULL;
}

void bst_preorder(bst b, void f(char* str)) {
    if (b==NULL) {
        return;
    } else {
        f(b->key);
        bst_preorder(b->left,f);
        bst_preorder(b->right,f);
    }
}

void bst_inorder(bst b, void f(char* str)) {
    if (b==NULL) {
        return;
    } else {
        bst_inorder(b->left,f);
        f(b->key);
        bst_inorder(b->right,f);
    }
}

bst bst_insert(bst b, char* str) {
    if (b==NULL) {
        b = emalloc(sizeof *b);
        b->key = emalloc((strlen(str) + 1) * sizeof str[0]);
        strcpy(b->key,str);
        b->left = NULL;
        b->right = NULL;
    } else if (strcmp(b->key,str) == 0) {
        /*duplicate case...*/
        ;
    } else if (strcmp(str,b->key) < 0) {
        /*str < b->key, go left*/
        b->left = bst_insert(b->left, str);
    } else if (strcmp(str,b->key) > 0) {
        /*str > b->key, go right.*/
        b->right = bst_insert(b->right, str);
    }
    /*insertion done, return b*/
    return b;
}

int bst_search(bst b, char* str) {
    if (b==NULL) {
        return 0;
    } else if (strcmp(str,b->key)==0) {
        return 1;
    } else if (strcmp(str, b->key) < 0) {
        /*our str is smaller than key, search left subtree*/
        return bst_search(b->left,str);
    } else if (strcmp(str, b->key) > 0) {
        return bst_search(b->right,str);
    }
    /*shouldn't reach this far... something has 
    * gone wrong */
    fprintf(stderr, "search failed.\n");
    exit(EXIT_FAILURE);
}

bst bst_free(bst b) {
    if (b==NULL) {
        return b;
    } else {
        b->left = bst_free(b->left);
        b->right = bst_free(b->right);
        free(b->key);
        free(b);
        b = NULL;
        return b;
    }
}   
