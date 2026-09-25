add_library(SparkEngineFoundation OBJECT)

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
