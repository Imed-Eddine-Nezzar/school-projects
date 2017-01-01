#ifndef __INCLUDES_FORWARD_LIST_H__
#define __INCLUDES_FORWARD_LIST_H__

#include <stdlib.h>   // malloc
#include <string.h>   // memcpy
#include <assert.h>   // assert

/***********************************************
* forward node
**/

/** @struct forward_node_t
 *  @brief
 */
typedef struct forward_node {
  void* _data;                          ///< data pointer
  struct forward_node* _next;           ///< next forward_node_t pointer
} forward_node_t, *forward_node_ptr;


/** @fn     static forward_node_ptr forward_nodemake(void*, size_t, forward_node_ptr)
 *  @brief  return a forward_node_t
 */
static forward_node_ptr forward_node_make(void* data, forward_node_ptr next) {
  forward_node_ptr fnode = malloc(sizeof(forward_node_t));
  assert(fnode != NULL);
  fnode->_data = data;
  fnode->_next = next;
  return fnode;
}


/** @fn     void forward_node_clear(forward_node_ptr, void (*)(void*))
 *  @brief
 */
static void forward_node_clear(forward_node_ptr fnode, void (*deleter)(void*)) {
  if (deleter) deleter(fnode->_data);
}

/***********************************************
* forward list
**/

/** @struct forward_list_t
 *  @brief
 */
typedef struct {
  forward_node_ptr _head;     ///< list head
  void (*_deleter)(void*);    ///< element deleter
} forward_list_t;

int forward_list_empty(forward_list_t* list) {
  return list->_head == NULL;
}


/** @fn     forward_list_t forward_list_create(size_t, void (*)(void*))
 *  @brief
 */
forward_list_t forward_list_create(void (*deleter)(void*)) {
  forward_list_t flist;
  flist._head = NULL;
  flist._deleter = deleter;
  return flist;
}

/** @fn     void forward_list_clear(forward_list_t*)
 *  @brief
 */
void forward_list_clear(forward_list_t* flist) {
  forward_node_ptr it;
  while (!forward_list_empty(flist)) {
    it = flist->_head;
    flist->_head = it->_next;
    forward_node_clear(it, flist->_deleter);
    free(it);
  }
  flist->_head = NULL;
}

/** @fn     void forward_ist_push_front(forward_list_t*, void*)
 *  @brief
 */
void forward_list_push_front(forward_list_t* flist, void* data) {
  flist->_head = forward_node_make(data, flist->_head);
}

/** @fn     void forward_list_for_each(forward_list_t*, void (*)(void*))
 *  @brief
 */
void forward_list_for_each(forward_list_t* flist, void (*anary_op)(void*)) {
  for (forward_node_ptr it = flist->_head; it != NULL; it = it->_next) {
    anary_op(it->_data);
  }
}

/** @fn     void forward_list_select(forward_list_t*, void (*)(void*, void*))
 *  @brief
 */
void* forward_list_select(forward_list_t* list, int (*bin_pred)(void*,void*)) {
  if (!forward_list_empty(list)) {
    forward_node_ptr res = list->_head;
    for (forward_node_ptr it = res->_next; it != NULL; it = it->_next) {
      if (bin_pred(it->_data, res->_data))
        res = it;
    }
    return res->_data;
  }
  return NULL;
}

#endif // __INCLUDES_FORWARD_LIST_H__