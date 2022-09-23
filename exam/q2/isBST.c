// isBST.c ... implementation of isBST function

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Tree.h"

/*
    You will submit only this one file.

    Implement the function "isBST" below. Read the exam paper for a
    detailed specification and description of your task.

    - DO NOT modify the code in any other files except for debugging
      purposes.
    - If you wish, you can add static variables and/or helper functions
      to this file.
    - DO NOT add a "main" function to this file.
*/
static bool doIsBST(Tree t, Node n);

int isBST(Tree t) {
    if (doIsBST(t, t->root)) {
        return 1;
    }
    return 0;
}

static bool doIsBST(Tree t, Node n) {
    if (n == NULL) {
        return true;
    }
    if (n->left == NULL && n->right == NULL) {
        return true;
    }
    if (n->left == NULL) {
        if (t->compare(n->rec, n->right->rec) < 0) {
            bool r = doIsBST(t, n->right);
            if (r) {
                return true;
            }
        } else {
            return false;
        }
    }
    if (n->right == NULL) {
        if (t->compare(n->left->rec, n->rec) < 0) {
            bool l = doIsBST(t, n->left);
            if (l) {
                return true;
            }
        } else {
            return false;
        }
    }
    if (t->compare(n->left->rec, n->rec) < 0 && t->compare(n->rec, n->right->rec) < 0) {
        bool l = doIsBST(t, n->left);
        bool r = doIsBST(t, n->right);
        if (l && r) {
            return true;
        }
    }
    return false;
}
