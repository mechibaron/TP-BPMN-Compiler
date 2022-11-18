#include "../support/logger.h"
#include "generator.h"
#include "../symbol-table/symbol-table.h"
#include "../semantic-analysis/abstract-syntax-tree.h"

/**
 * Implementación de "generator.h".
 */

void Generator(Program * program) {
	if(program == NULL){
		LogInfo("Program es null");
	} else {
		//LogInfo("ACA ESTA LA INFO DE GENERATOR");
		LogDebug(program->graph->name); // Me tira seg fault lpm
		LogInfo("Feliciationes, haz realizado un BPMN");
	}
}
