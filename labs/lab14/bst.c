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

/*return a bst node pointer*/
struct bst_node* talloc(void) {
    return (struct bst_node * ) emalloc(sizeof(struct bst_node));
}

bst bst_new() {
    return NULL;
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

void bst_preorder(bst b, void f(char* str)) {
    if (b==NULL) {
        return;
    } else {
        f(b->key);
        bst_preorder(b->left,f);
        bst_preorder(b->right,f);
    }
}

bst bst_insert(bst b, char* str) {
    if (b==NULL) {
        b = talloc();
        b->key = emalloc((strlen(str)+1) * sizeof str[0]);
        strcpy(b->key, str);
        b->left = NULL;
        b->right = NULL;
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

bst bst_delete(bst b, char* str) {
    if (b==NULL || bst_search(b,str)==0) {
        /*key does not exist in tree, so just return tree*/
        printf("key does not exist in tree, just returning tree.\n");
        return b; 
    } else if (strcmp(str,b->key) < 0) {
        printf("node too big, searching left subtree\n");
        b->left = bst_delete(b->left,str);
    } else if (strcmp(str,b->key) > 0) {
        /*node too small, search right subtree*/
        printf("node too small, searching right subtree\n");
        b->right = bst_delete(b->right,str);
    } else {
        /*found the string at this node*/
        printf("found string\n");
        /* if this node is a leaf*/
        if (b->left == NULL && b->right == NULL) {
            free(b->key);
            free(b);
            b = NULL;
        /* actually, the node has only one child */
        } else if ((b->left == NULL) ^ (b->right == NULL)) {
            /*if it is the left node that is null*/
            if (b->left == NULL) {
                char* str = b->right->key;
                b->key = realloc(b->key,((strlen(str)+1)*sizeof str[0]));
                strcpy(b->key,str);
                free(b->right->key);
                free(b->right);
                b->right = NULL;
            } else {
                char* str = b->left->key;
                b->key = realloc(b->key,((strlen(str)+1)*sizeof str[0]));
                strcpy(b->key,str);
                free(b->left->key);
                free(b->left);
                b->left = NULL;
            }
        /* oops, it is actually the case that the node has two children... */
        } else {
            /*need to find leftmost child of right subtree*/
            bst temp = b->right;
            char* str;
            while(temp->left != NULL) {
                temp = temp->left;
            }
            printf("leftmost key is %s\n",temp->key);
            printf("key to be swapped is %s\n",b->key);
            /*now swap the leftmost key with successor, and delete leftmost*/
            str = temp->key;
            temp->key = b->key;
            b->key = str;
            bst_delete(b->right,temp->key);
        }
    }
    return b;
}

bst bst_free(bst b) {
    if (b==NULL) {
        return b;
    }
    if (b->left != NULL) {
        b->left = bst_free(b->left);
    }
    if (b->right != NULL) {
        b->right = bst_free(b->right);
    }
    free(b->key);
    free(b);
    return b;
}
