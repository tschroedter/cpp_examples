/*
 * ISSR.h
 *
 *  Created on: 17 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_INTERFACES_IO_SERIALSHIFTREGISTER_ISSR_H_
#define SRC_HARDWARE_INTERFACES_IO_SERIALSHIFTREGISTER_ISSR_H_

#include <memory>

namespace Hardware {
namespace Interfaces {
namespace IO {
namespace SerialShiftRegister {
class ISSR {
 public:
    virtual ~ISSR() = default;

    virtual void set_value(int value) = 0;
    virtual int get_value() const = 0;
};
}
}
}
}

typedef std::shared_ptr<Hardware::Interfaces::IO::SerialShiftRegister::ISSR> ISSR_SPtr;

#endif /* SRC_HARDWARE_INTERFACES_IO_SERIALSHIFTREGISTER_ISSR_H_ */
