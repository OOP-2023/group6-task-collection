#ifndef _RADIO_BUTTON_HPP
#include "ComponentBase.hpp"
class RadioButton : public ComponentBase
{
private:
	bool checked;
	char text[17];
public:
	void show_dialog() override;
	void print() const override;
	void flip();
	bool is_on() const;

	ComponentBase* clone() const override
	{
		return new RadioButton(*this);
	}

	~RadioButton()
	{

	}
};

#endif // !_RADIO_BUTTON_HPP
