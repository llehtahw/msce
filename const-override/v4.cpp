#include <iostream>
#ifdef V1
#include "v1.h"
#elif defined(V2)
#include "v2.h"
#else
#error define V1 or V2
#endif

using namespace std;

namespace {
    template <typename T> const T* get_const(T* p) { return p; }
    template <typename T> const T& get_const(T& p) { return p; }
}

class : public XXXInterface {
public:
    int get() const {
        return 233;
    }
    int get() {
        auto res0 = get_const(this)->get();
        auto res1 = get_const(*this).get();
        if (res0 != res1)
            abort();
        return res0;
    }
} instance;

int main()
{
    XXXInterface& ins = instance;
    cout << ins.get() << endl;
    return 0;
}
