module;

#include <concepts>

export module Spark.Engine.Foundation.Math:LinearAlgebra;

export namespace Spark::Engine::Foundation::Math {
  template <std::floating_point T>
  struct SPackedVector2 {
    T x, y;

    explicit SPackedVector2() noexcept = default;
    explicit SPackedVector2(T x, T y) noexcept;
  };

  template <std::floating_point T>
  struct SPackedVector3 {
    T x, y, z;

    explicit SPackedVector3() noexcept = default;
    explicit SPackedVector3(T x, T y, T z) noexcept;
  };

  template <std::floating_point T>
  struct SPackedVector4 {
    T x, y, z, w;

    explicit SPackedVector4() noexcept = default;
    explicit SPackedVector4(T x, T y, T z, T w) noexcept;
  };

  template <std::floating_point T>
  struct alignas(16) SVector2 {
    T x, y;

    explicit SVector2() noexcept = default;
    explicit SVector2(T x, T y) noexcept;
    explicit SVector2(SPackedVector2<T> vector) noexcept;

    SPackedVector2<T> Packed() const noexcept;

    SVector2 operator+(SVector2 const& other) const noexcept;
    SVector2 operator-(SVector2 const& other) const noexcept;
    SVector2 operator*(SVector2 const& other) const noexcept;
    SVector2 operator/(SVector2 const& other) const noexcept;

    SVector2 operator*(T v) const noexcept;
    SVector2 operator/(T v) const noexcept;

    T InnerDot(SVector2 const& other) const noexcept;
    T Norm() const noexcept;
    SVector2 Normalized() const noexcept;

    static SVector2 Lerp(SVector2 const& x, SVector2 const& y, T t) noexcept;
  };

  template <std::floating_point T>
  struct alignas(16) SVector3 {
    T x, y, z;

    explicit SVector3() noexcept = default;
    explicit SVector3(T x, T y, T z) noexcept;
    explicit SVector3(SVector2<T> xy, T z) noexcept;
    explicit SVector3(SPackedVector3<T> vector) noexcept;

    SPackedVector3<T> Packed() const noexcept;

    SVector2<T> xy() const noexcept;

    SVector3 operator+(SVector3 const& other) const noexcept;
    SVector3 operator-(SVector3 const& other) const noexcept;
    SVector3 operator*(SVector3 const& other) const noexcept;
    SVector3 operator/(SVector3 const& other) const noexcept;

    SVector3 operator*(T v) const noexcept;
    SVector3 operator/(T v) const noexcept;

    T InnerDot(SVector3 const& other) const noexcept;
    T Norm() const noexcept;
    SVector3 Normalized() const noexcept;

    SVector3 Cross(SVector3 const& other) const noexcept;

    static SVector3 Lerp(SVector3 const& x, SVector3 const& y, T t) noexcept;
  };

  template <std::floating_point T>
  struct alignas(16) SVector4 {
    T x, y, z, w;

    explicit SVector4() noexcept = default;
    explicit SVector4(T x, T y, T z, T w) noexcept;
    explicit SVector4(SVector3<T> xyz, T w) noexcept;
    explicit SVector4(SPackedVector4<T> vector) noexcept;

    SPackedVector4<T> Packed() const noexcept;

    SVector3<T> xyz() const noexcept;

    SVector4 operator+(SVector4 const& other) const noexcept;
    SVector4 operator-(SVector4 const& other) const noexcept;
    SVector4 operator*(SVector4 const& other) const noexcept;
    SVector4 operator/(SVector4 const& other) const noexcept;

    SVector4 operator*(T v) const noexcept;
    SVector4 operator/(T v) const noexcept;

    T InnerDot(SVector4 const& other) const noexcept;
    T Norm() const noexcept;
    SVector4 Normalized() const noexcept;

    static SVector4 Lerp(SVector4 const& x, SVector4 const& y, T t) noexcept;
  };

  template <std::floating_point T>
  struct SMatrix4 {
    SVector4<T> columns[4];

    explicit SMatrix4() noexcept = default;
    explicit SMatrix4(SVector4<T> columns[4]) noexcept;
    explicit SMatrix4(SVector4<T> c0, SVector4<T> c1, SVector4<T> c2, SVector4<T> c3) noexcept;

    SMatrix4 operator+(SMatrix4 const& other) const noexcept;
    SMatrix4 operator-(SMatrix4 const& other) const noexcept;
    SMatrix4 operator*(SMatrix4 const& other) const noexcept;
    SMatrix4 operator/(SMatrix4 const& other) const noexcept;

    SVector4<T> Act(SVector4<T> const& vector) const noexcept;

    SMatrix4 Transposed() const noexcept;
    SMatrix4 Dot(SMatrix4 const& other) const noexcept;

    T Determinant() const noexcept;
    bool TryInverse(SMatrix4& output) const noexcept;

    static SMatrix4 const Identity;
    static SMatrix4 Translation(SVector3<T> delta) noexcept;
    static SMatrix4 Dilation(SVector3<T> dilationFactors) noexcept;
    static SMatrix4 PerspectiveProjection(T fieldOfView, T near, T far) noexcept;
    static SMatrix4 LookAt(SVector3<T> target, SVector3<T> up) noexcept;
  };

  static_assert(sizeof(SPackedVector2<float>) == sizeof(float) * 2);
  static_assert(sizeof(SPackedVector3<float>) == sizeof(float) * 3);
  static_assert(sizeof(SPackedVector4<float>) == sizeof(float) * 4);
  static_assert(alignof(SPackedVector2<float>) == alignof(float));
  static_assert(alignof(SPackedVector3<float>) == alignof(float));
  static_assert(alignof(SPackedVector4<float>) == alignof(float));
  static_assert(sizeof(SPackedVector2<double>) == sizeof(double) * 2);
  static_assert(sizeof(SPackedVector3<double>) == sizeof(double) * 3);
  static_assert(sizeof(SPackedVector4<double>) == sizeof(double) * 4);
  static_assert(alignof(SPackedVector2<double>) == alignof(double));
  static_assert(alignof(SPackedVector3<double>) == alignof(double));
  static_assert(alignof(SPackedVector4<double>) == alignof(double));
}
