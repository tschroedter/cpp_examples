/*
 * ThreadPidProvider.cpp
 *
 *  Created on: 22 Jan. 2018
 *      Author: tom
 */

#include "ThreadInformationProvider.h"

#include <thread>
#include <string>
#include <sstream>
#include <pthread.h>
#include <syscall.h>
#include <unistd.h>

namespace Common {

    pid_t ThreadInformationProvider::get_thread_process_id (void) const
    {
            return syscall(__NR_gettid);
    }

    std::string ThreadInformationProvider::get_thread_process_id_as_string (void) const
    {
            pid_t tid = get_thread_process_id();

            std::string text = std::to_string((int) tid);

            return text;
    }

    pid_t ThreadInformationProvider::get_process_id() const {
        pid_t pid = getpid();

        return pid;
    }

    std::string ThreadInformationProvider::get_process_id_as_string() const {
        pid_t pid = get_process_id();

        std::string text = std::to_string((int) pid);

        return text;
    }

    std::thread::id ThreadInformationProvider::get_thread_id() const {
        std::thread::id thread_id = std::this_thread::get_id();

        return thread_id;
    }

    std::string ThreadInformationProvider::get_thread_id_as_string() const {
        std::thread::id thread_id = get_thread_id();

        std::stringstream ss { };

        ss << thread_id;

        return (ss.str());
    }

}
