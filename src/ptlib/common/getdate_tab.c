/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "getdate.y"

/*
**  Originally written by Steven M. Bellovin <smb@research.att.com> while
**  at the University of North Carolina at Chapel Hill.  Later tweaked by
**  a couple of people on Usenet.  Completely overhauled by Rich $alz
**  <rsalz@bbn.com> and Jim Berets <jberets@bbn.com> in August, 1990;
**
**  Major hack to coerce it into use with the Equivalence Portable
**  Windows Library.
**
**  This grammar has 10 shift/reduce conflicts.
**
**  This code is in the public domain and has no copyright.
*/
/* SUPPRESS 287 on yaccpar_sccsid *//* Unused static variable */
/* SUPPRESS 288 on yyerrlab *//* Label unused */


#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#ifndef EOF
#include <stdio.h>
#endif


#ifdef _WIN32
#ifdef _MSC_VER
#pragma warning(disable:4131 4701 4996)
#endif
#define STDAPICALLTYPE __stdcall
#define MSDOS
#else
#define STDAPICALLTYPE
#endif


extern int  STDAPICALLTYPE PTimeGetChar(void * stream);
extern void STDAPICALLTYPE PTimeUngetChar(void * stream, int c);
int STDAPICALLTYPE PTimeGetDateOrder();
int STDAPICALLTYPE PTimeIsMonthName(const char *, int, int);
int STDAPICALLTYPE PTimeIsDayName(const char *, int, int);


#define EPOCH		1970
#define HOUR(x)		((time_t)(x) * 60)
#define SECSPERDAY	(24L * 60L * 60L)


/*
**  An entry in the lexical lookup table.
*/
typedef struct _TABLE {
    char	*name;
    int		type;
    time_t	value;
} TABLE;


/*
**  Daylight-savings mode:  on, off, or not yet known.
*/
typedef enum _DSTMODE {
    DSTon, DSToff, DSTmaybe
} DSTMODE;

/*
**  Meridian:  am, pm, or 24-hour style.
*/
typedef enum _MERIDIAN {
    MERam, MERpm, MER24
} MERIDIAN;


/*
**  Global variables.  We could get rid of most of these by using a good
**  union as the yacc stack.  (This routine was originally written before
**  yacc had the %union construct.)  Maybe someday; right now we only use
**  the %union very rarely.
*/
struct Variables {
    void	*yyInput;
    DSTMODE	yyDSTmode;
    time_t	yyDayOrdinal;
    time_t	yyDayNumber;
    int	yyHaveDate;
    int	yyHaveDay;
    int	yyHaveRel;
    int	yyHaveTime;
    int	yyHaveZone;
    time_t	yyTimezone;
    time_t	yyDay;
    time_t	yyHour;
    time_t	yyMinutes;
    time_t	yyMonth;
    time_t	yySeconds;
    time_t	yyYear;
    MERIDIAN	yyMeridian;
    time_t	yyRelMonth;
    time_t	yyRelSeconds;
};

#define VARIABLE ((struct Variables*)parseParam)


#define YYPURE		1
#define YYLEX_PARAM	VARIABLE
#define YYPARSE_PARAM	parseParam

#define yyparse		PTime_yyparse
#define yylex		PTime_yylex
#define yyerror		PTime_yyerror

#define GCC_VERSION (__GNUC__ * 10000 \
                    + __GNUC_MINOR__ * 100 \
                    + __GNUC_PATCHLEVEL__)

static int yyparse(void *); 
static int yylex();

#ifdef __GNUC__
static int yyerror(char const *msg);
#else
static void yyerror(char const *msg);
#endif


static void SetPossibleDate(struct Variables*, time_t, time_t, time_t);



