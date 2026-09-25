module;

#include <chrono>
#include <cstddef>
#include <functional>
#include <memory>
#include <source_location>
#include <string>
#include <vector>


module Spark.Engine.Foundation.Diagnostics.Logging;

namespace Spark::Engine::Foundation::Diagnostics::Logging {
  SRawLogger::SRawLogger(std::size_t capacity): m_Sinks() {
    m_Sinks.reserve(capacity);
  }

  void SRawLogger::AddSink(std::shared_ptr<SLogSinkProtocol> const& sink) noexcept {
    if (m_Sinks.size() == m_Sinks.capacity()) [[unlikely]] {
      return;
    }

    m_Sinks.push_back(sink);
  }

  void SRawLogger::Log(
    SLogLevel level,
    char const* category,
    std::function<std::string()> formatMessage,
    std::chrono::system_clock::time_point timestamp,
    std::source_location location) noexcept
  {
    std::string message = formatMessage();

    for (auto const& sink: m_Sinks) {
      sink->Write(level, category, message, timestamp, location);
    }
  }
}
