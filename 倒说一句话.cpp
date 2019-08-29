牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？

分析 ：  观察之后发现  .student 是连在一起的  

我们的做法是 碰到‘空格 ’或者‘\0’就进行逆置，但值得注意的是 str.size()返回的有效下标的个数，所以我们应该控制好循环次数。最后我们应该同时考虑到进行两次反转的必要性，也就是可能是一个单词的情况，这里设置了一个count做标志
class Solution {
public:
    string ReverseSentence(string str) {
        int left=0;
        int right= 0;
        int count =0;
        while(right<=str.size())
        {
            if (str[right]==' '|| str[right]=='\0')
            {
                count=1;
                int right1 =right;
                right--;
                while(left<right)
                {
                    char tmp=str[left];
                   str[left]=str[right];
                    str[right]=tmp;
                    --right;
                    ++left;
                }
                right=right1;
                left=right+1; 
            }
                ++right;
        }
      if(count !=0)
              reverse(str.begin(),str.end());
        return str;
    }
};