#ifndef ABSTRACT_SYNTAX_TREE_HEADER
#define ABSTRACT_SYNTAX_TREE_HEADER

#include "../support/shared.h"

typedef struct Expression
{
    char * type; //Activity es una expression y no tiene tipo
    char * title;
    char * varName;
} Expression;

typedef struct ExpressionP
{
    struct Expression * expression;
} ExpressionP;

typedef struct Create {
    struct Expression expression;
}Create;


typedef struct Connect{
    char *  title; //si tiene mensaje -> sino vacio
    struct Expression * from;
    struct Expression * to;
} Connect;

typedef struct Lane{
    char * title;
    struct Expression **  expression; //lista de expresiones
    struct Connect ** connect; //lista de conexiones
} Lane;

typedef struct Pool{
    char * title;
    struct Expression **  expression; //lista de expresiones
    struct Connect ** connect;  //lista de conexiones
    struct Lane ** lane; //arreglo de lanes
} Pool;

typedef struct PoolP
{
    struct Pool * pool;
} PoolP;

typedef struct Graph {
    struct Pool ** pool; //arreglo de pools
} Graph;

typedef struct Program{
    Graph * graph;
} Program;

typedef struct Set {
    struct Connect * connect1;
}Set;

typedef struct SetP{
    struct Set * set;
}SetP;

typedef struct Gateway
{
    char * title;
    struct Set ** sets;
} Gateway;
#endif