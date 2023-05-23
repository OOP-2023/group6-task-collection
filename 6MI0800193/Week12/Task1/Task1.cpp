#include <iostream>
#include "EventWithFixedIntermission.hpp"
#include "EventWithIntermission.hpp"
#include "SimpleEvent.hpp"
#include "EventManager.hpp"

int main()
{
	EventManager man(8);

	man.add_event(new SimpleEvent(14, 0, 16, 00));
	man.add_event(new EventWithFixedIntermission(17, 00, 20, 00, 18, 00));

	man.add_event(new EventWithFixedIntermission(15, 0, 18, 30, 17, 15));

	std::cout << "Events at 14:00 - " << man.ongoin_events(14, 00) << std::endl;
	std::cout << "Events at 17:00 - " << man.ongoin_events(17, 10) << std::endl;
	std::cout << "Events at 15:00 - " << man.ongoin_events(15, 00) << std::endl;

	std::cout << man.get_max_attendable() << std::endl;


}
