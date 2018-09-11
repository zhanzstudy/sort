<?php

function temp(&$arr, $i, $j)
{
    $temp = $arr[$i];
    $arr[$i] = $arr[$j];
    $arr[$j] = $temp;
}
//冒泡排序未改进版本
function bubblesort(&$arr, $high)
{
    for ($i = 1; $i <= $high; $i++)
    {
        for ($j = $i + 1; $j <= $high; $j++)
        {
            if ($arr[$j] < $arr[$i])
            {
                temp($arr, $i, $j); 
            }
        }
    }
}

//冒泡排序改进版本
function bubblesort2(&$arr, $high)
{
    for ($i = 1; $i <= $high; $i++)
    {
    
        for ($j = $high - 1;$j >= $i; $j-- )
        {
            if ($arr[$j + 1] < $arr[$j])
            {
                temp($arr, $j + 1, $j);
            } 
        }
    }

}

$arr = array(
    1 => 9,
    2 => 7,
    3 => 6,
    4 => 8,
    5 => 5,
    6 => 3,
    7 => 4,
    8 => 2,
    9 => 1,

);

bubblesort2($arr, 9);

echo "<pre>";

print_r($arr);
