#ifndef _TEXTBOX_HPP
#include <iostream>
#include <string>
#include "ComponentBase.hpp"
class TextBox : public ComponentBase
{
private:
	std::string text;
public:
	const char* get_text();
	void print() const override;
	void show_dialog() override;
	~TextBox() = default;

	ComponentBase* clone() const override
	{
		return new TextBox(*this);
	}

};
#endif // !_TEXTBOX_HPP
