bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char> s;

    for(auto it : expression){
        if(it=='[' || it=='(' || it=='{' ){
            s.push(it);
        }else{
            if(s.empty()) return false;
          if (s.top() == '{' && it == '}'){
              s.pop();
          }else if(s.top() == '[' && it == ']'){
              s.pop();
          }else if(s.top() == '(' && it == ')'){
              s.pop();
          }else{
              return false;
          }
        }
    }


    return s.empty();
}
