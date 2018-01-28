/*
 * IThreadPidProvider.h
 *
 *  Created on: 22 Jan. 2018
 *      Author: tom
 */

#ifndef SRC_COMMON_INTERFACES_ITHREADPIDPROVIDER_H_
#define SRC_COMMON_INTERFACES_ITHREADPIDPROVIDER_H_

#include <thread>
#include <string>

using namespace std;

namespace Common {
namespace Interfaces {

class IThreadInformationProvider {
 public:
    virtual ~IThreadInformationProvider() = default;

    virtual string thread_id_to_string(const thread::id thread_id) const = 0;
    virtual pid_t get_thread_process_id(void) const = 0;
    virtual string get_thread_process_id_as_string(void) const = 0;
    virtual pid_t get_process_id() const = 0;
    virtual string get_process_id_as_string() const = 0;
    virtual thread::id get_thread_id() const = 0;
    virtual string get_thread_id_as_string() const = 0;
};

}
}

typedef shared_ptr<Common::Interfaces::IThreadInformationProvider> IThreadInformationProvider_SPtr;

#endif /* SRC_COMMON_INTERFACES_ITHREADPIDPROVIDER_H_ */
