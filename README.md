# HML
Header Only Math Library - welp. I don't think that I have to explain much here.
## :spiral_notepad: Features
 - Vectors
 - Matrices
 - Matrix Transformations

## :package: Getting Started
This library is made only with header files so there is not much u have to do just:
### If you are using GIT
- - - -
1. Clone this repository and save it on your device.
2. Copy and paste HML folder with headers into your project
3. Include HeaderMath.hpp and you are done
### If you are not using GIT
- - - -
1. Download all files from this repository and save it on your device.
2. Copy and paste HML folder with headers into your project
3. Include HeaderMath.hpp and you are done

It's that simple.

## :gear: Usage
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