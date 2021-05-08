package main

import (
	"fmt"
)

type ListNode struct {
	Val int
	Next *ListNode
}

func createList(nums []int) *ListNode {
	prev := new(ListNode)
	prev.Val = nums[0]
	prevHead := new(ListNode)
	prevHead = prev
	for i:=1;i<len(nums);i++ {
		temp := new(ListNode)
		temp.Val = nums[i]
		prev.Next = temp
		prev = temp
	}
	return prevHead
}

func ShowList(L *ListNode) {
	temp := L
	for temp != nil {
		fmt.Print(temp.Val," ")
		temp = temp.Next
	}
	fmt.Println()
}

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	prev := new(ListNode)
	prev.Val = -1
	prevHead := prev
	for l1!=nil&&l2!=nil {
		if l1.Val<l2.Val {
			prev.Next = l1
			l1 = l1.Next
		} else{
			prev.Next = l2
			l2 = l2.Next
		}
		prev = prev.Next
	}
	if l1!=nil {
		prev.Next = l1
	}else{
		prev.Next = l2
	}
	return prevHead.Next
}

func main() {
	nums1 := []int {1,4,9}
	nums2 := []int {2,3,5,6}
	l1 := createList(nums1)
	l2 := createList(nums2)
	l3 := mergeTwoLists(l1,l2)
	ShowList(l3)
}