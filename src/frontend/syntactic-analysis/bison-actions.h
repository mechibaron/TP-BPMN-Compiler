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

// Programa.
int ProgramGrammarAction(const int value);

// Expresión.
int CreateGraphAction(const char* title, const char*value);
int CreateEventAction(char* type, char* title, char* var);
int CreateActivityAction(char* title, char* var);
int CreateArtifactAction(char* type, char* title, char* var);
int CreateGatewayAction(char* title, char* setName1, char* exp1, char* setName2, char* exp2, char* var );
int CreatePoolAction(const char* pool, const char* lane);
int CreateLaneAction(const char* title, const char* value);
int CreateConnectionAction(const char* leftNode, const char* rightNode);

#endif