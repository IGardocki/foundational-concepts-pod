#include "sorted_array.h"
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

int RegisterSortedArrayTests(){
    CU_TestInfo Array_tests[] = {
                               CU_TEST_INFO(ShouldPass),

};

int noop(void) { return 0; }

CU_SuiteInfo suites[] = {{.pName = "Sorted_Array",
                            .pInitFunc = noop,
                            .pCleanupFunc = noop,
                            .pTests = Array_tests},
                           CU_SUITE_INFO_NULL};

return CU_register_suites(suites);
}