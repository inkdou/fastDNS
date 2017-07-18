/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 10 "/root/fastDNS/nsd/configparser.y" /* yacc.c:339  */

#include "config.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "options.h"
#include "util.h"
#include "dname.h"
#include "tsig.h"
#include "rrl.h"
#include "configyyrename.h"
int c_lex(void);
void c_error(const char *message);

#ifdef __cplusplus
extern "C"
#endif /* __cplusplus */

/* these need to be global, otherwise they cannot be used inside yacc */
extern config_parser_state_t* cfg_parser;

#if 1
#define OUTYY(s) printf s /* used ONLY when debugging */
#else
#define OUTYY(s)
#endif


#line 99 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 42 "/root/fastDNS/nsd/configparser.y" /* yacc.c:355  */

	char*	str;

#line 288 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 305 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   149

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  79
/* YYNRULES -- Number of rules.  */
#define YYNRULES  146
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  217

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   329

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    72,    72,    72,    73,    73,    74,    74,    75,    78,
      86,    86,    87,    87,    87,    87,    88,    88,    88,    88,
      88,    89,    89,    89,    89,    90,    90,    90,    90,    91,
      91,    91,    92,    92,    92,    93,    93,    93,    94,    94,
      95,    95,    95,    96,    96,    96,    97,    97,    97,    98,
     120,   128,   136,   144,   152,   164,   176,   184,   192,   198,
     204,   228,   234,   242,   250,   256,   262,   270,   276,   282,
     288,   294,   300,   306,   312,   320,   328,   336,   344,   352,
     362,   370,   380,   390,   400,   408,   417,   422,   423,   424,
     424,   424,   425,   425,   425,   426,   428,   436,   444,   454,
     460,   466,   472,   480,   514,   514,   515,   515,   516,   516,
     516,   517,   517,   517,   518,   518,   518,   519,   520,   532,
     543,   580,   580,   581,   581,   582,   602,   611,   622,   626,
     638,   651,   665,   678,   689,   700,   712,   723,   733,   745,
     745,   746,   746,   746,   747,   761,   772
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SPACE", "LETTER", "NEWLINE", "COMMENT",
  "COLON", "ANY", "ZONESTR", "STRING", "VAR_SERVER", "VAR_NAME",
  "VAR_IP_ADDRESS", "VAR_IP_TRANSPARENT", "VAR_DEBUG_MODE", "VAR_IP4_ONLY",
  "VAR_IP6_ONLY", "VAR_DATABASE", "VAR_IDENTITY", "VAR_NSID",
  "VAR_LOGFILE", "VAR_SERVER_COUNT", "VAR_TCP_COUNT", "VAR_PIDFILE",
  "VAR_PORT", "VAR_STATISTICS", "VAR_CHROOT", "VAR_USERNAME",
  "VAR_ZONESDIR", "VAR_XFRDFILE", "VAR_DIFFFILE",
  "VAR_XFRD_RELOAD_TIMEOUT", "VAR_TCP_QUERY_COUNT", "VAR_TCP_TIMEOUT",
  "VAR_IPV4_EDNS_SIZE", "VAR_IPV6_EDNS_SIZE", "VAR_DO_IP4", "VAR_DO_IP6",
  "VAR_ZONEFILE", "VAR_ZONE", "VAR_ALLOW_NOTIFY", "VAR_REQUEST_XFR",
  "VAR_NOTIFY", "VAR_PROVIDE_XFR", "VAR_NOTIFY_RETRY",
  "VAR_OUTGOING_INTERFACE", "VAR_ALLOW_AXFR_FALLBACK", "VAR_KEY",
  "VAR_ALGORITHM", "VAR_SECRET", "VAR_AXFR", "VAR_UDP", "VAR_VERBOSITY",
  "VAR_HIDE_VERSION", "VAR_PATTERN", "VAR_INCLUDEPATTERN",
  "VAR_ZONELISTFILE", "VAR_REMOTE_CONTROL", "VAR_CONTROL_ENABLE",
  "VAR_CONTROL_INTERFACE", "VAR_CONTROL_PORT", "VAR_SERVER_KEY_FILE",
  "VAR_SERVER_CERT_FILE", "VAR_CONTROL_KEY_FILE", "VAR_CONTROL_CERT_FILE",
  "VAR_XFRDIR", "VAR_RRL_SIZE", "VAR_RRL_RATELIMIT", "VAR_RRL_SLIP",
  "VAR_RRL_IPV4_PREFIX_LENGTH", "VAR_RRL_IPV6_PREFIX_LENGTH",
  "VAR_RRL_WHITELIST_RATELIMIT", "VAR_RRL_WHITELIST",
  "VAR_ZONEFILES_CHECK", "$accept", "toplevelvars", "toplevelvar",
  "serverstart", "contents_server", "content_server", "server_ip_address",
  "server_ip_transparent", "server_debug_mode", "server_verbosity",
  "server_hide_version", "server_ip4_only", "server_ip6_only",
  "server_do_ip4", "server_do_ip6", "server_database", "server_identity",
  "server_nsid", "server_logfile", "server_server_count",
  "server_tcp_count", "server_pidfile", "server_port", "server_statistics",
  "server_chroot", "server_username", "server_zonesdir",
  "server_zonelistfile", "server_xfrdir", "server_difffile",
  "server_xfrdfile", "server_xfrd_reload_timeout",
  "server_tcp_query_count", "server_tcp_timeout", "server_ipv4_edns_size",
  "server_ipv6_edns_size", "server_rrl_size", "server_rrl_ratelimit",
  "server_rrl_slip", "server_rrl_ipv4_prefix_length",
  "server_rrl_ipv6_prefix_length", "server_rrl_whitelist_ratelimit",
  "server_zonefiles_check", "rcstart", "contents_rc", "content_rc",
  "rc_control_enable", "rc_control_port", "rc_control_interface",
  "rc_server_key_file", "rc_server_cert_file", "rc_control_key_file",
  "rc_control_cert_file", "patternstart", "contents_pattern",
  "content_pattern", "zone_config_item", "pattern_name", "include_pattern",
  "zonestart", "contents_zone", "content_zone", "zone_name",
  "zone_zonefile", "zone_allow_notify", "zone_request_xfr",
  "zone_request_xfr_data", "zone_notify", "zone_notify_retry",
  "zone_provide_xfr", "zone_outgoing_interface",
  "zone_allow_axfr_fallback", "zone_rrl_whitelist", "keystart",
  "contents_key", "content_key", "key_name", "key_algorithm", "key_secret", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329
};
# endif

