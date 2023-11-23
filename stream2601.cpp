ifstream inputFile("test.txt");//test.cpp里面的内容可以是数字  字母  可以在不同字符中间带一些空格
    int n;
    double x;
    string s;
    inputFile >> n >> x;
    inputFile>>s;
    cout<<n<<" "<<x<<" "<<s<<endl;
    return 0;

You read in a single character with a get method.
    char ch;
    inputFile.get(ch);


char ch;
inputFile.get(ch);
if ('0' <= ch && ch <= '9') {
inputFile.unget(); /* oops - didn't want to read it *///就是可以把指针从已读位置往前推一个字符：一个这段代码里面是已经读了一个字符，判断这个字符在不在0到9里面，然后如果在的话，想把这个字符赋值给n，就得重新读它
int n;
inputFile >> n; /* read integer starting with ch */
}

