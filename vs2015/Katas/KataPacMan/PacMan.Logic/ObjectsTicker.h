#pragma once
#include "IObjectsTicker.h"

namespace PacMan
{
    namespace Logic
    {
        class ObjectsTicker
            : public IObjectsTicker
        {
        private:
            IPlayingField_Ptr m_playing_field;

        public:
            ObjectsTicker () = default;
            ~ObjectsTicker () = default;

            void initialize (
                const IPlayingField_Ptr& playing_field ) override;
            void tick () const override;
        };
    };
};
