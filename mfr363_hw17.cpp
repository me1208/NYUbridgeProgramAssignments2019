#include <iostream>
#include <ctime>
#include <queue>

using namespace std;

template<class T>
class RBT;

template <class T>
class RBTNode {
	RBTNode<T> *parent, *left, *right;
	T data;
	char color;

public:
	friend class RBT<T>;
	RBTNode(const T& newdata = T()) : data(newdata), color('r'), parent(nullptr), left(nullptr), right(nullptr) {}
};

template<class T>
class RBT {

	RBTNode<T> *root;
	int size;
	RBTNode<T>* recursiveCopy(RBTNode<T>* toCopy);
	RBTNode<T>* insert(RBTNode<T> *root, RBTNode<T> *pointer);
	void configTree(RBTNode<T> *&root, RBTNode<T> *&pointer);
	void branchEval(RBTNode<T>* & point, RBTNode<T>* &uncle, RBTNode<T>* &parent, RBTNode<T>* &grandparent, string side);
	void singleCR(RBTNode<T> *& point);
	void singleCCR(RBTNode<T>*& point);
	void clear(RBTNode<T>* pointer);

public:
	//memory on the heap so.... here comes the big 3!
	RBT() : root(nullptr) {}
	virtual ~RBT(){ clear(); }
	RBT& operator=(const RBT<T>& rhs);
	void insert(const T &nodeData);
	void printLevelOrder();
	bool isEmpty()const{ return root == nullptr; }
	int getSize()const { return size; }
	void remove(const T& toRemove){
		RBTNode<T>* item = find(toRemove);
		if (item != nullptr)
			remove(item);
	}
	void remove(RBTNode<T>*);
	RBTNode<T>* find(const T& toFind) const;
	void clear(){ while (!isEmpty()) remove(root); }
};

template <class T>
void RBT<T>::clear(RBTNode<T>* pointer) {
	if (pointer) {
		clear(pointer->left);
		clear(pointer->right);
		delete pointer;
	}
}

template <class T>
void RBT<T>::singleCR(RBTNode<T>* &point) {
	RBTNode<T>* grandparent = point;
	RBTNode<T>* parent = point->left;
	parent->parent = grandparent->parent;
	grandparent->parent = parent;
	grandparent->left = parent->right;
	parent->right = grandparent;
	if (grandparent->left != nullptr) //if we now have a left child, update its parent pointer
		grandparent->left->parent = grandparent;
	if (parent->parent == nullptr)//if we were the root, update the root!
		root = parent;
	else if (parent->parent->left == grandparent)
		parent->parent->left = parent;
	else
		parent->parent->right = parent;
}

template <class T>
void RBT<T>::singleCCR(RBTNode<T>* &point) {
	RBTNode<T>* grandparent = point;
	RBTNode<T>* parent = point->right;
	parent->parent = grandparent->parent;
	grandparent->parent = parent;
	grandparent->right = parent->left;
	parent->left = grandparent;
	if (grandparent->right != nullptr) //if we now have a right child, update its parent pointer
		grandparent->right->parent = grandparent;
	if (parent->parent == nullptr)//if we were the root, update the root!
		root = parent;
	else if (parent->parent->right == grandparent)
		parent->parent->right = parent;
	else
		parent->parent->left = parent;
}

template <class T>
RBTNode<T>* RBT<T>::recursiveCopy(RBTNode<T>* toCopy){
	if (toCopy == nullptr)
		return nullptr;
	RBTNode<T>* temp = new RBTNode<T>(toCopy->data, nullptr, recursiveCopy(toCopy->left), recursiveCopy(toCopy->right));
	if (temp->left != nullptr)
		temp->left->parent = temp;
	if (temp->right != nullptr)
		temp->right->parent = temp;
	return temp;
}

template <class T>
RBT<T>& RBT<T>::operator=(const RBT<T>& rhs){
	if (this == &rhs)
		return *this;
	clear();
	root = recursiveCopy(rhs.root);
	size = rhs.size;
	return *this;
}

