<?php

//希尔排序
function shellsort(&$arr, $high)
{

    $increment = $high;

    do {
        $increment = intval($increment / 3 + 1);
        for ($i = $increment + 1; $i <= $high; $i++)
        {
            if ($arr[$i] < $arr[$i - $increment])
            {
                $arr[0] = $arr[$i];

                for ($j = $i - $increment; $j > 0 && $arr[$j] > $arr[0]; $j -= $increment)
                {
                    $arr[$j + $increment] = $arr[$j];
                }

                $arr[$j + $increment] = $arr[0];

            }
        }

    }while($increment > 1);

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

shellsort($arr, 9);

echo "<pre>";
print_r($arr);
