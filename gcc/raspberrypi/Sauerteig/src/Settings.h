/*
 * TemperaturesSettings.h
 *
 *  Created on: 2 Feb. 2018
 *      Author: tom
 */

#ifndef SRC_PUBLISHERS_SETTINGS_H_
#define SRC_PUBLISHERS_SETTINGS_H_

#include <mutex>
#include <string>
#include "Common/CommonTypes.h"
#include "Interfaces/ISettings.h"

using namespace std;
using namespace Sauerteig::Interfaces;

namespace Sauerteig {

class Settings : public ISettings {
 public:
    Settings() = default;
    virtual ~Settings() = default;

    celsius get_inside_average_value_correction() override;
    void set_inside_average_value_correction(celsius value) override;
    celsius get_outside_average_value_correction() override;
    void set_outside_average_value_correction(celsius) override;
    string to_string() override;

 private:
    mutex m_mutex { };

    celsius m_inside_average_value_correction = (celsius) 0;
    celsius m_outside_average_value_correction = (celsius) 0;
};

}

#endif /* SRC_PUBLISHERS_SETTINGS_H_ */
