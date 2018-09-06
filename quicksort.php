<?php

//交换数组中元素
function temp(&$arr, $i, $j)
{
    $temp = $arr[$i];
    $arr[$i] = $arr[$j];
    $arr[$j] = $temp;
}

 
function piviotion(&$arr, $low, $high)
{
    $piviokey = $arr[$low];

    while($low < $high)
    {
        while($low < $high && $arr[$high] >= $piviokey)
        {
            $high--;
        }
        temp($arr, $low, $high);

        while($low < $high && $arr[$low] <= $piviokey)
        {
            $low++;
        }

        temp($arr, $low, $high);

    }

    return $low;
}

//递归快速排序 
function quicksort(&$arr, $low, $high)
{
    if ($low < $high)
    {
        //选取 数组关键字，并排序，大的右边，小的左，并返回关键字
        $pivio = piviotion($arr, $low, $high);

        quicksort($arr, $low, $pivio - 1);
        quicksort($arr, $pivio + 1, $high);

    }
}


$arr = array(
    1 => 3,
    2 => 2,
    3 => 1,
    4 => 7,
    5 => 6,
    6 => 9,
    7 => 4
);

quicksort($arr, 1, 7);

echo "<pre>";
print_r($arr);
