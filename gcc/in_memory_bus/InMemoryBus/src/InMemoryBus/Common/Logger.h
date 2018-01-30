/*
 * Logger.h
 *
 *  Created on: 8 Dec. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_COMMON_LOGGER_H_
#define SRC_INMEMORYBUS_COMMON_LOGGER_H_

#include <string>
#include <mutex>
#include <iostream>
#include "Interfaces/ILogger.h"
#include "LogLevel.h"
#include "Interfaces/IThreadInformationProvider.h"

using namespace std;
using namespace Common::Interfaces;

namespace Common {

class Logger : public ILogger { // Todo check if testing all methods
 public:
    Logger(IThreadInformationProvider_SPtr provider);
    virtual ~Logger() = default;

    void debug(string message) override;
    void error(string message) override;
    void warn(string message) override;
    void info(string message) override;

    void set_prefix(string prefix) override;

    LogLevel get_log_level() const override;
    void set_log_level(LogLevel level) override;

 protected:
    Logger(IThreadInformationProvider_SPtr provider, ostream& out);

 private:
    IThreadInformationProvider_SPtr m_provider = nullptr;

    static LogLevel m_log_level;

    ostream& m_cout = cout;
    recursive_mutex m_mutex { };

    string m_prefix = "";

    void write_log_line(string debug_level, string message) const;
    string create_timestamp() const;
    string create_log_line(string debug_level, string message) const;
    string create_thread_pid() const;
};

}

#endif /* SRC_INMEMORYBUS_COMMON_LOGGER_H_ */
