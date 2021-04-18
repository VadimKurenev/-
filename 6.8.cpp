#include <iostream>
#include <string>
using namespace std;
struct Left;
struct Right;
struct LeftNext;
struct RightNext;
struct Root {
	string text;
	Left* left;
	Right* right;
	Root() : left(nullptr), right(nullptr) {}
};
struct Left {
	string text;
	LeftNext* leftNext;
	Left() : leftNext(nullptr) {}
};
struct Right {
	string text;
	RightNext* rightNext;
	Right() : rightNext(nullptr) {}
};
struct LeftNext {
	string text;
	Root* root;
	LeftNext() : root(nullptr) {}
};
struct RightNext {
	string text;
	Root* root;
	RightNext() : root(nullptr) {}
};
int main() {
	auto head = new Root;
	head->text = "Head";
	auto left = new Left;
	left->text = "Left";
	head->left = left;
	auto right = new Right;
	right->text = "Left";
	head->right = right;
	auto leftNext = new LeftNext;
	leftNext->text = "LeftNext";
	left->leftNext = leftNext;
	auto rightNext = new RightNext;
	rightNext->text = "RightNext";
	right->rightNext = rightNext;
	auto root = new Root;
	root->text = "Root";
	leftNext->root = root;
	rightNext->root = root;
}