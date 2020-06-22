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
        let token = self.cin.by_ref().bytes().map(|c| c.unwrap() as char)
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
const MOD: usize = 1_000_000_007;
fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);

    let k: usize = sc.input();
    let s: String = sc.input();
    let n = s.len();

    let max_n = 3_000_000;
    let mut pow25 = vec![1usize; max_n];
    let mut pow26 = vec![1usize; max_n];
    for i in 0..max_n - 1 {
        pow25[i + 1] = pow25[i] * 25 % MOD;
        pow26[i + 1] = pow26[i] * 26 % MOD;
    }

    let com = Combination::new(max_n, MOD);

    let mut ans: usize = 0;
    for i in 0..=k {
        let mut tmp = com.get(n - 1 + k - i, n - 1) * pow26[i] % MOD;
        tmp = tmp * pow25[k - i];
        tmp = tmp % MOD;
        ans += tmp;
        ans = ans % MOD;
    }
    println!("{}", ans);
}

struct Combination {
    fac: Vec<usize>,
    finv: Vec<usize>,
    modulo: usize,
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
            fac: fac,
            finv: finv,
            modulo: modulo,
        }
    }

    fn get(&self, n: usize, k: usize) -> usize {
        assert!(n >= k);
        self.fac[n] * (self.finv[k] * self.finv[n - k] % self.modulo) % self.modulo
    }

    #[allow(dead_code)]
    fn h(&self, n: usize, k: usize) -> usize {
        self.get(n + k - 1, k)
    }
}
