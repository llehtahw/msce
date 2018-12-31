#include "value_list.h"
int main()
{
    std::cout << value_list_to_string(value_list<2,3,3,6,6,6>()) << std::endl;

    using tp_cat = value_list_cat<value_list<2,3,3>, value_list<6,6,6>>::type;
    std::cout << value_list_to_string(tp_cat()) << std::endl;
    using tp_intersect = value_list_intersect<value_list<2,3,6>, value_list<3,6,6>>::type;
    std::cout << value_list_to_string(tp_intersect()) << std::endl;
    using tp_reverse = value_list_reverse<value_list<6,6,6,3,3,2>>::type;
    std::cout << value_list_to_string(tp_reverse()) << std::endl;
    using tp_sort = value_list_sort<value_list<6,3,6,2,6,3>>::type;
    std::cout << value_list_to_string(tp_sort()) << std::endl;
    return 0;
}
