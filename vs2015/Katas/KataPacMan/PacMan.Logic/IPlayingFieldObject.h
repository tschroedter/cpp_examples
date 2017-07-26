#pragma once

#include "ILocation.h"
#include "PlayingFieldObjectType.h"
#include "Heading.h"

namespace PacMan
{
    namespace Logic
    {
        class IPlayingFieldObject
        {
        public:
            virtual ~IPlayingFieldObject () = default;

            virtual PlayingFieldObjectType get_type () const = 0;
            virtual Heading get_heading () const = 0;
            virtual void set_heading ( Heading heading ) = 0;
            virtual bool is_moving () const = 0;
            virtual void tick () = 0;
            virtual bool is_moveable () const = 0;
        };

        typedef std::shared_ptr<IPlayingFieldObject> IPlayingFieldObject_Ptr;
    };
};
