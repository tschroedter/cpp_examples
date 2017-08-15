#include "stdafx.h"
#include "ObjectsMoveExecuter.h"
#include "PlayingFieldObjectType.h"

using namespace PacMan::Logic;

void ObjectsMoveExecuter::initialize ( 
    const IPlayingField_Ptr playing_field, 
    const IMovingObjectsRepository_Ptr repository )
{
    m_playing_field = playing_field;
    m_repository = repository;
}

void ObjectsMoveExecuter::move_objects_in_vector (
    MovingObjectsInformationVector_Ptr vector ) const
{
    for (auto info : (*vector))
    {
        m_playing_field->move_object_from_to(info->from_row,
                                             info->from_column,
                                             info->to_row,
                                             info->to_column);
    }
}

void ObjectsMoveExecuter::move_object_pacman () const
{
    auto all_pac_mans = m_repository->get_all_of_type(PlayingFieldObjectType_PacMan); // there should be only one

    move_objects_in_vector(all_pac_mans);
}

void ObjectsMoveExecuter::move_object_monster () const
{
    auto all_monsters = m_repository->get_all_of_type(PlayingFieldObjectType_Monster);

    move_objects_in_vector(all_monsters);
}

void ObjectsMoveExecuter::move_objects () const
{
    move_object_pacman();

    move_object_monster();
}
