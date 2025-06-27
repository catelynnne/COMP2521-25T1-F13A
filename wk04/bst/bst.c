
#include <stdlib.h>

struct node {
    int value;
    struct node *left;
    struct node *right;
};

/**
 * Frees all memory allocated to the given tree.
 */
void bstFree(struct node *t) {
    if (t != NULL) {
        bstFree(t->left);
        bstFree(t->right);
        free(t);
    }
}

/**
 * Counts the total number of nodes in a given tree.
 */
int bstNumNodes(struct node *t) {
    if (t == NULL) {
        return 0;
    }

    return bstNumNodes(t->left) + bstNumNodes(t->right) + 1;
} 

/**
 * Returns the number of odd values in the given tree.
 */
int bstCountOdds(struct node *t) {
    if (t == NULL) {
        return 0;
    }

    if (t->value % 2 == 1) {
        //
    }
}

/**
 * Returns the number of internal nodes in the tree. An internal node is
 * a node that has one or more children, i.e., a node that is not a
 * leaf.
 */
int bstCountInternal(struct node *t) {
    return 0;
}

/**
 * Returns the height of the tree. Height = maximum number of nodes in a path on the tree. Returns -1 for an empty tree
 */
int bstHeight(struct node *t) {
    if (t == NULL) {
        return -1;
    } else {
        // 10
        int lh = bstHeight(t->left); // 3
        int rh = bstHeight(t->right); // 1

        if (lh > rh) {
            return lh + 1;
        } else {
            return rh + 1;
        }
    }

}

/**
 * Returns the level of the node containing the given key in the tree if
 * it exists, or -1 otherwise.
 */
int bstNodeLevel(struct node *t, int key) {
    return 0;
}

/**
 * Returns the number of values in the tree that are greater than the
 * given value.
 */
int bstCountGreater(struct node *t, int key) {
    return 0;
}




