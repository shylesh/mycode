#include <iostream>

struct sample {
	int	a;
	char	b;
};

int main()
{
	struct sample sam;
	struct sample *s_ptr = &sam;
	struct sample*& sptr_ref = s_ptr;


	sptr_ref->a = 10;
	sptr_ref->b = 'c';

	std::cout << sptr_ref->a;
	std::cout << sptr_ref->b;
}
