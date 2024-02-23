#include "sorted_array.h"
#include "../array_in_c/array.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include "CUnit/Basic.h"
#include "CUnit/CUnit.h"
#include "../utils/utils.h"
#include "../utils/comparators.h"

#define CU_TEST_INFO(test_func) \
{#test_func, test_func}

static void ShouldPass(){
    CU_ASSERT_EQUAL(true, true);
}

static void ShouldInitArray(){
    Array* array = NULL; // calls a pointer to an Array struct array and sets it to NULL
    ResultCode result = Init_Sorted_Array(sizeof(int), &array); // passes in int size, and the reference to the array
    CU_ASSERT_EQUAL(result, kSuccess);
}

int sorted_arr_noop(void) { return 0; }

int RegisterSortedArrayTests(){
    CU_TestInfo Array_tests[] = {
                               CU_TEST_INFO(ShouldPass),
                               CU_TEST_INFO(ShouldInitArray),
                               CU_TEST_INFO_NULL

};



CU_SuiteInfo suites[] = {{.pName = "Sorted_Array",
                            .pInitFunc = sorted_arr_noop,
                            .pCleanupFunc = sorted_arr_noop,
                            .pTests = Array_tests},
                           CU_SUITE_INFO_NULL};

return CU_register_suites(suites);
}