let a = read_int ()
let b = read_int ()
let a, b = (max a b, min a b)
let ans = min (a - b) (10 - a + b)
let () = Printf.printf "%d\n" ans
