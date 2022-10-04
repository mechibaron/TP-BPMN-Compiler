#ifndef FLEX_ACTIONS_HEADER
#define FLEX_ACTIONS_HEADER

#include "../../backend/support/shared.h"
#include "../syntactic-analysis/bison-parser.h"
#define YYUNDEF 257
/**
 * Se definen las acciones a ejecutar sobre cada patrón hallado mediante el
 * analizador léxico Flex. Este analizador solo puede identificar
 * construcciones regulares, ya que utiliza un autómata finito determinístico
 * (a.k.a. DFA), como mecanismo de escaneo y reconocimiento.
 *
 * Debería existir una acción por cada patrón disponible en Flex (es decir,
 * por cada regla).
 *
 * Solo aquellas acciones que tengan interés en conocer el largo del lexema
 * emplean el parámetro adicional "length". Esto es útil cuando se desea
 * asignar memoria dinámica, y por lo tanto, se debe saber exactamente el
 * largo de aquello que se va a almacenar.
 */

// Bloque de comentarios multilínea.
void BeginCommentPatternAction();
void EndCommentPatternAction();

// Patrones terminales del lenguaje diseñado.
token StartPatternAction(const char * lexeme);
token EndPatternAction(const char * lexeme);
token GraphPatternAction(const char * lexeme);
token PoolPatternAction(const char * lexeme);
token LanePatternAction(const char * lexeme);
token CreatePatternAction(const char * lexeme);
token ConnectPatternAction(const char * lexeme);
token EventPatternAction(const char * lexeme);
token ActivityPatternAction(const char * lexeme);
token ArtifactPatternAction(const char * lexeme);
token GatewayPatternAction(const char * lexeme);
token SetPatternAction(const char * lexeme);
token AsPatternAction(const char * lexeme);
token ToPatternAction(const char * lexeme);
token OpenCurlyBracesPatternAction(const char * lexeme);
token CloseCurlyBracesPatternAction(const char * lexeme);
token NamePatternAction(const char * lexeme, const int length);
token EventTypePatternAction(const char * lexeme, const int length);
token ArtifactTypePatternAction(const char * lexeme, const int length);
token VarPatternAction(const char * lexeme, const int length);


// Patrón desconocido, permite abortar debido a un error de sintaxis.
token UnknownPatternAction(const char * lexeme, const int length);

// Regla que no hace nada, permite ignorar parte de la entrada.
void IgnoredPatternAction(const char * lexeme, const int length);

#endif