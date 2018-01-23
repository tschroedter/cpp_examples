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

using namespace std;

namespace InMemoryBus {
namespace Common {

string thread_id_to_string(thread::id id);

}
}

#endif /* INMEMORYBUS_COMMON_GENERAL_H_ */
