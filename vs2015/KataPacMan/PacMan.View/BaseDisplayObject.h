#pragma once
#include "IPlayingFieldObject.h"
#include "DisplayObjectType.h"
#include <string>

namespace PacMan
{
    namespace View
    {
        class BaseDisplayObject
        {
        protected:
            Logic::IPlayingFieldObject_Ptr m_object = nullptr;
            DisplayObjectType m_type = DisplayObjectType_Unknown;
            std::string m_to_string;

        public:
            BaseDisplayObject (
                DisplayObjectType object_type,
                std::string to_string = "UN" )
                : m_type ( object_type )
                , m_to_string ( to_string )
            {
            }

            virtual ~BaseDisplayObject () = default;
        };
    };
};
