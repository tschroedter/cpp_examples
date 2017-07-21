#pragma once
#include "PlayingFieldObject.h"
#include "IDirection.h"
#include "IPacMan.h"

namespace PacMan
{
    namespace Logic
    {
        class PacMan
                : public PlayingFieldObject
                  , public IPacMan
        {
        public:
            PacMan ( ILocation_Ptr location,
                     IDirection_Ptr direction )
                : PlayingFieldObject (
                                      PlayingFieldObjectType_PacMan,
                                      location,
                                      direction )
            {
            };

            ~PacMan ()
            {
            }

            PlayingFieldObjectType get_type () const override;
            Heading get_heading () const override;
            void set_heading(Heading heading) override;
            bool is_moving() const override;
            void tick () override;
        };
    };
};
