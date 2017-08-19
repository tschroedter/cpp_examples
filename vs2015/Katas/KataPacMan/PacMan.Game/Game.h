#pragma once

#include "IIOCContainerBuilder.h"
#include "IPlayingField.h"
#include "IGame.h"
#include "IPacMan.h"
#include "IMonster.h"
#include "IInputPacManMove.h"
#include "IGameTimer.h"
#include "IDisplayPlayingField.h"
#include "IWall.h"

namespace PacMan
{
    namespace Match
    {
        class Game
            : public Logic::IGame
        {
        private:
            Container_Ptr m_container;
            Logic::IPlayingField_Ptr m_playing_field;
            Logic::IPacMan_Ptr m_pac_man;
            Logic::IMonster_Ptr m_monster;
            std::function<std::shared_ptr<Logic::IWall> ()> m_factory;
            Logic::IInputPacManMove_Ptr m_input;
            Logic::IGameTimer_Ptr m_game_timer;
            View::IDisplayPlayingField_Ptr m_display;

            void create_walls () const;

        public:
            Game (
                Logic::IPlayingField_Ptr playing_field,
                Logic::IPacMan_Ptr pac_man,
                Logic::IMonster_Ptr monster,
                Logic::IInputPacManMove_Ptr input,
                Logic::IGameTimer_Ptr game_timer,
                const Hypodermic::FactoryWrapper<Logic::IWall>& factory_wrapper,
                View::IDisplayPlayingField_Ptr display )
                : m_playing_field(playing_field),
                  m_pac_man(pac_man),
                  m_monster(monster),
                  m_factory(factory_wrapper.getFactory()),
                  m_input(input),
                  m_game_timer(game_timer),
                  m_display(display)
            {
            }

            ~Game ()
            {
            }

            void run () const override;
        };
    };
};
