#ifndef ABSTRACT_SYNTAX_TREE_HEADER
#define ABSTRACT_SYNTAX_TREE_HEADER

#include "../support/shared.h"

typedef enum ExpressionType{
    EVENT_EXP,
    ACTIVITY_EXP,
    ARTIFACT_EXP,
    //CONNECT_EXP,
    //GATEWAY_EXP
} ExpressionType;

typedef struct Expression
{
    ExpressionType exp; //event - activity - artifact
    char* exp_type;  //event can be: initial - intermidiate - final,  output-
    char * title;
    char * varName;
    //Connect * connect;
    //Gateway * gateway;
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
    struct Expression *  expression; 
    struct Lane * next;
} Lane;

typedef struct Pool{
    char * title;
    struct Expression *  expression; 
    struct Lane * lane; 
    struct Pool * next;
} Pool;

typedef struct Graph {
    char * name;
    struct Pool * pool;
    struct Expression *  expression; 
} Graph;

typedef struct Program{
    Graph * graph;
} Program;

typedef struct Set {
    struct Connect * connect1;
    struct Set * next;
}Set;

typedef struct Gateway
{
    char * title;
    struct Set * set;
    char * varName;
} Gateway;
#endif