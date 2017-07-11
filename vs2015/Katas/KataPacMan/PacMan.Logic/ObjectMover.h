#pragma once
#include "IObjectMover.h"
#include "IPlayingField.h"

namespace PacMan
{
    namespace Logic
    {
        class ObjectMover   // todo testing
            : public IObjectMover
        {
        private:
            IPlayingField_Ptr m_playing_field;

            bool is_moveable_object(const IPlayingFieldObject_Ptr object);
            size_t move_left(const size_t& column) const;
            size_t move_right(const size_t& column) const;
            size_t move_up(const size_t& row) const;
            size_t move_down(const size_t& row) const;

        public:
            ObjectMover::ObjectMover(
                IPlayingField_Ptr playing_field);

            ~ObjectMover();

            void ObjectMover::move_object(
                const size_t from_row,
                const size_t from_columns) override;

            void initialize(const IPlayingField_Ptr& playing_field) override;
        };
    };
};
