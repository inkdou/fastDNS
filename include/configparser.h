/* A Bison parser, made by GNU Bison 2.6.1.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_CONFIGPARSER_H
# define YY_CONFIGPARSER_H
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     SPACE = 258,
     LETTER = 259,
     NEWLINE = 260,
     COMMENT = 261,
     COLON = 262,
     ANY = 263,
     ZONESTR = 264,
     STRING = 265,
     VAR_SERVER = 266,
     VAR_NAME = 267,
     VAR_IP_ADDRESS = 268,
     VAR_IP_TRANSPARENT = 269,
     VAR_DEBUG_MODE = 270,
     VAR_IP4_ONLY = 271,
     VAR_IP6_ONLY = 272,
     VAR_DATABASE = 273,
     VAR_IDENTITY = 274,
     VAR_NSID = 275,
     VAR_LOGFILE = 276,
     VAR_SERVER_COUNT = 277,
     VAR_TCP_COUNT = 278,
     VAR_PIDFILE = 279,
     VAR_PORT = 280,
     VAR_STATISTICS = 281,
     VAR_CHROOT = 282,
     VAR_USERNAME = 283,
     VAR_ZONESDIR = 284,
     VAR_XFRDFILE = 285,
     VAR_DIFFFILE = 286,
     VAR_XFRD_RELOAD_TIMEOUT = 287,
     VAR_TCP_QUERY_COUNT = 288,
     VAR_TCP_TIMEOUT = 289,
     VAR_IPV4_EDNS_SIZE = 290,
     VAR_IPV6_EDNS_SIZE = 291,
     VAR_DO_IP4 = 292,
     VAR_DO_IP6 = 293,
     VAR_ZONEFILE = 294,
     VAR_ZONE = 295,
     VAR_ALLOW_NOTIFY = 296,
     VAR_REQUEST_XFR = 297,
     VAR_NOTIFY = 298,
     VAR_PROVIDE_XFR = 299,
     VAR_NOTIFY_RETRY = 300,
     VAR_OUTGOING_INTERFACE = 301,
     VAR_ALLOW_AXFR_FALLBACK = 302,
     VAR_KEY = 303,
     VAR_ALGORITHM = 304,
     VAR_SECRET = 305,
     VAR_AXFR = 306,
     VAR_UDP = 307,
     VAR_VERBOSITY = 308,
     VAR_HIDE_VERSION = 309,
     VAR_PATTERN = 310,
     VAR_INCLUDEPATTERN = 311,
     VAR_ZONELISTFILE = 312,
     VAR_REMOTE_CONTROL = 313,
     VAR_CONTROL_ENABLE = 314,
     VAR_CONTROL_INTERFACE = 315,
     VAR_CONTROL_PORT = 316,
     VAR_SERVER_KEY_FILE = 317,
     VAR_SERVER_CERT_FILE = 318,
     VAR_CONTROL_KEY_FILE = 319,
     VAR_CONTROL_CERT_FILE = 320,
     VAR_XFRDIR = 321,
     VAR_RRL_SIZE = 322,
     VAR_RRL_RATELIMIT = 323,
     VAR_RRL_SLIP = 324,
     VAR_RRL_IPV4_PREFIX_LENGTH = 325,
     VAR_RRL_IPV6_PREFIX_LENGTH = 326,
     VAR_RRL_WHITELIST_RATELIMIT = 327,
     VAR_RRL_WHITELIST = 328,
     VAR_ZONEFILES_CHECK = 329
   };
#endif
/* Tokens.  */
#define SPACE 258
#define LETTER 259
#define NEWLINE 260
#define COMMENT 261
#define COLON 262
#define ANY 263
#define ZONESTR 264
#define STRING 265
#define VAR_SERVER 266
#define VAR_NAME 267
#define VAR_IP_ADDRESS 268
#define VAR_IP_TRANSPARENT 269
#define VAR_DEBUG_MODE 270
#define VAR_IP4_ONLY 271
#define VAR_IP6_ONLY 272
#define VAR_DATABASE 273
#define VAR_IDENTITY 274
#define VAR_NSID 275
#define VAR_LOGFILE 276
#define VAR_SERVER_COUNT 277
#define VAR_TCP_COUNT 278
#define VAR_PIDFILE 279
#define VAR_PORT 280
#define VAR_STATISTICS 281
#define VAR_CHROOT 282
#define VAR_USERNAME 283
#define VAR_ZONESDIR 284
#define VAR_XFRDFILE 285
#define VAR_DIFFFILE 286
#define VAR_XFRD_RELOAD_TIMEOUT 287
#define VAR_TCP_QUERY_COUNT 288
#define VAR_TCP_TIMEOUT 289
#define VAR_IPV4_EDNS_SIZE 290
#define VAR_IPV6_EDNS_SIZE 291
#define VAR_DO_IP4 292
#define VAR_DO_IP6 293
#define VAR_ZONEFILE 294
#define VAR_ZONE 295
#define VAR_ALLOW_NOTIFY 296
#define VAR_REQUEST_XFR 297
#define VAR_NOTIFY 298
#define VAR_PROVIDE_XFR 299
#define VAR_NOTIFY_RETRY 300
#define VAR_OUTGOING_INTERFACE 301
#define VAR_ALLOW_AXFR_FALLBACK 302
#define VAR_KEY 303
#define VAR_ALGORITHM 304
#define VAR_SECRET 305
#define VAR_AXFR 306
#define VAR_UDP 307
#define VAR_VERBOSITY 308
#define VAR_HIDE_VERSION 309
#define VAR_PATTERN 310
#define VAR_INCLUDEPATTERN 311
#define VAR_ZONELISTFILE 312
#define VAR_REMOTE_CONTROL 313
#define VAR_CONTROL_ENABLE 314
#define VAR_CONTROL_INTERFACE 315
#define VAR_CONTROL_PORT 316
#define VAR_SERVER_KEY_FILE 317
#define VAR_SERVER_CERT_FILE 318
#define VAR_CONTROL_KEY_FILE 319
#define VAR_CONTROL_CERT_FILE 320
#define VAR_XFRDIR 321
#define VAR_RRL_SIZE 322
#define VAR_RRL_RATELIMIT 323
#define VAR_RRL_SLIP 324
#define VAR_RRL_IPV4_PREFIX_LENGTH 325
#define VAR_RRL_IPV6_PREFIX_LENGTH 326
#define VAR_RRL_WHITELIST_RATELIMIT 327
#define VAR_RRL_WHITELIST 328
#define VAR_ZONEFILES_CHECK 329



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2049 of yacc.c  */
#line 42 "configparser.y"

	char*	str;


/* Line 2049 of yacc.c  */
#line 210 "configparser.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_CONFIGPARSER_H  */
