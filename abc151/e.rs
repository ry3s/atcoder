use std::io::{stdin, Read, StdinLock};
use std::str::FromStr;

#[allow(dead_code)]
struct Scanner<'a> {
    cin: StdinLock<'a>,
}
#[allow(dead_code)]
impl<'a> Scanner<'a> {
    fn new(cin: StdinLock<'a>) -> Scanner<'a> {
        Scanner { cin: cin }
    }

    fn read<T: FromStr>(&mut self) -> Option<T> {
        let token = self
            .cin
            .by_ref()
            .bytes()
            .map(|c| c.unwrap() as char)
            .skip_while(|c| c.is_whitespace())
            .take_while(|c| !c.is_whitespace())
            .collect::<String>();
        token.parse::<T>().ok()
    }

    fn input<T: FromStr>(&mut self) -> T {
        self.read().unwrap()
    }

    fn vec<T: FromStr>(&mut self, len: usize) -> Vec<T> {
        (0..len).map(|_| self.input()).collect()
    }

    fn mat<T: FromStr>(&mut self, row: usize, col: usize) -> Vec<Vec<T>> {
        (0..row).map(|_| self.vec(col)).collect()
    }
}

fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);

    let n: usize = sc.input();
    let k: usize = sc.input();
    let mut arr: Vec<i64> = sc.vec(n);
    const MOD: i64 = 1_000_000_007;

    arr.sort();

    let com = Combination::new(200_001, MOD as usize);

    let mut ans: i64 = 0;
    for i in 0..n {
        ans += arr[i] * com.com(i, k - 1) as i64 % MOD;
        ans -= arr[i] * com.com(n - 1 - i, k - 1) as i64 % MOD;
        ans = (ans % MOD + MOD) % MOD;
    }
    println!("{}", ans);
}
struct Combination {
    max_n: usize,
    modulo: usize,
    fac: Vec<usize>,
    finv: Vec<usize>,
    inv: Vec<usize>,
}

impl Combination {
    fn new(max_n: usize, modulo: usize) -> Combination {
        let mut fac = vec![0; max_n];
        let mut finv = vec![0; max_n];
        let mut inv = vec![0; max_n];
        fac[0] = 1;
        fac[1] = 1;
        finv[0] = 1;
        finv[1] = 1;
        inv[1] = 1;
        for i in 2..max_n {
            fac[i] = fac[i - 1] * i % modulo;
            inv[i] = modulo - inv[modulo % i] * (modulo / i) % modulo;
            finv[i] = finv[i - 1] * inv[i] % modulo;
        }
        Combination {
            max_n: max_n,
            modulo: modulo,
            fac: fac,
            finv: finv,
            inv: inv,
        }
    }

    fn com(&self, n: usize, k: usize) -> usize {
        if n < k {
            0
        } else {
            self.fac[n] * (self.finv[k] * self.finv[n - k] % self.modulo) % self.modulo
        }
    }

    fn hcom(&self, n: usize, k: usize) -> usize {
        if n == 0 && k == 0 {
            1
        } else {
            self.com(n + k - 1, k)
        }
    }
}
