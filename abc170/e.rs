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

use std::collections::BTreeMap;
fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);

    let (n, q): (usize, usize) = (sc.input(), sc.input());
    let infants: Vec<(usize, usize)> = (0..n)
        .map(|_| (sc.input(), sc.input()))
        .collect();

    let mut whr = vec![0; n];
    for (j, (rate, i)) in infants.iter().enumerate() {
        whr[j] = i - 1;
    }
    let mut rates = vec![MultiSet::new(); 200_000];
    for (rate, i) in &infants {
        rates[i - 1].insert(rate.clone());
    }

    let mut segtree = SegmentTree::init(vec![std::usize::MAX; 200_000]);

    for (i, rate) in rates.iter().enumerate() {
        if let Some(maxi) = rate.iter().next_back() {
            segtree.update(i, *maxi);
        }
    }


    // println!("{:?}, {:?}, {:?}", rates[0], rates[2], rates[3]);
    println!();
    for _ in 0..q {
        let c: usize = sc.input();
        let nxt: usize = sc.input();
        let prv = whr[c - 1];
        let rate = infants[c - 1].0.clone();
        rates[prv].remove(&rate);
        rates[nxt].insert(rate);
        if let Some(maxi) = rates[prv].iter().next_back() {
            println!("{}", maxi);
            segtree.update(prv, *maxi);
        } else {
            segtree.update(prv, std::usize::MAX);
        }
        if let Some(maxi) = rates[nxt].iter().next_back() {
            println!("{}", maxi);
            segtree.update(nxt, *maxi);
        } else {
            segtree.update(nxt, std::usize::MAX);
        }

        // println!("{:?}, {:?}, {:?}", rates[0], rates[2], rates[3]);
        whr[c - 1] = nxt;
        let ans = segtree.fold(0, 200_000);
        // println!("{}", ans);
    }
}

impl Magma for usize {
    fn op(&self, rhs: &Self) -> Self {
        *self.min(rhs)
    }
}

impl Associative for usize {}

impl Unital for usize {
    fn identity() -> Self {
        std::usize::MAX
    }
}

pub trait Magma: Sized + Clone {
  fn op(&self, rhs: &Self) -> Self;
}

pub trait Associative: Magma {}

pub trait Unital: Magma {
  fn identity() -> Self;
}

pub trait Monoid: Magma + Associative + Unital {}

impl<T: Magma + Associative + Unital> Monoid for T {}

pub struct SegmentTree<T: Monoid> {
    node: Vec<T>,
    sz: usize,
}

impl<T: Monoid> SegmentTree<T> {
    pub fn init(vec: Vec<T>) -> Self {
        let mut sz = 1;
        while sz < vec.len() { sz *= 2; }
        let mut node = vec![T::identity(); sz << 1];
        for i in 0..vec.len() { node[i + sz] = vec[i].clone(); }
        for i in (1..sz).rev() { node[i] = node[i << 1].op(&node[(i << 1) + 1]); }
        SegmentTree { node: node, sz: sz }
    }

    pub fn update(&mut self, i: usize, x: T) {
        let mut idx = i + self.sz;
        self.node[idx] = x;
        while idx > 1 {
            idx = idx >> 1;
            self.node[idx] = self.node[idx << 1].op(&self.node[(idx << 1)  + 1]);
        }
    }

    pub fn fold(&self, left: usize, right: usize) -> T {
        let mut lx = T::identity();
        let mut rx = T::identity();
        let mut l = left + self.sz;
        let mut r = right + self.sz;
        while l < r {
            if (l & 1) == 1 { lx = lx.op(&self.node[l]); }
            if (r & 1) == 0 { rx = self.node[r].op(&rx); }
            l = (l + 1) >> 1;
            r = (r - 1) >> 1;
        }
        if l == r { lx = lx.op(&self.node[l]); }
        lx.op(&rx)
    }
}


trait MultiSet<T> {
    fn add(&mut self, key: T);
    fn del(&mut self, key: T);
    fn least(&self) -> Option<T>;
    fn most(&self) -> Option<T>;
}

impl<T: Ord + Clone> MultiSet<T> for BTreeMap<T, usize> {
    fn add(&mut self, key: T) {
        *self.entry(key).or_insert(0) += 1;
    }

    fn del(&mut self, key: T) {
        if let Some(value) = self.get_mut(&key) {
            *value -= 1;
            if *value == 0 {
                self.remove(&key);
            }
        }
    }

    fn least(&self) -> Option<T> {
        self.iter().next().and_then(|(k, _)| k.clone())
    }

    fn most(&self) -> Option<T> {
        self.iter().next_back().and_then(|(k, _)| k.clone())
    }
}
