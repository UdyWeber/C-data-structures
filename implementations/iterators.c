#include <assert.h>
#include <bits/types/__FILE.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMS 5
#define DBG 1
#define DEBUG(fmt, ...)                                                        \
  do {                                                                         \
    if (DBG) {                                                                 \
      char buffer[1000];                                                       \
      snprintf(buffer, sizeof(buffer), fmt, ##__VA_ARGS__);                    \
      printf("[%s|%d] INFO:   %s", __FILE__, __LINE__, buffer);                \
    }                                                                          \
  } while (0)

typedef void *(*MappingFunc)(void *);
typedef bool(Predicate)(void *);

typedef struct {
  void *data;
  size_t size;
  size_t index;
  size_t elem_size;
} Iterator;

Iterator *Iterator_new(void *data, size_t size, size_t element_size) {
  DEBUG("Creating new iterator with element size %ld\n", element_size);
  Iterator *it = (Iterator *)malloc(sizeof(Iterator));
  it->data = data;
  it->size = size;
  it->elem_size = element_size;
  it->index = 0;
  return it;
}

void Iterator_free(Iterator *it) {
  DEBUG("Freeing iterator with element size %ld...\n", it->elem_size);
  free(it->data);
  free(it);
}

// INFO: Increments the pointer of the inner data
// As doing so it becames useless after consuming it
void *Iterator_next(Iterator *it) {
  assert(it->index >= 0);
  assert(it->size > 0);

  if (it->data == NULL || it->index >= it->size) {
    // INFO: Resetting the pointer to its initial position in memory
    it->index = 0;
    it->data -= ((it->size - 1) * it->elem_size);
    return NULL;
  }
  return it->data += (it->index++ * it->elem_size);
}

Iterator *map(Iterator *it, size_t return_size, MappingFunc apply) {
  size_t result_size = return_size * it->size;
  DEBUG("Setting map result size to: %ld\n", result_size);

  void *result = (void *)malloc(result_size);
  void *val;

  assert(it->index == 0);
  while ((val = Iterator_next(it))) {
    // INFO: Calculates the idx based on the return Iterator inner data size
    size_t idx = (it->index - 1) * return_size;
    void *apply_result = apply(val);

    // INFO: Copy the chunk of memory to the corresponding address with offset
    memcpy(result + idx, apply_result, return_size);
  }

  DEBUG("Releasing previous iterator on the chain\n");
  Iterator *nit = Iterator_new(result, it->size, return_size);
  Iterator_free(it);

  // INFO: Spits out the new iterator from the base one
  return nit;
}

Iterator *filter(Iterator *it, Predicate p) {
  void *result = (void *)malloc(it->size * it->elem_size);
  size_t idx = 0;
  void *val = NULL;

  assert(it->index == 0);
  while ((val = Iterator_next(it))) {
    if (p(val)) {
      memcpy(result + (idx++ * it->elem_size), val, it->elem_size);
    }
  }

  if (++idx < it->size) {
    result = realloc(result, idx);
  }

  Iterator *nit = Iterator_new(result, idx, it->elem_size);
  Iterator_free(it);

  return nit;
}

// TODO: That's too much boilerplate perhaps transform this in a Macro,
// to enable just implementing the lambda
float double_f(int *val) { return (*val * 2.0f); }
void *double_v(void *data) {
  float *result = (float *)malloc(sizeof(float));
  *result = double_f((int *)data);
  return (void *)result;
}

bool greater_than_5(void *val) { return *(float *)val > 5.0f; }

// TODO: Implement Arena allocator so memory can be efficiently managed at the
// end of use
int main(void) {
  int *nums = (int *)malloc(NUMS * sizeof(int));
  nums[0] = 1;
  nums[1] = 2;
  nums[2] = 3;
  nums[3] = 420;
  nums[4] = 69;

  Iterator *it = Iterator_new((void *)nums, NUMS, sizeof(int));

  int *ival = NULL;
  while ((ival = Iterator_next(it))) {
    DEBUG("%d\n", *ival);
  }

  it = map(it, sizeof(float *), double_v);
  DEBUG("Finished mapping\n");

  float *fval = NULL;
  while ((fval = Iterator_next(it))) {
    DEBUG("%f\n", *fval);
  }

  it = filter(it, greater_than_5);
  DEBUG("Finished filtering\n");

  while ((fval = Iterator_next(it))) {
    DEBUG("%f\n", *fval);
  }

  Iterator_free(it);
  return 0;
}
