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

static void ShouldOrderedInsert(){
    Array* array = NULL; // calls a pointer to an Array struct array and sets it to NULL
    Init_Sorted_Array(sizeof(int), &array); // passes in int size, and the reference to the array

    int test0 = 850;
    int test1 = 851;
    int test2 = 888;
    int test3 = 123;

    Sorted_Array_Ordered_Insertion(array, PIntComparator, &test3); // passes the array pointer and a reference to test into the function
    Sorted_Array_Ordered_Insertion(array, PIntComparator, &test1);
    Sorted_Array_Ordered_Insertion(array, PIntComparator, &test2);
    Sorted_Array_Ordered_Insertion(array, PIntComparator, &test0);
    CU_ASSERT_EQUAL(((int*)array->array)[0], 123);
    CU_ASSERT_EQUAL(((int*)array->array)[1], 850);
    CU_ASSERT_EQUAL(((int*)array->array)[2], 851);
    CU_ASSERT_EQUAL(((int*)array->array)[3], 888);
}

int sorted_arr_noop(void) { return 0; }

int RegisterSortedArrayTests(){
    CU_TestInfo Array_tests[] = {
                               CU_TEST_INFO(ShouldPass),
                               CU_TEST_INFO(ShouldInitArray),
                               CU_TEST_INFO(ShouldOrderedInsert),
                               CU_TEST_INFO_NULL

};



CU_SuiteInfo suites[] = {{.pName = "Sorted_Array",
                            .pInitFunc = sorted_arr_noop,
                            .pCleanupFunc = sorted_arr_noop,
                            .pTests = Array_tests},
                           CU_SUITE_INFO_NULL};

return CU_register_suites(suites);
}