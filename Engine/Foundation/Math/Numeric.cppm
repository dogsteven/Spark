module;

#include <concepts>

export module Spark.Engine.Foundation.Math:Numeric;

export namespace Spark::Engine::Foundation::Math {
  template <typename T>
  constexpr T pi = 3.141592653589793;

  template <typename T>
  constexpr T e = 2.718281828459045;

  template <std::floating_point T>
  T SafeDivide(T dividend, T divisor) noexcept;

  template <std::floating_point T>
  T Min(T x, T y) noexcept;

  template <std::floating_point T>
  T Max(T x, T y) noexcept;

  template <std::floating_point T>
  T Clamp(T x, T low, T high) noexcept;

  template <std::floating_point T>
  T Abs(T x) noexcept;

  template <std::floating_point T>
  T Sign(T x) noexcept;

  template <std::floating_point T>
  T ConvertDegreeToRadian(T degree) noexcept;

  template <std::floating_point T>
  T ConvertRadianToDegree(T radian) noexcept;

  template <std::floating_point T>
  T Lerp(T x, T y, T t) noexcept;

  template <std::floating_point T>
  T Exp(T x) noexcept;

  template <std::floating_point T>
  T Sin(T radian) noexcept;

  template <std::floating_point T>
  T Cos(T radian) noexcept;

  template <std::floating_point T>
  T Tan(T radian) noexcept;

  template <std::floating_point T>
  T Cot(T radian) noexcept;

  template <std::floating_point T>
  T ArcSin(T x) noexcept;

  template <std::floating_point T>
  T ArcCos(T x) noexcept;

  template <std::floating_point T>
  T ArcTan(T x) noexcept;

  template <std::floating_point T>
  T ArcCot(T x) noexcept;
}
