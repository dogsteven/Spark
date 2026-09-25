module;

#include <cstddef>
#include <memory>

#include <Diagnostics/Assertion/AssertionMacros.h>

module Spark.Engine.Foundation.Memory;

namespace Spark::Engine::Foundation::Memory {
  SLinearAllocator::SLinearAllocator(std::size_t const capacity): m_Capacity(capacity), m_Offset(0) {
    SPARK_ASSERT("Foundation::Memory", capacity > 0, "Capacity must be positive");

    m_Buffer = new std::byte[m_Capacity];
    m_Offset = 0;
  }

  void* SLinearAllocator::AllocateBytes(std::size_t const size, std::size_t const alignment) noexcept {
    std::size_t remaining = m_Capacity - m_Offset;

    if (size > remaining) {
      return nullptr;
    }

    void* memory = m_Buffer + m_Offset;

    if (std::align(alignment, size, memory, remaining) == nullptr) {
      return nullptr;
    }

    m_Offset = m_Capacity - remaining + size;
    return memory;
  }

  void SLinearAllocator::Reset() noexcept {
    m_Offset = 0;
  }
}
