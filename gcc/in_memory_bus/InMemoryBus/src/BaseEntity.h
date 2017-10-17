/*
 * BaseEntity.h
 *
 *  Created on: 23 Aug. 2017
 *      Author: tom
 */

#ifndef BASEENTITY_H_
#define BASEENTITY_H_

#include "uuid/uuid.h"
#include <memory>
#include <string>

namespace InMemoryBus
{

    class BaseEntity
    {
        public:
            BaseEntity();
            BaseEntity(const std::string& uuid_as_text);
            virtual ~BaseEntity();

            void get_id(uuid_t& id) const;
            bool is_id_equal_to(uuid_t other) const;

        protected:
            uuid_t m_id;
    };

} /* namespace InMemoryBus */

#endif /* BASEENTITY_H_ */
