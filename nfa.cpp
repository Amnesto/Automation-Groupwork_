#include"nfa.hpp"

typedef set<int> StateSet;

ato::Map convertNFA(map<int, map<char, StateSet>> nfaWithEpsilon) {
    ato::Map nfa;
    map<int, map<char, StateSet>> transitions = nfaWithEpsilon;
    set<int> visitedStates;
    stack<int> statesToVisit;
    // ��ȡ��ʼ״̬
    int startState = nfaWithEpsilon.begin()->first;
    nfa.startState = startState;
    // �������пմ���NFA
    statesToVisit.push(startState);
    while (!statesToVisit.empty()) {
        int currentState = statesToVisit.top();
        statesToVisit.pop();
        visitedStates.insert(currentState);
        // ��ȡ��ǰ״̬��ת��
        map<char, StateSet> currentTransitions = transitions[currentState];
        for (auto transition : currentTransitions) {
            char input = transition.first;
            StateSet destinationStates = transition.second;
            // ���ת�Ƶ�NFA
            nfa.transitions[currentState][input] = destinationStates;
            // �����пմ�ת�ƣ����������ʵ�״̬
            if (input == '\0') {
                for (int state : destinationStates) {
                    if (visitedStates.find(state) == visitedStates.end()) {
                        statesToVisit.push(state);
                    }
                }
            }
        }
    }
    // ���ý���״̬
    for (auto state : visitedStates) {
        if (transitions[state].find('\0') != transitions[state].end()) {
            nfa.acceptStates.insert(state);
        }
    }

    return nfa;
}