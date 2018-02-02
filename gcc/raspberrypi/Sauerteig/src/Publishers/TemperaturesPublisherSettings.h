/*
 * TemperaturesSettings.h
 *
 *  Created on: 2 Feb. 2018
 *      Author: tom
 */

#ifndef SRC_PUBLISHERS_TEMPERATURESPUBLISHERSETTINGS_H_
#define SRC_PUBLISHERS_TEMPERATURESPUBLISHERSETTINGS_H_

#include <mutex>
#include "Common/CommonTypes.h"
#include "../Interfaces/Publishers/ITemperaturesPublisherSettings.h"

using namespace std;
using namespace Sauerteig::Interfaces::Publishers;

namespace Sauerteig {
namespace Publishers {

class TemperaturesPublisherSettings : public ITemperaturesPublisherSettings {
 public:
    TemperaturesPublisherSettings() = default;
    virtual ~TemperaturesPublisherSettings() = default;

    celsius get_inside_average_value_correction() override;
    void set_inside_average_value_correction(celsius value) override;
    celsius get_outside_average_value_correction() override;
    void set_outside_average_value_correction(celsius) override;

 private:
    mutex m_mutex { };

    celsius m_inside_average_value_correction = (celsius) 0;
    celsius m_outside_average_value_correction = (celsius) 0;
};

}
}

#endif /* SRC_PUBLISHERS_TEMPERATURESPUBLISHERSETTINGS_H_ */
