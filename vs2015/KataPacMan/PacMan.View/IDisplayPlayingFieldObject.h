#pragma once
#include <string>
#include <memory>
#include "IPlayingFieldObject.h"
#include "DisplayObjectType.h"

namespace PacMan
{
    namespace View
    {
        class IDisplayPlayingFieldObject
        {
        public:
            virtual ~IDisplayPlayingFieldObject () = default;

            virtual DisplayObjectType get_type () const = 0;
            virtual std::string to_string () = 0;
            virtual void initialize ( const Logic::IPlayingFieldObject_Ptr object ) = 0;
        };

        typedef std::shared_ptr<IDisplayPlayingFieldObject> IDisplayPlayingFieldObject_Ptr;
    };
};
