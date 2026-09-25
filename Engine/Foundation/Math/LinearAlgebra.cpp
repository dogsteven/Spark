module;

#include <algorithm>
#include <cmath>
#include <concepts>

module Spark.Engine.Foundation.Math;

namespace Spark::Engine::Foundation::Math {
  template <std::floating_point T, unsigned N>
  void CopyRows(SMatrix4<T> const& matrix, T (&rows)[4][N]) noexcept;

  template <std::floating_point T>
  SPackedVector2<T>::SPackedVector2(T const x, T const y) noexcept: x(x), y(y) {}

  template <std::floating_point T>
  SPackedVector3<T>::SPackedVector3(T const x, T const y, T const z) noexcept: x(x), y(y), z(z) {}

  template <std::floating_point T>
  SPackedVector4<T>::SPackedVector4(T const x, T const y, T const z, T const w) noexcept:
  x(x), y(y), z(z), w(w) {}

  template <std::floating_point T>
  SVector2<T>::SVector2(T const x, T const y) noexcept: x(x), y(y) {}

  template <std::floating_point T>
  SVector2<T>::SVector2(SPackedVector2<T> const vector) noexcept: x(vector.x), y(vector.y) {}

  template <std::floating_point T>
  SPackedVector2<T> SVector2<T>::Packed() const noexcept {
    return SPackedVector2<T>(x, y);
  }

  template <std::floating_point T>
  SVector2<T> SVector2<T>::operator+(SVector2 const& other) const noexcept {
    return SVector2(x + other.x, y + other.y);
  }

  template <std::floating_point T>
  SVector2<T> SVector2<T>::operator-(SVector2 const& other) const noexcept {
    return SVector2(x - other.x, y - other.y);
  }

  template <std::floating_point T>
  SVector2<T> SVector2<T>::operator*(SVector2 const& other) const noexcept {
    return SVector2(x * other.x, y * other.y);
  }

  template <std::floating_point T>
  SVector2<T> SVector2<T>::operator/(SVector2 const& other) const noexcept {
    return SVector2(x / other.x, y / other.y);
  }

  template <std::floating_point T>
  SVector2<T> SVector2<T>::operator*(T const v) const noexcept {
    return SVector2(x * v, y * v);
  }

  template <std::floating_point T>
  SVector2<T> SVector2<T>::operator/(T const v) const noexcept {
    T const vInversed = T(1) / v;
    return SVector2(x * vInversed, y * vInversed);
  }

  template <std::floating_point T>
  T SVector2<T>::InnerDot(SVector2 const& other) const noexcept {
    return x * other.x + y * other.y;
  }

  template <std::floating_point T>
  T SVector2<T>::Norm() const noexcept {
    return std::hypot(x, y);
  }

  template <std::floating_point T>
  SVector2<T> SVector2<T>::Normalized() const noexcept {
    return *this / Norm();
  }

  template <std::floating_point T>
  SVector2<T> SVector2<T>::Lerp(SVector2<T> const& x, SVector2<T> const& y, T const t) noexcept {
    return x + (y - x) * t;
  }

  template <std::floating_point T>
  SVector3<T>::SVector3(T const x, T const y, T const z) noexcept: x(x), y(y), z(z) {}

  template <std::floating_point T>
  SVector3<T>::SVector3(SVector2<T> const xy, T const z) noexcept: x(xy.x), y(xy.y), z(z) {}

  template <std::floating_point T>
  SVector3<T>::SVector3(SPackedVector3<T> const vector) noexcept:
  x(vector.x), y(vector.y), z(vector.z) {}

  template <std::floating_point T>
  SPackedVector3<T> SVector3<T>::Packed() const noexcept {
    return SPackedVector3<T>(x, y, z);
  }

  template <std::floating_point T>
  SVector2<T> SVector3<T>::xy() const noexcept {
    return SVector2<T>(x, y);
  }

  template <std::floating_point T>
  SVector3<T> SVector3<T>::operator+(SVector3<T> const& other) const noexcept {
    return SVector3<T>(x + other.x, y + other.y, z + other.z);
  }

  template <std::floating_point T>
  SVector3<T> SVector3<T>::operator-(SVector3<T> const& other) const noexcept {
    return SVector3<T>(x - other.x, y - other.y, z - other.z);
  }

  template <std::floating_point T>
  SVector3<T> SVector3<T>::operator*(SVector3<T> const& other) const noexcept {
    return SVector3<T>(x * other.x, y * other.y, z * other.z);
  }

  template <std::floating_point T>
  SVector3<T> SVector3<T>::operator/(SVector3<T> const& other) const noexcept {
    return SVector3<T>(x / other.x, y / other.y, z / other.z);
  }