#define YYPACT_NINF -14

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-14)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -14,    74,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,
     -14,    21,    37,    22,   -13,    27,    16,    17,    19,    18,
      20,    25,    26,    28,    29,    33,    35,    21,   -14,   -14,
     -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,
     -14,    36,   -14,    37,   -14,   -14,    38,    40,    41,    22,
     -14,   -14,   -14,   -14,    42,    65,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   101,   102,   103,   105,   106,   107,   108,   109,   110,
     111,   113,   114,   115,   116,   117,   118,   120,   121,   123,
     124,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,
     -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,
     -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,
     -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   125,
     126,   127,   128,   129,   130,   131,   -14,   -14,   -14,   -14,
     -14,   -14,   -14,   -14,   -14,   -14,   132,   133,   134,   135,
     -14,   136,   137,   -14,   -14,   -14,   -14,   -14,   -14,   -14,
     -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,
     -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,
     -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,
     -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,
     -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,
     -14,   138,   139,   -14,   -14,   -14,   -14
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     9,   120,   138,   103,    86,     3,    11,
      88,     0,     0,     0,     4,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,   105,   107,
     106,   116,   108,   109,   110,   111,   112,   113,   114,   115,
     117,     0,   124,     5,   122,   123,     0,     0,     0,     6,
     140,   141,   142,   143,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    12,    13,    14,    36,    37,    15,    16,    47,
      48,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    38,    39,    29,    30,    31,    32,    33,
      34,    35,    40,    41,    42,    43,    44,    45,    46,     0,
       0,     0,     0,     0,     0,     0,    87,    89,    91,    90,
      92,    93,    94,    95,   118,   126,     0,     0,     0,     0,
     128,     0,     0,   133,   135,   136,   119,   137,   104,   125,
     121,   144,   145,   146,   139,    49,    50,    51,    54,    55,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    73,    72,    74,    75,    76,    77,    78,    56,
      57,    52,    53,    70,    71,    79,    80,    81,    82,    83,
      84,    85,    96,    98,    97,    99,   100,   101,   102,   127,
     129,     0,     0,   132,   134,   130,   131
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,
     -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,
     -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,
     -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,
     -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,
     -14,   -14,   -14,   -14,   -14,     4,    30,   -14,   -14,   -14,
     -14,   -11,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,
     -14,   -14,   -14,   -14,   -14,   -12,   -14,   -14,   -14
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     8,     9,    14,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    10,    15,   136,   137,   138,   139,   140,
     141,   142,   143,    11,    27,    28,    29,    30,    31,    12,
      43,    44,    45,    32,    33,    34,   150,    35,    36,    37,
      38,    39,    40,    13,    49,    50,    51,    52,    53
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,   144,   145,   147,   146,
     151,   158,   160,    16,    46,   152,   153,   164,   154,   155,
      80,    81,    42,   156,    82,   157,   159,     0,   161,    41,
     162,   163,   165,    83,    84,    85,    86,    87,    88,    89,
      17,    90,    18,    19,    20,    21,    22,    23,    24,   148,
     149,    47,    48,    42,     2,   166,    17,    25,    18,    19,
      20,    21,    22,    23,    24,     3,   129,   130,   131,   132,
     133,   134,   135,    25,    26,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
      26,   182,   183,   184,     4,   185,   186,   187,   188,   189,
     190,   191,     5,   192,   193,   194,   195,   196,   197,     6,
     198,   199,     7,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216
};

