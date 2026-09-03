# 数据结构 C 语言实现

本目录使用 C17 实现常见数据结构，并保存相应的算法练习、测试和课程设计代码。

## 参考教材

- 教材：李冬梅、严蔚敏、吴伟民《数据结构（C语言版）（第3版）》
- ISBN：9787115651259
- 出版社：人民邮电出版社
- 编程语言：C17
- 练习平台：LeetCode 为主，辅以教材题、手算题和课程实验

## 项目目录

```text
textbook_code/
└─ ch02_linear_list/
   ├─ sequence_list/  顺序表练习
   └─ linked_list/    单链表练习
leetcode/             题目路线、解题记录和 C 语言模板
course_design/        第 17 周课程设计资料
tests/                跨模块测试和后续综合测试
tools/                编译运行辅助脚本
```

## 编码要求

- 编译标准：C17。
- 推荐警告选项：`-Wall -Wextra -Wpedantic`。
- 动态内存分配后检查结果，并释放所拥有的内存。
- 核心操作应覆盖正常情况和边界情况。

## 入口

- [教材代码说明](textbook_code/README.md)
- [LeetCode 练习](leetcode/README.md)
- [测试](tests/README.md)