  template <std::floating_point T>
  SVector3<T> SVector3<T>::operator*(T const v) const noexcept {
    return SVector3<T>(x * v, y * v, z * v);
  }

  template <std::floating_point T>
  SVector3<T> SVector3<T>::operator/(T const v) const noexcept {
    T const vInversed = T(1) / v;
    return SVector3<T>(x * vInversed, y * vInversed, z * vInversed);
  }

  template <std::floating_point T>
  T SVector3<T>::InnerDot(SVector3<T> const& other) const noexcept {
    return x * other.x + y * other.y + z * other.z;
  }

  template <std::floating_point T>
  T SVector3<T>::Norm() const noexcept {
    return std::hypot(x, y, z);
  }

  template <std::floating_point T>
  SVector3<T> SVector3<T>::Normalized() const noexcept {
    return *this / Norm();
  }

  template <std::floating_point T>
  SVector3<T> SVector3<T>::Cross(SVector3<T> const& other) const noexcept {
    return SVector3<T>(
      z * other.y - y * other.z,
      x * other.z - z * other.x,
      y * other.x - x * other.y
    );
  }

  template <std::floating_point T>
  SVector3<T> SVector3<T>::Lerp(SVector3<T> const& x, SVector3<T> const& y, T const t) noexcept {
    return x + (y - x) * t;
  }

  template <std::floating_point T>
  SVector4<T>::SVector4(T x, T y, T z, T w) noexcept: x(x), y(y), z(z), w(w) {}

  template <std::floating_point T>
  SVector4<T>::SVector4(SVector3<T> const xyz, T const w) noexcept: x(xyz.x), y(xyz.y), z(xyz.z), w(w) {}

  template <std::floating_point T>
  SVector4<T>::SVector4(SPackedVector4<T> const vector) noexcept:
  x(vector.x), y(vector.y), z(vector.z), w(vector.w) {}

  template <std::floating_point T>
  SPackedVector4<T> SVector4<T>::Packed() const noexcept {
    return SPackedVector4<T>(x, y, z, w);
  }

  template <std::floating_point T>
  SVector3<T> SVector4<T>::xyz() const noexcept {
    return SVector3<T>(x, y, z);
  }

  template <std::floating_point T>
  SVector4<T> SVector4<T>::operator+(SVector4<T> const& other) const noexcept {
    return SVector4<T>(x + other.x, y + other.y, z + other.z, w + other.w);
  }

  template <std::floating_point T>
  SVector4<T> SVector4<T>::operator-(SVector4<T> const& other) const noexcept {
    return SVector4<T>(x - other.x, y - other.y, z - other.z, w - other.w);
  }

  template <std::floating_point T>
  SVector4<T> SVector4<T>::operator*(SVector4<T> const& other) const noexcept {
    return SVector4<T>(x * other.x, y * other.y, z * other.z, w * other.w);
  }

  template <std::floating_point T>
  SVector4<T> SVector4<T>::operator/(SVector4<T> const& other) const noexcept {
    return SVector4<T>(x / other.x, y / other.y, z / other.z, w / other.w);
  }

  template <std::floating_point T>
  SVector4<T> SVector4<T>::operator*(T const v) const noexcept {
    return SVector4<T>(x * v, y * v, z * v, w * v);
  }

  template <std::floating_point T>
  SVector4<T> SVector4<T>::operator/(T const v) const noexcept {
    T const vInversed = T(1) / v;
    return SVector4<T>(x * vInversed, y * vInversed, z * vInversed, w * vInversed);
  }

  template <std::floating_point T>
  T SVector4<T>::InnerDot(SVector4<T> const& other) const noexcept {
    return x * other.x + y * other.y + z * other.z + w * other.w;
  }

  template <std::floating_point T>
  T SVector4<T>::Norm() const noexcept {
    return std::hypot(std::hypot(x, y), std::hypot(z, w));
  }

  template <std::floating_point T>
  SVector4<T> SVector4<T>::Normalized() const noexcept {
    return *this / Norm();
  }

  template <std::floating_point T>
  SVector4<T> SVector4<T>::Lerp(SVector4<T> const& x, SVector4<T> const& y, T const t) noexcept {
    return x + (y - x) * t;
  }

  template <std::floating_point T>
  SMatrix4<T>::SMatrix4(SVector4<T> source[4]) noexcept:
  columns {source[0], source[1], source[2], source[3]} {}

  template <std::floating_point T>
  SMatrix4<T>::SMatrix4(SVector4<T> c0, SVector4<T> c1, SVector4<T> c2, SVector4<T> c3) noexcept:
  columns {c0, c1, c2, c3} {}