static const yytype_int8 yycheck[] =
{
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    10,    10,    10,    10,
      10,    27,    43,    12,    12,    10,    10,    49,    10,    10,
      53,    54,    12,    10,    57,    10,    10,    -1,    10,    12,
      10,    10,    10,    66,    67,    68,    69,    70,    71,    72,
      39,    74,    41,    42,    43,    44,    45,    46,    47,    51,
      52,    49,    50,    43,     0,    10,    39,    56,    41,    42,
      43,    44,    45,    46,    47,    11,    59,    60,    61,    62,
      63,    64,    65,    56,    73,    10,    10,    10,    10,    10,
      10,    10,    10,    10,    10,    10,    10,    10,    10,    10,
      73,    10,    10,    10,    40,    10,    10,    10,    10,    10,
      10,    10,    48,    10,    10,    10,    10,    10,    10,    55,
      10,    10,    58,    10,    10,    10,    10,    10,    10,    10,
      10,    10,    10,    10,    10,    10,    10,    10,    10,    10
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    76,     0,    11,    40,    48,    55,    58,    77,    78,
     118,   128,   134,   148,    79,   119,    12,    39,    41,    42,
      43,    44,    45,    46,    47,    56,    73,   129,   130,   131,
     132,   133,   138,   139,   140,   142,   143,   144,   145,   146,
     147,    12,   131,   135,   136,   137,    12,    49,    50,   149,
     150,   151,   152,   153,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      53,    54,    57,    66,    67,    68,    69,    70,    71,    72,
      74,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    59,
      60,    61,    62,    63,    64,    65,   120,   121,   122,   123,
     124,   125,   126,   127,    10,    10,    10,    10,    51,    52,
     141,    10,    10,    10,    10,    10,    10,    10,   130,    10,
     136,    10,    10,    10,   150,    10,    10,    10,    10,    10,
      10,    10,    10,    10,    10,    10,    10,    10,    10,    10,
      10,    10,    10,    10,    10,    10,    10,    10,    10,    10,
      10,    10,    10,    10,    10,    10,    10,    10,    10,    10,
      10,    10,    10,    10,    10,    10,    10,    10,    10,    10,
      10,    10,    10,    10,    10,    10,    10
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    75,    76,    76,    77,    77,    77,    77,    77,    78,
      79,    79,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   119,   120,
     120,   120,   120,   120,   120,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   129,   130,   130,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   132,   133,
     134,   135,   135,   136,   136,   137,   138,   139,   140,   141,
     141,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     149,   150,   150,   150,   151,   152,   153
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     2,     2,     1,
       2,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     0,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     2,     1,     1,     1,     2,     2,     3,     2,     2,
       3,     3,     3,     2,     3,     2,     2,     2,     1,     2,
       1,     1,     1,     1,     2,     2,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 9:
#line 79 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { OUTYY(("\nP(server:)\n")); 
		if(cfg_parser->server_settings_seen) {
			yyerror("duplicate server: element.");
		}
		cfg_parser->server_settings_seen = 1;
	}
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 99 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(server_ip_address:%s)\n", (yyvsp[0].str))); 
		if(cfg_parser->current_ip_address_option) {
			cfg_parser->current_ip_address_option->next = 
				(ip_address_option_t*)region_alloc(
				cfg_parser->opt->region, sizeof(ip_address_option_t));
			cfg_parser->current_ip_address_option = 
				cfg_parser->current_ip_address_option->next;
			cfg_parser->current_ip_address_option->next=0;
		} else {
			cfg_parser->current_ip_address_option = 
				(ip_address_option_t*)region_alloc(
				cfg_parser->opt->region, sizeof(ip_address_option_t));
			cfg_parser->current_ip_address_option->next=0;
			cfg_parser->opt->ip_addresses = cfg_parser->current_ip_address_option;
		}

		cfg_parser->current_ip_address_option->address = 
			region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
	}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 121 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(server_ip_transparent:%s)\n", (yyvsp[0].str))); 
		if(strcmp((yyvsp[0].str), "yes") != 0 && strcmp((yyvsp[0].str), "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->opt->ip_transparent = (strcmp((yyvsp[0].str), "yes")==0);
	}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 129 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(server_debug_mode:%s)\n", (yyvsp[0].str))); 
		if(strcmp((yyvsp[0].str), "yes") != 0 && strcmp((yyvsp[0].str), "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->opt->debug_mode = (strcmp((yyvsp[0].str), "yes")==0);
	}
#line 1626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 137 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(server_verbosity:%s)\n", (yyvsp[0].str))); 
		if(atoi((yyvsp[0].str)) == 0 && strcmp((yyvsp[0].str), "0") != 0)
			yyerror("number expected");
		else cfg_parser->opt->verbosity = atoi((yyvsp[0].str));
	}
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 145 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(server_hide_version:%s)\n", (yyvsp[0].str))); 
		if(strcmp((yyvsp[0].str), "yes") != 0 && strcmp((yyvsp[0].str), "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->opt->hide_version = (strcmp((yyvsp[0].str), "yes")==0);
	}
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 153 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		/* for backwards compatibility in config file with NSD3 */
		OUTYY(("P(server_ip4_only:%s)\n", (yyvsp[0].str))); 
		if(strcmp((yyvsp[0].str), "yes") != 0 && strcmp((yyvsp[0].str), "no") != 0)
			yyerror("expected yes or no.");
		else if(strcmp((yyvsp[0].str), "yes")==0) {
			cfg_parser->opt->do_ip4 = 1;
			cfg_parser->opt->do_ip6 = 0;
		}
	}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 165 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		/* for backwards compatibility in config file with NSD3 */
		OUTYY(("P(server_ip6_only:%s)\n", (yyvsp[0].str))); 
		if(strcmp((yyvsp[0].str), "yes") != 0 && strcmp((yyvsp[0].str), "no") != 0)
			yyerror("expected yes or no.");
		else if(strcmp((yyvsp[0].str), "yes")==0) {
			cfg_parser->opt->do_ip6 = 1;
			cfg_parser->opt->do_ip4 = 0;
		}
	}
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 177 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(server_do_ip4:%s)\n", (yyvsp[0].str))); 
		if(strcmp((yyvsp[0].str), "yes") != 0 && strcmp((yyvsp[0].str), "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->opt->do_ip4 = (strcmp((yyvsp[0].str), "yes")==0);
	}
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 185 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(server_do_ip6:%s)\n", (yyvsp[0].str))); 
		if(strcmp((yyvsp[0].str), "yes") != 0 && strcmp((yyvsp[0].str), "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->opt->do_ip6 = (strcmp((yyvsp[0].str), "yes")==0);
	}
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 193 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(server_database:%s)\n", (yyvsp[0].str))); 
		cfg_parser->opt->database = region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
	}
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 199 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(server_identity:%s)\n", (yyvsp[0].str))); 
		cfg_parser->opt->identity = region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
	}
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 205 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		unsigned char* nsid = 0;
		uint16_t nsid_len = 0;

		OUTYY(("P(server_nsid:%s)\n", (yyvsp[0].str)));

		if (strncasecmp((yyvsp[0].str), "ascii_", 6) == 0) {
			nsid_len = strlen((yyvsp[0].str)+6);
			cfg_parser->opt->nsid = region_alloc(cfg_parser->opt->region, nsid_len*2+1);
			hex_ntop((uint8_t*)(yyvsp[0].str)+6, nsid_len, (char*)cfg_parser->opt->nsid, nsid_len*2+1);
		} else if (strlen((yyvsp[0].str)) % 2 != 0) {
			yyerror("the NSID must be a hex string of an even length.");
		} else {
			nsid_len = strlen((yyvsp[0].str)) / 2;
			nsid = xalloc(nsid_len);
			if (hex_pton((yyvsp[0].str), nsid, nsid_len) == -1)
				yyerror("hex string cannot be parsed in NSID.");
			else
				cfg_parser->opt->nsid = region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
			free(nsid);
		}
	}
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 229 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(server_logfile:%s)\n", (yyvsp[0].str))); 
		cfg_parser->opt->logfile = region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
	}
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 235 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(server_server_count:%s)\n", (yyvsp[0].str))); 
		if(atoi((yyvsp[0].str)) <= 0)
			yyerror("number greater than zero expected");
		else cfg_parser->opt->server_count = atoi((yyvsp[0].str));
	}
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 243 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(server_tcp_count:%s)\n", (yyvsp[0].str))); 
		if(atoi((yyvsp[0].str)) <= 0)
			yyerror("number greater than zero expected");
		else cfg_parser->opt->tcp_count = atoi((yyvsp[0].str));
	}
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 251 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(server_pidfile:%s)\n", (yyvsp[0].str))); 
		cfg_parser->opt->pidfile = region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
	}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 257 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(server_port:%s)\n", (yyvsp[0].str))); 
		cfg_parser->opt->port = region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
	}
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 263 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(server_statistics:%s)\n", (yyvsp[0].str))); 
		if(atoi((yyvsp[0].str)) == 0 && strcmp((yyvsp[0].str), "0") != 0)
			yyerror("number expected");
		else cfg_parser->opt->statistics = atoi((yyvsp[0].str));
	}
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 271 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(server_chroot:%s)\n", (yyvsp[0].str))); 
		cfg_parser->opt->chroot = region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
	}
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 277 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(server_username:%s)\n", (yyvsp[0].str))); 
		cfg_parser->opt->username = region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
	}
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 283 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(server_zonesdir:%s)\n", (yyvsp[0].str))); 
		cfg_parser->opt->zonesdir = region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
	}
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 289 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(server_zonelistfile:%s)\n", (yyvsp[0].str))); 
		cfg_parser->opt->zonelistfile = region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
	}
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 295 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(server_xfrdir:%s)\n", (yyvsp[0].str))); 
		cfg_parser->opt->xfrdir = region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
	}
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 301 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(server_difffile:%s)\n", (yyvsp[0].str))); 
		/* ignore the value for backwards compatibility in config file*/
	}
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 307 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(server_xfrdfile:%s)\n", (yyvsp[0].str))); 
		cfg_parser->opt->xfrdfile = region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
	}
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 313 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(server_xfrd_reload_timeout:%s)\n", (yyvsp[0].str))); 
		if(atoi((yyvsp[0].str)) == 0 && strcmp((yyvsp[0].str), "0") != 0)
			yyerror("number expected");
		cfg_parser->opt->xfrd_reload_timeout = atoi((yyvsp[0].str));
	}
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 321 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(server_tcp_query_count:%s)\n", (yyvsp[0].str))); 
		if(atoi((yyvsp[0].str)) == 0 && strcmp((yyvsp[0].str), "0") != 0)
			yyerror("number expected");
		cfg_parser->opt->tcp_query_count = atoi((yyvsp[0].str));
	}
