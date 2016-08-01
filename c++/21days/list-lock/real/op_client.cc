#include <cstdlib>

#include "Op.h"
void random_op();

int main()
{
	while(1)
		random_op();

}

template <typename T>
void call(Op *ops, T fnpt)
{
	auto fn  = fpa[ops->op_ctx.op];

	//auto fp = ops->op_ctx.rfn;
//	optr->op_ctx.fptrs.(*fp) = fnpt;
///	(optr->*op_ctx.fpt.rfn) (ops->op_ctx.path);
	(ops->*fn) (ops->op_ctx.path);
	//ops->


}

void random_op()
{
	int opr = (int) rand()%(sizeof(Ops)-1);
	Op *ptr = new Op;
	cout << "opr="<<opr<<"\n";

	switch(opr)
	{
		case READ:
				 {
				 ptr->op_ctx.op=OPEN;
				 ptr->op_ctx.path="/dev/read";
//				 ptr->op_ctx.fpt.rfn=&Op::read_op;
				 call(ptr, ptr->op_ctx.fpt.rfn);
				 }
				 break;

		default:
				break;
	}
	delete ptr;
}
