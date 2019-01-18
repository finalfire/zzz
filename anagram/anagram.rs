use std::collections::HashMap;

// Check whether a is an anagram of b in O(nlogn)
fn anagram(a: &str, b: &str) -> bool {
    if a.len() != b.len() {
        return false;
    }

    let mut sortd_a: Vec<char> = a.chars().collect();
    let mut sortd_b: Vec<char> = b.chars().collect();

    sortd_a.sort();
    sortd_b.sort();

    sortd_a == sortd_b
}

fn main() {
    let a = "hello";
    let b = "lhelo";

    assert!(anagram(a, b));
}