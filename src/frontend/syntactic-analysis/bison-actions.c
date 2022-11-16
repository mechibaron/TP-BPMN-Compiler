#include "../../backend/domain-specific/calculator.h"
#include "../../backend/support/logger.h"
#include "../../backend/symbol-table/symbol-table.h"
#include "bison-actions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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

Program ProgramGrammarAction(Graph * value){

	LogDebug("\tProgramGrammarAction");

	state.succeed = true;

	Program program;
	program = (Program){.graph=value};
	return program;
	// state.result = value;
}

Graph * CreateGraphActionPool( char* title,  Pool * pool){
	LogDebug("\tCreateGraphAction");
	Graph * graph = malloc(sizeof(Graph));
	graph->name =  malloc(sizeof(char) * (strlen(title) + 1));
	strcpy(graph->name, title);
	graph->pool = pool;
	graph->expression = NULL;
	return graph;
}

Graph * CreateGraphAction( char* title,  Create * create_exp){
	LogDebug("\tCreateGraphAction");
	Graph * graph = malloc(sizeof(Graph));
	if(graph == NULL){
		LogDebug("Error from malloc\n");
		return NULL;
	}
	graph->name = malloc(sizeof(char) * (strlen(title) + 1));
	strcpy(graph->name, title);
	graph->pool = NULL;
	graph->expression = &((*create_exp).expression);
	return graph;
}

Expression * CreateEventAction(char* event_type, char* title, char* var){
	if(addSymbolToTable(state.table, newSymbol(var, EVENT_EXP)) == true){
		LogDebug("\tCreateEventAction");
		Expression * exp = malloc(sizeof(Expression));
		if(exp == NULL){
			LogDebug("Error from malloc\n");
			return NULL;
		}
		exp -> exp = EVENT_EXP;
		exp -> exp_type = malloc(sizeof(char) * (strlen(event_type) + 1));
		strcpy(exp -> exp_type, event_type);
		exp->title = malloc(sizeof(char) * (strlen(title) + 1));
		strcpy(exp->title, title);	
		exp->varName = malloc(sizeof(char) * (strlen(var) + 1));
		strcpy(exp->varName, var);
		return exp;
	} else {
		state.succeed = false;
		return NULL;
	}	
}

Expression * CreateActivityAction(char* title, char* var){
	LogDebug("\tCreateActivityAction");
	Expression * exp = malloc(sizeof(Expression));
	if(exp == NULL){
		LogDebug("Error from malloc\n");
		return NULL;
	}
	exp -> exp = ACTIVITY_EXP;
	exp -> exp_type = NULL;
	exp->title = malloc(sizeof(char) * (strlen(title) + 1));
	strcpy(exp->title, title);	
	exp->varName = malloc(sizeof(char) * (strlen(var) + 1));
	strcpy(exp->varName, var);
	return exp;
}

Expression * CreateArtifactAction(char* artifact_type, char* title, char* var){
	Expression * exp = malloc(sizeof(Expression));
	if(exp == NULL){
		LogDebug("Error from malloc\n");
		return NULL;
	}
	exp -> exp = ARTIFACT_EXP;
	exp -> exp_type = malloc(sizeof(char) * (strlen(artifact_type) + 1));
	strcpy(exp -> exp_type, artifact_type);
	exp->title = malloc(sizeof(char) * (strlen(title) + 1));
	strcpy(exp->title, title);	
	exp->varName = malloc(sizeof(char) * (strlen(var) + 1));
	strcpy(exp->varName, var);
	return exp;
}

Gateway * CreateGatewayAction(char * title,  Set * set,  char* var ){
	LogDebug("\tCreateGatewayAction");
	Gateway * gateway = malloc(sizeof(Gateway));
	if(gateway == NULL){
		LogDebug("Error from malloc\n");
		return NULL;
	}
	gateway->title =  malloc(sizeof(char) * (strlen(title) + 1));
	strcpy(gateway->title, title);
	gateway->set = set;
	gateway->varName =  malloc(sizeof(char) * (strlen(title) + 1));
	strcpy(gateway->varName, var);
	return gateway;
}

