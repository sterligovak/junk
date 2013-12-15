/* C++ code produced by gperf version 3.0.1 */
/* Command-line: /usr/bin/gperf -L C++ --output-file=D:/_PROJECTS/others/gperf_template/sources/months.cpp months.gperf  */
/* Computed positions: -k'1,3' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gnu-gperf@gnu.org>."
#endif

#line 1 "months.gperf"

#include <stdio.h>
#include <string.h>
#line 7 "months.gperf"
struct month { char *name; int number; int days; int leap_days; };

#define TOTAL_KEYWORDS 12
#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 9
#define MIN_HASH_VALUE 3
#define MAX_HASH_VALUE 18
/* maximum key range = 16, duplicates = 0 */

class MonthsHashTable
{
private:
  static inline unsigned int hash (const char *str, unsigned int len);
public:
  static struct month *in_word_set (const char *str, unsigned int len);
};

inline unsigned int
MonthsHashTable::hash (register const char *str, register unsigned int len)
{
  static unsigned char asso_values[] =
    {
      19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
      19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
      19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
      19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
      19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
      19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
      19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
      19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
      19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
      19, 19, 19, 19, 19, 19, 19,  5,  5,  5,
       0, 19,  5,  0, 19, 19,  0, 19, 10,  0,
       0,  5,  0, 19,  0,  0,  0, 19,  0, 19,
      19,  0, 19, 19, 19, 19, 19, 19, 19, 19,
      19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
      19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
      19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
      19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
      19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
      19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
      19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
      19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
      19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
      19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
      19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
      19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
      19, 19, 19, 19, 19, 19
    };
  return len + asso_values[(unsigned char)str[2]] + asso_values[(unsigned char)str[0]];
}

struct month *
MonthsHashTable::in_word_set (register const char *str, register unsigned int len)
{
  static struct month wordlist[] =
    {
      {""}, {""}, {""},
#line 13 "months.gperf"
      {"may",       5, 31, 31},
#line 14 "months.gperf"
      {"june",      6, 30, 30},
#line 11 "months.gperf"
      {"march",     3, 31, 31},
      {""},
#line 9 "months.gperf"
      {"january",   1, 31, 31},
#line 19 "months.gperf"
      {"november", 11, 30, 30},
#line 17 "months.gperf"
      {"september", 9, 30, 30},
#line 12 "months.gperf"
      {"april",     4, 30, 30},
#line 16 "months.gperf"
      {"august",    8, 31, 31},
#line 18 "months.gperf"
      {"october",  10, 31, 31},
#line 20 "months.gperf"
      {"december", 12, 31, 31},
#line 15 "months.gperf"
      {"july",      7, 31, 31},
      {""}, {""}, {""},
#line 10 "months.gperf"
      {"february",  2, 28, 29}
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= 0)
        {
          register const char *s = wordlist[key].name;

          if (*str == *s && !strcmp (str + 1, s + 1))
            return &wordlist[key];
        }
    }
  return 0;
}
#line 21 "months.gperf"

int main()
{
	char buf[BUFSIZ];
	while (gets(buf)) {
		const month *p = MonthsHashTable::in_word_set(buf, strlen (buf));
		if ( p )
		{
			printf ("%s is a month number %i\n", p->name, p->number );
		}
		else
		{
			printf( "%s is not a month\n", buf );
		}
	}
	return 0;	
}