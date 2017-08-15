#include "stdafx.h"
#include <memory>
#include "IDisplayPlayingFieldObject.h"
#include "ObjectToDisplayFieldObject.h"
#include "ObjectToDisplayFieldObjectException.h"

namespace PacMan
{
    namespace View
    {
        void ObjectToDisplayFieldObject::initialize ()
        {
            add_mapping(Logic::PlayingFieldObjectType_Unknown, m_factory_unknown);
            add_mapping(Logic::PlayingFieldObjectType_Dot, m_factory_dot);
            add_mapping(Logic::PlayingFieldObjectType_PacMan, m_factory_pac_man);
            add_mapping(Logic::PlayingFieldObjectType_Monster, m_factory_monster);
            add_mapping(Logic::PlayingFieldObjectType_Max, m_factory_max);
        }

        void ObjectToDisplayFieldObject::add_mapping (
            const Logic::PlayingFieldObjectType object_type,
            const DisplayObjectFactory factory )
        {
            if (factory == nullptr)
            {
                throw ObjectToDisplayFieldObjectException(
                                                          "Given factory for mapping is nullptr!");
            }

            m_play_to_display[object_type] = factory;
        }

        IDisplayPlayingFieldObject_Ptr
        ObjectToDisplayFieldObject::get_object_for (
            const Logic::IPlayingFieldObject_Ptr object ) const
        {
            Logic::PlayingFieldObjectType object_type = object->get_type();

            DisplayObjectFactory factory = m_play_to_display.at(object_type);

            IDisplayPlayingFieldObject_Ptr display_object = factory();
            display_object->initialize(object);

            return display_object;
        }
    };
};
