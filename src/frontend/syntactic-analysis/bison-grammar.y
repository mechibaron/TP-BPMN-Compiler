
%{

#include "bison-actions.h"
#include "../../backend/support/shared.h"
#include "../../backend/semantic-analysis/abstract-syntax-tree.h"

%}

// Tipos de dato utilizados en las variables semánticas ($$, $1, $2, etc.).
%union{
	Program * program;
	Expression * expression;
	ExpressionP * expressionp;
	Graph * graph;
	Pool * pool;
	PoolP * poolp;
	Gateway * gateway;
	Lane * lane;
	Connect * connect;

	char * string;
	int token;
	int integer;
}

// IDs y tipos de los tokens terminales generados desde Flex.
%token <token> START
%token <token> END
%token <token> GRAPH_ID
%token <token> POOL
%token <token> LANE
%token <token> CREATE
%token <token> EVENT
%token <token> ACTIVITY
%token <token> GATEWAY
%token <token> CONNECT
%token <token> CONNECT_TO
%token <token> CURLY_BRACES_OPEN
%token <token> CURLY_BRACES_CLOSE
%token <token> ARTIFACT
%token <token> AS
%token <token> TO
%token <token> SET

%token <string> NAME
%token <string> EVENT_TYPE
%token <string> ARTIFACT_TYPE
%token <string> VAR


// Tipos de dato para los no-terminales generados desde Bison.
%type <program> program
%type <expression> expression
%type <expressionp> expressionp
%type <graph> graph
%type <pool> pool
%type <poolp> poolp
%type <gateway> gateway
%type <lane> lane
%type <connect> connect
 
%start program

%%

program: graph											{ $$ = ProgramGrammarAction($1); }
	;

graph: START GRAPH_ID NAME pool END GRAPH_ID				{ $$ = CreateGraphAction($3,$4); }
	| START GRAPH_ID NAME expression END GRAPH_ID			{ $$ = CreateGraphAction($3,$4); }
	;

pool: START POOL NAME lane expression END POOL poolp		{ $$ = CreatePoolAction($3,$4); }
	;

poolp: pool 												{ $$ = CreatePoolPAction() }
	| /*lambda*/
	;

lane: START LANE NAME expression END LANE 					{ $$ = CreateLaneAction($3,$4); }
	| /*lambda*/  
	;

expression: CREATE EVENT EVENT_TYPE NAME AS VAR expressionp 			{ $$ = CreateEventAction($3, $4, $6); }
	| CREATE ACTIVITY NAME AS VAR	expressionp 						{ $$ = CreateActivityAction($3, $5); }
	| CREATE ARTIFACT ARTIFACT_TYPE NAME AS VAR expressionp 			{ $$ = CreateArtifactAction($3, $4, $6); }
	| gateway expressionp 												{ $$ = $1 }
	| connect															{ $$ = $1 }
	;


expressionp: expression 													{ $$ = $1 }
	| /*lambda*/ 
	;

gateway: CREATE GATEWAY NAME |
		CREATE GATEWAY NAME 
		CURLY_BRACES_OPEN 
			SET NAME CONNECT TO expression
			SET NAME CONNECT TO expression		
		CURLY_BRACES_CLOSE AS gateway										{ $$ = CreateGatewayAction($3, $6, $8, $10, $12, $15 ); }
	;

connect: CONNECT VAR TO VAR							{$$ = CreateConnectionAction($2, $4); }
	| expressionp 									{ $$ = $1 }
	| /*lambda*/  
	;

%%
