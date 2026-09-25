#ifndef SPARK_ASSERTION_HEADER
#define SPARK_ASSERTION_HEADER

#include <string>

namespace Spark::Engine::Foundation::Diagnostics::Assertion {
  void AssertFailure(char const* category, char const* condition, std::string const& message);
}

#ifdef SPARK_ASSERTION_ENABLED
#define SPARK_ASSERT(category, condition, message) \
  if (!(condition)) [[unlikely]] { \
    Spark::Engine::Foundation::Diagnostics::Assertion::AssertFailure((category), #condition, (message)); \
  }
#else
#define SPARK_ASSERT(category, condition, message) ((void)0)
#endif

#endif
