#include <iostream>

using namespace std;

typedef struct node {
    int value;
    node* parent;
    node* leftchild;
    node* rightchild;
}tsNode;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

tsNode* findMinAncestor(tsNode* node1, tsNode* node2) {
    //���ҳ�node1����������
    tsNode* sameAncestor = NULL;
    vector<tsNode*> ancestor1;
    tsNode* p1 = node1;
    tsNode* p2 = node2;
    while(p1->parent != NULL) {
        ancestor1.push_back(p1->parent);
        p1 = p1->parent;
    }

    while(p2->parent != NULL) {
        //��p1�����ȱȽ�,�ҵ��ǰ��
         int i = 0;
         for(i = 0; i < ancestor1.size(); i++) {
            if(p2->parent == ancestor1[i]) {
                sameAncestor = p2->parent;
            }
         }
    }
    return sameAncestor;
}

//�ж�node1�ڵ��Ƿ�Ϊn2�ڵ������
int isFather(tsNode* node1, tsNode* node2) {
    int IS = false;
    tsNode* p2 = node2;
    while(p2->parent != NULL) {
        if(p2->parent == node1) {
            IS = true;
        }
        p2 = p2->parent;
    }
    return IS;
}

tsNode* findMinAncestor2(tsNode* node1, tsNode* node2) {
    tsNode* p1 = node1;
    while(p1->parent != NULL) {
        if(isFather(p1->parent, node2)) {
            return p1->parent;
        }
    }
    return NULL;
}
