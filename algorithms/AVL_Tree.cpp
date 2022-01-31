#include <iostream>

using namespace std;

struct node{

    int data;
    node *left;
    node *right;

};

class AVl_TREE{
    private:
        node root;

    public:
        AVl_TREE();
        void insert(int data);


};

AVl_TREE:: AVl_TREE(){

    root.data = NULL;
    root.left = NULL;
    root.right = NULL;
}

void AVl_TREE::insert(int data){
    
}

int main(int argc, char ** argv)
{

    return 0;
}