/* Name: Tawan Chaeyklinthes
 * ID: 5980963
 */
#include <stdlib.h>
#include <stdio.h>
#include "btree.h"

void insert(Node **tree, int val) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = val;
    n->left = NULL;
    n->right = NULL;
    
    if((*tree) == NULL){
        (*tree) = n;

    }else{
        Node *parent = (*tree);
        
        while(1){
            
            if(val  > parent->data){
                
                if(!parent->right){
                    parent->right = n;
                    break;
                }else{
                    parent = parent->right;
                }
            }else{
                if(!parent->left){
                    parent->left = n;
                    break;
                }else{
                    parent = parent->left;
                }
            }
        }

    }
}

void helperPrint(Node *tree,int spaces){
    if(tree){
        printf("%*s|-%d\n",spaces," ",tree->data);
        helperPrint(tree->left,spaces+2);
        helperPrint(tree->right,spaces+2);
    }
}


void print(Node *tree) {
    printf("%d\n",tree->data);
    helperPrint(tree->left,0);
    helperPrint(tree->right,0);
}

void delete(Node *tree) {
    if(tree){
        delete(tree->left);
        delete(tree->right);
        free(tree);
    }

}


Node *lookup(Node ** tree, int val) {
    
    Node *node = *tree;
    
    while(node){
        
        if(node->data == val){
            return node;
        }else if(node->data > val){
            node = node->left;
        }else{
            node = node->right;
        }
    }
    return node;

}


/***** Expected output: *****
7
|-2
  |-1
  |-4
|-10
  |-15
    |-12
      |-11
Found
Not Found
 *****************************/
int main(int argc, char **argv)
{
    Node *root = NULL;
    Node *target = NULL;

    // add nodes
    insert(&root, 7);
    insert(&root, 2);
    insert(&root, 4);
    insert(&root, 10);
    insert(&root, 1);
    insert(&root, 15);
    insert(&root, 12);
    insert(&root, 11);

    // Lets see how the tree looks
    print(root);

    // Check if 4 in the tree
    target = lookup(&root, 4);
    if (target) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    // Check if 44 in the tree
    target = lookup(&root, 44);
    if (target) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    // Now let's free up the space
    delete(root);
}
