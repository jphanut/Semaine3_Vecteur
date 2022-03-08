#include <stdio.h>
#include <stdlib.h>
# include "vector.h"
# include "unittest.h"


int main (int argc, char ** argv){
    int rc = 0;
    int * ptr_rc = &rc;
    if (checkswitchtesting(&ptr_rc, argc, argv))
    {
        return rc;
    }
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