#line 205 "getdate_tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    tAGO = 258,                    /* tAGO  */
    tDAY = 259,                    /* tDAY  */
    tDAYZONE = 260,                /* tDAYZONE  */
    tID = 261,                     /* tID  */
    tMERIDIAN = 262,               /* tMERIDIAN  */
    tMINUTE_UNIT = 263,            /* tMINUTE_UNIT  */
    tMONTH = 264,                  /* tMONTH  */
    tMONTH_UNIT = 265,             /* tMONTH_UNIT  */
    tSNUMBER = 266,                /* tSNUMBER  */
    tS4DIGITNUMBER = 267,          /* tS4DIGITNUMBER  */
    tUNUMBER = 268,                /* tUNUMBER  */
    t4DIGITNUMBER = 269,           /* t4DIGITNUMBER  */
    t6DIGITNUMBER = 270,           /* t6DIGITNUMBER  */
    t8DIGITNUMBER = 271,           /* t8DIGITNUMBER  */
    tSEC_UNIT = 272,               /* tSEC_UNIT  */
    tZONE = 273,                   /* tZONE  */
    tMILZONE = 274,                /* tMILZONE  */
    tRFC3339 = 275,                /* tRFC3339  */
    tDST = 276                     /* tDST  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 140 "getdate.y"

    time_t		Number;
    enum _MERIDIAN	Meridian;

#line 278 "getdate_tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif




int yyparse (int parseParam);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_tAGO = 3,                       /* tAGO  */
  YYSYMBOL_tDAY = 4,                       /* tDAY  */
  YYSYMBOL_tDAYZONE = 5,                   /* tDAYZONE  */
  YYSYMBOL_tID = 6,                        /* tID  */
  YYSYMBOL_tMERIDIAN = 7,                  /* tMERIDIAN  */
  YYSYMBOL_tMINUTE_UNIT = 8,               /* tMINUTE_UNIT  */
  YYSYMBOL_tMONTH = 9,                     /* tMONTH  */
  YYSYMBOL_tMONTH_UNIT = 10,               /* tMONTH_UNIT  */
  YYSYMBOL_tSNUMBER = 11,                  /* tSNUMBER  */
  YYSYMBOL_tS4DIGITNUMBER = 12,            /* tS4DIGITNUMBER  */
  YYSYMBOL_tUNUMBER = 13,                  /* tUNUMBER  */
  YYSYMBOL_t4DIGITNUMBER = 14,             /* t4DIGITNUMBER  */
  YYSYMBOL_t6DIGITNUMBER = 15,             /* t6DIGITNUMBER  */
  YYSYMBOL_t8DIGITNUMBER = 16,             /* t8DIGITNUMBER  */
  YYSYMBOL_tSEC_UNIT = 17,                 /* tSEC_UNIT  */
  YYSYMBOL_tZONE = 18,                     /* tZONE  */
  YYSYMBOL_tMILZONE = 19,                  /* tMILZONE  */
  YYSYMBOL_tRFC3339 = 20,                  /* tRFC3339  */
  YYSYMBOL_tDST = 21,                      /* tDST  */
  YYSYMBOL_22_ = 22,                       /* ':'  */
  YYSYMBOL_23_ = 23,                       /* ','  */
  YYSYMBOL_24_ = 24,                       /* '/'  */
  YYSYMBOL_YYACCEPT = 25,                  /* $accept  */
  YYSYMBOL_spec = 26,                      /* spec  */
  YYSYMBOL_item = 27,                      /* item  */
  YYSYMBOL_time = 28,                      /* time  */
  YYSYMBOL_zone = 29,                      /* zone  */
  YYSYMBOL_day = 30,                       /* day  */
  YYSYMBOL_date = 31,                      /* date  */
  YYSYMBOL_rel = 32,                       /* rel  */
  YYSYMBOL_relunit = 33,                   /* relunit  */
  YYSYMBOL_unumber = 34,                   /* unumber  */
  YYSYMBOL_number = 35,                    /* number  */
  YYSYMBOL_o_merid = 36                    /* o_merid  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
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
#define YYLAST   105

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  25
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  12
/* YYNRULES -- Number of rules.  */
#define YYNRULES  51
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  63

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   276


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    23,     2,     2,    24,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    22,     2,
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
      15,    16,    17,    18,    19,    20,    21
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   156,   156,   157,   160,   163,   166,   169,   172,   175,
     178,   184,   192,   200,   206,   213,   219,   229,   233,   238,
     242,   252,   256,   260,   266,   269,   272,   276,   281,   285,
     292,   297,   304,   309,   313,   316,   319,   322,   325,   328,
     331,   334,   337,   340,   345,   348,   351,   356,   382,   393,
     410,   413
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "tAGO", "tDAY",
  "tDAYZONE", "tID", "tMERIDIAN", "tMINUTE_UNIT", "tMONTH", "tMONTH_UNIT",
  "tSNUMBER", "tS4DIGITNUMBER", "tUNUMBER", "t4DIGITNUMBER",
  "t6DIGITNUMBER", "t8DIGITNUMBER", "tSEC_UNIT", "tZONE", "tMILZONE",
  "tRFC3339", "tDST", "':'", "','", "'/'", "$accept", "spec", "item",
  "time", "zone", "day", "date", "rel", "relunit", "unumber", "number",
  "o_merid", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-27)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-50)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -27,    49,   -27,   -10,   -27,   -27,   -11,   -27,     1,    10,
      69,    86,   -27,   -27,    -9,   -27,   -27,   -27,   -27,   -27,
     -27,   -27,    13,    -3,   -27,   -27,   -27,   -27,   -27,     8,
     -27,   -27,   -27,   -27,   -27,   -27,   -27,   -27,   -27,   -27,
      30,   -27,     9,   -27,   -11,   -11,   -11,   -27,   -27,    12,
      15,    18,   -27,   -27,   -27,   -27,   -11,   -27,   -11,    23,
     -27,   -27,   -27
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,    21,    18,    37,     0,    43,     0,    44,
      45,    46,    27,    40,    17,    20,     3,     4,     5,     7,
       6,     8,    34,     0,     9,    22,    44,    45,    46,    29,
      36,    41,    38,    10,    11,    12,    19,    33,    23,    35,
      31,    42,     0,    39,     0,     0,     0,    28,    32,     0,
      50,    24,    30,    26,    51,    14,     0,    13,     0,    50,
      25,    16,    15
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -27,   -27,   -27,   -27,   -27,   -27,   -27,   -27,   -27,    -6,
     -27,   -26
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    57
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      29,    38,    26,    27,    28,    39,    40,    41,    42,    30,
     -47,    31,    36,    25,    43,   -47,    37,    33,    32,    44,
      49,    45,    54,   -47,   -47,   -47,   -47,    55,   -47,   -47,
      54,    46,    53,    62,    48,    61,     0,    56,    50,    51,
      52,    47,    58,    26,    27,    28,     0,     0,     0,     2,
      59,     0,    60,     3,     4,     0,     0,     5,     6,     7,
       8,     0,     9,    10,    11,    12,    13,    14,    15,   -48,
       0,     0,     0,     0,   -48,     0,     0,     0,     0,     0,
       0,    34,   -48,   -48,   -48,   -48,   -49,   -48,   -48,     0,
       0,   -49,     0,     0,     0,     0,     0,     0,    35,   -49,
     -49,   -49,   -49,     0,   -49,   -49
};

