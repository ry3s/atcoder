let n = read_int ()
let a, b = Scanf.sscanf (read_line ()) "%d %d" (fun a b -> (a, b))
let s = read_line ()

let ans = Printf.sprintf "%d %s" (n + a + b) s
let () = print_endline ans
