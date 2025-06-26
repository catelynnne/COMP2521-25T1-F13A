
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

#define LF(value)              newBstLink(value, NULL,  NULL) // leaf
#define LC(value, left)        newBstLink(value, left,  NULL) // left child only
#define RC(value, right)       newBstLink(value, NULL, right) // right child only
#define LR(value, left, right) newBstLink(value, left, right) // two children

static void initTrees(void);
static void freeTrees(void);

static void testBstCountOdds(void);
static void testBstCountInternal(void);
static void testBstNodeLevel(void);
static void testBstCountGreater(void);

static struct node *newBstLink(int value, struct node *left, struct node *right);

static struct node *t01, *t02, *t03, *t04, *t05, *t06, *t07, *t08, *t09, *t10, *t11;


int main(void) {
    initTrees();

    testBstCountOdds();
    testBstCountInternal();
    testBstNodeLevel();
    testBstCountGreater();

    freeTrees();
    printf("All tests passed!\n");
}

static void initTrees(void) {
    /*
     */
    t01 =
        NULL;
    
    /*
        3
     */
    t02 =
        LF(3);
    
    /*
          6
         /
        3
     */
    t03 =
        LC(6,
            LF(3)
        );
    
    /*
        3
         \
          8
     */
    t04 =
        RC(3,
            LF(8)
        );
    
    /*
          6
         / \
        3   8
     */
    t05 =
        LR(6,
            LF(3),
            LF(8)
        );
    
    /*
             5
            / \
           /   \
          3     7
         / \   / \
        2   4 6   8
     */
    t06 =
        LR(5,
            LR(3,
                LF(2),
                LF(4)
            ),
            LR(7,
                LF(6),
                LF(8)
            )
        );
    
    /*
            8
           /
          2
         / \
        1   7
     */
    t07 =
        LC(8,
            LR(2,
                LF(1),
                LF(7)
            )
        );
    
    /*
          2
         / \
        0   6
           / \
          4   8
     */
    t08 =
        LR(2,
            LF(0),
            LR(6,
                LF(4),
                LF(8)
            )
        );
    
    /*
        1
         \
          8
         /
        3
         \
          6
     */
    t09 =
        RC(1,
            LC(8,
                RC(3,
                    LF(6)
                )
            )
        );
    
    /*
              5
             / \
            4   6
           /     \
          3       7
         /         \
        2           8
     */
    t10 =
        LR(5,
            LC(4,
                LC(3,
                    LF(2)
                )
            ),
            RC(6,
                RC(7,
                    LF(8)
                )
            )
        );
    
    /*
        1
         \
          3
         / \
        2   5
           / \
          4   7
             / \
            6   9
               /
              8
     */
    t11 =
        RC(1,
            LR(3,
                LF(2),
                LR(5,
                    LF(4),
                    LR(7,
                        LF(6),
                        LC(9,
                            LF(8)
                        )
                    )
                )
            )
        );
}

static void freeTrees(void) {
    bstFree(t01);
    bstFree(t02);
    bstFree(t03);
    bstFree(t04);
    bstFree(t05);
    bstFree(t06);
    bstFree(t07);
    bstFree(t08);
    bstFree(t09);
    bstFree(t10);
    bstFree(t11);
}

// ----------------------------------------

static void testBstCountOdds(void) {
    printf("Testing bstCountOdds...\n");

    assert(bstCountOdds(t01) == 0);
    assert(bstCountOdds(t02) == 1);
    assert(bstCountOdds(t03) == 1);
    assert(bstCountOdds(t04) == 1);
    assert(bstCountOdds(t05) == 1);
    assert(bstCountOdds(t06) == 3);
    assert(bstCountOdds(t07) == 2);
    assert(bstCountOdds(t08) == 0);
    assert(bstCountOdds(t09) == 2);
    assert(bstCountOdds(t10) == 3);
    assert(bstCountOdds(t11) == 5);

    printf("bstCountOdds tests passed!\n");
}

static void testBstCountInternal(void) {
    printf("Testing bstCountInternal...\n");

    assert(bstCountInternal(t01) == 0);
    assert(bstCountInternal(t02) == 0);
    assert(bstCountInternal(t03) == 1);
    assert(bstCountInternal(t04) == 1);
    assert(bstCountInternal(t05) == 1);
    assert(bstCountInternal(t06) == 3);
    assert(bstCountInternal(t07) == 2);
    assert(bstCountInternal(t08) == 2);
    assert(bstCountInternal(t09) == 3);
    assert(bstCountInternal(t10) == 5);
    assert(bstCountInternal(t11) == 5);

    printf("bstCountInternal tests passed!\n");
}

