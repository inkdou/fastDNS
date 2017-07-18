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
#line 1 "/root/fastDNS/nsd/zparser.y" /* yacc.c:339  */

/*
 * zyparser.y -- yacc grammar for (DNS) zone files
 *
 * Copyright (c) 2001-2006, NLnet Labs. All rights reserved.
 *
 * See LICENSE for the license.
 *
 */

#include "config.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "dname.h"
#include "namedb.h"
#include "zonec.h"

/* these need to be global, otherwise they cannot be used inside yacc */
zparser_type *parser;

#ifdef __cplusplus
extern "C"
#endif /* __cplusplus */
int yywrap(void);

/* this hold the nxt bits */
static uint8_t nxtbits[16];
static int dlv_warn = 1;

/* 256 windows of 256 bits (32 bytes) */
/* still need to reset the bastard somewhere */
static uint8_t nsecbits[NSEC_WINDOW_COUNT][NSEC_WINDOW_BITS_SIZE];

/* hold the highest rcode seen in a NSEC rdata , BUG #106 */
uint16_t nsec_highest_rcode;

void yyerror(const char *message);

#ifdef NSEC3
/* parse nsec3 parameters and add the (first) rdata elements */
static void
nsec3_add_params(const char* hash_algo_str, const char* flag_str,
	const char* iter_str, const char* salt_str, int salt_len);
#endif /* NSEC3 */


#line 116 "y.tab.c" /* yacc.c:339  */

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
    T_A = 258,
    T_NS = 259,
    T_MX = 260,
    T_TXT = 261,
    T_CNAME = 262,
    T_AAAA = 263,
    T_PTR = 264,
    T_NXT = 265,
    T_KEY = 266,
    T_SOA = 267,
    T_SIG = 268,
    T_SRV = 269,
    T_CERT = 270,
    T_LOC = 271,
    T_MD = 272,
    T_MF = 273,
    T_MB = 274,
    T_MG = 275,
    T_MR = 276,
    T_NULL = 277,
    T_WKS = 278,
    T_HINFO = 279,
    T_MINFO = 280,
    T_RP = 281,
    T_AFSDB = 282,
    T_X25 = 283,
    T_ISDN = 284,
    T_RT = 285,
    T_NSAP = 286,
    T_NSAP_PTR = 287,
    T_PX = 288,
    T_GPOS = 289,
    T_EID = 290,
    T_NIMLOC = 291,
    T_ATMA = 292,
    T_NAPTR = 293,
    T_KX = 294,
    T_A6 = 295,
    T_DNAME = 296,
    T_SINK = 297,
    T_OPT = 298,
    T_APL = 299,
    T_UINFO = 300,
    T_UID = 301,
    T_GID = 302,
    T_UNSPEC = 303,
    T_TKEY = 304,
    T_TSIG = 305,
    T_IXFR = 306,
    T_AXFR = 307,
    T_MAILB = 308,
    T_MAILA = 309,
    T_DS = 310,
    T_DLV = 311,
    T_SSHFP = 312,
    T_RRSIG = 313,
    T_NSEC = 314,
    T_DNSKEY = 315,
    T_SPF = 316,
    T_NSEC3 = 317,
    T_IPSECKEY = 318,
    T_DHCID = 319,
    T_NSEC3PARAM = 320,
    T_TLSA = 321,
    T_NID = 322,
    T_L32 = 323,
    T_L64 = 324,
    T_LP = 325,
    T_EUI48 = 326,
    T_EUI64 = 327,
    T_CAA = 328,
    DOLLAR_TTL = 329,
    DOLLAR_ORIGIN = 330,
    NL = 331,
    SP = 332,
    STR = 333,
    PREV = 334,
    BITLAB = 335,
    T_TTL = 336,
    T_RRCLASS = 337,
    URR = 338,
    T_UTYPE = 339
  };
#endif
/* Tokens.  */
#define T_A 258
#define T_NS 259
#define T_MX 260
#define T_TXT 261
#define T_CNAME 262
#define T_AAAA 263
#define T_PTR 264
#define T_NXT 265
#define T_KEY 266
#define T_SOA 267
#define T_SIG 268
#define T_SRV 269
#define T_CERT 270
#define T_LOC 271
#define T_MD 272
#define T_MF 273
#define T_MB 274
#define T_MG 275
#define T_MR 276
#define T_NULL 277
#define T_WKS 278
#define T_HINFO 279
#define T_MINFO 280
#define T_RP 281
#define T_AFSDB 282
#define T_X25 283
#define T_ISDN 284
#define T_RT 285
#define T_NSAP 286
#define T_NSAP_PTR 287
#define T_PX 288
#define T_GPOS 289
#define T_EID 290
#define T_NIMLOC 291
#define T_ATMA 292
#define T_NAPTR 293
#define T_KX 294
#define T_A6 295
#define T_DNAME 296
#define T_SINK 297
#define T_OPT 298
#define T_APL 299
#define T_UINFO 300
#define T_UID 301
#define T_GID 302
#define T_UNSPEC 303
#define T_TKEY 304
#define T_TSIG 305
#define T_IXFR 306
#define T_AXFR 307
#define T_MAILB 308
#define T_MAILA 309
#define T_DS 310
#define T_DLV 311
#define T_SSHFP 312
#define T_RRSIG 313
#define T_NSEC 314
#define T_DNSKEY 315
#define T_SPF 316
#define T_NSEC3 317
#define T_IPSECKEY 318
#define T_DHCID 319
#define T_NSEC3PARAM 320
#define T_TLSA 321
#define T_NID 322
#define T_L32 323
#define T_L64 324
#define T_LP 325
#define T_EUI48 326
#define T_EUI64 327
#define T_CAA 328
#define DOLLAR_TTL 329
#define DOLLAR_ORIGIN 330
#define NL 331
#define SP 332
#define STR 333
#define PREV 334
#define BITLAB 335
#define T_TTL 336
#define T_RRCLASS 337
#define URR 338
#define T_UTYPE 339

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 50 "/root/fastDNS/nsd/zparser.y" /* yacc.c:355  */

	domain_type	 *domain;
	const dname_type *dname;
	struct lex_data	  data;
	uint32_t	  ttl;
	uint16_t	  klass;
	uint16_t	  type;
	uint16_t	 *unknown;

