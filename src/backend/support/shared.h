agus
#8420

abril
 ha saltado al servidor.
 — 05/09/2022
Me alegra verte, 
victoria_
.
 — 05/09/2022
mb0301010
 acaba de dejarse caer en el servidor.
 — 05/09/2022
victoria_ — 05/09/2022
hola
Imagen
Imagen
victoria_ — 01/10/2022
https://prod.liveshare.vsengsaas.visualstudio.com/join?B398BC04634C690E38CBEC4AD823DC51EBED
Visual Studio Code for the Web
Build with Visual Studio Code, anywhere, anytime, entirely in your browser.
abril — 01/10/2022
https://github.com/mcornidez/TP-TLA
GitHub
GitHub - mcornidez/TP-TLA
Contribute to mcornidez/TP-TLA development by creating an account on GitHub.
GitHub - mcornidez/TP-TLA
victoria_ — 01/10/2022
https://prod.liveshare.vsengsaas.visualstudio.com/join?493DFA80684B743B33881805227A249A51F5
Visual Studio Code for the Web
Build with Visual Studio Code, anywhere, anytime, entirely in your browser.
abril — 01/10/2022
https://campusvirtual.ull.es/ocw/pluginfile.php/2311/mod_resource/content/0/perlexamples/node216.html
El Análisis Léxico en yacc: flex
El Análisis Léxico en yacc: flex
https://prod.liveshare.vsengsaas.visualstudio.com/join?684FFA37A570B458FC4E3B14C92377EF39C6
Visual Studio Code for the Web
Build with Visual Studio Code, anywhere, anytime, entirely in your browser.
victoria_ — 01/10/2022
Imagen
Imagen
victoria_ — 01/10/2022
Imagen
abril — 01/10/2022
Imagen
abril — 01/10/2022
https://prod.liveshare.vsengsaas.visualstudio.com/join?684FFA37A570B458FC4E3B14C92377EF39C6
Visual Studio Code for the Web
Build with Visual Studio Code, anywhere, anytime, entirely in your browser.
agus — 01/10/2022
Imagen
victoriarossi2
 se ha unido al grupo.
 — ayer a las 19:24
abril — ayer a las 19:52
https://prod.liveshare.vsengsaas.visualstudio.com/join?54E9BB6B457AE0217EEEAA4CB928A397FDEE
Visual Studio Code for the Web
Build with Visual Studio Code, anywhere, anytime, entirely in your browser.
victoria_ — ayer a las 19:54
Imagen
abril — ayer a las 20:07
https://www.lucidchart.com/pages/bpmn-artifact-types
Lucidchart
BPMN Artifact Types
https://github.com/mcornidez/TP-TLA
GitHub
GitHub - mcornidez/TP-TLA
Contribute to mcornidez/TP-TLA development by creating an account on GitHub.
GitHub - mcornidez/TP-TLA
abril — ayer a las 21:19
Imagen
mb0301010 — hoy a las 15:38
https://prod.liveshare.vsengsaas.visualstudio.com/join?6CFB24D76C99E53EBE0FE343512071312602
Visual Studio Code for the Web
Build with Visual Studio Code, anywhere, anytime, entirely in your browser.
https://prod.liveshare.vsengsaas.visualstudio.com/join?C59612D9A4E03D7346ECBBAEAD8961B4F9C1
Visual Studio Code for the Web
Build with Visual Studio Code, anywhere, anytime, entirely in your browser.
https://prod.liveshare.vsengsaas.visualstudio.com/join?FC988FA94F6B8F72D3FCE23CE58C6867CA73
Visual Studio Code for the Web
Build with Visual Studio Code, anywhere, anytime, entirely in your browser.
agus — hoy a las 16:29
@mb0301010  me fui a hacer un pichin yo tamb
mb0301010 — hoy a las 16:29
d1
mb0301010 — hoy a las 16:57
js
jsjs
sisi tambien colgue de piola ah js
Me alegra que estés aquí, 
mechibaron
.
 — hoy a las 17:10
Lukyferreiro
 está aquí.
 — hoy a las 17:46
mb0301010 — hoy a las 17:49
https://prod.liveshare.vsengsaas.visualstudio.com/join?FC988FA94F6B8F72D3FCE23CE58C6867CA73
Visual Studio Code for the Web
Build with Visual Studio Code, anywhere, anytime, entirely in your browser.
mb0301010 — hoy a las 19:07
https://github.com/mechibaron/TP-BPMN-Compiler/tree/compilador-probando
mb0301010 — hoy a las 19:19
#ifndef SHARED_HEADER
#define SHARED_HEADER

#include <stdio.h>
#include <string.h>
#include "../semantic-analysis/abstract-syntax-tree.h"
Expandir
message.txt
3 KB
#ifndef SHARED_HEADER
#define SHARED_HEADER

#include <stdio.h>
#include <string.h>
#include "../semantic-analysis/abstract-syntax-tree.h"
Expandir
message.txt
3 KB
﻿
#ifndef SHARED_HEADER
#define SHARED_HEADER

#include <stdio.h>
#include <string.h>
#include "../semantic-analysis/abstract-syntax-tree.h"

// Descriptor del archivo de entrada que utiliza Bison.
extern FILE * yyin;

// Descriptor del archivo de salida que utiliza Bison.
extern FILE * yyout;

// La cantidad de caracteres en el lexema "yytext". Se debe leer en las
// acciones de Flex, no en Bison.
extern size_t yyleng;

// Variable global que contiene el número de la línea analizada.
extern int yylineno;

// Token actual en el tope de la pila del analizador Bison.
extern char * yytext;

// Función global de manejo de errores en Bison.
extern void yyerror(const char * string);

// Función global del analizador léxico Flex.
extern int yylex(void);

// Función global del analizador sintáctico Bison.
extern int yyparse(void);

// Emular tipo "boolean".
typedef enum {

	false = 0,
	true = 1
} boolean;

// El tipo de los tokens emitidos por Flex.
typedef int token;

// Estado global de toda la aplicación.
typedef struct {
	// Indica si la compilación tuvo problemas hasta el momento.
	boolean succeed;
	// Indica el resultado de la compilación (para la calculadora).
	int result;
	// El nodo raíz del AST (se usará cuando se implemente el backend).
	Program * program;
} CompilerState;

// El estado se define e inicializa en el archivo "main.c".
extern CompilerState state;

#endif