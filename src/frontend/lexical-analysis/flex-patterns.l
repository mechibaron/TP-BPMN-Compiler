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
%x NAME_PATTERN

/* Patrones reutilizables. */
endline			[\n]
whitespace		[ \f\n\r\t\v]
event_type      (initial|intermediate|final)
artifact_type   (input|output|collection|storage)
var             $[a-zA-Z0-9]+

%%

"/*"										{ BEGIN(COMMENT); BeginCommentPatternAction(); }
<COMMENT>.									{ ; }
<COMMENT>{endline}							{ ; }
<COMMENT>"*/"								{ EndCommentPatternAction(); BEGIN(INITIAL); }

"\""										{ BEGIN(NAME_PATTERN); BeginNamePatternAction(); }								
<NAME_PATTERN>[^\"]+					    { return NamePatternAction(yytext, yyleng); }
<NAME_PATTERN>"\""								        { EndNamePatternAction(); BEGIN(INITIAL); }



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

{artifact_type}                             { return ArtifactTypePatternAction(yytext, yyleng); }


{var}                                       { return VarPatternAction(yytext, yyleng); }

.											{ return UnknownPatternAction(yytext, yyleng); }

%%