#line 1890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 329 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(server_tcp_timeout:%s)\n", (yyvsp[0].str))); 
		if(atoi((yyvsp[0].str)) == 0 && strcmp((yyvsp[0].str), "0") != 0)
			yyerror("number expected");
		cfg_parser->opt->tcp_timeout = atoi((yyvsp[0].str));
	}
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 337 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(server_ipv4_edns_size:%s)\n", (yyvsp[0].str))); 
		if(atoi((yyvsp[0].str)) == 0 && strcmp((yyvsp[0].str), "0") != 0)
			yyerror("number expected");
		cfg_parser->opt->ipv4_edns_size = atoi((yyvsp[0].str));
	}
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 345 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(server_ipv6_edns_size:%s)\n", (yyvsp[0].str))); 
		if(atoi((yyvsp[0].str)) == 0 && strcmp((yyvsp[0].str), "0") != 0)
			yyerror("number expected");
		cfg_parser->opt->ipv6_edns_size = atoi((yyvsp[0].str));
	}
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 353 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(server_rrl_size:%s)\n", (yyvsp[0].str))); 
#ifdef RATELIMIT
		if(atoi((yyvsp[0].str)) <= 0)
			yyerror("number greater than zero expected");
		cfg_parser->opt->rrl_size = atoi((yyvsp[0].str));
