use std::io::{self, Read};
use std::collections::HashMap;

fn main() {
    let mut buffer = String::new();
    let stdin = io::stdin();
    let mut handle = stdin.lock();

    handle.read_to_string(&mut buffer).expect("Can't read");
    
    let values: Vec<i32> = buffer.lines().map(|n| n.parse::<i32>().unwrap()).collect();

    let res: i32 = values.iter().sum();
    println!("Part 1: {}", res);


    /* 
     * For part 2 this is not the best implementation whatsoever;
     * in particular, it is possible to check the repetition by
     * playing with the arithmetic group given out by the sum of the first iteration
     * on the vector `values`. By using modular arithmetic it is possible to check whether
     * a frequency has been already seen by looking at the group in which it lies in.
     */
    let mut h: HashMap<i32,i32> = HashMap::new();
    let mut i = 0;
    let mut f = 0;
    let rep = loop {
        if !h.contains_key(&f) {
            h.insert(f, 1);
        } else {
            break f;
        }
        f += values[i];
        i = (i + 1) % values.len();
    };
    println!("Part 2: {}", rep);
}