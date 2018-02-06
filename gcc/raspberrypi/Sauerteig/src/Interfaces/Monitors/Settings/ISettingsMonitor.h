/*
 * ISettingsMonitor.h
 *
 *  Created on: 6 Feb. 2018
 *      Author: tom
 */

#ifndef SRC_INTERFACES_MONITORS_SETTINGS_ISETTINGSMONITOR_H_
#define SRC_INTERFACES_MONITORS_SETTINGS_ISETTINGSMONITOR_H_

#include <memory>
#include <string>

using namespace std;

namespace Sauerteig {
namespace Interfaces {
namespace Monitors {
namespace Settings {

class ISettingsMonitor {
 public:
    virtual ~ISettingsMonitor() = default;

    virtual void operator()() = 0;
    virtual string to_string() const = 0;
};

}
}
}
}

typedef shared_ptr<Sauerteig::Interfaces::Monitors::Settings::ISettingsMonitor> ISettingsMonitor_SPtr;

#endif /* SRC_INTERFACES_MONITORS_SETTINGS_ISETTINGSMONITOR_H_ */
