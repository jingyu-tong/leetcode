package TwoSum

import (
	"reflect"
	"testing"
)

func TestTwoSum(t *testing.T) {
	nums := []int{2,7,11,15}
	target := 9
	out1 := []int{0, 1}
	out2 := []int{1, 0}
	if !reflect.DeepEqual(out1, twoSum(nums, target)) &&
		!reflect.DeepEqual(out2, twoSum(nums, target)) {
		t.Errorf("twoSum test fail")
	}
}