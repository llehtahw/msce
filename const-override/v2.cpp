#include <iostream>
#ifdef V1
#include "v1.h"
#elif defined(V2)
#include "v2.h"
#else
#error define V1 or V2
#endif

using namespace std;
class : public XXXInterface {
public:
    int get() const {
        return 233;
    }
    int get() {
        return 233;
    }
} instance;

int main()
{
    XXXInterface& ins = instance;
    cout << ins.get() << endl;
    return 0;
}