static const yytype_int8 yycheck[] =
{
       6,     4,    13,    14,    15,     8,     9,    10,    11,     8,
       0,    10,    21,    23,    17,     5,     3,     7,    17,    22,
      11,    24,     7,    13,    14,    15,    16,    12,    18,    19,
       7,    23,    20,    59,    40,    12,    -1,    22,    44,    45,
      46,    11,    24,    13,    14,    15,    -1,    -1,    -1,     0,
      56,    -1,    58,     4,     5,    -1,    -1,     8,     9,    10,
      11,    -1,    13,    14,    15,    16,    17,    18,    19,     0,
      -1,    -1,    -1,    -1,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    12,    13,    14,    15,    16,     0,    18,    19,    -1,
      -1,     5,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,
      14,    15,    16,    -1,    18,    19
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    26,     0,     4,     5,     8,     9,    10,    11,    13,
      14,    15,    16,    17,    18,    19,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    23,    13,    14,    15,    34,
       8,    10,    17,     7,    12,    12,    21,     3,     4,     8,
       9,    10,    11,    17,    22,    24,    23,    11,    34,    11,
      34,    34,    34,    20,     7,    12,    22,    36,    24,    34,
      34,    12,    36
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    25,    26,    26,    27,    27,    27,    27,    27,    27,
      28,    28,    28,    28,    28,    28,    28,    29,    29,    29,
      29,    30,    30,    30,    31,    31,    31,    31,    31,    31,
      31,    31,    31,    32,    32,    33,    33,    33,    33,    33,
      33,    33,    33,    33,    34,    34,    34,    35,    35,    35,
      36,    36
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     4,     4,     6,     6,     1,     1,     2,
       1,     1,     2,     2,     3,     5,     4,     1,     3,     2,
       4,     2,     3,     2,     1,     2,     2,     1,     2,     2,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       0,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
        yyerror (parseParam, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, parseParam); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, int parseParam)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (parseParam);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, int parseParam)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, parseParam);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, int parseParam)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], parseParam);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, parseParam); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, int parseParam)
{
  YY_USE (yyvaluep);
  YY_USE (parseParam);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (int parseParam)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 4: /* item: time  */
#line 160 "getdate.y"
               {
	    VARIABLE->yyHaveTime++;
	}
#line 1350 "getdate_tab.c"
    break;

  case 5: /* item: zone  */
#line 163 "getdate.y"
               {
	    VARIABLE->yyHaveZone++;
	}
#line 1358 "getdate_tab.c"
    break;

  case 6: /* item: date  */
#line 166 "getdate.y"
               {
	    VARIABLE->yyHaveDate++;
	}
#line 1366 "getdate_tab.c"
    break;

  case 7: /* item: day  */
#line 169 "getdate.y"
              {
	    VARIABLE->yyHaveDay++;
	}
#line 1374 "getdate_tab.c"
    break;

  case 8: /* item: rel  */
#line 172 "getdate.y"
              {
	    VARIABLE->yyHaveRel++;
	}
#line 1382 "getdate_tab.c"
    break;

  case 10: /* time: tUNUMBER tMERIDIAN  */
#line 178 "getdate.y"
                             {
	    VARIABLE->yyHour = (yyvsp[-1].Number);
	    VARIABLE->yyMinutes = 0;
	    VARIABLE->yySeconds = 0;
	    VARIABLE->yyMeridian = (yyvsp[0].Meridian);
	}
#line 1393 "getdate_tab.c"
    break;

  case 11: /* time: t4DIGITNUMBER tS4DIGITNUMBER  */
#line 184 "getdate.y"
                                        {
	    VARIABLE->yyHour = (yyvsp[-1].Number)/100;
	    VARIABLE->yyMinutes = (yyvsp[-1].Number)%100;
	    VARIABLE->yySeconds = 0;
	    VARIABLE->yyMeridian = MER24;
	    VARIABLE->yyDSTmode = DSToff;
	    VARIABLE->yyTimezone = - ((yyvsp[0].Number) % 100 + ((yyvsp[0].Number) / 100) * 60);
        }
#line 1406 "getdate_tab.c"
    break;

  case 12: /* time: t6DIGITNUMBER tS4DIGITNUMBER  */
#line 192 "getdate.y"
                                        {
	    VARIABLE->yyHour = (yyvsp[-1].Number)/10000;
	    VARIABLE->yyMinutes = ((yyvsp[-1].Number)/100)%100;
	    VARIABLE->yySeconds = (yyvsp[-1].Number) % 100;
	    VARIABLE->yyMeridian = MER24;
	    VARIABLE->yyDSTmode = DSToff;
	    VARIABLE->yyTimezone = - ((yyvsp[0].Number) % 100 + ((yyvsp[0].Number) / 100) * 60);
        }
#line 1419 "getdate_tab.c"
    break;

  case 13: /* time: unumber ':' unumber o_merid  */
#line 200 "getdate.y"
                                       {
	    VARIABLE->yyHour = (yyvsp[-3].Number);
	    VARIABLE->yyMinutes = (yyvsp[-1].Number);
	    VARIABLE->yySeconds = 0;
	    VARIABLE->yyMeridian = (yyvsp[0].Meridian);
	}
#line 1430 "getdate_tab.c"
    break;

  case 14: /* time: unumber ':' unumber tS4DIGITNUMBER  */
#line 206 "getdate.y"
                                              {
	    VARIABLE->yyHour = (yyvsp[-3].Number);
	    VARIABLE->yyMinutes = (yyvsp[-1].Number);
	    VARIABLE->yyMeridian = MER24;
	    VARIABLE->yyDSTmode = DSToff;
	    VARIABLE->yyTimezone = - ((yyvsp[0].Number) % 100 + ((yyvsp[0].Number) / 100) * 60);
	}
#line 1442 "getdate_tab.c"
    break;

  case 15: /* time: unumber ':' unumber ':' unumber o_merid  */
#line 213 "getdate.y"
                                                  {
	    VARIABLE->yyHour = (yyvsp[-5].Number);
	    VARIABLE->yyMinutes = (yyvsp[-3].Number);
	    VARIABLE->yySeconds = (yyvsp[-1].Number);
	    VARIABLE->yyMeridian = (yyvsp[0].Meridian);
	}
#line 1453 "getdate_tab.c"
    break;

  case 16: /* time: unumber ':' unumber ':' unumber tS4DIGITNUMBER  */
#line 219 "getdate.y"
                                                          {
	    VARIABLE->yyHour = (yyvsp[-5].Number);
	    VARIABLE->yyMinutes = (yyvsp[-3].Number);
	    VARIABLE->yySeconds = (yyvsp[-1].Number);
	    VARIABLE->yyMeridian = MER24;
	    VARIABLE->yyDSTmode = DSToff;
	    VARIABLE->yyTimezone = - ((yyvsp[0].Number) % 100 + ((yyvsp[0].Number) / 100) * 60);
	}
#line 1466 "getdate_tab.c"
    break;

  case 17: /* zone: tZONE  */
#line 229 "getdate.y"
                {
	    VARIABLE->yyTimezone = (yyvsp[0].Number);
	    VARIABLE->yyDSTmode = DSToff;
	}
#line 1475 "getdate_tab.c"
    break;

  case 18: /* zone: tDAYZONE  */
#line 233 "getdate.y"
                   {
	    VARIABLE->yyTimezone = (yyvsp[0].Number);
	    VARIABLE->yyDSTmode = DSTon;
	}
#line 1484 "getdate_tab.c"
    break;

  case 19: /* zone: tZONE tDST  */
#line 238 "getdate.y"
                     {
	    VARIABLE->yyTimezone = (yyvsp[-1].Number);
	    VARIABLE->yyDSTmode = DSTon;
	}
#line 1493 "getdate_tab.c"
    break;

  case 20: /* zone: tMILZONE  */
#line 242 "getdate.y"
                   {
            if (VARIABLE->yyHaveTime > 0) {
	      VARIABLE->yyTimezone = (yyvsp[0].Number);
	      VARIABLE->yyDSTmode = DSToff;
            }
            else
              VARIABLE->yyHaveZone--;
        }
#line 1506 "getdate_tab.c"
    break;

  case 21: /* day: tDAY  */
#line 252 "getdate.y"
               {
	    VARIABLE->yyDayOrdinal = 1;
	    VARIABLE->yyDayNumber = (yyvsp[0].Number);
	}
#line 1515 "getdate_tab.c"
    break;

  case 22: /* day: tDAY ','  */
#line 256 "getdate.y"
                   {
	    VARIABLE->yyDayOrdinal = 1;
	    VARIABLE->yyDayNumber = (yyvsp[-1].Number);
	}
#line 1524 "getdate_tab.c"
    break;

  case 23: /* day: unumber tDAY  */
#line 260 "getdate.y"
                       {
	    VARIABLE->yyDayOrdinal = (yyvsp[-1].Number);
	    VARIABLE->yyDayNumber = (yyvsp[0].Number);
	}
#line 1533 "getdate_tab.c"
    break;

  case 24: /* date: unumber '/' unumber  */
#line 266 "getdate.y"
                              {
	    SetPossibleDate(VARIABLE, (yyvsp[-2].Number), (yyvsp[0].Number), VARIABLE->yyYear);
	}
#line 1541 "getdate_tab.c"
    break;

  case 25: /* date: unumber '/' unumber '/' unumber  */
#line 269 "getdate.y"
                                          {
	    SetPossibleDate(VARIABLE, (yyvsp[-4].Number), (yyvsp[-2].Number), (yyvsp[0].Number));
	}
#line 1549 "getdate_tab.c"
    break;

  case 26: /* date: unumber tSNUMBER tSNUMBER tRFC3339  */
#line 272 "getdate.y"
                                             {
	    /* ISO 8601 format.  yyyy-mm-dd.  */
	    SetPossibleDate(VARIABLE, (yyvsp[-3].Number), -(yyvsp[-2].Number), -(yyvsp[-1].Number));
	}
#line 1558 "getdate_tab.c"
    break;

  case 27: /* date: t8DIGITNUMBER  */
#line 276 "getdate.y"
                        {
	    VARIABLE->yyDay= ((yyvsp[0].Number))%100;
	    VARIABLE->yyMonth= ((yyvsp[0].Number)/100)%100;
	    VARIABLE->yyYear = (yyvsp[0].Number)/10000;
	}
#line 1568 "getdate_tab.c"
    break;

  case 28: /* date: unumber tMONTH tSNUMBER  */
#line 281 "getdate.y"
                                  {
	    /* e.g. 17-JUN-1992.  */
	    SetPossibleDate(VARIABLE, (yyvsp[-2].Number), (yyvsp[-1].Number), -(yyvsp[0].Number));
	}
#line 1577 "getdate_tab.c"
    break;

  case 29: /* date: tMONTH unumber  */
#line 285 "getdate.y"
                         {
	    VARIABLE->yyMonth = (yyvsp[-1].Number);
	    if ((yyvsp[0].Number) > 31)
	      VARIABLE->yyYear = (yyvsp[0].Number);
	    else
	      VARIABLE->yyDay = (yyvsp[0].Number);
	}
#line 1589 "getdate_tab.c"
    break;

  case 30: /* date: tMONTH unumber ',' unumber  */
#line 292 "getdate.y"
                                     {
	    VARIABLE->yyMonth = (yyvsp[-3].Number);
	    VARIABLE->yyDay = (yyvsp[-2].Number);
	    VARIABLE->yyYear = (yyvsp[0].Number);
	}
#line 1599 "getdate_tab.c"
    break;

  case 31: /* date: unumber tMONTH  */
#line 297 "getdate.y"
                         {
	    if ((yyvsp[-1].Number) > 31)
	      VARIABLE->yyYear = (yyvsp[-1].Number);
	    else
	      VARIABLE->yyDay = (yyvsp[-1].Number);
	    VARIABLE->yyMonth = (yyvsp[0].Number);
	}
#line 1611 "getdate_tab.c"
    break;

  case 32: /* date: unumber tMONTH unumber  */
#line 304 "getdate.y"
                                 {
	    SetPossibleDate(VARIABLE, (yyvsp[-2].Number), (yyvsp[-1].Number), (yyvsp[0].Number));
	}
#line 1619 "getdate_tab.c"
    break;

  case 33: /* rel: relunit tAGO  */
#line 309 "getdate.y"
                       {
	    VARIABLE->yyRelSeconds = -VARIABLE->yyRelSeconds;
	    VARIABLE->yyRelMonth = -VARIABLE->yyRelMonth;
	}
#line 1628 "getdate_tab.c"
    break;

  case 35: /* relunit: unumber tMINUTE_UNIT  */
#line 316 "getdate.y"
                               {
	    VARIABLE->yyRelSeconds += (yyvsp[-1].Number) * (yyvsp[0].Number) * 60L;
	}
#line 1636 "getdate_tab.c"
    break;

  case 36: /* relunit: tSNUMBER tMINUTE_UNIT  */
#line 319 "getdate.y"
                                {
	    VARIABLE->yyRelSeconds += (yyvsp[-1].Number) * (yyvsp[0].Number) * 60L;
	}
#line 1644 "getdate_tab.c"
    break;

  case 37: /* relunit: tMINUTE_UNIT  */
#line 322 "getdate.y"
                       {
	    VARIABLE->yyRelSeconds += (yyvsp[0].Number) * 60L;
	}
#line 1652 "getdate_tab.c"
    break;

  case 38: /* relunit: tSNUMBER tSEC_UNIT  */
#line 325 "getdate.y"
                             {
	    VARIABLE->yyRelSeconds += (yyvsp[-1].Number);
	}
#line 1660 "getdate_tab.c"
    break;

  case 39: /* relunit: unumber tSEC_UNIT  */
#line 328 "getdate.y"
                            {
	    VARIABLE->yyRelSeconds += (yyvsp[-1].Number);
	}
#line 1668 "getdate_tab.c"
    break;

  case 40: /* relunit: tSEC_UNIT  */
#line 331 "getdate.y"
                    {
	    VARIABLE->yyRelSeconds++;
	}
#line 1676 "getdate_tab.c"
    break;

  case 41: /* relunit: tSNUMBER tMONTH_UNIT  */
#line 334 "getdate.y"
                               {
	    VARIABLE->yyRelMonth += (yyvsp[-1].Number) * (yyvsp[0].Number);
	}
#line 1684 "getdate_tab.c"
    break;

  case 42: /* relunit: unumber tMONTH_UNIT  */
#line 337 "getdate.y"
                              {
	    VARIABLE->yyRelMonth += (yyvsp[-1].Number) * (yyvsp[0].Number);
	}
#line 1692 "getdate_tab.c"
    break;

  case 43: /* relunit: tMONTH_UNIT  */
#line 340 "getdate.y"
                      {
	    VARIABLE->yyRelMonth += (yyvsp[0].Number);
	}
#line 1700 "getdate_tab.c"
    break;

  case 44: /* unumber: tUNUMBER  */
#line 345 "getdate.y"
                   {
	    (yyval.Number) = (yyvsp[0].Number);
	}
#line 1708 "getdate_tab.c"
    break;

  case 45: /* unumber: t4DIGITNUMBER  */
#line 348 "getdate.y"
                        {
	    (yyval.Number) = (yyvsp[0].Number);
	}
#line 1716 "getdate_tab.c"
    break;

  case 46: /* unumber: t6DIGITNUMBER  */
#line 351 "getdate.y"
                        {
	    (yyval.Number) = (yyvsp[0].Number);
	}
#line 1724 "getdate_tab.c"
    break;

  case 47: /* number: tUNUMBER  */
#line 356 "getdate.y"
                   {
	    if (VARIABLE->yyHaveTime && VARIABLE->yyHaveDate && !VARIABLE->yyHaveRel)
		VARIABLE->yyYear = (yyvsp[0].Number);
	    else {
		if((yyvsp[0].Number)>240000) {
		    VARIABLE->yyHaveDate++;
		    VARIABLE->yyDay= ((yyvsp[0].Number))%100;
		    VARIABLE->yyMonth= ((yyvsp[0].Number)/100)%100;
		    VARIABLE->yyYear = (yyvsp[0].Number)/10000;
		}
		else {
		    VARIABLE->yyHaveTime++;
		    if ((yyvsp[0].Number) < 10000) {
		    	VARIABLE->yyHour = (yyvsp[0].Number) / 100;
		    	VARIABLE->yyMinutes = (yyvsp[0].Number) % 100;
		        VARIABLE->yySeconds = 0;
		    }
		    else {
	                VARIABLE->yyHour = (yyvsp[0].Number)/10000;
	                VARIABLE->yyMinutes = ((yyvsp[0].Number)/100)%100;
	                VARIABLE->yySeconds = (yyvsp[0].Number) % 100;
                    }
		    VARIABLE->yyMeridian = MER24;
	        }
	    }
	}
#line 1755 "getdate_tab.c"
    break;

  case 48: /* number: t4DIGITNUMBER  */
#line 382 "getdate.y"
                        {
	    if (VARIABLE->yyHaveTime && VARIABLE->yyHaveDate && !VARIABLE->yyHaveRel)
		VARIABLE->yyYear = (yyvsp[0].Number);
	    else {
	        VARIABLE->yyHaveTime++;
	        VARIABLE->yyHour = (yyvsp[0].Number)/100;
	        VARIABLE->yyMinutes = (yyvsp[0].Number)%100;
	        VARIABLE->yySeconds = 0;
	        VARIABLE->yyMeridian = MER24;
            }
        }
#line 1771 "getdate_tab.c"
    break;

  case 49: /* number: t6DIGITNUMBER  */
#line 393 "getdate.y"
                        {
	    if (!VARIABLE->yyHaveDate && (yyvsp[0].Number)>240000) {
		VARIABLE->yyHaveDate++;
		VARIABLE->yyDay= ((yyvsp[0].Number))%100;
		VARIABLE->yyMonth= ((yyvsp[0].Number)/100)%100;
		VARIABLE->yyYear = (yyvsp[0].Number)/10000;
	    }
	    else if (!VARIABLE->yyHaveTime) {
	        VARIABLE->yyHaveTime++;
	        VARIABLE->yyHour = (yyvsp[0].Number)/10000;
	        VARIABLE->yyMinutes = ((yyvsp[0].Number)/100)%100;
	        VARIABLE->yySeconds = (yyvsp[0].Number) % 100;
	        VARIABLE->yyMeridian = MER24;
            }
        }
#line 1791 "getdate_tab.c"
    break;

  case 50: /* o_merid: %empty  */
#line 410 "getdate.y"
                     {
	    (yyval.Meridian) = MER24;
	}
#line 1799 "getdate_tab.c"
    break;

  case 51: /* o_merid: tMERIDIAN  */
#line 413 "getdate.y"
                    {
	    (yyval.Meridian) = (yyvsp[0].Meridian);
	}
#line 1807 "getdate_tab.c"
    break;


#line 1811 "getdate_tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (parseParam, YY_("syntax error"));
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
                      yytoken, &yylval, parseParam);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, parseParam);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (parseParam, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, parseParam);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, parseParam);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 418 "getdate.y"


