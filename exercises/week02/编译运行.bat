@echo off
REM 一键编译当前目录所有 .cpp（用你电脑上已装的 Visual Studio 2022 编译器）
REM 用法：把本文件复制到 exercises/weekNN/ 下，双击即可

setlocal
call "D:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvars64.bat" >nul

for %%f in (*.cpp) do (
    echo [编译] %%f
    cl /nologo /EHsc /std:c++17 /utf-8 "%%f" /Fe:"%%~nf.exe"
    if errorlevel 1 (
        echo.
        echo [失败] %%f 没编译通过，先看上面报错。
        echo.
    ) else (
        echo [成功] %%~nf.exe
        echo.
    )
)

echo 全部处理完毕。按任意键退出。
pause >nul
