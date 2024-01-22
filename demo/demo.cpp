#include "kisstest.h"

void Test() {
    KISSTEST::ASSERT(true);
    KISSTEST::ASSERT_EQUAL(1, 1);
    KISSTEST::ASSERT_EQUAL(2, 2);
    KISSTEST::ASSERT_EQUAL(3, 42);
}

int main() {
    KISSTEST::RUN_TEST(Test);
}
