# 怎么编译和运行

## 环境

你电脑上已经装了 **Visual Studio 2022 Community**（D 盘），里面自带微软的 C++ 编译器 `cl.exe`。
不用再装 MinGW 之类的东西。

## 最简单的方式

进入 `exercises/weekNN/` 目录，**双击 `编译运行.bat`**。

它会把这个目录下所有 `.cpp` 编成同名 `.exe`，并且告诉你哪个通过、哪个报错。

然后再双击生成的 `.exe` 就能跑。

## 命令行方式（推荐慢慢习惯）

打开 **开始菜单 → 搜索「x64 Native Tools Command Prompt for VS 2022」**，进入后：

```bat
cd C:\Users\qztaz\cpp-learning\exercises\week01
cl /nologo /EHsc /std:c++17 /utf-8 week01_day01.cpp
week01_day01.exe
```

参数说明：

| 参数 | 作用 |
| --- | --- |
| `/EHsc` | 开启 C++ 异常处理，不加会有一堆警告 |
| `/std:c++17` | 用 C++17 标准 |
| `/utf-8` | **必须加**，否则源码里的中文会乱码、甚至编译报错 |
| `/nologo` | 不打印版权横幅 |

## 为什么必须加 `/utf-8`

Windows 中文版默认按 GBK 编码理解源文件。你的 `.cpp` 是 UTF-8 存的，
不加这个参数，`cout << "整型"` 这种中文会直接编译失败，报 `C2001: 常量中有换行符`。

这不是你的错，是编码的事。

## 如果你想用 g++

之后如果想装 MinGW / MSYS2，把 `g++` 加进 PATH 后可以直接：

```bash
g++ -std=c++17 -Wall -finput-charset=UTF-8 -fexec-charset=GBK week01_day01.cpp -o week01_day01.exe
```

但**现在不需要**，先用 `cl` 就好。工具换来换去是最消耗时间的事。
