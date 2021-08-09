#include <iostream>
#include "map/Qlist.h"
#include "map/unidirectLink.h"
#include "map/staticLink.h"
#include "map/abstractLink.h"
#include "map/circularLink.h"
#include "map/Queue.h"
#include "map/MutualLink.h"
#include "map/generalStack.h"
#include "map/chainStack.h"
#include "map/circularQueue.h"
#include "test/Qnode.h"

int main() {
//    double ae = 80.0;
//    Qlist<double> ql(25);
//    ql.InitList(15);
//    ql.ListInsert(ae);
//    ql.ListInsert(ae);
//    ql.ListInsert(ae);
//    ql.ListInsert(ae);
//    ql.ListInsert(ae);
//    ql.ListInsert(1, 20);
//    ql.ListInsert(ae);
//    ql.ListInsert(ae);
//    ql.ListInsert(ae);
//    ql.ListInsert(ae);
//    std::cout << ql << std::endl;
//
//    unidirectLink<int> link(1, true);
//    link.insert(1,12);
//    link.insert(1,16);
//    link.insert(128);
//    link.insert(18, true);
//    link.insert(2,23);
//    link.LinkDelete(20);
//    int index = link.FindData(12);
//    int data = link.GetData(3);
//    link.LinkClear();
//
//    std::cout << data << std::endl;
//    std::cout << index << std::endl;
//    std::cout << link << std::endl;
//
//    staticLink<int> sl(15);
//    sl.InitLink();
//    sl.InsertElem(27);
//    sl.InsertElem(37);
//    sl.InsertElem(1, 17);
//    sl.InsertElem(1, 89);
//    sl.InsertElem(2, 127);
//    sl.InsertElem(1, 15);//data: [15, 89, 127, 17, 27, 37]
//    sl.DeleteElem(2);
//    sl.InsertElem(36);
//    sl.clear();
//    int data_1 = sl.getData(2);
//    std::cout << sl << data_1 << std::endl;
//
//    cricularLink<int> cl(93);
//    cl.linkInsert(1, 621);
//    cl.linkInsert(82);
//    std::cout << cl;
//    cl.magicianQuestion();
//    std::cout << cl;
//    cl.AnotherQuestion();


//    MutualLink<int> ml(1);
//    ml.insert(1);
//    ml.insert(2);
//    ml.insert(4);
//    ml.insert(2, 98);
//    std::cout << ml;

//    generalStrack<std::string> gs(2);
//    gs.push("Hello");
//    gs.push("world! ");
//    gs.push("hei ");
//    gs.push("i love u");
//    gs.push("BTW, ");
//    auto a = gs.pop();
//    auto b = gs.pop();
//    std::cout << gs.pop() << gs.pop();
//    std::cout << a;
//    std::cout << b;
//    gs.clear();
//    gs.del_all();
//    generalStrack<int> gs_int(4);
//    gs_int.push(1);
//    gs_int.push(1);
//    gs_int.push(1);
//    gs_int.push(1);
//    gs_int.push(1);
//    std::cout << gs_int.pop() << gs_int.pop() << gs_int.pop() << gs_int.pop();

//    int rear_data = gs_int.baseConversion(2,16);
//    std::cout << rear_data;
//    gs_int.del_all();

//    chainStrack<int> chain;
//    chain.push(1);
//    chain.push(2);
//    chain.push(3);
//    std::cout << chain.pop() << chain.pop() << chain.pop();
//    chain.push(1);
//    chain.push(2);
//    chain.push(3);
//    chain.clear();

//    chainStrack<char> cs_2;
//    cs_2.toRepolish();
//    chainStrack<double> cs_1;
//    std::cout << cs_1.repolishExpression();

//    Queue* qu;
//    qu = init(qu);
//    push(qu,1);
//    push(qu,2);
//    push(qu,3);
//    push(qu,4);
//    std::cout << *qu;
//    int a[3];
//    for (int i : a) std::cout << pop(qu) << std::endl;
//    std::cout << *qu;
//    delete_all(qu);
//    std::cout << *qu;

//    circularQueue<int> cq(5);
//    cq.push(1);
//    cq.push(2);
//    cq.push(2);
//    cq.push(2);
//    cq.push(1);
//    cq.push(2);
//    std::cout << cq.pop() << cq.pop();
//    cq.push(3);
//    cq.push(2);
//    int k[5];
//    for (int i : k) std::cout << cq.pop();
//    cq.push(1);
//    cq.push(6);
//    std::cout << cq.pop() << cq.pop();


//    LinkQ queue;
//    InitQ(queue);
//    InQ(queue,66);
//    InQ(queue, 123);
//    InQ(queue, 4444);
//    //OutQ(front);
//    //OutQ(front);
//    output(queue);
//    output(queue);
//    output(queue);


    return 0;
}
