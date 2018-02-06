/*
 * ITemperaturesSetCorrectionMessageHandler.h
 *
 *  Created on: 6 Feb. 2018
 *      Author: tom
 */

#ifndef SRC_INTERFACES_MONITORS_SETTINGS_ITEMPERATURESSETCORRECTIONMESSAGEHANDLER_H_
#define SRC_INTERFACES_MONITORS_SETTINGS_ITEMPERATURESSETCORRECTIONMESSAGEHANDLER_H_

#include "Common/CommonTypes.h"

namespace Sauerteig {
namespace Interfaces {
namespace Monitors {
namespace Settings {

class ITemperaturesSetCorrectionMessageHandler {
 public:
    virtual ~ITemperaturesSetCorrectionMessageHandler() = default;

    virtual celsius get_inside_average_value_correction() const = 0;
    virtual celsius get_outside_average_value_correction() const = 0;
};

}
}
}
}

#endif /* SRC_INTERFACES_MONITORS_SETTINGS_ITEMPERATURESSETCORRECTIONMESSAGEHANDLER_H_ */
