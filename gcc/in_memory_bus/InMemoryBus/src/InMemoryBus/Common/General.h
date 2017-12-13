/*
 * General.h
 *
 *  Created on: 13 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_COMMON_GENERAL_H_
#define INMEMORYBUS_COMMON_GENERAL_H_

#include <string>
#include <thread>

namespace InMemoryBus {
namespace Common {

  using namespace std;

  string thread_id_to_string(thread::id id);

}
}

#endif /* INMEMORYBUS_COMMON_GENERAL_H_ */