#line 331 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 348 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   867

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  71
/* YYNRULES -- Number of rules.  */
#define YYNRULES  218
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  538

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   339

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
       2,     2,     2,     2,     2,     2,    85,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    86,     2,     2,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    91,    91,    92,    95,    96,    97,    98,   102,   106,
     126,   130,   131,   134,   135,   138,   148,   154,   160,   167,
     172,   179,   183,   188,   193,   198,   205,   206,   224,   228,
     232,   242,   256,   263,   264,   282,   283,   286,   294,   306,
     323,   324,   341,   345,   355,   356,   361,   370,   382,   391,
     402,   405,   408,   422,   423,   430,   431,   447,   448,   463,
     464,   469,   479,   497,   498,   499,   500,   501,   502,   507,
     508,   514,   515,   516,   517,   518,   519,   525,   526,   527,
     528,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     630,   636,   643,   656,   663,   670,   678,   685,   692,   700,
     708,   715,   719,   727,   735,   747,   755,   761,   767,   775,
     785,   797,   805,   815,   818,   822,   828,   837,   846,   854,
     860,   875,   885,   900,   910,   919,   928,   962,   966,   970,
     977,   984,   991,   998,  1004,  1011,  1019,  1025,  1029
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_A", "T_NS", "T_MX", "T_TXT",
  "T_CNAME", "T_AAAA", "T_PTR", "T_NXT", "T_KEY", "T_SOA", "T_SIG",
  "T_SRV", "T_CERT", "T_LOC", "T_MD", "T_MF", "T_MB", "T_MG", "T_MR",
  "T_NULL", "T_WKS", "T_HINFO", "T_MINFO", "T_RP", "T_AFSDB", "T_X25",
  "T_ISDN", "T_RT", "T_NSAP", "T_NSAP_PTR", "T_PX", "T_GPOS", "T_EID",
  "T_NIMLOC", "T_ATMA", "T_NAPTR", "T_KX", "T_A6", "T_DNAME", "T_SINK",
  "T_OPT", "T_APL", "T_UINFO", "T_UID", "T_GID", "T_UNSPEC", "T_TKEY",
  "T_TSIG", "T_IXFR", "T_AXFR", "T_MAILB", "T_MAILA", "T_DS", "T_DLV",
  "T_SSHFP", "T_RRSIG", "T_NSEC", "T_DNSKEY", "T_SPF", "T_NSEC3",
  "T_IPSECKEY", "T_DHCID", "T_NSEC3PARAM", "T_TLSA", "T_NID", "T_L32",
  "T_L64", "T_LP", "T_EUI48", "T_EUI64", "T_CAA", "DOLLAR_TTL",
  "DOLLAR_ORIGIN", "NL", "SP", "STR", "PREV", "BITLAB", "T_TTL",
  "T_RRCLASS", "URR", "T_UTYPE", "'.'", "'@'", "$accept", "lines", "line",
  "sp", "trail", "ttl_directive", "origin_directive", "rr", "owner",
  "classttl", "dname", "abs_dname", "label", "rel_dname", "wire_dname",
  "wire_abs_dname", "wire_label", "wire_rel_dname", "str_seq",
  "concatenated_str_seq", "nxt_seq", "nsec_more", "nsec_seq", "str_sp_seq",
  "str_dot_seq", "dotted_str", "type_and_rdata", "rdata_a",
  "rdata_domain_name", "rdata_soa", "rdata_wks", "rdata_hinfo",
  "rdata_minfo", "rdata_mx", "rdata_txt", "rdata_rp", "rdata_afsdb",
  "rdata_x25", "rdata_isdn", "rdata_rt", "rdata_nsap", "rdata_px",
  "rdata_aaaa", "rdata_loc", "rdata_nxt", "rdata_srv", "rdata_naptr",
  "rdata_kx", "rdata_cert", "rdata_apl", "rdata_apl_seq", "rdata_ds",
  "rdata_dlv", "rdata_sshfp", "rdata_dhcid", "rdata_rrsig", "rdata_nsec",
  "rdata_nsec3", "rdata_nsec3_param", "rdata_tlsa", "rdata_dnskey",
  "rdata_ipsec_base", "rdata_ipseckey", "rdata_nid", "rdata_l32",
  "rdata_l64", "rdata_lp", "rdata_eui48", "rdata_eui64", "rdata_caa",
  "rdata_unknown", YY_NULLPTR
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
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,    46,    64
};
# endif

