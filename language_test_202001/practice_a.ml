open Core
let a = read_int ()
let b, c = Scanf.sscanf (read_line ()) "%d %d" (fun x y -> (x, y))
let s = read_line ()

let ans = Printf.sprintf "%d %s" (a + b + c) s
let () = print_endline ans
