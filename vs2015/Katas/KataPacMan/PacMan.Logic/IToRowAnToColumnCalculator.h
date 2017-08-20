#pragma once

#include <memory>
#include "IPlayingField.h"

namespace PacMan
{
    namespace Logic
    {
        class IToRowAnToColumnCalculator
        {
        public:
            virtual ~IToRowAnToColumnCalculator () = default;

            virtual void initialize (
                const IPlayingField_Ptr playing_field ) = 0;

            virtual void caclulate () = 0;

            Heading heading = Heading_Unknown;

            Row row{0};
            Row column{0};

            Row to_row{0};
            Row to_column{0};
        };

        typedef std::shared_ptr<IToRowAnToColumnCalculator> IToRowAnToColumnCalculator_Ptr;
    };
};
