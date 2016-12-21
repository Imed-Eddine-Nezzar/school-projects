#ifndef __INCLUDES_FORWARD_LIST_H__
#define __INCLUDES_FORWARD_LIST_H__

#include <stdlib.h>   // malloc
#include <string.h>   // memcpy

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
  fnode->_data = data;
  fnode->_next = next;
  return fnode;
}


/** @fn     void forward_node_clear(forward_node_ptr, void (*)(void*))
 *  @brief
 */
static void forward_node_clear(forward_node_ptr fnode, void (*deleter)(void*)) {
  deleter(fnode->_data);
}

/***********************************************
* forward list
**/

/** @struct forward_list_t
 *  @brief
 */
typedef struct {
  forward_node_ptr _head;     ///< list head
  forward_node_ptr _tail;     ///< list tail
  size_t _size;               ///< list size
  void (*_deleter)(void*);    ///< element deleter
} forward_list_t;


/** @fn     forward_list_t forward_list_create(size_t, void (*)(void*))
 *  @brief
 */
forward_list_t forward_list_create(void (*deleter)(void*)) {
  forward_list_t flist;
  flist._size = 0;
  flist._head = flist._tail = NULL;
  flist._deleter = deleter;
  return flist;
}

/** @fn     void forward_list_clear(forward_list_t*)
 *  @brief
 */
void forward_list_clear(forward_list_t* flist) {
  forward_node_ptr it;
  while (flist->_head) {
    it = flist->_head;
    flist->_head = it->_next;
    forward_node_clear(it, flist->_deleter);
    free(it);
  }
  flist->_size = 0;
  flist->_head = flist->_tail = NULL;
}

/** @fn     void forward_ist_push_front(forward_list_t*, void*)
 *  @brief
 */
void forward_list_push_front(forward_list_t* flist, void* data) {
  flist->_head = forward_node_make(data, flist->_head);
  if (flist->_tail == NULL)
    flist->_tail = flist->_head;
}

/** @fn     void forward_list_for_each(forward_list_t*, void (*)(void*))
 *  @brief
 */
void forward_list_for_each(forward_list_t* flist, void (*anary_op)(void*)) {
  for (forward_node_ptr it = flist->_head; it != NULL; it = it->_next) {
    anary_op(it->_data);
  }
}

#endif // __INCLUDES_FORWARD_LIST_H__