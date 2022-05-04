#include <iostream>
#include <assert.h>

char getTshirtSizeName(int centimeters ) {
    char sizeName = '\0';
    if(centimeters  < 38) {
        sizeName = 'S';
    } else if(centimeters  > 38 && centimeters  < 42) {
        sizeName = 'M';
    } else if(cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}

void Test_TshirtSizeName()
{
    assert(getTshirtSizeName(37) == 'S');
    assert(getTshirtSizeName(40) == 'M');
    assert(getTshirtSizeName(43) == 'L');
    assert(getTshirtSizeName(42) == 'M');
    assert(getTshirtSizeName(38) == 'S');
    std::cout << "All is well (maybe!)\n";
}

int main() {
    Test_TshirtSizeName();
    return 0;
}
