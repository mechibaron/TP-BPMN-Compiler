#include "../../backend/support/logger.h"
#include "../../backend/symbol-table/symbol-table.h"
#include "bison-actions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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


Program * ProgramGrammarAction(Graph * value){

	LogDebug("\tProgramGrammarAction");

	state.succeed = true;

	Program * program = malloc(sizeof(Program));
	program->graph = value;
	state.program = program;
	return program;
}

Graph * CreateGraphActionPool( char* title,  Pool * pool){
	LogDebug("\tCreateGraphAction");
	Graph * graph = malloc(sizeof(Graph));
	graph->name =  malloc(sizeof(char) * (strlen(title) + 1));
	strcpy(graph->name, title);
	graph->pool = pool;
	graph->create = NULL;
	graph->type = WITH_POOL;
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
	graph->create = malloc(sizeof(Create));
	graph->create = create_exp;
	graph->type = WITHOUT_POOL;
	return graph;
}

Expression * CreateEventAction(char* event_type, char* title, char* var){
	EventType type;
	if(strcmp(event_type, "final")==0){
		type = EVENT_FINAL;
	}else if(strcmp(event_type, "initial")==0){
		type = EVENT_INITIAL;
	}else{
		type = EVENT_INTERMEDIATE;
	}
	if(addSymbolToTable(state.table, newEventSymbol(var, EVENT_EXP, type)) == true){
		LogDebug("\tCreateEventAction");
		Expression * exp = malloc(sizeof(Expression));
		if(exp == NULL){
			LogDebug("Error from malloc\n");
			return NULL;
		}
		exp -> exp = EVENT_EXP;
		exp->eventType = type;
		exp->title = malloc(sizeof(char) * (strlen(title) + 1));
		strcpy(exp->title, title);	
		exp->varName = malloc(sizeof(char) * (strlen(var) + 1));
		strcpy(exp->varName, var);
		return exp;
	} else {
		state.errors++;
		LogError("Variable %s ya existe", var);
		return NULL;
	}	
}

Expression * CreateActivityAction(char* title, char* var){
	if(addSymbolToTable(state.table, newSymbol(var, ACTIVITY_EXP)) == true){
		LogDebug("\tCreateActivityAction");
		Expression * exp = malloc(sizeof(Expression));
		if(exp == NULL){
			LogDebug("Error from malloc\n");
			return NULL;
		}
		exp -> exp = ACTIVITY_EXP;
		exp->title = malloc(sizeof(char) * (strlen(title) + 1));
		strcpy(exp->title, title);	
		exp->varName = malloc(sizeof(char) * (strlen(var) + 1));
		strcpy(exp->varName, var);
		return exp;
	}else {
		state.errors++;
		LogError("Variable %s ya existe", var);
		return NULL;
	}	

}

Expression * CreateArtifactAction(char* artifact_type, char* title, char* var){
	if(addSymbolToTable(state.table, newSymbol(var, ARTIFACT_EXP)) == true){
		LogDebug("\tCreateArtifactAction");
		Expression * exp = malloc(sizeof(Expression));
		if(exp == NULL){
			LogDebug("Error from malloc\n");
			return NULL;
		}
		exp -> exp = ARTIFACT_EXP;		
		if(strcmp(artifact_type, "input")==0){
			exp -> artifactType = ARTIFACT_INPUT;
		}else if(strcmp(artifact_type, "output")==0){
			exp -> artifactType = ARTIFACT_OUTPUT;
		}else if(strcmp(artifact_type, "collection")==0){
			exp->artifactType = ARTIFACT_COLLECTION;
		}else{
			exp->artifactType = ARTIFACT_STORAGE;
		}
		exp->title = malloc(sizeof(char) * (strlen(title) + 1));
		strcpy(exp->title, title);	
		exp->varName = malloc(sizeof(char) * (strlen(var) + 1));
		strcpy(exp->varName, var);
		return exp;
	}else {
		state.errors++;
		LogError("Variable %s ya existe", var);
		return NULL;
	}	

}

Gateway * CreateGatewayAction(char * title,  Set * set,  char* var ){
	if(addSymbolToTable(state.table, newSymbol(var, GATEWAY_EXP)) == true){
		LogDebug("\tCreateGatewayAction");
		Gateway * gateway = malloc(sizeof(Gateway));
		if(gateway == NULL){
			LogError("Error from malloc\n");
			return NULL;
		}
		gateway->title =  malloc(sizeof(char) * (strlen(title) + 1));
		strcpy(gateway->title, title);
		gateway->set = set;
		gateway->varName =  malloc(sizeof(char) * (strlen(title) + 1));
		strcpy(gateway->varName, var);
		return gateway;
	}else{
		state.errors++;
		LogError("Variable %s ya existe", var);
		return NULL;
	}
}

Pool * CreatePoolAction( char* poolName,  Lane * lane,  CreateP * createp){
	LogDebug("\tCreatePoolAction");
	Pool * pool = malloc(sizeof(Pool));
	if(pool == NULL){
		state.errors++;
		LogError("Error from malloc\n");
		return NULL;
	}
	pool -> title = malloc(sizeof(char) * (strlen(poolName) + 1));
	strcpy(pool -> title, poolName);
	pool->lane = lane;
	pool->createP = malloc(sizeof(CreateP));
	pool->createP = createp;
	pool->next = NULL;
	return pool;
}

Pool * CreateAppendPoolAction( char* poolName,  Lane *lane,  CreateP * createp, Pool * poolAppend){
	LogDebug("\tCreatePoolAction");
	Pool * pool = malloc(sizeof(Pool));
	if(pool == NULL){
		state.errors++;
		LogError("Error from malloc\n");
		return NULL;
	}
	pool -> title = malloc(sizeof(char) * (strlen(poolName) + 1));
	strcpy(pool -> title, poolName);
	pool->lane = lane;
	pool->createP = malloc(sizeof(CreateP));
	pool->createP = createp;
	pool->next = poolAppend;
	return pool;
}

