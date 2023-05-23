#include <iostream>
#include "Value.h"
#include "And.h"
#include "Or.h"
#include "Xor.h"
using namespace std;
int main()
{
	bool expr_test = (true & (true & false) || (true || false));

	Expr* root = new Or(
		new And(new Value(true), new And(new Value(true), new Value(false))),
		new Or(new Value(true), new Value(false)));
	
	cout << root->eval() << endl;
	cout << expr_test << endl;
}