#endif
	}
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 363 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(server_rrl_ratelimit:%s)\n", (yyvsp[0].str))); 
#ifdef RATELIMIT
		cfg_parser->opt->rrl_ratelimit = atoi((yyvsp[0].str));
#endif
	}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 371 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(server_rrl_slip:%s)\n", (yyvsp[0].str))); 
#ifdef RATELIMIT
		if(atoi((yyvsp[0].str)) < 0)
			yyerror("number equal or greater than zero expected");
		cfg_parser->opt->rrl_slip = atoi((yyvsp[0].str));
#endif
	}
#line 1960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 381 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    {
		OUTYY(("P(server_rrl_ipv4_prefix_length:%s)\n", (yyvsp[0].str))); 
#ifdef RATELIMIT
		if(atoi((yyvsp[0].str)) < 0 || atoi((yyvsp[0].str)) > 32)
			yyerror("invalid IPv4 prefix length");
		cfg_parser->opt->rrl_ipv4_prefix_length = atoi((yyvsp[0].str));
#endif
	}
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 391 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    {
		OUTYY(("P(server_rrl_ipv6_prefix_length:%s)\n", (yyvsp[0].str))); 
#ifdef RATELIMIT
		if(atoi((yyvsp[0].str)) < 0 || atoi((yyvsp[0].str)) > 64)
			yyerror("invalid IPv6 prefix length");
		cfg_parser->opt->rrl_ipv6_prefix_length = atoi((yyvsp[0].str));
#endif
	}
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 401 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(server_rrl_whitelist_ratelimit:%s)\n", (yyvsp[0].str))); 
#ifdef RATELIMIT
		cfg_parser->opt->rrl_whitelist_ratelimit = atoi((yyvsp[0].str));
