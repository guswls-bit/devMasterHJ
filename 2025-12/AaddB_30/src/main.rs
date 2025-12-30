fn main() {    
    let stdin = std::io::stdin();
    let mut buf = String::new();
    stdin.read_line(&mut buf).expect("input error");

    let input:Vec<String> = buf.split(' ').map(|s| s.to_string()).collect(); //(1) (2)
    let n = input[0].trim().parse::<usize>().unwrap();  //(3)  (4)
    let k = input[1].trim().parse::<usize>().unwrap();
    println!("{}",k+n);
}