template <class T>
void RBT<T>::remove(RBTNode<T>* toRemove){
	if (root == nullptr)
		return; //Remove from an empty tree????
	if (toRemove->left == nullptr && toRemove->right == nullptr){ //leaf node case
		if (toRemove->parent == nullptr){
			root = nullptr;
		}
		else if (toRemove == toRemove->parent->left) //left child!
			toRemove->parent->left = nullptr; //fix the parent's pointer!
		else
			toRemove->parent->right = nullptr;
		delete toRemove;
		size--;
	}
	else if (toRemove->right == nullptr){ //has one (left) child
		if (toRemove->parent == nullptr){
			root = toRemove->left;
			root->parent = nullptr;
		}
		else if (toRemove == toRemove->parent->left){ //we're the left child of our parent
			toRemove->parent->left = toRemove->left;
			toRemove->left->parent = toRemove->parent;
		}
		else{
			toRemove->parent->right = toRemove->left;
			toRemove->left->parent = toRemove->parent;
		}
		delete toRemove;
		size--;
	}
	else if (toRemove->left == nullptr){ //has one right child, almost same solution as left child only
		if (toRemove->parent == nullptr){
			root = toRemove->right;
			root->parent = nullptr;
		}
		else if (toRemove == toRemove->parent->left){ //we're the left child of our parent
			toRemove->parent->left = toRemove->right;
			toRemove->right->parent = toRemove->parent;
		}
		else{
			toRemove->parent->right = toRemove->right;
			toRemove->right->parent = toRemove->parent;
		}
		delete toRemove;
		size--;
	}
	else{ //sigh... two children!
		RBTNode<T>* temp = toRemove->right;
		while (temp->left != nullptr)
			temp = temp->left;
		toRemove->data = temp->data;
		remove(temp);
	}

}

template <class T>
RBTNode<T>* RBT<T>::find(const T& toFind) const{
	RBTNode<T>* temp = root;
	while (temp != nullptr && temp->data != toFind){
		if (toFind < temp->data)
			temp = temp->left;
		else
			temp = temp->right;
	}
	return temp;
}

template <class T>
void RBT<T>::branchEval(RBTNode<T>* &point, RBTNode<T>* &uncle, RBTNode<T>* &parent, RBTNode<T>* &grandparent, string side) {

	if (uncle != nullptr && uncle->color == 'r') {
		grandparent->color == 'r';
		parent->color = 'b';
		uncle->color = 'b';
		point = grandparent;
	} else {
		if (side == "left"){
			if (point == parent->left) {
				singleCR(parent);
				point = parent;
				parent = point->parent;
			}
			singleCCR(grandparent);
		} else {
			if (point == parent->right) {
				singleCCR(parent);
				point = parent;
				parent = point->parent;
			}
			singleCR(grandparent);
		}

		swap(parent->color, grandparent->color);
		point = parent;
	}
}

template <class T>
void RBT<T>::configTree(RBTNode<T>* &root, RBTNode<T>* &point) {
	RBTNode<T> *parent = nullptr;
	RBTNode<T> *grandparent = nullptr;

	while ((point != root) && (point->color != 'b') && (point->parent->color == 'r')) {
		parent = point->parent;
		grandparent = point->parent->parent;

		if (parent == grandparent->left) {
			RBTNode<T>*  uncle = grandparent->right;
			branchEval(point, uncle, parent, grandparent, "right");
		}
		else {
			RBTNode<T>* uncle = grandparent->left;
			branchEval(point, uncle, parent, grandparent, "left");
		}
	}

	root->color = 'b';
}

template<class T>
RBTNode<T>* RBT<T>::insert(RBTNode<T>* root, RBTNode<T>* pointer){
	if (root == nullptr) {
		return pointer;
	} else if (pointer->data < root->data) {
		root->left = insert(root->left, pointer);
		root->left->parent = root;
		return root;
	}
	else if (pointer->data > root->data) {
		root->right = insert(root->right, pointer);
		root->right->parent = root;
		return root;
	}
	return root;
}

template <class T>
void RBT<T>::insert(const T &nodeData) {
	RBTNode<T> *node = new RBTNode<T>(nodeData);
	root = insert(root, node);
	configTree(root, node);
}

template <class T>
void RBT<T>::printLevelOrder(){
	queue<RBTNode<T>*> q;
	q.push(root);
	while(!q.empty()) {
		RBTNode<T>* temp = q.front();
		q.pop();
		cout << temp->data << "\t(" << temp->color << ")" << endl;

		if (temp->left != nullptr) {
			q.push(temp->left);
		}
		if (temp->right != nullptr) {
			q.push(temp->right);
		}
	}
}

int main()
{
	RBT<int> b;
	srand(time(NULL));
	for (int i = 0; i < 25; i++){
		int val = rand() % 1000;
		b.insert(val);
	}

	cout << "Red Black Tree displayed via Level Order Traversal" << endl;
	b.printLevelOrder();

	return 0;
}