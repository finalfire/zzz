use std::io::{self, Read};

fn main() {
    let mut buffer = String::new();
    let stdin = io::stdin();
    let mut handle = stdin.lock();

    handle.read_to_string(&mut buffer).expect("Can't read");

    let res: i32 = buffer.lines().map(|n| n.parse::<i32>().unwrap()).sum();
    println!("{}", res);
}