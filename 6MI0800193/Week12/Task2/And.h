#ifndef _AND
#define _AND
#include "Expression.h"
class And : public Expr
{
public:
	And(Node* l, Node* r) : Expr(l,r) {};

	bool eval() const override 
	{
		return lhs->eval() && rhs->eval();
	}
};

#endif