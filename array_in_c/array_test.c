#include "array.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

// TODO: FIGURE OUT HOW TO GET THIS FILE TO RECOGNIZE CUNIT
#include "CUnit/Basic.h"
#include "CUnit/CUnit.h"

int main (){
    // printf("Hello World!\n");
    Array* array = NULL;
    ResultCode result_code = Init_Array(sizeof(int), &array);
    CU_ASSERT_EQUAL(result_code, kSuccess);
}