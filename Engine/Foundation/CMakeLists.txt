add_library(SparkEngineFoundation OBJECT)

target_sources(SparkEngineFoundation
  PUBLIC FILE_SET diagnostics_logging_modules TYPE CXX_MODULES FILES
  Diagnostics/Logging/Logging.cppm
  Diagnostics/Logging/RawLogger.cppm

  PUBLIC FILE_SET diagnostics_logging_headers TYPE HEADERS FILES
  Diagnostics/Logging/LoggingMacros.h

  PRIVATE
  Diagnostics/Logging/RawLogger.cpp
  Diagnostics/Logging/LoggingMacros.cpp

  PUBLIC FILE_SET diagnostics_logging_sinks_modules TYPE CXX_MODULES FILES
  Diagnostics/Logging/Sinks/LogSinks.cppm
  Diagnostics/Logging/Sinks/OutputStream.cppm

  PRIVATE
  Diagnostics/Logging/Sinks/OutputStream.cpp
)

target_sources(SparkEngineFoundation
  PUBLIC FILE_SET diagnostics_assertion_headers TYPE HEADERS FILES
  Diagnostics/Assertion/AssertionMacros.h

  PRIVATE
  Diagnostics/Assertion/AssertionMacros.cpp
)

target_sources(SparkEngineFoundation
  PUBLIC FILE_SET math_modules TYPE CXX_MODULES FILES
  Math/Math.cppm
  Math/Numeric.cppm
  Math/LinearAlgebra.cppm
  Math/Quaternions.cppm

  PRIVATE
  Math/Numeric.cpp
  Math/LinearAlgebra.cpp
  Math/Quaternions.cpp
)

target_sources(SparkEngineFoundation
  PUBLIC FILE_SET memory_modules TYPE CXX_MODULES FILES
  Memory/Memory.cppm
  Memory/LinearAllocator.cppm
  Memory/PoolAllocator.cppm

  PRIVATE
  Memory/LinearAllocator.cpp
)

target_sources(SparkEngineFoundation
  PUBLIC FILE_SET utilities_modules TYPE CXX_MODULES FILES
  Utilities/Janitor.cppm

  PRIVATE
  Utilities/Janitor.cpp
)
