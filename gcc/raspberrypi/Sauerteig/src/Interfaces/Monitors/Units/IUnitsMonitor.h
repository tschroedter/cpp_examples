/*
 * IHeaterMonitor.h
 *
 *  Created on: 12 Feb. 2018
 *      Author: tom
 */

#ifndef SRC_INTERFACES_MONITORS_UNITS_IUNITSMONITOR_H_
#define SRC_INTERFACES_MONITORS_UNITS_IUNITSMONITOR_H_

#include <memory>

using namespace std;

namespace Sauerteig {
namespace Interfaces {
namespace Monitors {
namespace Units {

class IUnitsMonitor {
 public:
    virtual ~IUnitsMonitor() = default;

    virtual void operator()() = 0;
    virtual string to_string() const = 0;
};

}
}
}
}

typedef shared_ptr<Sauerteig::Interfaces::Monitors::Units::IUnitsMonitor> IHeaterMonitor_SPtr;

#endif /* SRC_INTERFACES_MONITORS_UNITS_IUNITSMONITOR_H_ */
