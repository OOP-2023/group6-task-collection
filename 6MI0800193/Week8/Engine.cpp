#include "Engine.hpp"

Engine::Engine() : CarPart()
{
	this->hp = 0;
}

Engine::Engine(int hp, const char* id, const char* man_name, const char* desc) : CarPart(id, man_name, desc)
{
	this->hp = hp;
}

void Engine::set_hp(int hp)
{
	this->hp = hp;
}

int Engine::get_hp()
{
	return hp;
}

std::ostream& operator<<(std::ostream& out, const Engine& engine)
{
	out << (CarPart&)engine;
	out << " - " << engine.hp << " hp";
	return out;
}
