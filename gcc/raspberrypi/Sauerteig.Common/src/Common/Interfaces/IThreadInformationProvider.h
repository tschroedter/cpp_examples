/*
 * IThreadPidProvider.h
 *
 *  Created on: 22 Jan. 2018
 *      Author: tom
 */

#ifndef COMMON_INTERFACES_ITHREADPIDPROVIDER_H_
#define COMMON_INTERFACES_ITHREADPIDPROVIDER_H_

#include <thread>
#include <string>

namespace Common {
namespace Interfaces {

class IThreadInformationProvider {
 public:
    virtual ~IThreadInformationProvider() = default;

    virtual std::string thread_id_to_string (const std::thread::id thread_id) const = 0;
    virtual pid_t get_thread_process_id (void) const = 0;
    virtual std::string get_thread_process_id_as_string (void) const = 0;
    virtual pid_t get_process_id() const = 0;
    virtual std::string get_process_id_as_string() const = 0;
    virtual std::thread::id get_thread_id() const = 0;
    virtual std::string get_thread_id_as_string() const = 0;
};

}
}

typedef std::shared_ptr<Common::Interfaces::IThreadInformationProvider> IThreadInformationProvider_SPtr;

#endif /* SRC_COMMON_INTERFACES_ITHREADPIDPROVIDER_H_ */