#define YYPACT_NINF -408

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-408)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -408,   101,  -408,   -70,    15,    15,  -408,  -408,  -408,    19,
    -408,  -408,  -408,  -408,   -68,  -408,  -408,  -408,   268,    15,
    -408,  -408,    34,  -408,   261,    40,  -408,  -408,  -408,    15,
      15,   729,    58,    84,   283,   283,    37,   -72,   -44,    15,
      15,    15,    15,    15,    15,    15,    15,    15,    15,    15,
      15,    15,    15,    15,    15,    15,    15,    15,    15,    15,
      15,    15,    15,    15,    15,    15,    15,    15,    15,    15,
      15,   283,    15,    15,    15,    15,    15,    15,    15,    15,
      15,    15,    15,    15,    15,    15,    15,    15,    15,    15,
      15,   139,    15,  -408,  -408,  -408,   299,  -408,  -408,  -408,
      15,    15,    65,   -61,   -51,   -47,   -61,    65,   -61,   -61,
      20,   -61,    76,   106,   129,    80,   -61,   -61,   -61,   -61,
     -61,    65,   131,   -61,   -61,   133,   142,   145,   157,   161,
     164,   174,   182,   -61,    51,  -408,   185,   192,   199,    76,
     115,    20,   -47,   210,   213,   222,   225,   232,   234,   236,
     243,   245,   247,   254,   257,    73,    33,  -408,    58,    58,
    -408,    13,  -408,    54,  -408,  -408,   283,  -408,  -408,    15,
    -408,  -408,  -408,   283,  -408,  -408,  -408,  -408,    54,  -408,
    -408,  -408,  -408,    15,  -408,  -408,    15,  -408,  -408,    15,
    -408,  -408,    15,  -408,  -408,    15,  -408,  -408,    15,  -408,
    -408,  -408,  -408,    56,  -408,  -408,  -408,  -408,  -408,  -408,
    -408,  -408,  -408,  -408,  -408,  -408,   -62,  -408,  -408,    15,
    -408,  -408,    15,  -408,  -408,    15,  -408,  -408,    15,  -408,
    -408,   283,  -408,  -408,   283,  -408,  -408,    15,  -408,  -408,
    -408,    61,  -408,  -408,    15,  -408,  -408,    15,  -408,  -408,
      15,  -408,  -408,  -408,  -408,    88,  -408,   283,  -408,    15,
    -408,  -408,    15,  -408,  -408,    15,  -408,  -408,  -408,  -408,
    -408,  -408,   303,  -408,  -408,   105,  -408,  -408,  -408,  -408,
    -408,  -408,    15,  -408,  -408,    15,   283,  -408,  -408,  -408,
     283,  -408,  -408,    15,  -408,  -408,    15,  -408,  -408,    15,
    -408,  -408,    15,  -408,  -408,    15,  -408,  -408,    15,  -408,
    -408,   283,  -408,  -408,   283,  -408,  -408,    15,  -408,  -408,
    -408,  -408,   123,   304,   126,  -408,  -408,    40,    93,  -408,
    -408,   315,   317,    40,   319,   324,   329,   135,   202,  -408,
     331,   340,    40,    40,    40,  -408,   269,  -408,    40,   148,
    -408,    40,   342,    40,   -65,  -408,   345,   347,   350,  -408,
     278,  -408,   151,   353,   355,   286,  -408,   289,  -408,   357,
     360,    67,    67,    67,    40,  -408,  -408,   364,  -408,   283,
    -408,   283,  -408,  -408,   283,    15,    15,    15,    15,    15,
    -408,  -408,    15,   283,   283,   283,   283,   283,   283,  -408,
      15,    15,   283,    88,    15,    15,    15,  -408,   278,   303,
    -408,  -408,    15,    15,   283,  -408,    15,    15,    54,    54,
      54,   283,    15,   286,  -408,  -408,   293,  -408,   366,   368,
     370,   372,   376,    89,  -408,  -408,  -408,  -408,  -408,  -408,
      40,   378,  -408,   397,   399,   401,  -408,  -408,   405,   409,
    -408,   411,   413,  -408,  -408,  -408,  -408,   424,   283,  -408,
      15,    15,    15,    15,    15,    56,   283,    15,    15,    15,
     283,    15,    15,    15,    15,   283,  -408,   401,   427,   430,
      40,   401,  -408,  -408,   433,   401,   401,  -408,   435,    67,
     441,   401,  -408,   283,    15,    15,   283,   283,    15,   283,
     283,    15,    88,   283,   283,  -408,   443,   448,  -408,  -408,
     450,  -408,  -408,   454,  -408,  -408,    15,    15,    15,   303,
     459,   461,    40,  -408,    15,    15,   283,   463,   465,  -408,
     283,    15,  -408,   118,    15,   401,   283,  -408
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     4,    11,    31,    20,
      32,    28,    29,     3,     0,     7,     8,     9,    21,     0,
      26,    33,    27,    10,     0,     0,     6,     5,    12,     0,
       0,     0,    19,    30,     0,     0,     0,    23,    22,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,    34,    13,     0,    15,    16,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   133,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    14,    24,    25,
      59,     0,    60,     0,    63,    64,     0,    65,    66,     0,
      89,    90,    42,     0,    91,    92,    71,    72,     0,   117,
     118,    83,    84,     0,   121,   122,     0,   113,   114,     0,
      73,    74,     0,   111,   112,     0,   123,   124,     0,   129,
     130,    44,    45,     0,   119,   120,    67,    68,    69,    70,
      75,    76,    77,    78,    79,    80,     0,    81,    82,     0,
      85,    86,     0,    87,    88,     0,    95,    96,     0,    97,
      98,     0,    99,   100,     0,   101,   102,     0,   107,   108,
      57,     0,   109,   110,     0,   115,   116,     0,   125,   126,
       0,   127,   128,   131,   132,   194,   134,     0,   135,     0,
     136,   137,     0,   138,   139,     0,   140,   141,   142,   143,
      39,    37,     0,    35,    40,    36,   144,   145,   150,   151,
      93,    94,     0,   146,   147,     0,     0,   103,   104,    55,
       0,   105,   106,     0,   148,   149,     0,   152,   153,     0,
     154,   155,     0,   156,   157,     0,   158,   159,     0,   160,
     161,     0,   162,   163,     0,   164,   165,     0,   166,   167,
     169,   168,     0,     0,    61,   170,   171,     0,     0,   177,
     186,     0,     0,     0,     0,     0,     0,     0,     0,   187,
       0,     0,     0,     0,     0,   180,     0,   181,     0,     0,
     184,     0,     0,     0,     0,   193,     0,     0,     0,    53,
       0,   201,    38,     0,     0,     0,   208,     0,   199,     0,
       0,     0,     0,     0,     0,   213,   214,     0,   218,     0,
      62,     0,    43,    48,     0,     0,     0,     0,     0,     0,
      47,    46,     0,     0,     0,     0,     0,     0,     0,    58,
       0,     0,     0,   195,     0,     0,     0,    51,     0,     0,
      54,    41,     0,     0,     0,    56,     0,     0,     0,     0,
       0,     0,     0,     0,   217,   176,     0,   188,     0,     0,
       0,     0,     0,     0,   174,   175,   178,   179,   182,   183,
       0,     0,   191,     0,     0,     0,    50,    52,     0,     0,
     207,     0,     0,   209,   210,   211,   212,     0,     0,    49,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   216,     0,     0,     0,
       0,     0,   173,   185,     0,     0,     0,   198,     0,     0,
       0,     0,   215,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   206,     0,     0,   205,     0,     0,   189,   192,
       0,   196,   197,     0,   203,   204,     0,     0,     0,     0,
       0,     0,     0,   202,     0,     0,     0,     0,     0,   190,
       0,     0,   172,     0,     0,     0,     0,   200
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -408,  -408,  -408,    -1,   195,  -408,  -408,  -408,  -408,  -408,
       0,   176,   184,   207,  -296,  -408,  -117,  -408,  -408,  -185,
    -408,  -158,  -407,  -330,  -408,  -100,  -408,  -408,   -12,  -408,
    -408,  -408,  -408,  -408,   111,  -408,  -408,  -408,  -408,  -408,
    -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,
    -408,  -408,  -408,  -408,  -408,   116,  -408,  -408,  -408,  -408,
     153,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,
     711
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    13,    96,    97,    15,    16,    17,    18,    31,
     166,    20,    21,    22,   272,   273,   274,   275,   173,   203,
     384,   410,   361,   290,   241,   163,    93,   164,   167,   190,
     217,   220,   223,   170,   174,   226,   229,   232,   235,   238,
     242,   245,   179,   204,   184,   196,   248,   251,   199,   256,
     257,   260,   263,   266,   291,   193,   276,   283,   294,   297,
     187,   286,   287,   300,   303,   306,   309,   312,   315,   318,
     165
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      14,    19,   447,    24,    25,    28,    23,   178,    27,    28,
     100,   157,    28,   160,   322,     7,    28,     8,    32,    10,
     162,   216,   161,   324,    11,    12,    28,   169,    37,    38,
      28,   172,   161,    28,   255,   414,   161,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
       7,   156,     7,   458,   176,    26,   181,    28,   186,   158,
     159,     2,     3,   161,   206,   208,   210,   212,   214,   183,
      28,   189,   523,    95,     7,   470,   161,    28,     8,    33,
      10,   253,    33,   222,   225,    11,    12,   157,    28,   160,
      95,     7,    95,     7,   161,    28,   162,    95,     7,   324,
     155,   337,    28,   160,    28,   160,   349,   493,   161,   320,
     162,   497,   162,    28,   192,   499,   500,    28,   201,   161,
     323,   504,     8,   161,    10,   202,    28,   201,   327,   157,
      28,   382,   328,   324,   202,     4,     5,     6,     7,     8,
       9,    10,   331,    28,   195,   332,    11,    12,   333,   161,
     362,   334,    28,   270,   335,    28,   270,   336,   161,   378,
     271,    35,   338,   271,   380,   536,    28,   198,    28,   219,
      28,   228,   161,   390,   161,   340,   161,    94,   341,    28,
     231,   342,    28,   234,   343,   161,   399,   344,   161,   270,
      98,    99,    36,   346,    28,   237,   348,   534,    28,   240,
     161,    28,   244,   351,   161,   411,   352,   161,   465,   353,
     446,    28,   247,   280,   403,   268,   354,   161,   356,    28,
     250,   357,    28,   259,   358,   161,   135,     0,   161,    28,
     262,   418,   419,   420,     0,   161,    28,   265,   157,    28,
     391,   363,   161,     0,   364,   365,     0,    28,   282,   367,
      28,   285,   369,   161,   278,   370,   161,     0,   371,    28,
     289,   372,    28,   293,   373,   161,     0,   374,   161,    28,
     296,    28,   299,    28,   302,   161,   377,   161,     0,   161,
      28,   305,    28,   308,    28,   311,   161,   381,   161,     0,
     161,    28,   314,   386,    28,   317,     0,   161,    28,    34,
     161,     0,   394,   395,   396,   157,    28,   397,   398,    29,
      30,   400,     0,   402,   407,   408,   409,     0,   325,    95,
       7,   326,   157,    28,   289,   157,    28,   415,   329,   157,
      28,   459,     0,   330,   421,   157,    28,     0,   423,   359,
     360,    28,   379,   426,   428,   429,   430,   431,   432,   502,
       0,   433,    28,   383,    28,   385,    28,   387,   339,   440,
     441,    28,   388,   443,   444,   445,    28,   389,    28,   392,
       0,   448,   449,   367,     0,   451,   452,    28,   393,    28,
     401,   457,    28,   404,    28,   405,   345,    28,   406,   347,
      28,   412,    28,   413,    28,   416,   350,    28,   417,     0,
     466,    28,   422,    28,   460,    28,   461,    28,   462,    28,
     463,     0,   355,    28,   464,    28,   467,   367,     0,   477,
     478,   479,   480,   481,   338,     0,   484,   485,   486,   367,
     488,   489,   490,   491,    28,   468,    28,   469,    28,   289,
     496,   366,    28,   471,     0,   368,    28,   472,    28,   473,
      28,   474,   367,   506,   507,     0,   367,   510,   367,   367,
     513,    28,   475,   367,    28,   494,   375,    28,   495,   376,
      28,   498,    28,   501,     0,   520,   521,   522,    28,   503,
      28,   516,   526,   527,   528,    28,   517,    28,   518,     0,
     533,    28,   519,   535,     0,   367,    28,   524,    28,   525,
      28,   530,    28,   531,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   424,     0,   425,     0,     0,   427,
       0,     0,     0,     0,     0,     0,     0,     0,   434,   435,
     436,   437,   438,   439,     0,     0,     0,   442,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   450,
       0,     0,     0,   453,   454,   455,   456,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   476,     0,     0,     0,     0,     0,     0,
     482,   483,     0,     0,     0,   487,     0,     0,     0,     0,
     492,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   505,     0,
       0,   508,   509,     0,   511,   512,     0,     0,   514,   515,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   529,     0,     0,     0,   532,     0,     0,     0,     0,
       0,   537,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,     0,    58,    59,    60,    61,    62,    63,    64,    65,
      66,     0,    67,     0,     0,     0,     0,    68,    69,     0,
      70,     0,     0,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,     0,     0,     0,     0,    91,     0,     0,
       0,     0,     0,    92,   168,   171,   175,   177,   180,   182,
     185,   188,   191,   194,   197,   200,   205,   207,   209,   211,
     213,   215,   218,   221,   224,   227,   230,   233,   236,   239,
     243,   246,   249,   252,   254,   258,     0,   261,   264,   267,
     269,   277,   279,   281,   284,   288,   292,   295,   298,   301,
     304,   307,   310,   313,   316,   319,     0,   321
};