static void testBstNodeLevel(void) {
    printf("Testing bstNodeLevel...\n");

    assert(bstNodeLevel(t01, 1) == -1);

    assert(bstNodeLevel(t02, 3) ==  0);
    assert(bstNodeLevel(t02, 0) == -1);
    assert(bstNodeLevel(t02, 6) == -1);
    
    assert(bstNodeLevel(t03, 6) ==  0);
    assert(bstNodeLevel(t03, 3) ==  1);
    assert(bstNodeLevel(t03, 2) == -1);
    assert(bstNodeLevel(t03, 5) == -1);
    assert(bstNodeLevel(t03, 9) == -1);
    
    assert(bstNodeLevel(t04, 3) ==  0);
    assert(bstNodeLevel(t04, 8) ==  1);
    assert(bstNodeLevel(t04, 0) == -1);
    assert(bstNodeLevel(t04, 7) == -1);
    assert(bstNodeLevel(t04, 4) == -1);
    
    assert(bstNodeLevel(t05, 6) ==  0);
    assert(bstNodeLevel(t05, 3) ==  1);
    assert(bstNodeLevel(t05, 8) ==  1);
    assert(bstNodeLevel(t05, 1) == -1);
    assert(bstNodeLevel(t05, 4) == -1);
    assert(bstNodeLevel(t05, 7) == -1);
    assert(bstNodeLevel(t05, 9) == -1);
    
    assert(bstNodeLevel(t06, 5) ==  0);
    assert(bstNodeLevel(t06, 3) ==  1);
    assert(bstNodeLevel(t06, 7) ==  1);
    assert(bstNodeLevel(t06, 2) ==  2);
    assert(bstNodeLevel(t06, 4) ==  2);
    assert(bstNodeLevel(t06, 6) ==  2);
    assert(bstNodeLevel(t06, 8) ==  2);
    assert(bstNodeLevel(t06, 0) == -1);
    assert(bstNodeLevel(t06, 9) == -1);
    
    assert(bstNodeLevel(t07, 8) ==  0);
    assert(bstNodeLevel(t07, 2) ==  1);
    assert(bstNodeLevel(t07, 1) ==  2);
    assert(bstNodeLevel(t07, 7) ==  2);
    assert(bstNodeLevel(t07, 0) == -1);
    assert(bstNodeLevel(t07, 5) == -1);
    assert(bstNodeLevel(t07, 9) == -1);

    assert(bstNodeLevel(t08, 2) ==  0);
    assert(bstNodeLevel(t08, 0) ==  1);
    assert(bstNodeLevel(t08, 6) ==  1);
    assert(bstNodeLevel(t08, 4) ==  2);
    assert(bstNodeLevel(t08, 8) ==  2);
    assert(bstNodeLevel(t08, 1) == -1);
    assert(bstNodeLevel(t08, 3) == -1);
    assert(bstNodeLevel(t08, 5) == -1);
    assert(bstNodeLevel(t08, 7) == -1);
    assert(bstNodeLevel(t08, 9) == -1);

    assert(bstNodeLevel(t09, 1) ==  0);
    assert(bstNodeLevel(t09, 8) ==  1);
    assert(bstNodeLevel(t09, 3) ==  2);
    assert(bstNodeLevel(t09, 6) ==  3);
    assert(bstNodeLevel(t09, 0) == -1);
    assert(bstNodeLevel(t09, 2) == -1);
    assert(bstNodeLevel(t09, 5) == -1);
    assert(bstNodeLevel(t09, 7) == -1);
    assert(bstNodeLevel(t09, 9) == -1);

    assert(bstNodeLevel(t10, 5) ==  0);
    assert(bstNodeLevel(t10, 4) ==  1);
    assert(bstNodeLevel(t10, 6) ==  1);
    assert(bstNodeLevel(t10, 3) ==  2);
    assert(bstNodeLevel(t10, 7) ==  2);
    assert(bstNodeLevel(t10, 2) ==  3);
    assert(bstNodeLevel(t10, 8) ==  3);
    assert(bstNodeLevel(t10, 1) == -1);
    assert(bstNodeLevel(t10, 9) == -1);

    assert(bstNodeLevel(t11,  1) ==  0);
    assert(bstNodeLevel(t11,  3) ==  1);
    assert(bstNodeLevel(t11,  2) ==  2);
    assert(bstNodeLevel(t11,  5) ==  2);
    assert(bstNodeLevel(t11,  4) ==  3);
    assert(bstNodeLevel(t11,  7) ==  3);
    assert(bstNodeLevel(t11,  6) ==  4);
    assert(bstNodeLevel(t11,  9) ==  4);
    assert(bstNodeLevel(t11,  8) ==  5);
    assert(bstNodeLevel(t11,  0) == -1);
    assert(bstNodeLevel(t11, 10) == -1);

    printf("bstNodeLevel tests passed!\n");
}

// ----------------------------------------

static void testBstCountGreater(void) {
    printf("Testing bstCountGreater...\n");

    assert(bstCountGreater(t10, 1) == 7);
    assert(bstCountGreater(t10, 2) == 6);
    assert(bstCountGreater(t10, 3) == 5);
    assert(bstCountGreater(t10, 4) == 4);
    assert(bstCountGreater(t10, 5) == 3);
    assert(bstCountGreater(t10, 6) == 2);
    assert(bstCountGreater(t10, 7) == 1);
    assert(bstCountGreater(t10, 8) == 0);

    assert(bstCountGreater(t11, 0) == 9);
    assert(bstCountGreater(t11, 1) == 8);
    assert(bstCountGreater(t11, 2) == 7);
    assert(bstCountGreater(t11, 3) == 6);
    assert(bstCountGreater(t11, 4) == 5);
    assert(bstCountGreater(t11, 5) == 4);
    assert(bstCountGreater(t11, 6) == 3);
    assert(bstCountGreater(t11, 7) == 2);
    assert(bstCountGreater(t11, 8) == 1);
    assert(bstCountGreater(t11, 9) == 0);

    printf("bstCountGreater tests passed!\n");
}

// ----------------------------------------

static struct node *newBstLink(int value, struct node *left, struct node *right) {
    struct node *t = malloc(sizeof(*t));
    if (t == NULL) {
        fprintf(stderr, "Insufficient memory!\n");
        exit(EXIT_FAILURE);
    }

    t->value = value;
    t->right = right;
    t->left = left;
    return t;
}
