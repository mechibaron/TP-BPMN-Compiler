#ifndef GENERATOR_HEADER
#define GENERATOR_HEADER
#include "../semantic-analysis/abstract-syntax-tree.h"
#include "../symbol-table/symbol-table.h"
#include "../support/shared.h"


void Generator();
void writeGraph(Graph * graph);
void writePool(Pool * pool);	
void writeLane(Lane * lane);
void writeExpression(Expression * expression);
void writeConnection(Connect * connect);
void writeEvent(EventType eventType, char* title, char* var);
void writeArtifact(ArtifactType artifactType, char* title, char* var);
void writeActivity (char* title, char* var);
void writeGateway(Gateway * gateway);
void writeCreate(Create * create);
void writeCreateP(CreateP * createP);
void writeSet(char * varName, Set * set);
void writeConnectionGateway(Connect * connect, char * from);

#endif
