#include "Events.hpp"
#include <iostream>
int main() {
    EventManager events;
    events.addEvent(*(new SimpleEvent(10, 00, 11, 30)));
    std::cout << events.isBusy(13, 00);
}