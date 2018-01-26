/*
 * ITemperaturesMonitor.h
 *
 *  Created on: 6 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_INTERFACES_MONITORS_TEMPERATURES_ITEMPERATURESMONITOR_H_
#define SRC_INTERFACES_MONITORS_TEMPERATURES_ITEMPERATURESMONITOR_H_

#include <memory>

using namespace std;

namespace Sauerteig {
namespace Interfaces {
namespace Monitors {
namespace Temperatures {
class ITemperaturesMonitor {
 public:
    virtual ~ITemperaturesMonitor() = default;

    virtual void operator()() = 0;
    virtual string to_string() const = 0;
};
}
}
}
}

typedef shared_ptr<Sauerteig::Interfaces::Monitors::Temperatures::ITemperaturesMonitor> ITemperaturesMonitor_SPtr;

#endif /* SRC_INTERFACES_MONITORS_TEMPERATURES_ITEMPERATURESMONITOR_H_ */
