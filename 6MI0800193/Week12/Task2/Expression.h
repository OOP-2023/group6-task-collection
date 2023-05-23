#ifndef _EXPR
#define _EXPR
#include "Node.h"
class Expr : public Node
{
protected:
	Node* lhs;
	Node* rhs;
public:
	Expr(Node* l, Node* r) : lhs(l), rhs(r) {};
};

#endif // !_EXPR
