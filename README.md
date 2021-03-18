This template is modified from mmorse1217's great work (https://github.com/mmorse1217/cmake-project-template).
# Table of Content
- [Introduction](#intro)
- [How to build](#how-to-build)
- [How to test](#how-to-test)

# Intro
streaming server and client for H265 encoded video.

# How to build
```
mkdir build && cd build
cmake -DBUILD_TESTING=OFF  ..
make -j4
./imageEncoder 
```

# How to Test
```
mkdir build && cd build
cmake ..
make -j4
make test
```