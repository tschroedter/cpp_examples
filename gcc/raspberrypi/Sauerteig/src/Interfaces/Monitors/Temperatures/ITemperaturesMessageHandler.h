/*
 * ITemperaturesMessageHandler.h
 *
 *  Created on: 16 Jan. 2018
 *      Author: tom
 */

#ifndef INTERFACES_MONITORS_TEMPERATURES_ITEMPERATURESMESSAGEHANDLER_H_
#define INTERFACES_MONITORS_TEMPERATURES_ITEMPERATURESMESSAGEHANDLER_H_

#include <memory>

namespace Sauerteig {
namespace Interfaces {
namespace Monitors {
namespace Temperatures {

class ITemperaturesMessageHandler {
 public:
    virtual ~ITemperaturesMessageHandler() = default;

    virtual celsius get_inside_average_value() const = 0;
    virtual double get_inside_average__percent_valid() const = 0;
    virtual celsius get_outside_average_value() const = 0;
    virtual double get_outside_average__percent_valid() const = 0;  // ToDo typedef percent
};

}
}
}
}

typedef std::shared_ptr<Sauerteig::Interfaces::Monitors::Temperatures::ITemperaturesMessageHandler> ITemperaturesMessageHandler_SPtr;

#endif /* INTERFACES_MONITORS_TEMPERATURES_ITEMPERATURESMESSAGEHANDLER_H_ */