/* Month and day table. */
static TABLE const MonthDayTable[] = {
    { "january",	tMONTH,  1 },
    { "february",	tMONTH,  2 },
    { "march",		tMONTH,  3 },
    { "april",		tMONTH,  4 },
    { "may",		tMONTH,  5 },
    { "june",		tMONTH,  6 },
    { "july",		tMONTH,  7 },
    { "august",		tMONTH,  8 },
    { "september",	tMONTH,  9 },
    { "sept",		tMONTH,  9 },
    { "october",	tMONTH, 10 },
    { "november",	tMONTH, 11 },
    { "december",	tMONTH, 12 },
    { "sunday",		tDAY, 0 },
    { "monday",		tDAY, 1 },
    { "tuesday",	tDAY, 2 },
    { "tues",		tDAY, 2 },
    { "wednesday",	tDAY, 3 },
    { "wednes",		tDAY, 3 },
    { "thursday",	tDAY, 4 },
    { "thur",		tDAY, 4 },
    { "thurs",		tDAY, 4 },
    { "friday",		tDAY, 5 },
    { "saturday",	tDAY, 6 },
    { NULL }
};

/* Time units table. */
static TABLE const UnitsTable[] = {
    { "year",		tMONTH_UNIT,	12 },
    { "month",		tMONTH_UNIT,	1 },
    { "fortnight",	tMINUTE_UNIT,	14 * 24 * 60 },
    { "week",		tMINUTE_UNIT,	7 * 24 * 60 },
    { "day",		tMINUTE_UNIT,	1 * 24 * 60 },
    { "hour",		tMINUTE_UNIT,	60 },
    { "minute",		tMINUTE_UNIT,	1 },
    { "min",		tMINUTE_UNIT,	1 },
    { "second",		tSEC_UNIT,	1 },
    { "sec",		tSEC_UNIT,	1 },
    { NULL }
};