static const yytype_int16 yycheck[] =
{
       1,     1,   409,     4,     5,    77,    76,   107,    76,    77,
      82,    76,    77,    78,     1,    77,    77,    78,    19,    80,
      85,   121,    83,    85,    85,    86,    77,    78,    29,    30,
      77,    78,    83,    77,   134,   365,    83,    81,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      77,    92,    77,   423,   106,    76,   108,    77,    78,   100,
     101,     0,     1,    83,   116,   117,   118,   119,   120,   109,
      77,   111,   519,    76,    77,   445,    83,    77,    78,    85,
      80,   133,    85,   123,   124,    85,    86,    76,    77,    78,
      76,    77,    76,    77,    83,    77,    85,    76,    77,    85,
       1,    85,    77,    78,    77,    78,    85,   477,    83,    76,
      85,   481,    85,    77,    78,   485,   486,    77,    78,    83,
     161,   491,    78,    83,    80,    85,    77,    78,   169,    76,
      77,    78,   173,    85,    85,    74,    75,    76,    77,    78,
      79,    80,   183,    77,    78,   186,    85,    86,   189,    83,
      85,   192,    77,    78,   195,    77,    78,   198,    83,    76,
      85,    25,   203,    85,    78,   535,    77,    78,    77,    78,
      77,    78,    83,    78,    83,   216,    83,    33,   219,    77,
      78,   222,    77,    78,   225,    83,    78,   228,    83,    78,
      35,    36,    25,   234,    77,    78,   237,   533,    77,    78,
      83,    77,    78,   244,    83,   362,   247,    83,   433,   250,
     408,    77,    78,   142,   354,   139,   257,    83,   259,    77,
      78,   262,    77,    78,   265,    83,    71,    -1,    83,    77,
      78,   371,   372,   373,    -1,    83,    77,    78,    76,    77,
      78,   282,    83,    -1,   285,   286,    -1,    77,    78,   290,
      77,    78,   293,    83,   141,   296,    83,    -1,   299,    77,
      78,   302,    77,    78,   305,    83,    -1,   308,    83,    77,
      78,    77,    78,    77,    78,    83,   317,    83,    -1,    83,
      77,    78,    77,    78,    77,    78,    83,   327,    83,    -1,
      83,    77,    78,   333,    77,    78,    -1,    83,    77,    78,
      83,    -1,   342,   343,   344,    76,    77,    78,   348,    81,
      82,   351,    -1,   353,    76,    77,    78,    -1,   163,    76,
      77,   166,    76,    77,    78,    76,    77,    78,   173,    76,
      77,    78,    -1,   178,   374,    76,    77,    -1,   379,    76,
      77,    77,    78,   384,   385,   386,   387,   388,   389,   489,
      -1,   392,    77,    78,    77,    78,    77,    78,   203,   400,
     401,    77,    78,   404,   405,   406,    77,    78,    77,    78,
      -1,   412,   413,   414,    -1,   416,   417,    77,    78,    77,
      78,   422,    77,    78,    77,    78,   231,    77,    78,   234,
      77,    78,    77,    78,    77,    78,   241,    77,    78,    -1,
     440,    77,    78,    77,    78,    77,    78,    77,    78,    77,
      78,    -1,   257,    77,    78,    77,    78,   458,    -1,   460,
     461,   462,   463,   464,   465,    -1,   467,   468,   469,   470,
     471,   472,   473,   474,    77,    78,    77,    78,    77,    78,
     480,   286,    77,    78,    -1,   290,    77,    78,    77,    78,
      77,    78,   493,   494,   495,    -1,   497,   498,   499,   500,
     501,    77,    78,   504,    77,    78,   311,    77,    78,   314,
      77,    78,    77,    78,    -1,   516,   517,   518,    77,    78,
      77,    78,   522,   524,   525,    77,    78,    77,    78,    -1,
     531,    77,    78,   534,    -1,   536,    77,    78,    77,    78,
      77,    78,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   379,    -1,   381,    -1,    -1,   384,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   393,   394,
     395,   396,   397,   398,    -1,    -1,    -1,   402,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   414,
      -1,    -1,    -1,   418,   419,   420,   421,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   458,    -1,    -1,    -1,    -1,    -1,    -1,
     465,   466,    -1,    -1,    -1,   470,    -1,    -1,    -1,    -1,
     475,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   493,    -1,
      -1,   496,   497,    -1,   499,   500,    -1,    -1,   503,   504,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   526,    -1,    -1,    -1,   530,    -1,    -1,    -1,    -1,
      -1,   536,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    -1,    33,    -1,    -1,    -1,    -1,    38,    39,    -1,
      41,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,    78,    -1,    -1,
      -1,    -1,    -1,    84,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,    -1,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,   156
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    88,     0,     1,    74,    75,    76,    77,    78,    79,
      80,    85,    86,    89,    90,    92,    93,    94,    95,    97,
      98,    99,   100,    76,    90,    90,    76,    76,    77,    81,
      82,    96,    90,    85,    78,    98,   100,    90,    90,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    33,    38,    39,
      41,    44,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    78,    84,   113,    99,    76,    90,    91,    91,    91,
      82,    81,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    91,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,     1,    90,    76,    90,    90,
      78,    83,    85,   112,   114,   157,    97,   115,   157,    78,
     120,   157,    78,   105,   121,   157,   115,   157,   112,   129,
     157,   115,   157,    97,   131,   157,    78,   147,   157,    97,
     116,   157,    78,   142,   157,    78,   132,   157,    78,   135,
     157,    78,    85,   106,   130,   157,   115,   157,   115,   157,
     115,   157,   115,   157,   115,   157,   112,   117,   157,    78,
     118,   157,    97,   119,   157,    97,   122,   157,    78,   123,
     157,    78,   124,   157,    78,   125,   157,    78,   126,   157,
      78,   111,   127,   157,    78,   128,   157,    78,   133,   157,
      78,   134,   157,   115,   157,   112,   136,   137,   157,    78,
     138,   157,    78,   139,   157,    78,   140,   157,   142,   157,
      78,    85,   101,   102,   103,   104,   143,   157,   147,   157,
     121,   157,    78,   144,   157,    78,   148,   149,   157,    78,
     110,   141,   157,    78,   145,   157,    78,   146,   157,    78,
     150,   157,    78,   151,   157,    78,   152,   157,    78,   153,
     157,    78,   154,   157,    78,   155,   157,    78,   156,   157,
      76,   157,     1,    90,    85,    91,    91,    90,    90,    91,
      91,    90,    90,    90,    90,    90,    90,    85,    90,    91,
      90,    90,    90,    90,    90,    91,    90,    91,    90,    85,
      91,    90,    90,    90,    90,    91,    90,    90,    90,    76,
      77,   109,    85,    90,    90,    90,    91,    90,    91,    90,
      90,    90,    90,    90,    90,    91,    91,    90,    76,    78,
      78,    97,    78,    78,   107,    78,    97,    78,    78,    78,
      78,    78,    78,    78,    97,    97,    97,    78,    97,    78,
      97,    78,    97,   112,    78,    78,    78,    76,    77,    78,
     108,   103,    78,    78,   110,    78,    78,    78,   112,   112,
     112,    97,    78,    90,    91,    91,    90,    91,    90,    90,
      90,    90,    90,    90,    91,    91,    91,    91,    91,    91,
      90,    90,    91,    90,    90,    90,   108,   109,    90,    90,
      91,    90,    90,    91,    91,    91,    91,    90,   110,    78,
      78,    78,    78,    78,    78,   106,    97,    78,    78,    78,
     110,    78,    78,    78,    78,    78,    91,    90,    90,    90,
      90,    90,    91,    91,    90,    90,    90,    91,    90,    90,
      90,    90,    91,   110,    78,    78,    97,   110,    78,   110,
     110,    78,   112,    78,   110,    91,    90,    90,    91,    91,
      90,    91,    91,    90,    91,    91,    78,    78,    78,    78,
      90,    90,    90,   109,    78,    78,    97,    90,    90,    91,
      78,    78,    91,    90,   101,    90,   110,    91
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    87,    88,    88,    89,    89,    89,    89,    89,    89,
      89,    90,    90,    91,    91,    92,    93,    93,    94,    95,
      95,    96,    96,    96,    96,    96,    97,    97,    98,    98,
      98,    99,    99,   100,   100,   101,   101,   102,   102,   103,
     104,   104,   105,   105,   106,   106,   106,   106,   107,   107,
     108,   108,   108,   109,   109,   110,   110,   111,   111,   112,
     112,   112,   112,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   157,   157
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     2,     1,     1,     1,
       2,     1,     2,     1,     2,     4,     4,     4,     3,     2,
       1,     0,     2,     2,     4,     4,     1,     1,     1,     1,
       2,     1,     1,     1,     3,     1,     1,     1,     2,     1,
       1,     3,     1,     3,     1,     1,     3,     3,     1,     3,
       2,     1,     2,     1,     2,     1,     3,     1,     3,     1,
       1,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,    14,     6,     4,     4,     4,     2,     4,     4,
       2,     2,     4,     4,     2,     6,     2,     2,     4,     8,
      12,     4,     8,     2,     1,     3,     8,     8,     6,     2,
      18,     2,    10,     8,     8,     8,     7,     4,     2,     4,
       4,     4,     4,     2,     2,     6,     6,     4,     3
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
        case 6:
#line 97 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 99 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    parser->error_occurred = 0;
    }
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 103 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    parser->error_occurred = 0;
    }
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 107 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {	/* rr should be fully parsed */
	    if (!parser->error_occurred) {
			    parser->current_rr.rdatas
				    = (rdata_atom_type *) region_alloc_init(
					    parser->region,
					    parser->current_rr.rdatas,
					    (parser->current_rr.rdata_count
					     * sizeof(rdata_atom_type)));

			    process_rr();
	    }

	    region_free_all(parser->rr_region);

	    parser->current_rr.type = 0;
	    parser->current_rr.rdata_count = 0;
	    parser->current_rr.rdatas = parser->temporary_rdatas;
	    parser->error_occurred = 0;
    }
