#include "symbol-table.h"

SymbolEntry * newSymbol(char * name, ExpressionType expression){
    SymbolEntry* entry = malloc(sizeof(SymbolEntry));
    char * name_copy = calloc(strlen(name) + 1, sizeof(char));
    strcpy(name_copy, name);
    if(entry == NULL){
        return NULL;
    }
    entry->key = (char *)calloc( strlen(name_copy) + 1, sizeof(char));
    if(entry->key == NULL){
        free(entry);
        return NULL;
    }
    strcpy(entry->key, name);
    entry->expression = expression;
    return entry;
}

SymbolEntry * newEventSymbol(char * name, ExpressionType expression, EventType eventType){
    SymbolEntry* entry = malloc(sizeof(SymbolEntry));
    char * name_copy = calloc(strlen(name) + 1, sizeof(char));
    strcpy(name_copy, name);
    if(entry == NULL){
        return NULL;
    }
    entry->key = (char *)calloc( strlen(name_copy) + 1, sizeof(char));
    if(entry->key == NULL){
        free(entry);
        return NULL;
    }
    strcpy(entry->key, name);
    entry->expression = expression;
    entry->eventType = eventType;
    return entry;
}

SymbolEntry* getSymbolWithKey(SymbolEntry* entry, char* key) {
    if (entry == NULL)
        return NULL;

    if (strcmp(entry->key, key) == 0)
        return entry;

    return getSymbolWithKey(entry->next, key);
}

SymbolTable* newEmptySymbolTable() {
    SymbolTable* table = malloc(sizeof(SymbolTable));
    if(table == NULL){
        return NULL;
    }
    table->top = NULL;
    return table;
}

int addSymbolToTable(SymbolTable* table, SymbolEntry* entry) {
    if(existInTable(table, entry->key) == false){
        entry->next = table->top;
        table->top = entry;
        return true;
    }
    return false;
}

SymbolEntry* getEntryFromTable(SymbolTable* table, char* key) {
    if (table == NULL)
        return NULL;

    SymbolEntry* res = getSymbolWithKey(table->top, key);
    return res;
}

int existInTableRecursive(SymbolEntry* entry, char * name){
    if(entry == NULL){
        return false;
    }
    if (strcmp(entry->key,name) == 0){
        return true;
    }else{
        return existInTableRecursive(entry->next, name);
    }
}

int existInTable(SymbolTable* table,char * name){
    return existInTableRecursive(table->top, name);
}

void printSymbolEntry(SymbolEntry* entry) {
    if (entry == NULL)
        printf("<%s>\n", "NONE");
    else
        printf("<%s>\n", entry->key);
}

void printSymbolEntryList(SymbolEntry* entry) {
    if (entry == NULL)
        return;
    printSymbolEntry(entry);
    printSymbolEntryList(entry->next);
}

void printSymbolTable(SymbolTable* table) {

    if (table == NULL) {
        printf("----EOT----\n");
        return;
    }

    printf("----TABLE---\n");
    printSymbolEntryList(table->top);
    printf("----EOT----\n");

}

int isArtifact(SymbolTable* table, char* key ){
    SymbolEntry* entry = getEntryFromTable(table, key);
    if(entry -> expression == ARTIFACT_EXP){
        return true;
    }
    return false;
}

int isFinal(SymbolTable* table, char* key ){
    SymbolEntry* entry = getEntryFromTable(table, key);
    if(entry -> expression == EVENT_EXP && entry -> eventType == EVENT_FINAL){
        return true;
    }
    return false;
}

int hasEventRecursive(SymbolEntry * entry, EventType eventType){
    if(entry == NULL){
        return false;
    }
    if (entry -> expression == EVENT_EXP && entry -> eventType == EVENT_INITIAL){
        return true;
    }else{
        return hasEventRecursive(entry->next, eventType);
    }
}

int hasEvent(SymbolTable * table, EventType eventType){
    return hasEventRecursive(table->top, eventType);
}
