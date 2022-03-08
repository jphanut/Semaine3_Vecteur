# include "unittest.h"
# include "vector.h"
# include <string.h>
#include "CUnit/Basic.h"

struct vector_t * g_ptr_vector = NULL;

int init_suite1(void)
{
    g_ptr_vector = init(20, 0);
    if ( !g_ptr_vector ) {
        return -1;
    }
    else {
        return 0;
    }
}

int clean_suite1(void)
{
    destroy(g_ptr_vector);
    return 0;
}

void test_init(void) {
    CU_ASSERT(NULL != g_ptr_vector);
}

void test_size(void) {
    CU_ASSERT(20 == g_ptr_vector->size);
}

void test_get1(void) {
    float value1 = get (g_ptr_vector, 10 );
    float value2 = get (g_ptr_vector, 11 );
    float value3 = get (g_ptr_vector, 12 );
    CU_ASSERT(0 == value1);
    CU_ASSERT(0 == value2);
    CU_ASSERT(0 == value3);
}

void test_set(void) {
    set ( g_ptr_vector, 10, 1);
    set ( g_ptr_vector, 11, 2);
    set ( g_ptr_vector, 12, 3);
}

void test_get2(void) {
    float value1 = get (g_ptr_vector, 10 );
    float value2 = get (g_ptr_vector, 11 );
    float value3 = get (g_ptr_vector, 12 );
    CU_ASSERT(1 == value1);
    CU_ASSERT(2 == value2);
    CU_ASSERT(3 == value3);
}

int checkswitchtesting(int ** rc, int argc, char **argv) {
    for ( int i =0; i < argc; i++) {
        if ( strcmp(argv[i], "-t")==0) {
             int * ptr_rc = * rc;
            * ptr_rc = main_testing(argc, argv);
            return 1;
        }
    }
    return 0;

}


int main_testing (int argc, char **argv) {
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   pSuite = CU_add_suite("Suite_1", init_suite1, clean_suite1);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   if ((NULL == CU_add_test(pSuite, "test of init", test_init)) ||
       (NULL == CU_add_test(pSuite, "test of size", test_size)) ||
       (NULL == CU_add_test(pSuite, "test of get 1", test_get1)) ||
       (NULL == CU_add_test(pSuite, "test of set", test_set)) ||
       (NULL == CU_add_test(pSuite, "test of get 2", test_get2)))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}
