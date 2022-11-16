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
    struct SymbolEntry * next; 
} SymbolEntry; 

typedef struct SymbolTable {
    SymbolEntry * top; 
} SymbolTable; 

// Symbol creation. A symbol cannot be deleted individually, it is destroyed in scope deletion. 
SymbolEntry * newSymbol(char * name, ExpressionType expression); 
SymbolEntry * getSymbolWithKey(SymbolEntry * entry, char * key); 

// Scope creation and deletion 
SymbolTable * newEmptySymbolTable();
void * deleteScope(SymbolTable * table);

// Symbol manipulation into tables
int addSymbolToTable(SymbolTable * table, SymbolEntry * entry); 
SymbolEntry * getEntryFromTable(SymbolTable * table, char * key); 

int existInTable(SymbolTable* table,char * name);

// Debugging
//void printSymbolEntry(SymbolEntry * entry); 
//void printSymbolEntryList(SymbolEntry * entry); 
void printSymbolTable(SymbolTable * table);

#endif