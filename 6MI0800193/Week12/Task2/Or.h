#ifndef _OR
#define _OR
#include "Expression.h"
class Or : public Expr
{
public:
	Or(Node* l, Node* r) : Expr(l, r) {};
	bool eval() const override
	{
		return lhs->eval() || rhs->eval();
	};
};

#endif // !_OR
