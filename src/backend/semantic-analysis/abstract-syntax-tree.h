#ifndef ABSTRACT_SYNTAX_TREE_HEADER
#define ABSTRACT_SYNTAX_TREE_HEADER


typedef enum ExpressionType {
    EVENT_EXP,
    ACTIVITY_EXP,
    ARTIFACT_EXP,
    CONNECT_EXP,
    GATEWAY_EXP
} ExpressionType;

typedef enum EventType{
    EVENT_INITIAL,
    EVENT_INTERMEDIATE,
    EVENT_FINAL
} EventType;

typedef enum ArtifactType{
    ARTIFACT_INPUT,
    ARTIFACT_OUTPUT,
    ARTIFACT_COLLECTION,
    ARTIFACT_STORAGE
} ArtifactType;

// Agregue esto por lo que nos dijo agus que por cada opction que tengamos tenemos que tener un enum.
typedef enum GraphType {
    WITH_POOL,
    WITHOUT_POOL
} GraphType;

typedef enum LaneType {
    WITH_LANE,
    WITHOUT_LANE
} LaneType;

typedef struct Connect {
    char * title; //si tiene mensaje -> sino vacio
    char * from;
    char * to;
} Connect;

typedef struct Gateway {
    char * title;
    struct Set * set;
    char * varName;
} Gateway;

typedef struct Expression {
    ExpressionType exp; //event - activity - artifact - gateway - connect
    EventType eventType;
    ArtifactType artifactType;
    char * title;
    char * varName;
    Connect * connect;
    Gateway * gateway;
} Expression;

typedef struct Create {
    struct Expression * expression;
    struct Create * next;
}Create;

typedef struct CreateP {
    struct Create * create;
}CreateP;

typedef struct Lane {
    char * title;
    LaneType type;
    struct Lane * insideLane;
    struct Create *  create; 
    struct Lane * next;
} Lane;

typedef struct Pool {
    char * title;
    struct CreateP *  createP; 
    struct Lane * lane; 
    struct Pool * next;
} Pool;

typedef struct Graph {
    char * name;
    struct Pool * pool;
    struct Create *  create; 
    GraphType type; //with pool, without pool
} Graph;

typedef struct Program {
    Graph * graph;
} Program;

typedef struct Set {
    struct Connect * connect;
    struct Set * next;
}Set;

#endif