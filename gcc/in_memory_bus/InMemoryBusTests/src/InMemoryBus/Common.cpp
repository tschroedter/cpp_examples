/*
 * Common.cpp
 *
 *  Created on: 5 Dec. 2017
 *      Author: tom
 */
#include <string>
#include <gtest/gtest.h>
#include "InMemoryBus/Common/BaseMessage.h"

namespace InMemoryBusTest {

using namespace std;

void expect_std_strings_are_equal(const string & expected, const string & actual) {
  int result = expected.compare(actual);

  if (result) {
    cout << "Actual  : " << actual << "\n";
    cout << "Expected: " << expected << "\n";
  }

  EXPECT_EQ(0, result);
}

void do_nothing_subscriber_function(BaseMessage_SPtr base_message) {
}

}

