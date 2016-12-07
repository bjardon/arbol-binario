//
// Created by bruno on 26/05/16.
//

#ifndef TREE_UTIL_H
#define TREE_UTIL_H

#include "stdio_ext.h"
#include "list.h"

typedef char * String;

void openfile(FILE ** file, String filename);
void getinput(FILE ** file, String * input);
void getnumbers(String input, List numbers);
int countnumbers(String input);
void addall(Tree *tree, List numbers);
void c();
void pause(String msg);

void openfile(FILE ** file, String filename)
{
    *file = fopen(filename, "r+");
    if(!(*file))
    {
        printf("\n   ERROR!:\n   Ocurrió un error al intentar leer el archivo. El archivo '%s' no se encontró o no se cuenta con suficientes permisos para abrirlo. Asegúrese de que incluyó la extensión del archivo.\n\n", filename);
        exit(-1);
    }
}

void getinput(FILE ** file, String * input)
{
    c();
    fgets(*input, 1000, *file);
}

void getnumbers(String input, List numbers){
    char auxnumber[100];
    int i, j, c = 0, a = 0, aux;
    for(i = 0; i < strlen(input); i++){
        c++;
        if(input[i] == ','){
            for(j = 0; j < c; j++){
                auxnumber[j] = *(input + i + j - c + 1);
            }
            aux = atoi(auxnumber);
            add_l(numbers, aux);
            c = 0;
            a++;
        }
    }
}

int countnumbers(String input)
{
    int i;
    int c = 0;
    for(i = 0; i < strlen(input); i++)
        if (*(input + i) == ',')
            c++;
    return c;
}

void addall(Tree *tree, List numbers)
{
    int i;
    int v;
    int n = countlist(numbers);
    for (i = 0; i < n; i++) {
        v = get(numbers, i);
        add(tree, v);
    }
}

void c()
{
    __fpurge(stdin);
}

void pause(String msg)
{
    char a;
    c();
    if(strlen(msg) > 0)
        printf("\n\n%s\n Presione [Enter] para continuar", msg);
    else
        printf("\n\n Presione [Enter] para continuar");
    while (a != '\n')
        a = getchar();
}

#endif //TREE_UTIL_H
