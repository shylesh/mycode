#include <string>

#include "Op.h"


int Op::write_op(string path)
{
	cout << "inside write_op";
}

int Op::read_op(string path)
{
	cout << "inside read_op";
	cout << "path = " << path << "\n";
}

int Op::parall_write(string path)
{
	cout << "inside parall_write";
}

int Op::parall_read(string path)
{
	cout << "inside parall_read";
}
