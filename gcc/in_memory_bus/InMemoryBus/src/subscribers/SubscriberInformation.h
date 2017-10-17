/*
 * SubscriberInformation.h
 *
 *  Created on: 17Jun.,2017
 *      Author: tom
 */

#ifndef NEWSUBSCRIBERINFORMATION_H_
#define NEWSUBSCRIBERINFORMATION_H_

#include <memory>
#include <string>
#include <vector>
#include "../BaseEntity.h"
#include "../Typedefs.h"

namespace InMemoryBus
{
    class SubscriberInformation: public BaseEntity
    {
        public:
            SubscriberInformation(const std::string id,
                    const std::string message_type,
                    const SubscriberFunction function);
            virtual ~SubscriberInformation();

            friend bool operator<(const SubscriberInformation& one,
                    const SubscriberInformation& two);

            std::string subscriber_id;
            std::string message_type;
            SubscriberFunction subscriber_function;
    };

    typedef std::shared_ptr<SubscriberInformation> SubscriberInformation_SPtr;
    typedef std::vector<SubscriberInformation_SPtr> SubscriberInformationVector;
    typedef std::shared_ptr<SubscriberInformationVector> SubscriberInformationVector_SPtr;
} /* namespace InMemoryBus */

#endif /* NEWSUBSCRIBERINFORMATION_H_ */
