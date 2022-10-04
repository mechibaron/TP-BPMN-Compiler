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
}

token AsPatternAction(const char * lexeme) {
	LogDebug("AsPatternAction: '%s'.", lexeme);
	yylval.token = AS;
	return AS;
}

token ToPatternAction(const char * lexeme) {
	LogDebug("ToPatternAction: '%s'.", lexeme);
	yylval.token = TO;
	return TO;
}

token OpenCurlyBracesPatternAction(const char * lexeme) {
	LogDebug("OpenCurlyBracesPatternAction: '%s'.", lexeme);
	yylval.token = CURLY_BRACES_OPEN;
	return CURLY_BRACES_OPEN;
}

token CloseCurlyBracesPatternAction(const char * lexeme) {
	LogDebug("CloseCurlyBracesPatternAction: '%s'.", lexeme);
	yylval.token = CURLY_BRACES_CLOSE;
	return CURLY_BRACES_CLOSE;
}


/*
token IntegerPatternAction(const char * lexeme, const int length) {
	LogDebug("IntegerPatternAction: '%s' (length = %d).", lexeme, length);
	yylval.integer = atoi(lexeme);
	return INTEGER;
}
*/


//???
token NamePatternAction(const char * lexeme, const int length) {
	LogDebug("NamePatternAction: '%s' (length = %d).", lexeme, length);
	char * aux = malloc(length+1);
	strncpy(aux, lexeme, length);
	yylval.string = aux;
	return NAME;
}

token EventTypePatternAction(const char * lexeme, const int length) {
	LogDebug("EventTypePatternAction: '%s' (length = %d).", lexeme, length);
	char * aux = malloc(length+1);
	strncpy(aux, lexeme, length);
	yylval.string = aux;
	return EVENT_TYPE;
}

token ArtifactTypePatternAction(const char * lexeme, const int length) {
	LogDebug("rtifactTypePatternAction: '%s' (length = %d).", lexeme, length);
	char * aux = malloc(length+1);
	strncpy(aux, lexeme, length);
	yylval.string = aux;
	return ARTIFACT_TYPE;
}


token VarPatternAction(const char * lexeme, const int length) {
	LogDebug("VarPatternAction: '%s' (length = %d).", lexeme, length);
	char * aux = malloc(length+1);
	strncpy(aux, lexeme, length);
	yylval.string = aux;
	return VAR;
}



// token MultiplicationOperatorPatternAction(const char * lexeme) {
// 	LogDebug("MultiplicationOperatorPatternAction: '%s'.", lexeme);
// 	yylval.token = MUL;
// 	return MUL;
// }

// // token OpenParenthesisPatternAction(const char * lexeme) {
// // 	LogDebug("OpenParenthesisPatternAction: '%s'.", lexeme);
// // 	yylval.token = OPEN_PARENTHESIS;
// // 	return OPEN_PARENTHESIS;
// }

// // token SubtractionOperatorPatternAction(const char * lexeme) {
// // 	LogDebug("SubtractionOperatorPatternAction: '%s'.", lexeme);
// // 	yylval.token = SUB;
// // 	return SUB;
// }

token UnknownPatternAction(const char * lexeme, const int length) {
	LogDebug("UnknownPatternAction: '%s' (length = %d).", lexeme, length);
	yylval.token = YYUNDEF;
	// Al emitir este token, el compilador aborta la ejecución.
	return YYUNDEF;
}

void IgnoredPatternAction(const char * lexeme, const int length) {
	LogDebug("IgnoredPatternAction: '%s' (length = %d).", lexeme, length);
	// Como no debe hacer nada con el patrón, solo se loguea en consola.
}