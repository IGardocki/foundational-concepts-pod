#include "array.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include "CUnit/Basic.h"
#include "CUnit/CUnit.h"
#include "../utils/utils.h"
#include "../utils/comparators.h"

#define CU_TEST_INFO(test_func) \
{#test_func, test_func}


static void ShouldFail(){
    CU_ASSERT_EQUAL(false, true);
}

static void ShouldPass(){
    CU_ASSERT_EQUAL(true, true);
}

static void ShouldInitArray(){
    Array* array = NULL; // calls a pointer to an Array struct array and sets it to NULL
    ResultCode result = Init_Array(sizeof(int), &array); // passes in int size, and the reference to the array
    CU_ASSERT_EQUAL(result, kSuccess);
}

static void ShouldInsertAtHead(){
    Array* array = NULL; // calls a pointer to an Array struct array and sets it to NULL
    Init_Array(sizeof(int), &array); // passes in int size, and the reference to the array
    int test0 = 15; //declares an int
    ResultCode result = Insert_At_Head(array, &test0); // passes the array pointer and a reference to test into the function
    CU_ASSERT_EQUAL(result, kSuccess);
}

static void ShouldInsertAtTail(){
    Array* array = NULL; // calls a pointer to an Array struct array and sets it to NULL
    Init_Array(sizeof(int), &array); // passes in int size, and the reference to the array
    int test0 = 15; //declares an int
    int test1 = 20;
    Insert_At_Head(array, &test0); // passes the array pointer and a reference to test into the function
    ResultCode result = Insert_At_Tail(array, &test1);
    CU_ASSERT_EQUAL(result, kSuccess);
}

static void ShouldSearchArrayAndReturnKFound(){
    Array* array = NULL; // calls a pointer to an Array struct array and sets it to NULL
    Init_Array(sizeof(int), &array); // passes in int size, and the reference to the array
    int test0 = 15; //declares an int
    int test1 = 20;
 
    Insert_At_Head(array, &test0); // passes the array pointer and a reference to test into the function
    Insert_At_Tail(array, &test1);

    void* search_result_store = NULL;
    ResultCode result = Array_Search(array, &test0, PIntComparator, &search_result_store);
    int search_result = *(int*)search_result_store;
    CU_ASSERT_EQUAL(result, kFound);
    CU_ASSERT_EQUAL(search_result, 15);
}

static void ShouldSearchArrayAndReturnKNotFound(){
    Array* array = NULL; // calls a pointer to an Array struct array and sets it to NULL
    Init_Array(sizeof(int), &array); // passes in int size, and the reference to the array
    int test0 = 15; //declares an int
    int test1 = 20;
    int notPresentInArr = 851;
 
    Insert_At_Head(array, &test0); // passes the array pointer and a reference to test into the function
    Insert_At_Tail(array, &test1);

    void* search_result_store = NULL;
    ResultCode result = Array_Search(array, &notPresentInArr, PIntComparator, &search_result_store);
    CU_ASSERT_EQUAL(result, kNotFound);
}

static void ShouldFindMax(){
    Array* array = NULL; // calls a pointer to an Array struct array and sets it to NULL
    Init_Array(sizeof(int), &array); // passes in int size, and the reference to the array
    int test0 = 15; //declares an int
    int test1 = 20;
    int test2 = 850;
 

    Insert_At_Head(array, &test0); // passes the array pointer and a reference to test into the function
    Insert_At_Tail(array, &test1);
    Insert_At_Head(array, &test2);

    void* max_result_store = NULL;
    ResultCode result = Array_Max(array, PIntComparator, &max_result_store);
    CU_ASSERT_EQUAL(result, kSuccess);
    int max_result = *(int*)max_result_store;
    printf("XXXXXXXXXX %i",max_result);
    CU_ASSERT_EQUAL(max_result, 850);
}

// TODO: LOOK INTO MAKE
int noop(void) { return 0; }

int RegisterArrayTests(){
    CU_TestInfo Array_tests[] = {CU_TEST_INFO(ShouldFail),
                               CU_TEST_INFO(ShouldPass),
                               CU_TEST_INFO(ShouldInitArray),
                               CU_TEST_INFO(ShouldInsertAtHead),
                               CU_TEST_INFO(ShouldInsertAtTail),
                               CU_TEST_INFO(ShouldSearchArrayAndReturnKFound),
                               CU_TEST_INFO(ShouldSearchArrayAndReturnKNotFound),
                               CU_TEST_INFO(ShouldFindMax),
                               CU_TEST_INFO_NULL
};

CU_SuiteInfo suites[] = {{.pName = "Array",
                            .pInitFunc = noop,
                            .pCleanupFunc = noop,
                            .pTests = Array_tests},
                           CU_SUITE_INFO_NULL};

return CU_register_suites(suites);
}

