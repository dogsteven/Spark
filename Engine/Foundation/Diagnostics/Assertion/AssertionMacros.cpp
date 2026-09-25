#include <format>

#include <Diagnostics/Logging/LoggingMacros.h>

import Spark.Engine.Foundation.Diagnostics.Logging;

#if (__clang__)
#define BREAKPOINT() __builtin_trap()
#else
#define BREAKPOINT() __debugbreak()
#endif

namespace Spark::Engine::Foundation::Diagnostics::Assertion {
  void AssertFailure(char const* category, char const* condition, std::string const& message) {
    SPARK_LOG_CRITICAL(category, ([condition, message]() {
      return std::format("Assertion failed for expression {}: {}", condition, message);
    }));

    BREAKPOINT();
  }
}
