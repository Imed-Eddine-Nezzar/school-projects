#ifndef __INCLUDES_MODULEDEF_H__
#define __INCLUDES_MODULEDEF_H__

#include <stdlib.h>
#include "util.h"

/** @struct module_t
 *  @brief
 */
typedef struct {
  char* _name;            ///< module name
  short _coef;            ///< module coef
  short _credit;          ///< module credit
} module_t;

const char* module_name(module_t* mod) {
  return mod->_name;
}

short module_coef(module_t* mod) {
  return mod->_coef;
}

short module_credit(module_t* mod) {
  return mod->_credit;
}

#endif // __INCLUDES_MODULEDEF_H__