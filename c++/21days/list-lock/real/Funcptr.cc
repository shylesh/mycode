#include <cstdlib>

using namespace std;

class myclass;
enum ops  { OPEN, READ, WRITE};

typedef  int (myclass::*fn_ptr)(string, string);

class myclass {
	public:
		string	path;
		string op;
		//int (myclass::*f_ptr)(string, string);
		fn_ptr fp;


	public:
		int open(string, string);
		int read(string, string);
		int write(string,string);
};

int myclass:: open(string op, string name)

{
	cout << "op=" << op<< "=" << "name: " << name << "\n";
}

int myclass::read(string op, string name)
{
	cout << "op=" << op << "=" << "name:" << name << "\n";
}

int myclass::write(string op, string name)
{
	cout <<"op=" << op << "="<< "name:" << name << "\n";
}

void random_op(void);

fn_ptr fptr_read = &myclass::read;
fn_ptr fptr_write = &myclass::write;
fn_ptr fptr_open = &myclass::open;

int main()
{
	myclass mc ;
	mc.path = "/dev/urandom";
	mc.path += "/";
	mc.path += "LOL";

//	string path="/dev/urandom";
//	fn_ptr func= &myclass::print;
	while(1)
		random_op();

//	(mc.*func)(mc.path);
}

template <typename T>
void call (myclass *mc, T fpt)
{
	//T fptr;
//	mc->fp = fptr;
	auto fptr = mc->fp;
	(mc->*fptr) (mc->op, mc->path);
}



/*void call (myclass *mc, )
{
	myclass loc ;
//	fn_ptr fptr = &myclass::read;
	fn_ptr fpt;
	loc.op = mc->op;
	loc.path = mc->path;
	loc.fp = mc->fp;
	(loc.*fp) (loc.op, loc.path);

//	fptr = mc->f_ptr;
//	(mc->*(*fp))(mc->op, mc->path);
}*/

void random_op()
{
	int ops = (int) rand() % (sizeof(ops) -1) ;
	myclass * mc = new myclass;
	cout << "ops = " << ops;

	switch(ops)
	{
	case OPEN:
		{
		//fn_ptr func = &myclass::open;
		mc->op ="open";
		mc->path = "/dev/open";
//		mc->open(mc->op, mc->path);
		mc->fp = fptr_open;
		//call(mc, fptr_open);
		call(mc, mc->fp);
		}
		break;

	case READ:
		{
		mc->op="read";
		mc->path = "/dev/read";
		//mc->read(mc->op, mc->path);
	//	call(mc, fptr_read);
		mc->fp = fptr_read;
		call(mc, mc->fp);
		}
		break;

	case WRITE:
		{
		mc->op="write";
		mc->path = "/dev/write";
//		call(mc, fptr_write);
		mc->fp = fptr_write;
		call(mc, mc->fp);
		}
	}
	delete mc;
}

