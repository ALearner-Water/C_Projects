# 教材代码

此目录按照教材章节保存数据结构的 C 语言实现。

## 当前内容

- `ch02_linear_list/sequence_list/`：顺序表早期练习。
- `ch02_linear_list/linked_list/`：单链表早期练习。

## 后续模块

新章节在开始学习时再创建，不提前生成大量空目录：

- `ch03_stack_queue/`
- `ch04_string_array/`
- `ch05_tree/`
- `ch06_graph/`
- `ch07_search/`
- `ch08_sort/`

## 成熟实现的建议结构

```text
module_name/
├─ module_name.h    类型和对外接口
├─ module_name.c    操作实现
├─ demo.c           最小使用示例
└─ test_module.c    边界与功能测试
```

当前单文件练习暂时保留原样，学到对应章节后再重构，避免丢失学习轨迹。

模块的接口约定、编译、测试和完成标准见 [`../docs/开发与验收指南.md`](../docs/开发与验收指南.md)。
