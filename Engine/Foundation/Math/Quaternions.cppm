module;

#include <concepts>

export module Spark.Engine.Foundation.Math:Quaternions;

import :LinearAlgebra;

export namespace Spark::Engine::Foundation::Math {
  template <std::floating_point T>
  struct SQuaternion {
    SVector3<T> xyz;
    T w;

    explicit SQuaternion() noexcept = default;
    explicit SQuaternion(SVector3<T> xyz, T w) noexcept;
    explicit SQuaternion(SVector4<T> components) noexcept;

    SQuaternion operator+(SQuaternion const &other) const noexcept;
    SQuaternion operator-(SQuaternion const &other) const noexcept;
    SQuaternion operator*(SQuaternion const &other) const noexcept;
    SQuaternion operator/(SQuaternion const &other) const noexcept;

    SQuaternion operator*(T v) const noexcept;
    SQuaternion operator/(T v) const noexcept;

    T InnerDot(SQuaternion const &other) const noexcept;
    T Norm() const noexcept;
    SQuaternion Normalized() const noexcept;

    SQuaternion Conjugated() const noexcept;
    SQuaternion Inversed() const noexcept;

    SVector3<T> Rotate(SVector3<T> v) const noexcept;

    static SQuaternion Rotation(SVector3<T> axis, T angle) noexcept;
    static SQuaternion Lerp(SQuaternion const &p, SQuaternion const &q, T t) noexcept;
    static SQuaternion SLerp(SQuaternion const &p, SQuaternion const &q, T t) noexcept;
  };
}
