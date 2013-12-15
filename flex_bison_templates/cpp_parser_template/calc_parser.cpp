/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2010 Free Software Foundation, Inc.
   
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

// Take the name prefix into account.
#define yylex   calc_lex

/* First part of user declarations.  */


/* Line 310 of lalr1.cc  */
#line 41 "D:/Development/templates/parser_template/sources/calc_parser.cpp"


#include "calc_parser.hpp"

/* User implementation prologue.  */


/* Line 316 of lalr1.cc  */
#line 50 "D:/Development/templates/parser_template/sources/calc_parser.cpp"
/* Unqualified %code blocks.  */

/* Line 317 of lalr1.cc  */
#line 38 "D:/Development/templates/parser_template/sources/calc.y"

#include "calc_driver.hpp"



/* Line 317 of lalr1.cc  */
#line 61 "D:/Development/templates/parser_template/sources/calc_parser.cpp"

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace calc_ {

/* Line 379 of lalr1.cc  */
#line 127 "D:/Development/templates/parser_template/sources/calc_parser.cpp"
#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  calc_parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
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
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

#endif

  /// Build a parser object.
  calc_parser::calc_parser (yyscan_t yyscanner_yyarg, calc_driver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      yyscanner (yyscanner_yyarg),
      driver (driver_yyarg)
  {
  }

  calc_parser::~calc_parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  calc_parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
        case 11: /* "\"identifier\"" */

/* Line 448 of lalr1.cc  */
#line 59 "D:/Development/templates/parser_template/sources/calc.y"
	{ debug_stream () << *(yyvaluep->sval); };

/* Line 448 of lalr1.cc  */
#line 205 "D:/Development/templates/parser_template/sources/calc_parser.cpp"
	break;
      case 19: /* "function_declaration" */

/* Line 448 of lalr1.cc  */
#line 59 "D:/Development/templates/parser_template/sources/calc.y"
	{ debug_stream () << *(yyvaluep->sval); };

/* Line 448 of lalr1.cc  */
#line 214 "D:/Development/templates/parser_template/sources/calc_parser.cpp"
	break;
      case 20: /* "function_header" */

/* Line 448 of lalr1.cc  */
#line 59 "D:/Development/templates/parser_template/sources/calc.y"
	{ debug_stream () << *(yyvaluep->sval); };

/* Line 448 of lalr1.cc  */
#line 223 "D:/Development/templates/parser_template/sources/calc_parser.cpp"
	break;
       default:
	  break;
      }
  }


  void
  calc_parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  calc_parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
        case 11: /* "\"identifier\"" */

/* Line 479 of lalr1.cc  */
#line 60 "D:/Development/templates/parser_template/sources/calc.y"
	{ delete (yyvaluep->sval); };

/* Line 479 of lalr1.cc  */
#line 262 "D:/Development/templates/parser_template/sources/calc_parser.cpp"
	break;
      case 19: /* "function_declaration" */

/* Line 479 of lalr1.cc  */
#line 60 "D:/Development/templates/parser_template/sources/calc.y"
	{ delete (yyvaluep->sval); };

/* Line 479 of lalr1.cc  */
#line 271 "D:/Development/templates/parser_template/sources/calc_parser.cpp"
	break;
      case 20: /* "function_header" */

/* Line 479 of lalr1.cc  */
#line 60 "D:/Development/templates/parser_template/sources/calc.y"
	{ delete (yyvaluep->sval); };

/* Line 479 of lalr1.cc  */
#line 280 "D:/Development/templates/parser_template/sources/calc_parser.cpp"
	break;

	default:
	  break;
      }
  }

  void
  calc_parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  calc_parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  calc_parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  calc_parser::debug_level_type
  calc_parser::debug_level () const
  {
    return yydebug_;
  }

  void
  calc_parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  int
  calc_parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    
/* Line 552 of lalr1.cc  */
#line 24 "D:/Development/templates/parser_template/sources/calc.y"
{
    // Initialize the initial location.
    yylloc.begin.filename = yylloc.end.filename = &driver.file;
}

/* Line 552 of lalr1.cc  */
#line 366 "D:/Development/templates/parser_template/sources/calc_parser.cpp"

    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yyn == yypact_ninf_)
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, &yylloc, yyscanner, driver);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yyn == 0 || yyn == yytable_ninf_)
	goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 5:

/* Line 677 of lalr1.cc  */
#line 73 "D:/Development/templates/parser_template/sources/calc.y"
    { std::cout << "class: " << *(yysemantic_stack_[(5) - (2)].sval) << std::endl; }
    break;

  case 9:

