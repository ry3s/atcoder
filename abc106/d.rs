use std::io;
use std::str::FromStr;

fn main() {
    let stdin = io::stdin();
    let mut buf = String::new();
    stdin.read_line(&mut buf).ok();
    let mut it = buf.split_whitespace().map(|n| usize::from_str(n).unwrap());
    let (n, m, q) = (it.next().unwrap(), it.next().unwrap(), it.next().unwrap());

    let mut matrix = vec![vec![0; n + 1]; n + 1];
    for _ in 0..m {
        let mut buf = String::new();
        stdin.read_line(&mut buf).ok();
        let mut it = buf.split_whitespace().map(|n| usize::from_str(n).unwrap());
        let (l, r) = (it.next().unwrap(), it.next().unwrap());
        matrix[l][r] += 1;
    }

    let mut sum : Vec<Vec<i64>>= vec![vec![0; n + 1]; n + 1];
    for i in 0..n + 1 {
        for j in 0..n + 1 {
            sum[i][j] = matrix[i][j];
            if j as i32 - 1 >= 0 { sum[i][j] += sum[i][j - 1]; };
            if i as i32 - 1 >= 0 { sum[i][j] += sum[i - 1][j]; };
            if i as i32 - 1 >= 0 && j as i32 - 1 >= 0 { sum[i][j] -= sum[i - 1][j - 1]; };
        }
    }

    for _ in 0..q {
        let mut buf = String::new();
        stdin.read_line(&mut buf).ok();
        let mut it = buf.split_whitespace().map(|n| usize::from_str(n).unwrap());
        let (p, q) = (it.next().unwrap(), it.next().unwrap());
        let cnt = get((p, p), (q, q), &sum);
        println!("{}", cnt);
    }
}

fn get((x1, y1) : (usize, usize), (x2, y2) : (usize, usize), sum : &Vec<Vec<i64>>) -> i64 {
    let mut res : i64 = sum[x2][y2];
    if x1 > 0 { res -= sum[x1 - 1][y2]; };
    if y1 > 0 { res -= sum[x2][y1 - 1]; };
    if x1 > 0 && y1 >0 { res += sum[x1 - 1][y1 - 1]; };
    res
}
