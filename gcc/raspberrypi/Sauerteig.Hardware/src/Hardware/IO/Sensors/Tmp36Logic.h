/*
 * Tmp36Logic.h
 *
 *  Created on: 14 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_IO_SENSORS_TMP36LOGIC_H_
#define SRC_HARDWARE_IO_SENSORS_TMP36LOGIC_H_

#include "Common/CommonTypes.h"
#include "../../Interfaces/IO/Sensors/ITmp36Logic.h"

using namespace Hardware::Interfaces::IO::Sensors;

namespace Hardware {
namespace IO {
namespace Sensors {
class Tmp36Logic : public ITmp36Logic {
 public:
    Tmp36Logic() = default;
    virtual ~Tmp36Logic() = default;

    celsius raw_to_celsius(uint raw_value) override;
};
}
}
}

#endif /* SRC_HARDWARE_IO_SENSORS_TMP36LOGIC_H_ */
