# Qt 简易计算器

这是一个使用 **Qt 6、C++ 和 Qt Widgets** 编写的桌面简易计算器，也是我在学习 Qt 信号与槽、Lambda 表达式和界面控件时完成的练习项目。

## 功能

- 输入数字和小数点
- 支持 `+`、`-`、`*`、`/` 四则运算
- 按下 `=` 后显示计算结果
- 连续输入运算符时，用新的运算符替换前一个运算符
- 表达式错误时将显示内容重置为 `0`

## 实现方式

- 使用 `QLabel` 显示输入内容和计算结果
- 使用循环动态创建 16 个 `QPushButton`
- 使用 Lambda 表达式让多个按钮连接到统一的处理逻辑
- 使用 `QJSEngine::evaluate()` 计算输入的表达式
- 使用 CMake 管理和构建项目

## 开发环境

- Qt 6.11.2
- Qt Widgets
- Qt QML（`QJSEngine`）
- C++
- CMake
- MinGW 64-bit

## 项目文件

```text
qt-simple-calculator/
├── CMakeLists.txt   # CMake 项目配置
├── main.cpp         # 程序入口
├── widget.h         # 计算器窗口类声明
├── widget.cpp       # 界面创建和按钮处理逻辑
└── widget.ui        # Qt Designer 界面文件
```

## 运行方法

1. 使用 Qt Creator 打开 `CMakeLists.txt`。
2. 选择包含 Qt Widgets 和 Qt QML 模块的 Qt 6 构建套件。
3. 构建并运行项目。

> Windows 下建议将项目放在不含中文和特殊字符的路径中，避免部分 Qt 工具出现路径编码问题。

## 当前版本说明

这是一个学习阶段的基础版本，目前没有清除键、退格键、括号、键盘输入和历史记录等功能，后续学习更多 Qt 内容后可以继续完善。
