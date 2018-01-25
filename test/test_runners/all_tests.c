#include "unity_fixture.h"

static void RunAllTests(void)
{
  RUN_TEST_GROUP(processor);
  RUN_TEST_GROUP(Instructions);
  RUN_TEST_GROUP(Memory);
}

int main(int argc, const char * argv[])
{
  return UnityMain(argc, argv, RunAllTests);
}
