/*
 * Tmp36Console.h
 *
 *  Created on: 3 Nov. 2017
 *      Author: tom
 */

#ifndef IO_SENSORS_TMP36CONSOLE_H_
#define IO_SENSORS_TMP36CONSOLE_H_

#include <chrono>
#include <thread>
#include "../../Interfaces/IO/Sensors/ITmp36.h"
#include "../../Interfaces/IO/Sensors/ITmp36Console.h"

class Tmp36Console : public ITmp36Console {
 public:
    Tmp36Console(ITmp36_SPtr tmp36);
    virtual ~Tmp36Console() = default;

    void operator()() override {
        while (1) {
            std::this_thread::sleep_for(std::chrono::seconds(1));

            print();
        }
    }

    void initialize(uint channel, std::string description) override;
    void print() const override;

 private:
    ITmp36_SPtr m_tmp36 = nullptr;
    std::string m_description;
};

#endif /* IO_TMP36CONSOLE_H_ */
