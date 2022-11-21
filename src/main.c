#include "backend/code-generation/generator.h"
#include "backend/support/logger.h"
#include "backend/support/shared.h"
#include "backend/symbol-table/symbol-table.h"
#include "frontend/syntactic-analysis/bison-parser.h"
#include <stdio.h>
#include <string.h>
#include "backend/domain-specific/validateProgram.h"

// Estado de la aplicación.
CompilerState state;

// Punto de entrada principal del compilador.
const int main(const int argumentCount, const char ** arguments) {
	// Inicializar estado de la aplicación.
	state.program = NULL;
	state.result = 0;
	state.succeed = false;
	state.errors = 0;
	state.table = newEmptySymbolTable();

	// Mostrar parámetros recibidos por consola.
	for (int i = 0; i < argumentCount; ++i) {
		LogInfo("Argumento %d: '%s'", i, arguments[i]);
	}

	// Compilar el programa de entrada.
	LogInfo("Compilando...\n");
	const int result = yyparse();
	switch (result) {
		case 0:
			// La variable "succeed" es la que setea Bison al identificar el símbolo
			// inicial de la gramática satisfactoriamente.
			if (state.succeed && state.errors == 0) {
				LogInfo("La compilacion fue exitosa.");
				if(validateProgram(state.program) == true){
					Generator(state.program);
				} else {
					return -1;
				}
			}
			else {
				LogError("Se produjeron %d errores en la aplicacion.", state.errors);
				return -1;
			}
			break;
		case 1:
			LogError("Bison finalizo debido a un error de sintaxis.");
			break;
		case 2:
			LogError("Bison finalizo abruptamente debido a que ya no hay memoria disponible.");
			break;
		default:
			LogError("Error desconocido mientras se ejecutaba el analizador Bison (codigo %d).", result);
	}
	LogInfo("Fin.");

	return result;
}