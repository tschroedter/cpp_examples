/*
 * TestLogger.cpp
 *
 *  Created on: 14 Dec. 2017
 *      Author: tom
 */

#include "TestLogger.h"
#include "InMemoryBus/Common/Logger.h"

namespace InMemoryBusTests {

TestLogger::TestLogger(std::ostream& cout)
: InMemoryBus::Common::Logger(cout) {
}

}
