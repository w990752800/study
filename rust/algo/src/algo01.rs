


# 两个有序数组合并

pub fn merge(nums1: &mut Vec<i32>(), m: i32, nums2: &mut Vec<i32>(), n: i32) {

    let mut i = m as usize;
    let mut j = n as usize;
    let mut k = i + j as usize;


    # 循环 倒叙取值 判断大小，将大的值放到 nums1的最后面
    while i > 0 && j > 0 {

        if nums1[i - 1] > nums2[j - 1] {
            nums[k - 1] = nums1[i - 1];
            i -= 1;
        } else {
            nums[k - 1] = nums2[j - 1];
            j -= 1;
        }
        k -= 1;
    }

    # 如果nums2还有值，补到nums1的前面
    while j > 0 {
        nums1[k - 1] = nums2[j - 1];
        j -= 1;
        k -= 1;
    }

}



