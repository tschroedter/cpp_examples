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
    // todo continue here
}
