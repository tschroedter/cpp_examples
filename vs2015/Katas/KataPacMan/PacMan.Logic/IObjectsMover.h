#pragma once

#include <memory>
#include "IPlayingField.h"
#include "ValidationStatus.h"

namespace PacMan
{
    namespace Logic
    {
        class IObjectsMover
        {
        public:
            virtual ~IObjectsMover () = default;

            virtual void initialize ( const IPlayingField_Ptr& playing_field ) = 0;
            virtual void calculate () = 0;
            virtual std::ostream& print_moves ( std::ostream& out ) const = 0;
            virtual void move_objects () const = 0;
            virtual ValidationStatus get_status() const = 0;
        };

        typedef std::shared_ptr<IObjectsMover> IObjectsMover_Ptr;
    };
};
