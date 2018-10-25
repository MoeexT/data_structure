/*
 * Created by yuwancumian666 on 2018/10/25.
*/

#ifndef DATA_STRUCTURE_SEQUENCESTACK_H
#define DATA_STRUCTURE_SEQUENCESTACK_H

#define SIZE 50
#define STACK_TYPE int

class SequenceStack {
private:
    int values[SIZE];
    int top;

public:
    SequenceStack();

    bool push(STACK_TYPE x);

    int pop();

    int getTop();
};


#endif //DATA_STRUCTURE_SEQUENCESTACK_H
