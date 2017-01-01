#ifndef __INCLUDES_MENU_H__
#define __INCLUDES_MENU_H__

#include <stdio.h>        // scanf, fgets
#include <stddef.h>       // size_t
#include <math.h>         // log
#include "util.h"         // istream_ignore

/** @fn
 *  @brief
 */
int menu_display(const char* prompt, const char** choices, size_t n) {
  for (int i = 0; i < n; ++i) {
    printf("[%d] - %s\n", i + 1, choices[i]);
  }
  fputs(prompt, stdout);
  int input;
  scanf("%d", &input);
  return input;
}

#endif // __INCLUDES_MENU_H__