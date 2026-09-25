module;

#include <cstddef>
#include <functional>
#include <vector>

module Spark.Engine.Foundation.Utilities.Janitor;

namespace Spark::Engine::Foundation::Utilities {
  SJanitor::SJanitor(std::size_t capacity): m_CleanUpTasks() {
    m_CleanUpTasks.reserve(capacity);
  }

  SJanitor::~SJanitor() noexcept {
    CleanUp();
  }

  void SJanitor::AddCleanUpTask(std::function<void()> const cleanUpTask) noexcept {
    m_CleanUpTasks.push_back(std::move(cleanUpTask));
  }

  void SJanitor::CleanUp() noexcept {
    for (auto cleanUpTask = m_CleanUpTasks.rbegin(); cleanUpTask != m_CleanUpTasks.rend(); ++cleanUpTask) {
      (*cleanUpTask)();
    }

    m_CleanUpTasks.clear();
  }
}
