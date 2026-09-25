module;

#include <chrono>
#include <cstddef>
#include <functional>
#include <memory>
#include <source_location>
#include <string>
#include <vector>

export module Spark.Engine.Foundation.Diagnostics.Logging:RawLogger;

export namespace Spark::Engine::Foundation::Diagnostics::Logging {
  enum class SLogLevel: char {
    Verbose = 0,
    Trace = 1,
    Debug = 2,
    Information = 3,
    Warning = 4,
    Error = 5,
    Critical = 6
  };

  class SLogSinkProtocol {
  public:
    virtual ~SLogSinkProtocol() noexcept = default;

    virtual void Write(
      SLogLevel level,
      char const* category,
      std::string message,
      std::chrono::system_clock::time_point timestamp,
      std::source_location location
    ) = 0;
  };

  class SRawLogger {
  private:
    std::vector<std::shared_ptr<SLogSinkProtocol>> m_Sinks;

  public:
    explicit SRawLogger(std::size_t capacity);
    SRawLogger(SRawLogger const& other) noexcept = delete;
    SRawLogger(SRawLogger&& other) noexcept = delete;

    SRawLogger& operator=(SRawLogger const& other) noexcept = delete;
    SRawLogger& operator=(SRawLogger&& other) noexcept = delete;

    void AddSink(std::shared_ptr<SLogSinkProtocol> const& sink) noexcept;

    void Log(
      SLogLevel level,
      char const* category,
      std::function<std::string()> formatMessage,
      std::chrono::system_clock::time_point timestamp = std::chrono::system_clock::now(),
      std::source_location location = std::source_location::current()
    ) noexcept;
  };
}
