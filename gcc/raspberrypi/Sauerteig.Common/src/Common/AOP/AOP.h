/*
 * AOP.h
 *
 *  Created on: 24 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_COMMON_AOP_AOP_H_
#define SRC_COMMON_AOP_AOP_H_

#include <iostream>
#include <string>
#include <functional>
#include <memory>
#include <chrono>

#define LOG std::cout
#define NL std::endl

// Helpers to convert lambda into std::function

template<typename Function>
struct function_traits : public function_traits<decltype(&Function::operator())> {
};

template<typename ClassType, typename ReturnType, typename ... Args>
struct function_traits<ReturnType (ClassType::*)(Args...) const> {
    typedef ReturnType (*pointer)(Args...);
    typedef std::function<ReturnType(Args...)> function;
};

template<typename Function>
typename function_traits<Function>::function to_function(Function& lambda) {
    return static_cast<typename function_traits<Function>::function>(lambda);
}

// Aspect logging duration of execution
template<typename R, typename ...Args>
std::function<R(Args...)> logged(std::string name, std::function<R(Args...)> f) {
    return [f,name](Args... args) {

        LOG << name << " start" << NL;
        auto start = std::chrono::high_resolution_clock::now();

        R result = f(std::forward<Args>(args)...);

        auto end = std::chrono::high_resolution_clock::now();
        auto total = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        LOG << "Elapsed: " << total << "us" << NL;

        return result;
    };
}

/* example
 void Cooler::on() {
 auto on = [this]()->bool{m_cooler->on(); return true;};

 logged("Cooler", to_function(on))();
 }
 */

#endif /* SRC_COMMON_AOP_AOP_H_ */
