#include <Diagnostics/Logging/LoggingMacros.h>

import Spark.Engine.Foundation.Diagnostics.Logging;

extern Spark::Engine::Foundation::Diagnostics::Logging::SRawLogger* g_Logger;

namespace Spark::Engine::Foundation::Diagnostics::Logging {
  void SetGlobalLogger(SRawLogger* const logger) {
    if (g_Logger != nullptr) [[unlikely]] {
      return;
    }

    g_Logger = logger;
  }

  void SparkGlobalLog(
    std::chrono::system_clock::time_point timestamp,
    std::source_location location,
    SLogLevel level,
    char const* category,
    std::function<std::string()> formatMessage
  ) {
    if (g_Logger == nullptr) [[unlikely]] {
      return;
    }

    g_Logger->Log(level, category, formatMessage, timestamp, location);
  }
}
