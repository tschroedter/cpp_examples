#pragma once
#include "IPlayingFieldObject.h"
#include "PlayingFieldObjectType.h"
#include "IDirection.h"

namespace PacMan
{
    namespace Logic
    {
        class PlayingFieldObject
                : public IPlayingFieldObject
        {
        protected:
            PlayingFieldObjectType m_type;
            ILocation_Ptr m_location;
            IDirection_Ptr m_direction;
        public:
            PlayingFieldObject (
                PlayingFieldObjectType type,
                ILocation_Ptr location,
                IDirection_Ptr direction )
                : m_type ( type )
                , m_location ( location )
                , m_direction ( direction )
            {
            }

            PlayingFieldObjectType get_type () const override;
            Heading get_heading () const override;
            void set_heading(Heading heading) override;
            virtual bool is_moving() const override;
            virtual void tick () override;  // todo check if we still need this
            bool is_moveable() const override;
        };
    };
};
