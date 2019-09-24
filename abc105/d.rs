use std::collections::HashMap;

fn read<T: std::str::FromStr>() -> T {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).ok();
    s.trim().parse().ok().unwrap()
}
fn read_vec<T: std::str::FromStr>() -> Vec<T> {
    read::<String>().split_whitespace().map(|e| e.parse().ok().unwrap()).collect()
}

fn solve(n : i32, m : i32, a : Vec<i32>) -> i64 {
    let mut map = HashMap::<i32, i32>::new();
    map.reserve((n + 1) as usize);

    let mut ans : i64 = 0;
    let mut acc : i32 = 0;
    map.insert(acc, 1);
    for i in 0..n {
        acc = (acc + a[i as usize]) % m;

        let count = map.entry(acc).or_insert(0);
        ans += *count as i64;
        *count += 1;
    }
    ans
}

fn main() {
    let nm = read_vec::<i32>();
    let a = read_vec::<i32>();
    println!("{}", solve(nm[0], nm[1], a));
}
