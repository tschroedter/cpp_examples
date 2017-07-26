#pragma once
#include "PlayingFieldObjectType.h"
#include <vector>
#include "IPlayingFieldObjectTypeToCharMapping.h"

namespace PacMam
{
    namespace View
    {
        struct PlayingFieldObjectTypeToCharMappingItem
        {
            PacMan::Logic::PlayingFieldObjectType object_type;
            char character;
        };

        class PlayingFieldObjectTypeToCharMapping
            : IPlayingFieldObjectTypeToCharMapping
        {
        private:
            std::vector<PlayingFieldObjectTypeToCharMappingItem> m_mapping{};
        public:
            void initialize () override
            {
            }
        };
    }
}
