#include <bits/stdc++.h>

void insertIt(stack<int> &stack, int tp){
	
	if(stack.empty()){
		stack.push(tp);
		return;
	}
	
	int tp2 = stack.top();
	if(tp2<=tp){
		stack.push(tp);
		return;
    }
	else {
          stack.pop();
          insertIt(stack, tp);
          stack.push(tp2);
    }
}


void sortIt(stack<int> &stack){
	if(stack.empty()) return;
	
	int tp = stack.top();
	stack.pop();
	
	sortIt(stack);

	insertIt(stack, tp);
}
void sortStack(stack<int> &stack)
{
	// Write your code here
	
	if(stack.empty()) return;
	
	int tp = stack.top();
	stack.pop();
	
	sortIt(stack);

	insertIt(stack, tp);
}
