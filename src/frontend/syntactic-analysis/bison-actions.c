#include "../../backend/domain-specific/calculator.h"
#include "../../backend/support/logger.h"
#include "bison-actions.h"
#include <stdio.h>
#include <string.h>

/**
 * Implementación de "bison-grammar.h".
 */

/**
* Esta función se ejecuta cada vez que se emite un error de sintaxis.
*/
void yyerror(const char * string) {
	LogError("Mensaje: '%s' debido a '%s' (linea %d).", string, yytext, yylineno);
	LogError("En ASCII es:");
	LogErrorRaw("\t");
	const int length = strlen(yytext);
	for (int i = 0; i < length; ++i) {
		LogErrorRaw("[%d]", yytext[i]);
	}
	LogErrorRaw("\n\n");
}

/**
* Esta acción se corresponde con el no-terminal que representa el símbolo
* inicial de la gramática, y por ende, es el último en ser ejecutado, lo que
* indica que efectivamente el programa de entrada se pudo generar con esta
* gramática, o lo que es lo mismo, que el programa pertenece al lenguaje.
*/
int ProgramGrammarAction(const int value) {
	LogDebug("\tProgramGrammarAction(%d)", value);
	/*
	* "state" es una variable global que almacena el estado del compilador,
	* cuyo campo "succeed" indica si la compilación fue o no exitosa, la cual
	* es utilizada en la función "main".
	*/
	state.succeed = true;
	/*
	* Por otro lado, "result" contiene el resultado de aplicar el análisis
	* sintáctico mediante Bison, y almacenar el nood raíz del AST construido
	* en esta variable. Para el ejemplo de la calculadora, no hay AST porque
	* la expresión se computa on-the-fly, y es la razón por la cual esta
	* variable es un simple entero, en lugar de un nodo.
	*/
	state.result = value;
	return value;
}

int CreateGraphAction(const char* title, const char*value) {
	LogDebug("\tCreateGraphAction(%s)", title);
	return 0;
	// return Graph(value);
}

int CreateEventAction(char* type, char* title, char* var){
	LogDebug("\tCreateEventAction(%s)", title);
	return 0;
	// return Event(type, title, var);
}

int CreateActivityAction(char* title, char* var){
	LogDebug("\tCreateActivityAction(%s)", title);
	return 0;
}
int CreateArtifactAction(char* type, char* title, char* var){
	LogDebug("\tCreateArtifactAction(%s)", title);
	return 0;
}

int CreateGatewayAction(char* title, int* setToken, char* var ){
	LogDebug("\tCreateGatewayAction(%s)", title);
	return 0;
}

int CreatePoolAction(const char* pool, const char* lane) {
	LogDebug("\tCreatePoolAction");
	return 0;
	// return Pool(leftValue, rightValue);
}

int CreateLaneAction(const char* title, const char* value) {
	LogDebug("\tCreateLaneAction(%s)", title);
	return 0;
	// return Lane(value);
}

int CreateConnectionAction(const char* leftNode, const char* rightNode){
	LogDebug("\tCreateConnectionAction");
	return 0;
	// return Connection(leftNode, rightNode)
}

int CreatePoolPAction(){
	LogDebug("\tCreateConnectionAction");
	return 0;
	// return Connection(leftNode, rightNode)
}


int CreateSetGetwayAction(char* title, char* setName1){
		LogDebug("\tCreateSetGatewayAction");
	return 0;
}