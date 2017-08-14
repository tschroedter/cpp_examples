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
                const Row rows,
                const Column columns ) = 0;

            virtual Row get_rows () const = 0;
            virtual Column get_columns () const = 0;

            virtual void validate_object ( const IPlayingFieldObject_Ptr object ) const = 0;
            virtual void validate_row ( const Row row ) const = 0;
            virtual void validate_column ( const Column column ) const = 0;
            virtual void validate_rows_and_columns (
                const Row rows,
                const Column columns ) const = 0; // todo column and row typedef
        };

        typedef std::shared_ptr<IPlayingFieldValidator> IPlayingFieldValidator_Ptr;
    };
};
