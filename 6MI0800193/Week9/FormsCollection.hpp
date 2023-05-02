#ifndef _FORMS_COLLECTION_HPP
#define _FORMS_COLLECTION_HPP
#include <vector>
#include "ComponentBase.hpp"
#include "Label.hpp"
#include "RadioButton.hpp"
#include "TextBox.hpp"
class FormsCollection
{
private:
	std::vector<ComponentBase*> forms;
public:
	void add_label();
	void add_radio_button();
	void add_text_box();
	int get_len() const;
	const ComponentBase* get_at(int i);
	void call_show_dialog_at(size_t i);
	~FormsCollection();
	FormsCollection(const FormsCollection& other);
	FormsCollection() = default;
};

#endif // !_FORMS_COLLECTION_HPP
