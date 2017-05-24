#pragma once
#include "IPlayingField.h"

namespace PacMan
{
    namespace View
    {
        class IDisplayPlayingField
        {
        public:
            virtual ~IDisplayPlayingField () = default;

            virtual void initialize (
                const Logic::IPlayingField_Ptr playing_field ) = 0;

            virtual size_t get_rows () const = 0;
            virtual size_t get_columns () const = 0;
            virtual void print () = 0;
        };

        typedef std::shared_ptr<IDisplayPlayingField> IDisplayPlayingField_Ptr;
    };
};
