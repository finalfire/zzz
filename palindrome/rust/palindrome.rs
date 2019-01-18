fn palindrome(a: &str) -> bool {
    let len = a.len();

    if len <= 1 {
        return true;
    }

    if a[0..1] == a[len-1..len] {
        return palindrome(&a[1..len-1])
    }

    false
}

fn main() {
    let a = "aibohphobia";
    assert!(palindrome(a));
}