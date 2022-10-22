class Solution {
public:
    
    bool Okay(vector<int>&c1,vector<int>&c2)
    {
        for(int i='A';i<='z';i++)
        {
            if(c1[i]<c2[i])return false;
        }
        return true;
    }
    
    void removeExtras(vector<int>&v1,vector<int>&v2,int &start,string &s)
    {
            while(v1[s[start]]>v2[s[start]])
            {
                v1[s[start]]--;
                start++;
            }
    }
    string minWindow(string s, string t) 
    {
        if(t.size()>s.size())return "";
        vector<int>count1(256,0),count2(256,0);
        
        int start=0;
        for(int i=0;i<t.size();i++)
        {
            count2[t[i]]++;
            count1[s[i]]++;
        }
    
        
        int minLen=INT_MAX,minStart=0;
        if(Okay(count1,count2))
        {
         return s.substr(0,t.size());
        }
        
        for(int i=t.size();i<s.size();i++)
        {
            count1[s[i]]++;
            removeExtras(count1,count2,start,s);
            if(i-start+1<minLen)
            {
                if(Okay(count1,count2))
                {
                    minStart=start;
                    minLen=i-start+1;
                }
            }
        }
        if(minLen==INT_MAX)return "";
        return s.substr(minStart,minLen);
    }
};