#include "gtest/gtest.h"

#include "retroactive-priority-queue-stupid.hpp"
#include "retroactive-priority-queue.hpp"

TEST(RetroactivePriorityQueue, InsertsOnly) {
  stupid::retroactive::RetroactivePriorityQueue<int> stupid;
  retroactive::RetroactivePriorityQueue<int> smart;

  for (int i = 0; i < 10; ++i) {
    EXPECT_EQ(stupid.enqueue(i, i), smart.enqueue(i, i));
  }
}
