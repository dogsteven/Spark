module;

#include <cstddef>
#include <functional>
#include <vector>
#include <memory>

export module Spark.Engine.Foundation.Utilities.Janitor;

export namespace Spark::Engine::Foundation::Utilities {
  class SJanitor {
  private:
    std::vector<std::function<void()>> m_CleanUpTasks;

  public:
    explicit SJanitor(std::size_t capacity);
    SJanitor(SJanitor const& other) noexcept = delete;
    ~SJanitor() noexcept;

    SJanitor& operator=(SJanitor const& other) noexcept = delete;

    void AddCleanUpTask(std::function<void()>) noexcept;
    void CleanUp() noexcept;

    template <typename T>
    void AddDestruction(T* object) noexcept;
  };

  template <typename T>
  void SJanitor::AddDestruction(T* const object) noexcept {
    if constexpr (!std::is_destructible_v<T>) {
      return;
    }

    AddCleanUpTask([object]() {
      std::destroy_at(object);
    });
  }
}