#line 1903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 139 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    parser->default_ttl = zparser_ttl2int((yyvsp[-1].data).str, &(parser->error_occurred));
	    if (parser->error_occurred == 1) {
		    parser->default_ttl = DEFAULT_TTL;
			parser->error_occurred = 0;
	    }
    }
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 149 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    /* if previous origin is unused, remove it, do not leak it */
	    domain_table_deldomain(parser->db, parser->origin);
	    parser->origin = (yyvsp[-1].domain);
    }
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 155 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zc_error_prev_line("$ORIGIN directive requires absolute domain name");
    }
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 161 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    parser->current_rr.owner = (yyvsp[-2].domain);
	    parser->current_rr.type = (yyvsp[0].type);
    }
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 168 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    parser->prev_dname = (yyvsp[-1].domain);
	    (yyval.domain) = (yyvsp[-1].domain);
    }
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 173 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    (yyval.domain) = parser->prev_dname;
    }
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 179 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    parser->current_rr.ttl = parser->default_ttl;
	    parser->current_rr.klass = parser->default_class;
    }
#line 1968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 184 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    parser->current_rr.ttl = parser->default_ttl;
	    parser->current_rr.klass = (yyvsp[-1].klass);
    }
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 189 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    parser->current_rr.ttl = (yyvsp[-1].ttl);
	    parser->current_rr.klass = parser->default_class;
    }
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 194 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    parser->current_rr.ttl = (yyvsp[-3].ttl);
	    parser->current_rr.klass = (yyvsp[-1].klass);
    }
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 199 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    parser->current_rr.ttl = (yyvsp[-1].ttl);
	    parser->current_rr.klass = (yyvsp[-3].klass);
    }
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 207 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    if ((yyvsp[0].dname) == error_dname) {
		    (yyval.domain) = error_domain;
	    } else if ((yyvsp[0].dname)->name_size + domain_dname(parser->origin)->name_size - 1 > MAXDOMAINLEN) {
		    zc_error("domain name exceeds %d character limit", MAXDOMAINLEN);
		    (yyval.domain) = error_domain;
	    } else {
		    (yyval.domain) = domain_table_insert(
			    parser->db->domains,
			    dname_concatenate(
				    parser->rr_region,
				    (yyvsp[0].dname),
				    domain_dname(parser->origin)));
	    }
    }
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 225 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    (yyval.domain) = parser->db->domains->root;
    }
#line 2032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 229 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    (yyval.domain) = parser->origin;
    }
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 233 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    if ((yyvsp[-1].dname) != error_dname) {
		    (yyval.domain) = domain_table_insert(parser->db->domains, (yyvsp[-1].dname));
	    } else {
		    (yyval.domain) = error_domain;
	    }
    }
#line 2052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 243 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    if ((yyvsp[0].data).len > MAXLABELLEN) {
		    zc_error("label exceeds %d character limit", MAXLABELLEN);
		    (yyval.dname) = error_dname;
	    } else if ((yyvsp[0].data).len <= 0) {
		    zc_error("zero label length");
		    (yyval.dname) = error_dname;
	    } else {
		    (yyval.dname) = dname_make_from_label(parser->rr_region,
					       (uint8_t *) (yyvsp[0].data).str,
					       (yyvsp[0].data).len);
	    }
    }
#line 2070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 257 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zc_error("bitlabels are now deprecated. RFC2673 is obsoleted.");
	    (yyval.dname) = error_dname;
    }
#line 2079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 265 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    if ((yyvsp[-2].dname) == error_dname || (yyvsp[0].dname) == error_dname) {
		    (yyval.dname) = error_dname;
	    } else if ((yyvsp[-2].dname)->name_size + (yyvsp[0].dname)->name_size - 1 > MAXDOMAINLEN) {
		    zc_error("domain name exceeds %d character limit",
			     MAXDOMAINLEN);
		    (yyval.dname) = error_dname;
	    } else {
		    (yyval.dname) = dname_concatenate(parser->rr_region, (yyvsp[-2].dname), (yyvsp[0].dname));
	    }
    }
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 287 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    char *result = (char *) region_alloc(parser->rr_region, 2);
	    result[0] = 0;
	    result[1] = '\0';
	    (yyval.data).str = result;
	    (yyval.data).len = 1;
    }
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 295 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    char *result = (char *) region_alloc(parser->rr_region,
						 (yyvsp[-1].data).len + 2);
	    memcpy(result, (yyvsp[-1].data).str, (yyvsp[-1].data).len);
	    result[(yyvsp[-1].data).len] = 0;
	    result[(yyvsp[-1].data).len+1] = '\0';
	    (yyval.data).str = result;
	    (yyval.data).len = (yyvsp[-1].data).len + 1;
    }
#line 2121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 307 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    char *result = (char *) region_alloc(parser->rr_region,
						 (yyvsp[0].data).len + 1);

	    if ((yyvsp[0].data).len > MAXLABELLEN)
		    zc_error("label exceeds %d character limit", MAXLABELLEN);

	    /* make label anyway */
	    result[0] = (yyvsp[0].data).len;
	    memcpy(result+1, (yyvsp[0].data).str, (yyvsp[0].data).len);

	    (yyval.data).str = result;
	    (yyval.data).len = (yyvsp[0].data).len + 1;
    }
#line 2140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 325 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    if ((yyvsp[-2].data).len + (yyvsp[0].data).len - 3 > MAXDOMAINLEN)
		    zc_error("domain name exceeds %d character limit",
			     MAXDOMAINLEN);

	    /* make dname anyway */
	    (yyval.data).len = (yyvsp[-2].data).len + (yyvsp[0].data).len;
	    (yyval.data).str = (char *) region_alloc(parser->rr_region, (yyval.data).len + 1);
	    memcpy((yyval.data).str, (yyvsp[-2].data).str, (yyvsp[-2].data).len);
	    memcpy((yyval.data).str + (yyvsp[-2].data).len, (yyvsp[0].data).str, (yyvsp[0].data).len);
	    (yyval.data).str[(yyval.data).len] = '\0';
    }
#line 2157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 342 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zadd_rdata_txt_wireformat(zparser_conv_text(parser->rr_region, (yyvsp[0].data).str, (yyvsp[0].data).len), 1);
    }
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 346 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zadd_rdata_txt_wireformat(zparser_conv_text(parser->rr_region, (yyvsp[0].data).str, (yyvsp[0].data).len), 0);
    }
