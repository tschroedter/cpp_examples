/*
 * Common.h
 *
 *  Created on: 4 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_COMMON_H_
#define INMEMORYBUS_COMMON_H_

#include <string>
#include "InMemoryBus/Common/BaseMessage.h"

namespace InMemoryBusTest {

using namespace std;

void expect_std_strings_contains(const string & expected, const string & actual);
void expect_std_strings_are_equal(const string & expected, const string & actual);
void do_nothing_subscriber_function(BaseMessage_SPtr base_message);

}

#endif /* INMEMORYBUS_COMMON_H_ */
