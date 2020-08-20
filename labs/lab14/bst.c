#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

struct bst_node {
    char* key;
    bst left;
    bst right;
};

void print_key(char* s) {
    printf("%s\n", s);
}

void* emalloc(size_t n) {
    void* result = malloc(n);
    if (result == NULL) {
        fprintf(stderr, "memory allocation failed\n");
    }
    return result;
}

bst bst_new() {
    return NULL;
}

void bst_inorder(bst b, void f(char* str)) {
    if (b==NULL) {
        return;
    }
    bst_inorder(b->left,f);
    f(b->key);
    bst_inorder(b->right,f);
}

void bst_preorder(bst b, void f(char* str)) {
    if (b==NULL) {
        return;
    }
    f(b->key);
    bst_preorder(b->left,f);
    bst_preorder(b->right,f);
}

bst bst_insert(bst b, char* str) {
    if (b==NULL) {
        b = emalloc(sizeof *b);
        b->key = emalloc((strlen(str)+1) * sizeof str[0]);
        b->key=str;
    } else if (strcmp(b->key,str)==0) {
        ;
    } else if (strcmp(str,b->key)<0) {
        b->left = bst_insert(b->left, str);
    } else {
        b->right = bst_insert(b->right,str);
    }
    return b;
}

int bst_search(bst b, char* str) {
    if (b==NULL) {
        /*empty tree, so string can't be found*/
        return 0;
    } else if (strcmp(b->key,str)==0) {
        /*found the string, return true*/
        return 1;
    } else if (strcmp(str,b->key) < 0) {
        /*node too big, search left subtree*/
        return bst_search(b->left,str);
    } else {
        /*node too small, search right subtree*/
        return bst_search(b->right,str);
    }
}
