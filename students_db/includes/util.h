#ifndef __INCLUDES_UTIL_H__
#define __INCLUDES_UTIL_H__

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

#endif // __INCLUDES_UTIL_H__