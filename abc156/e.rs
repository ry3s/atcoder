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

    const MOD: usize = 1_000_000_007;
    let n: usize = sc.input();
    let k: usize = sc.input();

    let com = Combination::new(1_400_001, MOD);

    if k >= n {
        // 任意の配置が可能
        let ans: usize = com.hcom(n, n);
        println!("{}", ans);
    } else if k == 1 {
        println!("{}", (n * (n - 1)) % MOD);
    } else {
        // 0人になる部屋がm(0..=k)個あるとすると、m人が残りのn - m部屋に散らばる。
        let mut ans = 0usize;

        for i in 0..k + 1 {
            let room = n - i;
            ans += com.com(n, i) * com.hcom(room, i) % MOD;
        }
        println!("{}", ans % MOD);
    }
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
        if n < k || n < 0 || k < 0 {
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
