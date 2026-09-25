module;

#include <cmath>
#include <concepts>

module Spark.Engine.Foundation.Math;

namespace Spark::Engine::Foundation::Math {
  template <std::floating_point T>
  SQuaternion<T>::SQuaternion(SVector3<T> const xyz, T const w) noexcept:
  xyz(xyz), w(w) {}

  template <std::floating_point T>
  SQuaternion<T>::SQuaternion(SVector4<T> const components) noexcept:
  xyz(components.xyz()), w(components.w) {}

  template <std::floating_point T>
  SQuaternion<T> SQuaternion<T>::operator+(SQuaternion<T> const& other) const noexcept {
    return SQuaternion<T>(xyz + other.xyz, w + other.w);
  }

  template <std::floating_point T>
  SQuaternion<T> SQuaternion<T>::operator-(SQuaternion<T> const& other) const noexcept {
    return SQuaternion<T>(xyz - other.xyz, w - other.w);
  }

  template <std::floating_point T>
  SQuaternion<T> SQuaternion<T>::operator*(SQuaternion<T> const& other) const noexcept {
    return SQuaternion<T>(
      xyz * other.w + other.xyz * w - xyz.Cross(other.xyz),
      w * other.w - xyz.InnerDot(other.xyz)
    );
  }

  template <std::floating_point T>
  SQuaternion<T> SQuaternion<T>::operator/(SQuaternion<T> const& other) const noexcept {
    return *this * other.Inversed();
  }

  template <std::floating_point T>
  SQuaternion<T> SQuaternion<T>::operator*(T const v) const noexcept {
    return SQuaternion<T>(xyz * v, w * v);
  }

  template <std::floating_point T>
  SQuaternion<T> SQuaternion<T>::operator/(T const v) const noexcept {
    const T vInversed = T(1) / v;
    return SQuaternion<T>(xyz * vInversed, w * vInversed);
  }

  template <std::floating_point T>
  T SQuaternion<T>::InnerDot(SQuaternion<T> const& other) const noexcept {
    return xyz.InnerDot(other.xyz) + w * other.w;
  }

  template<std::floating_point T>
  T SQuaternion<T>::Norm() const noexcept {
    return std::hypot(xyz.Norm(), w);
  }

  template <std::floating_point T>
  SQuaternion<T> SQuaternion<T>::Normalized() const noexcept {
    T const normInversed = T(1) / Norm();
    return SQuaternion<T>(xyz * normInversed, w * normInversed);
  }

  template <std::floating_point T>
  SQuaternion<T> SQuaternion<T>::Conjugated() const noexcept {
    return SQuaternion<T>(SVector3<T>(-xyz.x, -xyz.y, -xyz.z), w);
  }

  template <std::floating_point T>
  SQuaternion<T> SQuaternion<T>::Inversed() const noexcept {
    T const normSquaredInversed = T(1) / (xyz.InnerDot(xyz) + w * w);
    return SQuaternion<T>(
      SVector3<T>(-xyz.x, -xyz.y, -xyz.z) * normSquaredInversed,
      w * normSquaredInversed
    );
  }

  template <std::floating_point T>
  SVector3<T> SQuaternion<T>::Rotate(SVector3<T> const v) const noexcept {
    SQuaternion<T> const normalized = Normalized();
    SQuaternion<T> const rotated = (normalized * SQuaternion<T>(v, T(0))) * normalized.Conjugated();
    return rotated.xyz;
  }

  template <std::floating_point T>
  SQuaternion<T> SQuaternion<T>::Rotation(SVector3<T> const axis, T const angle) noexcept {
    return SQuaternion<T>(axis.Normalized() * Sin(angle / T(2)), Cos(angle / T(2)));
  }

  template <std::floating_point T>
  SQuaternion<T> SQuaternion<T>::Lerp(SQuaternion<T> const& p, SQuaternion<T> const& q, T const t) noexcept {
    SQuaternion<T> const linearInterpretation = p + (q - p) * t;
    return linearInterpretation / linearInterpretation.Norm();
  }

  template <std::floating_point T>
  SQuaternion<T> SQuaternion<T>::SLerp(SQuaternion<T> const& p, SQuaternion<T> const& q, T const t) noexcept {
    SQuaternion<T> const start = p.Normalized();
    SQuaternion<T> end = q.Normalized();
    T cosine = start.InnerDot(end);

    if (cosine < T(0)) {
      end = end * T(-1);
      cosine = -cosine;
    }

    cosine = Clamp(cosine, T(0), T(1));

    if (cosine > T(0.9995)) {
      return (start + (end - start) * t).Normalized();
    }

    T const angle = ArcCos(cosine);
    T const sineInversed = T(1) / Sin(angle);
    T const startWeight = Sin((T(1) - t) * angle) * sineInversed;
    T const endWeight = Sin(t * angle) * sineInversed;

    return (start * startWeight + end * endWeight).Normalized();
  }

  template struct SQuaternion<float>;
  template struct SQuaternion<double>;
}
