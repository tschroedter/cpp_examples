/*
 * SubscriberInformation.h
 *
 *  Created on: 17Jun.,2017
 *      Author: tom
 */

#ifndef SUBSCRIBERINFORMATION_H_
#define SUBSCRIBERINFORMATION_H_

#include <memory>
#include <string>
#include <vector>
#include "../Typedefs.h"

namespace InMemoryBus
{

    class SubscriberInformation
    {
        public:
            SubscriberInformation(
                    const std::string id,
                    const SubscriberFunction function);
            virtual ~SubscriberInformation();

            friend bool operator<(
                    const SubscriberInformation& one,
                    const SubscriberInformation& two);

            std::string subscriber_id;
            SubscriberFunction function;
    };

    typedef SubscriberInformation* SubscriberInformation_Ptr;
    typedef std::vector<SubscriberInformation_Ptr> Subscribers;
    typedef Subscribers* Subscribers_Ptr;

    // --- new
    typedef std::shared_ptr<SubscriberInformation> SubscriberInformation_SPtr;
    typedef std::vector<SubscriberInformation_SPtr> SubscriberInformationVector;
    typedef std::shared_ptr<SubscriberInformationVector> SubscriberInformationVector_SPtr;

} /* namespace InMemoryBus */

#endif /* SUBSCRIBERINFORMATION_H_ */
