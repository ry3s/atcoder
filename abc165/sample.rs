fn print_type<T>(_: T) {
    println!("{}", std::any::type_name::<T>())
}
fn main() {
    let mut x: usize = 1;

    let y = x;
    print_type(y); // ---> usize
    let y = &x;
    print_type(y); // ---> &usize

    let &y = &x;
    print_type(y); // ---> usize

    let mut y = x;
    print_type(y); // ---> usize
    let mut y = &mut x;
    print_type(y); // ---> &mut usize
    let &mut y = &mut x;
    print_type(y); // ---> usize
    let &mut mut y = &mut x;
    print_type(y); // ---> usize

    let ref mut y = x;
    print_type(y); // ---> &mut usize
    let ref y = x;
    print_type(y); // ---> &usizse
    let ref y = &x;
    print_type(y); // ---> &&usize
    let ref y = &mut x;
    print_type(y); // ---> &&mut usize

}
// note: `mut` may be followed by `variable` and `variable @ pattern`
