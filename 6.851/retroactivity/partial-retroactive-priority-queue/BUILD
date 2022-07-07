cc_library(
  name = "retroactive_priority_queue",
  hdrs = ["retroactive-priority-queue.hpp"],
  strip_include_prefix = "",
)

cc_library(
  name = "retroactive_priority_queue_stupid",
  hdrs = ["retroactive-priority-queue-stupid.hpp"],
  strip_include_prefix = "",
)

cc_test(
  name = "test_retroactive_priority_queue",
  deps = [
    "retroactive_priority_queue",
    "retroactive_priority_queue_stupid",
    "@gtest//:gtest",
    "@gtest//:gtest_main",
  ],
  srcs = ["retroactive-priority-queue-test.cpp"],
)
