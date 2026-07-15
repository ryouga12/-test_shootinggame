#include "Actor.h"


//コンストラクタ
Actor::Actor(const int& new_hp, const int& new_speed, const int& new_height, const int& new_width, const float& new_actor_pos_x, const float& new_actor_pos_y):
	hp(new_hp),speed(new_speed),height(new_height),width(new_width), actor_pos_x(new_actor_pos_x), actor_pos_y(new_actor_pos_y)
{
	max_hp = hp;
}

Actor::~Actor()
{

}

