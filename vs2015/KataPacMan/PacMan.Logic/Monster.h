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
                : PlayingFieldObject (
                                      PlayingFieldObjectType_Monster,
                                      location,
                                      direction )
            {
            };

            ~Monster ()
            {
            }

            PlayingFieldObjectType get_type () const override;
            ILocation_Ptr get_location () const override;
            Heading get_heading () const override;
            void tick () override;
        };
    };
};
