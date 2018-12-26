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
        using tp = typename std::decay<decltype(*this)>::type;
        using ctp = typename std::add_pointer<std::add_const<tp>::type>::type;

        using this_type = decltype(this);
        static_assert(std::is_same<this_type, ctp>::value, "wtf???");
        return 233;
    }
    int get() {
        using tp = typename std::decay<decltype(*this)>::type;
        using ctp = typename std::add_pointer<std::add_const<tp>::type>::type;

        using this_type = decltype(this);
        static_assert(std::is_same<this_type, tp*>::value, "wtf???");
        return ((ctp)this)->get();
    }
} instance;

int main()
{
    XXXInterface& ins = instance;
    cout << ins.get() << endl;
    return 0;
}
