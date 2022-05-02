# Pangolin-examples
## 简介

Pangolin 是一套轻量级、跨平台的便携实用程序库，用于3D、数字或基于视频的程序和算法的原型制作。

GitHub 地址：https://github.com/stevenlovegrove/Pangolin

## 安装

```bash
# 安装依赖
sudo apt-get install libglew-dev

# 下载源码
git clone https://github.com/stevenlovegrove/Pangolin.git

# 编译
cd [path-to-pangolin（Pangolin路径）] # 打开解压后的Pangolin文件夹
mkdir build
cd build
cmake ..
make 	#（或者用cmake --build .）
sudo make install 	# (.h默认安装到了/usr/local/include）
```

## 测试



## examples

Pangolin 提供了一些例子，本文将从这些例子出发，学习 Pangolin。