/* Assorted relative-time words. */
static TABLE const OtherTable[] = {
    { "tomorrow",	tMINUTE_UNIT,	1 * 24 * 60 },
    { "yesterday",	tMINUTE_UNIT,	-1 * 24 * 60 },
    { "today",		tMINUTE_UNIT,	0 },
    { "now",		tMINUTE_UNIT,	0 },
    { "last",		tUNUMBER,	-1 },
    { "this",		tMINUTE_UNIT,	0 },
    { "next",		tUNUMBER,	2 },
    { "first",		tUNUMBER,	1 },
/*  { "second",		tUNUMBER,	2 }, */
    { "third",		tUNUMBER,	3 },
    { "fourth",		tUNUMBER,	4 },
    { "fifth",		tUNUMBER,	5 },
    { "sixth",		tUNUMBER,	6 },
    { "seventh",	tUNUMBER,	7 },
    { "eighth",		tUNUMBER,	8 },
    { "ninth",		tUNUMBER,	9 },
    { "tenth",		tUNUMBER,	10 },
    { "eleventh",	tUNUMBER,	11 },
    { "twelfth",	tUNUMBER,	12 },
    { "ago",		tAGO,	1 },
    { NULL }
};

/* The timezone table. */
/* Some of these are commented out because a time_t can't store a float. */
static TABLE const TimezoneTable[] = {
    { "gmt",	tZONE,     HOUR( 0) },	/* Greenwich Mean */
    { "ut",	tZONE,     HOUR( 0) },	/* Universal (Coordinated) */
    { "utc",	tZONE,     HOUR( 0) },
    { "wet",	tZONE,     HOUR( 0) },	/* Western European */
    { "bst",	tDAYZONE,  HOUR( 0) },	/* British Summer */
    { "wat",	tZONE,     HOUR( 1) },	/* West Africa */
    { "at",	tZONE,     HOUR( 2) },	/* Azores */
#if	0
    /* For completeness.  BST is also British Summer, and GST is
     * also Guam Standard. */
    { "bst",	tZONE,     HOUR( 3) },	/* Brazil Standard */
    { "gst",	tZONE,     HOUR( 3) },	/* Greenland Standard */
#endif
#if 0
    { "nft",	tZONE,     HOUR(3.5) },	/* Newfoundland */
    { "nst",	tZONE,     HOUR(3.5) },	/* Newfoundland Standard */
    { "ndt",	tDAYZONE,  HOUR(3.5) },	/* Newfoundland Daylight */
#endif
    { "ast",	tZONE,     HOUR( 4) },	/* Atlantic Standard */
    { "adt",	tDAYZONE,  HOUR( 4) },	/* Atlantic Daylight */
    { "est",	tZONE,     HOUR( 5) },	/* Eastern Standard */
    { "edt",	tDAYZONE,  HOUR( 5) },	/* Eastern Daylight */
    { "cst",	tZONE,     HOUR( 6) },	/* Central Standard */
    { "cdt",	tDAYZONE,  HOUR( 6) },	/* Central Daylight */
    { "mst",	tZONE,     HOUR( 7) },	/* Mountain Standard */
    { "mdt",	tDAYZONE,  HOUR( 7) },	/* Mountain Daylight */
    { "pst",	tZONE,     HOUR( 8) },	/* Pacific Standard */
    { "pdt",	tDAYZONE,  HOUR( 8) },	/* Pacific Daylight */
    { "yst",	tZONE,     HOUR( 9) },	/* Yukon Standard */
    { "ydt",	tDAYZONE,  HOUR( 9) },	/* Yukon Daylight */
    { "hst",	tZONE,     HOUR(10) },	/* Hawaii Standard */
    { "hdt",	tDAYZONE,  HOUR(10) },	/* Hawaii Daylight */
    { "cat",	tZONE,     HOUR(10) },	/* Central Alaska */
    { "ahst",	tZONE,     HOUR(10) },	/* Alaska-Hawaii Standard */
    { "nt",	tZONE,     HOUR(11) },	/* Nome */
    { "idlw",	tZONE,     HOUR(12) },	/* International Date Line West */
    { "cet",	tZONE,     -HOUR(1) },	/* Central European */
    { "met",	tZONE,     -HOUR(1) },	/* Middle European */
    { "mewt",	tZONE,     -HOUR(1) },	/* Middle European Winter */
    { "mest",	tDAYZONE,  -HOUR(1) },	/* Middle European Summer */
    { "swt",	tZONE,     -HOUR(1) },	/* Swedish Winter */
    { "sst",	tDAYZONE,  -HOUR(1) },	/* Swedish Summer */
    { "fwt",	tZONE,     -HOUR(1) },	/* French Winter */
    { "fst",	tDAYZONE,  -HOUR(1) },	/* French Summer */
    { "eet",	tZONE,     -HOUR(2) },	/* Eastern Europe, USSR Zone 1 */
    { "bt",	tZONE,     -HOUR(3) },	/* Baghdad, USSR Zone 2 */
#if 0
    { "it",	tZONE,     -HOUR(3.5) },/* Iran */
#endif
    { "zp4",	tZONE,     -HOUR(4) },	/* USSR Zone 3 */
    { "zp5",	tZONE,     -HOUR(5) },	/* USSR Zone 4 */
#if 0
    { "ist",	tZONE,     -HOUR(5.5) },/* Indian Standard */
#endif
    { "zp6",	tZONE,     -HOUR(6) },	/* USSR Zone 5 */
#if	0
    /* For completeness.  NST is also Newfoundland Stanard, and SST is
     * also Swedish Summer. */
    { "nst",	tZONE,     -HOUR(6.5) },/* North Sumatra */
    { "sst",	tZONE,     -HOUR(7) },	/* South Sumatra, USSR Zone 6 */
#endif	/* 0 */
    { "wast",	tZONE,     -HOUR(7) },	/* West Australian Standard */
    { "wadt",	tDAYZONE,  -HOUR(7) },	/* West Australian Daylight */
#if 0
    { "jt",	tZONE,     -HOUR(7.5) },/* Java (3pm in Cronusland!) */
#endif
    { "cct",	tZONE,     -HOUR(8) },	/* China Coast, USSR Zone 7 */
    { "jst",	tZONE,     -HOUR(9) },	/* Japan Standard, USSR Zone 8 */
#if 0
    { "cast",	tZONE,     -HOUR(9.5) },/* Central Australian Standard */
    { "cadt",	tDAYZONE,  -HOUR(9.5) },/* Central Australian Daylight */
#endif
    { "east",	tZONE,     -HOUR(10) },	/* Eastern Australian Standard */
    { "eadt",	tDAYZONE,  -HOUR(10) },	/* Eastern Australian Daylight */
    { "gst",	tZONE,     -HOUR(10) },	/* Guam Standard, USSR Zone 9 */
    { "nzt",	tZONE,     -HOUR(12) },	/* New Zealand */
    { "nzst",	tZONE,     -HOUR(12) },	/* New Zealand Standard */
    { "nzdt",	tDAYZONE,  -HOUR(12) },	/* New Zealand Daylight */
    { "idle",	tZONE,     -HOUR(12) },	/* International Date Line East */
    {  NULL  }
};

