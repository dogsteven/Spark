module;

#include <cstddef>
#include <cstdint>
#include <memory>
#include <utility>

export module Spark.Engine.Foundation.Memory:LinearAllocator;

import Spark.Engine.Foundation.Utilities.Janitor;

export namespace Spark::Engine::Foundation::Memory {
  using SJanitor = Spark::Engine::Foundation::Utilities::SJanitor;

  class SLinearAllocator {
  private:
    std::byte* m_Buffer;
    std::size_t m_Capacity;
    std::size_t m_Offset;

    [[nodiscard]] void* AllocateBytes(std::size_t size, std::size_t alignment) noexcept;
  public:
    explicit SLinearAllocator(std::size_t capacity);
    SLinearAllocator(SLinearAllocator const& other) noexcept = delete;
    SLinearAllocator(SLinearAllocator&& other) noexcept = delete;

    SLinearAllocator& operator=(SLinearAllocator const& other) noexcept = delete;
    SLinearAllocator& operator=(SLinearAllocator&& other) noexcept = delete;

    template <typename T, typename... Args>
    [[nodiscard]] T* Allocate(Args&&... args);

    template <typename T, typename... Args>
    [[nodiscard]] T* AllocateWithJanitor(SJanitor& janitor, Args&&... args);

    void Reset() noexcept;
  };

  template <typename T, typename... Args>
  [[nodiscard]] T* SLinearAllocator::Allocate(Args&&... args) {
    std::uintptr_t savedOffset = m_Offset;

    T* memory = static_cast<T*>(AllocateBytes(sizeof(T), alignof(T)));

    if (memory == nullptr) {
      return nullptr;
    }

    try {
      return std::construct_at(memory, std::forward<Args>(args)...);
    } catch (...) {
      m_Offset = savedOffset;
      throw;
    }
  }

  template <typename T, typename... Args>
  [[nodiscard]] T* SLinearAllocator::AllocateWithJanitor(SJanitor& janitor, Args&&... args) {
    T* const memory = Allocate<T>(args...);
    janitor.AddDestruction(memory);

    return memory;
  }
}
