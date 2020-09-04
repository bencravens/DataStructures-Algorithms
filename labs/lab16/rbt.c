#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rbt.h"

#define IS_BLACK(x) ((NULL == (x)) || (BLACK == (x)->colour))
#define IS_RED(x) ((NULL != (x)) && (RED == (x)->colour)) 

typedef enum { RED, BLACK } rbt_colour;

struct rbt_node {
    char* key;
    rbt_colour colour;
    rbt left;
    rbt right;
};

void print_key(char* s) {
    printf("%s\n", s);
}

void print_colour(rbt b) {
    if (b->colour==RED) {
        printf("red: %s\n",b->key);
    } else {
        printf("black: %s\n",b->key);
    }
}

void* emalloc(size_t n) {
    void* result = malloc(n);
    if (result == NULL) {
        fprintf(stderr, "memory allocation failed\n");
    }
    return result;
}

/*return a rbt node pointer*/
struct rbt_node* talloc(void) {
    return (struct rbt_node * ) emalloc(sizeof(struct rbt_node));
}

rbt rbt_new() {
    return NULL;
}

void rbt_inorder(rbt b) {
    if (b==NULL) {
        return;
    } else {
        rbt_inorder(b->left);
        if (b->colour==BLACK) {
            printf("black: %s\n",b->key);
        } else {
            printf("red: %s\n",b->key);
        } 
        rbt_inorder(b->right);
    }
}

void rbt_preorder(rbt b) {
    if (b==NULL) {
        return;
    } else {
        if (b->colour==BLACK) {
            printf("black: %s\n",b->key);
        } else {
            printf("red: %s\n",b->key);
        }
        rbt_preorder(b->left);
        rbt_preorder(b->right);
    }
}

rbt left_rotate(rbt b) {
    /*keep track of original*/
    rbt temp = b;
    /*change the root to point to its right child*/
    b = b->right;
    /*make the right child of temp (original root) point to
    * left child of the new root. */
    temp->right = b->left;
    /*now make the left child of the new root point to temp (old root)*/
    b->left = temp;
    return b;
}

rbt right_rotate(rbt b) {
    /*keep track of original*/
    rbt temp = b;
    /*change the root to point to its left child*/
    b = b->left;
    /*make the left child of temp (original root) point to
    * right child of the new root. */
    temp->left = b->right;
    /*now make the right child of the new root point to temp (old root)*/
    b->right = temp;
    return b;
}


static rbt rbt_fix(rbt R) {
    if(IS_RED(R->left) && IS_RED(R->left->left)) {
        if (IS_RED(R->right)) {
            R->colour = RED;
            R->left->colour = BLACK;
            R->right->colour = BLACK;
        } else {
            R = right_rotate(R);
            R->colour = BLACK;
            R->right->colour = RED;
        } 
    } else if (IS_RED(R->left) && IS_RED(R->left->right)) {
        if (IS_RED(R->right)) {
            R->colour = RED;
            R->left->colour = BLACK;
            R->right->colour = BLACK;
        } else {
            R->left = left_rotate(R->left);
            R = right_rotate(R);
            R->colour = BLACK;
            R->right->colour = RED;
        }
    } else if (IS_RED(R->right) && IS_RED(R->right->left)) {
        if (IS_RED(R->left)) {
            R->colour = RED;
            R->left->colour = BLACK;
            R->right->colour = BLACK; 
        } else {
            R->right = right_rotate(R->right);
            R = left_rotate(R);
            R->colour = BLACK;
            R->left->colour = RED;
        } 
    } else if (IS_RED(R->right) && IS_RED(R->right->right)) {
        if (IS_RED(R->left)) {
            R->colour = RED;
            R->left->colour = BLACK;
            R->right->colour = BLACK;
        } else {
            R = left_rotate(R);
            R->colour = BLACK;
            R->left->colour = RED;
        }
    } 
    return R;
}

rbt rbt_insert(rbt b, char* str) {
    if (b==NULL) {
        b = emalloc(sizeof *b);
        b->key = emalloc((strlen(str)+1) * sizeof str[0]);
        strcpy(b->key, str);
        b->left = NULL;
        b->right = NULL;
        b->colour = RED; /*node is red by default*/
    } else if (strcmp(b->key,str)==0) {
        ;
    } else if (strcmp(str,b->key)<0) {
        b->left = rbt_insert(b->left, str);
    } else {
        b->right = rbt_insert(b->right,str);
    }
    b = rbt_fix(b);
    return b;
}

int rbt_search(rbt b, char* str) {
    if (b==NULL) {
        /*empty tree, so string can't be found*/
        return 0;
    } else if (strcmp(b->key,str)==0) {
        /*found the string, return true*/
        return 1;
    } else if (strcmp(str,b->key) < 0) {
        /*node too big, search left subtree*/
        return rbt_search(b->left,str);
    } else {
        /*node too small, search right subtree*/
        return rbt_search(b->right,str);
    }
}

rbt rbt_delete(rbt b, char* str) {
    if (b==NULL || rbt_search(b,str)==0) {
        /*key does not exist in tree, so just return tree*/
        printf("key does not exist in tree, just returning tree.\n");
        return b; 
    } else if (strcmp(str,b->key) < 0) {
        printf("node too big, searching left subtree\n");
        b->left = rbt_delete(b->left,str);
    } else if (strcmp(str,b->key) > 0) {
        /*node too small, search right subtree*/
        printf("node too small, searching right subtree\n");
        b->right = rbt_delete(b->right,str);
    } else if (strcmp(str,b->key) == 0) {
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
            rbt temp = b->right;
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
            b->right = rbt_delete(b->right,temp->key);
        }
    }
    return b;
}

rbt rbt_free(rbt b) {
    if (b==NULL) {
        return b;
    }
    if (b->left != NULL) {
        b->left = rbt_free(b->left);
    }
    if (b->right != NULL) {
        b->right = rbt_free(b->right);
    }
    free(b->key);
    free(b);
    return b;
}