Lane * CreateLaneAction( char* title,  Create *create_exp, Lane * laneAppend){
	LogDebug("\tCreateLaneAction");
	Lane * lane = malloc(sizeof(Lane));
	if(lane == NULL){
		state.errors++;
		LogError("Error from malloc\n");
		return NULL;
	}
	lane -> title = malloc(sizeof(char) * (strlen(title) + 1));
	strcpy(lane -> title, title);
	lane->type = WITHOUT_LANE;
	lane->create = malloc(sizeof(Create));
	lane->create = create_exp;
	lane->next = laneAppend;
	lane->insideLane = NULL;	
	return lane;
}

Lane * CreateLaneWithLaneAction( char* title,  Lane *lane_param, Lane * laneAppend){
	LogDebug("\tCreateLaneAction");
	Lane * lane = malloc(sizeof(Lane));
	if(lane == NULL){
		state.errors++;
		LogError("Error from malloc\n");
		return NULL;
	}
	lane -> title = malloc(sizeof(char) * (strlen(title) + 1));
	strcpy(lane -> title, title);
	lane->type = WITH_LANE;
	lane->insideLane = malloc(sizeof(Lane));
	lane->insideLane = lane_param;
	lane->next = laneAppend;	
	return lane;
}

Connect * CreateConnectionAction( char* leftVar,  char* rightVar){
	LogDebug("\tCreateConnectionAction");
	Connect * connect = malloc(sizeof(Connect));
	if(connect == NULL){
		LogError("Error from malloc\n");
		return NULL;
	}
	connect->from =  malloc(sizeof(char) * (strlen(leftVar) + 1));
	strcpy(connect->from, leftVar);
	connect->to =  malloc(sizeof(char) * (strlen(rightVar) + 1));
	strcpy(connect->to, rightVar);	
	connect->title= NULL; 
	return connect;
}

Set * CreateSetGatewayAction(char* title, char* var){
	LogDebug("\tCreateSetGatewayAction");
	Set * set = malloc(sizeof(Set));
	if(set == NULL){
		state.errors++;
		LogError("Error from malloc\n");
		return NULL;
	}
	Connect * connect = malloc(sizeof(Connect));
	if(connect == NULL){
		state.errors++;
		LogError("Error from malloc\n");
		return NULL;
	}
	connect->from = NULL;
	connect->to = var;
	connect -> title = malloc(sizeof(char) * (strlen(title) + 1));
	strcpy(connect -> title, title);
	set -> connect =  connect;
	set->next = NULL;	
	return set;
}

Set * CreateAppendSetGatewayAction(char* title, char* var, Set * setAppend){
	LogDebug("\tCreateSetGatewayAction");

	Set * set = malloc(sizeof(Set));
	if(set == NULL){
		state.errors++;
		LogError("Error from malloc\n");
		return NULL;
	}
	Connect * connect = malloc(sizeof(Connect));
	if(connect == NULL){
		state.errors++;
		LogError("Error from malloc\n");
		return NULL;
	}
	connect->from = NULL;
	connect->to = var;
	connect -> title = malloc(sizeof(char) * (strlen(title) + 1));
	strcpy(connect -> title, title);
	set -> connect =  connect;
	set->next = setAppend;	
	return set;
}

Expression * CreateGatewayIntoExpressionAction(Gateway * gateway){
	LogDebug("\tCreateGatewayIntoExpressionAction");
	Expression * exp = malloc(sizeof(Expression));
	if(exp == NULL){
		state.errors++;
		LogError("Error from malloc\n");
		return NULL;
	}
	exp -> exp = GATEWAY_EXP;
	exp -> connect = NULL;
	exp -> title = malloc(sizeof(char) * (strlen(gateway->title) + 1));
	strcpy(exp->title, gateway->title);	
	exp -> varName = malloc(sizeof(char) * (strlen(gateway->varName) + 1));
	strcpy(exp->varName, gateway->varName);
	exp -> gateway = gateway;
	return exp;
}

Expression * CreateConnectIntoExpressionAction(Connect * connect){
	LogDebug("\tCreateConnectIntoExpressionAction");

	Expression * exp = malloc(sizeof(Expression));
	if(exp == NULL){
		state.errors++;
		LogError("Error from malloc\n");
		return NULL;
	}
	exp -> exp = CONNECT_EXP;
	exp -> gateway = NULL;
	exp -> varName = NULL;
	exp -> connect = connect;
	return exp;
}

Create * CreateExpressionIntoCreate(Expression * exp){
	LogDebug("\tCreateExpressionIntoCreate");

	Create * create = malloc(sizeof(Create));
	if(create == NULL){
		state.errors++;
		LogError("Error from malloc\n");
		return NULL;
	}
	create -> expression = exp;
	create -> next = NULL;
	return create;
}

CreateP * CreateIntoCreatep(Create * create){
	LogDebug("\tCreateIntoCreatep");

	CreateP * createp = malloc(sizeof(CreateP));
	if(createp == NULL){
		state.errors++;
		LogError("Error from malloc\n");
		return NULL;
	}
	createp -> create = create;
	return createp;
}

Create * CreateAppendExpresionIntoCreate(Expression * exp, Create * createAppend){
	LogDebug("\tCreateAppendExpresionIntoCreate");

	Create * create = malloc(sizeof(Create));
	if(create == NULL){
		state.errors++;
		LogError("Error from malloc\n");
		return NULL;
	}
	create -> expression = exp;
	create -> next = createAppend;
	return create;
}