  template <std::floating_point T>
  SMatrix4<T> SMatrix4<T>::operator+(SMatrix4<T> const& other) const noexcept {
    return SMatrix4<T>(
      columns[0] + other.columns[0],
      columns[1] + other.columns[1],
      columns[2] + other.columns[2],
      columns[3] + other.columns[3]
    );
  }

  template <std::floating_point T>
  SMatrix4<T> SMatrix4<T>::operator-(SMatrix4<T> const& other) const noexcept {
    return SMatrix4<T>(
      columns[0] - other.columns[0],
      columns[1] - other.columns[1],
      columns[2] - other.columns[2],
      columns[3] - other.columns[3]
    );
  }

  template <std::floating_point T>
  SMatrix4<T> SMatrix4<T>::operator*(SMatrix4<T> const& other) const noexcept {
    return SMatrix4<T>(
      columns[0] * other.columns[0],
      columns[1] * other.columns[1],
      columns[2] * other.columns[2],
      columns[3] * other.columns[3]
    );
  }

  template <std::floating_point T>
  SMatrix4<T> SMatrix4<T>::operator/(SMatrix4<T> const& other) const noexcept {
    return SMatrix4<T>(
      columns[0] / other.columns[0],
      columns[1] / other.columns[1],
      columns[2] / other.columns[2],
      columns[3] / other.columns[3]
    );
  }

  template <std::floating_point T>
  SVector4<T> SMatrix4<T>::Act(SVector4<T> const& vector) const noexcept {
    return columns[0] * vector.x + columns[1] * vector.y
           + columns[2] * vector.z + columns[3] * vector.w;
  }

  template <std::floating_point T>
  SMatrix4<T> SMatrix4<T>::Transposed() const noexcept {
    SVector4<T> result[4] = {
      SVector4<T>(columns[0].x, columns[1].x, columns[2].x, columns[3].x),
      SVector4<T>(columns[0].y, columns[1].y, columns[2].y, columns[3].y),
      SVector4<T>(columns[0].z, columns[1].z, columns[2].z, columns[3].z),
      SVector4<T>(columns[0].w, columns[1].w, columns[2].w, columns[3].w)
    };
    return SMatrix4<T>(result);
  }

  template <std::floating_point T>
  SMatrix4<T> SMatrix4<T>::Dot(SMatrix4<T> const& other) const noexcept {
    return SMatrix4<T>(
      Act(other.columns[0]),
      Act(other.columns[1]),
      Act(other.columns[2]),
      Act(other.columns[3])
    );
  }

  template <std::floating_point T>
  T SMatrix4<T>::Determinant() const noexcept {
    T rows[4][4];
    CopyRows(*this, rows);
    T result = T(1);

    for (unsigned column = 0; column < 4; ++column) {
      unsigned pivot = column;
      for (unsigned row = column + 1; row < 4; ++row) {
        if (std::abs(rows[row][column]) > std::abs(rows[pivot][column])) {
          pivot = row;
        }
      }

      if (rows[pivot][column] == T(0)) {
          return T(0);
      }

      if (pivot != column) {
        std::swap(rows[pivot], rows[column]);
        result = -result;
      }

      T const diagonal = rows[column][column];
      result *= diagonal;

      for (unsigned row = column + 1; row < 4; ++row) {
        T const factor = rows[row][column] / diagonal;
        for (unsigned entry = column + 1; entry < 4; ++entry) {
          rows[row][entry] -= factor * rows[column][entry];
        }
      }
    }
    return result;
  }

