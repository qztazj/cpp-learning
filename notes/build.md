# 怎么编译和运行

## 推荐：VS Code（已配好）

用 VS Code **打开 `cpp-learning` 这个文件夹**（不是打开单个 .cpp 文件），然后：

| 操作 | 效果 |
| --- | --- |
| `Ctrl + Alt + N` | 编译并运行当前文件（需装 Code Runner 插件） |
| `Ctrl + Shift + B` | 只编译当前文件 |
| `F5` | 带调试运行，可以打断点 |

配置都在 `.vscode/` 目录里，这个目录不进 Git（路径是本机的），换电脑需要重新配。

## 编译器在哪

用的是 Dev-C++ 自带的那套 **TDM-GCC 9.2.0**：

```
C:\Program Files (x86)\Embarcadero\Dev-Cpp\TDM-GCC-64\bin\g++.exe
```

不用另外装 MinGW，Dev-C++ 已经帮你装好了。调试器 `gdb.exe` 在同目录，版本 8.3.1。

## 手动命令行编译

```bash
"C:\Program Files (x86)\Embarcadero\Dev-Cpp\TDM-GCC-64\bin\g++.exe" -std=c++17 -Wall -fexec-charset=UTF-8 文件名.cpp -o 文件名.exe
```

| 参数 | 作用 |
| --- | --- |
| `-Wall` | 打开所有警告。**别省**，新手一半的错误它会提前告诉你 |
| `-std=c++17` | 用 C++17 标准 |
| `-fexec-charset=UTF-8` | 让程序输出的中文是 UTF-8，配合 `chcp 65001` 才不乱码 |

## 中文乱码怎么办

Windows 控制台默认用 GBK（代码页 936），而源码是 UTF-8 存的。两头对不上就乱码。

解决：运行前切换代码页。

```cmd
chcp 65001
```

VS Code 的配置里已经自动做了（`settings.json` 和 `tasks.json` 里都有 `chcp 65001 >nul &&`）。

如果你用 Dev-C++ 或 Code::Blocks，它们默认按 GBK 处理，通常反而不乱码——但**源码得用 GBK 保存**才不冲突。建议统一用 UTF-8 + `chcp 65001`，跟 Git 也一致。

## 另一个选择：Dev-C++ / Code::Blocks

打开软件 → 新建源文件 → 粘贴代码 → 按 `F11`（Dev-C++）编译运行。

零配置，缺点是调试功能弱、界面老。学基础语法够用。

## 编译产物

`.exe`、`.obj`、`.pdb` 这些都在 `.gitignore` 里，不会被提交到 GitHub。

## 之前写的另一个方案（备用）

`exercises/weekNN/编译运行.bat` 也能用，它调的是 Visual Studio 2022 的 `cl.exe`，双击就能编译整个目录。但既然 VS Code 配好了，一般用不上。
