#include "stdafx.h"
#include "MonstersHeadingUpdater.h"

void PacMan::Logic::MonstersHeadingUpdater::initialize ( const IPlayingField_Ptr& playing_field )
{
    m_playing_field = playing_field;
    m_locator->initialize(playing_field);
}

void PacMan::Logic::MonstersHeadingUpdater::update () const
{
    // todo maybe nicer to get all monsters from playing field and have method give me position for object on playing field
    auto pacmans = m_locator->get_all_of_type(PlayingFieldObjectType_PacMan);
    auto pacman = (*pacmans)[0]; // todo null checks

    m_calculator->pacman_row = pacman->row;
    m_calculator->pacman_column = pacman->column;

    auto monsters = m_locator->get_all_of_type(PlayingFieldObjectType_Monster);

    for (auto iter = monsters->begin(); iter != monsters->end();
         ++iter)
    {
        ILocatorInformation_Ptr info = (*iter);

        m_calculator->monster_row = info->row;
        m_calculator->monster_column = info->column;

        m_calculator->calculate();

        auto heading = m_calculator->get_heading();
        info->object->set_heading(heading);
    }
}
