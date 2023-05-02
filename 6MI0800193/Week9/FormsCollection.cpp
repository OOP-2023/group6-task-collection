#include "FormsCollection.hpp"

void FormsCollection::add_label()
{
	forms.push_back(new Label());
}

void FormsCollection::add_radio_button()
{
	forms.push_back(new RadioButton());
}

void FormsCollection::add_text_box()
{
	forms.push_back(new TextBox());
}

int FormsCollection::get_len() const
{
	return forms.size();
}

const ComponentBase* FormsCollection::get_at(int i)
{
	return forms[i];
}

void FormsCollection::call_show_dialog_at(size_t i)
{
	forms[i]->show_dialog();
}

FormsCollection::~FormsCollection()
{
	for (size_t i = 0; i < forms.size(); i++)
	{
		delete forms[i];
	}
}

FormsCollection::FormsCollection(const FormsCollection& other)
{
	for (size_t i = 0; i < other.get_len(); i++)
	{
		forms.push_back(other.forms[i]->clone());
	}
}
