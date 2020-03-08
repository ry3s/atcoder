let n = read_int ()
let s = n mod 60
let m = (n / 60) mod 60
let h = n / 3600
let () = Printf.printf "%02d:%02d:%02d\n" h m s
