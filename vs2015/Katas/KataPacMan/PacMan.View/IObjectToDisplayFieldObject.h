#pragma once

#include <memory>
#include "IDisplayPlayingFieldObject.h"
#include <functional>

namespace PacMan
{
    namespace View
    {
        typedef std::function<std::shared_ptr<IDisplayPlayingFieldObject>  ()> DisplayObjectFactory;

        class IObjectToDisplayFieldObject
        {
        public:
            virtual ~IObjectToDisplayFieldObject () = default;

            virtual void initialize () = 0;
            virtual void add_mapping (
                const Logic::PlayingFieldObjectType object_type,
                const DisplayObjectFactory factory ) = 0;
            virtual IDisplayPlayingFieldObject_Ptr get_object_for (
                const Logic::IPlayingFieldObject_Ptr playing_field ) const = 0;
        };

        typedef std::shared_ptr<IObjectToDisplayFieldObject> IObjectToDisplayFieldObject_Ptr;
    };
};
