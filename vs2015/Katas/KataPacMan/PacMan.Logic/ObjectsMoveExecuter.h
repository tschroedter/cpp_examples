#pragma once
#include "IMovingObjectsRepository.h"
#include "IPlayingField.h"
#include "IObjectsMoveExecuter.h"

namespace PacMan
{
    namespace Logic
    {
        class ObjectsMoveExecuter // todo testing and move into class
            : public IObjectsMoveExecuter
        {
        public:
            ObjectsMoveExecuter () = default;

            ~ObjectsMoveExecuter ()
            {
            };

            void initialize (
                const IPlayingField_Ptr playing_field,
                const IMovingObjectsRepository_Ptr repository ) override;
            void move_objects () const override;

        private:
            IPlayingField_Ptr m_playing_field;
            IMovingObjectsRepository_Ptr m_repository;

            void move_object_pacman () const;
            void move_object_monster () const;
        };
    }
}
