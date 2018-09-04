<?php

class merge
{
    function mergesort()
    {
        $arr1 = array(
            1 => 50, 2 => 10, 3 => 30,4 => 20
        );
        testf($arr1, $arr1, 1, 4);
    }
}
function testf(&$sr, &$tr1, $s, $t)
{
    $tr2 = array();
    if ($s == $t)
    {
        $tr1[$s] = $sr[$s];
    }else {
        $m = intval(($s + $t) / 2);
        testf($sr, $tr2, $s, $m);
        testf($sr, $tr2, $m + 1, $t);
        echo $s;
        echo "<br>";
        echo $m;
        echo "<br>";
        echo $t;

        var_dump($tr2);
        var_dump($tr1);
        merge($tr2,$tr1,$s,$m,$t);
    }
}
function merge(&$sr, &$tr, $i, $m, $n)
{
    for($j = $m + 1, $k = $i; $i <= $m && $j <= $n; $k++)
    {
        if ($sr[$i] < $sr[$j]) {
            $tr[$k] = $sr[$i++];
        }else {
            $tr[$k] = $sr[$j++];
        }
    }

    if ($i <= $m)
    {
        for($l = 0; $l <= $m- $i; $l++)
        {
            $tr[$k+$l] = $sr[$i + $l];
        }
    }
    if ($j <= $n)
    {
        for ($l = 0; $l <= $n - $j;$l++)
        {
            $tr[$k + $l] = $sr[$j + $l];
        }
    }
}
