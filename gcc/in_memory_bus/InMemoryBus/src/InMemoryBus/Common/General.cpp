/*
 * General.cpp
 *
 *  Created on: 13 Dec. 2017
 *      Author: tom
 */

#include "General.h"
#include <string>
#include <thread>
#include <sstream>

namespace InMemoryBus {
namespace Common {

using namespace std;

string thread_id_to_string(thread::id id) {
  stringstream ss{};
  ss << id;

  return ss.str();
}

}
}
