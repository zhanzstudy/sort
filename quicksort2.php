<?php
/**
 *快速排序优化版本
 */

//块笋插入排序
function insertsort(&$arr, $length)
{
    for ($i = 2; $i <= $length; $i++)
    {
        if ($arr[$i] < $arr[$i - 1])
        {
            $temp = $arr[$i];
            for($j = $i - 1; $temp < $arr[$j]; $j--)
            {
            
                $arr[$j + 1] = $arr[$j];
            }
            $arr[$j + 1] = $temp;
        }
    }
}

function temp(&$arr,$i, $j)
{
    $temp = $arr[$i];
    $arr[$i] = $arr[$j];

    $arr[$j] = $temp;

}

function piviotion(&$arr, $low, $high)
{
    //优化一， 三数取中选取关键字
    $mid = intval( ($low +  $high) / 2);
    if ($arr[$low] > $arr[$high])
    {
        temp($arr, $low, $high);
    }

    if ($arr[$mid] > $arr[$high])
    {
        temp($arr, $mid, $high);
    }

    if ($arr[$low] < $arr[$mid])
    {
        temp($arr, $low, $mid);
    }

    $piviokey = $arr[$low];

    while($low < $high)
    {
        while ($low < $high && $arr[$high] >= $piviokey)
        {
            $high--;  
        }
        //优化二，重新复制，不直接交换
        $arr[$low] = $arr[$high];

        //temp ($arr, $low, $high);

        while ($low < $high && $arr[$low] <= $piviokey)
        {
            $low++;

        }
        $arr[$high] = $arr[$low];
        //temp($arr, $low, $high);
    }

    $arr[$low] = $piviokey;
    return $low;
}

function quicksort(&$arr, $low, $high)
{
    //优化三， 数据少的用直接插入排序
    if ($high > 5)
    {
        //优化四， 用尾递归 代替递归
        while($low < $high)
        {
            $pivio = piviotion($arr, $low, $high); 
            quicksort($arr, $low, $pivio - 1);
            $low = $pivio + 1;
        } 
    
    }else {
        insertsort($arr, $high);
    }
}
$arr = array(
    1 => 9,
    2 => 3,
    3 => 6,
    4 => 2,
    5 => 1,
    6 => 5,
    7 => 4,
    8 => 8,
    9 => 7,
);

quicksort($arr, 1, 9);

echo "<pre>";
print_r($arr);
