//Aclaracion: las lineas comentadas son parte del desarrollo del backend, por eso se las 
//comentó para la entrega del Frontend

%{

#include "bison-actions.h"
#include "../../backend/support/shared.h"
#include "../../backend/semantic-analysis/abstract-syntax-tree.h"

%}

// Tipos de dato utilizados en las variables semánticas ($$, $1, $2, etc.).
%union{
	
	Program program;
	Expression expression;
	Create create;
	CreateP createp;
	Graph graph;
	Pool pool;
	Gateway gateway;
	Set set;
	Lane lane;
	Connect connect;

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
%type <create> create
%type <createp> createp
%type <graph> graph
%type <pool> pool
%type <gateway> gateway
%type <set> set
%type <lane> lane
%type <connect> connect
 
%start program

%%

program: graph											/*{ $$ = ProgramGrammarAction(NULL); }*/ { $$ = ProgramGrammarAction($1); }
	;

graph: START GRAPH_ID NAME pool END GRAPH_ID				{ $$ = CreateGraphActionPool($3,$4); }/* { $$ = CreateGraphActionPool(NULL,NULL); }*/
	| START GRAPH_ID NAME create END GRAPH_ID				{ $$ = CreateGraphAction($3,$4); } /* { $$ = CreateGraphAction(NULL,NULL); }*/
	;

pool: START POOL NAME lane createp END POOL					{ $$ = CreatePoolAction($3,$4, $5); } /*{ $$ = CreatePoolAction(NULL,NULL,NULL); }*/
	| START POOL NAME lane createp END POOL pool			{ $$ = CreatePoolAction($3,$4, $5); } /*{ $$ = CreatePoolAction(NULL,NULL,NULL); }*/
	;

lane: START LANE NAME create END LANE lane				{ $$ = CreateLaneAction($3,$4); } /* { $$ = CreateLaneAction(NULL,NULL); }*/
	| START LANE create END LANE lane					{ $$ = CreateLaneAction("",$3); } /*{ $$ = CreateLaneAction(NULL,NULL); }*/
	| /*lambda*/  										{ $$ = 0 }
	;

create: expression  											{ $$ = 0 }
		| expression create 								{ $$ = 0 }            

createp: create 	  										{ $$ = 0 }
		| /*lambda*/  										{ $$ = 0 }
		;
expression:  CREATE EVENT EVENT_TYPE NAME AS VAR 		{ $$ = CreateEventAction($3, $4, $6); } /*{ $$ = CreateEventAction(NULL,NULL,NULL); }*/
		| CREATE ACTIVITY NAME AS VAR 					{ $$ = CreateActivityAction($3, $5); } /*{ $$ = CreateActivityAction(NULL,NULL); }*/
		| CREATE ARTIFACT ARTIFACT_TYPE NAME AS VAR  	{ $$ = CreateArtifactAction($3, $4, $6); } /*{ $$ = CreateArtifactAction(NULL,NULL,NULL); }*/
		| gateway										{ $$ = 0; }
		| connect										{ $$ = 0; }
		;


gateway: CREATE GATEWAY NAME CURLY_BRACES_OPEN
			set	
		 CURLY_BRACES_CLOSE AS VAR 						{ $$ = CreateGatewayAction($3, $5, $8); } /* { $$ = CreateGatewayAction(NULL, NULL, NULL); } */
	;

set: SET NAME CONNECT TO VAR  						{ $$ = CreateSetGetwayAction($2, $5); } /* { $$ = CreateSetGetwayAction(NULL, NULL); }*/
	|SET NAME CONNECT TO VAR set					{ $$ = CreateSetGetwayAction($2, $5); } /* { $$ = CreateSetGetwayAction(NULL,NULL); }*/
	;


connect: CONNECT VAR TO VAR 						{$$ = CreateConnectionAction($2, $4); } /* {$$ = CreateConnectionAction(NULL, NULL); }*/
	;

%%