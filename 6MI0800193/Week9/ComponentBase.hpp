#ifndef _COMPONENT_BASE_HPP
#define _COMPONENT_BASE_HPP

class ComponentBase
{
protected:
	float x;
	float y;
public:

	virtual void show_dialog() = 0;
	virtual void print() const = 0;
	void move(float dx, float dy);
	virtual ComponentBase* clone() const = 0;
	virtual ~ComponentBase() = default;
};

#endif // !_COMPONENT_BASE_HPP
