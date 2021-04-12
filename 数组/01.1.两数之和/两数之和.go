package main

import "fmt"

func twoSum(nums []int, target int) []int {
	hashTable := map[int]int{}
	for i, v := range nums {
		if p, ok := hashTable[target-v]; ok {
			return []int{p, i}
		}
		hashTable[v] = i
	}
	return nil
}

func main() {
	nums := []int{2, 7, 11, 15}
	target := 9
	result := twoSum(nums, target)
	fmt.Println(result)

}
