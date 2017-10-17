/*
 * NullReferenceException.h
 *
 *  Created on: 16 Oct. 2017
 *      Author: tom
 */

#ifndef ARGUMENTINVALIDEXCEPTION_H_
#define ARGUMENTINVALIDEXCEPTION_H_

#include <iostream>
#include <string>
#include <exception>

namespace InMemoryBus
{
    // todo testing
    class ArgumentInvalidException: public std::exception
    {
        public:
            ArgumentInvalidException(const std::string & parameter_name)
            {
                m_message = create_message("", parameter_name);
            }

            ArgumentInvalidException(const std::string & error_message,
                    const std::string & parameter_name)
            {
                m_message = create_message(error_message, parameter_name);
            }

            virtual ~ArgumentInvalidException()
            {
            }

            const char* what()
            {
                return (m_message.c_str());
            }

            std::string get_message() const
            {
                return (m_message);
            }

        private:
            std::string m_message;

            std::string create_message(const std::string & error_message,
            const std::string & parameter_name) const
            {
                std::string message = "Parameter '" + parameter_name
                        + "' is invalid!";;

                if (!error_message.empty())
                {
                    message += " " + error_message;
                }

                return (message);
            }

    };

} /* namespace InMemoryBus */

#endif /* ARGUMENTINVALIDEXCEPTION_H_ */

