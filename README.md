# Pangolin-examples
## 简介

Pangolin 是一套轻量级、跨平台的便携实用程序库，基于OpenGL，用于3D、数字或基于视频的程序和算法的原型制作。

GitHub 地址：https://github.com/stevenlovegrove/Pangolin

## 安装

```bash
# 安装依赖
sudo apt-get install libglew-dev

# 下载源码
git clone https://github.com/stevenlovegrove/Pangolin.git

# 编译
cd [path-to-pangolin（Pangolin路径）] # 打开解压后的 Pangolin 文件夹
mkdir build
cd build
cmake ..
make 	#（或者用 cmake --build . ）
sudo make install 	# ( .h 默认安装到了/usr/local/include ）
```

## 测试

```bash
# 进入 Pangolin/examples/HelloPangolin 目录
cd Pangolin/examples/HelloPangolin/

# 编译
mkdir build
cd build
cmake ..
make

# 运行
./HelloPangolin		# 会显示一个立方体，表明安装成功
```

## examples

Pangolin 提供了一些例子，本文将从这些例子出发，学习 Pangolin。

### 头文件

例子中头文件都是针对不同的实现所包含的，如果不确定要包含哪个头文件，可包含如下头文件，该头文件将所有头文件都包含了：

```cpp
#include <pangolin/pangolin.h>
```

### CMakeLists.txt

另外，在 CMakeLists.txt 中，链接库时依然针对不同的实现使用了不同的库，下面给出通用的形式：

```cmake
find_package( Pangolin 0.4 REQUIRED )
include_directories( ${Pangolin_INCLUDE_DIRS} )

add_executable( demo main.cpp )
target_link_libraries( demo ${Pangolin_LIBRARIES} )
```

