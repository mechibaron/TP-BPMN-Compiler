#include "symbol-table.h"

// Pure, simple, symbol manipulation
SymbolEntry* newSymbol(char* name) {
    SymbolEntry* entry = malloc(sizeof(SymbolEntry));
    
    if(entry == NULL){
        //outOfMemory(state.errorManager);
        return NULL;
    }
    printf("%s\n", name);
    //entry->key = malloc( sizeof(char) *  (strlen(name) + 1));
    entry->key = (char *) calloc(strlen(name) + 1, sizeof(char));
    //printf("name: %s\n",name);
    if(entry->key == NULL){
        free(entry);
        //outOfMemory(state.errorManager);
        return NULL;
    }
    strncpy(entry->key, name, strlen(name));
    //printf("%s",entry->key);
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