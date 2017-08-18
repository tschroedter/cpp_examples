#pragma once

#include <memory>
#include <map>
#include "IDisplayPlayingFieldObject.h"
#include "IObjectToDisplayFieldObject.h"
#include <functional>
#include "IDisplayPacMan.h"
#include <Hypodermic/FactoryWrapper.h>
#include "IDisplayUnknown.h"
#include "IDisplayMonster.h"
#include "IDisplayMax.h"
#include "IDisplayDot.h"
#include "IDisplayWall.h"

namespace PacMan
{
    namespace View
    {
        class ObjectToDisplayFieldObject
            : public IObjectToDisplayFieldObject
        {
        private:
            std::map<Logic::PlayingFieldObjectType,
                     DisplayObjectFactory> m_play_to_display;

            std::function<std::shared_ptr<IDisplayUnknown>  ()> m_factory_unknown;
            std::function<std::shared_ptr<IDisplayDot>  ()> m_factory_dot;
            std::function<std::shared_ptr<IDisplayWall>  ()> m_factory_wall;
            std::function<std::shared_ptr<IDisplayPacMan>  ()> m_factory_pac_man;
            std::function<std::shared_ptr<IDisplayMonster>  ()> m_factory_monster;
            std::function<std::shared_ptr<IDisplayMax>  ()> m_factory_max;

        public:
            ObjectToDisplayFieldObject (
                const Hypodermic::FactoryWrapper<IDisplayUnknown>&
                factory_wrapper_unknown,
                const Hypodermic::FactoryWrapper<IDisplayDot>&
                factory_wrapper_dot,
                const Hypodermic::FactoryWrapper<IDisplayWall>&
                factory_wrapper_wall,
                const Hypodermic::FactoryWrapper<IDisplayPacMan>&
                factory_wrapper_pac_man,
                const Hypodermic::FactoryWrapper<IDisplayMonster>&
                factory_wrapper_monster,
                const Hypodermic::FactoryWrapper<IDisplayMax>&
                factory_wrapper_max )
                : m_factory_unknown(factory_wrapper_unknown.getFactory()),
                  m_factory_dot(factory_wrapper_dot.getFactory()),
                  m_factory_wall(factory_wrapper_wall.getFactory()),
                  m_factory_pac_man(factory_wrapper_pac_man.getFactory()),
                  m_factory_monster(factory_wrapper_monster.getFactory()),
                  m_factory_max(factory_wrapper_max.getFactory())
            {
            }

            ~ObjectToDisplayFieldObject ()
            {
            }

            void initialize () override;
            void add_mapping (
                const Logic::PlayingFieldObjectType object_type,
                const DisplayObjectFactory factory ) override;
            IDisplayPlayingFieldObject_Ptr get_object_for (
                const Logic::IPlayingFieldObject_Ptr playing_field ) const override;
        };
    };
};
