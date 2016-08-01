#include <iostream>
#include <stdint.h>
#include <stdlib.h>

enum Ops
{
	READ,
	WRITE,
	OPEN,
	PARALL_WRITE,
	PARALL_READ
};

class Op;


class Op {
	private:
		string op;
		string path;





