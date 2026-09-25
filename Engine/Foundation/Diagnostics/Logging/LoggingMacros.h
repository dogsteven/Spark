#ifndef SPARK_LOGGING_HEADER
#define SPARK_LOGGING_HEADER

#include <string>
#include <functional>
#include <chrono>
#include <source_location>

import Spark.Engine.Foundation.Diagnostics.Logging;

namespace Spark::Engine::Foundation::Diagnostics::Logging {
  void SetGlobalLogger(SRawLogger* logger);

  void SparkGlobalLog(
    std::chrono::system_clock::time_point timestamp,
    std::source_location location,
    SLogLevel level,
    char const* category,
    std::function<std::string ()> formatMessage
  );
}

#ifndef SPARK_LOG_VERBOSITY
#define SPARK_LOG_VERBOSITY 0
#endif

#if SPARK_LOG_VERBOSITY <= 0
#define SPARK_LOG_VERBOSE(category, formatMessage) \
  Spark::Engine::Foundation::Diagnostics::Logging::SparkGlobalLog( \
    std::chrono::system_clock::now(), \
    std::source_location::current(), \
    Spark::Engine::Foundation::Diagnostics::Logging::SLogLevel::Verbose, \
    (category), \
    (formatMessage) \
  )
#else
#define SPARK_LOG_VERBOSE(category, formatMessage) ((void)0)
#endif

#if SPARK_LOG_VERBOSITY <= 1
#define SPARK_LOG_TRACE(category, formatMessage) \
  Spark::Engine::Foundation::Diagnostics::Logging::SparkGlobalLog( \
    std::chrono::system_clock::now(), \
    std::source_location::current(), \
    Spark::Engine::Foundation::Diagnostics::Logging::SLogLevel::Trace, \
    (category), \
    (formatMessage) \
  )
#else
#define SPARK_LOG_TRACE(category, formatMessage) ((void)0)
#endif

#if SPARK_LOG_VERBOSITY <= 2
#define SPARK_LOG_DEBUG(category, formatMessage) \
  Spark::Engine::Foundation::Diagnostics::Logging::SparkGlobalLog( \
    std::chrono::system_clock::now(), \
    std::source_location::current(), \
    Spark::Engine::Foundation::Diagnostics::Logging::SLogLevel::Debug, \
    (category), \
    (formatMessage) \
  )
#else
#define SPARK_LOG_DEBUG(category, formatMessage) ((void)0)
#endif

#if SPARK_LOG_VERBOSITY <= 3
#define SPARK_LOG_INFORMATION(category, formatMessage) \
  Spark::Engine::Foundation::Diagnostics::Logging::SparkGlobalLog( \
    std::chrono::system_clock::now(), \
    std::source_location::current(), \
    Spark::Engine::Foundation::Diagnostics::Logging::SLogLevel::Information, \
    (category), \
    (formatMessage) \
  )
#else
#define SPARK_LOG_INFORMATION(category, formatMessage) ((void)0)
#endif

#if SPARK_LOG_VERBOSITY <= 4
#define SPARK_LOG_WARNING(category, formatMessage) \
  Spark::Engine::Foundation::Diagnostics::Logging::SparkGlobalLog( \
    std::chrono::system_clock::now(), \
    std::source_location::current(), \
    Spark::Engine::Foundation::Diagnostics::Logging::SLogLevel::Warning, \
    (category), \
    (formatMessage) \
  )
#else
#define SPARK_LOG_WARNING(category, formatMessage) ((void)0)
#endif

#if SPARK_LOG_VERBOSITY <= 5
#define SPARK_LOG_ERROR(category, formatMessage) \
  Spark::Engine::Foundation::Diagnostics::Logging::SparkGlobalLog( \
    std::chrono::system_clock::now(), \
    std::source_location::current(), \
    Spark::Engine::Foundation::Diagnostics::Logging::SLogLevel::Error, \
    (category), \
    (formatMessage) \
  )
#else
#define SPARK_LOG_ERROR(category, formatMessage) ((void)0)
#endif

#if SPARK_LOG_VERBOSITY <= 6
#define SPARK_LOG_CRITICAL(category, formatMessage) \
  Spark::Engine::Foundation::Diagnostics::Logging::SparkGlobalLog( \
    std::chrono::system_clock::now(), \
    std::source_location::current(), \
    Spark::Engine::Foundation::Diagnostics::Logging::SLogLevel::Critical, \
    (category), \
    (formatMessage) \
  )
#else
#define SPARK_LOG_CRITICAL(category, formatMessage) ((void)0)
#endif

#endif
