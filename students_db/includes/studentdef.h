#ifndef __INCLUDES_STUDENTDEF_H__
#define __INCLUDES_STUDENTDEF_H__

#include <stdio.h>        // printf
#include <stdlib.h>       // malloc
#include "util.h"

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

/** @fn void student_display(student_ptr)
 *  @brief
 */
void student_display(student_ptr s) {
  printf(
    "id: %u\n"
    "first name: %s\n"
    "last name: %s\n"
    "group: %d\n"
    "credit: %d\n",
    s->_id, s->_fname, s->_lname, s->_group, s->_credit);
}

float student_calc_average(student_ptr s, short n) {
  float sum = 0;
  for (float* g = s->_grades; g != s->_grades + n; ++g)
    sum += *g;
  s->_average = sum / n;
  return s->_average;
}

#endif // __INCLUDES_STUDENTDEF_H__