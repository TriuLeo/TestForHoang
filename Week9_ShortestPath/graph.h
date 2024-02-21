#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

//con cho LMT

struct Node
{
    string label;
    vector<pair<Node*, int>> connectedNode;
    int distance; // Khoảng cách tạm thời
    Node* previousNode; // Đỉnh trước đó trong đường đi ngắn nhất
};

struct Graph
{
    vector<Node*> nodeList;

    void printGraph() {
        for (Node* p : nodeList) {
            cout << p->label << " ";
        }
    }

    void connectNode(Node* a, Node* b, int weight)
    {
        a->connectedNode.push_back({ b, weight });
        //b->connectedNode.push_back({a, weight}); // Nếu đồ thị vô hướng, hãy bỏ comment dòng này
    }

    //void dijkstra(Node* A)
    //{
    //    // Khởi tạo khoảng cách tạm thời của tất cả đỉnh
    //    for (Node* node : nodeList) {
    //        node->distance = INT_MAX; // Sử dụng giá trị vô cùng làm giá trị ban đầu
    //        node->previousNode = nullptr;
    //    }

    //    A->distance = 0; // Khoảng cách từ A đến chính nó là 0

    //    int step = 0; // Đếm bước trong thuật toán

    //    while (true) {
    //        cout << "Step " << step << ":\n";
    //        // In ra bảng khoảng cách tạm thời và đỉnh trước đó
    //        for (Node* node : nodeList) {
    //            cout << node->label << ": " << node->distance;
    //            if (node->previousNode != nullptr) {
    //                cout << " (via " << node->previousNode->label << ")";
    //            }
    //            cout << endl;
    //        }

    //        // Tìm đỉnh có khoảng cách tạm thời nhỏ nhất chưa được xét
    //        Node* current = nullptr;
    //        for (Node* node : nodeList) {
    //            if (node->distance < INT_MAX && (current == nullptr || node->distance < current->distance)) {
    //                current = node;
    //            }
    //        }

    //        if (current == nullptr) {
    //            break; // Tất cả đỉnh đã được xét
    //        }

    //        // Duyệt qua các đỉnh kề của current
    //        for (pair<Node*, int>& neighbor : current->connectedNode) {
    //            Node* nextNode = neighbor.first;
    //            int edgeWeight = neighbor.second;

    //            // Kiểm tra xem có cách tốt hơn để đến nextNode không
    //            if (current->distance + edgeWeight < nextNode->distance) {
    //                nextNode->distance = current->distance + edgeWeight;
    //                nextNode->previousNode = current;
    //            }
    //        }

    //        step++; // Tăng bước sau khi hoàn thành một bước
    //    }
    //}

    void dijkstra(Node* A)
    {
        // Khởi tạo khoảng cách tạm thời của tất cả đỉnh
        for (Node* node : nodeList) {
            node->distance = INT_MAX; // Sử dụng giá trị vô cùng làm giá trị ban đầu
        }

        A->distance = 0; // Khoảng cách từ A đến chính nó là 0

        // Khởi tạo hàng đợi ưu tiên (min heap)
        priority_queue<pair<int, Node*>> pq;
        pq.push({ 0, A }); // Đưa đỉnh A vào hàng đợi

        while (!pq.empty()) {
            Node* current = pq.top().second;
            int currentDistance = -pq.top().first;
            pq.pop();

            // Duyệt qua các đỉnh kề của current
            for (pair<Node*, int>& neighbor : current->connectedNode) {
                Node* nextNode = neighbor.first;
                int edgeWeight = neighbor.second;

                // Kiểm tra xem có cách tốt hơn để đến nextNode không
                if (currentDistance + edgeWeight < nextNode->distance) {
                    nextNode->distance = currentDistance + edgeWeight;
                    pq.push({ -nextNode->distance, nextNode });
                }
            }
        }
    }
};