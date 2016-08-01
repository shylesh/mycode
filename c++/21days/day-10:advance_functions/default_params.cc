#include <iostream>
#include <stdint.h>

typedef uint32_t uint;

enum BOOL {FALSE, TRUE};

using namespace std;

class Rectangle {
	public:
		Rectangle (uint height, uint width);
		~Rectangle() {};
		void Draw(uint newheight, uint newwidth, BOOL usenewval = FALSE) const;
	private:
		uint its_height;
		uint its_width;
};

Rectangle::Rectangle(uint height, uint width)
{
	its_height = height;
	its_width = width;
}

void Rectangle::Draw (uint newheight, uint newwidth, BOOL usenewval) const
{
	uint x;
	uint y;

	if (usenewval == TRUE)
	{
		x = newwidth;
		y = newheight;
	}

	else
	{
		x = its_width;
		y = its_height;
	}

	for (int i=0; i<y; i++)
	{
		for (int j=0; j<x; j++)
		{
			cout << "*" << " ";
		}
		cout << "\n";
	}
}

int main()
{
	Rectangle robj(10,10);

	cout << "with default\n";
	robj.Draw(0, 0);

	cout << "value for default\n";
	robj.Draw(50, 50, TRUE);
}
