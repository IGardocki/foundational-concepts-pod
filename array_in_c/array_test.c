#include "array.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

// TODO: FIGURE OUT HOW TO GET THIS FILE TO RECOGNIZE CUNIT
#include "CUnit/Basic.h"
#include "CUnit/CUnit.h"

#define CU_TEST_INFO(test_func) \
{#test_func, test_func}


static void ShouldFail(){
    CU_ASSERT_EQUAL(false, true);
}

static void ShouldPass(){
    CU_ASSERT_EQUAL(true, true);
}

// TODO: LOOK INTO MAKE
int noop(void) { return 0; }

int RegisterArrayTests(){
    CU_TestInfo Array_tests[] = {CU_TEST_INFO(ShouldFail),
                               CU_TEST_INFO(ShouldPass),
                               CU_TEST_INFO_NULL
};

CU_SuiteInfo suites[] = {{.pName = "Array",
                            .pInitFunc = noop,
                            .pCleanupFunc = noop,
                            .pTests = Array_tests},
                           CU_SUITE_INFO_NULL};

return CU_register_suites(suites);
}

