#include <iostream>
using namespace std;

class ComponentBase {
protected:
	float x;
	float y;
public:
	virtual void showDialog() = 0;
	void move(float dx, float dy)
	{
		x += dx;
		y += dy;
	}

	virtual ~ComponentBase() = default;
};

class Label :public ComponentBase {
	char str[16];
public:
	void showDialog() override
	{
		cout << "Enter coordinates:";
		cin >> x >> y;
		cin.ignore();
		cout << "Enter text:";
		cin.getline(str, 16);
	}
};

class RadioButton :public ComponentBase {
	char rText[16];
	bool isSelected;
public:
	void showDialog() override
	{
		cout << "On/Off";
		cin >> isSelected;
		cin.ignore();
		cout << "Enter text:";
		cin.getline(rText, 16);
	}

	void flip()
	{
		isSelected = !isSelected;
	}

	bool isOn() const
	{
		return isSelected;
	}
};

class TextBox :public ComponentBase {
	char* text;

	void copy(const TextBox& current)
	{
		text = new char;
		strcpy(this->text, current.text);
	}

	void free()
	{
		delete[] text;
	}
public:
	TextBox()
	{
		text = nullptr;
	}

	TextBox(const TextBox& current)
	{
		copy(current);
	}

	TextBox& operator=(const TextBox& other)
	{
		if (this != &other)
		{
			free();
			copy(other);
		}
		return *this;
	}

	~TextBox()
	{
		free();
	}

	void showDialog() override
	{
		cout << "Enter file name or text:";
		cin.getline(text, 128);
	}
};

#include <vector>;

class Collection
{
	std::vector<ComponentBase*> collection;
	int size = collection.size();
public:
	void addLabel()
	{
		collection.push_back(new Label);
	}

	void addRadioButton()
	{
		collection.push_back(new RadioButton);
	}

	void addTextBox()
	{
		collection.push_back(new TextBox);
	}

	Collection(const vector<ComponentBase*> current)
	{
		for (size_t i = 0; i < size; i++)
		{
			collection[i] = current[i];
		}
	}

	~Collection()
	{
		for (size_t i = 0; i < size; i++)
		{
			delete collection[i];
		}
		delete[] &collection;
	}

};

int main()
{

}