/* Military timezone table. */
static TABLE const MilitaryTable[] = {
    { "a",	tMILZONE,	HOUR(  1) },
    { "b",	tMILZONE,	HOUR(  2) },
    { "c",	tMILZONE,	HOUR(  3) },
    { "d",	tMILZONE,	HOUR(  4) },
    { "e",	tMILZONE,	HOUR(  5) },
    { "f",	tMILZONE,	HOUR(  6) },
    { "g",	tMILZONE,	HOUR(  7) },
    { "h",	tMILZONE,	HOUR(  8) },
    { "i",	tMILZONE,	HOUR(  9) },
    { "k",	tMILZONE,	HOUR( 10) },
    { "l",	tMILZONE,	HOUR( 11) },
    { "m",	tMILZONE,	HOUR( 12) },
    { "n",	tMILZONE,	HOUR(- 1) },
    { "o",	tMILZONE,	HOUR(- 2) },
    { "p",	tMILZONE,	HOUR(- 3) },
    { "q",	tMILZONE,	HOUR(- 4) },
    { "r",	tMILZONE,	HOUR(- 5) },
    { "s",	tMILZONE,	HOUR(- 6) },
    { "t",	tMILZONE,	HOUR(- 7) },
    { "u",	tMILZONE,	HOUR(- 8) },
    { "v",	tMILZONE,	HOUR(- 9) },
    { "w",	tMILZONE,	HOUR(-10) },
    { "x",	tMILZONE,	HOUR(-11) },
    { "y",	tMILZONE,	HOUR(-12) },
    { "z",	tZONE,		HOUR(  0) }, /* Deliberately tZONE */
    { NULL }
};

