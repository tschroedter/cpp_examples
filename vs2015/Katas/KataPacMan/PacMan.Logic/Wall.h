#pragma once
#include "PlayingFieldObject.h"
#include "IDirection.h"
#include "IWall.h"

namespace PacMan
{
    namespace Logic
    {
        class Wall
            : public PlayingFieldObject
              , public IWall
        {
        public:
            Wall ( ILocation_Ptr location,
                   IDirection_Ptr direction )
                : PlayingFieldObject(
                                     PlayingFieldObjectType_Wall,
                                     location,
                                     direction)
            {
            };

            ~Wall ()
            {
            }

            PlayingFieldObjectType get_type () const override;
            Heading get_heading () const override;
            void set_heading ( Heading heading ) override;
            bool is_moving () const override;
            void tick () override;
            bool is_moveable () const override;
        };
    };
};
