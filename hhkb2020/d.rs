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

const MOD: usize = 1000000007;
fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);

    let t: usize = sc.input();
    for _ in 0..t {
        let (n, a, b): (usize, usize, usize) = (sc.input(), sc.input(), sc.input());
        let (a, b) = if a > b { (a, b) } else {(b, a)};
        let n = ModInt::new(n);
        let one = ModInt::one();
        let (a, b)= (ModInt::new(a) , ModInt::new(b));
        let dai = (n + one - a) * (n + one - a);
        let sho = (n + one - b) * (n + one - b);

        let m = if (a + b + b - one - one).0 > n.0 {n } else { a + b + b - one - one};
        let l = if (a + b - one ).0 > n.0 { n } else { a + b - one };
        let x = if n.0 > 2 && n.0 - 2 >= a.0 {
            (n - one - a) * (n - one - a)
        } else {
            ModInt::new(0)
        };
        let kado = (l + one - b) * (l + one - b) * ModInt::new(4);
        let haji = (l + one - b) * (m + one - b) * x * ModInt::new(4);
        let mannaka = (m + one - b) * (m + one - b) * (x * x);

        // let dup = (l + one - b) + (l + one - b);
        // println!("{} {} {} {}", dai, sho, dup, x);
        println!("{} {} {}", kado, haji, mannaka);
        let ans = (sho * dai)  - kado - haji - mannaka;
        println!("{}", ans);
    }
}


#[derive(Clone, Copy, Debug)]
struct ModInt(usize);

#[allow(dead_code)]
impl ModInt {
    fn new(n: usize) -> ModInt {
        ModInt(n % MOD)
    }

    fn zero() -> ModInt {
        ModInt(0)
    }

    fn one() -> ModInt {
        ModInt(1)
    }

    fn pow(self, mut n: usize) -> ModInt {
        let mut ret = ModInt::one();
        let mut x = self;
        while n > 0 {
            if n & 1 == 1 {
                ret *= x;
            }
            x *= x;
            n >>= 1;
        }
        ret
    }

    fn inv(self) -> ModInt {
        assert!(self.0 > 0);
        self.pow(MOD - 2)
    }
}

impl std::ops::Add for ModInt {
    type Output = ModInt;
    fn add(self, rhs: ModInt) -> Self::Output {
        let mut d = self.0 + rhs.0;
        if d >= MOD {
            d -= MOD;
        }
        ModInt(d)
    }
}

impl std::ops::AddAssign for ModInt {
    fn add_assign(&mut self, rhs: ModInt) {
        *self = *self + rhs;
    }
}

impl std::ops::Sub for ModInt {
    type Output = ModInt;
    fn sub(self, rhs: ModInt) -> Self::Output {
        let mut d = self.0 + MOD - rhs.0;
        if d >= MOD {
            d -= MOD;
        }
        ModInt(d)
    }
}

impl std::ops::SubAssign for ModInt {
    fn sub_assign(&mut self, rhs: ModInt) {
        *self = *self - rhs;
    }
}

impl std::ops::Mul for ModInt {
    type Output = ModInt;
    fn mul(self, rhs: ModInt) -> Self::Output {
        ModInt(self.0 * rhs.0 % MOD)
    }
}

impl std::ops::MulAssign for ModInt {
    fn mul_assign(&mut self, rhs: ModInt) {
        *self = *self * rhs;
    }
}

impl std::ops::Neg for ModInt {
    type Output = ModInt;
    fn neg(self) -> Self::Output {
        ModInt(if self.0 == 0 { 0 } else { MOD - self.0 })
    }
}

impl std::fmt::Display for ModInt {
    fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
        write!(f, "{}", self.0)
    }
}

impl std::str::FromStr for ModInt {
    type Err = std::num::ParseIntError;
    fn from_str(s: &str) -> Result<Self, Self::Err> {
        let val = s.parse::<usize>()?;
        Ok(ModInt::new(val))
    }
}

impl From<usize> for ModInt {
    fn from(n: usize) -> Self {
        Self::new(n)
    }
}
