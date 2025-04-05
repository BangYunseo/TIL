package com.yunseo_33.ch00_firstapplication

import java.util.*;

fun main(){
    val data1: Array<Int> = Array(3, {0})
    data1[0] = 10
    data1[1] = 20
    data1.set(2, 30)
    // 배열 2번째 데이터를 30으로 설정

    println("""
    array size : ${data1.size}
    array data : ${data1[0]}, ${data1[1]}, ${data1.get(2)}
    """)
    // get() 함수를 통한 2번째 데이터 가져오기
}