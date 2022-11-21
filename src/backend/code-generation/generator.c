#include "../support/logger.h"
#include "generator.h"

/**
 * Implementación de "generator.h".
 */
FILE * file;

int clusterCount = 0;

void Generator(Program * program) {
	if(program == NULL){
		LogInfo("Program es null");
	} else {
		file = fopen("out.dot", "w+");
		fprintf(file, "digraph {\n");
		writeGraph(program->graph);
		fprintf(file, "}");
		fclose(file);
		LogInfo("Feliciationes, haz realizado un BPMN");
	}
	free(program);
}

void writeGraph(Graph * graph){		
	fprintf(file, "subgraph cluster_%d { \n", clusterCount++);
	fprintf(file, "label=\"%s\"\n", strlen(graph->name) != 0 ? graph->name : "" );
	fprintf(file, "labelloc=\"t\" \n");
	
	if(graph->type == WITH_POOL){
		writePool(graph->pool);
	}
	if(graph->create != NULL){
		writeCreate(graph->create);
	}
	fprintf(file, "} \n");
	free(graph);
}

void writePool(Pool * pool){
		
	fprintf(file, "subgraph cluster_%d { \n", clusterCount++);
	fprintf(file, "label=\"%s\"\n", strlen(pool->title) != 0 ? pool->title : "" );
	
	if(pool->createP != NULL){
		writeCreateP(pool->createP);
	}
	if(pool->lane != NULL){
		writeLane(pool->lane);
	}

	fprintf(file, "} \n");

	if(pool->next != NULL){
		writePool(pool->next);
	}
	free(pool);
}	

void writeLane(Lane * lane){	
	fprintf(file, "subgraph cluster_%d { \n", clusterCount++ );
	fprintf(file, "label=\"%s\"\n", strlen(lane->title) != 0 ? lane->title : "" );

	if(lane->create != NULL){
		writeCreate(lane->create);
	}
	fprintf(file, "} \n");

	if(lane->next != NULL){
		writeLane(lane->next);
	}
	free(lane);
}	

void writeCreate(Create * create){
	if(create->expression != NULL){
		writeExpression(create->expression);
	}
	if(create->next != NULL){
		writeCreate(create->next);
	}
	free(create);
}

void writeCreateP(CreateP * createP){
	if(createP->create != NULL){
		writeCreate(createP->create);
	}
	free(createP);
}

void writeExpression(Expression * expression){	
	if(expression->exp == CONNECT_EXP){
		writeConnection(expression->connect);
	}else if(expression->exp == EVENT_EXP){
		writeEvent(expression->eventType, expression->title, expression->varName);
	}else if(expression->exp == ARTIFACT_EXP){
		writeArtifact(expression->artifactType, expression->title, expression->varName);
	}else if(expression->exp == ACTIVITY_EXP){
		writeActivity(expression->title, expression->varName);
	}else{
		writeGateway(expression->gateway);
	}
	free(expression);
}	

void writeConnection(Connect * connect){
	if(isArtifact(state.table, connect->from) == true){
		fprintf(file, "\t %s->%s  [style=dashed]\n", (connect->from + 1), (connect->to + 1));
	}else{
		fprintf(file, "\t %s->%s\n", (connect->from + 1), (connect->to + 1) );
	}
	free(connect);
}
 
void writeEvent(EventType eventType, char* title, char* var){
	if(eventType == EVENT_INITIAL){
		fprintf(file, "\t %s [label=\"%s\" , shape=circle, color=green]\n",(var + 1), title);
	}else if (eventType == EVENT_INTERMEDIATE){
		fprintf(file, "\t %s [label=\"%s\" , shape=doublecircle, color=orange]\n",(var + 1), title);
	}else{
		fprintf(file, "\t %s [label=\"%s\" , shape=circle, color=red]\n",(var + 1), title);
	}
}

void writeArtifact(ArtifactType artifactType, char* title, char* var){
	if(artifactType == ARTIFACT_STORAGE){
		fprintf(file, "\t %s [label=\"%s\" , shape=cylinder, color=black]\n",(var + 1), title);
	}else {
		fprintf(file, "\t %s [label=\"%s\" , shape=note, color=black]\n",(var + 1), title);
	}
}

void writeActivity (char* title, char* var){
	fprintf(file, "\t %s [label=\"%s\" , shape=rectangle, color=yellow]\n", (var + 1), title);
}

void writeGateway(Gateway * gateway){
	fprintf(file, "\t %s [label=\"%s\" shape=diamond,  color=gray, style=filled]\n", (gateway->varName + 1), gateway->title);
	if(gateway->set != NULL){
		writeSet(gateway->varName, gateway->set);
	}
	free(gateway);
}

void writeSet(char * varName, Set * set){
	if(set->connect != NULL){
		writeConnectionGateway(set->connect, varName);
	}
	if(set->next != NULL){
		writeSet(varName, set->next);
	}
	free(set);
}


void writeConnectionGateway(Connect * connect, char * from){
	fprintf(file, "%s->%s [label=\"%s\"]\n", (from + 1), (connect->to + 1), connect->title);
	free(connect);
}