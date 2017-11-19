/*
 * Logger.h
 *
 *  Created on: 18 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_COMMON_LOGGER_H_
#define SRC_COMMON_LOGGER_H_

#include <string>
#include "Interfaces/ILogger.h"

namespace Common {
class Logger : public Interfaces::ILogger {
 public:
    Logger() = default;
    virtual ~Logger() = default;

    void debug(std::string message) override;
    void error(std::string message) override;
    void info(std::string message) override;
};
}

#endif /* SRC_COMMON_LOGGER_H_ */
