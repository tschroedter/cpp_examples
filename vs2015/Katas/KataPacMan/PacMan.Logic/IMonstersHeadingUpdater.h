#pragma once
#include <memory>
#include "IPlayingField.h"

namespace PacMan
{
    namespace Logic
    {
        class IMonstersHeadingUpdater
        {
        public:
            virtual ~IMonstersHeadingUpdater () = default;

            virtual void initialize ( const IPlayingField_Ptr& playing_field ) = 0;
            virtual void update () const = 0;
        };

        typedef std::shared_ptr<IMonstersHeadingUpdater> IMonstersHeadingUpdater_Ptr;
    };
};
