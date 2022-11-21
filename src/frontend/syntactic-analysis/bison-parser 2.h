/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     START = 258,
     END = 259,
     GRAPH_ID = 260,
     POOL = 261,
     LANE = 262,
     CREATE = 263,
     EVENT = 264,
     ACTIVITY = 265,
     GATEWAY = 266,
     CONNECT = 267,
     CONNECT_TO = 268,
     CURLY_BRACES_OPEN = 269,
     CURLY_BRACES_CLOSE = 270,
     ARTIFACT = 271,
     AS = 272,
     TO = 273,
     SET = 274,
     NAME = 275,
     EVENT_TYPE = 276,
     ARTIFACT_TYPE = 277,
     VAR = 278
   };
#endif
/* Tokens.  */
#define START 258
#define END 259
#define GRAPH_ID 260
#define POOL 261
#define LANE 262
#define CREATE 263
#define EVENT 264
#define ACTIVITY 265
#define GATEWAY 266
#define CONNECT 267
#define CONNECT_TO 268
#define CURLY_BRACES_OPEN 269
#define CURLY_BRACES_CLOSE 270
#define ARTIFACT 271
#define AS 272
#define TO 273
#define SET 274
#define NAME 275
#define EVENT_TYPE 276
#define ARTIFACT_TYPE 277
#define VAR 278




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 13 "../src/frontend/syntactic-analysis/bison-grammar.y"
{
	
	Program  program;
	Expression * expression;
	Create * create;
	CreateP * createp;
	Graph * graph;
	Pool * pool;
	Gateway * gateway;
	Set * set;
	Lane * lane;
	Connect * connect;

	char * string;
	int token;
	int integer;
}
/* Line 1529 of yacc.c.  */
#line 113 "../src/frontend/syntactic-analysis/bison-parser.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

