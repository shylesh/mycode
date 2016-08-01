#include <iostream>
#include <cstdlib>
#include <string>
#include <map>

using namespace std;

enum Ops
{
	READ,
	WRITE,
	OPEN,
	PARALL_WRITE,
	PARALL_READ
};


class Op;

/* Func pointer should come here , also
 * this should be visible to threads
 */
typedef int (Op::*write_fnptr)(string);
typedef int (Op::*read_fnptr)(string);
typedef int (Op::*pwrite_fnptr)(string);
typedef int (Op::*pread_fnptr)(string);

/* op_ctx structure contains the op, path
 */
struct Op_ctx
{
	int op;
	string path;
};

class Op {
	public:
		Op_ctx op_ctx;

	public:
		int write_op(string path);
		int read_op(string path);
		int parall_write(string path);
		int parall_read(string path);
		int runner(Op_ctx *op_ctx);
};







