#pragma once
#include "PlayingFieldObject.h"
#include "IDirection.h"
#include "IMonster.h"

namespace PacMan
{
    namespace Logic
    {
        class Monster
            : public PlayingFieldObject
              , public IMonster
        {
        public:
            Monster ( ILocation_Ptr location,
                      IDirection_Ptr direction )
                : PlayingFieldObject(
                                     PlayingFieldObjectType_Monster,
                                     location,
                                     direction)
            {
                PlayingFieldObject::set_heading(Heading_Down); // todo testing, plus initialize method
            };

            ~Monster ()
            {
            }

            PlayingFieldObjectType get_type () const override;
            Heading get_heading () const override;
            void set_heading ( Heading heading ) override;
            bool Monster::is_moving () const override;
            void tick () override;
            bool is_moveable () const override;
        };
    };
};
