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
#include "../../backend/support/logger.h"
#include "flex-actions.h"
#include <stdlib.h>

/**
 * Implementación de "flex-actions.h".
 *
 * Cada función debe realizar 2 operaciones básicas para lograr el streaming
 * de tokens hacia Bison:
 *
 *	1) Computar los atributos del token y almacenarlos donde sea conveniente
 *		(en la tabla de símbolos, en "yylval", o en ambos).
 *	2) Retornar el token que identifica el terminal identificado.
 *
 * Bison utilizará el token retornado en el punto (2) para matchear dicho
 * terminal en la gramática. Por otro lado, el valor almacenado en "yylval" es
 * el que Bison proveerá como valor semántico al realizar una reducción
 * (mediante $1, $2, $3, etc.).
 */

void BeginCommentPatternAction() {
	LogDebug("BeginCommentPatternAction.");
}

void EndCommentPatternAction() {
	LogDebug("EndCommentPatternAction.");
}



token StartPatternAction(const char * lexeme) {
	LogDebug("StartPatternAction: '%s'.", lexeme);
	yylval.token = START;
	return START;
}

token EndPatternAction(const char * lexeme) {
	LogDebug("EndPatternAction: '%s'.", lexeme);
	yylval.token = END;
	return END;
}

token GraphPatternAction(const char * lexeme) {
	LogDebug("GraphPatternAction: '%s'.", lexeme);
	yylval.token = GRAPH_ID;
	return GRAPH_ID;
}

token PoolPatternAction(const char * lexeme) {
	LogDebug("PoolPatternAction: '%s'.", lexeme);
	yylval.token = POOL;
	return POOL;
}

token LanePatternAction(const char * lexeme) {
	LogDebug("LanePatternAction: '%s'.", lexeme);
	yylval.token = LANE;
	return LANE;
}

token CreatePatternAction(const char * lexeme) {
	LogDebug("CreatePatternAction: '%s'.", lexeme);
	yylval.token = CREATE;
	return CREATE;
}

token ConnectPatternAction(const char * lexeme) {
	LogDebug("ConnectPatternAction: '%s'.", lexeme);
	yylval.token = CONNECT;
	return CONNECT;
}

token EventPatternAction(const char * lexeme) {
	LogDebug("EventPatternAction: '%s'.", lexeme);
	yylval.token = EVENT;
	return EVENT;
}

token ActivityPatternAction(const char * lexeme) {
	LogDebug("ActivityPatternAction: '%s'.", lexeme);
	yylval.token = ACTIVITY;
	return ACTIVITY;
}

token ArtifactPatternAction(const char * lexeme) {
	LogDebug("ArtifactPatternAction: '%s'.", lexeme);
	yylval.token = ARTIFACT;
	return ARTIFACT;
}

token GatewayPatternAction(const char * lexeme) {
	LogDebug("GatewayPatternAction: '%s' ", lexeme);
	yylval.token= atoi(lexeme);
	return GATEWAY;
}

token SetPatternAction(const char * lexeme) {
	LogDebug("SetPatternAction: '%s'.", lexeme);
	yylval.token = SET;
	return SET;
... (102 líneas restantes)
Contraer
message.txt
6 KB
#ifndef FLEX_ACTIONS_HEADER
#define FLEX_ACTIONS_HEADER

#include "../../backend/support/shared.h"
#include "../syntactic-analysis/bison-parser.h"
#define YYUNDEF 257
Expandir
message.txt
3 KB
%{

#include "flex-actions.h"

%}
Expandir
message.txt
3 KB
﻿
%{

#include "flex-actions.h"

%}

/* Obliga a crear una regla explícita para manejar lexemas desconocidos. */
%option nodefault

/* Escanea un único archivo y se detiene. */
%option noyywrap

/* Dispone una variable global "yylineno" con el número de línea actual. */
%option yylineno

/* Contextos de Flex. */
%x COMMENT

/* Patrones reutilizables. */
endline			[\n]
whitespace		[ \f\n\r\t\v]
event_type      (start|intermediate|end)
artifact_type   (input|output|collection|storage)
name            \".*\"
var             $[a-zA-Z]+

%%

"/*"										{ BEGIN(COMMENT); BeginCommentPatternAction(); }
<COMMENT>.									{ ; }
<COMMENT>{endline}							{ ; }
<COMMENT>"*/"								{ EndCommentPatternAction(); BEGIN(INITIAL); }



"start"                                     { return StartPatternAction(yytext); }
"end"                                       { return EndPatternAction(yytext); }

"graph"                                     { return GraphPatternAction(yytext); }
"pool"                                      { return PoolPatternAction(yytext); }
"lane"                                      { return LanePatternAction(yytext); }

"create"                                    { return CreatePatternAction(yytext); }
"connect"                                   { return ConnectPatternAction(yytext); }


"event"                                     { return EventPatternAction(yytext); }
"activity"                                  { return ActivityPatternAction(yytext); }
"artifact"                                  { return ArtifactPatternAction(yytext); }
"gateway"                                   { return GatewayPatternAction(yytext); }

"set"                                       { return SetPatternAction(yytext); }
"as"                                        { return AsPatternAction(yytext); }
"to"                                        { return ToPatternAction(yytext); }

"{"                                         { return OpenCurlyBracesPatternAction(yytext); }            
"}"                                         { return CloseCurlyBracesPatternAction(yytext); }

{whitespace}								{ IgnoredPatternAction(yytext, yyleng); }

{event_type}                                { return EventTypePatternAction(yytext, yyleng); }

{artifact_type}                                  { return ArtifactTypePatternAction(yytext, yyleng); }

{name}                                      { return NamePatternAction(yytext, yyleng); }

{var}                                       { return VarPatternAction(yytext, yyleng); }

.											{ return UnknownPatternAction(yytext, yyleng); }

%%