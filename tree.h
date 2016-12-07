//
// Created by bruno on 26/05/16.
//

#ifndef TREE_TREE_H
#define TREE_TREE_H

#include <stdlib.h>
#include <stdio.h>

const int TRUE = 1;
const int FALSE = 0;
const int NOT_FOUND = -1;

/* Estructuras y tipos */
typedef struct _node {
    int value;
    struct _node * right;
    struct _node * left;
} _Node;

typedef _Node * Node;
typedef _Node * Tree;

void treeInit(Tree *tree);
void add(Tree *tree, int value);
void del(Tree *tree, int value);
int find(Tree tree, int value);
int isEmpty(Tree tree);
int isLeaf(Node node);
int count(Tree tree);
int treeHeight(Tree tree);
int nodeHeight(Tree tree, int value);
void infix(Tree tree, void (*func)(int *));
void prefix(Tree tree, void (*func)(int *));
void postfix(Tree tree, void (*func)(int *));
void chop(Tree *tree);
void _count(Tree tree, int *);
void _height(Tree tree, int, int *);
void showValue(int *value);
void showPostfix(Tree tree);


void treeInit(Tree *tree)
{
    *tree = NULL;
}

void add(Tree *tree, int value)
{
    Node parent = NULL;
    Node current = *tree;

    while(!isEmpty(current) && value != current->value) {
        parent = current;
        if(value < current->value) current = current->left;
        else if(value > current->value) current = current->right;
    }
    if(!isEmpty(current)) return;
    if(isEmpty(parent)) {
        *tree = (Tree)malloc(sizeof(_Node));
        (*tree)->value = value;
        (*tree)->left = (*tree)->right = NULL;
    }
    else if(value < parent->value) {
        current = (Tree)malloc(sizeof(_Node));
        parent->left = current;
        current->value = value;
        current->left = current->right = NULL;
    }
    else if(value > parent->value) {
        current = (Tree)malloc(sizeof(_Node));
        parent->right = current;
        current->value = value;
        current->left = current->right = NULL;
    }
}

void del(Tree *tree, int value)
{
    Node parent = NULL;
    Node current;
    Node node;
    int aux;

    current = *tree;
    while(!isEmpty(current)) {
        if(value == current->value) {
            if(isLeaf(current)) {
                if(parent)
                if(parent->right == current) parent->right = NULL;
                else if(parent->left == current) parent->left = NULL;
                free(current);
                current = NULL;
                return;
            }
            else {
                parent = current;
                if(current->right) {
                    node = current->right;
                    while(node->left) {
                        parent = node;
                        node = node->left;
                    }
                }
                else {
                    node = current->left;
                    while(node->right) {
                        parent = node;
                        node = node->right;
                    }
                }
                aux = current->value;
                current->value = node->value;
                node->value = aux;
                current = node;
            }
        }
        else {
            parent = current;
            if(value > current->value) current = current->right;
            else if(value < current->value) current = current->left;
        }
    }
}

void chop(Tree *tree)
{
    if(*tree) {
        chop(&(*tree)->left);
        chop(&(*tree)->right);
        free(*tree);
        *tree = NULL;
    }
}

void infix(Tree tree, void (*func)(int *))
{
    if(tree->left) infix(tree->left, func);
    func(&(tree->value));
    if(tree->right) infix(tree->right, func);
}

void prefix(Tree a, void (*func)(int *))
{
    func(&a->value);
    if(a->left) prefix(a->left, func);
    if(a->right) prefix(a->right, func);
}

void postfix(Tree a, void (*func)(int *))
{
    if(a->left) postfix(a->left, func);
    if(a->right) postfix(a->right, func);
    func(&a->value);
}

int find(Tree tree, int value)
{
    Node current = tree;
    while(!isEmpty(current)) {
        showValue(&current->value);
        if(value == current->value) return TRUE;
        else if(value < current->value) current = current->left;
        else if(value > current->value) current = current->right;
    }
    return FALSE;
}

int nodeHeight(Tree tree, int value)
{
    int height = 0;
    Node current = tree;

    while(!isEmpty(current)) {
        if(value == current->value) return height;
        else {
            height++;
            if(value < current->value) current = current->left;
            else if(value > current->value) current = current->right;
        }
    }
    return NOT_FOUND;
}

int count(Tree tree)
{
    int count = 0;
    _count(tree, &count);
    return count;
}

void _count(Tree tree, int * count)
{
    (*count)++;
    if(tree->left) _count(tree->left, count);
    if(tree->right) _count(tree->right, count);
}

int treeHeight(Tree tree)
{
    int height = 0;
    _height(tree, 0, &height);
    return height;
}

void _height(Node tree, int aux, int *height)
{
    if(tree->left) _height(tree->left, aux + 1, height);
    if(tree->right) _height(tree->right, aux + 1, height);
    if(isLeaf(tree) && aux > *height) *height = aux;
}

int isEmpty(Tree tree)
{
    return tree==NULL;
}

int isLeaf(Node node)
{
    return !node->right && !node->left;
}

void showValue(int *value)
{
    printf("%d, ", *value);
}

void showPostfix(Tree tree)
{
    postfix(tree, showValue);
}


#endif //TREE_TREE_H