#line 2173 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 357 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    (yyval.data).len = 1;
	    (yyval.data).str = region_strdup(parser->rr_region, ".");
    }
#line 2182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 362 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    (yyval.data).len = (yyvsp[-2].data).len + (yyvsp[0].data).len + 1;
	    (yyval.data).str = (char *) region_alloc(parser->rr_region, (yyval.data).len + 1);
	    memcpy((yyval.data).str, (yyvsp[-2].data).str, (yyvsp[-2].data).len);
	    memcpy((yyval.data).str + (yyvsp[-2].data).len, " ", 1);
	    memcpy((yyval.data).str + (yyvsp[-2].data).len + 1, (yyvsp[0].data).str, (yyvsp[0].data).len);
	    (yyval.data).str[(yyval.data).len] = '\0';
    }
#line 2195 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 371 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    (yyval.data).len = (yyvsp[-2].data).len + (yyvsp[0].data).len + 1;
	    (yyval.data).str = (char *) region_alloc(parser->rr_region, (yyval.data).len + 1);
	    memcpy((yyval.data).str, (yyvsp[-2].data).str, (yyvsp[-2].data).len);
	    memcpy((yyval.data).str + (yyvsp[-2].data).len, ".", 1);
	    memcpy((yyval.data).str + (yyvsp[-2].data).len + 1, (yyvsp[0].data).str, (yyvsp[0].data).len);
	    (yyval.data).str[(yyval.data).len] = '\0';
    }
#line 2208 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 383 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    uint16_t type = rrtype_from_string((yyvsp[0].data).str);
	    if (type != 0 && type < 128) {
		    set_bit(nxtbits, type);
	    } else {
		    zc_error("bad type %d in NXT record", (int) type);
	    }
    }
#line 2221 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 392 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    uint16_t type = rrtype_from_string((yyvsp[0].data).str);
	    if (type != 0 && type < 128) {
		    set_bit(nxtbits, type);
	    } else {
		    zc_error("bad type %d in NXT record", (int) type);
	    }
    }
#line 2234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 403 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
    }
#line 2241 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 406 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
    }
#line 2248 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 409 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    uint16_t type = rrtype_from_string((yyvsp[-1].data).str);
	    if (type != 0) {
                    if (type > nsec_highest_rcode) {
                            nsec_highest_rcode = type;
                    }
		    set_bitnsec(nsecbits, type);
	    } else {
		    zc_error("bad type %d in NSEC record", (int) type);
	    }
    }
#line 2264 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 432 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    char *result = (char *) region_alloc(parser->rr_region,
						 (yyvsp[-2].data).len + (yyvsp[0].data).len + 1);
	    memcpy(result, (yyvsp[-2].data).str, (yyvsp[-2].data).len);
	    memcpy(result + (yyvsp[-2].data).len, (yyvsp[0].data).str, (yyvsp[0].data).len);
	    (yyval.data).str = result;
	    (yyval.data).len = (yyvsp[-2].data).len + (yyvsp[0].data).len;
	    (yyval.data).str[(yyval.data).len] = '\0';
    }
#line 2278 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 449 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    char *result = (char *) region_alloc(parser->rr_region,
						 (yyvsp[-2].data).len + (yyvsp[0].data).len + 1);
	    memcpy(result, (yyvsp[-2].data).str, (yyvsp[-2].data).len);
	    memcpy(result + (yyvsp[-2].data).len, (yyvsp[0].data).str, (yyvsp[0].data).len);
	    (yyval.data).str = result;
	    (yyval.data).len = (yyvsp[-2].data).len + (yyvsp[0].data).len;
	    (yyval.data).str[(yyval.data).len] = '\0';
    }
#line 2292 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 465 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	(yyval.data).str = ".";
	(yyval.data).len = 1;
    }
#line 2301 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 470 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    char *result = (char *) region_alloc(parser->rr_region,
						 (yyvsp[-1].data).len + 2);
	    memcpy(result, (yyvsp[-1].data).str, (yyvsp[-1].data).len);
	    result[(yyvsp[-1].data).len] = '.';
	    (yyval.data).str = result;
	    (yyval.data).len = (yyvsp[-1].data).len + 1;
	    (yyval.data).str[(yyval.data).len] = '\0';
    }
#line 2315 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 480 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    char *result = (char *) region_alloc(parser->rr_region,
						 (yyvsp[-2].data).len + (yyvsp[0].data).len + 2);
	    memcpy(result, (yyvsp[-2].data).str, (yyvsp[-2].data).len);
	    result[(yyvsp[-2].data).len] = '.';
	    memcpy(result + (yyvsp[-2].data).len + 1, (yyvsp[0].data).str, (yyvsp[0].data).len);
	    (yyval.data).str = result;
	    (yyval.data).len = (yyvsp[-2].data).len + (yyvsp[0].data).len + 1;
	    (yyval.data).str[(yyval.data).len] = '\0';
    }
#line 2330 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 498 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2336 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 500 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2342 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 501 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { zc_warning_prev_line("MD is obsolete"); }
#line 2348 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 503 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zc_warning_prev_line("MD is obsolete");
	    (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown));
    }
#line 2357 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 507 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { zc_warning_prev_line("MF is obsolete"); }
#line 2363 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 509 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zc_warning_prev_line("MF is obsolete");
	    (yyval.type) = (yyvsp[-2].type);
	    parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown));
    }
#line 2373 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 515 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2379 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 517 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2385 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 518 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { zc_warning_prev_line("MB is obsolete"); }
#line 2391 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 520 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zc_warning_prev_line("MB is obsolete");
	    (yyval.type) = (yyvsp[-2].type);
	    parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown));
    }
#line 2401 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 526 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2407 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 528 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2413 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 531 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2419 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 533 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2425 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 535 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 537 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2437 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 539 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 541 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 543 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2455 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 545 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2461 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 547 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2467 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 549 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 551 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 553 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 555 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 557 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 559 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 561 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 563 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 565 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 567 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 569 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 571 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 573 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 575 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 577 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 579 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 581 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 584 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 586 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 587 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { if (dlv_warn) { dlv_warn = 0; zc_warning_prev_line("DLV is experimental"); } }
#line 2587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 588 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { if (dlv_warn) { dlv_warn = 0; zc_warning_prev_line("DLV is experimental"); } (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 590 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 592 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 594 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 596 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 598 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 600 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 602 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 604 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 606 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 608 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 610 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 612 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 614 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 616 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 617 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 619 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zc_error_prev_line("unrecognized RR type '%s'", (yyvsp[-2].data).str);
    }
#line 2691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 631 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zadd_rdata_wireformat(zparser_conv_a(parser->region, (yyvsp[-1].data).str));
    }
#line 2699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 637 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    /* convert a single dname record */
	    zadd_rdata_domain((yyvsp[-1].domain));
    }
#line 2708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 644 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    /* convert the soa data */
	    zadd_rdata_domain((yyvsp[-13].domain));	/* prim. ns */
	    zadd_rdata_domain((yyvsp[-11].domain));	/* email */
	    zadd_rdata_wireformat(zparser_conv_serial(parser->region, (yyvsp[-9].data).str)); /* serial */
	    zadd_rdata_wireformat(zparser_conv_period(parser->region, (yyvsp[-7].data).str)); /* refresh */
	    zadd_rdata_wireformat(zparser_conv_period(parser->region, (yyvsp[-5].data).str)); /* retry */
	    zadd_rdata_wireformat(zparser_conv_period(parser->region, (yyvsp[-3].data).str)); /* expire */
	    zadd_rdata_wireformat(zparser_conv_period(parser->region, (yyvsp[-1].data).str)); /* minimum */
    }
#line 2723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 657 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zadd_rdata_wireformat(zparser_conv_a(parser->region, (yyvsp[-5].data).str)); /* address */
	    zadd_rdata_wireformat(zparser_conv_services(parser->region, (yyvsp[-3].data).str, (yyvsp[-1].data).str)); /* protocol and services */
    }
#line 2732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 664 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[-3].data).str, (yyvsp[-3].data).len)); /* CPU */
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[-1].data).str, (yyvsp[-1].data).len)); /* OS*/
    }
