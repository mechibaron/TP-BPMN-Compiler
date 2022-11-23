#ifndef SYMBOL_TABLE_HEADER
#define SYMBOL_TABLE_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../support/shared.h"
#include "../semantic-analysis/abstract-syntax-tree.h"

typedef struct SymbolEntry {
    char * key; //variable name
    ExpressionType expression;
    EventType eventType;
    struct SymbolEntry * next; 
} SymbolEntry; 

typedef struct SymbolTable {
    SymbolEntry * top; 
} SymbolTable; 

SymbolEntry * newSymbol(char * name, ExpressionType expression); 
SymbolEntry * newEventSymbol(char * name, ExpressionType expression, EventType eventType);
SymbolEntry * getSymbolWithKey(SymbolEntry * entry, char * key); 

SymbolTable * newEmptySymbolTable();

int addSymbolToTable(SymbolTable * table, SymbolEntry * entry); 
SymbolEntry * getEntryFromTable(SymbolTable * table, char * key); 

int existInTable(SymbolTable* table,char * name);
int isArtifact(SymbolTable * table, char * key);
int isFinal(SymbolTable * table, char * key);
int hasEvent(SymbolTable * table, EventType eventType);

// Debugging
void printSymbolTable(SymbolTable * table);

#endif