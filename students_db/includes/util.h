#ifndef __INCLUDES_UTIL_H__
#define __INCLUDES_UTIL_H__

#include <stdio.h>        // FILE
#include <string.h>       // memcpy
#include <stdlib.h>       // malloc
#include <stddef.h>       // size_t

/** @fn void* memdup(const void*, size_t)
 *  @brief
 */
void* memdup(const void* addr, size_t n) {
  void* cp = malloc(n);
  memcpy(cp, addr, n);
  return cp;
}

/** @fn void isflush(FILE* instream)
 *  @brief
 */
void istream_ignore(FILE* instream, int d) {
  for (int c; (c = fgetc(instream)) != EOF && c != d;);
}

#endif // __INCLUDES_UTIL_H__