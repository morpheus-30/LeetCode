class Solution {
public:
    string solve(string s,int n)
    {
        if(n==1)//base case
        {
            return s;
        }
        //count contiguous occurences of characters
        int freq=1;
        char ch=s[0];
        string ans="";
        s+="#";//append because occurence of last element is pushed in else statement
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==ch)
            {
                //freq+1 till same character is coming
                freq++;
            }
            else
            {
                //different character encountered
                // push the occurence of last character along with last character
                ans+=to_string(freq)+ch;
                freq=1;//restart the count to count the other character
                ch=s[i];
            }
        }
        return solve(ans,n-1);//recursive call
    }
    string countAndSay(int n) {
        return solve("1",n);//start sequence with base case
    }
};