#include "UnitTestFramework.h"

#include <stdlib.h>

UnitTestFramework* _UnitTestFramework_new() {
    UnitTestFramework* fw = (UnitTestFramework*)malloc(sizeof(UnitTestFramework));
    fw->err_count = 0;
    return fw;
}

void _UnitTestFramework_delete(UnitTestFramework* fw) {
    free(fw);
}


//////////