#endif
	}
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 409 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(server_zonefiles_check:%s)\n", (yyvsp[0].str))); 
		if(strcmp((yyvsp[0].str), "yes") != 0 && strcmp((yyvsp[0].str), "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->opt->zonefiles_check = (strcmp((yyvsp[0].str), "yes")==0);
	}
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 418 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    {
		OUTYY(("\nP(remote-control:)\n"));
	}
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 429 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    {
		OUTYY(("P(control_enable:%s)\n", (yyvsp[0].str)));
		if(strcmp((yyvsp[0].str), "yes") != 0 && strcmp((yyvsp[0].str), "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->opt->control_enable = (strcmp((yyvsp[0].str), "yes")==0);
	}
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 437 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    {
		OUTYY(("P(control_port:%s)\n", (yyvsp[0].str)));
		if(atoi((yyvsp[0].str)) == 0)
			yyerror("control port number expected");
		else cfg_parser->opt->control_port = atoi((yyvsp[0].str));
	}
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 445 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    {
		ip_address_option_t* o = (ip_address_option_t*)region_alloc(
			cfg_parser->opt->region, sizeof(ip_address_option_t));
		OUTYY(("P(control_interface:%s)\n", (yyvsp[0].str)));
		o->next = cfg_parser->opt->control_interface;
		cfg_parser->opt->control_interface = o;
		o->address = region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
	}
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 455 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    {
	OUTYY(("P(rc_server_key_file:%s)\n", (yyvsp[0].str)));
	cfg_parser->opt->server_key_file = region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
	}
#line 2060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 461 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    {
	OUTYY(("P(rc_server_cert_file:%s)\n", (yyvsp[0].str)));
	cfg_parser->opt->server_cert_file = region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
	}
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 467 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    {
	OUTYY(("P(rc_control_key_file:%s)\n", (yyvsp[0].str)));
	cfg_parser->opt->control_key_file = region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
	}
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 473 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    {
	OUTYY(("P(rc_control_cert_file:%s)\n", (yyvsp[0].str)));
	cfg_parser->opt->control_cert_file = region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
	}
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 481 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("\nP(pattern:)\n")); 
		if(cfg_parser->current_zone) {
			if(!cfg_parser->current_zone->name) 
				c_error("previous zone has no name");
			else {
				if(!nsd_options_insert_zone(cfg_parser->opt, 
					cfg_parser->current_zone))
					c_error("duplicate zone");
			}
			if(!cfg_parser->current_zone->pattern) 
				c_error("previous zone has no pattern");
			cfg_parser->current_zone = NULL;
		}
		if(cfg_parser->current_pattern) {
			if(!cfg_parser->current_pattern->pname) 
				c_error("previous pattern has no name");
			else {
				if(!nsd_options_insert_pattern(cfg_parser->opt, 
					cfg_parser->current_pattern))
					c_error_msg("duplicate pattern %s",
						cfg_parser->current_pattern->pname);
			}
		}
		cfg_parser->current_pattern = pattern_options_create(
			cfg_parser->opt->region);
		cfg_parser->current_allow_notify = 0;
		cfg_parser->current_request_xfr = 0;
		cfg_parser->current_notify = 0;
		cfg_parser->current_provide_xfr = 0;
		cfg_parser->current_outgoing_interface = 0;
	}
#line 2124 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 521 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(pattern_name:%s)\n", (yyvsp[0].str))); 
#ifndef NDEBUG
		assert(cfg_parser->current_pattern);
#endif
		if(strchr((yyvsp[0].str), ' '))
			c_error_msg("space is not allowed in pattern name: "
				"'%s'", (yyvsp[0].str));
		cfg_parser->current_pattern->pname = region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
	}
#line 2139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 533 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    {
		OUTYY(("P(include-pattern:%s)\n", (yyvsp[0].str))); 
#ifndef NDEBUG
		assert(cfg_parser->current_pattern);
#endif
		config_apply_pattern((yyvsp[0].str));
	}
#line 2151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 544 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("\nP(zone:)\n")); 
		if(cfg_parser->current_zone) {
			if(!cfg_parser->current_zone->name) 
				c_error("previous zone has no name");
			else {
				if(!nsd_options_insert_zone(cfg_parser->opt, 
					cfg_parser->current_zone))
					c_error("duplicate zone");
			}
			if(!cfg_parser->current_zone->pattern) 
				c_error("previous zone has no pattern");
		}
		if(cfg_parser->current_pattern) {
			if(!cfg_parser->current_pattern->pname) 
				c_error("previous pattern has no name");
			else {
				if(!nsd_options_insert_pattern(cfg_parser->opt, 
					cfg_parser->current_pattern))
					c_error_msg("duplicate pattern %s",
						cfg_parser->current_pattern->pname);
			}
		}
		cfg_parser->current_zone = zone_options_create(cfg_parser->opt->region);
		cfg_parser->current_zone->part_of_config = 1;
		cfg_parser->current_pattern = pattern_options_create(
			cfg_parser->opt->region);
		cfg_parser->current_pattern->implicit = 1;
		cfg_parser->current_zone->pattern = cfg_parser->current_pattern;
		cfg_parser->current_allow_notify = 0;
		cfg_parser->current_request_xfr = 0;
		cfg_parser->current_notify = 0;
		cfg_parser->current_provide_xfr = 0;
		cfg_parser->current_outgoing_interface = 0;
	}