#line 2741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 671 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    /* convert a single dname record */
	    zadd_rdata_domain((yyvsp[-3].domain));
	    zadd_rdata_domain((yyvsp[-1].domain));
    }
#line 2751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 679 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-3].data).str));  /* priority */
	    zadd_rdata_domain((yyvsp[-1].domain));	/* MX host */
    }
#line 2760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 686 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	zadd_rdata_txt_clean_wireformat();
    }
#line 2768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 693 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zadd_rdata_domain((yyvsp[-3].domain)); /* mbox d-name */
	    zadd_rdata_domain((yyvsp[-1].domain)); /* txt d-name */
    }
#line 2777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 701 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-3].data).str)); /* subtype */
	    zadd_rdata_domain((yyvsp[-1].domain)); /* domain name */
    }
#line 2786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 709 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[-1].data).str, (yyvsp[-1].data).len)); /* X.25 address. */
    }
#line 2794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 716 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[-1].data).str, (yyvsp[-1].data).len)); /* address */
    }
#line 2802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 720 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[-3].data).str, (yyvsp[-3].data).len)); /* address */
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[-1].data).str, (yyvsp[-1].data).len)); /* sub-address */
    }
#line 2811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 728 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-3].data).str)); /* preference */
	    zadd_rdata_domain((yyvsp[-1].domain)); /* intermediate host */
    }
#line 2820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 736 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    /* String must start with "0x" or "0X".	 */
	    if (strncasecmp((yyvsp[-1].data).str, "0x", 2) != 0) {
		    zc_error_prev_line("NSAP rdata must start with '0x'");
	    } else {
		    zadd_rdata_wireformat(zparser_conv_hex(parser->region, (yyvsp[-1].data).str + 2, (yyvsp[-1].data).len - 2)); /* NSAP */
	    }
    }
#line 2833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 748 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-5].data).str)); /* preference */
	    zadd_rdata_domain((yyvsp[-3].domain)); /* MAP822 */
	    zadd_rdata_domain((yyvsp[-1].domain)); /* MAPX400 */
    }
#line 2843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 756 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zadd_rdata_wireformat(zparser_conv_aaaa(parser->region, (yyvsp[-1].data).str));  /* IPv6 address */
    }
#line 2851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 762 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zadd_rdata_wireformat(zparser_conv_loc(parser->region, (yyvsp[-1].data).str)); /* Location */
    }
#line 2859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 768 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zadd_rdata_domain((yyvsp[-3].domain)); /* nxt name */
	    zadd_rdata_wireformat(zparser_conv_nxt(parser->region, nxtbits)); /* nxt bitlist */
	    memset(nxtbits, 0, sizeof(nxtbits));
    }
#line 2869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 776 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-7].data).str)); /* prio */
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-5].data).str)); /* weight */
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-3].data).str)); /* port */
	    zadd_rdata_domain((yyvsp[-1].domain)); /* target name */
    }
#line 2880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 786 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-11].data).str)); /* order */
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-9].data).str)); /* preference */
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[-7].data).str, (yyvsp[-7].data).len)); /* flags */
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[-5].data).str, (yyvsp[-5].data).len)); /* service */
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[-3].data).str, (yyvsp[-3].data).len)); /* regexp */
	    zadd_rdata_domain((yyvsp[-1].domain)); /* target name */
    }
#line 2893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 798 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-3].data).str)); /* preference */
	    zadd_rdata_domain((yyvsp[-1].domain)); /* exchanger */
    }
#line 2902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 806 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zadd_rdata_wireformat(zparser_conv_certificate_type(parser->region, (yyvsp[-7].data).str)); /* type */
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-5].data).str)); /* key tag */
	    zadd_rdata_wireformat(zparser_conv_algorithm(parser->region, (yyvsp[-3].data).str)); /* algorithm */
	    zadd_rdata_wireformat(zparser_conv_b64(parser->region, (yyvsp[-1].data).str)); /* certificate or CRL */
    }
#line 2913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 819 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zadd_rdata_wireformat(zparser_conv_apl_rdata(parser->region, (yyvsp[0].data).str));
    }
#line 2921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 823 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zadd_rdata_wireformat(zparser_conv_apl_rdata(parser->region, (yyvsp[0].data).str));
    }
#line 2929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 829 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-7].data).str)); /* keytag */
	    zadd_rdata_wireformat(zparser_conv_algorithm(parser->region, (yyvsp[-5].data).str)); /* alg */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[-3].data).str)); /* type */
	    zadd_rdata_wireformat(zparser_conv_hex(parser->region, (yyvsp[-1].data).str, (yyvsp[-1].data).len)); /* hash */
    }
#line 2940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 838 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-7].data).str)); /* keytag */
	    zadd_rdata_wireformat(zparser_conv_algorithm(parser->region, (yyvsp[-5].data).str)); /* alg */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[-3].data).str)); /* type */
	    zadd_rdata_wireformat(zparser_conv_hex(parser->region, (yyvsp[-1].data).str, (yyvsp[-1].data).len)); /* hash */
    }
#line 2951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 847 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[-5].data).str)); /* alg */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[-3].data).str)); /* fp type */
	    zadd_rdata_wireformat(zparser_conv_hex(parser->region, (yyvsp[-1].data).str, (yyvsp[-1].data).len)); /* hash */
    }
#line 2961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 855 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zadd_rdata_wireformat(zparser_conv_b64(parser->region, (yyvsp[-1].data).str)); /* data blob */
    }
#line 2969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 861 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zadd_rdata_wireformat(zparser_conv_rrtype(parser->region, (yyvsp[-17].data).str)); /* rr covered */
	    zadd_rdata_wireformat(zparser_conv_algorithm(parser->region, (yyvsp[-15].data).str)); /* alg */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[-13].data).str)); /* # labels */
	    zadd_rdata_wireformat(zparser_conv_period(parser->region, (yyvsp[-11].data).str)); /* # orig TTL */
	    zadd_rdata_wireformat(zparser_conv_time(parser->region, (yyvsp[-9].data).str)); /* sig exp */
	    zadd_rdata_wireformat(zparser_conv_time(parser->region, (yyvsp[-7].data).str)); /* sig inc */
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-5].data).str)); /* key id */
	    zadd_rdata_wireformat(zparser_conv_dns_name(parser->region, 
				(const uint8_t*) (yyvsp[-3].data).str,(yyvsp[-3].data).len)); /* sig name */
	    zadd_rdata_wireformat(zparser_conv_b64(parser->region, (yyvsp[-1].data).str)); /* sig data */
    }
#line 2986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 876 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zadd_rdata_wireformat(zparser_conv_dns_name(parser->region, 
				(const uint8_t*) (yyvsp[-1].data).str, (yyvsp[-1].data).len)); /* nsec name */
	    zadd_rdata_wireformat(zparser_conv_nsec(parser->region, nsecbits)); /* nsec bitlist */
	    memset(nsecbits, 0, sizeof(nsecbits));
            nsec_highest_rcode = 0;
    }
#line 2998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 886 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
#ifdef NSEC3
	    nsec3_add_params((yyvsp[-9].data).str, (yyvsp[-7].data).str, (yyvsp[-5].data).str, (yyvsp[-3].data).str, (yyvsp[-3].data).len);

	    zadd_rdata_wireformat(zparser_conv_b32(parser->region, (yyvsp[-1].data).str)); /* next hashed name */
	    zadd_rdata_wireformat(zparser_conv_nsec(parser->region, nsecbits)); /* nsec bitlist */
	    memset(nsecbits, 0, sizeof(nsecbits));
	    nsec_highest_rcode = 0;
#else
	    zc_error_prev_line("nsec3 not supported");
#endif /* NSEC3 */
    }
#line 3015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 901 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
#ifdef NSEC3
	    nsec3_add_params((yyvsp[-7].data).str, (yyvsp[-5].data).str, (yyvsp[-3].data).str, (yyvsp[-1].data).str, (yyvsp[-1].data).len);
#else
	    zc_error_prev_line("nsec3 not supported");
#endif /* NSEC3 */
    }
