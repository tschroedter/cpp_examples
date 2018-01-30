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

using namespace std;

namespace InMemoryBus {
namespace Common {

string thread_id_to_string(thread::id id) {
  stringstream ss { };
  ss << id;

  return ss.str();
}

}
}
