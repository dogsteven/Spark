module;

#include <ostream>
#include <chrono>
#include <print>
#include <source_location>

module Spark.Engine.Foundation.Diagnostics.Logging.LogSinks;

import Spark.Engine.Foundation.Diagnostics.Logging;

namespace Spark::Engine::Foundation::Diagnostics::Logging {
  std::string_view StringifyLogLevel(SLogLevel level);

  SNonOwningOutputStreamLogSink::SNonOwningOutputStreamLogSink(std::ostream& stream) noexcept:
  m_Stream(stream) {}

  void SNonOwningOutputStreamLogSink::Write(
    SLogLevel level,
    char const* category,
    std::string message,
    std::chrono::system_clock::time_point timestamp,
    std::source_location location
  ) {
    std::print(
      m_Stream,
      "[{}] ({}) {:%F %T} [{} - {} - {}]: {}\n",
      StringifyLogLevel(level),
      category,
      timestamp,
      location.file_name(),
      location.function_name(),
      location.line(),
      message
    );
  }

  std::string_view StringifyLogLevel(SLogLevel level) {
    switch (level) {
      case SLogLevel::Verbose:
      return "Verbose";
      case SLogLevel::Trace:
      return "Trace";
      case SLogLevel::Debug:
      return "Debug";
      case SLogLevel::Information:
      return "Info";
      case SLogLevel::Warning:
      return "Warning";
      case SLogLevel::Error:
      return "Error";
      case SLogLevel::Critical:
      return "Critical";
    };
  }
}
