
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
	Create * create;
	Set * set;
	SetP * setp;
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
%type <create> create
%type <graph> graph
%type <pool> pool
%type <poolp> poolp
%type <gateway> gateway
%type <set> set
%type <setp> setp
%type <lane> lane
%type <connect> connect
 
%start program

%%

program: graph											{ $$ = ProgramGrammarAction($1); }
	;

graph: START GRAPH_ID NAME pool END GRAPH_ID				{ $$ = CreateGraphAction($3,$4); }
	| START GRAPH_ID NAME expression END GRAPH_ID			{ $$ = CreateGraphAction($3,$4); }
	;

pool: START POOL NAME lane expressionp END POOL poolp		{ $$ = CreatePoolAction($3,$4); }
	;

poolp: pool 												{ $$ = CreatePoolPAction() }
	| /*lambda*/
	;

lane: START LANE NAME expression END LANE lane				{ $$ = CreateLaneAction($3,$4); }
	| START LANE expression END LANE lane					{ $$ = CreateLaneAction($3,$4); }
	| /*lambda*/  
	;
                  
expression: create expressionp 	{ $$ = $1 }
			;
create:  CREATE EVENT EVENT_TYPE NAME AS VAR 			{ $$ = CreateEventAction($3, $4, $6); }
		| CREATE ACTIVITY NAME AS VAR 					{ $$ = CreateActivityAction($3, $5); }
		| CREATE ARTIFACT ARTIFACT_TYPE NAME AS VAR  	{ $$ = CreateArtifactAction($3, $4, $6); }
		| gateway										{ $$ = $1; }
		| connect										{ $$ = $1; }
		;

expressionp: expression 								{ $$ = $1 }
	| /*lambda*/ 
	;

gateway: CREATE GATEWAY NAME  CURLY_BRACES_OPEN
			set	
		 CURLY_BRACES_CLOSE AS VAR 						{ $$ = CreateGatewayAction($3, $4, $7); }
	;

set: SET NAME CONNECT TO VAR setp 						{ $$ = CreateSetGetwayAction($2, $5); }
	;

setp: set | /*lambda*/
	;


connect: CONNECT VAR TO VAR 						{$$ = CreateConnectionAction($2, $4); } 
	;

%%
