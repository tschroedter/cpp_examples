/*
 * ThreadPidProvider.h
 *
 *  Created on: 22 Jan. 2018
 *      Author: tom
 */

#ifndef COMMON_THREADPIDPROVIDER_H_
#define COMMON_THREADPIDPROVIDER_H_

#include <thread>
#include <string>

#include "Interfaces/IThreadInformationProvider.h"

namespace Common {

class ThreadInformationProvider : public Interfaces::IThreadInformationProvider {
 public:
    ThreadInformationProvider() = default;
    virtual ~ThreadInformationProvider() = default;

    pid_t get_thread_process_id (void) const override;
    std::string get_thread_process_id_as_string (void) const override;
    pid_t get_process_id() const override;
    std::string get_process_id_as_string() const override;
    std::thread::id get_thread_id() const override;
    std::string get_thread_id_as_string() const override;
};

}

#endif /* COMMON_THREADPIDPROVIDER_H_ */
