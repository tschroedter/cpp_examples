/*
 * ITemperaturesPublisher.h
 *
 *  Created on: 16 Jan. 2018
 *      Author: tom
 */

#ifndef SRC_INTERFACES_PUBLISHERS_ITEMPERATURESPUBLISHER_H_
#define SRC_INTERFACES_PUBLISHERS_ITEMPERATURESPUBLISHER_H_

#include <memory>

namespace Sauerteig {
namespace Interfaces {
namespace Publishers {

class ITemperaturesPublisher {
 public:
    virtual ~ITemperaturesPublisher() = default;

    virtual void operator()() = 0;
    virtual void publish() = 0;
};

}
}
}

typedef std::shared_ptr<Sauerteig::Interfaces::Publishers::ITemperaturesPublisher> ITemperaturesPublisher_SPtr;

#endif /* SRC_INTERFACES_PUBLISHERS_ITEMPERATURESPUBLISHER_H_ */
