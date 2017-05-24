#pragma once
#include "IDot.h"
#include "PlayingFieldObject.h"
#include "IDirection.h"

namespace PacMan
{
    namespace Logic
    {
        class Dot
                : public PlayingFieldObject
                  , public IDot
        {
        public:
            Dot ( ILocation_Ptr location,
                  IDirection_Ptr direction )
                : PlayingFieldObject (
                                      PlayingFieldObjectType_Dot,
                                      location,
                                      direction )
            {
            };

            ~Dot ()
            {
            }

            PlayingFieldObjectType get_type () const override;
            ILocation_Ptr get_location () const override;
            Heading get_heading () const override;
            void tick () override;
        };
    };
};
