fn main() {  // 1) 시작될 때 처음 호출되는 main 함수
    println!("1+...+100={}",get_sum(100));    // 2) 화면 출력  3) 함수의 호출
}

fn get_sum(n:u32) -> u32 {  // 4) 함수: 함수명, 파라미터, 리턴 타임
    let mut sum:u32 = 0;   // 5) 변수


    for i in 1..=n{    // 6) for 루프
	sum += i;
    }


    return sum;   // 7) 함수의 리턴 값
}
