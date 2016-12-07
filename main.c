#include "string.h"
#include "stdio.h"
#include "tree.h"
#include "util.h"
#include "list.h"

void header();
int menu();

int main(int argc, char const * argv[])
{
    Tree tree;
    treeInit(&tree);
    String input = (String)malloc((size_t) 1000);
    String filename = (String)malloc((size_t) 1000);
    FILE * file = NULL;
    List numbers = (List)malloc(sizeof(List));
    int v;

    if(argc > 1) strcpy(filename, argv[1]);
    else
    {
        printf("\nIndique el nombre del archivo a leer \n(por favor incluya la extensión)\n   > ");
        scanf("%[^\n]s", filename);
    }
    openfile(&file, filename);
    getinput(&file, &input);
    getnumbers(input, numbers);
    addall(&tree, numbers);
    while (1) {
        switch (menu()) {
            case 0:
                exit(0);
            case 1: {
                header();
                printf("\n\t   INSERTAR NODO\n");
                printf("\n Ingrese un valor para insertar:\n  > ");
                c();
                scanf("%d", &v);
                add(&tree, v);
                pause("Insercion terminada");
                break;
            }
            case 2: {
                header();
                printf("\n\t    BUSCAR NODO\n");
                printf("\n Ingrese el valor a buscar:\n  > ");
                c();
                scanf("%d", &v);
                if (!find(tree, v))
                    printf("\n El valor no esta en el arbol! Deberia estar en esta posicion!\n");
                pause("Busqueda terminada");
                break;
            }
            case 3: {
                header();
                printf("\n\t    ELIMINAR NODO\n");
                printf("\n Imprimiendo todo el arbol...\n");
                showPostfix(tree);
                printf("\n Ingrese el valor a eliminar:\n  > ");
                c();
                scanf("%d", &v);
                del(&tree, v);
                printf("\n Imprimiendo todo el arbol...\n");
                showPostfix(tree);
                pause("Eliminacion terminada");
                break;
            }
            case 4: {
                header();
                printf("\n\t    RECORRIDO EN POSTFIJO\n");
                printf("\n Imprimiendo todo el arbol...\n");
                showPostfix(tree);
                pause("Recorrido terminado");
                break;
            }
            case 666: {
                while (1)
                    printf(":D ");
            }
        }
    }
}

void header()
{
    //system("reset");
    printf("\n\t PRACTICA DE ARBOL BINARIO");
    printf("\n\t    Jardon Fonseca Bruno");
    printf("\n");
}

int menu()
{
    int repeat = 0;
    char ans;
    do {
        header();
        printf("\n\t MENU PRINCIPAL");
        printf("\n  1. Insertar nuevo elemento");
        printf("\n  2. Buscar un nodo");
        printf("\n  3. Eliminar un nodo");
        printf("\n  4. Imprimir todo el arbol");
        printf("\n  x. Salir");
        printf("\n  > ");
        c();
        scanf("%c", &ans);
        switch (ans)
        {
            case '1':
                repeat = 0;
                return 1;
            case '2':
                repeat = 0;
                return 2;
            case '3':
                repeat = 0;
                return 3;
            case '4':
                repeat = 0;
                return 4;
            case 'x':
            case 'X':
                repeat = 0;
                return 0;
            case '+':
                repeat = 0;
                return 666;
            default:
                repeat = 1;
                break;
        }
    } while (repeat);
}