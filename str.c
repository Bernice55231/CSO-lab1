#include <stdio.h>
#include <assert.h>

#include "string.h"


// Return the length of the string pointed to by "s".
//
// Note: C standard library function strlen accomplishes
// exactly the same functionality as string_len. In this exercise,
// please do not use strlen. In subsequent exercises (list.c, htable.c), 
// it is recommended that you use strlen instead of string_len
int string_len(char *s)
{
  int i = 0;
  while (s[i] != '\0') {
    i++;
  }
  return i;
}

// Compare strings "s1" and "s2". It returns less than, equal to or great than zero 
// if "s1" is found to be less than, match, or larger than "s2" alphabetically.
// For example, string_cmp("aa", "aaa") should return a negative number
// and string_cmp("aa", "a0") should return a positive number
// Note that we use the ASCII values of characters as basis for comparison.
// As the ascii value of 'a' is greater than the ascii value of '0', 
// "aa" is considered to be greater than "a0".
//
// Note: C standard library function strcmp accomplishes
// exactly the same functionality as string_cmp. In this exercise,
// please do not use strcmp. In subsequent exercises (list.c, htable.c), 
// it is recommended that you use strcmp instead of string_cmp.
int string_cmp(char *s1, char *s2)
{
  int len1 = string_len(s1);
  int len2 = string_len(s2);
  int count = 0;
  while (len1 > 0 && len2 > 0) {
    if (s1[count] < s2[count])
      return -1;
    else if (s1[count] > s2[count])
      return 1;
    else {
      len1--;
      len2--;
      count++;
    }
  }
  if (len1 > len2)
    return 1;
  else if (len1 < len2)
    return -1;
  else 
    return 0;
}

// Convert integer x into hex format and store the resulting hex string to "str",
// e.g. if x=16, then str should be "00000010".
// If x=26, then str should be "0000001a";
// The resulting hex string should always have exactly 8 hex characters 
// followed by the null character.
// We assume the caller has allocated an array of at least 9 characters for "str", 
// Note: please do not use formatted output, such as sprintf
void int_to_hex(unsigned int x, char *str) 
{
  str[8] = '\0';
  int counter = 7;
  unsigned int n = x;
  while (n != 0) {
    int remainder = n % 16;
    n = n / 16;
    if (remainder < 10) 
      str[counter] = remainder + '0';
    else
      str[counter] = 'a' + remainder - 10;
    counter--;
  }
  while (counter>=0) {
    str[counter] = '0';
    counter--;
  }
}