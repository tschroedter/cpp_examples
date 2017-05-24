#pragma once

namespace PacMam
{
    namespace View
    {
        class IPlayingFieldObjectTypeToCharMapping
        {
        public:
            virtual ~IPlayingFieldObjectTypeToCharMapping () = default;

            virtual void initialize () = 0;
        };
    }
}