#line 3027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 911 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[-7].data).str)); /* usage */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[-5].data).str)); /* selector */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[-3].data).str)); /* matching type */
	    zadd_rdata_wireformat(zparser_conv_hex(parser->region, (yyvsp[-1].data).str, (yyvsp[-1].data).len)); /* ca data */
    }
#line 3038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 920 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-7].data).str)); /* flags */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[-5].data).str)); /* proto */
	    zadd_rdata_wireformat(zparser_conv_algorithm(parser->region, (yyvsp[-3].data).str)); /* alg */
	    zadd_rdata_wireformat(zparser_conv_b64(parser->region, (yyvsp[-1].data).str)); /* hash */
    }
#line 3049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 929 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    const dname_type* name = 0;
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[-6].data).str)); /* precedence */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[-4].data).str)); /* gateway type */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[-2].data).str)); /* algorithm */
	    switch(atoi((yyvsp[-4].data).str)) {
		case IPSECKEY_NOGATEWAY: 
			zadd_rdata_wireformat(alloc_rdata_init(parser->region, "", 0));
			break;
		case IPSECKEY_IP4:
			zadd_rdata_wireformat(zparser_conv_a(parser->region, (yyvsp[0].data).str));
			break;
		case IPSECKEY_IP6:
			zadd_rdata_wireformat(zparser_conv_aaaa(parser->region, (yyvsp[0].data).str));
			break;
		case IPSECKEY_DNAME:
			/* convert and insert the dname */
			if(strlen((yyvsp[0].data).str) == 0)
				zc_error_prev_line("IPSECKEY must specify gateway name");
			if(!(name = dname_parse(parser->region, (yyvsp[0].data).str)))
				zc_error_prev_line("IPSECKEY bad gateway dname %s", (yyvsp[0].data).str);
			if((yyvsp[0].data).str[strlen((yyvsp[0].data).str)-1] != '.')
				name = dname_concatenate(parser->rr_region, name, 
					domain_dname(parser->origin));
			zadd_rdata_wireformat(alloc_rdata_init(parser->region,
				dname_name(name), name->name_size));
			break;
		default:
			zc_error_prev_line("unknown IPSECKEY gateway type");
	    }
    }
#line 3085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 963 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	   zadd_rdata_wireformat(zparser_conv_b64(parser->region, (yyvsp[-1].data).str)); /* public key */
    }
#line 3093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 971 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-3].data).str));  /* preference */
	    zadd_rdata_wireformat(zparser_conv_ilnp64(parser->region, (yyvsp[-1].data).str));  /* NodeID */
    }
#line 3102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 978 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-3].data).str));  /* preference */
	    zadd_rdata_wireformat(zparser_conv_a(parser->region, (yyvsp[-1].data).str));  /* Locator32 */
    }
#line 3111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 985 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-3].data).str));  /* preference */
	    zadd_rdata_wireformat(zparser_conv_ilnp64(parser->region, (yyvsp[-1].data).str));  /* Locator64 */
    }
#line 3120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 992 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-3].data).str));  /* preference */
	    zadd_rdata_domain((yyvsp[-1].domain));  /* FQDN */
    }
#line 3129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 999 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zadd_rdata_wireformat(zparser_conv_eui(parser->region, (yyvsp[-1].data).str, 48));
    }
#line 3137 "y.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1005 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zadd_rdata_wireformat(zparser_conv_eui(parser->region, (yyvsp[-1].data).str, 64));
    }
#line 3145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1012 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[-5].data).str)); /* Flags */
	    zadd_rdata_wireformat(zparser_conv_tag(parser->region, (yyvsp[-3].data).str, (yyvsp[-3].data).len)); /* Tag */
	    zadd_rdata_wireformat(zparser_conv_long_text(parser->region, (yyvsp[-1].data).str, (yyvsp[-1].data).len)); /* Value */
    }
#line 3155 "y.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1020 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    /* $2 is the number of octects, currently ignored */
	    (yyval.unknown) = zparser_conv_hex(parser->region, (yyvsp[-1].data).str, (yyvsp[-1].data).len);

    }
#line 3165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1026 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    (yyval.unknown) = zparser_conv_hex(parser->region, "", 0);
    }
#line 3173 "y.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1030 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1646  */
    {
	    (yyval.unknown) = zparser_conv_hex(parser->region, "", 0);
    }
#line 3181 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3185 "y.tab.c" /* yacc.c:1646  */
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
#line 1034 "/root/fastDNS/nsd/zparser.y" /* yacc.c:1906  */


int
yywrap(void)
{
	return 1;
}

/*
 * Create the parser.
 */
zparser_type *
zparser_create(region_type *region, region_type *rr_region, namedb_type *db)
{
	zparser_type *result;

	result = (zparser_type *) region_alloc(region, sizeof(zparser_type));
	result->region = region;
	result->rr_region = rr_region;
	result->db = db;

	result->filename = NULL;
	result->current_zone = NULL;
	result->origin = NULL;
	result->prev_dname = NULL;
	result->default_apex = NULL;

	result->temporary_rdatas = (rdata_atom_type *) region_alloc(
		result->region, MAXRDATALEN * sizeof(rdata_atom_type));

	return result;
}

/*
 * Initialize the parser for a new zone file.
 */
void
zparser_init(const char *filename, uint32_t ttl, uint16_t klass,
	     const dname_type *origin)
{
	memset(nxtbits, 0, sizeof(nxtbits));
	memset(nsecbits, 0, sizeof(nsecbits));
        nsec_highest_rcode = 0;

	parser->default_ttl = ttl;
	parser->default_class = klass;
	parser->current_zone = NULL;
	parser->origin = domain_table_insert(parser->db->domains, origin);
	parser->prev_dname = parser->origin;
	parser->default_apex = parser->origin;
	parser->error_occurred = 0;
	parser->errors = 0;
	parser->line = 1;
	parser->filename = filename;
	parser->current_rr.rdata_count = 0;
	parser->current_rr.rdatas = parser->temporary_rdatas;
}

void
yyerror(const char *message)
{
	zc_error("%s", message);
}

static void
error_va_list(unsigned line, const char *fmt, va_list args)
{
	if (parser->filename) {
		char message[MAXSYSLOGMSGLEN];
		vsnprintf(message, sizeof(message), fmt, args);
		log_msg(LOG_ERR, "%s:%u: %s", parser->filename, line, message);
	}
	else log_vmsg(LOG_ERR, fmt, args);

	++parser->errors;
	parser->error_occurred = 1;
}

/* the line counting sux, to say the least
 * with this grose hack we try do give sane
 * numbers back */
void
zc_error_prev_line(const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	error_va_list(parser->line - 1, fmt, args);
	va_end(args);
}

void
zc_error(const char *fmt, ...)
{
	/* send an error message to stderr */
	va_list args;
	va_start(args, fmt);
	error_va_list(parser->line, fmt, args);
	va_end(args);
}

static void
warning_va_list(unsigned line, const char *fmt, va_list args)
{
	if (parser->filename) {
		char m[MAXSYSLOGMSGLEN];
		vsnprintf(m, sizeof(m), fmt, args);
		log_msg(LOG_WARNING, "%s:%u: %s", parser->filename, line, m);
	}
	else log_vmsg(LOG_WARNING, fmt, args);
}

void
zc_warning_prev_line(const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	warning_va_list(parser->line - 1, fmt, args);
	va_end(args);
}

void
zc_warning(const char *fmt, ... )
{
	va_list args;
	va_start(args, fmt);
	warning_va_list(parser->line, fmt, args);
	va_end(args);
}

#ifdef NSEC3
static void
nsec3_add_params(const char* hashalgo_str, const char* flag_str,
	const char* iter_str, const char* salt_str, int salt_len)
{
	zadd_rdata_wireformat(zparser_conv_byte(parser->region, hashalgo_str));
	zadd_rdata_wireformat(zparser_conv_byte(parser->region, flag_str));
	zadd_rdata_wireformat(zparser_conv_short(parser->region, iter_str));

	/* salt */
	if(strcmp(salt_str, "-") != 0) 
		zadd_rdata_wireformat(zparser_conv_hex_length(parser->region, 
			salt_str, salt_len)); 
	else 
		zadd_rdata_wireformat(alloc_rdata_init(parser->region, "", 1));
}
#endif /* NSEC3 */
