class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto it:s){
            switch(it){
                case '(': st.push('(');
                        break;
                case '[': st.push('[');
                        break;
                case '{': st.push('{');
                        break;
                case ')':if(st.empty() || st.top()!='(')
                         return false;
                         st.pop();
                        break;
                case ']': if(st.empty() || st.top()!='[')
                         return false;
                         st.pop();
                        break;
                case '}' : if(st.empty() || st.top()!='{')
                         return false;
                         st.pop();
                            break;
        }
    }
        return st.empty()?true:false;
    }
};