  template <std::floating_point T>
  bool SMatrix4<T>::TryInverse(SMatrix4<T>& output) const noexcept {
    T rows[4][8] = {};
    CopyRows(*this, rows);

    for (unsigned row = 0; row < 4; ++row) {
      rows[row][row + 4] = T(1);
      for (unsigned column = 0; column < 4; ++column) {
        if (!std::isfinite(rows[row][column])) {
          return false;
        }
      }
    }

    for (unsigned column = 0; column < 4; ++column) {
      unsigned pivot = column;
      for (unsigned row = column + 1; row < 4; ++row) {
        if (std::abs(rows[row][column]) > std::abs(rows[pivot][column])) {
          pivot = row;
        }
      }

      T const diagonal = rows[pivot][column];
      if (diagonal == T(0) || !std::isfinite(diagonal)) {
        return false;
      }

      if (pivot != column) {
        std::swap(rows[pivot], rows[column]);
      }

      for (unsigned entry = 0; entry < 8; ++entry) {
        rows[column][entry] /= diagonal;
      }

      rows[column][column] = T(1);
      for (unsigned row = 0; row < 4; ++row) {
        if (row == column) {
          continue;
        }

        T const factor = rows[row][column];
        for (unsigned entry = 0; entry < 8; ++entry) {
          rows[row][entry] -= factor * rows[column][entry];
        }

        rows[row][column] = T(0);
      }
    }

    for (unsigned row = 0; row < 4; ++row) {
      for (unsigned column = 4; column < 8; ++column) {
        if (!std::isfinite(rows[row][column])) {
          return false;
        }
      }
    }

    output = SMatrix4<T>(
      SVector4<T>(rows[0][4], rows[1][4], rows[2][4], rows[3][4]),
      SVector4<T>(rows[0][5], rows[1][5], rows[2][5], rows[3][5]),
      SVector4<T>(rows[0][6], rows[1][6], rows[2][6], rows[3][6]),
      SVector4<T>(rows[0][7], rows[1][7], rows[2][7], rows[3][7])
    );
    return true;
  }

  template <std::floating_point T>
  const SMatrix4<T> SMatrix4<T>::Identity(
    SVector4<T>(T(1), T(0), T(0), T(0)),
    SVector4<T>(T(0), T(1), T(0), T(0)),
    SVector4<T>(T(0), T(0), T(1), T(0)),
    SVector4<T>(T(0), T(0), T(0), T(1))
  );

  template <std::floating_point T>
  SMatrix4<T> SMatrix4<T>::Translation(SVector3<T> delta) noexcept {
    return SMatrix4<T>(
      SVector4<T>(T(1), T(0), T(0), T(0)),
      SVector4<T>(T(0), T(1), T(0), T(0)),
      SVector4<T>(T(0), T(0), T(1), T(0)),
      SVector4<T>(delta, T(1))
    );
  }

  template <std::floating_point T>
  SMatrix4<T> SMatrix4<T>::Dilation(SVector3<T> dilationFactors) noexcept {
    return SMatrix4<T>(
      SVector4<T>(dilationFactors.x, T(0), T(0), T(0)),
      SVector4<T>(T(0), dilationFactors.y, T(0), T(0)),
      SVector4<T>(T(0), T(0), dilationFactors.z, T(0)),
      SVector4<T>(T(0), T(0), T(0), T(1))
    );
  }

  template <std::floating_point T>
  SMatrix4<T> SMatrix4<T>::PerspectiveProjection(T const fieldOfView, T const near, T const far) noexcept {
    T const focalLength = T(1) / std::tan(fieldOfView / T(2));
    T const depthScale = far / (far - near);

    return SMatrix4<T>(
      SVector4<T>(focalLength, T(0), T(0), T(0)),
      SVector4<T>(T(0), focalLength, T(0), T(0)),
      SVector4<T>(T(0), T(0), depthScale, T(1)),
      SVector4<T>(T(0), T(0), -near * depthScale, T(0))
    );
  }

  template <std::floating_point T>
  SMatrix4<T> SMatrix4<T>::LookAt(SVector3<T> const target, SVector3<T> const up) noexcept {
    SVector3<T> const forward = target.Normalized();
    SVector3<T> const right = forward.Cross(up).Normalized();
    SVector3<T> const cameraUp = right.Cross(forward);

    return SMatrix4<T>(
      SVector4<T>(right.x, cameraUp.x, forward.x, T(0)),
      SVector4<T>(right.y, cameraUp.y, forward.y, T(0)),
      SVector4<T>(right.z, cameraUp.z, forward.z, T(0)),
      SVector4<T>(T(0), T(0), T(0), T(1))
    );
  }

  template struct SPackedVector2<float>;
  template struct SPackedVector3<float>;
  template struct SPackedVector4<float>;
  template struct SVector2<float>;
  template struct SVector3<float>;
  template struct SVector4<float>;
  template struct SMatrix4<float>;
  template struct SPackedVector2<double>;
  template struct SPackedVector3<double>;
  template struct SPackedVector4<double>;
  template struct SVector2<double>;
  template struct SVector3<double>;
  template struct SVector4<double>;
  template struct SMatrix4<double>;

  template <std::floating_point T, unsigned N>
  void CopyRows(SMatrix4<T> const& matrix, T (&rows)[4][N]) noexcept {
    for (unsigned column = 0; column < 4; ++column) {
      rows[0][column] = matrix.columns[column].x;
      rows[1][column] = matrix.columns[column].y;
      rows[2][column] = matrix.columns[column].z;
      rows[3][column] = matrix.columns[column].w;
    }
  }
}
