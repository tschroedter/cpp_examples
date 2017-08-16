#include "stdafx.h"
#include "MonstersHeadingUpdater.h"
#include "IPacMan.h"

using namespace PacMan::Logic;

void MonstersHeadingUpdater::initialize (
    const IPlayingField_Ptr& playing_field )
{
    m_playing_field = playing_field;
    m_locator->initialize(playing_field);
}

ILocatorInformation_Ptr MonstersHeadingUpdater::get_pacman () const
{
    auto pacmans = m_locator->get_all_of_type(PlayingFieldObjectType_PacMan);

    if (pacmans->size() == 0)
    {
        return nullptr;
    }

    return (*pacmans)[0];
}

void MonstersHeadingUpdater::calculate_and_update_monster (
    ILocatorInformation_Ptr info ) const
{
    m_calculator->monster_row = info->row;
    m_calculator->monster_column = info->column;

    m_calculator->calculate();

    auto heading = m_calculator->get_heading();
    info->object->set_heading(heading);
}

void MonstersHeadingUpdater::calculate_and_update_all_monsters () const
{
    auto monsters = m_locator->get_all_of_type(PlayingFieldObjectType_Monster);

    for (auto iter = monsters->begin(); iter != monsters->end();
         ++iter)
    {
        calculate_and_update_monster(*iter);
    }
}

void MonstersHeadingUpdater::update () const
{
    // todo maybe nicer to get all monsters from playing field and have method give me position for object on playing field
    auto pacman = get_pacman();

    if (pacman == nullptr)
    {
        return; // todo logging
    }

    m_calculator->pacman_row = pacman->row;
    m_calculator->pacman_column = pacman->column;

    calculate_and_update_all_monsters();
}
