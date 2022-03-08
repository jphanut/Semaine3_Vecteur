#include <stdio.h>
#include <stdlib.h>
# include "vector.h"

struct vector_t * init(int size, float value) {
    float * ptr = (float *)malloc(sizeof(float)*size);
    if ( ptr == NULL) return NULL;
    for ( int i=0; i<size; i++) {
       * (ptr+i) = value;
    }
    struct vector_t * ptr_vector =(struct vector_t *)malloc(sizeof(struct vector_t));
    if ( ptr_vector == NULL ) return NULL;
    (* ptr_vector).size = size;
    ptr_vector->v = ptr;
    return ptr_vector;
}

float get(struct vector_t * ptr_vector, int index) {
    float * ptr_v = ptr_vector->v;
    return * (ptr_v+index);
}

void set(struct vector_t * ptr_vector, int index, float value) {
   float * ptr_v = ptr_vector->v;
   * (ptr_v+index) = value;

}

void destroy(struct vector_t * ptr) {
    free(ptr->v);
    free(ptr);
}
