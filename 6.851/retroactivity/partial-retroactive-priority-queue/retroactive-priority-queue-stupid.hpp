#include <map>
#include <optional>
#include <set>
#include <variant>
#include <vector>

namespace stupid::retroactive {

template <typename T>
class RetroactivePriorityQueue {
 public:
  RetroactivePriorityQueue() = default;
  ~RetroactivePriorityQueue() = default;

  ::std::optional<T> enqueue(int now, T item);
  ::std::optional<T> delete_min(int now);

 private:
  struct InsertData {
    T item;
  };

  struct DeleteMinData {};

  using Event = ::std::variant<InsertData, DeleteMinData>;

  ::std::multiset<T> AllElements() const;

  ::std::map<int, Event> events_;
};

}  // namespace stupid::retroactive

/////////////////////////////// Implementation. ///////////////////////////////

namespace stupid::retroactive {

namespace internal {

template <typename T>
::std::optional<T> first_diff(const ::std::multiset<T>& a,
                              const ::std::multiset<T>& b) {
  for (auto it_a = a.begin(), it_b = b.begin();
       it_a != a.end() || it_b != b.end(); ++it_a, ++it_b) {
    if (it_a == a.end()) {
      return *it_b;
    }
    if (it_b == b.end()) {
      return *it_a;
    }
    if (*it_a != *it_b) {
      return *it_a;
    }
  }
  return ::std::nullopt;
}

}  // namespace internal

template <typename T>
::std::multiset<T> RetroactivePriorityQueue<T>::AllElements() const {
  ::std::multiset<T> result;
  for (const auto& [_, event] : events_) {
    if (::std::holds_alternative<InsertData>(event)) {
      result.insert(std::get<InsertData>(event).item);
    } else if (!result.empty()) {
      result.erase(result.begin());
    }
  }
  return result;
}

template <typename T>
::std::optional<T> RetroactivePriorityQueue<T>::enqueue(int now, T item) {
  auto before = AllElements();
  events_.emplace(now, InsertData{item});
  return internal::first_diff(AllElements(), before);
}

template <typename T>
::std::optional<T> RetroactivePriorityQueue<T>::delete_min(int now) {
  auto before = AllElements();
  events_.emplace(now, DeleteMinData{});
  return internal::first_diff(AllElements(), before);
}

}  // namespace stupid::retroactive
