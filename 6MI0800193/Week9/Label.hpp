#ifndef _LABEL_HPP
#define _LABEL_HPP
#include "ComponentBase.hpp"
class Label : public ComponentBase
{
private:
	char content[17];
public:
	void print() const override;
	void show_dialog() override;

	ComponentBase* clone() const {
		return new Label(*this);
	}

	~Label()
	{

	}
};

#endif // !_LABEL_HPP
