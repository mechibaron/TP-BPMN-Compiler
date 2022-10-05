#ifndef ABSTRACT_SYNTAX_TREE_HEADER
#define ABSTRACT_SYNTAX_TREE_HEADER

#include "../support/shared.h"

typedef struct Expression
{
    char * type; //Activity es una expression y no tiene tipo
    char * title;
    char * varName;
} Expression;

typedef struct Create {
    struct Expression expression;
}Create;

typedef struct CreateP {
    struct Create create;
}CreateP;


typedef struct Connect{
    char *  title; //si tiene mensaje -> sino vacio
    char * from;
    char * to;
} Connect;

typedef struct Lane{
    char * title;
    struct Expression *  expression; //lista de expresiones
} Lane;

typedef struct Pool{
    char * title;
    struct Expression *  expression; //lista de expresiones
    struct Lane ** lane; //arreglo de lanes
} Pool;

typedef struct Graph {
    char * name;
    struct Pool ** pool; //arreglo de pools
    struct Expression *  expression; //lista de expresiones
} Graph;

typedef struct Program{
    Graph * graph;
} Program;

typedef struct Set {
    struct Connect * connect1;
}Set;

typedef struct Gateway
{
    char * title;
    struct Set ** sets;
    char * varName;
} Gateway;
#endif