#pragma once

namespace PacMan
{
    namespace Logic
    {
        class IPlayingFieldValidator
        {
        public:
            virtual ~IPlayingFieldValidator () = default;

            virtual void initialize (
                const size_t rows,
                const size_t columns ) =0;

            virtual size_t get_rows () const = 0;
            virtual size_t get_columns () const = 0;

            virtual void validate_object ( const IPlayingFieldObject_Ptr object ) const = 0;
            virtual void validate_row ( const size_t row ) const = 0;
            virtual void validate_column ( const size_t column ) const = 0;
            virtual void validate_rows_and_columns (
                const size_t rows,
                const size_t columns ) const = 0; // todo column and row typedef
        };

        typedef std::shared_ptr<IPlayingFieldValidator> IPlayingFieldValidator_Ptr;
    };
};
