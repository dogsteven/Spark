module;

#include <cstddef>
#include <memory>

#include <Diagnostics/Assertion/AssertionMacros.h>

export module Spark.Engine.Foundation.Memory:PoolAllocator;

export namespace Spark::Engine::Foundation::Memory {
  template <typename T>
  class SIntrusivePoolAllocator {
    static_assert(sizeof(T) >= sizeof(void*), "T must be at least as large as a pointer");
  private:
    union Block {
      T value;
      Block* next;

      Block() noexcept: next(nullptr) {}
      ~Block() {}
    };
    std::size_t m_Capacity;
    std::size_t m_ActiveCount;
    Block* m_Blocks;
    Block* m_FreeHead;

  public:
    explicit SIntrusivePoolAllocator(std::size_t capacity);
    SIntrusivePoolAllocator(SIntrusivePoolAllocator const& other) noexcept = delete;
    SIntrusivePoolAllocator(SIntrusivePoolAllocator&& other) noexcept = delete;
    ~SIntrusivePoolAllocator() noexcept;

    SIntrusivePoolAllocator& operator=(SIntrusivePoolAllocator const& other) noexcept = delete;
    SIntrusivePoolAllocator& operator=(SIntrusivePoolAllocator&& other) noexcept = delete;

    template <typename... Args>
    [[nodiscard]] T* Allocate(Args&&... args);

    void Dellocate(T* memory) noexcept;
  };

  template <typename T>
  SIntrusivePoolAllocator<T>::SIntrusivePoolAllocator(std::size_t const capacity):
  m_Capacity(capacity), m_ActiveCount(0) {
    SPARK_ASSERT("Foundation::Memory", capacity > 0, "Capacity must be positive");

    m_Blocks = new Block[capacity];
    m_FreeHead = m_Blocks;

    for (std::size_t index = 0; index < capacity; ++index) {
      Block* const next = index + 1 < capacity ? std::addressof(m_Blocks[index + 1]) : nullptr;

      m_Blocks[index].next = next;
    }
  }

  template <typename T>
  SIntrusivePoolAllocator<T>::~SIntrusivePoolAllocator() noexcept {
    SPARK_ASSERT("Foundation::Memory", m_ActiveCount == 0, "Active count must be zero");

    delete[] m_Blocks;
  }

  template <typename T>
  template <typename... Args>
  T* SIntrusivePoolAllocator<T>::Allocate(Args&&... args) {
    if (m_FreeHead == nullptr) {
      return nullptr;
    }

    Block* const block = m_FreeHead;
    Block* const blockNext = block->next;

    T* memory = std::construct_at(std::addressof(block->value), args...);
    m_FreeHead = blockNext;
    ++m_ActiveCount;
    return memory;
  }

  template <typename T>
  void SIntrusivePoolAllocator<T>::Dellocate(T* const memory) noexcept {
    if (memory == nullptr) {
      return;
    }

    Block* const block = reinterpret_cast<Block*>(memory);

    if (block < m_Blocks || block >= m_Blocks + m_Capacity) {
      return;
    }

    if constexpr (std::is_destructible_v<T>) {
      std::destroy_at(memory);
    }

    block->next = m_FreeHead;
    m_FreeHead = block;
    --m_ActiveCount;
  }
}