/* Line 677 of lalr1.cc  */
#line 82 "D:/Development/templates/parser_template/sources/calc.y"
    { std::cout << "function: " << *(yysemantic_stack_[(1) - (1)].sval) << std::endl; }
    break;

  case 12:

/* Line 677 of lalr1.cc  */
#line 87 "D:/Development/templates/parser_template/sources/calc.y"
    { (yyval.sval) = (yysemantic_stack_[(2) - (1)].sval); }
    break;

  case 13:

/* Line 677 of lalr1.cc  */
#line 88 "D:/Development/templates/parser_template/sources/calc.y"
    { (yyval.sval) = (yysemantic_stack_[(2) - (1)].sval); }
    break;

  case 14:

/* Line 677 of lalr1.cc  */
#line 91 "D:/Development/templates/parser_template/sources/calc.y"
    { (yyval.sval) = (yysemantic_stack_[(5) - (2)].sval); }
    break;



/* Line 677 of lalr1.cc  */
#line 520 "D:/Development/templates/parser_template/sources/calc_parser.cpp"
	default:
          break;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[0] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
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
    if (false)
      goto yyerrorlab;

    yyerror_range[0] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (yyn != yypact_ninf_)
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[0] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval, &yylloc);

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  calc_parser::yysyntax_error_ (int yystate, int tok)
  {
    std::string res;
    YYUSE (yystate);
#if YYERROR_VERBOSE
    int yyn = yypact_[yystate];
    if (yypact_ninf_ < yyn && yyn <= yylast_)
      {
	/* Start YYX at -YYN if negative to avoid negative indexes in
	   YYCHECK.  */
	int yyxbegin = yyn < 0 ? -yyn : 0;

	/* Stay within bounds of both yycheck and yytname.  */
	int yychecklim = yylast_ - yyn + 1;
	int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
	int count = 0;
	for (int x = yyxbegin; x < yyxend; ++x)
	  if (yycheck_[x + yyn] == x && x != yyterror_)
	    ++count;

	// FIXME: This method of building the message is not compatible
	// with internationalization.  It should work like yacc.c does it.
	// That is, first build a string that looks like this:
	// "syntax error, unexpected %s or %s or %s"
	// Then, invoke YY_ on this string.
	// Finally, use the string as a format to output
	// yytname_[tok], etc.
	// Until this gets fixed, this message appears in English only.
	res = "syntax error, unexpected ";
	res += yytnamerr_ (yytname_[tok]);
	if (count < 5)
	  {
	    count = 0;
	    for (int x = yyxbegin; x < yyxend; ++x)
	      if (yycheck_[x + yyn] == x && x != yyterror_)
		{
		  res += (!count++) ? ", expecting " : " or ";
		  res += yytnamerr_ (yytname_[x]);
		}
	  }
      }
    else
#endif
      res = YY_("syntax error");
    return res;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const signed char calc_parser::yypact_ninf_ = -28;
  const signed char
  calc_parser::yypact_[] =
  {
       -28,     3,     6,   -28,     1,   -28,     9,   -28,    10,    -1,
     -28,     8,     7,   -28,   -28,    -2,   -28,   -28,    11,   -28,
     -28,   -28,    12,     0,    13,    14,     5,   -28,    17,   -28,
      -3,   -28,    18,    19,   -28,   -28,    20,   -28,    21,   -28,
     -28,   -28,    13,   -28,   -28,    16,    12,     5,    22,   -28
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  calc_parser::yydefact_[] =
  {
         3,     0,     2,     1,     0,     4,     0,     7,     0,     0,
       5,     0,     0,     8,     9,     0,    10,    11,    26,    21,
      12,    13,    15,     0,     0,     0,    16,    17,     0,    20,
       0,    22,     0,     0,    19,    14,     0,    25,     0,    26,
      23,    24,    31,    18,    30,     0,    28,    29,     0,    27
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  calc_parser::yypgoto_[] =
  {
       -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,
     -27,   -16,   -28,   -28,   -28,    15,   -28,   -28,   -28
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  calc_parser::yydefgoto_[] =
  {
        -1,     1,     2,     5,     8,     9,    13,    14,    15,    25,
      26,    27,    21,    23,    31,    16,    33,    48,    44
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char calc_parser::yytable_ninf_ = -7;
  const signed char
  calc_parser::yytable_[] =
  {
        11,    28,    19,     3,    -6,    29,    20,    38,    39,     4,
      12,    30,     6,     7,    36,    10,    17,    22,    18,    47,
      43,    35,    46,    24,    34,    37,    40,    41,     0,    49,
       0,    42,    45,     0,     0,     0,     0,     0,    32
  };

  /* YYCHECK.  */
  const signed char
  calc_parser::yycheck_[] =
  {
         1,     1,     4,     0,     5,     5,     8,    10,    11,     3,
      11,    11,    11,     4,     9,     5,     8,     6,    11,    46,
      36,     7,     6,    11,    11,     8,     8,     8,    -1,     7,
      -1,    11,    11,    -1,    -1,    -1,    -1,    -1,    23
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  calc_parser::yystos_[] =
  {
         0,    13,    14,     0,     3,    15,    11,     4,    16,    17,
       5,     1,    11,    18,    19,    20,    27,     8,    11,     4,
       8,    24,     6,    25,    11,    21,    22,    23,     1,     5,
      11,    26,    27,    28,    11,     7,     9,     8,    10,    11,
       8,     8,    11,    23,    30,    11,     6,    22,    29,     7
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  calc_parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   123,   125,    40,    41,    59,    44,
      46,   259
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  calc_parser::yyr1_[] =
  {
         0,    12,    13,    14,    14,    15,    16,    17,    17,    18,
      18,    18,    19,    19,    20,    21,    21,    22,    22,    23,
      24,    25,    25,    26,    26,    26,    27,    28,    29,    29,
      22,    30
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  calc_parser::yyr2_[] =
  {
         0,     2,     1,     0,     2,     5,     1,     0,     2,     1,
       1,     2,     2,     2,     5,     0,     1,     1,     3,     2,
       3,     0,     2,     2,     2,     2,     2,     6,     0,     1,
       3,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const calc_parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "\"class\"", "'{'", "'}'",
  "'('", "')'", "';'", "','", "'.'", "\"identifier\"", "$accept", "unit",
  "declarations", "declaration", "class_body", "class_elements",
  "class_element", "function_declaration", "function_header",
  "argument_list", "non_empty_argument_list", "argument", "function_body",
  "statements", "statement", "var_declaration", "function_call",
  "call_argument_list", "call_argument", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const calc_parser::rhs_number_type
  calc_parser::yyrhs_[] =
  {
        13,     0,    -1,    14,    -1,    -1,    14,    15,    -1,     3,
      11,     4,    16,     5,    -1,    17,    -1,    -1,    17,    18,
      -1,    19,    -1,    27,    -1,     1,     8,    -1,    20,     8,
      -1,    20,    24,    -1,    11,    11,     6,    21,     7,    -1,
      -1,    22,    -1,    23,    -1,    22,     9,    23,    -1,    11,
      11,    -1,     4,    25,     5,    -1,    -1,    25,    26,    -1,
      27,     8,    -1,    28,     8,    -1,     1,     8,    -1,    11,
      11,    -1,    11,    10,    11,     6,    29,     7,    -1,    -1,
      22,    -1,    22,     9,    30,    -1,    11,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  calc_parser::yyprhs_[] =
  {
         0,     0,     3,     5,     6,     9,    15,    17,    18,    21,
      23,    25,    28,    31,    34,    40,    41,    43,    45,    49,
      52,    56,    57,    60,    63,    66,    69,    72,    79,    80,
      82,    86
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned char
  calc_parser::yyrline_[] =
  {
         0,    66,    66,    69,    70,    73,    76,    79,    80,    82,
      83,    84,    87,    88,    91,    94,    95,    98,    99,   102,
     105,   108,   109,   112,   113,   114,   117,   120,   123,   124,
     127,   130
  };

  // Print the state stack on the debug stream.
  void
  calc_parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  calc_parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  calc_parser::token_number_type
  calc_parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       6,     7,     2,     2,     9,     2,    10,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     8,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     4,     2,     5,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,    11
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int calc_parser::yyeof_ = 0;
  const int calc_parser::yylast_ = 38;
  const int calc_parser::yynnts_ = 19;
  const int calc_parser::yyempty_ = -2;
  const int calc_parser::yyfinal_ = 3;
  const int calc_parser::yyterror_ = 1;
  const int calc_parser::yyerrcode_ = 256;
  const int calc_parser::yyntokens_ = 12;

  const unsigned int calc_parser::yyuser_token_number_max_ = 259;
  const calc_parser::token_number_type calc_parser::yyundef_token_ = 2;


} // calc_

/* Line 1053 of lalr1.cc  */
#line 970 "D:/Development/templates/parser_template/sources/calc_parser.cpp"


/* Line 1055 of lalr1.cc  */
#line 133 "D:/Development/templates/parser_template/sources/calc.y"


void calc_::calc_parser::error (const calc_::calc_parser::location_type& l,
                          const std::string& m)
{
    driver.error (l, m);
}

