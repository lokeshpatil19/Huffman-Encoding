// Name: Lokesh Patil
// Project: Huffmann Enoding

#include <bits/stdc++.h>
using namespace std;

class MinHeapNode {
    public:
	char data;

	int freq;

	MinHeapNode *left, *right;

	MinHeapNode(char data, unsigned freq)
	{
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};

struct compare {

	bool operator()(MinHeapNode* l, MinHeapNode* r)

	{
		return (l->freq > r->freq);
	}
};


void printCodes(MinHeapNode* root, string str)
{

	if (!root)
		return;

	if (root->data != '0')
		cout << root->data << ": " << str << "\n";

	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}


void HuffmanCodes(char data[], int freq[], int size)
{
	struct MinHeapNode *left, *right, *top;

	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

	for (int i = 0; i < size; ++i)
		minHeap.push(new MinHeapNode(data[i], freq[i]));

	while (minHeap.size() != 1) {

		left = minHeap.top();
		minHeap.pop();

		right = minHeap.top();
		minHeap.pop();
		top = new MinHeapNode('0', left->freq + right->freq);
		top->left = left;
		top->right = right;

		minHeap.push(top);
	}

	printCodes(minHeap.top(), "");
}

int main()
{
	char arr[] = { 'a', 'b', 'c', 'd' };
	int freq[] = { 1,2,3,4 };

	int size = sizeof(arr) / sizeof(arr[0]);

	HuffmanCodes(arr, freq, size);

}

