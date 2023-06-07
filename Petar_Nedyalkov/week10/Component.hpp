#ifndef _COMPONENT_HPP
#define _COMPONENT_HPP

class ComponentBase {
protected:
	double x = 0;
	double y = 0;
public:
	virtual ~ComponentBase() = default;
	virtual	void showDialog() = 0;
	virtual ComponentBase* clone() = 0;
	void move(double, double);
};

class Label : public ComponentBase {
	char name[17];
public:
	~Label() = default;
	void showDialog() override;
	ComponentBase* clone() override;
};

class RadioButton : public ComponentBase {
	char name[17];
	bool isSelect;
public:
	~RadioButton() = default;
	void showDialog() override;
	ComponentBase* clone() override;
	void flip();
	bool isOn();

};

class TextBox : public ComponentBase {
	std::string context;
public:
	~TextBox() = default;
	void showDialog() override;
	ComponentBase* clone() override;
};

#include <vector>
class Collection {
	std::vector<ComponentBase*> collection;
	void copy(const Collection&);
	void free();
public:
	Collection() = default;
	~Collection();
	Collection(const Collection&);
	Collection& operator=(const Collection&);
	void addLabel();
	void addRadioButton();
	void addTextBox();

};
#endif // !_COMPONENT_HPP
