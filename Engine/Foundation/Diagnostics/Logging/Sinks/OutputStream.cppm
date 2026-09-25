module;

#include <ostream>
#include <chrono>
#include <source_location>


export module Spark.Engine.Foundation.Diagnostics.Logging.LogSinks:OutputStreamLogSink;

import Spark.Engine.Foundation.Diagnostics.Logging;

export namespace Spark::Engine::Foundation::Diagnostics::Logging {
  class SNonOwningOutputStreamLogSink: public SLogSinkProtocol {
  private:
    std::ostream& m_Stream;

  public:
    explicit SNonOwningOutputStreamLogSink(std::ostream& stream) noexcept;
    SNonOwningOutputStreamLogSink(SNonOwningOutputStreamLogSink const& other) noexcept = delete;
    SNonOwningOutputStreamLogSink(SNonOwningOutputStreamLogSink&& other) noexcept = delete;

    SNonOwningOutputStreamLogSink& operator=(SNonOwningOutputStreamLogSink const& other) noexcept = delete;
    SNonOwningOutputStreamLogSink& operator=(SNonOwningOutputStreamLogSink&& other) noexcept = delete;

    void Write(
      SLogLevel level,
      char const* category,
      std::string message,
      std::chrono::system_clock::time_point timestamp,
      std::source_location location
    ) override;
  };
}
