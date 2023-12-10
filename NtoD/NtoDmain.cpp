Epset epcloure(Epset s);
//求状态集的空闭包状态集
Epset epcloureMove(Epset s, char ch);
//求状态集在经过ch后到的空闭包状态集



Unknown NfaToDfa() {
	//Epset:存储结点的容器（未定）
	Epset tempSet;

	set s;
	//子集s
	queue q;
	//队列q

	tempSet.insert(NFA初态)；

	DFA初态 = epcloure(Epset);
	//算起始状态空闭包给I0
	DFA状态数量自加；
	q.push(0);
	//空闭包进入s和q


	while (!q.empty()) {
		//出队列到I
		int n = q.front();
		q.pop();

		for （非终结符）{
			Epset temp = epcloureMove(n对应DFA状态集， * it);
			//temp_s = I读ch后的空闭包

			if (!temp.empty()) {
				if (!s.count(temp)) {
					s.insert(temp);
					q.push(DFA状态数);

					判断是否是终态;
					DFA状态数自加;

				}

				else {

					for (int i = 0; i < DFA状态数; i++) {
						if (temp == i对应的DFA状态) {
							//为当前I新建一条Edege；
							break;
						}
					}

				}

			}

		}
	}

}



Epset epcloure(Epset s) {
	stack<int> epStack;

	Epset::iterator it;
	for (it = s.begin(); it != s.end(); it++) {
		epStack.push(*it);
	}

	while (!epStack.empty()) {
		int temp = epStack.top();
		epStack.pop();

		//遍历temp通过空能到状态集
		//若当前未出现则加入集合并压入栈中
		
	}

	return s;
}

Epset epcloureMove(Epset s, char ch) {
	Epset temp;

	Epset::iterator it;
	for (it = s.begin(); it != s.end(); it++) {
		if (对应边为ch) {
			temp.insert(通过边到的状态);
		}
	}
	temp = epcloure(temp);
	return temp;
}