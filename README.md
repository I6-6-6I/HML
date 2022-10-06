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
    HML::Vector2<> x(5,7);
    HML::Vector2<> y(4,5);
    HML::Vector2<int> z(7, 8);
    HML::Mat2x3<> mat3(5, 6, 7, 8, 9, 0);
    HML::Mat2x2<> mat(mat3);
    HML::Mat2x2<int> mat2(y, z);
    z = x + y;
    z++;

    std::cout << "Hello World!\n";
    std::cout << mat[0].x << std::endl << mat[0].y << std::endl << mat[1].x << std::endl << mat[1].y << std::endl;
    mat--;
    std::cout << "++\n";
    std::cout << mat[0].x << std::endl << mat[0].y << std::endl << mat[1].x << std::endl << mat[1].y << std::endl;
}
```

## License
[MIT](https://choosealicense.com/licenses/mit/)