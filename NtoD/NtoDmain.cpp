#include "macros.hpp"
#include "Node.hpp"



Epset epcloure(Epset s);
//求状态集的空闭包状态集
Epset epcloureMove(Epset s, char ch);
//求状态集在经过ch后到的空闭包状态集
bool isEnd();
//判断DFA状态是否是终态



Unknown NfaToDfa() {
	//Epset:存储结点的容器（未定）
	Epset tempSet;

	set<Epset> s;
	//子集s
	queue<int> q;
	//队列q

	tempSet.insert(NFA初态编号)；

	DFA初态.对应NFA空闭包集合 = epcloure(Epset);
	DFA初态.End = isEnd();
	DFA状态数量++；
	q.push(0);


	while (!q.empty()) {
		//出队列到I
		int n = q.front();
		q.pop();

		for （非终结符）{
			Epset temp = epcloureMove(DFA状态n.对应NFA空闭包集合， * it);

			if (!temp.empty()) {
				if (!s.count(temp)) {
					s.insert(temp);

					DFA状态n.对应NFA闭包集合 = temp;

					处理边（将终结符放到边上，转移到最后一个DFA状态（DFA状态数））;
					DFA初态.End = isEnd();

					q.push(DFA状态数);

					判断是否是终态;
					DFA状态数++;

				}

				else {

					for (int i = 0; i < DFA状态数; i++) {
						if (temp == DFA状态i.对应NFA空闭包集合) {

							处理边（将终结符放到边上，转移到第i个状态）;
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

		Epset::iterator iter;
		for (iter = NFA状态temp.对应空闭包.begin(); iter != NFA状态temp.对应空闭包.end(); iter++) {
			if (!s.count(*iter)) {
				s.insert(*iter);
				epStack.push(*iter);
			}
		}
		
	}

	return s;
}

Epset epcloureMove(Epset s, char ch) {
	Epset temp;

	Epset::iterator it;
	for (it = s.begin(); it != s.end(); it++) {
		if (对应NFA转换边为ch) {
			temp.insert(通过转换边到的状态);
		}
	}
	temp = epcloure(temp);
	return temp;
}

bool isEnd() {

}