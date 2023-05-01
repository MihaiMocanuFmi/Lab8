#include "Set.h"
#include "SetIterator.h"

#include <cassert>
#include <string>

int main()
{
    Set<int> set1;
    set1.add(2);
    set1.add(3);

    int a = set1.iterator().getCurrent();

    assert (set1.search(a) == true);



    Set<std::string> set2;
    set2.add("Ana");
    set2.add("are");
    set2.add("mere");

    Set<float> set3;
    set3.add(1.2);
    set3.add(1.3f);
    set3.add(1);
    return 0;
}