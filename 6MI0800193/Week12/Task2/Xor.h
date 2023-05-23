#ifndef _XOR
#define _XOR
#include "Expression.h"
class Xor : public Expr
{
public:
	Xor(Node* l, Node* r) : Expr(l, r) {};
	bool eval() const override
	{
		return (lhs->eval() || rhs->eval()) && !(lhs->eval() && rhs->eval());
	};
};

#endif // !_OR
