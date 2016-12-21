#include <stdio.h>
#include <stdlib.h>
#include "includes/student_db.h"
#include "includes/forward_list.h"

/*
void module_disp(module_t md) {
  puts(md._name);
  printf("%d\n%d\n", md._credit, md._coef);
}
*/

int* int_make(int x) {
  int* r = malloc(sizeof(int));
  *r = x;
  return r;
}

void print(void* addr) {
  printf("%d ", *(int*)addr);
}

int main(void) {
  /*
  for (int i = 0; i < 7; ++i) {
    module_disp(mds[i]);
  }
  */

  forward_list_t list = forward_list_create(free);
  for (int i = 0; i < 10; ++i)
    forward_list_push_front(&list, int_make(i));

  forward_list_for_each(&list, print);
  printf("\n");

  forward_list_clear(&list);
}