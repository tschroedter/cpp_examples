#pragma once
#include "IMovingObjectsRepository.h"
#include "IMoveObjectInformation.h"
#include <functional>

namespace PacMan
{
    namespace Logic
    {
        class MovingObjectsRepository
            : public IMovingObjectsRepository
        {
        public:
            MovingObjectsRepository (
                MovingObjectsInformationVector_Ptr vector );
            ~MovingObjectsRepository () = default;

            void add ( const IMoveObjectInformation_Ptr information ) override;
            void clear () override;
            MovingObjectsInformationVector_Ptr get_all () const override;
            MovingObjectsInformationVector_Ptr get_all_of_type ( PlayingFieldObjectType type ) const override;
            std::ostream& print_moves ( std::ostream& out ) const override;

        private:
            MovingObjectsInformationVector_Ptr m_informations;

            MovingObjectsInformationVector_Ptr MovingObjectsRepository::get_all_with_filter (
                std::function<bool  ( IMoveObjectInformation_Ptr& )> func ) const;
        };
    }
}
