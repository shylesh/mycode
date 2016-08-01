#include <iostream>
#include <list>
#include <stdint.h>
#include <stdlib.h>

struct info {
	int i;
	char j;
};

class mylist {
	private:
		std::list<struct info *> ilist;
	public:
		void insert_list(struct info  *iptr);
		void rem_list(); 	//remove always front ele
		void walk();
};

void mylist::insert_list(struct info *iptr)
{
	ilist.push_back(iptr);
}

void mylist::rem_list()
{
	ilist.pop_front();
}

void mylist::walk()
{
	std::list<struct info *>::iterator it;
	for (it=ilist.begin(); it!= ilist.end(); ++it) {
		//std::cout <<*it->i << "\n" << *it->j;
		std::cout << (*it)->i;
		std::cout <<(*it)->j;
		std::cout << "\n";
	}
}
