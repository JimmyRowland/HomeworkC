#pragma once
namespace cs20a
{
	template <class T>
	struct ListNode
	{
		ListNode() {};
		ListNode(T t) : value(t), next(nullptr), previous(nullptr) {}

		T value;
		ListNode *next;
		ListNode *previous;
	};
}