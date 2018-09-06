<?php

function temp(&$arr, $i, $j)
{
    $temp = $arr[$i];
    $arr[$i] = $arr[$j];
    $arr[$j] = $temp;
}

function pivottion(&$arr, &$low, &$high)
{
    $pivotkey = $arr[$low];
    while ($low < $high)
    {
        while($low < $high && $arr[$high] >= $pivotkey);
        {
            $high--;
        }
        //交换
        temp($arr, $low, $high);
        while($low <= $high && $arr[$low] <= $pivotkey)
        {
            $low--;
        }
        temp($arr, $low, $high);
    }
    return $low;
}

function QuickSort(&$arr , $low, $high)
{
    if ($low < $high)
    {
        $pivot = pivottion($arr, $low, $high);
        QuickSort($arr,$low, $pivot - 1);
        QuickSort($arr,$pivot + 1, $high);
    }
}