Pool * CreatePoolAction( char* poolName,  Lane * lane,  CreateP * createp){
	LogDebug("\tCreatePoolAction");
	Pool * pool = malloc(sizeof(Pool));
	if(pool == NULL){
		LogDebug("Error from malloc\n");
		return NULL;
	}
	pool -> title = malloc(sizeof(char) * (strlen(poolName) + 1));
	strcpy(pool -> title, poolName);
	pool->lane = lane;
	pool -> expression =  &((*createp).create.expression);
	pool->next = NULL;
	return pool;
}

Pool * CreateAppendPoolAction( char* poolName,  Lane *lane,  CreateP * createp, Pool * poolAppend){
	LogDebug("\tCreatePoolAction");
	Pool * pool = malloc(sizeof(Pool));
	if(pool == NULL){
		LogDebug("Error from malloc\n");
		return NULL;
	}
	pool -> title = malloc(sizeof(char) * (strlen(poolName) + 1));
	strcpy(pool -> title, poolName);
	pool->lane = lane;
	pool -> expression =  &((*createp).create.expression);
	pool->next = poolAppend;
	return pool;
}

Lane * CreateLaneAction( char* title,  Create *create_exp, Lane * laneAppend){
	LogDebug("\tCreateLaneAction");
	Lane * lane = malloc(sizeof(Lane));
	if(lane == NULL){
		LogDebug("Error from malloc\n");
		return NULL;
	}
	lane -> title = malloc(sizeof(char) * (strlen(title) + 1));
	strcpy(lane -> title, title);
	lane -> expression =  &((*create_exp).expression);
	lane->next = laneAppend;	
	return lane;
}

Connect * CreateConnectionAction( char* leftVar,  char* rightVar){
	if(existInTable(state.table, leftVar) == true && existInTable(state.table, rightVar) == true){
		LogDebug("\tCreateConnectionAction");
		Connect * connect = malloc(sizeof(Connect));
		if(connect == NULL){
			LogDebug("Error from malloc\n");
			return NULL;
		}
		connect->from =  malloc(sizeof(char) * (strlen(leftVar) + 1));
		strcpy(connect->from, leftVar);
		connect->to =  malloc(sizeof(char) * (strlen(rightVar) + 1));
		strcpy(connect->to, rightVar);	
		connect->title= NULL; //chequear esto
		return connect;
	}else{
		state.succeed = false;
		return NULL;
	}
}

Set * CreateSetGetwayAction(char* title, char* var){
	LogDebug("\tCreateSetGatewayAction");
	Set * set = malloc(sizeof(Set));
	if(set == NULL){
		LogDebug("Error from malloc\n");
		return NULL;
	}
	Connect * connect = malloc(sizeof(Connect));
	if(connect == NULL){
		LogDebug("Error from malloc\n");
		return NULL;
	}
	connect->from = NULL;
	connect->to = var;
	connect -> title = malloc(sizeof(char) * (strlen(title) + 1));
	strcpy(connect -> title, title);
	set -> connect1 =  connect;
	set->next = NULL;	
	return set;
}

Set * CreateAppendSetGetwayAction(char* title, char* var, Set * setAppend){
	LogDebug("\tCreateSetGatewayAction");

	Set * set = malloc(sizeof(Set));
	if(set == NULL){
		LogDebug("Error from malloc\n");
		return NULL;
	}
	Connect * connect = malloc(sizeof(Connect));
	if(connect == NULL){
		LogDebug("Error from malloc\n");
		return NULL;
	}
	connect->from = NULL;
	connect->to = var;
	connect -> title = malloc(sizeof(char) * (strlen(title) + 1));
	strcpy(connect -> title, title);
	set -> connect1 =  connect;
	set->next = setAppend;	
	return set;
}