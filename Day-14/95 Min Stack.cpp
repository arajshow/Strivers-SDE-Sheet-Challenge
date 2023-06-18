#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.
	stack<int> s;
	int mn;
	int size;

	
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
			size = 0;
			mn = INT_MAX;
			while(!s.empty()) s.pop();
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
			// cout<<1<<endl;
			if(mn>num){
				mn = num;
			}
			size++;
			s.push(num);
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here
			// cout<<2<<endl;
			if(size==0){
				return -1;
			}

			int ret = s.top();
			if(s.top()==mn){
				s.pop();
				
				mn = find_mn(size-1);
			}else{
				s.pop();
			}
			size--;
			
			return ret;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
			// cout<<3<<endl;
			if(size==0) return -1;
			return s.top();
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
			// cout<<4<<endl;
			if(size==0) return -1;
			return mn;

		}

		int find_mn(int n){
			stack<int> temp;
			mn = INT_MAX;
			int t  = n;
			// cout<<"loop"<<endl;
			while(n--){
				mn = min(mn, s.top());
				temp.push(s.top());
				s.pop();
				
			}

			while(t--){
				s.push(temp.top());
				temp.pop();
			}

			return mn;
		}
};
