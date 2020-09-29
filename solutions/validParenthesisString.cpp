class Solution {
public:
    bool checkValidString(string s) {
       stack<int> openBracket ;
        stack<int> star;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') openBracket.push(i);
            else if(s[i] == '*') star.push(i);
            else {
                if(openBracket.size()) openBracket.pop();
                else if(star.size()) star.pop();
                else return false;
            }
        }
        
        while(openBracket.size()) {
            if(star.size()) {
                
                if(star.top() > openBracket.top()) star.pop(), openBracket.pop();
                else return false;
                
            } else return false;
        }
        
        return true;
    }
};
