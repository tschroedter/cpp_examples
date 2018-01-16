/*
 * ITemperaturesMonitor.h
 *
 *  Created on: 6 Nov. 2017
 *      Author: tom
 */

#ifndef INTERFACES_MONITORS_TEMPERATURES_ITEMPERATURESMONITOR_H_
#define INTERFACES_MONITORS_TEMPERATURES_ITEMPERATURESMONITOR_H_

#include <memory>

namespace Sauerteig {
namespace Interfaces {
namespace Monitors {
namespace Temperatures {
class ITemperaturesMonitor {
 public:
    virtual ~ITemperaturesMonitor() = default;

    virtual void operator()() = 0;
    virtual std::string to_string() const = 0;
};
}
}
}
}

typedef std::shared_ptr<Sauerteig::Interfaces::Monitors::Temperatures::ITemperaturesMonitor> ITemperaturesMonitor_SPtr;

#endif /* INTERFACES_MONITORS_TEMPERATURES_ITEMPERATURESMONITOR_H_ */