#pragma once
#include <memory>
#include "IMoveObjectInformation.h"
#include <vector>

namespace PacMan
{
    namespace Logic
    {
        typedef std::vector<IMoveObjectInformation_Ptr> MovingObjectsInformationVector;
        typedef std::shared_ptr<MovingObjectsInformationVector> MovingObjectsInformationVector_Ptr;

        class IMovingObjectsRepository
        {
        public:
            virtual ~IMovingObjectsRepository () = default;
            virtual void add ( const IMoveObjectInformation_Ptr information ) = 0;
            virtual void clear () = 0;
            virtual MovingObjectsInformationVector_Ptr get_all () const = 0;
            virtual MovingObjectsInformationVector_Ptr get_all_of_type ( PlayingFieldObjectType type ) const = 0;
            virtual std::ostream& print_moves ( std::ostream& out ) const = 0;
        };

        typedef std::shared_ptr<IMovingObjectsRepository> IMovingObjectsRepository_Ptr;
    }
}
