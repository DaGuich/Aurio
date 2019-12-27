#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <LibFir.h>

static void LibFir_Test_01(void** state)
{
    (void)state;
}

int main()
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(LibFir_Test_01),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}