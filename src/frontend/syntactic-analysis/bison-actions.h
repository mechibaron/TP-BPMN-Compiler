#ifndef BISON_ACTIONS_HEADER
#define BISON_ACTIONS_HEADER

#include "../../backend/support/shared.h"
#include "../../backend/semantic-analysis/abstract-syntax-tree.h"

/**
 * Se definen las acciones a ejecutar sobre cada regla de producción de la
 * gramática. El objetivo de cada acción debe ser el de construir el nodo
 * adecuado que almacene la información requerida en el árbol de sintaxis
 * abstracta (i.e., el AST).
 */

/** Aclaración: se decidió comentar las siguientes lineas 
 * ya que no era necesario para la entrega 2 (Frontend), pero 
 * será utilizado en la próxima entrega (Backend)
 */

// Programa.
Program ProgramGrammarAction( Graph * value);

// Expresión.
Graph * CreateGraphActionPool(char* title,  Pool *pool);
Graph * CreateGraphAction( char* title,  Create* value);
Pool * CreatePoolAction( char* poolName,  Lane *lane,  CreateP *createp);
Pool * CreateAppendPoolAction( char* poolName,  Lane * lane,  CreateP *createp, Pool *poolAppend);
Lane * CreateLaneAction( char* title,  Create *create_exp, Lane *laneAppend);
Expression * CreateEventAction(char* event_type,char* title, char* var);
Expression * CreateActivityAction(char* title, char* var);
Expression * CreateArtifactAction(char* artifact_type,char* title, char* var);
Gateway * CreateGatewayAction(char* title,  Set * set,  char* var );
Set * CreateSetGetwayAction(char* title, char* var);
Set * CreateAppendSetGetwayAction(char* title, char* var, Set *setAppend);
Connect * CreateConnectionAction( char* leftVar, char* rightVar);

// int CreateGraphActionPool(char* title,  Pool * pool);
// int CreateGraphAction( char* title,  Create * value);
// int CreatePoolAction( char* poolName,  Lane * lane,  CreateP * create);
// int CreateLaneAction( char* title,  Create * expression);
// int CreateEventAction(char* type, char* title, char* var);
// int CreateActivityAction(char* title, char* var);
// int CreateArtifactAction(char* type, char* title, char* var);
// int CreateGatewayAction(char* title,  Set * set,  char* var );
// int CreateSetGetwayAction(char* title, char* var);
// int CreateConnectionAction( char* leftVar, char* rightVar);

#endif