static int LookupWord(char * buff, YYSTYPE * yylval, struct Variables * vars)
{
    register char	*p;
    register char	*q;
    register const TABLE	*tp;
    int			i;
    int			abbrev;

    /* Make it lowercase. */
    for (p = buff; *p != '\0'; p++)
        *p = (char)tolower(*p);

    if (strcmp(buff, "am") == 0 || strcmp(buff, "a.m.") == 0) {
	yylval->Meridian = MERam;
	return tMERIDIAN;
    }
    if (strcmp(buff, "pm") == 0 || strcmp(buff, "p.m.") == 0) {
	yylval->Meridian = MERpm;
	return tMERIDIAN;
    }

    /* See if we have an abbreviation for a month. */
    if (strlen(buff) == 3)
	abbrev = 1;
    else if (strlen(buff) == 4 && buff[3] == '.') {
	abbrev = 1;
	buff[3] = '\0';
    }
    else
	abbrev = 0;

    for (tp = MonthDayTable; tp->name; tp++) {
	if (abbrev) {
	    if (strncmp(buff, tp->name, 3) == 0) {
		yylval->Number = tp->value;
		return tp->type;
	    }
	}
	else if (strcmp(buff, tp->name) == 0) {
	    yylval->Number = tp->value;
	    return tp->type;
	}
    }

    for (tp = TimezoneTable; tp->name; tp++)
	if (strcmp(buff, tp->name) == 0) {
	    yylval->Number = tp->value;
	    return tp->type;
	}

    if (strcmp(buff, "dst") == 0) 
	return tDST;

    for (tp = UnitsTable; tp->name; tp++)
	if (strcmp(buff, tp->name) == 0) {
	    yylval->Number = tp->value;
	    return tp->type;
	}

    /* Strip off any plural and try the units table again. */
    i = strlen(buff) - 1;
    if (buff[i] == 's') {
	buff[i] = '\0';
	for (tp = UnitsTable; tp->name; tp++)
	    if (strcmp(buff, tp->name) == 0) {
		yylval->Number = tp->value;
		return tp->type;
	    }
	buff[i] = 's';		/* Put back for "this" in OtherTable. */
    }

    for (tp = OtherTable; tp->name; tp++)
	if (strcmp(buff, tp->name) == 0) {
	    yylval->Number = tp->value;
	    return tp->type;
	}

    /* Avoid confusion with 'T' in RFC3339 and 't' in Military timezones */
    if (!vars->yyHaveTime && strcmp(buff, "t") == 0)
	return tRFC3339;
 
    /* Military timezones. */
   if (buff[1] == '\0' && isalpha(*buff)) {
	for (tp = MilitaryTable; tp->name; tp++)
	    if (strcmp(buff, tp->name) == 0) {
		yylval->Number = tp->value;
		return tp->type;
	    }
    }

    /* Drop out any periods and try the timezone table again. */
    for (i = 0, p = q = buff; *q; q++)
	if (*q != '.')
	    *p++ = *q;
	else
	    i++;
    *p = '\0';
    if (i)
	for (tp = TimezoneTable; tp->name; tp++)
	    if (strcmp(buff, tp->name) == 0) {
		yylval->Number = tp->value;
		return tp->type;
	    }

    for (i = 1; i <= 12; i++)
	for (abbrev = 0; abbrev < 2; abbrev++)
	    if (PTimeIsMonthName(buff, i, abbrev)) {
		yylval->Number = i;
		return tMONTH;
	    }

    for (i = 1; i <= 7; i++)
	for (abbrev = 0; abbrev < 2; abbrev++)
	    if (PTimeIsDayName(buff, i, abbrev)) {
		yylval->Number = i;
		return tDAY;
	    }

    return tID;
}


#ifdef _MSC_VER
#pragma warning(disable:4211)
#endif

#ifndef __GNUC__
static
#endif
int yylex(YYSTYPE * yylval, struct Variables * vars)
{
    register char	*p;
    char		buff[20];
    int			Count;
    int			sign;
    register int	c = PTimeGetChar(vars->yyInput);

    while (c != EOF && c != '\0' && c != '\n') {
	while (isspace(c))
	    c = PTimeGetChar(vars->yyInput);

	if (isdigit(c) || c == '-' || c == '+') {
	    if (c == '-' || c == '+') {
		sign = c == '-' ? -1 : 1;
		if (!isdigit(c = PTimeGetChar(vars->yyInput)))
		    /* skip the '-' sign */
		    continue;
	    }
	    else
		sign = 0;
	    yylval->Number = 0;
            Count = 0; /* Count number of digits */
	    while (isdigit(c)) {
		yylval->Number = 10 * yylval->Number + c - '0';
		c = PTimeGetChar(vars->yyInput);
                Count++;
	    }
	    PTimeUngetChar(vars->yyInput, c);
	    if (sign < 0)
		yylval->Number = -yylval->Number;
            if (Count == 4)
              return sign ? tS4DIGITNUMBER : t4DIGITNUMBER;
	    if (sign)
              return tSNUMBER;
            if (Count == 6)
              return t6DIGITNUMBER;
            if (Count == 8)
              return t8DIGITNUMBER;
            return tUNUMBER;
	}

	if (isalpha(c)) {
	    for (p = buff; isalpha(c) || c == '.'; c = PTimeGetChar(vars->yyInput)) {
		if (p < &buff[sizeof(buff)-1])
		    *p++ = (char)c;
	    }
	    *p = '\0';
	    PTimeUngetChar(vars->yyInput, c);
	    return LookupWord(buff, yylval, vars);
	}

	if (c != '(')
	    return c;

	Count = 0;
	do {
	    c = PTimeGetChar(vars->yyInput);
	    if (c == '\0' || c == EOF)
		return c;
	    if (c == '(')
		Count++;
	    else if (c == ')')
		Count--;
	} while (Count > 0);
    }

    if (c == '\n')
        PTimeUngetChar(vars->yyInput, c);

    return EOF;
}

#ifdef _MSC_VER
#pragma warning(default:4211)
#endif


static time_t ToSeconds(time_t Hours, time_t Minutes, time_t Seconds,
			MERIDIAN Meridian)
{
    if (Minutes < 0 || Minutes > 59 || Seconds < 0 || Seconds > 59)
	return -1;
    switch (Meridian) {
    case MER24:
	if (Hours < 0 || Hours > 23)
	    return -1;
	return (Hours * 60L + Minutes) * 60L + Seconds;
    case MERam:
	if (Hours < 1 || Hours > 12)
	    return -1;
	if (Hours == 12)
	    Hours = 0;
	return (Hours * 60L + Minutes) * 60L + Seconds;
    case MERpm:
	if (Hours < 1 || Hours > 12)
	    return -1;
	if (Hours == 12)
	    Hours = 0;
	return ((Hours + 12) * 60L + Minutes) * 60L + Seconds;
    }

    return -1;
}