#line 2191 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 583 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		char* s;
		OUTYY(("P(zone_name:%s)\n", (yyvsp[0].str))); 
#ifndef NDEBUG
		assert(cfg_parser->current_zone);
		assert(cfg_parser->current_pattern);
#endif
		cfg_parser->current_zone->name = region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
		s = (char*)region_alloc(cfg_parser->opt->region,
			strlen((yyvsp[0].str))+strlen(PATTERN_IMPLICIT_MARKER)+1);
		memmove(s, PATTERN_IMPLICIT_MARKER,
			strlen(PATTERN_IMPLICIT_MARKER));
		memmove(s+strlen(PATTERN_IMPLICIT_MARKER), (yyvsp[0].str), strlen((yyvsp[0].str))+1);
		if(pattern_options_find(cfg_parser->opt, s))
			c_error_msg("zone %s cannot be created because "
				"implicit pattern %s already exists", (yyvsp[0].str), s);
		cfg_parser->current_pattern->pname = s;
	}
#line 2214 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 603 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(zonefile:%s)\n", (yyvsp[0].str))); 
#ifndef NDEBUG
		assert(cfg_parser->current_pattern);
#endif
		cfg_parser->current_pattern->zonefile = region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
	}
#line 2226 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 612 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		acl_options_t* acl = parse_acl_info(cfg_parser->opt->region, (yyvsp[-1].str), (yyvsp[0].str));
		OUTYY(("P(allow_notify:%s %s)\n", (yyvsp[-1].str), (yyvsp[0].str))); 
		if(cfg_parser->current_allow_notify)
			cfg_parser->current_allow_notify->next = acl;
		else
			cfg_parser->current_pattern->allow_notify = acl;
		cfg_parser->current_allow_notify = acl;
	}
#line 2240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 623 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    {
	}
#line 2247 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 627 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		acl_options_t* acl = parse_acl_info(cfg_parser->opt->region, (yyvsp[-1].str), (yyvsp[0].str));
		OUTYY(("P(request_xfr:%s %s)\n", (yyvsp[-1].str), (yyvsp[0].str))); 
		if(acl->blocked) c_error("blocked address used for request-xfr");
		if(acl->rangetype!=acl_range_single) c_error("address range used for request-xfr");
		if(cfg_parser->current_request_xfr)
			cfg_parser->current_request_xfr->next = acl;
		else
			cfg_parser->current_pattern->request_xfr = acl;
		cfg_parser->current_request_xfr = acl;
	}
#line 2263 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 639 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		acl_options_t* acl = parse_acl_info(cfg_parser->opt->region, (yyvsp[-1].str), (yyvsp[0].str));
		acl->use_axfr_only = 1;
		OUTYY(("P(request_xfr:%s %s)\n", (yyvsp[-1].str), (yyvsp[0].str))); 
		if(acl->blocked) c_error("blocked address used for request-xfr");
		if(acl->rangetype!=acl_range_single) c_error("address range used for request-xfr");
		if(cfg_parser->current_request_xfr)
			cfg_parser->current_request_xfr->next = acl;
		else
			cfg_parser->current_pattern->request_xfr = acl;
		cfg_parser->current_request_xfr = acl;
	}
#line 2280 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 652 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		acl_options_t* acl = parse_acl_info(cfg_parser->opt->region, (yyvsp[-1].str), (yyvsp[0].str));
		acl->allow_udp = 1;
		OUTYY(("P(request_xfr:%s %s)\n", (yyvsp[-1].str), (yyvsp[0].str))); 
		if(acl->blocked) c_error("blocked address used for request-xfr");
		if(acl->rangetype!=acl_range_single) c_error("address range used for request-xfr");
		if(cfg_parser->current_request_xfr)
			cfg_parser->current_request_xfr->next = acl;
		else
			cfg_parser->current_pattern->request_xfr = acl;
		cfg_parser->current_request_xfr = acl;
	}
#line 2297 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 666 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		acl_options_t* acl = parse_acl_info(cfg_parser->opt->region, (yyvsp[-1].str), (yyvsp[0].str));
		OUTYY(("P(notify:%s %s)\n", (yyvsp[-1].str), (yyvsp[0].str))); 
		if(acl->blocked) c_error("blocked address used for notify");
		if(acl->rangetype!=acl_range_single) c_error("address range used for notify");
		if(cfg_parser->current_notify)
			cfg_parser->current_notify->next = acl;
		else
			cfg_parser->current_pattern->notify = acl;
		cfg_parser->current_notify = acl;
	}
