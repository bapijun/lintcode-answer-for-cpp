class Queue {
public:
	stack<int> stack1;
	stack<int> stack2;

	Queue() {
		// do intialization if necessary
	}

	void push(int element) {
		stack1.push(element);
	}

	int pop() {
		if(stack2.empty()) {
			if(!stack1.empty()) {
				while(!stack1.empty()) {//put the ele in stack1 into stack2
					int tem = stack1.top();
					stack1.pop();
					stack2.push(tem);
				}

				int Top = stack2.top();
				stack2.pop();
				return Top;
			}
			//else do nothing
		}
		else {//stack2 is not empty
			int Top = stack2.top();
			stack2.pop();
			return Top;
		}
	}

	int top() {
		if(stack2.empty()) {
			if(!stack1.empty()) {
				while(!stack1.empty()) {//put the ele in stack1 into stack2
					int tem = stack1.top();
					stack1.pop();
					stack2.push(tem);
				}
				int Top = stack2.top();
				return Top;
			}
			//else do nothing
		}
		else {//stack2 is not empty
			int Top = stack2.top();
			return Top;
		}
	}
};
