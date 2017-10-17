/*
 * BaseRepository.h
 *
 *  Created on: 22 Aug. 2017
 *      Author: tom
 */

#ifndef BASEREPOSITORY_H_
#define BASEREPOSITORY_H_

#include <memory>
#include <vector>
#include "uuid/uuid.h"
#include "BaseEntity.h"
#include "UnknownEntity.h"

namespace InMemoryBus
{
    template<class T>
    class BaseRepository
    {
            typedef std::shared_ptr<T> SP_PointerOfT;
            typedef std::vector<SP_PointerOfT> VectorOfT;
            typedef std::shared_ptr<VectorOfT> SP_VectorOfT;

        public:
            BaseRepository(SP_VectorOfT entities) :
                    m_entities
                    { entities }
            {
                // Compile-time sanity check
                static_assert(std::is_base_of<BaseEntity, T>::value, "T not derived from BaseClass");
            }

            virtual ~BaseRepository() = default;

            SP_PointerOfT findById(uuid_t& id)
            {
                int indexToFind = findIndexById(id);

                if (indexToFind > -1)
                {
                    return (m_entities->at(indexToFind));
                }

                return (nullptr);
            }

            void add(const SP_PointerOfT entity)
            {
                m_entities->push_back(entity);
            }

            void remove(const SP_PointerOfT entity)
            {
                uuid_t id;
                entity->get_id(id);

                const int index = this->findIndexById(id);

                if (index >= 0)
                {
                    m_entities->erase(m_entities->begin() + index);
                }
            }

            SP_VectorOfT getAll()
            {
                VectorOfT* p_vector = new VectorOfT();

                for (auto iter = m_entities->begin(); iter != m_entities->end();
                        iter++)
                {
                    SP_PointerOfT entity = (*iter);

                    p_vector->push_back(entity);
                }

                auto all = std::shared_ptr<VectorOfT>(p_vector);

                return (all);
            }

            size_t size()   // todo testing
            {
                return m_entities->size();
            }

        protected:
            SP_VectorOfT m_entities;

            int findIndexById(uuid_t& id)
            {
                int indexToFind = -1;
                int currentIndex = 0;

                for (auto iter = m_entities->begin(); iter != m_entities->end();
                        iter++)
                {
                    SP_PointerOfT entity = (*iter);

                    if (entity->is_id_equal_to(id))
                    {
                        indexToFind = currentIndex;
                        break;
                    }

                    currentIndex++;
                }

                return (indexToFind);
            }
    };
} /* namespace InMemoryBus */

#endif /* BASEREPOSITORY_H_ */

