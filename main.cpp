#include "kisstest.h"

void Test() {
    KISSTEST::ASSERT(true);
    KISSTEST::ASSERT_EQUAL(1, 1);
}

int main() {
    KISSTEST::RUN_TEST(Test);
}








