#line 2313 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 679 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(notify_retry:%s)\n", (yyvsp[0].str))); 
		if(atoi((yyvsp[0].str)) == 0 && strcmp((yyvsp[0].str), "0") != 0)
			yyerror("number expected");
		else {
			cfg_parser->current_pattern->notify_retry = atoi((yyvsp[0].str));
			cfg_parser->current_pattern->notify_retry_is_default=0;
		}
	}
#line 2327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 690 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		acl_options_t* acl = parse_acl_info(cfg_parser->opt->region, (yyvsp[-1].str), (yyvsp[0].str));
		OUTYY(("P(provide_xfr:%s %s)\n", (yyvsp[-1].str), (yyvsp[0].str))); 
		if(cfg_parser->current_provide_xfr)
			cfg_parser->current_provide_xfr->next = acl;
		else
			cfg_parser->current_pattern->provide_xfr = acl;
		cfg_parser->current_provide_xfr = acl;
	}
#line 2341 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 701 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		acl_options_t* acl = parse_acl_info(cfg_parser->opt->region, (yyvsp[0].str), "NOKEY");
		OUTYY(("P(outgoing_interface:%s)\n", (yyvsp[0].str))); 
		if(acl->rangetype!=acl_range_single) c_error("address range used for outgoing interface");
		if(cfg_parser->current_outgoing_interface)
			cfg_parser->current_outgoing_interface->next = acl;
		else
			cfg_parser->current_pattern->outgoing_interface = acl;
		cfg_parser->current_outgoing_interface = acl;
	}
#line 2356 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 713 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(allow_axfr_fallback:%s)\n", (yyvsp[0].str))); 
		if(strcmp((yyvsp[0].str), "yes") != 0 && strcmp((yyvsp[0].str), "no") != 0)
			yyerror("expected yes or no.");
		else {
			cfg_parser->current_pattern->allow_axfr_fallback = (strcmp((yyvsp[0].str), "yes")==0);
			cfg_parser->current_pattern->allow_axfr_fallback_is_default = 0;
		}
	}
#line 2370 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 724 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(zone_rrl_whitelist:%s)\n", (yyvsp[0].str))); 
#ifdef RATELIMIT
		cfg_parser->current_pattern->rrl_whitelist |= rrlstr2type((yyvsp[0].str));
#endif
	}
#line 2381 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 734 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("\nP(key:)\n")); 
		if(cfg_parser->current_key) {
			if(!cfg_parser->current_key->name) c_error("previous key has no name");
			if(!cfg_parser->current_key->algorithm) c_error("previous key has no algorithm");
			if(!cfg_parser->current_key->secret) c_error("previous key has no secret blob");
			key_options_insert(cfg_parser->opt, cfg_parser->current_key);
		}
		cfg_parser->current_key = key_options_create(cfg_parser->opt->region);
	}
#line 2396 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 748 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		const dname_type* d;
		OUTYY(("P(key_name:%s)\n", (yyvsp[0].str))); 
#ifndef NDEBUG
		assert(cfg_parser->current_key);
#endif
		cfg_parser->current_key->name = region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
		d = dname_parse(cfg_parser->opt->region, (yyvsp[0].str));
		if(!d)	c_error_msg("Failed to parse tsig key name %s", (yyvsp[0].str));
		else	region_recycle(cfg_parser->opt->region, (void*)d,
				dname_total_size(d));
	}
#line 2413 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 762 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		OUTYY(("P(key_algorithm:%s)\n", (yyvsp[0].str))); 
#ifndef NDEBUG
		assert(cfg_parser->current_key);
#endif
		cfg_parser->current_key->algorithm = region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
		if(tsig_get_algorithm_by_name((yyvsp[0].str)) == NULL)
			c_error_msg("Bad tsig algorithm %s", (yyvsp[0].str));
	}
#line 2427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 773 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1646  */
    { 
		uint8_t data[16384];
		int size;
		OUTYY(("key_secret:%s)\n", (yyvsp[0].str))); 
#ifndef NDEBUG
		assert(cfg_parser->current_key);
#endif
		cfg_parser->current_key->secret = region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
		size = b64_pton((yyvsp[0].str), data, sizeof(data));
		if(size == -1) {
			c_error_msg("Cannot base64 decode tsig secret %s",
				cfg_parser->current_key->name?
				cfg_parser->current_key->name:"");
		} else if(size != 0) {
			memset(data, 0xdd, size); /* wipe secret */
		}
	}
#line 2449 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2453 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 792 "/root/fastDNS/nsd/configparser.y" /* yacc.c:1906  */


/* parse helper routines could be here */
