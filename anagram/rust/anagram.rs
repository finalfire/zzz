use std::collections::HashMap;

// O(nlogn)
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

// If a is an anagram of b, then for each symbols s in a appearing |s| times,
// b contains s exactly |s| times.
fn anagram_2(a: &str, b: &str) -> bool {
    if a.len() != b.len() {
        return false;
    }

    let mut h: HashMap<char, i32> = HashMap::new();

    for c in a.chars() {
        *h.entry(c).or_insert(0) += 1;
    }

    for c in b.chars() {
        *h.entry(c).or_insert(0) -= 1;
    }

    for v in h.values() {
        if *v != 0 {
            return false;
        }
    }

    true
}

fn main() {
    let a = "hello";
    let b = "lhelo";

    assert!(anagram(a,b));
    assert!(anagram_2(a,b));
}