static time_t Convert(time_t Month, time_t Day, time_t Year,
		      time_t Hours, time_t Minutes, time_t Seconds,
		      MERIDIAN Meridian, DSTMODE DSTmode, time_t yyTimezone)
{
    static int DaysInMonth[12] = {
	31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
    time_t	tod;
    time_t	Julian;
    int		i;

    if (Year < 0)
	Year = -Year;
    if (Year < 70)
	Year += 2000;
    else if (Year < 100)
	Year += 1900;
    DaysInMonth[1] = Year % 4 == 0 && (Year % 100 != 0 || Year % 400 == 0)
		    ? 29 : 28;
    /* Checking for 2038 bogusly assumes that time_t is 32 bits.  But
       I'm too lazy to try to check for time_t overflow in another way.  */
    if (Year < EPOCH || Year > 2038
     || Month < 1 || Month > 12
     /* Lint fluff:  "conversion from long may lose accuracy" */
     || Day < 1 || Day > DaysInMonth[(int)--Month])
	return -1;

    for (Julian = Day - 1, i = 0; i < Month; i++)
	Julian += DaysInMonth[i];
    for (i = EPOCH; i < Year; i++)
	Julian += 365 + (i % 4 == 0);
    Julian *= SECSPERDAY;
    Julian += yyTimezone * 60L;
    if ((tod = ToSeconds(Hours, Minutes, Seconds, Meridian)) < 0)
	return -1;
    Julian += tod;
    if (DSTmode == DSTon
     || (DSTmode == DSTmaybe && localtime(&Julian)->tm_isdst))
	Julian -= 60 * 60;
    return Julian;
}


static time_t DSTcorrect(time_t Start, time_t Future)
{
    time_t	StartDay;
    time_t	FutureDay;

    StartDay = (localtime(&Start)->tm_hour + 1) % 24;
    FutureDay = (localtime(&Future)->tm_hour + 1) % 24;
    return (Future - Start) + (StartDay - FutureDay) * 60L * 60L;
}


static time_t RelativeDate(time_t Start, time_t DayOrdinal, time_t DayNumber)
{
    struct tm	*tm;
    time_t	now;

    now = Start;
    tm = localtime(&now);
    now += SECSPERDAY * ((DayNumber - tm->tm_wday + 7) % 7);
    now += 7 * SECSPERDAY * (DayOrdinal <= 0 ? DayOrdinal : DayOrdinal - 1);
    return DSTcorrect(Start, now);
}


static time_t RelativeMonth(time_t Start, time_t RelMonth, time_t yyTimezone)
{
    struct tm	*tm;
    time_t	Month;
    time_t	Year;

    if (RelMonth == 0)
	return 0;
    tm = localtime(&Start);
    Month = 12 * tm->tm_year + tm->tm_mon + RelMonth;
    Year = Month / 12 + 1900;
    Month = Month % 12 + 1;
    return DSTcorrect(Start,
	    Convert(Month, (time_t)tm->tm_mday, Year,
		(time_t)tm->tm_hour, (time_t)tm->tm_min, (time_t)tm->tm_sec,
		MER24, DSTmaybe, yyTimezone));
}


static void SetPossibleDate(struct Variables * var,
			      time_t possible_day,
			      time_t possible_month,
			      time_t possible_year)
{
    int date_order;

    if (possible_day > 31) /* test for ymd */
	date_order = 2;
    else if (possible_day > 12) /* test for dmy */
	date_order = 1;
    else if (possible_month > 12) /* test for mdy */
	date_order = 0;
    else
	date_order = PTimeGetDateOrder();

    switch (date_order) {
      case 0 :
	var->yyDay   = possible_month;
	var->yyMonth = possible_day;
	var->yyYear  = possible_year;
	break;
      case 1 :
	var->yyDay   = possible_day;
	var->yyMonth = possible_month;
	var->yyYear  = possible_year;
	break;
      default :
	var->yyDay   = possible_year;
	var->yyMonth = possible_month;
	var->yyYear  = possible_day;
    }
}


time_t STDAPICALLTYPE PTimeParse(void * inputStream, struct tm * now, int timezone)
{
    time_t		Start;
    struct Variables	var;


    var.yyInput = inputStream;
    var.yyYear = now->tm_year + 1900;
    var.yyMonth = now->tm_mon + 1;
    var.yyDay = now->tm_mday;
    var.yyTimezone = -timezone;
    var.yyDSTmode = DSTmaybe;
    var.yyHour = 0;
    var.yyMinutes = 0;
    var.yySeconds = 0;
    var.yyMeridian = MER24;
    var.yyRelSeconds = 0;
    var.yyRelMonth = 0;
    var.yyHaveDate = 0;
    var.yyHaveDay = 0;
    var.yyHaveRel = 0;
    var.yyHaveTime = 0;
    var.yyHaveZone = 0;

    yyparse(&var);

    if (var.yyHaveTime > 1 || var.yyHaveZone > 1 ||
	var.yyHaveDate > 1 || var.yyHaveDay > 1)
	return -1;

    if (var.yyHaveTime == 0 && var.yyHaveZone == 0 &&
	var.yyHaveDate == 0 && var.yyHaveDay == 0 && var.yyHaveRel == 0)
	return -1;

    if (var.yyHaveDate || var.yyHaveTime || var.yyHaveDay) {
	Start = Convert(var.yyMonth, var.yyDay, var.yyYear,
			var.yyHour, var.yyMinutes, var.yySeconds,
			var.yyMeridian, var.yyDSTmode, var.yyTimezone);
	if (Start < 0)
	    return -1;
    }
    else {
	time(&Start);
	if (!var.yyHaveRel)
	    Start -= ((now->tm_hour * 60L + now->tm_min) * 60L) + now->tm_sec;
    }

    Start += var.yyRelSeconds;
    Start += RelativeMonth(Start, var.yyRelMonth, var.yyTimezone);

    if (var.yyHaveDay && !var.yyHaveDate)
	Start += RelativeDate(Start, var.yyDayOrdinal, var.yyDayNumber);

    /* Have to do *something* with a legitimate -1 so it's distinguishable
     * from the error return value.  (Alternately could set errno on error.) */
    return Start == -1 ? 0 : Start;
}


#ifdef _MSC_VER
#pragma warning(disable:4028 4100 4211)
#endif

#ifdef __GNUC__
int yyerror(const char * s)
{
  return 0;
}
#else
static void yyerror(const char * s)
{
}
#endif

#ifdef _MSC_VER
#pragma warning(default:4028 4100 4211)
#endif


/* End of file ***************************************************************/
