module;

#include <algorithm>
#include <cmath>
#include <concepts>

module Spark.Engine.Foundation.Math;

namespace Spark::Engine::Foundation::Math {
  template <std::floating_point T>
  T SafeDivide(T const dividend, T divisor) noexcept {
    if (divisor == T(0)) [[unlikely]] {
      divisor = T(1e-5);
    }

    return dividend / divisor;
  }

  template <std::floating_point T>
  T Min(T const x, T const y) noexcept {
    return std::min(x, y);
  }

  template <std::floating_point T>
  T Max(T const x, T const y) noexcept {
    return std::max(x, y);
  }

  template <std::floating_point T>
  T Clamp(T const x, T const low, T const high) noexcept {
    return std::clamp(x, low, high);
  }

  template <std::floating_point T>
  T Abs(T const x) noexcept {
    return std::abs(x);
  }

  template <std::floating_point T>
  T Sign(T const x) noexcept {
    return static_cast<T>((T(0) < x) - (x < T(0)));
  }

  template <std::floating_point T>
  T ConvertDegreeToRadian(T const degree) noexcept {
    return degree * (pi<T> / T(180));
  }

  template <std::floating_point T>
  T ConvertRadianToDegree(T const radian) noexcept {
    return radian * (T(180) / pi<T>);
  }

  template <std::floating_point T>
  T Lerp(T const x, T const y, T const t) noexcept {
    return std::lerp(x, y, t);
  }

  template <std::floating_point T>
  T Exp(T const x) noexcept {
    return std::exp(x);
  }

  template <std::floating_point T>
  T Sin(T const radian) noexcept {
    return std::sin(radian);
  }

  template <std::floating_point T>
  T Cos(T const radian) noexcept {
    return std::cos(radian);
  }

  template <std::floating_point T>
  T Tan(T const radian) noexcept {
    return std::tan(radian);
  }

  template <std::floating_point T>
  T Cot(T const radian) noexcept {
    return SafeDivide(T(1), Tan(radian));
  }

  template <std::floating_point T>
  T ArcSin(T const x) noexcept {
    return std::asin(x);
  }

  template <std::floating_point T>
  T ArcCos(T const x) noexcept {
    return std::acos(x);
  }

  template <std::floating_point T>
  T ArcTan(T const x) noexcept {
    return std::atan(x);
  }

  // Principal arccotangent in [0, pi], including infinite inputs.
  template <std::floating_point T>
  T ArcCot(T const x) noexcept {
    return std::atan2(T(1), x);
  }

  template float SafeDivide<float>(float, float) noexcept;
  template double SafeDivide<double>(double, double) noexcept;
  template float Min<float>(float, float) noexcept;
  template double Min<double>(double, double) noexcept;
  template float Max<float>(float, float) noexcept;
  template double Max<double>(double, double) noexcept;
  template float Clamp<float>(float, float, float) noexcept;
  template double Clamp<double>(double, double, double) noexcept;
  template float Abs<float>(float) noexcept;
  template double Abs<double>(double) noexcept;
  template float Sign<float>(float) noexcept;
  template double Sign<double>(double) noexcept;
  template float ConvertDegreeToRadian<float>(float) noexcept;
  template double ConvertDegreeToRadian<double>(double) noexcept;
  template float ConvertRadianToDegree<float>(float) noexcept;
  template double ConvertRadianToDegree<double>(double) noexcept;
  template float Lerp<float>(float, float, float) noexcept;
  template double Lerp<double>(double, double, double) noexcept;
  template float Exp<float>(float) noexcept;
  template double Exp<double>(double) noexcept;
  template float Sin<float>(float) noexcept;
  template double Sin<double>(double) noexcept;
  template float Cos<float>(float) noexcept;
  template double Cos<double>(double) noexcept;
  template float Tan<float>(float) noexcept;
  template double Tan<double>(double) noexcept;
  template float Cot<float>(float) noexcept;
  template double Cot<double>(double) noexcept;
  template float ArcSin<float>(float) noexcept;
  template double ArcSin<double>(double) noexcept;
  template float ArcCos<float>(float) noexcept;
  template double ArcCos<double>(double) noexcept;
  template float ArcTan<float>(float) noexcept;
  template double ArcTan<double>(double) noexcept;
  template float ArcCot<float>(float) noexcept;
  template double ArcCot<double>(double) noexcept;
}
