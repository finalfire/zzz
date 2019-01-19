fn palindrome_2(a: &str) -> bool {
    let len = a.len();
    let hlen =
        if len % 2 == 0 { 
            a.len() / 2
        } else {
            (a.len() / 2) + 1
        };

    let v: Vec<char> = a.chars().collect();

    for left in 0..hlen {
        let right = len - 1 - left;
        if v[left] != v[right] {
            return false;
        }
    }
    
    return true;
}

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
    assert!(palindrome_2(a));
}