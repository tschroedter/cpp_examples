#pragma once

#include <memory>
#include "IPlayingFieldObject.h"
#include "IPlayingField.h"

namespace PacMan
{
    namespace Logic
    {
        class IObjectsMover
            :public IPlayingFieldObject
        {
        public:
            virtual ~IObjectsMover() = default;

            virtual void initialize(const IPlayingField_Ptr playing_field) = 0;
            virtual void move_objects() = 0;
        };

        typedef std::shared_ptr<IObjectsMover> IObjectsMover_Ptr;
    };
};
