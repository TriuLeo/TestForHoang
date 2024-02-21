#include"graph.h"

int main()
{
    Node* A = new Node({ "0" });
    Node* B = new Node({ "1" });
    Node* C = new Node({ "2" });
    Node* D = new Node({ "3" });
    Node* E = new Node({ "4" });

    Graph* h = new Graph;
    h->nodeList.push_back(A);
    h->nodeList.push_back(B);
    h->nodeList.push_back(C);
    h->nodeList.push_back(D);
    h->nodeList.push_back(E);

    h->connectNode(A, B, 2);//0->1
    h->connectNode(A, C, 5);//0->2
    h->connectNode(B, D, 7);//1->3
    h->connectNode(C, D, 3);//2->3
    h->connectNode(D, E, 5);//3->4
    h->connectNode(C, E, 12);//2->4
    h->connectNode(E, B, 2);//4->1
    h->connectNode(D, A, 3);//3->0
    h->connectNode(D, C, 2);//3->2
   
    h->dijkstra(A);

    delete A, B, C, D, E, h;
    return 0;
}