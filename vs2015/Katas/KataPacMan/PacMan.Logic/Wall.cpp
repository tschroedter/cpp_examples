#include "stdafx.h"
#include "Wall.h"

using namespace PacMan::Logic;

PlayingFieldObjectType Wall::get_type () const
{
    return PlayingFieldObject::get_type();
}

Heading Wall::get_heading () const
{
    return PlayingFieldObject::get_heading();
}

void Wall::set_heading ( Heading heading )
{
    // nothing to do here
}

bool Wall::is_moving () const
{
    return false;
}

void Wall::tick ()
{
}

bool Wall::is_moveable () const
{
    return false;
}
