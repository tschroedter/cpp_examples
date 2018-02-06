/*
 * ITemperaturesSettings.h
 *
 *  Created on: 2 Feb. 2018
 *      Author: tom
 */

#ifndef SRC_INTERFACES_PUBLISHERS_ITEMPERATURESPUBLISHERSETTINGS_H_
#define SRC_INTERFACES_PUBLISHERS_ITEMPERATURESPUBLISHERSETTINGS_H_

#include <memory>
#include <string>
#include "Common/CommonTypes.h"

using namespace std;

namespace Sauerteig {
namespace Interfaces {

class ISettings {
 public:
    virtual ~ISettings() = default;

    virtual celsius get_inside_average_value_correction() = 0;
    virtual void set_inside_average_value_correction(celsius value) = 0;
    virtual celsius get_outside_average_value_correction() = 0;
    virtual void set_outside_average_value_correction(celsius) = 0;
    virtual string to_string() = 0;
};

}
}

typedef std::shared_ptr<Sauerteig::Interfaces::ISettings> ISettings_SPtr;

#endif /* SRC_INTERFACES_PUBLISHERS_ITEMPERATURESPUBLISHERSETTINGS_H_ */
