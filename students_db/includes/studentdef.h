#ifndef __INCLUDES_STUDENTDEF_H__
#define __INCLUDES_STUDENTDEF_H__

#include <stdio.h>        // printf
#include <stdlib.h>       // malloc
#include "util.h"
#include "moduledef.h"

/** @struct student_t
 *  @brief
 */
typedef struct {
  unsigned _id;               ///< student id
  char* _fname;               ///< student first name
  char* _lname;               ///< student last name
  short _group;               ///< student group
  float* _grades;             ///< student grades
  float _average;             ///< sutdent average
  short _credit;              ///< student credit
} student_t, *student_ptr;

/** @fn void student_init(student_ptr, unsigned, const char*, const char*, short, const float*, short)
 *  @brief
 */
void student_init(student_ptr s, unsigned id,
                  const char* fname, const char* lname,
                  short group,
                  const float* grades, short n) {
  s->_id = id;
  s->_fname = memdup(fname, strlen(fname) + 1);
  s->_lname = memdup(lname, strlen(lname) + 1);
  s->_group = group;
  s->_grades = memdup(grades, n * sizeof(float));
}

/** @fn student_ptr sutdent_make(unsigned, const char*, const char*, short, const float*, short n)
 *  @brief
 */
student_ptr student_make(unsigned id,
                         const char* fname, const char* lname,
                         short group,
                         const float* grades, short n) {
  student_ptr s = malloc(sizeof(student_t));
  student_init(s, id, fname, lname, group, grades, n);
  return s;
}


/** @fn void student_clear(student_ptr)
 *  @brief
 */
void student_clear(student_ptr s) {
  free(s->_fname);
  free(s->_lname);
  free(s->_grades);
}

void student_del(student_ptr s) {
  student_clear(s);
  free(s);
}

/** @fn void student_display(student_ptr)
 *  @brief
 */
void student_display(student_ptr s) {
  if (s) {
    printf(
      "\nStudent info:\n"
      "=============\n"
      "        id: %u\n"
      "first name: %s\n"
      " last name: %s\n"
      "     group: %d\n"
      "   average: %.2f\n"
      "    credit: %d\n",
      s->_id, s->_fname, s->_lname, s->_group, s->_average, s->_credit);
  }
}

float student_calc_average(student_ptr s, const module_t* modules, short n) {
  s->_average = 0;
  int totla_credit = 0;
  for (int i = 0; i < n; ++i) {
    s->_average += s->_grades[i] * modules[i]._credit;
    totla_credit += modules[i]._credit;
  }

  s->_average /= totla_credit;
  return s->_average;
}

unsigned student_calc_credit(student_ptr s, module_t* modules_table, short n, float base) {
  s->_credit = 0;
  for (int i = 0; i < n; ++i) {
    if (s->_grades[i] >= base)
      s->_credit += module_credit(modules_table + i);
  }
  return s->_credit;
}

#endif // __INCLUDES_STUDENTDEF_H__
