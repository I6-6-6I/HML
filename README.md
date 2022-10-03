# HML
Header Only Math Library - welp. I don't think that I have to explain much here.
## :package: Instalation
It's not really hard everything you need to do is just drag and drop it to your project files.
Then you can include it and it's ready to go.
## Usage
```cpp
#include <iostream>
#include "include/HeaderMath.hpp"
int main()
{
    HML::Vector2 x(5,7);
    HML::Vector2 y(4,5);
    HML::iVector2 z(7, 8);
    z = x + y;
    z++;
    std::cout << "Hello World!\n";
    std::cout << z.x << std::endl << z.y;
}
```

## License
[MIT](https://choosealicense.com/licenses/mit/)