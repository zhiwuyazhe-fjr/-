#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<cstdio>
using namespace std;
int main()
{
    /*
        Part1：这部分不用大家写
        主要是把读入的东西切分成一堆字符串。
     */
    // 读入字符串
    string a;
    getline(cin,a); // a不包括最后的回车
    
    // 拆分字符串
    int pre = 0; //记录当前尚未处理的数字部分的起始位置
    vector<string> inputs; // 这就是一个顺序表
    for (int i=0;i<a.length();i++)
    {
        if (a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'||a[i]=='('||a[i]==')')
        {
            if (pre!=i)
                inputs.push_back(a.substr(pre,i-pre)); //substr(起始位置, 长度)：从字符串中截取一段子串
            inputs.push_back(a.substr(i,1));
            pre = i+1;
        }
    }
    if (pre<a.length())
        inputs.push_back(a.substr(pre,a.length()-pre));

    // 输出拆分的字符串，可以帮你调试。
    /*
    for (int i=0;i<inputs.size();i++)
        cout<<inputs[i]<<endl;
    下方故意留白，用来在视觉上区分三个part
     */
    
    


    
    


    
    
    
    
    
    /*
        Part2：需要完成！
        将表达式转为后缀表达式（逆波兰式）
     */
    stack<string> op;    // op就是操作符栈
    vector<string> res;  // res用来暂存后缀表达式的
    for (int i=0;i<inputs.size();i++)
    {
        string now=inputs[i];
        if(now!="+" && now !="-" && now !="*" && now !="/" && now !="(" && now !=")"){
            res.push_back(now);
            continue;
        }
        else{
            if(now == "("){
                op.push(now);
                continue;
            }
            else if(now == ")"){
                while(!op.empty() && op.top() != "("){
                    string temp = op.top();
                    op.pop();
                    res.push_back(temp);
                }
                op.pop();
            }
            else if(now == "*" || now == "/"){
                while(!op.empty() && (op.top() == "*" || op.top() == "/")){
                    string temp = op.top();
                    res.push_back(temp);
                    op.pop();
                }
                op.push(now);
            }
            else if(now == "+" || now == "-"){
                while(!op.empty() && op.top() != "("){
                    string temp = op.top();
                    res.push_back(temp);
                    op.pop();
                }
                op.push(now);
            }
        }
    }
    while (!op.empty()){
        res.push_back(op.top());
        op.pop();

    }

    // 输出后缀表达式，可以帮你调试。
    /*
    for (int i=0;i<res.size();i++)
        cout<<res[i]<<endl;
    下方故意留白，用来在视觉上区分三个part
     */
    
    
    
    
    
    
    
    
    
    
    
    /*
        Part3：需要完成！
        后缀表达式求值
     */
    stack<float> ans; // 这是答案栈，或者可以理解为传统表达式求值的第二个栈
    for (int i=0;i<res.size();i++)
    {
        string now=res[i];
        if (now != "+" && now != "-" && now != "*" && now != "/") {
            ans.push(stof(now));
            continue;
        }
        float a = ans.top();
        ans.pop();
        float b = ans.top();
        ans.pop();
        if (now == "+") {
            ans.push(a + b);
        }
        else if (now == "-") {
            ans.push(b - a);
        }
        else if (now == "*") {
            ans.push(a * b);
        }
        else if (now == "/") {
            ans.push(b / a);
        }
       
    }
    // 输出最终答案！
    printf("%.6f\n",ans.top());
    return 0;
}