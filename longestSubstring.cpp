#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string str="";
        vector<string> v1;
        bool flag=true;
        for(int i=0;i<s.length();i++){  //遍历s
            for(char ch:str){  //遍历str (但好像是刚开始的时候遍历一个空的str不太好)
                if(s[i]==ch){  //如果s在str之后的字符有和str中的字符相同：
                    v1.push_back(str);//把str存在v1里面
                    str=s[i];//str重新赋值
                    flag=false;//不用执行22行代码
                    break;
                }
            }
            while(flag){//增加str中字符
                str+=s[i];
                break;
            }
            flag=true;
        }
        int longest=v1[0].length();
        for(string substr:v1){
            if(longest<substr.length()) longest=substr.length();
        }
        return longest;
    }
};
int main()
{
    Solution s;
    cout<<s.lengthOfLongestSubstring("bbbb")<<endl;
    return 0;
}