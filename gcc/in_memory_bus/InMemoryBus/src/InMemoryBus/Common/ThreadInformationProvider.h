/*
 * ThreadPidProvider.h
 *
 *  Created on: 22 Jan. 2018
 *      Author: tom
 */

#ifndef SRC_COMMON_THREADPIDPROVIDER_H_
#define SRC_COMMON_THREADPIDPROVIDER_H_

#include <thread>
#include <string>
#include "Interfaces/IThreadInformationProvider.h"

using namespace std;
using namespace Common::Interfaces;

namespace Common {

class ThreadInformationProvider : public IThreadInformationProvider { // Todo testing
 public:
    ThreadInformationProvider() = default;
    virtual ~ThreadInformationProvider() = default;

    string thread_id_to_string(const thread::id thread_id) const override;
    pid_t get_thread_process_id(void) const override;
    string get_thread_process_id_as_string(void) const override;
    pid_t get_process_id() const override;
    string get_process_id_as_string() const override;
    thread::id get_thread_id() const override;
    string get_thread_id_as_string() const override;
};

}

#endif /* SRC_COMMON_THREADPIDPROVIDER_H_ */
