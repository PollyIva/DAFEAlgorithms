/****************************************************************************
Дано число N < 10^4 и последовательность целых чисел из [-2^31..2^31]
длиной N. Требуется построить бинарное дерево, заданное наивным порядком
вставки. Т.е., при добавлении очередного числа K в дерево с корнем root, если
root→Key ≤ K, то узел K добавляется в правое поддерево root; иначе в левое
поддерево root. Рекурсия запрещена.
****************************************************************************/

/****************************************************************************

Задача 1_4 Выведите элементы в порядке level-order (по слоям, "в ширину").

  in    | out
  ----- | ---
  3     |
  2 1 3 | 2 1 3

  in    | out
  ----- | ---
  3     |
  1 2 3 | 1 2 3

  in    | out
  ----- | ---
  3     |
  3 1 2 | 3 1 2

  in    | out
  ----- | ---
  4     |
  3 1 4 2 | 3 1 4 2

****************************************************************************/
#include <iostream>
#include <queue>

using namespace std;

struct Node
{
   int Key;
   Node *left,*right;
};


void add(int Key,Node *&MyTree)
{

	if (NULL==MyTree)
    {
		MyTree=new Node;
		MyTree->Key=Key;
		MyTree->left=MyTree->right=NULL;
	}
    if (Key<MyTree->Key)
    {
        if (MyTree->left!=NULL) add(Key,MyTree->left);
        else
        {
            MyTree->left=new Node;
            MyTree->left->left=MyTree->left->right=NULL;
            MyTree->left->Key=Key;
        }
    }
    if (Key>MyTree->Key)
    {
        if (MyTree->right!=NULL) add(Key,MyTree->right);
        else
        {
        MyTree->right=new Node;
        MyTree->right->left=MyTree->right->right=NULL;
        MyTree->right->Key=Key;
        }
    }
}

void levelOrder(Node* root) {
    queue <Node*> q;
    if (root != nullptr) q.push(root);
    while (!q.empty())
    {
        Node* node = q.front();
        q.pop();
        cout << node->Key << ' ';
        if (node->left != nullptr)
            q.push(node->left);
        if (node->right != nullptr)
            q.push(node->right);
    }
}

int main()
{
    int n,x;
    cin >> n;
    Node* Tree = NULL;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        add(x,Tree);
    };
    levelOrder(Tree);
    return 0;
}


