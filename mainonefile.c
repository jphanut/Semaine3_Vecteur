#include <stdio.h>
#include <stdlib.h>

struct vector_t {
  int size;
  float *v;
};
// initialise le vecteur à la valeur du réel
struct vector_t * init(int, float);
// récupère le nième élément
float get(struct vector_t *, int) ;
// fixe la valeur du nième élément
void set(struct vector_t *, int , float);
// supprime un vecteur
void destroy(struct vector_t *);


int main (int argc, char ** argv){
    int rc = 0;
    // Example : Vector of 20 elements initiazed to 0
    struct vector_t *ptr_vector = init(20, 0);
    if ( !ptr_vector )
    {
        printf("Error when allocating memory\n");
        return 1;
    }
    // Assign value 1 in the vector at the index 10,11 and 12
    set ( ptr_vector, 10, 1);
    set ( ptr_vector, 11, 1);
    set ( ptr_vector, 12, 1);
    // List all values in vector
    for ( int i=0; i < ptr_vector->size; i++)
    {
        float value = get (ptr_vector, i );
        printf("Element at index %d: value: %f\n", i, value);
    }

    destroy(ptr_vector);
    return rc;
}

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
