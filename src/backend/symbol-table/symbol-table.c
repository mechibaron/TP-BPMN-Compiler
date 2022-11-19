#include "symbol-table.h"

// Pure, simple, symbol manipulation
SymbolEntry * newSymbol(char * name, ExpressionType expression){
    SymbolEntry* entry = malloc(sizeof(SymbolEntry));
    char * name_copy = calloc(strlen(name) + 1, sizeof(char));
    strcpy(name_copy, name);
    if(entry == NULL){
        //outOfMemory(state.errorManager);
        return NULL;
    }
    entry->key = (char *)calloc( strlen(name_copy) + 1, sizeof(char));
    if(entry->key == NULL){
        free(entry);
        //outOfMemory(state.errorManager);
        return NULL;
    }
    strcpy(entry->key, name);
    entry->expression = expression;
    return entry;
}

// Recurse through the symbol list

SymbolEntry* getSymbolWithKey(SymbolEntry* entry, char* key) {
    if (entry == NULL)
        return NULL;

    if (strcmp(entry->key, key) == 0)
        return entry;

    return getSymbolWithKey(entry->next, key);
}

// Delete symbol list

void deleteSymbolEntryList(SymbolEntry* entry) {
    if (entry == NULL)
        return;

    if (entry->key != NULL)
        free(entry->key);

    deleteSymbolEntryList(entry->next);
    free(entry);
}

// Table creation
SymbolTable* newEmptySymbolTable() {
    SymbolTable* table = malloc(sizeof(SymbolTable));
    if(table == NULL){
       // outOfMemory(state.errorManager);
        return NULL;
    }
    table->top = NULL;
    return table;
}

// Table erasure
void* deleteScope(SymbolTable* table) {
    if (table == NULL)
        return NULL;

    deleteSymbolEntryList(table->top);
    free(table);
    return NULL;
}


// Table manipulation and referencing
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