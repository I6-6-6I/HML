![](https://github.com/I6-6-6I/HML/blob/main/HML.png)

## :blue_book: Introduction

HML is a **Header** Only **Math Library** highly inspired by both glm and cmath.
It was made in order to make creating Vulkan and DirectX12 applications easier to do by giving ready to use mathematic functions and structs. 

## :spiral_notepad: Features
 - Common functions such as: Min, Max, Abs, Round, Ceil, Pow etc. 
 - Simple Trigonometry functions such as: Radians, Degrees, Sin, Cos etc.
 - Simple Geometry functions: Dot, Normalize, Cross
 - Vectors(1,2,3,4)
 - Matrices(2x2-4x4)
 - Quaternions
 - Matrix Transformations such as: Translate, Rotate, Scale, View.
 - Clip Space(Right Handed, Left Handed, 0 to 1 and -1 to 1)

## :gear: Usage

In HML both structs and functions allways starts by upper case letter for example:

<table>
<tr>
<th> cmath / HML </th><th> glm / HML </th>
</tr>
<tr>
<td>

| cmath | HML |
|-------|-----|
| log() | Log()|
| pow() | Pow()|
| sin() | Sin()|
| abs() | Abs()|

</td>

<td>

| glm | HML |
|-------|-----|
| vec3() | Vector3<default = float>|
| mat4() | Mat4x4<default = float>|
| qua() | Quat<default = float>|
| ortho() | Ortho_RH/LH_ZO/NO()|

</td>
</tr>
<table>

**etc.**

## :page_with_curl: Example

```cpp
#include <iostream>
#include "HML.hpp"
int main()
{
    HML::Vector3<> Position(0.0f, 0.0f, 0.0f);
    
    //Most functions have overloads for vectors
    auto the_absolute_value_number = HML::Abs(-20.0f); //returns 20.0f
    auto the_absolute_value_vector = HML::Abs(HML::Vector2<>(-11.0f, -15.0f)); //returns {11.0f, 15.0f}
    
    float width = 1920;
    float height = 1080;
    
    HML::Mat4x4<> Projection = HML::Perspective_RH_ZO(HML::Radians(45.0f), width/height, 0.1f, 100.0f);
    HML::Mat4x4<> View = HML::View_RH(Position, HML::Vector3<>(0.0f, 0.0f, 1.0f), HML::Vector3<>(0.0f, -1.0f, 0.0f));
    HML::Mat4x4<> Model = HML::Mat4x4<>(1.0f);
    
    HML::Mat4x4<> MVP = Projection * View * Model;
}
```

## License
[MIT](https://choosealicense.com/licenses/mit/)
