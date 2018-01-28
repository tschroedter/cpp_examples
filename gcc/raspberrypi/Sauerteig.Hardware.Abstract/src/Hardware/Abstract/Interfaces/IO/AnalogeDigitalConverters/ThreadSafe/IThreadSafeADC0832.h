/*
 * IThreadSafeADC0832.h
 *
 *  Created on: 4 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_ABSTRACT_INTERFACES_IO_ANALOGEDIGITALCONVERTERS_THREADSAFE_ITHREADSAFEADC0832_H_
#define SRC_HARDWARE_ABSTRACT_INTERFACES_IO_ANALOGEDIGITALCONVERTERS_THREADSAFE_ITHREADSAFEADC0832_H_

#include <memory>
#include "Hardware/Interfaces/IO/AnalogeDigitalConverters/IADC0832.h"
#include "Common/CommonTypes.h"

namespace Hardware {
namespace Abstract {
namespace Interfaces {
namespace IO {
namespace AnalogeDigitalConverters {
namespace ThreadSafe {
class IThreadSafeADC0832 : public Hardware::Interfaces::IO::AnalogeDigitalConverters::IADC0832 {
 public:
    virtual ~IThreadSafeADC0832() = default;

    virtual void set_adc0832(IADC0832_SPtr adc0832) = 0;
};
}
}
}
}
}
}

typedef std::shared_ptr<Hardware::Abstract::Interfaces::IO::AnalogeDigitalConverters::ThreadSafe::IThreadSafeADC0832> IThreadSafeADC0832_SPtr;

#endif /* SRC_HARDWARE_ABSTRACT_INTERFACES_IO_ANALOGEDIGITALCONVERTERS_THREADSAFE_ITHREADSAFEADC0832_H_ */
