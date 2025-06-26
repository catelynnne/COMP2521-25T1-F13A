
#ifndef BST_H
#define BST_H

struct node {
    int value;
    struct node *left;
    struct node *right;
};

/**
 * Frees all memory allocated to the given tree.
 */
void bstFree(struct node *t);

/**
 * Returns the number of odd values in the given tree.
 */
int bstCountOdds(struct node *t);

/**
 * Returns the number of internal nodes in the tree. An internal node is
 * a node that has one or more children, i.e., a node that is not a
 * leaf.
 */
int bstCountInternal(struct node *t);

/**
 * Returns the level of the node containing the given key in the tree if
 * it exists, or -1 otherwise.
 */
int bstNodeLevel(struct node *t, int key);

/**
 * Returns the number of values in the tree that are greater than the
 * given value.
 */
int bstCountGreater(struct node *t, int key);

#endif
