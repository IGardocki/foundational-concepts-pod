#include "CUnit/Basic.h"
extern int RegisterArrayTests(void);
extern int RegisterSortedArrayTests(void);


int main()
{
   
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   if(RegisterArrayTests() != 0){
      CU_cleanup_registry();
      return -1;
   }

   if(RegisterSortedArrayTests() != 0){
      CU_cleanup_registry();
      return -1;
   }

   

   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error(); 
}