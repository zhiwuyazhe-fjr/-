补全RPN.cpp，完成附加题！
RPN（Reverse Polish notation，逆波兰记法），或称逆波兰式或后缀表达式。

这个程序写完运行，你可以直接输入一个表达式，然后回车，就能得到结果！
如果你想用ABCD代替数字，只需要将Part3注释掉，就是一个转换逆波兰式的程序！

测试的时候，会用一个比较大的算式来测试。
（我相信你过了in.txt里的算式就没问题）
你只需要输出最终结果即可（out.txt）。

编译：g++ RPN.cpp -o main.exe	(这个main.exe其实你想叫啥都行，不写-o xxx，windows默认出a.exe)
运行比对：main.exe < in.txt > out.txt
比对文件：out.txt ans.txt