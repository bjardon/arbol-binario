//
// Created by bruno on 7/06/16.
//

#ifndef TREE_LIST_H
#define TREE_LIST_H

//
// Created by bruno on 30/05/16.
//

#include "string.h"
#include "stdlib.h"
#include "stdio.h"

typedef struct _element
{
    char name[255];
    int value;
    struct _element * next;
    struct _element * prev;
} _Element;
typedef _Element * Element;

typedef struct _list
{
    struct _element * first;
} _List;
typedef _List * List;
// Function declarations
void addf(List list, int value);
void add_l(List list, int value);
int get(List list, int index);
int seek(List list, char * name);
int listisempty(List list);
int countlist(List list);

void addf(List list, int value)
{
    Element element;
    element = (Element)malloc(sizeof(_Element));
    element->value = value;
    element->next = list->first;
    element->prev = NULL;
    list->first = element;
    if(element->next)
        element->next->prev = element;
}

void add_l(List list, int value)
{
    if(!listisempty(list))
    {
        Element element;
        element = (Element)malloc(sizeof(_Element));
        element->value = value;
        Element aux;
        aux = list->first;
        while(aux->next)
            aux = aux->next;
        element->next = aux->next;
        aux->next = element;
        element->prev = aux;
        if(element->next)
            element->next->prev = element;
    }
    else
    {
        addf(list, value);
    }
}

int get(List list, int index)
{
    Element aux = list->first;
    int i = 0;
    while(aux->next)
    {
        if(i == index)
            return aux->value;
        aux = aux->next;
        i++;
    }
    return 0;
}

int listisempty(List  list)
{
    if(list->first != NULL)
        return 0;
    return 1;
}

int countlist(List  list)
{
    int i = 1;
    Element aux = list->first;
    if(list->first)
        while(aux->next)
        {
            i++;
            aux = aux->next;
        }
    else
        return 0;
    return i;
}

#endif //TREE_LIST_H
