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

Program ProgramGrammarAction( Graph * value){

	LogDebug("\tProgramGrammarAction");


	state.succeed = true;

	// Program program;
	// program = (Program){.graph=value};
	// return &program;
	// state.result = value;
	return NULL;
}

Graph CreateGraphActionPool( char* title,  Pool * pool){
	LogDebug("\tCreateGraphAction");
	// Graph graph;
	// graph = (Graph){.name = title, .pool = &pool, .expression = NULL};	
	// return &graph;
	return NULL;
}

Graph CreateGraphAction( char* title,  Create * expression){
	LogDebug("\tCreateGraphAction");

	// Graph graph;
	// graph = (Graph){.name = title, .pool = NULL, .expression = &(*expression).expression};	
	// return &graph;
	return NULL;
}

Expression CreateEventAction(char* type, char* title, char* var){
	LogDebug("\tCreateEventAction");
	
	// Expression exp;
	// exp = (Expression){.type = type, .title = title, .varName = var};	
	// return &exp;
	return NULL;
}

Expression CreateActivityAction(char* title, char* var){
	LogDebug("\tCreateActivityAction");
	// Expression exp;
	// exp = (Expression){.type = "", .title = title, .varName = var};	
	// return &exp;
	return NULL;
}

Expression CreateArtifactAction(char* type, char* title, char* var){
	// Expression exp;
	// exp = (Expression){.type = type, .title = title, .varName = var};	
	// return &exp;
	return NULL;
}

Gateway CreateGatewayAction(char * title,  Set * set,  char* var ){
	LogDebug("\tCreateGatewayAction");
	// Gateway gateway;
	// gateway = (Gateway){.title = title, .sets = &set, .varName = var};	
	return NULL;
}

Pool CreatePoolAction( char* poolName,  Lane * lane,  CreateP * create){
	LogDebug("\tCreatePoolAction");
	// Pool pool;
	// pool = (Pool){.title = poolName, .lane = &lane, .expression = &(*create).create.expression};		
	// return &pool;
	return NULL;
}

Lane CreateLaneAction( char* title,  Create * expression){
	LogDebug("\tCreateLaneAction");
	// Lane lane;
	// lane = (Lane){.title = title, .expression = &(*expression).expression};	
	// return &lane;
	return NULL;
}

Connect CreateConnectionAction( char* leftVar,  char* rightVar){
	LogDebug("\tCreateConnectionAction");
	// Connect connect;
	// connect = (Connect){.from = leftVar, .to = rightVar};	
	// return &connect;
	return NULL;
}


Set CreateSetGetwayAction(char* title, char* var){
	LogDebug("\tCreateSetGatewayAction");
	// Set set;
	// Connect connect;
	// connect = (Connect){.from = NULL, .to = var, .title= title};	
	// set = (Set){.connect1 = &connect };
	return NULL;
}