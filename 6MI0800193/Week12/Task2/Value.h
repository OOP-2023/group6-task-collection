#ifndef _VAL
#define _VAL

#include "Node.h"

class Value : public Node
{
private:
	bool val;
public:
	Value(bool v) : val(v) {};
	bool eval() const override 
	{
		return val;
	}
};

#endif // !_VAL
