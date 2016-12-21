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
} module_t, *module_ptr;


/** @fn module_t module_make(const char*, short, short)
 *  @brief
 */
module_t module_make(const char* name,
                     short coef,
                     short credit) {
  module_t md;
  md._name = memdup(name, strlen(name) + 1);
  md._coef = coef;
  md._credit = credit;
  return md;
}


/** @fn void module_de(module_ptr)
 *  @brief
 */
void module_del(module_ptr md) {
  free(md->_name);
}

#endif // __INCLUDES_MODULEDEF_H__