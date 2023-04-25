#ifndef _ENGINE_HPP
#define _ENGINE_HPP
#include "CarPart.hpp"
class Engine : public CarPart
{
private:
	int hp;
public:
	Engine();
	Engine(int hp, const char* id, const char* man_name, const char* desc);

	void set_hp(int hp);
	int get_hp();

	friend std::ostream& operator<< (std::ostream& out, const Engine& tire);
};
#endif // !_ENGINE_HPP
