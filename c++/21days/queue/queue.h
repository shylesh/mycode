#include <iostream>
#include <deque>
#include <stdint.h>
#include <stdlib.h>

#define Q_EMPTY -1

using namespace std;


class myqueue {

        private:
                deque<int>      myq;

        public:
                uint32_t        q_push();
                int32_t         q_pop();
                int             q_display();
};

uint32_t myqueue::q_push()
{
        uint32_t        input;

        cout << "Enter the  element to insert:-";
        cin >> input;
        myq.push_back (input);

        return 0;
}

int32_t myqueue::q_pop()
{
        int32_t ret;
        int32_t& ele = ret;

        if (myq.empty())
                return Q_EMPTY;
        ele = myq.front();
        myq.pop_front();
        return ret;
}

int     myqueue::q_display()
{
        if (myq.empty())
                return Q_EMPTY;

        for (deque<int>::iterator it=myq.begin(); it != myq.end(); it++)
                cout << *it << "\n";
        return 0;
}


