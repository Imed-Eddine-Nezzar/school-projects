#include <stdio.h>
#include <stdlib.h>
#include "includes/forward_list.h"
#include "includes/db_core.h"
#include "includes/menu.h"

#define __array_size(arr) sizeof((arr)) / sizeof(*(arr))

static const char* options[] = {
  "add student",
  "display averages",
  "display credit",
  "display top student"
};
const size_t noptions = __array_size(options);

static module_t modules[] = {
  {"TL", 2, 4},
  {"ALG && SDD", 3, 6},
  {"SI", 3, 4},
  {"Math Logique", 2, 4},
  {"POO", 3, 5},
  {"AO", 2, 5},
  {"Anglais", 1, 2}
};
const size_t nmodules = __array_size(modules);

student_t* read_student() {
  printf("Student information:\n");
  unsigned id;
  printf("id: ");
  scanf("%u", &id);

  char fname[30];
  printf("first name: ");
  scanf("%29s", fname);

  char lname[30];
  printf("last name: ");
  scanf("%29s", lname);

  short group;
  printf("group: ");
  scanf("%hd", &group);

  float grades[7];
  printf("grades:\n");
  for (int i = 0; i < 7; ++i) {
    printf("%15s: ", module_name(modules + i));
    scanf("%f", (grades + i));
  }

  return student_make(id, fname, lname, group, grades, 7);
}

void _calc_average(void* s) {
  student_calc_average((student_ptr)s, 7);
}

void calc_average(forward_list_t* list) {
  forward_list_for_each(list, _calc_average);
}

void _calc_credit(void* s) {
  student_calc_credit((student_ptr)s, modules, 7, 10.0);
}

void calc_credit(forward_list_t* list) {
  forward_list_for_each(list, _calc_credit);
}

int _student_average_cmp(void* a, void* b) {
  student_ptr x = a;
  student_ptr y = b;
  return x->_average > y->_average;
}

student_ptr top_student(forward_list_t* list) {
  return forward_list_select(list, _student_average_cmp);
}


int main(void) {
  forward_list_t students = forward_list_create((void (*)(void*)) student_del);
  int input;
  do {
    printf("\nStudent data base:\n"
             "==================\n");
    input = menu_display("option [0 to exit]: ", options, noptions);
    switch(input) {
      case 1: {
        student_ptr s = read_student();
        forward_list_push_front(&students, s);
        break;
      }

      case 2: {
        calc_average(&students);
        break;
      }

      case 3: {
        calc_credit(&students);
        break;
      }

      case 4: {
        student_display(top_student(&students));
        break;
      }

      case 0: {
        goto terminate;
      }

      default: printf("Unknown Option!\n");
    }
  } while (1);

  terminate:
    forward_list_clear(&students);
    return EXIT_SUCCESS;
}