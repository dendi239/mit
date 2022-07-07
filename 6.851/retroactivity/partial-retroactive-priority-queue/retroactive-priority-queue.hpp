#include <optional>

namespace retroactive {

template <typename T>
class RetroactivePriorityQueue {
 public:
  RetroactivePriorityQueue();
  ~RetroactivePriorityQueue();

  ::std::optional<T> enqueue(int now, T item);
  ::std::optional<T> delete_min(int now);
  
 private:
  int preceding_bridge(int now) const;
};

}  // namespace retroactive

/////////////////////////////// Implementation. ///////////////////////////////

namespace retroactive {



}  // namespace retroactive
