#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void *(*MappingFunc)(void *);

typedef struct {
  void *data;
  size_t size;
  size_t index;
  size_t elem_size;
} Iterator;

Iterator create_iterator(void *data, size_t size, size_t element_size) {
  Iterator it = {
      .data = data, .size = size, .index = 0, .elem_size = element_size};
  return it;
}

// INFO: Increments the pointer of the inner data
// As doing so it becames useless after consuming it
// Maybe reset the pointer afterwards?
void *next(Iterator *it) {
  if (it->data == NULL || it->index >= it->size) {
    return NULL;
  }
  return it->data += (it->index++ * it->elem_size);
}

Iterator map(Iterator *it, size_t return_size, MappingFunc apply) {
  size_t result_size = return_size * it->size;
  printf("Setting map result size to: %ld\n", result_size);

  void *result = malloc(result_size);
  void *val;

  assert(it->index == 0);
  while ((val = next(it))) {
    // INFO: Calculates the idx based on the return Iterator inner data size
    size_t idx = (it->index - 1) * return_size;
    void *apply_result = apply(val);

    // INFO: Copy the chunk of memory to the corresponding address with offset
    memcpy(result + idx, apply_result, return_size);
  }

  // INFO: Spits out the new iterator from the base one
  return create_iterator(result, it->size, return_size);
}

// TODO: That's too much boilerplate perhaps transform this in a Macro,
// to enable just implementing the lambda
float double_f(int *val) { return (*val * 2.0f); }
void *double_v(void *data) {
  float *result = malloc(sizeof(float));
  *result = double_f((int *)data);
  return (void *)result;
}

int main(int argc, char *argv[]) {
  int nums[] = {1, 2};
  size_t nums_size = sizeof(nums) / sizeof(nums[0]);

  for (int i = 0; i < nums_size; i++) {
    printf("%d\n", nums[i]);
  }

  float *val;
  Iterator it = create_iterator((void *)nums, nums_size, sizeof(int));
  it = map(&it, sizeof(float *), double_v);

  while ((val = next(&it))) {
    printf("%f\n", *val);
  }

  return 0;
}
